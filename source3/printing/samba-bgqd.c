/*
 *  Printing background queue helper
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#include "replace.h"
#include "system/filesys.h"
#include "lib/util/server_id.h"
#include "source3/locking/share_mode_lock.h"
#include "source3/param/loadparm.h"
#include "source3/param/param_proto.h"
#include "lib/cmdline/cmdline.h"
#include "lib/util/talloc_stack.h"
#include "lib/util/debug.h"
#include "lib/util/signal.h"
#include "lib/util/fault.h"
#include "lib/util/become_daemon.h"
#include "lib/util/charset/charset.h"
#include "lib/util/samba_util.h"
#include "lib/util/sys_rw.h"
#include "lib/util/pidfile.h"
#include "lib/async_req/async_sock.h"
#include "dynconfig/dynconfig.h"
#include "source3/lib/global_contexts.h"
#include "messages.h"
#include "nsswitch/winbind_client.h"
#include "source3/include/auth.h"
#include "source3/lib/util_procid.h"
#include "source3/auth/proto.h"
#include "source3/printing/queue_process.h"

static void watch_handler(struct tevent_req *req)
{
	bool *pdone = tevent_req_callback_data_void(req);
	*pdone = true;
}

static void bgqd_sig_term_handler(
	struct tevent_context *ev,
	struct tevent_signal *se,
	int signum,
	int count,
	void *siginfo,
	void *private_data)
{
	bool *pdone = private_data;
	*pdone = true;
}

static bool ready_signal_filter(
	struct messaging_rec *rec, void *private_data)
{
	pid_t pid = getpid();
	ssize_t written;

	if (rec->msg_type != MSG_DAEMON_READY_FD) {
		return false;
	}
	if (rec->num_fds != 1) {
		return false;
	}

	written = sys_write(rec->fds[0], &pid, sizeof(pid));
	if (written != sizeof(pid)) {
		DBG_ERR("Could not write pid: %s\n", strerror(errno));
	}

	return false;
}

static int samba_bgqd_pidfile_create(
	struct messaging_context *msg_ctx,
	const char *progname,
	int ready_signal_fd)
{
	const char *piddir = lp_pid_directory();
	size_t len = strlen(piddir) + strlen(progname) + 6;
	char pidFile[len];
	pid_t existing_pid;
	int fd, ret;

	snprintf(pidFile,
		 sizeof(pidFile),
		 "%s/%s.pid",
		 piddir, progname);

	ret = pidfile_path_create(pidFile, &fd, &existing_pid);
	if (ret == 0) {
		struct tevent_req *ready_signal_req = NULL;

		/*
		 * Listen for fd's sent via MSG_DAEMON_READY_FD:
		 * Multiple instances of this process might have raced
		 * for creating the pidfile. Make sure the parent does
		 * not suffer from this race, reply on behalf of the
		 * loser of this race.
		 */

		ready_signal_req = messaging_filtered_read_send(
			msg_ctx,
			messaging_tevent_context(msg_ctx),
			msg_ctx,
			ready_signal_filter,
			NULL);
		if (ready_signal_req == NULL) {
			DBG_DEBUG("messaging_filtered_read_send failed\n");
			pidfile_unlink(piddir, progname);
			pidfile_fd_close(fd);
			return ENOMEM;
		}

		/* leak fd */
		return 0;
	}

	if (ret != EAGAIN) {
		DBG_DEBUG("pidfile_path_create() failed: %s\n",
			  strerror(ret));
		return ret;
	}

	DBG_DEBUG("%s pid %d exists\n", progname, (int)existing_pid);

	if (ready_signal_fd != -1) {
		/*
		 * We lost the race for the pidfile, but someone else
		 * can report readiness on our behalf.
		 */
		NTSTATUS status = messaging_send_iov(
			msg_ctx,
			pid_to_procid(existing_pid),
			MSG_DAEMON_READY_FD,
			NULL,
			0,
			&ready_signal_fd,
			1);
		if (!NT_STATUS_IS_OK(status)) {
			DBG_DEBUG("Could not send ready_signal_fd: %s\n",
				  nt_errstr(status));
		}
	}

	return EAGAIN;
}

