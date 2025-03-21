/*
 *  Unix SMB/CIFS implementation.
 *
 *  SMBD RPC service callbacks
 *
 *  Copyright (c) 2011      Andreas Schneider <asn@samba.org>
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

#include "includes.h"
#include "ntdomain.h"

#include "librpc/gen_ndr/ndr_winreg_scompat.h"
#include "librpc/gen_ndr/ndr_srvsvc_scompat.h"
#include "librpc/gen_ndr/ndr_lsa_scompat.h"
#include "librpc/gen_ndr/ndr_samr_scompat.h"
#include "librpc/gen_ndr/ndr_netlogon_scompat.h"
#include "librpc/gen_ndr/ndr_dfs_scompat.h"
#include "librpc/gen_ndr/ndr_echo_scompat.h"
#include "librpc/gen_ndr/ndr_dssetup_scompat.h"
#include "librpc/gen_ndr/ndr_wkssvc_scompat.h"
#include "librpc/gen_ndr/ndr_spoolss_scompat.h"
#include "librpc/gen_ndr/ndr_svcctl_scompat.h"
#include "librpc/gen_ndr/ndr_ntsvcs_scompat.h"
#include "librpc/gen_ndr/ndr_eventlog_scompat.h"
#include "librpc/gen_ndr/ndr_initshutdown_scompat.h"

#include "printing/nt_printing_migrate_internal.h"
#include "rpc_server/eventlog/srv_eventlog_reg.h"
#include "rpc_server/svcctl/srv_svcctl_reg.h"
#include "rpc_server/spoolss/srv_spoolss_nt.h"
#include "rpc_server/svcctl/srv_svcctl_nt.h"

#include "lib/server_prefork.h"
#include "librpc/rpc/dcesrv_core.h"
#include "librpc/rpc/dcerpc_ep.h"
#include "rpc_server/rpc_sock_helper.h"
#include "rpc_server/rpc_service_setup.h"
#include "rpc_server/rpc_ep_register.h"
#include "rpc_server/rpc_server.h"
#include "rpc_server/rpc_config.h"
#include "rpc_server/rpc_modules.h"
#include "rpc_server/epmapper/srv_epmapper.h"

#undef DBGC_CLASS
#define DBGC_CLASS DBGC_RPC_SRV

static_decl_rpc;

/* Common routine for embedded RPC servers */
NTSTATUS rpc_setup_embedded(struct tevent_context *ev_ctx,
			    struct messaging_context *msg_ctx,
			    struct dcesrv_context *dce_ctx,
			    const struct dcesrv_interface *iface)
{
	enum rpc_service_mode_e epm_mode = rpc_epmapper_mode();
	NTSTATUS status;

	/* Registration of ncacn_np services is problematic.  The
	 * ev_ctx passed in here is passed down to all children of the
	 * smbd process, and if the end point mapper ever goes away,
	 * they will all attempt to re-register.  But we want to test
	 * the code for now, so it is enabled in on environment in
	 * make test */
	if (epm_mode != RPC_SERVICE_MODE_DISABLED &&
	    (lp_parm_bool(-1, "rpc_server", "register_embedded_np", false))) {
		status = rpc_ep_register(ev_ctx, msg_ctx, dce_ctx, iface);
		if (!NT_STATUS_IS_OK(status)) {
			return status;
		}
	}

	return NT_STATUS_OK;
}

