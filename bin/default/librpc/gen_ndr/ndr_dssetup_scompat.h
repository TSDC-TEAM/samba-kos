#ifndef __NDR_DSSETUP_SCOMPAT_H__
#define __NDR_DSSETUP_SCOMPAT_H__

struct pipes_struct;
struct dcesrv_endpoint_server;
struct dcesrv_call_state;

const struct dcesrv_endpoint_server *dssetup_get_ep_server(void);

NTSTATUS dssetup__op_ndr_pull(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_pull *pull, void **r);
struct dssetup_DsRoleGetPrimaryDomainInformation;
WERROR _dssetup_DsRoleGetPrimaryDomainInformation(struct pipes_struct *p, struct dssetup_DsRoleGetPrimaryDomainInformation *r);
struct dssetup_DsRoleDnsNameToFlatName;
WERROR _dssetup_DsRoleDnsNameToFlatName(struct pipes_struct *p, struct dssetup_DsRoleDnsNameToFlatName *r);
struct dssetup_DsRoleDcAsDc;
WERROR _dssetup_DsRoleDcAsDc(struct pipes_struct *p, struct dssetup_DsRoleDcAsDc *r);
struct dssetup_DsRoleDcAsReplica;
WERROR _dssetup_DsRoleDcAsReplica(struct pipes_struct *p, struct dssetup_DsRoleDcAsReplica *r);
struct dssetup_DsRoleDemoteDc;
WERROR _dssetup_DsRoleDemoteDc(struct pipes_struct *p, struct dssetup_DsRoleDemoteDc *r);
struct dssetup_DsRoleGetDcOperationProgress;
WERROR _dssetup_DsRoleGetDcOperationProgress(struct pipes_struct *p, struct dssetup_DsRoleGetDcOperationProgress *r);
struct dssetup_DsRoleGetDcOperationResults;
WERROR _dssetup_DsRoleGetDcOperationResults(struct pipes_struct *p, struct dssetup_DsRoleGetDcOperationResults *r);
struct dssetup_DsRoleCancel;
WERROR _dssetup_DsRoleCancel(struct pipes_struct *p, struct dssetup_DsRoleCancel *r);
struct dssetup_DsRoleServerSaveStateForUpgrade;
WERROR _dssetup_DsRoleServerSaveStateForUpgrade(struct pipes_struct *p, struct dssetup_DsRoleServerSaveStateForUpgrade *r);
struct dssetup_DsRoleUpgradeDownlevelServer;
WERROR _dssetup_DsRoleUpgradeDownlevelServer(struct pipes_struct *p, struct dssetup_DsRoleUpgradeDownlevelServer *r);
struct dssetup_DsRoleAbortDownlevelServerUpgrade;
WERROR _dssetup_DsRoleAbortDownlevelServerUpgrade(struct pipes_struct *p, struct dssetup_DsRoleAbortDownlevelServerUpgrade *r);
NTSTATUS dssetup__op_dispatch(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS dssetup__op_reply(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS dssetup__op_ndr_push(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_push *push, const void *r);
NTSTATUS dssetup__op_local(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
#endif /* __NDR_DSSETUP_SCOMPAT_H__ */
