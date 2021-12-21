#ifndef __NDR_BACKUPKEY_SCOMPAT_H__
#define __NDR_BACKUPKEY_SCOMPAT_H__

struct pipes_struct;
struct dcesrv_endpoint_server;
struct dcesrv_call_state;

const struct dcesrv_endpoint_server *backupkey_get_ep_server(void);

NTSTATUS backupkey__op_ndr_pull(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_pull *pull, void **r);
struct bkrp_BackupKey;
WERROR _bkrp_BackupKey(struct pipes_struct *p, struct bkrp_BackupKey *r);
NTSTATUS backupkey__op_dispatch(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS backupkey__op_reply(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS backupkey__op_ndr_push(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_push *push, const void *r);
NTSTATUS backupkey__op_local(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
#endif /* __NDR_BACKUPKEY_SCOMPAT_H__ */