NTSTATUS dcesrv_create_endpoint_sockets(struct tevent_context *ev_ctx,
					struct messaging_context *msg_ctx,
					struct dcesrv_endpoint *e,
					TALLOC_CTX *mem_ctx,
					size_t *pnum_fds,
					int **pfds)
{
	struct dcerpc_binding *b = e->ep_description;
	char *binding = NULL;
	int *fds = NULL;
	size_t num_fds;
	NTSTATUS status;

	binding = dcerpc_binding_string(mem_ctx, b);
	if (binding == NULL) {
		return NT_STATUS_NO_MEMORY;
	}
	DBG_DEBUG("Creating endpoint '%s'\n", binding);
	TALLOC_FREE(binding);

	status = dcesrv_create_binding_sockets(b, mem_ctx, &num_fds, &fds);

	/* Build binding string again as the endpoint may have changed by
	 * dcesrv_create_<transport>_socket functions */
	binding = dcerpc_binding_string(mem_ctx, b);
	if (binding == NULL) {
		return NT_STATUS_NO_MEMORY;
	}

	if (!NT_STATUS_IS_OK(status)) {
		struct dcesrv_if_list *iface = NULL;
		DBG_ERR("Failed to create '%s' sockets for ", binding);
		for (iface = e->interface_list; iface; iface = iface->next) {
			DEBUGADD(DBGLVL_ERR, ("'%s' ", iface->iface->name));
		}
		DEBUGADD(DBGLVL_ERR, (": %s\n", nt_errstr(status)));
		return status;
	} else {
		struct dcesrv_if_list *iface = NULL;
		DBG_INFO("Successfully listening on '%s' for ", binding);
		for (iface = e->interface_list; iface; iface = iface->next) {
			DEBUGADD(DBGLVL_INFO, ("'%s' ", iface->iface->name));
		}
		DEBUGADD(DBGLVL_INFO, ("\n"));
	}

	TALLOC_FREE(binding);

	*pnum_fds = num_fds;
	*pfds = fds;

	return status;
}

NTSTATUS dcesrv_create_endpoint_list_pf_listen_fds(
	struct tevent_context *ev_ctx,
	struct messaging_context *msg_ctx,
	struct dcesrv_context *dce_ctx,
	struct dcesrv_endpoint *e,
	TALLOC_CTX *mem_ctx,
	size_t *pnum_fds,
	struct pf_listen_fd **pfds)
{
	struct pf_listen_fd *fds = NULL;
	size_t num_fds = 0;
	NTSTATUS status;

	for (; e != NULL; e = e->next) {
		int *ep_fds = NULL;
		struct pf_listen_fd *tmp = NULL;
		size_t i, num_ep_fds;

		status = dcesrv_create_endpoint_sockets(
			ev_ctx,
			msg_ctx,
			e,
			mem_ctx,
			&num_ep_fds,
			&ep_fds);
		if (!NT_STATUS_IS_OK(status)) {
			char *ep_string = dcerpc_binding_string(
					dce_ctx, e->ep_description);
			DBG_ERR("Failed to create endpoint '%s': %s\n",
				ep_string, nt_errstr(status));
			TALLOC_FREE(ep_string);
			goto fail;
		}

		if (num_fds + num_ep_fds < num_fds) {
			/* overflow */
			status = NT_STATUS_INTEGER_OVERFLOW;
			goto fail;
		}

		tmp = talloc_realloc(
			mem_ctx,
			fds,
			struct pf_listen_fd,
			num_fds + num_ep_fds);
		if (tmp == NULL) {
			status = NT_STATUS_NO_MEMORY;
			goto fail;
		}
		fds = tmp;

		for (i=0; i<num_ep_fds; i++) {
			fds[num_fds].fd = ep_fds[i];
			fds[num_fds].fd_data = e;
			num_fds += 1;
		}

		TALLOC_FREE(ep_fds);
	}

	*pnum_fds = num_fds;
	*pfds = fds;
	return NT_STATUS_OK;

fail:
	{
		size_t i;
		for (i=0; i<num_fds; i++) {
			close(fds[i].fd);
		}
	}

	TALLOC_FREE(fds);
	return status;
}