static int closeall_except(int *fds, size_t num_fds)
{
	size_t i;
	int max_keep = -1;
	int fd, ret;

	for (i=0; i<num_fds; i++) {
		max_keep = MAX(max_keep, fds[i]);
	}
	if (max_keep == -1) {
		return 0;
	}

	for (fd = 0; fd < max_keep; fd++) {
		bool keep = false;

		/*
		 * O(num_fds*max_keep), but we expect the number of
		 * fds to keep to be very small, typically 0,1,2 and
		 * very few more.
		 */
		for (i=0; i<num_fds; i++) {
			if (fd == fds[i]) {
				keep = true;
				break;
			}
		}
		if (keep) {
			continue;
		}
		ret = close(fd);
		if ((ret == -1) && (errno != EBADF)) {
			return errno;
		}
	}

	closefrom(max_keep+1);
	return 0;
}

static int closeall_except_fd_params(
	size_t num_fd_params,
	const char *fd_params[],
	int argc,
	const char *argv[])
{
	int fds[num_fd_params+3];
	size_t i;
	struct poptOption long_options[num_fd_params + 1];
	poptContext pc;
	int ret;

	for (i=0; i<num_fd_params; i++) {
		fds[i] = -1;
		long_options[i] = (struct poptOption) {
			.longName = fd_params[i],
			.argInfo = POPT_ARG_INT,
			.arg = &fds[i],
		};
	}
	long_options[num_fd_params] = (struct poptOption) { .longName=NULL, };

	fds[num_fd_params] = 0;
	fds[num_fd_params+1] = 1;
	fds[num_fd_params+2] = 2;

	pc = poptGetContext(argv[0], argc, argv, long_options, 0);

	while ((ret = poptGetNextOpt(pc)) != -1) {
		/* do nothing */
	}

	poptFreeContext(pc);

	ret = closeall_except(fds, ARRAY_SIZE(fds));
	return ret;
}

