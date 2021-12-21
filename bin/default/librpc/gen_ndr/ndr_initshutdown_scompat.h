#ifndef __NDR_INITSHUTDOWN_SCOMPAT_H__
#define __NDR_INITSHUTDOWN_SCOMPAT_H__

struct pipes_struct;
struct dcesrv_endpoint_server;
struct dcesrv_call_state;

const struct dcesrv_endpoint_server *initshutdown_get_ep_server(void);

NTSTATUS initshutdown__op_ndr_pull(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_pull *pull, void **r);
struct initshutdown_Init;
WERROR _initshutdown_Init(struct pipes_struct *p, struct initshutdown_Init *r);
struct initshutdown_Abort;
WERROR _initshutdown_Abort(struct pipes_struct *p, struct initshutdown_Abort *r);
struct initshutdown_InitEx;
WERROR _initshutdown_InitEx(struct pipes_struct *p, struct initshutdown_InitEx *r);
NTSTATUS initshutdown__op_dispatch(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS initshutdown__op_reply(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS initshutdown__op_ndr_push(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_push *push, const void *r);
NTSTATUS initshutdown__op_local(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
#endif /* __NDR_INITSHUTDOWN_SCOMPAT_H__ */