NTSTATUS dcesrv_setup_endpoint_sockets(struct tevent_context *ev_ctx,
				       struct messaging_context *msg_ctx,
				       struct dcesrv_context *dce_ctx,
				       struct dcesrv_endpoint *e,
				       dcerpc_ncacn_termination_fn term_fn,
				       void *term_data)
{
	TALLOC_CTX *frame = talloc_stackframe();
	struct dcerpc_binding *b = e->ep_description;
	char *binding = NULL;
	NTSTATUS status = NT_STATUS_NO_MEMORY;
	struct dcesrv_if_list *iface = NULL;
	int *fds = NULL;
	size_t i, num_fds = 0;
	struct dcerpc_ncacn_listen_state **listen_states = NULL;

	binding = dcerpc_binding_string(frame, b);
	if (binding == NULL) {
		goto fail;
	}

	DBG_DEBUG("Setting up endpoint '%s'\n", binding);
	TALLOC_FREE(binding);

	status = dcesrv_create_binding_sockets(b, frame, &num_fds, &fds);

	/* Build binding string again as the endpoint may have changed by
	 * dcesrv_create_<transport>_socket functions */
	binding = dcerpc_binding_string(frame, b);
	if (binding == NULL) {
		status = NT_STATUS_NO_MEMORY;
		goto fail;
	}

	if (!NT_STATUS_IS_OK(status)) {
		DBG_ERR("Failed to setup '%s' sockets for ", binding);
		for (iface = e->interface_list; iface; iface = iface->next) {
			DEBUGADD(DBGLVL_ERR, ("'%s' ", iface->iface->name));
		}
		DEBUGADD(DBGLVL_ERR, (": %s\n", nt_errstr(status)));
		goto fail;
	}

	listen_states = talloc_array(
		frame, struct dcerpc_ncacn_listen_state *, num_fds);
	if (listen_states == NULL) {
		status = NT_STATUS_NO_MEMORY;
		goto fail;
	}

	for (i=0; i<num_fds; i++) {
		int ret = dcesrv_setup_ncacn_listener(
			listen_states,
			dce_ctx,
			ev_ctx,
			msg_ctx,
			e,
			&fds[i],
			term_fn,
			term_data,
			&listen_states[i]);
		if (ret != 0) {
#ifdef __KOS__
			DBG_NOTICE("dcesrv_setup_ncacn_listener failed for "
				"socket %d: %s\n",
				fds[i],
				strerror(ret));
#else
			DBG_ERR("dcesrv_setup_ncacn_listener failed for "
				"socket %d: %s\n",
				fds[i],
				strerror(ret));
#endif
			break;
		}
	}

	if (i < num_fds) {
		goto fail;
	}

	for (i=0; i<num_fds; i++) {
		/*
		 * Make the listener states including the tevent_fd's
		 * talloc children of the endpoint. If the endpoint is
		 * freed (for example when forked daemons reinit) the
		 * dcesrv_context, the tevent_fd listener will be
		 * stopped and the socket closed.
		 *
		 * Do this in a loop separate from the one doing the
		 * dcesrv_setup_ncacn_listener() that can't fail
		 * anymore.
		 */
		talloc_move(e, &listen_states[i]);
	}

	DBG_INFO("Successfully listening on '%s' for ", binding);
	for (iface = e->interface_list; iface; iface = iface->next) {
		DEBUGADD(DBGLVL_INFO, ("'%s' ", iface->iface->name));
	}
	DEBUGADD(DBGLVL_INFO, ("\n"));

	TALLOC_FREE(frame);
	return NT_STATUS_OK;

fail:
	for (i=0; i<num_fds; i++) {
		if (fds[i] != -1) {
			close(fds[i]);
		}
	}
	TALLOC_FREE(frame);
	return status;
}

static NTSTATUS dcesrv_init_endpoints(struct tevent_context *ev_ctx,
				      struct messaging_context *msg_ctx,
				      struct dcesrv_context *dce_ctx)
{
	struct dcesrv_endpoint *e = NULL;
	NTSTATUS status;

	for (e = dce_ctx->endpoint_list; e; e = e->next) {
		enum dcerpc_transport_t transport =
			dcerpc_binding_get_transport(e->ep_description);

		if (transport == NCACN_HTTP) {
			/*
			 * We don't support ncacn_http yet
			 */
			continue;
		}

		status = dcesrv_setup_endpoint_sockets(ev_ctx,
						       msg_ctx,
						       dce_ctx,
						       e,
						       NULL,
						       NULL);
		if (!NT_STATUS_IS_OK(status)) {
			return status;
		}

		/* Register only NCACN_NP for embedded services */
		if (transport == NCACN_NP) {
			struct dcesrv_if_list *ifl = NULL;
			for (ifl = e->interface_list; ifl; ifl = ifl->next) {
				status = rpc_setup_embedded(ev_ctx,
							    msg_ctx,
							    dce_ctx,
							    ifl->iface);
				if (!NT_STATUS_IS_OK(status)) {
					DBG_ERR("Failed to register embedded "
						"interface in endpoint mapper "
						": %s", nt_errstr(status));
					return status;
				}
			}
		}
	}

