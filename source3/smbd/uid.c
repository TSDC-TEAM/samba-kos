/* 
   Unix SMB/CIFS implementation.
   uid/user handling
   Copyright (C) Andrew Tridgell 1992-1998

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "includes.h"
#include "system/passwd.h"
#include "smbd/smbd.h"
#include "smbd/globals.h"
#include "../librpc/gen_ndr/netlogon.h"
#include "libcli/security/security.h"
#include "passdb/lookup_sid.h"
#include "auth.h"
#include "../auth/auth_util.h"

/* what user is current? */
extern struct current_user current_user;

/****************************************************************************
 Become the guest user without changing the security context stack.
****************************************************************************/

bool change_to_guest(void)
{
	struct passwd *pass;

	pass = Get_Pwnam_alloc(talloc_tos(), lp_guest_account());
	if (!pass) {
		return false;
	}

#ifdef AIX
	/* MWW: From AIX FAQ patch to WU-ftpd: call initgroups before 
	   setting IDs */
	initgroups(pass->pw_name, pass->pw_gid);
#endif

	set_sec_ctx(pass->pw_uid, pass->pw_gid, 0, NULL, NULL);

	current_user.conn = NULL;
	current_user.vuid = UID_FIELD_INVALID;

	TALLOC_FREE(pass);

	return true;
}

/****************************************************************************
 talloc free the conn->session_info if not used in the vuid cache.
****************************************************************************/

static void free_conn_session_info_if_unused(connection_struct *conn)
{
	unsigned int i;

	for (i = 0; i < VUID_CACHE_SIZE; i++) {
		struct vuid_cache_entry *ent;
		ent = &conn->vuid_cache->array[i];
		if (ent->vuid != UID_FIELD_INVALID &&
				conn->session_info == ent->session_info) {
			return;
		}
	}
	/* Not used, safe to free. */
	TALLOC_FREE(conn->session_info);
}

/****************************************************************************
  Setup the share access mask for a connection.
****************************************************************************/

static uint32_t create_share_access_mask(int snum,
				bool readonly_share,
				const struct security_token *token)
{
	uint32_t share_access = 0;

	share_access_check(token,
			lp_const_servicename(snum),
			MAXIMUM_ALLOWED_ACCESS,
			&share_access);

	if (readonly_share) {
		share_access &=
			~(SEC_FILE_WRITE_DATA | SEC_FILE_APPEND_DATA |
			  SEC_FILE_WRITE_EA | SEC_FILE_WRITE_ATTRIBUTE |
			  SEC_DIR_DELETE_CHILD );
	}

	if (security_token_has_privilege(token, SEC_PRIV_SECURITY)) {
		share_access |= SEC_FLAG_SYSTEM_SECURITY;
	}
	if (security_token_has_privilege(token, SEC_PRIV_RESTORE)) {
		share_access |= SEC_RIGHTS_PRIV_RESTORE;
	}
	if (security_token_has_privilege(token, SEC_PRIV_BACKUP)) {
		share_access |= SEC_RIGHTS_PRIV_BACKUP;
	}
	if (security_token_has_privilege(token, SEC_PRIV_TAKE_OWNERSHIP)) {
		share_access |= SEC_STD_WRITE_OWNER;
	}

	return share_access;
}

/*******************************************************************
 Calculate access mask and if this user can access this share.
********************************************************************/

NTSTATUS check_user_share_access(connection_struct *conn,
				const struct auth_session_info *session_info,
				uint32_t *p_share_access,
				bool *p_readonly_share)
{
	int snum = SNUM(conn);
	uint32_t share_access = 0;
	bool readonly_share = false;

	if (!user_ok_token(session_info->unix_info->unix_name,
			   session_info->info->domain_name,
			   session_info->security_token, snum)) {
		return NT_STATUS_ACCESS_DENIED;
	}

	readonly_share = is_share_read_only_for_token(
		session_info->unix_info->unix_name,
		session_info->info->domain_name,
		session_info->security_token,
		conn);

	share_access = create_share_access_mask(snum,
					readonly_share,
					session_info->security_token);

	if ((share_access & (FILE_READ_DATA|FILE_WRITE_DATA)) == 0) {
		/* No access, read or write. */
		DBG_NOTICE("user %s connection to %s denied due to share "
			 "security descriptor.\n",
			 session_info->unix_info->unix_name,
			 lp_const_servicename(snum));
		return NT_STATUS_ACCESS_DENIED;
	}

	if (!readonly_share &&
	    !(share_access & FILE_WRITE_DATA)) {
		/* smb.conf allows r/w, but the security descriptor denies
		 * write. Fall back to looking at readonly. */
		readonly_share = true;
		DBG_INFO("falling back to read-only access-evaluation due to "
			 "security descriptor\n");
	}

	*p_share_access = share_access;
	*p_readonly_share = readonly_share;

	return NT_STATUS_OK;
}

