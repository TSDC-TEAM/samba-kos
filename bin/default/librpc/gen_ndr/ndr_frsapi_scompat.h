#ifndef __NDR_FRSAPI_SCOMPAT_H__
#define __NDR_FRSAPI_SCOMPAT_H__

struct pipes_struct;
struct dcesrv_endpoint_server;
struct dcesrv_call_state;

const struct dcesrv_endpoint_server *frsapi_get_ep_server(void);

NTSTATUS frsapi__op_ndr_pull(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_pull *pull, void **r);
struct FRSAPI_VERIFY_PROMOTION;
void _FRSAPI_VERIFY_PROMOTION(struct pipes_struct *p, struct FRSAPI_VERIFY_PROMOTION *r);
struct FRSAPI_PROMOTION_STATUS;
void _FRSAPI_PROMOTION_STATUS(struct pipes_struct *p, struct FRSAPI_PROMOTION_STATUS *r);
struct FRSAPI_START_DEMOTION;
void _FRSAPI_START_DEMOTION(struct pipes_struct *p, struct FRSAPI_START_DEMOTION *r);
struct FRSAPI_COMMIT_DEMOTION;
void _FRSAPI_COMMIT_DEMOTION(struct pipes_struct *p, struct FRSAPI_COMMIT_DEMOTION *r);
struct frsapi_SetDsPollingIntervalW;
WERROR _frsapi_SetDsPollingIntervalW(struct pipes_struct *p, struct frsapi_SetDsPollingIntervalW *r);
struct frsapi_GetDsPollingIntervalW;
WERROR _frsapi_GetDsPollingIntervalW(struct pipes_struct *p, struct frsapi_GetDsPollingIntervalW *r);
struct FRSAPI_VERIFY_PROMOTION_W;
void _FRSAPI_VERIFY_PROMOTION_W(struct pipes_struct *p, struct FRSAPI_VERIFY_PROMOTION_W *r);
struct frsapi_InfoW;
WERROR _frsapi_InfoW(struct pipes_struct *p, struct frsapi_InfoW *r);
struct frsapi_IsPathReplicated;
WERROR _frsapi_IsPathReplicated(struct pipes_struct *p, struct frsapi_IsPathReplicated *r);
struct frsapi_WriterCommand;
WERROR _frsapi_WriterCommand(struct pipes_struct *p, struct frsapi_WriterCommand *r);
struct frsapi_ForceReplication;
WERROR _frsapi_ForceReplication(struct pipes_struct *p, struct frsapi_ForceReplication *r);
NTSTATUS frsapi__op_dispatch(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS frsapi__op_reply(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS frsapi__op_ndr_push(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_push *push, const void *r);
NTSTATUS frsapi__op_local(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
#endif /* __NDR_FRSAPI_SCOMPAT_H__ */
