#ifndef __NDR_DRSUAPI_SCOMPAT_H__
#define __NDR_DRSUAPI_SCOMPAT_H__

struct pipes_struct;
struct dcesrv_endpoint_server;
struct dcesrv_call_state;

const struct dcesrv_endpoint_server *drsuapi_get_ep_server(void);

NTSTATUS drsuapi__op_ndr_pull(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_pull *pull, void **r);
struct drsuapi_DsBind;
WERROR _drsuapi_DsBind(struct pipes_struct *p, struct drsuapi_DsBind *r);
struct drsuapi_DsUnbind;
WERROR _drsuapi_DsUnbind(struct pipes_struct *p, struct drsuapi_DsUnbind *r);
struct drsuapi_DsReplicaSync;
WERROR _drsuapi_DsReplicaSync(struct pipes_struct *p, struct drsuapi_DsReplicaSync *r);
struct drsuapi_DsGetNCChanges;
WERROR _drsuapi_DsGetNCChanges(struct pipes_struct *p, struct drsuapi_DsGetNCChanges *r);
struct drsuapi_DsReplicaUpdateRefs;
WERROR _drsuapi_DsReplicaUpdateRefs(struct pipes_struct *p, struct drsuapi_DsReplicaUpdateRefs *r);
struct drsuapi_DsReplicaAdd;
WERROR _drsuapi_DsReplicaAdd(struct pipes_struct *p, struct drsuapi_DsReplicaAdd *r);
struct drsuapi_DsReplicaDel;
WERROR _drsuapi_DsReplicaDel(struct pipes_struct *p, struct drsuapi_DsReplicaDel *r);
struct drsuapi_DsReplicaMod;
WERROR _drsuapi_DsReplicaMod(struct pipes_struct *p, struct drsuapi_DsReplicaMod *r);
struct DRSUAPI_VERIFY_NAMES;
WERROR _DRSUAPI_VERIFY_NAMES(struct pipes_struct *p, struct DRSUAPI_VERIFY_NAMES *r);
struct drsuapi_DsGetMemberships;
WERROR _drsuapi_DsGetMemberships(struct pipes_struct *p, struct drsuapi_DsGetMemberships *r);
struct DRSUAPI_INTER_DOMAIN_MOVE;
WERROR _DRSUAPI_INTER_DOMAIN_MOVE(struct pipes_struct *p, struct DRSUAPI_INTER_DOMAIN_MOVE *r);
struct drsuapi_DsGetNT4ChangeLog;
WERROR _drsuapi_DsGetNT4ChangeLog(struct pipes_struct *p, struct drsuapi_DsGetNT4ChangeLog *r);
struct drsuapi_DsCrackNames;
WERROR _drsuapi_DsCrackNames(struct pipes_struct *p, struct drsuapi_DsCrackNames *r);
struct drsuapi_DsWriteAccountSpn;
WERROR _drsuapi_DsWriteAccountSpn(struct pipes_struct *p, struct drsuapi_DsWriteAccountSpn *r);
struct drsuapi_DsRemoveDSServer;
WERROR _drsuapi_DsRemoveDSServer(struct pipes_struct *p, struct drsuapi_DsRemoveDSServer *r);
struct DRSUAPI_REMOVE_DS_DOMAIN;
WERROR _DRSUAPI_REMOVE_DS_DOMAIN(struct pipes_struct *p, struct DRSUAPI_REMOVE_DS_DOMAIN *r);
struct drsuapi_DsGetDomainControllerInfo;
WERROR _drsuapi_DsGetDomainControllerInfo(struct pipes_struct *p, struct drsuapi_DsGetDomainControllerInfo *r);
struct drsuapi_DsAddEntry;
WERROR _drsuapi_DsAddEntry(struct pipes_struct *p, struct drsuapi_DsAddEntry *r);
struct drsuapi_DsExecuteKCC;
WERROR _drsuapi_DsExecuteKCC(struct pipes_struct *p, struct drsuapi_DsExecuteKCC *r);
struct drsuapi_DsReplicaGetInfo;
WERROR _drsuapi_DsReplicaGetInfo(struct pipes_struct *p, struct drsuapi_DsReplicaGetInfo *r);
struct DRSUAPI_ADD_SID_HISTORY;
WERROR _DRSUAPI_ADD_SID_HISTORY(struct pipes_struct *p, struct DRSUAPI_ADD_SID_HISTORY *r);
struct drsuapi_DsGetMemberships2;
WERROR _drsuapi_DsGetMemberships2(struct pipes_struct *p, struct drsuapi_DsGetMemberships2 *r);
struct DRSUAPI_REPLICA_VERIFY_OBJECTS;
WERROR _DRSUAPI_REPLICA_VERIFY_OBJECTS(struct pipes_struct *p, struct DRSUAPI_REPLICA_VERIFY_OBJECTS *r);
struct DRSUAPI_GET_OBJECT_EXISTENCE;
WERROR _DRSUAPI_GET_OBJECT_EXISTENCE(struct pipes_struct *p, struct DRSUAPI_GET_OBJECT_EXISTENCE *r);
struct drsuapi_QuerySitesByCost;
WERROR _drsuapi_QuerySitesByCost(struct pipes_struct *p, struct drsuapi_QuerySitesByCost *r);
NTSTATUS drsuapi__op_dispatch(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS drsuapi__op_reply(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS drsuapi__op_ndr_push(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_push *push, const void *r);
NTSTATUS drsuapi__op_local(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
#endif /* __NDR_DRSUAPI_SCOMPAT_H__ */