/*******************************************************************
 Check if a username is OK.

 This sets up conn->session_info with a copy related to this vuser that
 later code can then mess with.
********************************************************************/

static bool check_user_ok(connection_struct *conn,
			uint64_t vuid,
			const struct auth_session_info *session_info,
			int snum)
{
	unsigned int i;
	bool readonly_share = false;
	bool admin_user = false;
	struct vuid_cache_entry *ent = NULL;
	uint32_t share_access = 0;
	NTSTATUS status;

	for (i=0; i<VUID_CACHE_SIZE; i++) {
		ent = &conn->vuid_cache->array[i];
		if (ent->vuid == vuid) {
			if (vuid == UID_FIELD_INVALID) {
				/*
				 * Slow path, we don't care
				 * about the array traversal.
				*/
				continue;
			}
			free_conn_session_info_if_unused(conn);
			conn->session_info = ent->session_info;
			conn->read_only = ent->read_only;
			conn->share_access = ent->share_access;
			conn->vuid = ent->vuid;
			return(True);
		}
	}

	status = check_user_share_access(conn,
					session_info,
					&share_access,
					&readonly_share);
	if (!NT_STATUS_IS_OK(status)) {
		return false;
	}

	admin_user = token_contains_name_in_list(
		session_info->unix_info->unix_name,
		session_info->info->domain_name,
		NULL, session_info->security_token, lp_admin_users(snum));

	ent = &conn->vuid_cache->array[conn->vuid_cache->next_entry];

	conn->vuid_cache->next_entry =
		(conn->vuid_cache->next_entry + 1) % VUID_CACHE_SIZE;

	TALLOC_FREE(ent->session_info);

	/*
	 * If force_user was set, all session_info's are based on the same
	 * username-based faked one.
	 */

	ent->session_info = copy_session_info(
		conn, conn->force_user ? conn->session_info : session_info);

	if (ent->session_info == NULL) {
		ent->vuid = UID_FIELD_INVALID;
		return false;
	}

	if (admin_user) {
		DEBUG(2,("check_user_ok: user %s is an admin user. "
			"Setting uid as %d\n",
			ent->session_info->unix_info->unix_name,
			sec_initial_uid() ));
		ent->session_info->unix_token->uid = sec_initial_uid();
	}

	/*
	 * It's actually OK to call check_user_ok() with
	 * vuid == UID_FIELD_INVALID as called from become_user_by_session().
	 * All this will do is throw away one entry in the cache.
	 */

	ent->vuid = vuid;
	ent->read_only = readonly_share;
	ent->share_access = share_access;
	free_conn_session_info_if_unused(conn);
	conn->session_info = ent->session_info;
	conn->vuid = ent->vuid;
	if (vuid == UID_FIELD_INVALID) {
		/*
		 * Not strictly needed, just make it really
		 * clear this entry is actually an unused one.
		 */
		ent->read_only = false;
		ent->share_access = 0;
		ent->session_info = NULL;
	}

	conn->read_only = readonly_share;
	conn->share_access = share_access;

	return(True);
}

static void print_impersonation_info(connection_struct *conn)
{
	struct smb_filename *cwdfname = NULL;

	if (!CHECK_DEBUGLVL(DBGLVL_INFO)) {
		return;
	}

	cwdfname = vfs_GetWd(talloc_tos(), conn);
	if (cwdfname == NULL) {
		return;
	}

	DBG_INFO("Impersonated user: uid=(%d,%d), gid=(%d,%d), cwd=[%s]\n",
		 (int)getuid(),
		 (int)geteuid(),
		 (int)getgid(),
		 (int)getegid(),
		 cwdfname->base_name);
	TALLOC_FREE(cwdfname);
}

