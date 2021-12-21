#ifndef __NDR_MDSSVC_SCOMPAT_H__
#define __NDR_MDSSVC_SCOMPAT_H__

struct pipes_struct;
struct dcesrv_endpoint_server;
struct dcesrv_call_state;

const struct dcesrv_endpoint_server *mdssvc_get_ep_server(void);

NTSTATUS mdssvc__op_ndr_pull(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_pull *pull, void **r);
struct mdssvc_open;
void _mdssvc_open(struct pipes_struct *p, struct mdssvc_open *r);
struct mdssvc_unknown1;
void _mdssvc_unknown1(struct pipes_struct *p, struct mdssvc_unknown1 *r);
struct mdssvc_cmd;
void _mdssvc_cmd(struct pipes_struct *p, struct mdssvc_cmd *r);
struct mdssvc_close;
void _mdssvc_close(struct pipes_struct *p, struct mdssvc_close *r);
NTSTATUS mdssvc__op_dispatch(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS mdssvc__op_reply(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS mdssvc__op_ndr_push(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_push *push, const void *r);
NTSTATUS mdssvc__op_local(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
#endif /* __NDR_MDSSVC_SCOMPAT_H__ */
