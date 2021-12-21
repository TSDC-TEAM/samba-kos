#ifndef __NDR_NETDFS_SCOMPAT_H__
#define __NDR_NETDFS_SCOMPAT_H__

struct pipes_struct;
struct dcesrv_endpoint_server;
struct dcesrv_call_state;

const struct dcesrv_endpoint_server *netdfs_get_ep_server(void);

NTSTATUS netdfs__op_ndr_pull(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_pull *pull, void **r);
struct dfs_GetManagerVersion;
void _dfs_GetManagerVersion(struct pipes_struct *p, struct dfs_GetManagerVersion *r);
struct dfs_Add;
WERROR _dfs_Add(struct pipes_struct *p, struct dfs_Add *r);
struct dfs_Remove;
WERROR _dfs_Remove(struct pipes_struct *p, struct dfs_Remove *r);
struct dfs_SetInfo;
WERROR _dfs_SetInfo(struct pipes_struct *p, struct dfs_SetInfo *r);
struct dfs_GetInfo;
WERROR _dfs_GetInfo(struct pipes_struct *p, struct dfs_GetInfo *r);
struct dfs_Enum;
WERROR _dfs_Enum(struct pipes_struct *p, struct dfs_Enum *r);
struct dfs_Rename;
WERROR _dfs_Rename(struct pipes_struct *p, struct dfs_Rename *r);
struct dfs_Move;
WERROR _dfs_Move(struct pipes_struct *p, struct dfs_Move *r);
struct dfs_ManagerGetConfigInfo;
WERROR _dfs_ManagerGetConfigInfo(struct pipes_struct *p, struct dfs_ManagerGetConfigInfo *r);
struct dfs_ManagerSendSiteInfo;
WERROR _dfs_ManagerSendSiteInfo(struct pipes_struct *p, struct dfs_ManagerSendSiteInfo *r);
struct dfs_AddFtRoot;
WERROR _dfs_AddFtRoot(struct pipes_struct *p, struct dfs_AddFtRoot *r);
struct dfs_RemoveFtRoot;
WERROR _dfs_RemoveFtRoot(struct pipes_struct *p, struct dfs_RemoveFtRoot *r);
struct dfs_AddStdRoot;
WERROR _dfs_AddStdRoot(struct pipes_struct *p, struct dfs_AddStdRoot *r);
struct dfs_RemoveStdRoot;
WERROR _dfs_RemoveStdRoot(struct pipes_struct *p, struct dfs_RemoveStdRoot *r);
struct dfs_ManagerInitialize;
WERROR _dfs_ManagerInitialize(struct pipes_struct *p, struct dfs_ManagerInitialize *r);
struct dfs_AddStdRootForced;
WERROR _dfs_AddStdRootForced(struct pipes_struct *p, struct dfs_AddStdRootForced *r);
struct dfs_GetDcAddress;
WERROR _dfs_GetDcAddress(struct pipes_struct *p, struct dfs_GetDcAddress *r);
struct dfs_SetDcAddress;
WERROR _dfs_SetDcAddress(struct pipes_struct *p, struct dfs_SetDcAddress *r);
struct dfs_FlushFtTable;
WERROR _dfs_FlushFtTable(struct pipes_struct *p, struct dfs_FlushFtTable *r);
struct dfs_Add2;
WERROR _dfs_Add2(struct pipes_struct *p, struct dfs_Add2 *r);
struct dfs_Remove2;
WERROR _dfs_Remove2(struct pipes_struct *p, struct dfs_Remove2 *r);
struct dfs_EnumEx;
WERROR _dfs_EnumEx(struct pipes_struct *p, struct dfs_EnumEx *r);
struct dfs_SetInfo2;
WERROR _dfs_SetInfo2(struct pipes_struct *p, struct dfs_SetInfo2 *r);
NTSTATUS netdfs__op_dispatch(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS netdfs__op_reply(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS netdfs__op_ndr_push(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_push *push, const void *r);
NTSTATUS netdfs__op_local(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
#endif /* __NDR_NETDFS_SCOMPAT_H__ */