/****************************************************************************
 Become the user of a connection number without changing the security context
 stack, but modify the current_user entries.
****************************************************************************/

static bool change_to_user_impersonate(connection_struct *conn,
				       const struct auth_session_info *session_info,
				       uint64_t vuid)
{
	const struct loadparm_substitution *lp_sub =
		loadparm_s3_global_substitution();
	int snum;
	gid_t gid;
	uid_t uid;
	const char *force_group_name;
	char group_c;
	int num_groups = 0;
	gid_t *group_list = NULL;
	bool ok;

	if ((current_user.conn == conn) &&
	    (current_user.vuid == vuid) &&
	    (current_user.ut.uid == session_info->unix_token->uid))
	{
		DBG_INFO("Skipping user change - already user\n");
		return true;
	}

	set_current_user_info(session_info->unix_info->sanitized_username,
			      session_info->unix_info->unix_name,
			      session_info->info->domain_name);

	snum = SNUM(conn);

	ok = check_user_ok(conn, vuid, session_info, snum);
	if (!ok) {
		DBG_WARNING("SMB user %s (unix user %s) "
			 "not permitted access to share %s.\n",
			 session_info->unix_info->sanitized_username,
			 session_info->unix_info->unix_name,
			 lp_const_servicename(snum));
		return false;
	}

	uid = conn->session_info->unix_token->uid;
	gid = conn->session_info->unix_token->gid;
	num_groups = conn->session_info->unix_token->ngroups;
	group_list  = conn->session_info->unix_token->groups;

	/*
	 * See if we should force group for this service. If so this overrides
	 * any group set in the force user code.
	 */
	force_group_name = lp_force_group(talloc_tos(), lp_sub, snum);
	group_c = *force_group_name;

	if ((group_c != '\0') && (conn->force_group_gid == (gid_t)-1)) {
		/*
		 * This can happen if "force group" is added to a
		 * share definition whilst an existing connection
		 * to that share exists. In that case, don't change
		 * the existing credentials for force group, only
		 * do so for new connections.
		 *
		 * BUG: https://bugzilla.samba.org/show_bug.cgi?id=13690
		 */
		DBG_INFO("Not forcing group %s on existing connection to "
			"share %s for SMB user %s (unix user %s)\n",
			force_group_name,
			lp_const_servicename(snum),
			session_info->unix_info->sanitized_username,
			session_info->unix_info->unix_name);
	}

	if((group_c != '\0') && (conn->force_group_gid != (gid_t)-1)) {
		/*
		 * Only force group for connections where
		 * conn->force_group_gid has already been set
		 * to the correct value (i.e. the connection
		 * happened after the 'force group' definition
		 * was added to the share definition. Connections
		 * that were made before force group was added
		 * should stay with their existing credentials.
		 *
		 * BUG: https://bugzilla.samba.org/show_bug.cgi?id=13690
		 */

		if (group_c == '+') {
			int i;

			/*
			 * Only force group if the user is a member of the
			 * service group. Check the group memberships for this
			 * user (we already have this) to see if we should force
			 * the group.
			 */
			for (i = 0; i < num_groups; i++) {
				if (group_list[i] == conn->force_group_gid) {
					conn->session_info->unix_token->gid =
						conn->force_group_gid;
					gid = conn->force_group_gid;
					gid_to_sid(&conn->session_info->security_token
						   ->sids[1], gid);
					break;
				}
			}
		} else {
			conn->session_info->unix_token->gid = conn->force_group_gid;
			gid = conn->force_group_gid;
			gid_to_sid(&conn->session_info->security_token->sids[1],
				   gid);
		}
	}

	set_sec_ctx(uid,
		    gid,
		    num_groups,
		    group_list,
		    conn->session_info->security_token);

	current_user.conn = conn;
	current_user.vuid = vuid;
	return true;
}

/**
 * Impersonate user and change directory to service
 *
 * change_to_user_and_service() is used to impersonate the user associated with
 * the given vuid and to change the working directory of the process to the
 * service base directory.
 **/
