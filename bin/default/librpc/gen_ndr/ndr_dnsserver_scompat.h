#ifndef __NDR_DNSSERVER_SCOMPAT_H__
#define __NDR_DNSSERVER_SCOMPAT_H__

struct pipes_struct;
struct dcesrv_endpoint_server;
struct dcesrv_call_state;

const struct dcesrv_endpoint_server *dnsserver_get_ep_server(void);

NTSTATUS dnsserver__op_ndr_pull(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_pull *pull, void **r);
struct DnssrvOperation;
WERROR _DnssrvOperation(struct pipes_struct *p, struct DnssrvOperation *r);
struct DnssrvQuery;
WERROR _DnssrvQuery(struct pipes_struct *p, struct DnssrvQuery *r);
struct DnssrvComplexOperation;
WERROR _DnssrvComplexOperation(struct pipes_struct *p, struct DnssrvComplexOperation *r);
struct DnssrvEnumRecords;
WERROR _DnssrvEnumRecords(struct pipes_struct *p, struct DnssrvEnumRecords *r);
struct DnssrvUpdateRecord;
WERROR _DnssrvUpdateRecord(struct pipes_struct *p, struct DnssrvUpdateRecord *r);
struct DnssrvOperation2;
WERROR _DnssrvOperation2(struct pipes_struct *p, struct DnssrvOperation2 *r);
struct DnssrvQuery2;
WERROR _DnssrvQuery2(struct pipes_struct *p, struct DnssrvQuery2 *r);
struct DnssrvComplexOperation2;
WERROR _DnssrvComplexOperation2(struct pipes_struct *p, struct DnssrvComplexOperation2 *r);
struct DnssrvEnumRecords2;
WERROR _DnssrvEnumRecords2(struct pipes_struct *p, struct DnssrvEnumRecords2 *r);
struct DnssrvUpdateRecord2;
WERROR _DnssrvUpdateRecord2(struct pipes_struct *p, struct DnssrvUpdateRecord2 *r);
NTSTATUS dnsserver__op_dispatch(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS dnsserver__op_reply(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS dnsserver__op_ndr_push(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_push *push, const void *r);
NTSTATUS dnsserver__op_local(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
#endif /* __NDR_DNSSERVER_SCOMPAT_H__ */
