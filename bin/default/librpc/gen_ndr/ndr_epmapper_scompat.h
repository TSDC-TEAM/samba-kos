#ifndef __NDR_EPMAPPER_SCOMPAT_H__
#define __NDR_EPMAPPER_SCOMPAT_H__

struct pipes_struct;
struct dcesrv_endpoint_server;
struct dcesrv_call_state;

const struct dcesrv_endpoint_server *epmapper_get_ep_server(void);

NTSTATUS epmapper__op_ndr_pull(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_pull *pull, void **r);
struct epm_Insert;
uint32_t _epm_Insert(struct pipes_struct *p, struct epm_Insert *r);
struct epm_Delete;
uint32_t _epm_Delete(struct pipes_struct *p, struct epm_Delete *r);
struct epm_Lookup;
uint32_t _epm_Lookup(struct pipes_struct *p, struct epm_Lookup *r);
struct epm_Map;
uint32_t _epm_Map(struct pipes_struct *p, struct epm_Map *r);
struct epm_LookupHandleFree;
uint32_t _epm_LookupHandleFree(struct pipes_struct *p, struct epm_LookupHandleFree *r);
struct epm_InqObject;
uint32_t _epm_InqObject(struct pipes_struct *p, struct epm_InqObject *r);
struct epm_MgmtDelete;
uint32_t _epm_MgmtDelete(struct pipes_struct *p, struct epm_MgmtDelete *r);
struct epm_MapAuth;
uint32_t _epm_MapAuth(struct pipes_struct *p, struct epm_MapAuth *r);
NTSTATUS epmapper__op_dispatch(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS epmapper__op_reply(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS epmapper__op_ndr_push(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_push *push, const void *r);
NTSTATUS epmapper__op_local(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
#endif /* __NDR_EPMAPPER_SCOMPAT_H__ */