bool change_to_user_and_service(connection_struct *conn, uint64_t vuid)
{
	int snum = SNUM(conn);
	struct auth_session_info *si = NULL;
	NTSTATUS status;
	bool ok;

	if (conn == NULL) {
		DBG_WARNING("Connection not open\n");
		return false;
	}

	status = smbXsrv_session_info_lookup(conn->sconn->client,
					     vuid,
					     &si);
	if (!NT_STATUS_IS_OK(status)) {
		DBG_WARNING("Invalid vuid %llu used on share %s.\n",
			    (unsigned long long)vuid,
			    lp_const_servicename(snum));
		return false;
	}

	ok = change_to_user_impersonate(conn, si, vuid);
	if (!ok) {
		return false;
	}

	if (conn->tcon_done) {
		ok = chdir_current_service(conn);
		if (!ok) {
			return false;
		}
	}

	print_impersonation_info(conn);
	return true;
}

/**
 * Impersonate user and change directory to service
 *
 * change_to_user_and_service_by_fsp() is used to impersonate the user
 * associated with the given vuid and to change the working directory of the
 * process to the service base directory.
 **/
bool change_to_user_and_service_by_fsp(struct files_struct *fsp)
{
	return change_to_user_and_service(fsp->conn, fsp->vuid);
}

/****************************************************************************
 Go back to being root without changing the security context stack,
 but modify the current_user entries.
****************************************************************************/

bool smbd_change_to_root_user(void)
{
	set_root_sec_ctx();

	DEBUG(5,("change_to_root_user: now uid=(%d,%d) gid=(%d,%d)\n",
		(int)getuid(),(int)geteuid(),(int)getgid(),(int)getegid()));

	current_user.conn = NULL;
	current_user.vuid = UID_FIELD_INVALID;

	return(True);
}

/****************************************************************************
 Become the user of an authenticated connected named pipe.
 When this is called we are currently running as the connection
 user. Doesn't modify current_user.
****************************************************************************/

bool smbd_become_authenticated_pipe_user(struct auth_session_info *session_info)
{
	if (!push_sec_ctx())
		return False;

	set_current_user_info(session_info->unix_info->sanitized_username,
			      session_info->unix_info->unix_name,
			      session_info->info->domain_name);

	set_sec_ctx(session_info->unix_token->uid, session_info->unix_token->gid,
		    session_info->unix_token->ngroups, session_info->unix_token->groups,
		    session_info->security_token);

	DEBUG(5, ("Impersonated user: uid=(%d,%d), gid=(%d,%d)\n",
		 (int)getuid(),
		 (int)geteuid(),
		 (int)getgid(),
		 (int)getegid()));

	return True;
}

/****************************************************************************
 Unbecome the user of an authenticated connected named pipe.
 When this is called we are running as the authenticated pipe
 user and need to go back to being the connection user. Doesn't modify
 current_user.
****************************************************************************/

bool smbd_unbecome_authenticated_pipe_user(void)
{
	return pop_sec_ctx();
}

/****************************************************************************
 Utility functions used by become_xxx/unbecome_xxx.
****************************************************************************/

static void push_conn_ctx(void)
{
	struct conn_ctx *ctx_p;
	extern userdom_struct current_user_info;

	/* Check we don't overflow our stack */

	if (conn_ctx_stack_ndx == MAX_SEC_CTX_DEPTH) {
		DEBUG(0, ("Connection context stack overflow!\n"));
		smb_panic("Connection context stack overflow!\n");
	}

	/* Store previous user context */
	ctx_p = &conn_ctx_stack[conn_ctx_stack_ndx];

	ctx_p->conn = current_user.conn;
	ctx_p->vuid = current_user.vuid;
	ctx_p->user_info = current_user_info;

	DEBUG(4, ("push_conn_ctx(%llu) : conn_ctx_stack_ndx = %d\n",
		(unsigned long long)ctx_p->vuid, conn_ctx_stack_ndx));

	conn_ctx_stack_ndx++;
}

static void pop_conn_ctx(void)
{
	struct conn_ctx *ctx_p;

	/* Check for stack underflow. */

	if (conn_ctx_stack_ndx == 0) {
		DEBUG(0, ("Connection context stack underflow!\n"));
		smb_panic("Connection context stack underflow!\n");
	}

	conn_ctx_stack_ndx--;
	ctx_p = &conn_ctx_stack[conn_ctx_stack_ndx];

	set_current_user_info(ctx_p->user_info.smb_name,
			      ctx_p->user_info.unix_name,
			      ctx_p->user_info.domain);

	current_user.conn = ctx_p->conn;
	current_user.vuid = ctx_p->vuid;

	*ctx_p = (struct conn_ctx) {
		.vuid = UID_FIELD_INVALID,
	};
}

