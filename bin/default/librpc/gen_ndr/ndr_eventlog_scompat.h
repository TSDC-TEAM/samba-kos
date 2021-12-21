#ifndef __NDR_EVENTLOG_SCOMPAT_H__
#define __NDR_EVENTLOG_SCOMPAT_H__

struct pipes_struct;
struct dcesrv_endpoint_server;
struct dcesrv_call_state;

const struct dcesrv_endpoint_server *eventlog_get_ep_server(void);

NTSTATUS eventlog__op_ndr_pull(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_pull *pull, void **r);
struct eventlog_ClearEventLogW;
NTSTATUS _eventlog_ClearEventLogW(struct pipes_struct *p, struct eventlog_ClearEventLogW *r);
struct eventlog_BackupEventLogW;
NTSTATUS _eventlog_BackupEventLogW(struct pipes_struct *p, struct eventlog_BackupEventLogW *r);
struct eventlog_CloseEventLog;
NTSTATUS _eventlog_CloseEventLog(struct pipes_struct *p, struct eventlog_CloseEventLog *r);
struct eventlog_DeregisterEventSource;
NTSTATUS _eventlog_DeregisterEventSource(struct pipes_struct *p, struct eventlog_DeregisterEventSource *r);
struct eventlog_GetNumRecords;
NTSTATUS _eventlog_GetNumRecords(struct pipes_struct *p, struct eventlog_GetNumRecords *r);
struct eventlog_GetOldestRecord;
NTSTATUS _eventlog_GetOldestRecord(struct pipes_struct *p, struct eventlog_GetOldestRecord *r);
struct eventlog_ChangeNotify;
NTSTATUS _eventlog_ChangeNotify(struct pipes_struct *p, struct eventlog_ChangeNotify *r);
struct eventlog_OpenEventLogW;
NTSTATUS _eventlog_OpenEventLogW(struct pipes_struct *p, struct eventlog_OpenEventLogW *r);
struct eventlog_RegisterEventSourceW;
NTSTATUS _eventlog_RegisterEventSourceW(struct pipes_struct *p, struct eventlog_RegisterEventSourceW *r);
struct eventlog_OpenBackupEventLogW;
NTSTATUS _eventlog_OpenBackupEventLogW(struct pipes_struct *p, struct eventlog_OpenBackupEventLogW *r);
struct eventlog_ReadEventLogW;
NTSTATUS _eventlog_ReadEventLogW(struct pipes_struct *p, struct eventlog_ReadEventLogW *r);
struct eventlog_ReportEventW;
NTSTATUS _eventlog_ReportEventW(struct pipes_struct *p, struct eventlog_ReportEventW *r);
struct eventlog_ClearEventLogA;
NTSTATUS _eventlog_ClearEventLogA(struct pipes_struct *p, struct eventlog_ClearEventLogA *r);
struct eventlog_BackupEventLogA;
NTSTATUS _eventlog_BackupEventLogA(struct pipes_struct *p, struct eventlog_BackupEventLogA *r);
struct eventlog_OpenEventLogA;
NTSTATUS _eventlog_OpenEventLogA(struct pipes_struct *p, struct eventlog_OpenEventLogA *r);
struct eventlog_RegisterEventSourceA;
NTSTATUS _eventlog_RegisterEventSourceA(struct pipes_struct *p, struct eventlog_RegisterEventSourceA *r);
struct eventlog_OpenBackupEventLogA;
NTSTATUS _eventlog_OpenBackupEventLogA(struct pipes_struct *p, struct eventlog_OpenBackupEventLogA *r);
struct eventlog_ReadEventLogA;
NTSTATUS _eventlog_ReadEventLogA(struct pipes_struct *p, struct eventlog_ReadEventLogA *r);
struct eventlog_ReportEventA;
NTSTATUS _eventlog_ReportEventA(struct pipes_struct *p, struct eventlog_ReportEventA *r);
struct eventlog_RegisterClusterSvc;
NTSTATUS _eventlog_RegisterClusterSvc(struct pipes_struct *p, struct eventlog_RegisterClusterSvc *r);
struct eventlog_DeregisterClusterSvc;
NTSTATUS _eventlog_DeregisterClusterSvc(struct pipes_struct *p, struct eventlog_DeregisterClusterSvc *r);
struct eventlog_WriteClusterEvents;
NTSTATUS _eventlog_WriteClusterEvents(struct pipes_struct *p, struct eventlog_WriteClusterEvents *r);
struct eventlog_GetLogInformation;
NTSTATUS _eventlog_GetLogInformation(struct pipes_struct *p, struct eventlog_GetLogInformation *r);
struct eventlog_FlushEventLog;
NTSTATUS _eventlog_FlushEventLog(struct pipes_struct *p, struct eventlog_FlushEventLog *r);
struct eventlog_ReportEventAndSourceW;
NTSTATUS _eventlog_ReportEventAndSourceW(struct pipes_struct *p, struct eventlog_ReportEventAndSourceW *r);
NTSTATUS eventlog__op_dispatch(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS eventlog__op_reply(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
NTSTATUS eventlog__op_ndr_push(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, struct ndr_push *push, const void *r);
NTSTATUS eventlog__op_local(struct dcesrv_call_state *dce_call, TALLOC_CTX *mem_ctx, void *r);
#endif /* __NDR_EVENTLOG_SCOMPAT_H__ */
