#ifndef __NDR_LSARPC_SCOMPAT_H__
#define __NDR_LSARPC_SCOMPAT_H__

struct pipes_struct;
struct dcesrv_endpoint_server;
struct dcesrv_call_state;

const struct dcesrv_endpoint_server *lsarpc_get_ep_server(void);

NTSTATUS lsarpc__op_ndr_pull(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_pull *pull, void **r);
struct lsa_Close;
NTSTATUS _lsa_Close(struct pipes_struct *p, struct lsa_Close *r);
struct lsa_Delete;
NTSTATUS _lsa_Delete(struct pipes_struct *p, struct lsa_Delete *r);
struct lsa_EnumPrivs;
NTSTATUS _lsa_EnumPrivs(struct pipes_struct *p, struct lsa_EnumPrivs *r);
struct lsa_QuerySecurity;
NTSTATUS _lsa_QuerySecurity(struct pipes_struct *p, struct lsa_QuerySecurity *r);
struct lsa_SetSecObj;
NTSTATUS _lsa_SetSecObj(struct pipes_struct *p, struct lsa_SetSecObj *r);
struct lsa_ChangePassword;
NTSTATUS _lsa_ChangePassword(struct pipes_struct *p, struct lsa_ChangePassword *r);
struct lsa_OpenPolicy;
NTSTATUS _lsa_OpenPolicy(struct pipes_struct *p, struct lsa_OpenPolicy *r);
struct lsa_QueryInfoPolicy;
NTSTATUS _lsa_QueryInfoPolicy(struct pipes_struct *p, struct lsa_QueryInfoPolicy *r);
struct lsa_SetInfoPolicy;
NTSTATUS _lsa_SetInfoPolicy(struct pipes_struct *p, struct lsa_SetInfoPolicy *r);
struct lsa_ClearAuditLog;
NTSTATUS _lsa_ClearAuditLog(struct pipes_struct *p, struct lsa_ClearAuditLog *r);
struct lsa_CreateAccount;
NTSTATUS _lsa_CreateAccount(struct pipes_struct *p, struct lsa_CreateAccount *r);
struct lsa_EnumAccounts;
NTSTATUS _lsa_EnumAccounts(struct pipes_struct *p, struct lsa_EnumAccounts *r);
struct lsa_CreateTrustedDomain;
NTSTATUS _lsa_CreateTrustedDomain(struct pipes_struct *p, struct lsa_CreateTrustedDomain *r);
struct lsa_EnumTrustDom;
NTSTATUS _lsa_EnumTrustDom(struct pipes_struct *p, struct lsa_EnumTrustDom *r);
struct lsa_LookupNames;
NTSTATUS _lsa_LookupNames(struct pipes_struct *p, struct lsa_LookupNames *r);
struct lsa_LookupSids;
NTSTATUS _lsa_LookupSids(struct pipes_struct *p, struct lsa_LookupSids *r);
struct lsa_CreateSecret;
NTSTATUS _lsa_CreateSecret(struct pipes_struct *p, struct lsa_CreateSecret *r);
struct lsa_OpenAccount;
NTSTATUS _lsa_OpenAccount(struct pipes_struct *p, struct lsa_OpenAccount *r);
struct lsa_EnumPrivsAccount;
NTSTATUS _lsa_EnumPrivsAccount(struct pipes_struct *p, struct lsa_EnumPrivsAccount *r);
struct lsa_AddPrivilegesToAccount;
NTSTATUS _lsa_AddPrivilegesToAccount(struct pipes_struct *p, struct lsa_AddPrivilegesToAccount *r);
struct lsa_RemovePrivilegesFromAccount;
NTSTATUS _lsa_RemovePrivilegesFromAccount(struct pipes_struct *p, struct lsa_RemovePrivilegesFromAccount *r);
struct lsa_GetQuotasForAccount;
NTSTATUS _lsa_GetQuotasForAccount(struct pipes_struct *p, struct lsa_GetQuotasForAccount *r);
struct lsa_SetQuotasForAccount;
NTSTATUS _lsa_SetQuotasForAccount(struct pipes_struct *p, struct lsa_SetQuotasForAccount *r);
struct lsa_GetSystemAccessAccount;
NTSTATUS _lsa_GetSystemAccessAccount(struct pipes_struct *p, struct lsa_GetSystemAccessAccount *r);
struct lsa_SetSystemAccessAccount;
NTSTATUS _lsa_SetSystemAccessAccount(struct pipes_struct *p, struct lsa_SetSystemAccessAccount *r);
struct lsa_OpenTrustedDomain;
NTSTATUS _lsa_OpenTrustedDomain(struct pipes_struct *p, struct lsa_OpenTrustedDomain *r);
struct lsa_QueryTrustedDomainInfo;
NTSTATUS _lsa_QueryTrustedDomainInfo(struct pipes_struct *p, struct lsa_QueryTrustedDomainInfo *r);
struct lsa_SetInformationTrustedDomain;
NTSTATUS _lsa_SetInformationTrustedDomain(struct pipes_struct *p, struct lsa_SetInformationTrustedDomain *r);
struct lsa_OpenSecret;
NTSTATUS _lsa_OpenSecret(struct pipes_struct *p, struct lsa_OpenSecret *r);
struct lsa_SetSecret;
NTSTATUS _lsa_SetSecret(struct pipes_struct *p, struct lsa_SetSecret *r);
struct lsa_QuerySecret;
NTSTATUS _lsa_QuerySecret(struct pipes_struct *p, struct lsa_QuerySecret *r);
struct lsa_LookupPrivValue;
NTSTATUS _lsa_LookupPrivValue(struct pipes_struct *p, struct lsa_LookupPrivValue *r);
struct lsa_LookupPrivName;
NTSTATUS _lsa_LookupPrivName(struct pipes_struct *p, struct lsa_LookupPrivName *r);
struct lsa_LookupPrivDisplayName;
NTSTATUS _lsa_LookupPrivDisplayName(struct pipes_struct *p, struct lsa_LookupPrivDisplayName *r);
struct lsa_DeleteObject;
NTSTATUS _lsa_DeleteObject(struct pipes_struct *p, struct lsa_DeleteObject *r);
struct lsa_EnumAccountsWithUserRight;
NTSTATUS _lsa_EnumAccountsWithUserRight(struct pipes_struct *p, struct lsa_EnumAccountsWithUserRight *r);
struct lsa_EnumAccountRights;
NTSTATUS _lsa_EnumAccountRights(struct pipes_struct *p, struct lsa_EnumAccountRights *r);
struct lsa_AddAccountRights;
NTSTATUS _lsa_AddAccountRights(struct pipes_struct *p, struct lsa_AddAccountRights *r);
struct lsa_RemoveAccountRights;
NTSTATUS _lsa_RemoveAccountRights(struct pipes_struct *p, struct lsa_RemoveAccountRights *r);
struct lsa_QueryTrustedDomainInfoBySid;
NTSTATUS _lsa_QueryTrustedDomainInfoBySid(struct pipes_struct *p, struct lsa_QueryTrustedDomainInfoBySid *r);
struct lsa_SetTrustedDomainInfo;
NTSTATUS _lsa_SetTrustedDomainInfo(struct pipes_struct *p, struct lsa_SetTrustedDomainInfo *r);
struct lsa_DeleteTrustedDomain;
NTSTATUS _lsa_DeleteTrustedDomain(struct pipes_struct *p, struct lsa_DeleteTrustedDomain *r);
struct lsa_StorePrivateData;
NTSTATUS _lsa_StorePrivateData(struct pipes_struct *p, struct lsa_StorePrivateData *r);
struct lsa_RetrievePrivateData;
NTSTATUS _lsa_RetrievePrivateData(struct pipes_struct *p, struct lsa_RetrievePrivateData *r);
struct lsa_OpenPolicy2;
NTSTATUS _lsa_OpenPolicy2(struct pipes_struct *p, struct lsa_OpenPolicy2 *r);
struct lsa_GetUserName;
NTSTATUS _lsa_GetUserName(struct pipes_struct *p, struct lsa_GetUserName *r);
struct lsa_QueryInfoPolicy2;
NTSTATUS _lsa_QueryInfoPolicy2(struct pipes_struct *p, struct lsa_QueryInfoPolicy2 *r);
struct lsa_SetInfoPolicy2;
NTSTATUS _lsa_SetInfoPolicy2(struct pipes_struct *p, struct lsa_SetInfoPolicy2 *r);
struct lsa_QueryTrustedDomainInfoByName;
NTSTATUS _lsa_QueryTrustedDomainInfoByName(struct pipes_struct *p, struct lsa_QueryTrustedDomainInfoByName *r);
struct lsa_SetTrustedDomainInfoByName;
NTSTATUS _lsa_SetTrustedDomainInfoByName(struct pipes_struct *p, struct lsa_SetTrustedDomainInfoByName *r);
struct lsa_EnumTrustedDomainsEx;
NTSTATUS _lsa_EnumTrustedDomainsEx(struct pipes_struct *p, struct lsa_EnumTrustedDomainsEx *r);
struct lsa_CreateTrustedDomainEx;
NTSTATUS _lsa_CreateTrustedDomainEx(struct pipes_struct *p, struct lsa_CreateTrustedDomainEx *r);
struct lsa_CloseTrustedDomainEx;
NTSTATUS _lsa_CloseTrustedDomainEx(struct pipes_struct *p, struct lsa_CloseTrustedDomainEx *r);
struct lsa_QueryDomainInformationPolicy;
NTSTATUS _lsa_QueryDomainInformationPolicy(struct pipes_struct *p, struct lsa_QueryDomainInformationPolicy *r);
struct lsa_SetDomainInformationPolicy;
NTSTATUS _lsa_SetDomainInformationPolicy(struct pipes_struct *p, struct lsa_SetDomainInformationPolicy *r);
struct lsa_OpenTrustedDomainByName;
NTSTATUS _lsa_OpenTrustedDomainByName(struct pipes_struct *p, struct lsa_OpenTrustedDomainByName *r);
struct lsa_TestCall;
NTSTATUS _lsa_TestCall(struct pipes_struct *p, struct lsa_TestCall *r);
struct lsa_LookupSids2;
NTSTATUS _lsa_LookupSids2(struct pipes_struct *p, struct lsa_LookupSids2 *r);
struct lsa_LookupNames2;
NTSTATUS _lsa_LookupNames2(struct pipes_struct *p, struct lsa_LookupNames2 *r);
struct lsa_CreateTrustedDomainEx2;
NTSTATUS _lsa_CreateTrustedDomainEx2(struct pipes_struct *p, struct lsa_CreateTrustedDomainEx2 *r);
struct lsa_CREDRWRITE;
NTSTATUS _lsa_CREDRWRITE(struct pipes_struct *p, struct lsa_CREDRWRITE *r);
struct lsa_CREDRREAD;
NTSTATUS _lsa_CREDRREAD(struct pipes_struct *p, struct lsa_CREDRREAD *r);
struct lsa_CREDRENUMERATE;
NTSTATUS _lsa_CREDRENUMERATE(struct pipes_struct *p, struct lsa_CREDRENUMERATE *r);
struct lsa_CREDRWRITEDOMAINCREDENTIALS;
NTSTATUS _lsa_CREDRWRITEDOMAINCREDENTIALS(struct pipes_struct *p, struct lsa_CREDRWRITEDOMAINCREDENTIALS *r);
struct lsa_CREDRREADDOMAINCREDENTIALS;
NTSTATUS _lsa_CREDRREADDOMAINCREDENTIALS(struct pipes_struct *p, struct lsa_CREDRREADDOMAINCREDENTIALS *r);
struct lsa_CREDRDELETE;
NTSTATUS _lsa_CREDRDELETE(struct pipes_struct *p, struct lsa_CREDRDELETE *r);
struct lsa_CREDRGETTARGETINFO;
NTSTATUS _lsa_CREDRGETTARGETINFO(struct pipes_struct *p, struct lsa_CREDRGETTARGETINFO *r);
struct lsa_CREDRPROFILELOADED;
NTSTATUS _lsa_CREDRPROFILELOADED(struct pipes_struct *p, struct lsa_CREDRPROFILELOADED *r);
struct lsa_LookupNames3;
NTSTATUS _lsa_LookupNames3(struct pipes_struct *p, struct lsa_LookupNames3 *r);
struct lsa_CREDRGETSESSIONTYPES;
NTSTATUS _lsa_CREDRGETSESSIONTYPES(struct pipes_struct *p, struct lsa_CREDRGETSESSIONTYPES *r);
struct lsa_LSARREGISTERAUDITEVENT;
NTSTATUS _lsa_LSARREGISTERAUDITEVENT(struct pipes_struct *p, struct lsa_LSARREGISTERAUDITEVENT *r);
struct lsa_LSARGENAUDITEVENT;
NTSTATUS _lsa_LSARGENAUDITEVENT(struct pipes_struct *p, struct lsa_LSARGENAUDITEVENT *r);
struct lsa_LSARUNREGISTERAUDITEVENT;
NTSTATUS _lsa_LSARUNREGISTERAUDITEVENT(struct pipes_struct *p, struct lsa_LSARUNREGISTERAUDITEVENT *r);
struct lsa_lsaRQueryForestTrustInformation;
NTSTATUS _lsa_lsaRQueryForestTrustInformation(struct pipes_struct *p, struct lsa_lsaRQueryForestTrustInformation *r);
struct lsa_lsaRSetForestTrustInformation;
NTSTATUS _lsa_lsaRSetForestTrustInformation(struct pipes_struct *p, struct lsa_lsaRSetForestTrustInformation *r);
struct lsa_CREDRRENAME;
NTSTATUS _lsa_CREDRRENAME(struct pipes_struct *p, struct lsa_CREDRRENAME *r);
struct lsa_LookupSids3;
NTSTATUS _lsa_LookupSids3(struct pipes_struct *p, struct lsa_LookupSids3 *r);
struct lsa_LookupNames4;
NTSTATUS _lsa_LookupNames4(struct pipes_struct *p, struct lsa_LookupNames4 *r);
struct lsa_LSAROPENPOLICYSCE;
NTSTATUS _lsa_LSAROPENPOLICYSCE(struct pipes_struct *p, struct lsa_LSAROPENPOLICYSCE *r);
struct lsa_LSARADTREGISTERSECURITYEVENTSOURCE;
NTSTATUS _lsa_LSARADTREGISTERSECURITYEVENTSOURCE(struct pipes_struct *p, struct lsa_LSARADTREGISTERSECURITYEVENTSOURCE *r);
struct lsa_LSARADTUNREGISTERSECURITYEVENTSOURCE;
NTSTATUS _lsa_LSARADTUNREGISTERSECURITYEVENTSOURCE(struct pipes_struct *p, struct lsa_LSARADTUNREGISTERSECURITYEVENTSOURCE *r);
struct lsa_LSARADTREPORTSECURITYEVENT;
NTSTATUS _lsa_LSARADTREPORTSECURITYEVENT(struct pipes_struct *p, struct lsa_LSARADTREPORTSECURITYEVENT *r);
NTSTATUS lsarpc__op_dispatch(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS lsarpc__op_reply(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS lsarpc__op_ndr_push(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_push *push, const void *r);
NTSTATUS lsarpc__op_local(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
#endif /* __NDR_LSARPC_SCOMPAT_H__ */