	return NT_STATUS_OK;
}

static NTSTATUS rpc_setup_winreg(struct tevent_context *ev_ctx,
				 struct messaging_context *msg_ctx)
{
	NTSTATUS status;
	enum rpc_service_mode_e service_mode;
	const struct dcesrv_endpoint_server *ep_server = NULL;

	/* Register the endpoint server in DCERPC core */
	ep_server = winreg_get_ep_server();
	if (ep_server == NULL) {
		DBG_ERR("Failed to get 'winreg' endpoint server\n");
		return NT_STATUS_UNSUCCESSFUL;
	}

	service_mode = rpc_service_mode(ep_server->name);
	if (service_mode != RPC_SERVICE_MODE_EMBEDDED) {
		return NT_STATUS_OK;
	}

	status = dcerpc_register_ep_server(ep_server);
	if (!NT_STATUS_IS_OK(status)) {
		DBG_ERR("Failed to register '%s' endpoint server: "
			"%s\n", ep_server->name, nt_errstr(status));
		return status;
	}

	return NT_STATUS_OK;
}

static NTSTATUS rpc_setup_srvsvc(struct tevent_context *ev_ctx,
				 struct messaging_context *msg_ctx)
{
	NTSTATUS status;
	enum rpc_service_mode_e service_mode;
	const struct dcesrv_endpoint_server *ep_server = NULL;

	/* Register the endpoint server in DCERPC core */
	ep_server = srvsvc_get_ep_server();
	if (ep_server == NULL) {
		DBG_ERR("Failed to get 'srvsvc' endpoint server\n");
		return NT_STATUS_UNSUCCESSFUL;
	}

	service_mode = rpc_service_mode(ep_server->name);
	if (service_mode != RPC_SERVICE_MODE_EMBEDDED) {
		return NT_STATUS_OK;
	}

	status = dcerpc_register_ep_server(ep_server);
	if (!NT_STATUS_IS_OK(status)) {
		DBG_ERR("Failed to register '%s' endpoint server: "
			"%s\n", ep_server->name, nt_errstr(status));
		return status;
	}

	return NT_STATUS_OK;
}

static NTSTATUS rpc_setup_lsarpc(struct tevent_context *ev_ctx,
				 struct messaging_context *msg_ctx)
{
	enum rpc_daemon_type_e lsasd_type = rpc_lsasd_daemon();
	NTSTATUS status;
	enum rpc_service_mode_e service_mode;
	const struct dcesrv_endpoint_server *ep_server = NULL;

	/* Register the endpoint server in DCERPC core */
	ep_server = lsarpc_get_ep_server();
	if (ep_server == NULL) {
		DBG_ERR("Failed to get 'lsarpc' endpoint server\n");
		return NT_STATUS_UNSUCCESSFUL;
	}

	service_mode = rpc_service_mode(ep_server->name);
	if (service_mode != RPC_SERVICE_MODE_EMBEDDED ||
	    lsasd_type != RPC_DAEMON_EMBEDDED) {
		return NT_STATUS_OK;
	}

	status = dcerpc_register_ep_server(ep_server);
	if (!NT_STATUS_IS_OK(status)) {
		DBG_ERR("Failed to register '%s' endpoint server: "
			"%s\n", ep_server->name, nt_errstr(status));
		return status;
	}

	return NT_STATUS_OK;
}

static NTSTATUS rpc_setup_samr(struct tevent_context *ev_ctx,
			       struct messaging_context *msg_ctx)
{
	enum rpc_daemon_type_e lsasd_type = rpc_lsasd_daemon();
	NTSTATUS status;
	enum rpc_service_mode_e service_mode;
	const struct dcesrv_endpoint_server *ep_server = NULL;

	/* Register the endpoint server in DCERPC core */
	ep_server = samr_get_ep_server();
	if (ep_server == NULL) {
		DBG_ERR("Failed to get 'samr' endpoint server\n");
		return NT_STATUS_UNSUCCESSFUL;
	}

