#ifndef __NDR_FILESERVERVSSAGENT_SCOMPAT_H__
#define __NDR_FILESERVERVSSAGENT_SCOMPAT_H__

struct pipes_struct;
struct dcesrv_endpoint_server;
struct dcesrv_call_state;

const struct dcesrv_endpoint_server *FileServerVssAgent_get_ep_server(void);

NTSTATUS FileServerVssAgent__op_ndr_pull(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_pull *pull, void **r);
struct fss_GetSupportedVersion;
uint32_t _fss_GetSupportedVersion(struct pipes_struct *p, struct fss_GetSupportedVersion *r);
struct fss_SetContext;
uint32_t _fss_SetContext(struct pipes_struct *p, struct fss_SetContext *r);
struct fss_StartShadowCopySet;
uint32_t _fss_StartShadowCopySet(struct pipes_struct *p, struct fss_StartShadowCopySet *r);
struct fss_AddToShadowCopySet;
uint32_t _fss_AddToShadowCopySet(struct pipes_struct *p, struct fss_AddToShadowCopySet *r);
struct fss_CommitShadowCopySet;
uint32_t _fss_CommitShadowCopySet(struct pipes_struct *p, struct fss_CommitShadowCopySet *r);
struct fss_ExposeShadowCopySet;
uint32_t _fss_ExposeShadowCopySet(struct pipes_struct *p, struct fss_ExposeShadowCopySet *r);
struct fss_RecoveryCompleteShadowCopySet;
uint32_t _fss_RecoveryCompleteShadowCopySet(struct pipes_struct *p, struct fss_RecoveryCompleteShadowCopySet *r);
struct fss_AbortShadowCopySet;
uint32_t _fss_AbortShadowCopySet(struct pipes_struct *p, struct fss_AbortShadowCopySet *r);
struct fss_IsPathSupported;
uint32_t _fss_IsPathSupported(struct pipes_struct *p, struct fss_IsPathSupported *r);
struct fss_IsPathShadowCopied;
uint32_t _fss_IsPathShadowCopied(struct pipes_struct *p, struct fss_IsPathShadowCopied *r);
struct fss_GetShareMapping;
uint32_t _fss_GetShareMapping(struct pipes_struct *p, struct fss_GetShareMapping *r);
struct fss_DeleteShareMapping;
uint32_t _fss_DeleteShareMapping(struct pipes_struct *p, struct fss_DeleteShareMapping *r);
struct fss_PrepareShadowCopySet;
uint32_t _fss_PrepareShadowCopySet(struct pipes_struct *p, struct fss_PrepareShadowCopySet *r);
NTSTATUS FileServerVssAgent__op_dispatch(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS FileServerVssAgent__op_reply(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS FileServerVssAgent__op_ndr_push(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_push *push, const void *r);
NTSTATUS FileServerVssAgent__op_local(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
#endif /* __NDR_FILESERVERVSSAGENT_SCOMPAT_H__ */
