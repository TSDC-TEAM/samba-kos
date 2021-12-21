#ifndef __NDR_MGMT_SCOMPAT_H__
#define __NDR_MGMT_SCOMPAT_H__

struct pipes_struct;
struct dcesrv_endpoint_server;
struct dcesrv_call_state;

const struct dcesrv_endpoint_server *mgmt_get_ep_server(void);

NTSTATUS mgmt__op_ndr_pull(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_pull *pull, void **r);
struct mgmt_inq_if_ids;
WERROR _mgmt_inq_if_ids(struct pipes_struct *p, struct mgmt_inq_if_ids *r);
struct mgmt_inq_stats;
WERROR _mgmt_inq_stats(struct pipes_struct *p, struct mgmt_inq_stats *r);
struct mgmt_is_server_listening;
uint32_t _mgmt_is_server_listening(struct pipes_struct *p, struct mgmt_is_server_listening *r);
struct mgmt_stop_server_listening;
WERROR _mgmt_stop_server_listening(struct pipes_struct *p, struct mgmt_stop_server_listening *r);
struct mgmt_inq_princ_name;
WERROR _mgmt_inq_princ_name(struct pipes_struct *p, struct mgmt_inq_princ_name *r);
NTSTATUS mgmt__op_dispatch(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS mgmt__op_reply(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS mgmt__op_ndr_push(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_push *push, const void *r);
NTSTATUS mgmt__op_local(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
#endif /* __NDR_MGMT_SCOMPAT_H__ */