	service_mode = rpc_service_mode(ep_server->name);
	if (service_mode != RPC_SERVICE_MODE_EMBEDDED ||
	    lsasd_type != RPC_DAEMON_EMBEDDED) {
		return NT_STATUS_OK;
	}

	status = dcerpc_register_ep_server(ep_server);
	if (!NT_STATUS_IS_OK(status)) {
		DBG_ERR("Failed to register '%s' endpoint server: "
			"%s\n", ep_server->name, nt_errstr(status));
		return status;
	}

	return NT_STATUS_OK;
}

static NTSTATUS rpc_setup_netlogon(struct tevent_context *ev_ctx,
				   struct messaging_context *msg_ctx)
{
	enum rpc_daemon_type_e lsasd_type = rpc_lsasd_daemon();
	NTSTATUS status;
	enum rpc_service_mode_e service_mode;
	const struct dcesrv_endpoint_server *ep_server = NULL;

	/* Register the endpoint server in DCERPC core */
	ep_server = netlogon_get_ep_server();
	if (ep_server == NULL) {
		DBG_ERR("Failed to get 'netlogon' endpoint server\n");
		return NT_STATUS_UNSUCCESSFUL;
	}

	service_mode = rpc_service_mode(ep_server->name);
	if (service_mode != RPC_SERVICE_MODE_EMBEDDED ||
	    lsasd_type != RPC_DAEMON_EMBEDDED) {
		return NT_STATUS_OK;
	}

	status = dcerpc_register_ep_server(ep_server);
	if (!NT_STATUS_IS_OK(status)) {
		DBG_ERR("Failed to register '%s' endpoint server: "
			"%s\n", ep_server->name, nt_errstr(status));
		return status;
	}

	return NT_STATUS_OK;
}

static NTSTATUS rpc_setup_netdfs(struct tevent_context *ev_ctx,
				 struct messaging_context *msg_ctx)
{
	NTSTATUS status;
	enum rpc_service_mode_e service_mode;
	const struct dcesrv_endpoint_server *ep_server = NULL;

	/* Register the endpoint server in DCERPC core */
	ep_server = netdfs_get_ep_server();
	if (ep_server == NULL) {
		DBG_ERR("Failed to get 'netdfs' endpoint server\n");
		return NT_STATUS_UNSUCCESSFUL;
	}

	service_mode = rpc_service_mode(ep_server->name);
	if (service_mode != RPC_SERVICE_MODE_EMBEDDED) {
		return NT_STATUS_OK;
	}

	status = dcerpc_register_ep_server(ep_server);
	if (!NT_STATUS_IS_OK(status)) {
		DBG_ERR("Failed to register '%s' endpoint server: "
			"%s\n", ep_server->name, nt_errstr(status));
		return status;
	}

	return NT_STATUS_OK;
}

#ifdef DEVELOPER
static NTSTATUS rpc_setup_rpcecho(struct tevent_context *ev_ctx,
				  struct messaging_context *msg_ctx)
{
	NTSTATUS status;
	enum rpc_service_mode_e service_mode;
	const struct dcesrv_endpoint_server *ep_server = NULL;

	/* Register the endpoint server in DCERPC core */
	ep_server = rpcecho_get_ep_server();
	if (ep_server == NULL) {
		DBG_ERR("Failed to get 'rpcecho' endpoint server\n");
		return NT_STATUS_UNSUCCESSFUL;
	}

	service_mode = rpc_service_mode(ep_server->name);
	if (service_mode != RPC_SERVICE_MODE_EMBEDDED) {
		return NT_STATUS_OK;
	}

	status = dcerpc_register_ep_server(ep_server);
	if (!NT_STATUS_IS_OK(status)) {
		DBG_ERR("Failed to register '%s' endpoint server: "
			"%s\n", ep_server->name, nt_errstr(status));
		return status;
	}

	return NT_STATUS_OK;
}
#endif

static NTSTATUS rpc_setup_dssetup(struct tevent_context *ev_ctx,
				  struct messaging_context *msg_ctx)
{
	NTSTATUS status;
	enum rpc_service_mode_e service_mode;
	const struct dcesrv_endpoint_server *ep_server = NULL;

