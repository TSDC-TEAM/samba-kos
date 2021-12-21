#ifndef __NDR_BROWSER_SCOMPAT_H__
#define __NDR_BROWSER_SCOMPAT_H__

struct pipes_struct;
struct dcesrv_endpoint_server;
struct dcesrv_call_state;

const struct dcesrv_endpoint_server *browser_get_ep_server(void);

NTSTATUS browser__op_ndr_pull(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_pull *pull, void **r);
struct BrowserrServerEnum;
void _BrowserrServerEnum(struct pipes_struct *p, struct BrowserrServerEnum *r);
struct BrowserrDebugCall;
void _BrowserrDebugCall(struct pipes_struct *p, struct BrowserrDebugCall *r);
struct BrowserrQueryOtherDomains;
WERROR _BrowserrQueryOtherDomains(struct pipes_struct *p, struct BrowserrQueryOtherDomains *r);
struct BrowserrResetNetlogonState;
void _BrowserrResetNetlogonState(struct pipes_struct *p, struct BrowserrResetNetlogonState *r);
struct BrowserrDebugTrace;
void _BrowserrDebugTrace(struct pipes_struct *p, struct BrowserrDebugTrace *r);
struct BrowserrQueryStatistics;
void _BrowserrQueryStatistics(struct pipes_struct *p, struct BrowserrQueryStatistics *r);
struct BrowserResetStatistics;
void _BrowserResetStatistics(struct pipes_struct *p, struct BrowserResetStatistics *r);
struct NetrBrowserStatisticsClear;
void _NetrBrowserStatisticsClear(struct pipes_struct *p, struct NetrBrowserStatisticsClear *r);
struct NetrBrowserStatisticsGet;
void _NetrBrowserStatisticsGet(struct pipes_struct *p, struct NetrBrowserStatisticsGet *r);
struct BrowserrSetNetlogonState;
void _BrowserrSetNetlogonState(struct pipes_struct *p, struct BrowserrSetNetlogonState *r);
struct BrowserrQueryEmulatedDomains;
void _BrowserrQueryEmulatedDomains(struct pipes_struct *p, struct BrowserrQueryEmulatedDomains *r);
struct BrowserrServerEnumEx;
void _BrowserrServerEnumEx(struct pipes_struct *p, struct BrowserrServerEnumEx *r);
NTSTATUS browser__op_dispatch(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS browser__op_reply(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS browser__op_ndr_push(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_push *push, const void *r);
NTSTATUS browser__op_local(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
#endif /* __NDR_BROWSER_SCOMPAT_H__ */