int main(int argc, const char *argv[])
{
	const struct loadparm_substitution *lp_sub =
		loadparm_s3_global_substitution();
	const char *progname = getprogname();
	TALLOC_CTX *frame = NULL;
	poptContext pc;
	struct messaging_context *msg_ctx = NULL;
	struct tevent_context *ev = NULL;
	struct tevent_req *watch_req = NULL;
	struct tevent_signal *sigterm_handler = NULL;
	struct bq_state *bq = NULL;
	int foreground = 0;
	int no_process_group = 0;
	int log_stdout = 0;
	int ready_signal_fd = -1;
	int watch_fd = -1;
	NTSTATUS status;
	int ret;
	bool ok;
	bool done = false;
	int exitcode = 1;

	struct poptOption long_options[] = {
		POPT_AUTOHELP
		POPT_COMMON_SAMBA
		{
			.longName   = "foreground",
			.shortName  = 'F',
			.argInfo    = POPT_ARG_NONE,
			.arg        = &foreground,
			.descrip    = "Run daemon in foreground "
				      "(for daemontools, etc.)",
		},
		{
			.longName   = "no-process-group",
			.shortName  = '\0',
			.argInfo    = POPT_ARG_NONE,
			.arg        = &no_process_group,
			.descrip    = "Don't create a new process group" ,
		},

		/*
		 * File descriptor to write the PID of the helper
		 * process to
		 */
		{
			.longName   = "ready-signal-fd",
			.argInfo    = POPT_ARG_INT,
			.arg        = &ready_signal_fd,
			.descrip    = "Fd to signal readiness to" ,
		},

		/*
		 * Read end of a pipe held open by the parent
		 * smbd. Exit this process when it becomes readable.
		 */
		{
			.longName   = "parent-watch-fd",
			.argInfo    = POPT_ARG_INT,
			.arg        = &watch_fd,
			.descrip    = "Fd to watch for exiting",
		},
		POPT_TABLEEND
	};

	{
		const char *fd_params[] = {
			"ready-signal-fd", "parent-watch-fd",
		};

		closeall_except_fd_params(
			ARRAY_SIZE(fd_params), fd_params, argc, argv);
	}

	frame = talloc_stackframe();

	umask(0);

	ok = samba_cmdline_init(frame,
				SAMBA_CMDLINE_CONFIG_SERVER,
				true /* require_smbconf */);
	if (!ok) {
		DBG_ERR("Failed to setup cmdline parser!\n");
		exit(ENOMEM);
	}

	pc = samba_popt_get_context(progname,
				    argc,
				    argv,
				    long_options,
				    0);
	if (pc == NULL) {
		DBG_ERR("Failed to get popt context!\n");
		exit(ENOMEM);
	}

	ret = poptGetNextOpt(pc);
	if (ret < -1) {
		fprintf(stderr, "invalid options: %s\n", poptStrerror(ret));
		goto done;
	}

	poptFreeContext(pc);

	log_stdout = (debug_get_log_type() == DEBUG_STDOUT);

	if (foreground) {
		daemon_status(progname, "Starting process ... ");
	} else {
		become_daemon(true, no_process_group, log_stdout);
	}

	if (log_stdout) {
		setup_logging(progname, DEBUG_STDOUT);
	} else {
		setup_logging(progname, DEBUG_FILE);
	}

	BlockSignals(true, SIGPIPE);

	smb_init_locale();
	dump_core_setup(progname, lp_logfile(frame, lp_sub));

	msg_ctx = global_messaging_context();
	if (msg_ctx == NULL) {
		DBG_ERR("messaging_init() failed\n");
		goto done;
	}
	ev = messaging_tevent_context(msg_ctx);

	ret = samba_bgqd_pidfile_create(msg_ctx, progname, ready_signal_fd);
	if (ret != 0) {
		goto done;
	}

	if (watch_fd != -1) {
		watch_req = wait_for_read_send(ev, ev, watch_fd, true);
		if (watch_req == NULL) {
			fprintf(stderr, "tevent_add_fd failed\n");
			goto done;
		}
		tevent_req_set_callback(watch_req, watch_handler, &done);
	}

	(void)winbind_off();
	ok = init_guest_session_info(frame);
	(void)winbind_on();
	if (!ok) {
		DBG_ERR("init_guest_session_info failed\n");
		goto done;
	}

	(void)winbind_off();
	status = init_system_session_info(frame);
	(void)winbind_on();
	if (!NT_STATUS_IS_OK(status)) {
		DBG_ERR("init_system_session_info failed: %s\n",
			nt_errstr(status));
		goto done;
	}

	sigterm_handler = tevent_add_signal(
		ev, frame, SIGTERM, 0, bgqd_sig_term_handler, &done);
	if (sigterm_handler == NULL) {
		DBG_ERR("Could not install SIGTERM handler\n");
		goto done;
	}

	bq = register_printing_bq_handlers(frame, msg_ctx);
	if (bq == NULL) {
		DBG_ERR("Could not register bq handlers\n");
		goto done;
	}

	ok = locking_init();
	if (!ok) {
		DBG_ERR("locking_init failed\n");
		goto done;
	}

	if (ready_signal_fd != -1) {
		pid_t pid = getpid();
		ssize_t written;

		written = sys_write(ready_signal_fd, &pid, sizeof(pid));
		if (written != sizeof(pid)) {
			DBG_ERR("Reporting readiness failed\n");
			goto done;
		}
		close(ready_signal_fd);
		ready_signal_fd = -1;
	}

	while (!done) {
		TALLOC_CTX *tmp = talloc_stackframe();
		ret = tevent_loop_once(ev);
		TALLOC_FREE(tmp);
		if (ret != 0) {
			DBG_ERR("tevent_loop_once failed\n");
			break;
		}
	}

	exitcode = 0;
done:
	TALLOC_FREE(watch_req);
	TALLOC_FREE(bq);
	TALLOC_FREE(sigterm_handler);
	global_messaging_context_free();
	TALLOC_FREE(frame);
	return exitcode;
}