	/* Register the endpoint server in DCERPC core */
	ep_server = dssetup_get_ep_server();
	if (ep_server == NULL) {
		DBG_ERR("Failed to get 'dssetup' endpoint server\n");
		return NT_STATUS_UNSUCCESSFUL;
	}

	service_mode = rpc_service_mode(ep_server->name);
	if (service_mode != RPC_SERVICE_MODE_EMBEDDED) {
		return NT_STATUS_OK;
	}

	status = dcerpc_register_ep_server(ep_server);
	if (!NT_STATUS_IS_OK(status)) {
		DBG_ERR("Failed to register '%s' endpoint server: "
			"%s\n", ep_server->name, nt_errstr(status));
		return status;
	}

	return NT_STATUS_OK;
}

static NTSTATUS rpc_setup_wkssvc(struct tevent_context *ev_ctx,
				 struct messaging_context *msg_ctx)
{
	NTSTATUS status;
	enum rpc_service_mode_e service_mode;
	const struct dcesrv_endpoint_server *ep_server = NULL;

	/* Register the endpoint server in DCERPC core */
	ep_server = wkssvc_get_ep_server();
	if (ep_server == NULL) {
		DBG_ERR("Failed to get 'wkssvc' endpoint server\n");
		return NT_STATUS_UNSUCCESSFUL;
	}

	service_mode = rpc_service_mode(ep_server->name);
	if (service_mode != RPC_SERVICE_MODE_EMBEDDED) {
		return NT_STATUS_OK;
	}

	status = dcerpc_register_ep_server(ep_server);
	if (!NT_STATUS_IS_OK(status)) {
		DBG_ERR("Failed to register '%s' endpoint server: "
			"%s\n", ep_server->name, nt_errstr(status));
		return status;
	}

	return NT_STATUS_OK;
}

static NTSTATUS rpc_setup_spoolss(struct tevent_context *ev_ctx,
				  struct messaging_context *msg_ctx)
{
	enum rpc_daemon_type_e spoolss_type = rpc_spoolss_daemon();
	NTSTATUS status = NT_STATUS_UNSUCCESSFUL;
	enum rpc_service_mode_e service_mode;
	const struct dcesrv_endpoint_server *ep_server = NULL;

	if (lp__disable_spoolss()) {
		return NT_STATUS_OK;
	}

	/* Register the endpoint server in DCERPC core */
	ep_server = spoolss_get_ep_server();
	if (ep_server == NULL) {
		DBG_ERR("Failed to get 'spoolss' endpoint server\n");
		return NT_STATUS_UNSUCCESSFUL;
	}

	service_mode = rpc_service_mode(ep_server->name);
	if (service_mode != RPC_SERVICE_MODE_EMBEDDED ||
	    spoolss_type != RPC_DAEMON_EMBEDDED) {
		return NT_STATUS_OK;
	}

	status = dcerpc_register_ep_server(ep_server);
	if (!NT_STATUS_IS_OK(status)) {
		DBG_ERR("Failed to register '%s' endpoint server"
			": %s\n", ep_server->name, nt_errstr(status));
		return status;
	}

	return NT_STATUS_OK;
}

static NTSTATUS rpc_setup_svcctl(struct tevent_context *ev_ctx,
				 struct messaging_context *msg_ctx)
{
	NTSTATUS status;
	enum rpc_service_mode_e service_mode;
	const struct dcesrv_endpoint_server *ep_server = NULL;

	/* Register the endpoint server in DCERPC core */
	ep_server = svcctl_get_ep_server();
	if (ep_server == NULL) {
		DBG_ERR("Failed to get 'svcctl' endpoint server\n");
		return NT_STATUS_UNSUCCESSFUL;
	}

	service_mode = rpc_service_mode(ep_server->name);
	if (service_mode != RPC_SERVICE_MODE_EMBEDDED) {
		return NT_STATUS_OK;
	}

