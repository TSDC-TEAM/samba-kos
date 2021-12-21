#ifndef __NDR_RPCECHO_SCOMPAT_H__
#define __NDR_RPCECHO_SCOMPAT_H__

struct pipes_struct;
struct dcesrv_endpoint_server;
struct dcesrv_call_state;

const struct dcesrv_endpoint_server *rpcecho_get_ep_server(void);

NTSTATUS rpcecho__op_ndr_pull(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_pull *pull, void **r);
struct echo_AddOne;
void _echo_AddOne(struct pipes_struct *p, struct echo_AddOne *r);
struct echo_EchoData;
void _echo_EchoData(struct pipes_struct *p, struct echo_EchoData *r);
struct echo_SinkData;
void _echo_SinkData(struct pipes_struct *p, struct echo_SinkData *r);
struct echo_SourceData;
void _echo_SourceData(struct pipes_struct *p, struct echo_SourceData *r);
struct echo_TestCall;
void _echo_TestCall(struct pipes_struct *p, struct echo_TestCall *r);
struct echo_TestCall2;
NTSTATUS _echo_TestCall2(struct pipes_struct *p, struct echo_TestCall2 *r);
struct echo_TestSleep;
uint32_t _echo_TestSleep(struct pipes_struct *p, struct echo_TestSleep *r);
struct echo_TestEnum;
void _echo_TestEnum(struct pipes_struct *p, struct echo_TestEnum *r);
struct echo_TestSurrounding;
void _echo_TestSurrounding(struct pipes_struct *p, struct echo_TestSurrounding *r);
struct echo_TestDoublePointer;
uint16_t _echo_TestDoublePointer(struct pipes_struct *p, struct echo_TestDoublePointer *r);
NTSTATUS rpcecho__op_dispatch(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS rpcecho__op_reply(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS rpcecho__op_ndr_push(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_push *push, const void *r);
NTSTATUS rpcecho__op_local(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
#endif /* __NDR_RPCECHO_SCOMPAT_H__ */
