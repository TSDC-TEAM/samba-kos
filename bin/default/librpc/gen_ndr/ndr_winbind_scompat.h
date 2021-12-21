#ifndef __NDR_WINBIND_SCOMPAT_H__
#define __NDR_WINBIND_SCOMPAT_H__

struct pipes_struct;
struct dcesrv_endpoint_server;
struct dcesrv_call_state;

const struct dcesrv_endpoint_server *winbind_get_ep_server(void);

NTSTATUS winbind__op_ndr_pull(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_pull *pull, void **r);
struct wbint_Ping;
void _wbint_Ping(struct pipes_struct *p, struct wbint_Ping *r);
struct wbint_LookupSid;
NTSTATUS _wbint_LookupSid(struct pipes_struct *p, struct wbint_LookupSid *r);
struct wbint_LookupSids;
NTSTATUS _wbint_LookupSids(struct pipes_struct *p, struct wbint_LookupSids *r);
struct wbint_LookupName;
NTSTATUS _wbint_LookupName(struct pipes_struct *p, struct wbint_LookupName *r);
struct wbint_Sids2UnixIDs;
NTSTATUS _wbint_Sids2UnixIDs(struct pipes_struct *p, struct wbint_Sids2UnixIDs *r);
struct wbint_UnixIDs2Sids;
NTSTATUS _wbint_UnixIDs2Sids(struct pipes_struct *p, struct wbint_UnixIDs2Sids *r);
struct wbint_AllocateUid;
NTSTATUS _wbint_AllocateUid(struct pipes_struct *p, struct wbint_AllocateUid *r);
struct wbint_AllocateGid;
NTSTATUS _wbint_AllocateGid(struct pipes_struct *p, struct wbint_AllocateGid *r);
struct wbint_GetNssInfo;
NTSTATUS _wbint_GetNssInfo(struct pipes_struct *p, struct wbint_GetNssInfo *r);
struct wbint_LookupUserAliases;
NTSTATUS _wbint_LookupUserAliases(struct pipes_struct *p, struct wbint_LookupUserAliases *r);
struct wbint_LookupUserGroups;
NTSTATUS _wbint_LookupUserGroups(struct pipes_struct *p, struct wbint_LookupUserGroups *r);
struct wbint_QuerySequenceNumber;
NTSTATUS _wbint_QuerySequenceNumber(struct pipes_struct *p, struct wbint_QuerySequenceNumber *r);
struct wbint_LookupGroupMembers;
NTSTATUS _wbint_LookupGroupMembers(struct pipes_struct *p, struct wbint_LookupGroupMembers *r);
struct wbint_QueryGroupList;
NTSTATUS _wbint_QueryGroupList(struct pipes_struct *p, struct wbint_QueryGroupList *r);
struct wbint_QueryUserRidList;
NTSTATUS _wbint_QueryUserRidList(struct pipes_struct *p, struct wbint_QueryUserRidList *r);
struct wbint_DsGetDcName;
NTSTATUS _wbint_DsGetDcName(struct pipes_struct *p, struct wbint_DsGetDcName *r);
struct wbint_LookupRids;
NTSTATUS _wbint_LookupRids(struct pipes_struct *p, struct wbint_LookupRids *r);
struct wbint_CheckMachineAccount;
NTSTATUS _wbint_CheckMachineAccount(struct pipes_struct *p, struct wbint_CheckMachineAccount *r);
struct wbint_ChangeMachineAccount;
NTSTATUS _wbint_ChangeMachineAccount(struct pipes_struct *p, struct wbint_ChangeMachineAccount *r);
struct wbint_PingDc;
NTSTATUS _wbint_PingDc(struct pipes_struct *p, struct wbint_PingDc *r);
struct winbind_SamLogon;
NTSTATUS _winbind_SamLogon(struct pipes_struct *p, struct winbind_SamLogon *r);
struct winbind_DsrUpdateReadOnlyServerDnsRecords;
NTSTATUS _winbind_DsrUpdateReadOnlyServerDnsRecords(struct pipes_struct *p, struct winbind_DsrUpdateReadOnlyServerDnsRecords *r);
struct winbind_LogonControl;
WERROR _winbind_LogonControl(struct pipes_struct *p, struct winbind_LogonControl *r);
struct winbind_GetForestTrustInformation;
WERROR _winbind_GetForestTrustInformation(struct pipes_struct *p, struct winbind_GetForestTrustInformation *r);
struct winbind_SendToSam;
NTSTATUS _winbind_SendToSam(struct pipes_struct *p, struct winbind_SendToSam *r);
NTSTATUS winbind__op_dispatch(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS winbind__op_reply(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS winbind__op_ndr_push(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_push *push, const void *r);
NTSTATUS winbind__op_local(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
#endif /* __NDR_WINBIND_SCOMPAT_H__ */