	status = dcerpc_register_ep_server(ep_server);
	if (!NT_STATUS_IS_OK(status)) {
		DBG_ERR("Failed to register '%s' endpoint server"
			": %s\n", ep_server->name, nt_errstr(status));
		return status;
	}

	return NT_STATUS_OK;
}

static NTSTATUS rpc_setup_ntsvcs(struct tevent_context *ev_ctx,
				 struct messaging_context *msg_ctx)
{
	NTSTATUS status;
	enum rpc_service_mode_e service_mode;
	const struct dcesrv_endpoint_server *ep_server = NULL;

	/* Register the endpoint server in DCERPC core */
	ep_server = ntsvcs_get_ep_server();
	if (ep_server == NULL) {
		DBG_ERR("Failed to get 'ntsvcs' endpoint server\n");
		return NT_STATUS_UNSUCCESSFUL;
	}

	service_mode = rpc_service_mode(ep_server->name);
	if (service_mode != RPC_SERVICE_MODE_EMBEDDED) {
		return NT_STATUS_OK;
	}

	status = dcerpc_register_ep_server(ep_server);
	if (!NT_STATUS_IS_OK(status)) {
		DBG_ERR("Failed to register '%s' endpoint server"
			": %s\n", ep_server->name, nt_errstr(status));
		return status;
	}

	return NT_STATUS_OK;
}

static NTSTATUS rpc_setup_eventlog(struct tevent_context *ev_ctx,
				   struct messaging_context *msg_ctx)
{
	NTSTATUS status;
	enum rpc_service_mode_e service_mode;
	const struct dcesrv_endpoint_server *ep_server = NULL;

	/* Register the endpoint server in DCERPC core */
	ep_server = eventlog_get_ep_server();
	if (ep_server == NULL) {
		DBG_ERR("Failed to get 'eventlog' endpoint server\n");
		return NT_STATUS_UNSUCCESSFUL;
	}

	service_mode = rpc_service_mode(ep_server->name);
	if (service_mode != RPC_SERVICE_MODE_EMBEDDED) {
		return NT_STATUS_OK;
	}

	status = dcerpc_register_ep_server(ep_server);
	if (!NT_STATUS_IS_OK(status)) {
		DBG_ERR("Failed to register '%s' endpoint server"
			": %s\n", ep_server->name, nt_errstr(status));
		return status;
	}

	return NT_STATUS_OK;
}

static NTSTATUS rpc_setup_initshutdown(struct tevent_context *ev_ctx,
				       struct messaging_context *msg_ctx)
{
	NTSTATUS status;
	enum rpc_service_mode_e service_mode;
	const struct dcesrv_endpoint_server *ep_server = NULL;

	/* Register the endpoint server in DCERPC core */
	ep_server = initshutdown_get_ep_server();
	if (ep_server == NULL) {
		DBG_ERR("Failed to get 'initshutdown' endpoint server\n");
		return NT_STATUS_UNSUCCESSFUL;
	}

	service_mode = rpc_service_mode(ep_server->name);
	if (service_mode != RPC_SERVICE_MODE_EMBEDDED) {
		return NT_STATUS_OK;
	}

	status = dcerpc_register_ep_server(ep_server);
	if (!NT_STATUS_IS_OK(status)) {
		DBG_ERR("Failed to register '%s' endpoint "
			"server: %s\n", ep_server->name, nt_errstr(status));
		return status;
	}

	return NT_STATUS_OK;
}

NTSTATUS dcesrv_init(TALLOC_CTX *mem_ctx,
		     struct tevent_context *ev_ctx,
		     struct messaging_context *msg_ctx,
		     struct dcesrv_context *dce_ctx)
{
	TALLOC_CTX *tmp_ctx;
	bool ok;
	init_module_fn *mod_init_fns = NULL;
	NTSTATUS status;

	tmp_ctx = talloc_stackframe();
	if (tmp_ctx == NULL) {
		return NT_STATUS_NO_MEMORY;
	}

	DBG_INFO("Registering DCE/RPC endpoint servers\n");

	status = rpc_setup_winreg(ev_ctx, msg_ctx);
	if (!NT_STATUS_IS_OK(status)) {
		goto done;
	}

