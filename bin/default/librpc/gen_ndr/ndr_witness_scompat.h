#ifndef __NDR_WITNESS_SCOMPAT_H__
#define __NDR_WITNESS_SCOMPAT_H__

struct pipes_struct;
struct dcesrv_endpoint_server;
struct dcesrv_call_state;

const struct dcesrv_endpoint_server *witness_get_ep_server(void);

NTSTATUS witness__op_ndr_pull(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_pull *pull, void **r);
struct witness_GetInterfaceList;
WERROR _witness_GetInterfaceList(struct pipes_struct *p, struct witness_GetInterfaceList *r);
struct witness_Register;
WERROR _witness_Register(struct pipes_struct *p, struct witness_Register *r);
struct witness_UnRegister;
WERROR _witness_UnRegister(struct pipes_struct *p, struct witness_UnRegister *r);
struct witness_AsyncNotify;
WERROR _witness_AsyncNotify(struct pipes_struct *p, struct witness_AsyncNotify *r);
struct witness_RegisterEx;
WERROR _witness_RegisterEx(struct pipes_struct *p, struct witness_RegisterEx *r);
NTSTATUS witness__op_dispatch(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS witness__op_reply(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS witness__op_ndr_push(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_push *push, const void *r);
NTSTATUS witness__op_local(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
#endif /* __NDR_WITNESS_SCOMPAT_H__ */