/****************************************************************************
 Temporarily become a root user.  Must match with unbecome_root(). Saves and
 restores the connection context.
****************************************************************************/

void smbd_become_root(void)
{
	 /*
	  * no good way to handle push_sec_ctx() failing without changing
	  * the prototype of become_root()
	  */
	if (!push_sec_ctx()) {
		smb_panic("become_root: push_sec_ctx failed");
	}
	push_conn_ctx();
	set_root_sec_ctx();
}

/* Unbecome the root user */

void smbd_unbecome_root(void)
{
	pop_sec_ctx();
	pop_conn_ctx();
}

/****************************************************************************
 Push the current security context then force a change via change_to_user().
 Saves and restores the connection context.
****************************************************************************/

bool become_user_without_service(connection_struct *conn, uint64_t vuid)
{
	struct auth_session_info *session_info = NULL;
	int snum = SNUM(conn);
	NTSTATUS status;
	bool ok;

	if (conn == NULL) {
		DBG_WARNING("Connection not open\n");
		return false;
	}

	status = smbXsrv_session_info_lookup(conn->sconn->client,
					     vuid,
					     &session_info);
	if (!NT_STATUS_IS_OK(status)) {
		/* Invalid vuid sent */
		DBG_WARNING("Invalid vuid %llu used on share %s.\n",
			    (unsigned long long)vuid,
			    lp_const_servicename(snum));
		return false;
	}

	ok = push_sec_ctx();
	if (!ok) {
		return false;
	}

	push_conn_ctx();

	ok = change_to_user_impersonate(conn, session_info, vuid);
	if (!ok) {
		pop_sec_ctx();
		pop_conn_ctx();
		return false;
	}

	return true;
}

bool become_user_without_service_by_fsp(struct files_struct *fsp)
{
	return become_user_without_service(fsp->conn, fsp->vuid);
}

bool become_user_without_service_by_session(connection_struct *conn,
			    const struct auth_session_info *session_info)
{
	bool ok;

	SMB_ASSERT(conn != NULL);
	SMB_ASSERT(session_info != NULL);

	ok = push_sec_ctx();
	if (!ok) {
		return false;
	}

	push_conn_ctx();

	ok = change_to_user_impersonate(conn, session_info, UID_FIELD_INVALID);
	if (!ok) {
		pop_sec_ctx();
		pop_conn_ctx();
		return false;
	}

	return true;
}

bool unbecome_user_without_service(void)
{
	pop_sec_ctx();
	pop_conn_ctx();
	return True;
}

/****************************************************************************
 Return the current user we are running effectively as on this connection.
 I'd like to make this return conn->session_info->unix_token->uid, but become_root()
 doesn't alter this value.
****************************************************************************/

uid_t get_current_uid(connection_struct *conn)
{
	return current_user.ut.uid;
}

/****************************************************************************
 Return the current group we are running effectively as on this connection.
 I'd like to make this return conn->session_info->unix_token->gid, but become_root()
 doesn't alter this value.
****************************************************************************/

gid_t get_current_gid(connection_struct *conn)
{
	return current_user.ut.gid;
}

/****************************************************************************
 Return the UNIX token we are running effectively as on this connection.
 I'd like to make this return &conn->session_info->unix_token-> but become_root()
 doesn't alter this value.
****************************************************************************/

const struct security_unix_token *get_current_utok(connection_struct *conn)
{
#ifdef KOS_NO_FORK /* our become_root is empty */
    return conn->session_info->unix_token;
#else
	return &current_user.ut;
#endif 
}

/****************************************************************************
 Return the Windows token we are running effectively as on this connection.
 If this is currently a NULL token as we're inside become_root() - a temporary
 UNIX security override, then we search up the stack for the previous active
 token.
****************************************************************************/

const struct security_token *get_current_nttok(connection_struct *conn)
{
	if (current_user.nt_user_token) {
		return current_user.nt_user_token;
	}
	return sec_ctx_active_token();
}