	status = rpc_setup_srvsvc(ev_ctx, msg_ctx);
	if (!NT_STATUS_IS_OK(status)) {
		goto done;
	}

	status = rpc_setup_lsarpc(ev_ctx, msg_ctx);
	if (!NT_STATUS_IS_OK(status)) {
		goto done;
	}

	status = rpc_setup_samr(ev_ctx, msg_ctx);
	if (!NT_STATUS_IS_OK(status)) {
		goto done;
	}

	status = rpc_setup_netlogon(ev_ctx, msg_ctx);
	if (!NT_STATUS_IS_OK(status)) {
		goto done;
	}

	status = rpc_setup_netdfs(ev_ctx, msg_ctx);
	if (!NT_STATUS_IS_OK(status)) {
		goto done;
	}

#ifdef DEVELOPER
	status = rpc_setup_rpcecho(ev_ctx, msg_ctx);
	if (!NT_STATUS_IS_OK(status)) {
		goto done;
	}
#endif

	status = rpc_setup_dssetup(ev_ctx, msg_ctx);
	if (!NT_STATUS_IS_OK(status)) {
		goto done;
	}

	status = rpc_setup_wkssvc(ev_ctx, msg_ctx);
	if (!NT_STATUS_IS_OK(status)) {
		goto done;
	}

	status = rpc_setup_spoolss(ev_ctx, msg_ctx);
	if (!NT_STATUS_IS_OK(status)) {
		goto done;
	}

	status = rpc_setup_svcctl(ev_ctx, msg_ctx);
	if (!NT_STATUS_IS_OK(status)) {
		goto done;
	}

	status = rpc_setup_ntsvcs(ev_ctx, msg_ctx);
	if (!NT_STATUS_IS_OK(status)) {
		goto done;
	}

	status = rpc_setup_eventlog(ev_ctx, msg_ctx);
	if (!NT_STATUS_IS_OK(status)) {
		goto done;
	}

	status = rpc_setup_initshutdown(ev_ctx, msg_ctx);
	if (!NT_STATUS_IS_OK(status)) {
		goto done;
	}

	DBG_INFO("Initializing DCE/RPC modules\n");

	/* Initialize static subsystems */
	static_init_rpc(NULL);

	/* Initialize shared modules */
	mod_init_fns = load_samba_modules(tmp_ctx, "rpc");
	if ((mod_init_fns == NULL) && (errno != ENOENT)) {
		/*
		 * ENOENT means the directory doesn't exist which can happen if
		 * all modules are static. So ENOENT is ok, everything else is
		 * not ok.
		 */
		DBG_ERR("Loading shared DCE/RPC modules failed [%s]\n",
			strerror(errno));
		status = NT_STATUS_UNSUCCESSFUL;
		goto done;
	}

	ok = run_init_functions(NULL, mod_init_fns);
	if (!ok) {
		DBG_ERR("Initializing shared DCE/RPC modules failed\n");
		status = NT_STATUS_UNSUCCESSFUL;
		goto done;
	}

	/* The RPC module setup function has to register the endpoint server */
	ok = setup_rpc_modules(ev_ctx, msg_ctx);
	if (!ok) {
		DBG_ERR("Shared DCE/RPC modules setup failed\n");
		status = NT_STATUS_UNSUCCESSFUL;
		goto done;
	}

	DBG_INFO("Initializing DCE/RPC registered endpoint servers\n");

	status = dcesrv_init_registered_ep_servers(dce_ctx);
	if (!NT_STATUS_IS_OK(status)) {
		DBG_ERR("Failed to init DCE/RPC endpoint servers: %s\n",
			nt_errstr(status));
		goto done;
	}

	DBG_INFO("Initializing DCE/RPC connection endpoints\n");

	status = dcesrv_init_endpoints(ev_ctx, msg_ctx, dce_ctx);
	if (!NT_STATUS_IS_OK(status)) {
		DBG_ERR("Failed to init DCE/RPC endpoints: %s\n",
			nt_errstr(status));
		goto done;
	}

	status = NT_STATUS_OK;
done:
	talloc_free(tmp_ctx);
	return status;
}

/* vim: set ts=8 sw=8 noet cindent ft=c.doxygen: */
