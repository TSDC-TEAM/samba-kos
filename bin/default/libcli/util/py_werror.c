/*
 * Errors generated from
 * [MS-ERREF] https://msdn.microsoft.com/en-us/library/cc231199.aspx
 */
#include <Python.h>
#include "python/py3compat.h"
#include "includes.h"

static struct PyModuleDef moduledef = {
	PyModuleDef_HEAD_INIT,
	.m_name = "werror",
	.m_doc = "WERROR defines",
	.m_size = -1,
};

MODULE_INIT_FUNC(werror)
{
	PyObject *m;

	m = PyModule_Create(&moduledef);
	if (m == NULL)
		return NULL;

	PyModule_AddObject(m, "WERR_SUCCESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SUCCESS)));
	PyModule_AddObject(m, "WERR_NERR_SUCCESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_SUCCESS)));
	PyModule_AddObject(m, "WERR_INVALID_FUNCTION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_FUNCTION)));
	PyModule_AddObject(m, "WERR_FILE_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FILE_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_PATH_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PATH_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_TOO_MANY_OPEN_FILES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TOO_MANY_OPEN_FILES)));
	PyModule_AddObject(m, "WERR_ACCESS_DENIED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ACCESS_DENIED)));
	PyModule_AddObject(m, "WERR_INVALID_HANDLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_HANDLE)));
	PyModule_AddObject(m, "WERR_ARENA_TRASHED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ARENA_TRASHED)));
	PyModule_AddObject(m, "WERR_NOT_ENOUGH_MEMORY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_ENOUGH_MEMORY)));
	PyModule_AddObject(m, "WERR_INVALID_BLOCK",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_BLOCK)));
	PyModule_AddObject(m, "WERR_BAD_ENVIRONMENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_ENVIRONMENT)));
	PyModule_AddObject(m, "WERR_BAD_FORMAT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_FORMAT)));
	PyModule_AddObject(m, "WERR_INVALID_ACCESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_ACCESS)));
	PyModule_AddObject(m, "WERR_INVALID_DATA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_DATA)));
	PyModule_AddObject(m, "WERR_OUTOFMEMORY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_OUTOFMEMORY)));
	PyModule_AddObject(m, "WERR_INVALID_DRIVE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_DRIVE)));
	PyModule_AddObject(m, "WERR_CURRENT_DIRECTORY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CURRENT_DIRECTORY)));
	PyModule_AddObject(m, "WERR_NOT_SAME_DEVICE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_SAME_DEVICE)));
	PyModule_AddObject(m, "WERR_NO_MORE_FILES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_MORE_FILES)));
	PyModule_AddObject(m, "WERR_WRITE_PROTECT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WRITE_PROTECT)));
	PyModule_AddObject(m, "WERR_BAD_UNIT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_UNIT)));
	PyModule_AddObject(m, "WERR_NOT_READY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_READY)));
	PyModule_AddObject(m, "WERR_BAD_COMMAND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_COMMAND)));
	PyModule_AddObject(m, "WERR_CRC",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CRC)));
	PyModule_AddObject(m, "WERR_BAD_LENGTH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_LENGTH)));
	PyModule_AddObject(m, "WERR_SEEK",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SEEK)));
	PyModule_AddObject(m, "WERR_NOT_DOS_DISK",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_DOS_DISK)));
	PyModule_AddObject(m, "WERR_SECTOR_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SECTOR_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_OUT_OF_PAPER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_OUT_OF_PAPER)));
	PyModule_AddObject(m, "WERR_WRITE_FAULT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WRITE_FAULT)));
	PyModule_AddObject(m, "WERR_READ_FAULT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_READ_FAULT)));
	PyModule_AddObject(m, "WERR_GEN_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_GEN_FAILURE)));
	PyModule_AddObject(m, "WERR_SHARING_VIOLATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SHARING_VIOLATION)));
	PyModule_AddObject(m, "WERR_LOCK_VIOLATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOCK_VIOLATION)));
	PyModule_AddObject(m, "WERR_WRONG_DISK",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WRONG_DISK)));
	PyModule_AddObject(m, "WERR_SHARING_BUFFER_EXCEEDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SHARING_BUFFER_EXCEEDED)));
	PyModule_AddObject(m, "WERR_HANDLE_EOF",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_HANDLE_EOF)));
	PyModule_AddObject(m, "WERR_HANDLE_DISK_FULL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_HANDLE_DISK_FULL)));
	PyModule_AddObject(m, "WERR_NOT_SUPPORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_SUPPORTED)));
	PyModule_AddObject(m, "WERR_REM_NOT_LIST",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_REM_NOT_LIST)));
	PyModule_AddObject(m, "WERR_DUP_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DUP_NAME)));
	PyModule_AddObject(m, "WERR_BAD_NETPATH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_NETPATH)));
	PyModule_AddObject(m, "WERR_NETWORK_BUSY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NETWORK_BUSY)));
	PyModule_AddObject(m, "WERR_DEV_NOT_EXIST",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DEV_NOT_EXIST)));
	PyModule_AddObject(m, "WERR_TOO_MANY_CMDS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TOO_MANY_CMDS)));
	PyModule_AddObject(m, "WERR_ADAP_HDW_ERR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ADAP_HDW_ERR)));
	PyModule_AddObject(m, "WERR_BAD_NET_RESP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_NET_RESP)));
	PyModule_AddObject(m, "WERR_UNEXP_NET_ERR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNEXP_NET_ERR)));
	PyModule_AddObject(m, "WERR_BAD_REM_ADAP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_REM_ADAP)));
	PyModule_AddObject(m, "WERR_PRINTQ_FULL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PRINTQ_FULL)));
	PyModule_AddObject(m, "WERR_NO_SPOOL_SPACE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_SPOOL_SPACE)));
	PyModule_AddObject(m, "WERR_PRINT_CANCELLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PRINT_CANCELLED)));
	PyModule_AddObject(m, "WERR_NETNAME_DELETED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NETNAME_DELETED)));
	PyModule_AddObject(m, "WERR_NETWORK_ACCESS_DENIED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NETWORK_ACCESS_DENIED)));
	PyModule_AddObject(m, "WERR_BAD_DEV_TYPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_DEV_TYPE)));
	PyModule_AddObject(m, "WERR_BAD_NET_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_NET_NAME)));
	PyModule_AddObject(m, "WERR_TOO_MANY_NAMES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TOO_MANY_NAMES)));
	PyModule_AddObject(m, "WERR_TOO_MANY_SESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TOO_MANY_SESS)));
	PyModule_AddObject(m, "WERR_SHARING_PAUSED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SHARING_PAUSED)));
	PyModule_AddObject(m, "WERR_REQ_NOT_ACCEP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_REQ_NOT_ACCEP)));
	PyModule_AddObject(m, "WERR_REDIR_PAUSED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_REDIR_PAUSED)));
	PyModule_AddObject(m, "WERR_FILE_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FILE_EXISTS)));
	PyModule_AddObject(m, "WERR_CANNOT_MAKE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANNOT_MAKE)));
	PyModule_AddObject(m, "WERR_FAIL_I24",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FAIL_I24)));
	PyModule_AddObject(m, "WERR_OUT_OF_STRUCTURES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_OUT_OF_STRUCTURES)));
	PyModule_AddObject(m, "WERR_ALREADY_ASSIGNED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ALREADY_ASSIGNED)));
	PyModule_AddObject(m, "WERR_INVALID_PASSWORD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_PASSWORD)));
	PyModule_AddObject(m, "WERR_INVALID_PARAMETER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_PARAMETER)));
	PyModule_AddObject(m, "WERR_NET_WRITE_FAULT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NET_WRITE_FAULT)));
	PyModule_AddObject(m, "WERR_NO_PROC_SLOTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_PROC_SLOTS)));
	PyModule_AddObject(m, "WERR_TOO_MANY_SEMAPHORES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TOO_MANY_SEMAPHORES)));
	PyModule_AddObject(m, "WERR_EXCL_SEM_ALREADY_OWNED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EXCL_SEM_ALREADY_OWNED)));
	PyModule_AddObject(m, "WERR_SEM_IS_SET",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SEM_IS_SET)));
	PyModule_AddObject(m, "WERR_TOO_MANY_SEM_REQUESTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TOO_MANY_SEM_REQUESTS)));
	PyModule_AddObject(m, "WERR_INVALID_AT_INTERRUPT_TIME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_AT_INTERRUPT_TIME)));
	PyModule_AddObject(m, "WERR_SEM_OWNER_DIED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SEM_OWNER_DIED)));
	PyModule_AddObject(m, "WERR_SEM_USER_LIMIT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SEM_USER_LIMIT)));
	PyModule_AddObject(m, "WERR_DISK_CHANGE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DISK_CHANGE)));
	PyModule_AddObject(m, "WERR_DRIVE_LOCKED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DRIVE_LOCKED)));
	PyModule_AddObject(m, "WERR_BROKEN_PIPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BROKEN_PIPE)));
	PyModule_AddObject(m, "WERR_OPEN_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_OPEN_FAILED)));
	PyModule_AddObject(m, "WERR_BUFFER_OVERFLOW",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BUFFER_OVERFLOW)));
	PyModule_AddObject(m, "WERR_DISK_FULL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DISK_FULL)));
	PyModule_AddObject(m, "WERR_NO_MORE_SEARCH_HANDLES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_MORE_SEARCH_HANDLES)));
	PyModule_AddObject(m, "WERR_INVALID_TARGET_HANDLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_TARGET_HANDLE)));
	PyModule_AddObject(m, "WERR_INVALID_CATEGORY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_CATEGORY)));
	PyModule_AddObject(m, "WERR_INVALID_VERIFY_SWITCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_VERIFY_SWITCH)));
	PyModule_AddObject(m, "WERR_BAD_DRIVER_LEVEL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_DRIVER_LEVEL)));
	PyModule_AddObject(m, "WERR_CALL_NOT_IMPLEMENTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CALL_NOT_IMPLEMENTED)));
	PyModule_AddObject(m, "WERR_SEM_TIMEOUT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SEM_TIMEOUT)));
	PyModule_AddObject(m, "WERR_INSUFFICIENT_BUFFER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INSUFFICIENT_BUFFER)));
	PyModule_AddObject(m, "WERR_INVALID_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_NAME)));
	PyModule_AddObject(m, "WERR_INVALID_LEVEL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_LEVEL)));
	PyModule_AddObject(m, "WERR_NO_VOLUME_LABEL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_VOLUME_LABEL)));
	PyModule_AddObject(m, "WERR_MOD_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MOD_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_PROC_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PROC_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_WAIT_NO_CHILDREN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WAIT_NO_CHILDREN)));
	PyModule_AddObject(m, "WERR_CHILD_NOT_COMPLETE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CHILD_NOT_COMPLETE)));
	PyModule_AddObject(m, "WERR_DIRECT_ACCESS_HANDLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DIRECT_ACCESS_HANDLE)));
	PyModule_AddObject(m, "WERR_NEGATIVE_SEEK",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NEGATIVE_SEEK)));
	PyModule_AddObject(m, "WERR_SEEK_ON_DEVICE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SEEK_ON_DEVICE)));
	PyModule_AddObject(m, "WERR_IS_JOIN_TARGET",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IS_JOIN_TARGET)));
	PyModule_AddObject(m, "WERR_IS_JOINED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IS_JOINED)));
	PyModule_AddObject(m, "WERR_IS_SUBSTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IS_SUBSTED)));
	PyModule_AddObject(m, "WERR_NOT_JOINED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_JOINED)));
	PyModule_AddObject(m, "WERR_NOT_SUBSTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_SUBSTED)));
	PyModule_AddObject(m, "WERR_JOIN_TO_JOIN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_JOIN_TO_JOIN)));
	PyModule_AddObject(m, "WERR_SUBST_TO_SUBST",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SUBST_TO_SUBST)));
	PyModule_AddObject(m, "WERR_JOIN_TO_SUBST",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_JOIN_TO_SUBST)));
	PyModule_AddObject(m, "WERR_SUBST_TO_JOIN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SUBST_TO_JOIN)));
	PyModule_AddObject(m, "WERR_BUSY_DRIVE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BUSY_DRIVE)));
	PyModule_AddObject(m, "WERR_SAME_DRIVE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SAME_DRIVE)));
	PyModule_AddObject(m, "WERR_DIR_NOT_ROOT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DIR_NOT_ROOT)));
	PyModule_AddObject(m, "WERR_DIR_NOT_EMPTY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DIR_NOT_EMPTY)));
	PyModule_AddObject(m, "WERR_IS_SUBST_PATH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IS_SUBST_PATH)));
	PyModule_AddObject(m, "WERR_IS_JOIN_PATH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IS_JOIN_PATH)));
	PyModule_AddObject(m, "WERR_PATH_BUSY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PATH_BUSY)));
	PyModule_AddObject(m, "WERR_IS_SUBST_TARGET",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IS_SUBST_TARGET)));
	PyModule_AddObject(m, "WERR_SYSTEM_TRACE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SYSTEM_TRACE)));
	PyModule_AddObject(m, "WERR_INVALID_EVENT_COUNT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_EVENT_COUNT)));
	PyModule_AddObject(m, "WERR_TOO_MANY_MUXWAITERS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TOO_MANY_MUXWAITERS)));
	PyModule_AddObject(m, "WERR_INVALID_LIST_FORMAT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_LIST_FORMAT)));
	PyModule_AddObject(m, "WERR_LABEL_TOO_LONG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LABEL_TOO_LONG)));
	PyModule_AddObject(m, "WERR_TOO_MANY_TCBS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TOO_MANY_TCBS)));
	PyModule_AddObject(m, "WERR_SIGNAL_REFUSED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SIGNAL_REFUSED)));
	PyModule_AddObject(m, "WERR_DISCARDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DISCARDED)));
	PyModule_AddObject(m, "WERR_NOT_LOCKED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_LOCKED)));
	PyModule_AddObject(m, "WERR_BAD_THREADID_ADDR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_THREADID_ADDR)));
	PyModule_AddObject(m, "WERR_BAD_ARGUMENTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_ARGUMENTS)));
	PyModule_AddObject(m, "WERR_BAD_PATHNAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_PATHNAME)));
	PyModule_AddObject(m, "WERR_SIGNAL_PENDING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SIGNAL_PENDING)));
	PyModule_AddObject(m, "WERR_MAX_THRDS_REACHED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MAX_THRDS_REACHED)));
	PyModule_AddObject(m, "WERR_LOCK_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOCK_FAILED)));
	PyModule_AddObject(m, "WERR_BUSY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BUSY)));
	PyModule_AddObject(m, "WERR_CANCEL_VIOLATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANCEL_VIOLATION)));
	PyModule_AddObject(m, "WERR_ATOMIC_LOCKS_NOT_SUPPORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ATOMIC_LOCKS_NOT_SUPPORTED)));
	PyModule_AddObject(m, "WERR_INVALID_SEGMENT_NUMBER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_SEGMENT_NUMBER)));
	PyModule_AddObject(m, "WERR_INVALID_ORDINAL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_ORDINAL)));
	PyModule_AddObject(m, "WERR_ALREADY_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ALREADY_EXISTS)));
	PyModule_AddObject(m, "WERR_INVALID_FLAG_NUMBER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_FLAG_NUMBER)));
	PyModule_AddObject(m, "WERR_SEM_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SEM_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_INVALID_STARTING_CODESEG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_STARTING_CODESEG)));
	PyModule_AddObject(m, "WERR_INVALID_STACKSEG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_STACKSEG)));
	PyModule_AddObject(m, "WERR_INVALID_MODULETYPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_MODULETYPE)));
	PyModule_AddObject(m, "WERR_INVALID_EXE_SIGNATURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_EXE_SIGNATURE)));
	PyModule_AddObject(m, "WERR_EXE_MARKED_INVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EXE_MARKED_INVALID)));
	PyModule_AddObject(m, "WERR_BAD_EXE_FORMAT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_EXE_FORMAT)));
	PyModule_AddObject(m, "WERR_ITERATED_DATA_EXCEEDS_64K",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ITERATED_DATA_EXCEEDS_64K)));
	PyModule_AddObject(m, "WERR_INVALID_MINALLOCSIZE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_MINALLOCSIZE)));
	PyModule_AddObject(m, "WERR_DYNLINK_FROM_INVALID_RING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DYNLINK_FROM_INVALID_RING)));
	PyModule_AddObject(m, "WERR_IOPL_NOT_ENABLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IOPL_NOT_ENABLED)));
	PyModule_AddObject(m, "WERR_INVALID_SEGDPL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_SEGDPL)));
	PyModule_AddObject(m, "WERR_AUTODATASEG_EXCEEDS_64K",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_AUTODATASEG_EXCEEDS_64K)));
	PyModule_AddObject(m, "WERR_RING2SEG_MUST_BE_MOVABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RING2SEG_MUST_BE_MOVABLE)));
	PyModule_AddObject(m, "WERR_RELOC_CHAIN_XEEDS_SEGLIM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RELOC_CHAIN_XEEDS_SEGLIM)));
	PyModule_AddObject(m, "WERR_INFLOOP_IN_RELOC_CHAIN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INFLOOP_IN_RELOC_CHAIN)));
	PyModule_AddObject(m, "WERR_ENVVAR_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ENVVAR_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_NO_SIGNAL_SENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_SIGNAL_SENT)));
	PyModule_AddObject(m, "WERR_FILENAME_EXCED_RANGE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FILENAME_EXCED_RANGE)));
	PyModule_AddObject(m, "WERR_RING2_STACK_IN_USE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RING2_STACK_IN_USE)));
	PyModule_AddObject(m, "WERR_META_EXPANSION_TOO_LONG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_META_EXPANSION_TOO_LONG)));
	PyModule_AddObject(m, "WERR_INVALID_SIGNAL_NUMBER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_SIGNAL_NUMBER)));
	PyModule_AddObject(m, "WERR_THREAD_1_INACTIVE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_THREAD_1_INACTIVE)));
	PyModule_AddObject(m, "WERR_LOCKED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOCKED)));
	PyModule_AddObject(m, "WERR_TOO_MANY_MODULES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TOO_MANY_MODULES)));
	PyModule_AddObject(m, "WERR_NESTING_NOT_ALLOWED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NESTING_NOT_ALLOWED)));
	PyModule_AddObject(m, "WERR_EXE_MACHINE_TYPE_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EXE_MACHINE_TYPE_MISMATCH)));
	PyModule_AddObject(m, "WERR_EXE_CANNOT_MODIFY_SIGNED_BINARY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EXE_CANNOT_MODIFY_SIGNED_BINARY)));
	PyModule_AddObject(m, "WERR_EXE_CANNOT_MODIFY_STRONG_SIGNED_BINARY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EXE_CANNOT_MODIFY_STRONG_SIGNED_BINARY)));
	PyModule_AddObject(m, "WERR_FILE_CHECKED_OUT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FILE_CHECKED_OUT)));
	PyModule_AddObject(m, "WERR_CHECKOUT_REQUIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CHECKOUT_REQUIRED)));
	PyModule_AddObject(m, "WERR_BAD_FILE_TYPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_FILE_TYPE)));
	PyModule_AddObject(m, "WERR_FILE_TOO_LARGE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FILE_TOO_LARGE)));
	PyModule_AddObject(m, "WERR_FORMS_AUTH_REQUIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FORMS_AUTH_REQUIRED)));
	PyModule_AddObject(m, "WERR_VIRUS_INFECTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_VIRUS_INFECTED)));
	PyModule_AddObject(m, "WERR_VIRUS_DELETED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_VIRUS_DELETED)));
	PyModule_AddObject(m, "WERR_PIPE_LOCAL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PIPE_LOCAL)));
	PyModule_AddObject(m, "WERR_BAD_PIPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_PIPE)));
	PyModule_AddObject(m, "WERR_PIPE_BUSY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PIPE_BUSY)));
	PyModule_AddObject(m, "WERR_NO_DATA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_DATA)));
	PyModule_AddObject(m, "WERR_PIPE_NOT_CONNECTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PIPE_NOT_CONNECTED)));
	PyModule_AddObject(m, "WERR_MORE_DATA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MORE_DATA)));
	PyModule_AddObject(m, "WERR_VC_DISCONNECTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_VC_DISCONNECTED)));
	PyModule_AddObject(m, "WERR_INVALID_EA_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_EA_NAME)));
	PyModule_AddObject(m, "WERR_EA_LIST_INCONSISTENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EA_LIST_INCONSISTENT)));
	PyModule_AddObject(m, "WERR_WAIT_TIMEOUT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WAIT_TIMEOUT)));
	PyModule_AddObject(m, "WERR_NO_MORE_ITEMS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_MORE_ITEMS)));
	PyModule_AddObject(m, "WERR_CANNOT_COPY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANNOT_COPY)));
	PyModule_AddObject(m, "WERR_DIRECTORY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DIRECTORY)));
	PyModule_AddObject(m, "WERR_EAS_DIDNT_FIT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EAS_DIDNT_FIT)));
	PyModule_AddObject(m, "WERR_EA_FILE_CORRUPT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EA_FILE_CORRUPT)));
	PyModule_AddObject(m, "WERR_EA_TABLE_FULL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EA_TABLE_FULL)));
	PyModule_AddObject(m, "WERR_INVALID_EA_HANDLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_EA_HANDLE)));
	PyModule_AddObject(m, "WERR_EAS_NOT_SUPPORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EAS_NOT_SUPPORTED)));
	PyModule_AddObject(m, "WERR_NOT_OWNER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_OWNER)));
	PyModule_AddObject(m, "WERR_TOO_MANY_POSTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TOO_MANY_POSTS)));
	PyModule_AddObject(m, "WERR_PARTIAL_COPY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PARTIAL_COPY)));
	PyModule_AddObject(m, "WERR_OPLOCK_NOT_GRANTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_OPLOCK_NOT_GRANTED)));
	PyModule_AddObject(m, "WERR_INVALID_OPLOCK_PROTOCOL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_OPLOCK_PROTOCOL)));
	PyModule_AddObject(m, "WERR_DISK_TOO_FRAGMENTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DISK_TOO_FRAGMENTED)));
	PyModule_AddObject(m, "WERR_DELETE_PENDING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DELETE_PENDING)));
	PyModule_AddObject(m, "WERR_MR_MID_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MR_MID_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_SCOPE_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SCOPE_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_FAIL_NOACTION_REBOOT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FAIL_NOACTION_REBOOT)));
	PyModule_AddObject(m, "WERR_FAIL_SHUTDOWN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FAIL_SHUTDOWN)));
	PyModule_AddObject(m, "WERR_FAIL_RESTART",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FAIL_RESTART)));
	PyModule_AddObject(m, "WERR_MAX_SESSIONS_REACHED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MAX_SESSIONS_REACHED)));
	PyModule_AddObject(m, "WERR_THREAD_MODE_ALREADY_BACKGROUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_THREAD_MODE_ALREADY_BACKGROUND)));
	PyModule_AddObject(m, "WERR_THREAD_MODE_NOT_BACKGROUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_THREAD_MODE_NOT_BACKGROUND)));
	PyModule_AddObject(m, "WERR_PROCESS_MODE_ALREADY_BACKGROUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PROCESS_MODE_ALREADY_BACKGROUND)));
	PyModule_AddObject(m, "WERR_PROCESS_MODE_NOT_BACKGROUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PROCESS_MODE_NOT_BACKGROUND)));
	PyModule_AddObject(m, "WERR_INVALID_ADDRESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_ADDRESS)));
	PyModule_AddObject(m, "WERR_USER_PROFILE_LOAD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_USER_PROFILE_LOAD)));
	PyModule_AddObject(m, "WERR_ARITHMETIC_OVERFLOW",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ARITHMETIC_OVERFLOW)));
	PyModule_AddObject(m, "WERR_PIPE_CONNECTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PIPE_CONNECTED)));
	PyModule_AddObject(m, "WERR_PIPE_LISTENING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PIPE_LISTENING)));
	PyModule_AddObject(m, "WERR_VERIFIER_STOP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_VERIFIER_STOP)));
	PyModule_AddObject(m, "WERR_ABIOS_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ABIOS_ERROR)));
	PyModule_AddObject(m, "WERR_WX86_WARNING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WX86_WARNING)));
	PyModule_AddObject(m, "WERR_WX86_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WX86_ERROR)));
	PyModule_AddObject(m, "WERR_TIMER_NOT_CANCELED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TIMER_NOT_CANCELED)));
	PyModule_AddObject(m, "WERR_UNWIND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNWIND)));
	PyModule_AddObject(m, "WERR_BAD_STACK",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_STACK)));
	PyModule_AddObject(m, "WERR_INVALID_UNWIND_TARGET",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_UNWIND_TARGET)));
	PyModule_AddObject(m, "WERR_INVALID_PORT_ATTRIBUTES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_PORT_ATTRIBUTES)));
	PyModule_AddObject(m, "WERR_PORT_MESSAGE_TOO_LONG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PORT_MESSAGE_TOO_LONG)));
	PyModule_AddObject(m, "WERR_INVALID_QUOTA_LOWER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_QUOTA_LOWER)));
	PyModule_AddObject(m, "WERR_DEVICE_ALREADY_ATTACHED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DEVICE_ALREADY_ATTACHED)));
	PyModule_AddObject(m, "WERR_INSTRUCTION_MISALIGNMENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INSTRUCTION_MISALIGNMENT)));
	PyModule_AddObject(m, "WERR_PROFILING_NOT_STARTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PROFILING_NOT_STARTED)));
	PyModule_AddObject(m, "WERR_PROFILING_NOT_STOPPED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PROFILING_NOT_STOPPED)));
	PyModule_AddObject(m, "WERR_COULD_NOT_INTERPRET",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_COULD_NOT_INTERPRET)));
	PyModule_AddObject(m, "WERR_PROFILING_AT_LIMIT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PROFILING_AT_LIMIT)));
	PyModule_AddObject(m, "WERR_CANT_WAIT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANT_WAIT)));
	PyModule_AddObject(m, "WERR_CANT_TERMINATE_SELF",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANT_TERMINATE_SELF)));
	PyModule_AddObject(m, "WERR_UNEXPECTED_MM_CREATE_ERR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNEXPECTED_MM_CREATE_ERR)));
	PyModule_AddObject(m, "WERR_UNEXPECTED_MM_MAP_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNEXPECTED_MM_MAP_ERROR)));
	PyModule_AddObject(m, "WERR_UNEXPECTED_MM_EXTEND_ERR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNEXPECTED_MM_EXTEND_ERR)));
	PyModule_AddObject(m, "WERR_BAD_FUNCTION_TABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_FUNCTION_TABLE)));
	PyModule_AddObject(m, "WERR_NO_GUID_TRANSLATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_GUID_TRANSLATION)));
	PyModule_AddObject(m, "WERR_INVALID_LDT_SIZE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_LDT_SIZE)));
	PyModule_AddObject(m, "WERR_INVALID_LDT_OFFSET",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_LDT_OFFSET)));
	PyModule_AddObject(m, "WERR_INVALID_LDT_DESCRIPTOR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_LDT_DESCRIPTOR)));
	PyModule_AddObject(m, "WERR_TOO_MANY_THREADS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TOO_MANY_THREADS)));
	PyModule_AddObject(m, "WERR_THREAD_NOT_IN_PROCESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_THREAD_NOT_IN_PROCESS)));
	PyModule_AddObject(m, "WERR_PAGEFILE_QUOTA_EXCEEDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PAGEFILE_QUOTA_EXCEEDED)));
	PyModule_AddObject(m, "WERR_LOGON_SERVER_CONFLICT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOGON_SERVER_CONFLICT)));
	PyModule_AddObject(m, "WERR_SYNCHRONIZATION_REQUIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SYNCHRONIZATION_REQUIRED)));
	PyModule_AddObject(m, "WERR_NET_OPEN_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NET_OPEN_FAILED)));
	PyModule_AddObject(m, "WERR_IO_PRIVILEGE_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IO_PRIVILEGE_FAILED)));
	PyModule_AddObject(m, "WERR_CONTROL_C_EXIT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CONTROL_C_EXIT)));
	PyModule_AddObject(m, "WERR_MISSING_SYSTEMFILE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MISSING_SYSTEMFILE)));
	PyModule_AddObject(m, "WERR_UNHANDLED_EXCEPTION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNHANDLED_EXCEPTION)));
	PyModule_AddObject(m, "WERR_APP_INIT_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_APP_INIT_FAILURE)));
	PyModule_AddObject(m, "WERR_PAGEFILE_CREATE_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PAGEFILE_CREATE_FAILED)));
	PyModule_AddObject(m, "WERR_INVALID_IMAGE_HASH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_IMAGE_HASH)));
	PyModule_AddObject(m, "WERR_NO_PAGEFILE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_PAGEFILE)));
	PyModule_AddObject(m, "WERR_ILLEGAL_FLOAT_CONTEXT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ILLEGAL_FLOAT_CONTEXT)));
	PyModule_AddObject(m, "WERR_NO_EVENT_PAIR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_EVENT_PAIR)));
	PyModule_AddObject(m, "WERR_DOMAIN_CTRLR_CONFIG_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DOMAIN_CTRLR_CONFIG_ERROR)));
	PyModule_AddObject(m, "WERR_ILLEGAL_CHARACTER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ILLEGAL_CHARACTER)));
	PyModule_AddObject(m, "WERR_UNDEFINED_CHARACTER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNDEFINED_CHARACTER)));
	PyModule_AddObject(m, "WERR_FLOPPY_VOLUME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FLOPPY_VOLUME)));
	PyModule_AddObject(m, "WERR_BIOS_FAILED_TO_CONNECT_INTERRUPT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BIOS_FAILED_TO_CONNECT_INTERRUPT)));
	PyModule_AddObject(m, "WERR_BACKUP_CONTROLLER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BACKUP_CONTROLLER)));
	PyModule_AddObject(m, "WERR_MUTANT_LIMIT_EXCEEDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MUTANT_LIMIT_EXCEEDED)));
	PyModule_AddObject(m, "WERR_FS_DRIVER_REQUIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FS_DRIVER_REQUIRED)));
	PyModule_AddObject(m, "WERR_CANNOT_LOAD_REGISTRY_FILE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANNOT_LOAD_REGISTRY_FILE)));
	PyModule_AddObject(m, "WERR_DEBUG_ATTACH_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DEBUG_ATTACH_FAILED)));
	PyModule_AddObject(m, "WERR_SYSTEM_PROCESS_TERMINATED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SYSTEM_PROCESS_TERMINATED)));
	PyModule_AddObject(m, "WERR_DATA_NOT_ACCEPTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DATA_NOT_ACCEPTED)));
	PyModule_AddObject(m, "WERR_VDM_HARD_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_VDM_HARD_ERROR)));
	PyModule_AddObject(m, "WERR_DRIVER_CANCEL_TIMEOUT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DRIVER_CANCEL_TIMEOUT)));
	PyModule_AddObject(m, "WERR_REPLY_MESSAGE_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_REPLY_MESSAGE_MISMATCH)));
	PyModule_AddObject(m, "WERR_LOST_WRITEBEHIND_DATA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOST_WRITEBEHIND_DATA)));
	PyModule_AddObject(m, "WERR_CLIENT_SERVER_PARAMETERS_INVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLIENT_SERVER_PARAMETERS_INVALID)));
	PyModule_AddObject(m, "WERR_NOT_TINY_STREAM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_TINY_STREAM)));
	PyModule_AddObject(m, "WERR_STACK_OVERFLOW_READ",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_STACK_OVERFLOW_READ)));
	PyModule_AddObject(m, "WERR_CONVERT_TO_LARGE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CONVERT_TO_LARGE)));
	PyModule_AddObject(m, "WERR_FOUND_OUT_OF_SCOPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FOUND_OUT_OF_SCOPE)));
	PyModule_AddObject(m, "WERR_ALLOCATE_BUCKET",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ALLOCATE_BUCKET)));
	PyModule_AddObject(m, "WERR_MARSHALL_OVERFLOW",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MARSHALL_OVERFLOW)));
	PyModule_AddObject(m, "WERR_INVALID_VARIANT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_VARIANT)));
	PyModule_AddObject(m, "WERR_BAD_COMPRESSION_BUFFER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_COMPRESSION_BUFFER)));
	PyModule_AddObject(m, "WERR_AUDIT_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_AUDIT_FAILED)));
	PyModule_AddObject(m, "WERR_TIMER_RESOLUTION_NOT_SET",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TIMER_RESOLUTION_NOT_SET)));
	PyModule_AddObject(m, "WERR_INSUFFICIENT_LOGON_INFO",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INSUFFICIENT_LOGON_INFO)));
	PyModule_AddObject(m, "WERR_BAD_DLL_ENTRYPOINT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_DLL_ENTRYPOINT)));
	PyModule_AddObject(m, "WERR_BAD_SERVICE_ENTRYPOINT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_SERVICE_ENTRYPOINT)));
	PyModule_AddObject(m, "WERR_IP_ADDRESS_CONFLICT1",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IP_ADDRESS_CONFLICT1)));
	PyModule_AddObject(m, "WERR_IP_ADDRESS_CONFLICT2",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IP_ADDRESS_CONFLICT2)));
	PyModule_AddObject(m, "WERR_REGISTRY_QUOTA_LIMIT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_REGISTRY_QUOTA_LIMIT)));
	PyModule_AddObject(m, "WERR_NO_CALLBACK_ACTIVE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_CALLBACK_ACTIVE)));
	PyModule_AddObject(m, "WERR_PWD_TOO_SHORT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PWD_TOO_SHORT)));
	PyModule_AddObject(m, "WERR_PWD_TOO_RECENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PWD_TOO_RECENT)));
	PyModule_AddObject(m, "WERR_PWD_HISTORY_CONFLICT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PWD_HISTORY_CONFLICT)));
	PyModule_AddObject(m, "WERR_UNSUPPORTED_COMPRESSION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNSUPPORTED_COMPRESSION)));
	PyModule_AddObject(m, "WERR_INVALID_HW_PROFILE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_HW_PROFILE)));
	PyModule_AddObject(m, "WERR_INVALID_PLUGPLAY_DEVICE_PATH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_PLUGPLAY_DEVICE_PATH)));
	PyModule_AddObject(m, "WERR_QUOTA_LIST_INCONSISTENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_QUOTA_LIST_INCONSISTENT)));
	PyModule_AddObject(m, "WERR_EVALUATION_EXPIRATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVALUATION_EXPIRATION)));
	PyModule_AddObject(m, "WERR_ILLEGAL_DLL_RELOCATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ILLEGAL_DLL_RELOCATION)));
	PyModule_AddObject(m, "WERR_DLL_INIT_FAILED_LOGOFF",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DLL_INIT_FAILED_LOGOFF)));
	PyModule_AddObject(m, "WERR_VALIDATE_CONTINUE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_VALIDATE_CONTINUE)));
	PyModule_AddObject(m, "WERR_NO_MORE_MATCHES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_MORE_MATCHES)));
	PyModule_AddObject(m, "WERR_RANGE_LIST_CONFLICT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RANGE_LIST_CONFLICT)));
	PyModule_AddObject(m, "WERR_SERVER_SID_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SERVER_SID_MISMATCH)));
	PyModule_AddObject(m, "WERR_CANT_ENABLE_DENY_ONLY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANT_ENABLE_DENY_ONLY)));
	PyModule_AddObject(m, "WERR_FLOAT_MULTIPLE_FAULTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FLOAT_MULTIPLE_FAULTS)));
	PyModule_AddObject(m, "WERR_FLOAT_MULTIPLE_TRAPS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FLOAT_MULTIPLE_TRAPS)));
	PyModule_AddObject(m, "WERR_NOINTERFACE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOINTERFACE)));
	PyModule_AddObject(m, "WERR_DRIVER_FAILED_SLEEP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DRIVER_FAILED_SLEEP)));
	PyModule_AddObject(m, "WERR_CORRUPT_SYSTEM_FILE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CORRUPT_SYSTEM_FILE)));
	PyModule_AddObject(m, "WERR_COMMITMENT_MINIMUM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_COMMITMENT_MINIMUM)));
	PyModule_AddObject(m, "WERR_PNP_RESTART_ENUMERATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PNP_RESTART_ENUMERATION)));
	PyModule_AddObject(m, "WERR_SYSTEM_IMAGE_BAD_SIGNATURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SYSTEM_IMAGE_BAD_SIGNATURE)));
	PyModule_AddObject(m, "WERR_PNP_REBOOT_REQUIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PNP_REBOOT_REQUIRED)));
	PyModule_AddObject(m, "WERR_INSUFFICIENT_POWER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INSUFFICIENT_POWER)));
	PyModule_AddObject(m, "WERR_SYSTEM_SHUTDOWN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SYSTEM_SHUTDOWN)));
	PyModule_AddObject(m, "WERR_PORT_NOT_SET",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PORT_NOT_SET)));
	PyModule_AddObject(m, "WERR_DS_VERSION_CHECK_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_VERSION_CHECK_FAILURE)));
	PyModule_AddObject(m, "WERR_RANGE_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RANGE_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_NOT_SAFE_MODE_DRIVER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_SAFE_MODE_DRIVER)));
	PyModule_AddObject(m, "WERR_FAILED_DRIVER_ENTRY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FAILED_DRIVER_ENTRY)));
	PyModule_AddObject(m, "WERR_DEVICE_ENUMERATION_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DEVICE_ENUMERATION_ERROR)));
	PyModule_AddObject(m, "WERR_MOUNT_POINT_NOT_RESOLVED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MOUNT_POINT_NOT_RESOLVED)));
	PyModule_AddObject(m, "WERR_INVALID_DEVICE_OBJECT_PARAMETER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_DEVICE_OBJECT_PARAMETER)));
	PyModule_AddObject(m, "WERR_MCA_OCCURED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MCA_OCCURED)));
	PyModule_AddObject(m, "WERR_DRIVER_DATABASE_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DRIVER_DATABASE_ERROR)));
	PyModule_AddObject(m, "WERR_SYSTEM_HIVE_TOO_LARGE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SYSTEM_HIVE_TOO_LARGE)));
	PyModule_AddObject(m, "WERR_DRIVER_FAILED_PRIOR_UNLOAD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DRIVER_FAILED_PRIOR_UNLOAD)));
	PyModule_AddObject(m, "WERR_VOLSNAP_PREPARE_HIBERNATE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_VOLSNAP_PREPARE_HIBERNATE)));
	PyModule_AddObject(m, "WERR_HIBERNATION_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_HIBERNATION_FAILURE)));
	PyModule_AddObject(m, "WERR_FILE_SYSTEM_LIMITATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FILE_SYSTEM_LIMITATION)));
	PyModule_AddObject(m, "WERR_ASSERTION_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ASSERTION_FAILURE)));
	PyModule_AddObject(m, "WERR_ACPI_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ACPI_ERROR)));
	PyModule_AddObject(m, "WERR_WOW_ASSERTION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WOW_ASSERTION)));
	PyModule_AddObject(m, "WERR_PNP_BAD_MPS_TABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PNP_BAD_MPS_TABLE)));
	PyModule_AddObject(m, "WERR_PNP_TRANSLATION_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PNP_TRANSLATION_FAILED)));
	PyModule_AddObject(m, "WERR_PNP_IRQ_TRANSLATION_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PNP_IRQ_TRANSLATION_FAILED)));
	PyModule_AddObject(m, "WERR_PNP_INVALID_ID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PNP_INVALID_ID)));
	PyModule_AddObject(m, "WERR_WAKE_SYSTEM_DEBUGGER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WAKE_SYSTEM_DEBUGGER)));
	PyModule_AddObject(m, "WERR_HANDLES_CLOSED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_HANDLES_CLOSED)));
	PyModule_AddObject(m, "WERR_EXTRANEOUS_INFORMATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EXTRANEOUS_INFORMATION)));
	PyModule_AddObject(m, "WERR_RXACT_COMMIT_NECESSARY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RXACT_COMMIT_NECESSARY)));
	PyModule_AddObject(m, "WERR_MEDIA_CHECK",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MEDIA_CHECK)));
	PyModule_AddObject(m, "WERR_GUID_SUBSTITUTION_MADE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_GUID_SUBSTITUTION_MADE)));
	PyModule_AddObject(m, "WERR_STOPPED_ON_SYMLINK",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_STOPPED_ON_SYMLINK)));
	PyModule_AddObject(m, "WERR_LONGJUMP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LONGJUMP)));
	PyModule_AddObject(m, "WERR_PLUGPLAY_QUERY_VETOED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PLUGPLAY_QUERY_VETOED)));
	PyModule_AddObject(m, "WERR_UNWIND_CONSOLIDATE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNWIND_CONSOLIDATE)));
	PyModule_AddObject(m, "WERR_REGISTRY_HIVE_RECOVERED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_REGISTRY_HIVE_RECOVERED)));
	PyModule_AddObject(m, "WERR_DLL_MIGHT_BE_INSECURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DLL_MIGHT_BE_INSECURE)));
	PyModule_AddObject(m, "WERR_DLL_MIGHT_BE_INCOMPATIBLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DLL_MIGHT_BE_INCOMPATIBLE)));
	PyModule_AddObject(m, "WERR_DBG_EXCEPTION_NOT_HANDLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DBG_EXCEPTION_NOT_HANDLED)));
	PyModule_AddObject(m, "WERR_DBG_REPLY_LATER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DBG_REPLY_LATER)));
	PyModule_AddObject(m, "WERR_DBG_UNABLE_TO_PROVIDE_HANDLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DBG_UNABLE_TO_PROVIDE_HANDLE)));
	PyModule_AddObject(m, "WERR_DBG_TERMINATE_THREAD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DBG_TERMINATE_THREAD)));
	PyModule_AddObject(m, "WERR_DBG_TERMINATE_PROCESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DBG_TERMINATE_PROCESS)));
	PyModule_AddObject(m, "WERR_DBG_CONTROL_C",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DBG_CONTROL_C)));
	PyModule_AddObject(m, "WERR_DBG_PRINTEXCEPTION_C",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DBG_PRINTEXCEPTION_C)));
	PyModule_AddObject(m, "WERR_DBG_RIPEXCEPTION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DBG_RIPEXCEPTION)));
	PyModule_AddObject(m, "WERR_DBG_CONTROL_BREAK",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DBG_CONTROL_BREAK)));
	PyModule_AddObject(m, "WERR_DBG_COMMAND_EXCEPTION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DBG_COMMAND_EXCEPTION)));
	PyModule_AddObject(m, "WERR_OBJECT_NAME_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_OBJECT_NAME_EXISTS)));
	PyModule_AddObject(m, "WERR_THREAD_WAS_SUSPENDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_THREAD_WAS_SUSPENDED)));
	PyModule_AddObject(m, "WERR_IMAGE_NOT_AT_BASE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IMAGE_NOT_AT_BASE)));
	PyModule_AddObject(m, "WERR_RXACT_STATE_CREATED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RXACT_STATE_CREATED)));
	PyModule_AddObject(m, "WERR_SEGMENT_NOTIFICATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SEGMENT_NOTIFICATION)));
	PyModule_AddObject(m, "WERR_BAD_CURRENT_DIRECTORY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_CURRENT_DIRECTORY)));
	PyModule_AddObject(m, "WERR_FT_READ_RECOVERY_FROM_BACKUP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FT_READ_RECOVERY_FROM_BACKUP)));
	PyModule_AddObject(m, "WERR_FT_WRITE_RECOVERY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FT_WRITE_RECOVERY)));
	PyModule_AddObject(m, "WERR_IMAGE_MACHINE_TYPE_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IMAGE_MACHINE_TYPE_MISMATCH)));
	PyModule_AddObject(m, "WERR_RECEIVE_PARTIAL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RECEIVE_PARTIAL)));
	PyModule_AddObject(m, "WERR_RECEIVE_EXPEDITED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RECEIVE_EXPEDITED)));
	PyModule_AddObject(m, "WERR_RECEIVE_PARTIAL_EXPEDITED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RECEIVE_PARTIAL_EXPEDITED)));
	PyModule_AddObject(m, "WERR_EVENT_DONE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVENT_DONE)));
	PyModule_AddObject(m, "WERR_EVENT_PENDING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVENT_PENDING)));
	PyModule_AddObject(m, "WERR_CHECKING_FILE_SYSTEM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CHECKING_FILE_SYSTEM)));
	PyModule_AddObject(m, "WERR_FATAL_APP_EXIT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FATAL_APP_EXIT)));
	PyModule_AddObject(m, "WERR_PREDEFINED_HANDLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PREDEFINED_HANDLE)));
	PyModule_AddObject(m, "WERR_WAS_UNLOCKED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WAS_UNLOCKED)));
	PyModule_AddObject(m, "WERR_WAS_LOCKED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WAS_LOCKED)));
	PyModule_AddObject(m, "WERR_ALREADY_WIN32",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ALREADY_WIN32)));
	PyModule_AddObject(m, "WERR_IMAGE_MACHINE_TYPE_MISMATCH_EXE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IMAGE_MACHINE_TYPE_MISMATCH_EXE)));
	PyModule_AddObject(m, "WERR_NO_YIELD_PERFORMED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_YIELD_PERFORMED)));
	PyModule_AddObject(m, "WERR_TIMER_RESUME_IGNORED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TIMER_RESUME_IGNORED)));
	PyModule_AddObject(m, "WERR_ARBITRATION_UNHANDLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ARBITRATION_UNHANDLED)));
	PyModule_AddObject(m, "WERR_CARDBUS_NOT_SUPPORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CARDBUS_NOT_SUPPORTED)));
	PyModule_AddObject(m, "WERR_MP_PROCESSOR_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MP_PROCESSOR_MISMATCH)));
	PyModule_AddObject(m, "WERR_HIBERNATED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_HIBERNATED)));
	PyModule_AddObject(m, "WERR_RESUME_HIBERNATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RESUME_HIBERNATION)));
	PyModule_AddObject(m, "WERR_FIRMWARE_UPDATED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FIRMWARE_UPDATED)));
	PyModule_AddObject(m, "WERR_DRIVERS_LEAKING_LOCKED_PAGES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DRIVERS_LEAKING_LOCKED_PAGES)));
	PyModule_AddObject(m, "WERR_WAKE_SYSTEM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WAKE_SYSTEM)));
	PyModule_AddObject(m, "WERR_ABANDONED_WAIT_0",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ABANDONED_WAIT_0)));
	PyModule_AddObject(m, "WERR_ELEVATION_REQUIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ELEVATION_REQUIRED)));
	PyModule_AddObject(m, "WERR_REPARSE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_REPARSE)));
	PyModule_AddObject(m, "WERR_OPLOCK_BREAK_IN_PROGRESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_OPLOCK_BREAK_IN_PROGRESS)));
	PyModule_AddObject(m, "WERR_VOLUME_MOUNTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_VOLUME_MOUNTED)));
	PyModule_AddObject(m, "WERR_RXACT_COMMITTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RXACT_COMMITTED)));
	PyModule_AddObject(m, "WERR_NOTIFY_CLEANUP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOTIFY_CLEANUP)));
	PyModule_AddObject(m, "WERR_PRIMARY_TRANSPORT_CONNECT_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PRIMARY_TRANSPORT_CONNECT_FAILED)));
	PyModule_AddObject(m, "WERR_PAGE_FAULT_TRANSITION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PAGE_FAULT_TRANSITION)));
	PyModule_AddObject(m, "WERR_PAGE_FAULT_DEMAND_ZERO",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PAGE_FAULT_DEMAND_ZERO)));
	PyModule_AddObject(m, "WERR_PAGE_FAULT_COPY_ON_WRITE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PAGE_FAULT_COPY_ON_WRITE)));
	PyModule_AddObject(m, "WERR_PAGE_FAULT_GUARD_PAGE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PAGE_FAULT_GUARD_PAGE)));
	PyModule_AddObject(m, "WERR_PAGE_FAULT_PAGING_FILE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PAGE_FAULT_PAGING_FILE)));
	PyModule_AddObject(m, "WERR_CACHE_PAGE_LOCKED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CACHE_PAGE_LOCKED)));
	PyModule_AddObject(m, "WERR_CRASH_DUMP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CRASH_DUMP)));
	PyModule_AddObject(m, "WERR_BUFFER_ALL_ZEROS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BUFFER_ALL_ZEROS)));
	PyModule_AddObject(m, "WERR_REPARSE_OBJECT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_REPARSE_OBJECT)));
	PyModule_AddObject(m, "WERR_RESOURCE_REQUIREMENTS_CHANGED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RESOURCE_REQUIREMENTS_CHANGED)));
	PyModule_AddObject(m, "WERR_TRANSLATION_COMPLETE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TRANSLATION_COMPLETE)));
	PyModule_AddObject(m, "WERR_NOTHING_TO_TERMINATE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOTHING_TO_TERMINATE)));
	PyModule_AddObject(m, "WERR_PROCESS_NOT_IN_JOB",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PROCESS_NOT_IN_JOB)));
	PyModule_AddObject(m, "WERR_PROCESS_IN_JOB",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PROCESS_IN_JOB)));
	PyModule_AddObject(m, "WERR_VOLSNAP_HIBERNATE_READY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_VOLSNAP_HIBERNATE_READY)));
	PyModule_AddObject(m, "WERR_FSFILTER_OP_COMPLETED_SUCCESSFULLY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FSFILTER_OP_COMPLETED_SUCCESSFULLY)));
	PyModule_AddObject(m, "WERR_INTERRUPT_VECTOR_ALREADY_CONNECTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INTERRUPT_VECTOR_ALREADY_CONNECTED)));
	PyModule_AddObject(m, "WERR_INTERRUPT_STILL_CONNECTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INTERRUPT_STILL_CONNECTED)));
	PyModule_AddObject(m, "WERR_WAIT_FOR_OPLOCK",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WAIT_FOR_OPLOCK)));
	PyModule_AddObject(m, "WERR_DBG_EXCEPTION_HANDLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DBG_EXCEPTION_HANDLED)));
	PyModule_AddObject(m, "WERR_DBG_CONTINUE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DBG_CONTINUE)));
	PyModule_AddObject(m, "WERR_CALLBACK_POP_STACK",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CALLBACK_POP_STACK)));
	PyModule_AddObject(m, "WERR_COMPRESSION_DISABLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_COMPRESSION_DISABLED)));
	PyModule_AddObject(m, "WERR_CANTFETCHBACKWARDS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANTFETCHBACKWARDS)));
	PyModule_AddObject(m, "WERR_CANTSCROLLBACKWARDS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANTSCROLLBACKWARDS)));
	PyModule_AddObject(m, "WERR_ROWSNOTRELEASED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ROWSNOTRELEASED)));
	PyModule_AddObject(m, "WERR_BAD_ACCESSOR_FLAGS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_ACCESSOR_FLAGS)));
	PyModule_AddObject(m, "WERR_ERRORS_ENCOUNTERED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ERRORS_ENCOUNTERED)));
	PyModule_AddObject(m, "WERR_NOT_CAPABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_CAPABLE)));
	PyModule_AddObject(m, "WERR_REQUEST_OUT_OF_SEQUENCE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_REQUEST_OUT_OF_SEQUENCE)));
	PyModule_AddObject(m, "WERR_VERSION_PARSE_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_VERSION_PARSE_ERROR)));
	PyModule_AddObject(m, "WERR_BADSTARTPOSITION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BADSTARTPOSITION)));
	PyModule_AddObject(m, "WERR_MEMORY_HARDWARE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MEMORY_HARDWARE)));
	PyModule_AddObject(m, "WERR_DISK_REPAIR_DISABLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DISK_REPAIR_DISABLED)));
	PyModule_AddObject(m, "WERR_INSUFFICIENT_RESOURCE_FOR_SPECIFIED_SHARED_SECTION_SIZE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INSUFFICIENT_RESOURCE_FOR_SPECIFIED_SHARED_SECTION_SIZE)));
	PyModule_AddObject(m, "WERR_SYSTEM_POWERSTATE_TRANSITION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SYSTEM_POWERSTATE_TRANSITION)));
	PyModule_AddObject(m, "WERR_SYSTEM_POWERSTATE_COMPLEX_TRANSITION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SYSTEM_POWERSTATE_COMPLEX_TRANSITION)));
	PyModule_AddObject(m, "WERR_MCA_EXCEPTION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MCA_EXCEPTION)));
	PyModule_AddObject(m, "WERR_ACCESS_AUDIT_BY_POLICY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ACCESS_AUDIT_BY_POLICY)));
	PyModule_AddObject(m, "WERR_ACCESS_DISABLED_NO_SAFER_UI_BY_POLICY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ACCESS_DISABLED_NO_SAFER_UI_BY_POLICY)));
	PyModule_AddObject(m, "WERR_ABANDON_HIBERFILE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ABANDON_HIBERFILE)));
	PyModule_AddObject(m, "WERR_LOST_WRITEBEHIND_DATA_NETWORK_DISCONNECTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOST_WRITEBEHIND_DATA_NETWORK_DISCONNECTED)));
	PyModule_AddObject(m, "WERR_LOST_WRITEBEHIND_DATA_NETWORK_SERVER_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOST_WRITEBEHIND_DATA_NETWORK_SERVER_ERROR)));
	PyModule_AddObject(m, "WERR_LOST_WRITEBEHIND_DATA_LOCAL_DISK_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOST_WRITEBEHIND_DATA_LOCAL_DISK_ERROR)));
	PyModule_AddObject(m, "WERR_EA_ACCESS_DENIED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EA_ACCESS_DENIED)));
	PyModule_AddObject(m, "WERR_OPERATION_ABORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_OPERATION_ABORTED)));
	PyModule_AddObject(m, "WERR_IO_INCOMPLETE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IO_INCOMPLETE)));
	PyModule_AddObject(m, "WERR_IO_PENDING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IO_PENDING)));
	PyModule_AddObject(m, "WERR_NOACCESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOACCESS)));
	PyModule_AddObject(m, "WERR_SWAPERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SWAPERROR)));
	PyModule_AddObject(m, "WERR_STACK_OVERFLOW",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_STACK_OVERFLOW)));
	PyModule_AddObject(m, "WERR_INVALID_MESSAGE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_MESSAGE)));
	PyModule_AddObject(m, "WERR_CAN_NOT_COMPLETE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CAN_NOT_COMPLETE)));
	PyModule_AddObject(m, "WERR_INVALID_FLAGS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_FLAGS)));
	PyModule_AddObject(m, "WERR_UNRECOGNIZED_VOLUME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNRECOGNIZED_VOLUME)));
	PyModule_AddObject(m, "WERR_FILE_INVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FILE_INVALID)));
	PyModule_AddObject(m, "WERR_FULLSCREEN_MODE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FULLSCREEN_MODE)));
	PyModule_AddObject(m, "WERR_NO_TOKEN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_TOKEN)));
	PyModule_AddObject(m, "WERR_BADDB",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BADDB)));
	PyModule_AddObject(m, "WERR_BADKEY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BADKEY)));
	PyModule_AddObject(m, "WERR_CANTOPEN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANTOPEN)));
	PyModule_AddObject(m, "WERR_CANTREAD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANTREAD)));
	PyModule_AddObject(m, "WERR_CANTWRITE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANTWRITE)));
	PyModule_AddObject(m, "WERR_REGISTRY_RECOVERED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_REGISTRY_RECOVERED)));
	PyModule_AddObject(m, "WERR_REGISTRY_CORRUPT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_REGISTRY_CORRUPT)));
	PyModule_AddObject(m, "WERR_REGISTRY_IO_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_REGISTRY_IO_FAILED)));
	PyModule_AddObject(m, "WERR_NOT_REGISTRY_FILE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_REGISTRY_FILE)));
	PyModule_AddObject(m, "WERR_KEY_DELETED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_KEY_DELETED)));
	PyModule_AddObject(m, "WERR_NO_LOG_SPACE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_LOG_SPACE)));
	PyModule_AddObject(m, "WERR_KEY_HAS_CHILDREN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_KEY_HAS_CHILDREN)));
	PyModule_AddObject(m, "WERR_CHILD_MUST_BE_VOLATILE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CHILD_MUST_BE_VOLATILE)));
	PyModule_AddObject(m, "WERR_NOTIFY_ENUM_DIR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOTIFY_ENUM_DIR)));
	PyModule_AddObject(m, "WERR_DEPENDENT_SERVICES_RUNNING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DEPENDENT_SERVICES_RUNNING)));
	PyModule_AddObject(m, "WERR_INVALID_SERVICE_CONTROL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_SERVICE_CONTROL)));
	PyModule_AddObject(m, "WERR_SERVICE_REQUEST_TIMEOUT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SERVICE_REQUEST_TIMEOUT)));
	PyModule_AddObject(m, "WERR_SERVICE_NO_THREAD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SERVICE_NO_THREAD)));
	PyModule_AddObject(m, "WERR_SERVICE_DATABASE_LOCKED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SERVICE_DATABASE_LOCKED)));
	PyModule_AddObject(m, "WERR_SERVICE_ALREADY_RUNNING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SERVICE_ALREADY_RUNNING)));
	PyModule_AddObject(m, "WERR_INVALID_SERVICE_ACCOUNT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_SERVICE_ACCOUNT)));
	PyModule_AddObject(m, "WERR_SERVICE_DISABLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SERVICE_DISABLED)));
	PyModule_AddObject(m, "WERR_CIRCULAR_DEPENDENCY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CIRCULAR_DEPENDENCY)));
	PyModule_AddObject(m, "WERR_SERVICE_DOES_NOT_EXIST",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SERVICE_DOES_NOT_EXIST)));
	PyModule_AddObject(m, "WERR_SERVICE_CANNOT_ACCEPT_CTRL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SERVICE_CANNOT_ACCEPT_CTRL)));
	PyModule_AddObject(m, "WERR_SERVICE_NOT_ACTIVE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SERVICE_NOT_ACTIVE)));
	PyModule_AddObject(m, "WERR_FAILED_SERVICE_CONTROLLER_CONNECT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FAILED_SERVICE_CONTROLLER_CONNECT)));
	PyModule_AddObject(m, "WERR_EXCEPTION_IN_SERVICE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EXCEPTION_IN_SERVICE)));
	PyModule_AddObject(m, "WERR_DATABASE_DOES_NOT_EXIST",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DATABASE_DOES_NOT_EXIST)));
	PyModule_AddObject(m, "WERR_SERVICE_SPECIFIC_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SERVICE_SPECIFIC_ERROR)));
	PyModule_AddObject(m, "WERR_PROCESS_ABORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PROCESS_ABORTED)));
	PyModule_AddObject(m, "WERR_SERVICE_DEPENDENCY_FAIL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SERVICE_DEPENDENCY_FAIL)));
	PyModule_AddObject(m, "WERR_SERVICE_LOGON_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SERVICE_LOGON_FAILED)));
	PyModule_AddObject(m, "WERR_SERVICE_START_HANG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SERVICE_START_HANG)));
	PyModule_AddObject(m, "WERR_INVALID_SERVICE_LOCK",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_SERVICE_LOCK)));
	PyModule_AddObject(m, "WERR_SERVICE_MARKED_FOR_DELETE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SERVICE_MARKED_FOR_DELETE)));
	PyModule_AddObject(m, "WERR_SERVICE_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SERVICE_EXISTS)));
	PyModule_AddObject(m, "WERR_ALREADY_RUNNING_LKG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ALREADY_RUNNING_LKG)));
	PyModule_AddObject(m, "WERR_SERVICE_DEPENDENCY_DELETED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SERVICE_DEPENDENCY_DELETED)));
	PyModule_AddObject(m, "WERR_BOOT_ALREADY_ACCEPTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BOOT_ALREADY_ACCEPTED)));
	PyModule_AddObject(m, "WERR_SERVICE_NEVER_STARTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SERVICE_NEVER_STARTED)));
	PyModule_AddObject(m, "WERR_DUPLICATE_SERVICE_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DUPLICATE_SERVICE_NAME)));
	PyModule_AddObject(m, "WERR_DIFFERENT_SERVICE_ACCOUNT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DIFFERENT_SERVICE_ACCOUNT)));
	PyModule_AddObject(m, "WERR_CANNOT_DETECT_DRIVER_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANNOT_DETECT_DRIVER_FAILURE)));
	PyModule_AddObject(m, "WERR_CANNOT_DETECT_PROCESS_ABORT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANNOT_DETECT_PROCESS_ABORT)));
	PyModule_AddObject(m, "WERR_NO_RECOVERY_PROGRAM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_RECOVERY_PROGRAM)));
	PyModule_AddObject(m, "WERR_SERVICE_NOT_IN_EXE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SERVICE_NOT_IN_EXE)));
	PyModule_AddObject(m, "WERR_NOT_SAFEBOOT_SERVICE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_SAFEBOOT_SERVICE)));
	PyModule_AddObject(m, "WERR_END_OF_MEDIA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_END_OF_MEDIA)));
	PyModule_AddObject(m, "WERR_FILEMARK_DETECTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FILEMARK_DETECTED)));
	PyModule_AddObject(m, "WERR_BEGINNING_OF_MEDIA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BEGINNING_OF_MEDIA)));
	PyModule_AddObject(m, "WERR_SETMARK_DETECTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SETMARK_DETECTED)));
	PyModule_AddObject(m, "WERR_NO_DATA_DETECTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_DATA_DETECTED)));
	PyModule_AddObject(m, "WERR_PARTITION_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PARTITION_FAILURE)));
	PyModule_AddObject(m, "WERR_INVALID_BLOCK_LENGTH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_BLOCK_LENGTH)));
	PyModule_AddObject(m, "WERR_DEVICE_NOT_PARTITIONED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DEVICE_NOT_PARTITIONED)));
	PyModule_AddObject(m, "WERR_UNABLE_TO_LOCK_MEDIA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNABLE_TO_LOCK_MEDIA)));
	PyModule_AddObject(m, "WERR_UNABLE_TO_UNLOAD_MEDIA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNABLE_TO_UNLOAD_MEDIA)));
	PyModule_AddObject(m, "WERR_MEDIA_CHANGED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MEDIA_CHANGED)));
	PyModule_AddObject(m, "WERR_BUS_RESET",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BUS_RESET)));
	PyModule_AddObject(m, "WERR_NO_MEDIA_IN_DRIVE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_MEDIA_IN_DRIVE)));
	PyModule_AddObject(m, "WERR_NO_UNICODE_TRANSLATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_UNICODE_TRANSLATION)));
	PyModule_AddObject(m, "WERR_DLL_INIT_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DLL_INIT_FAILED)));
	PyModule_AddObject(m, "WERR_SHUTDOWN_IN_PROGRESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SHUTDOWN_IN_PROGRESS)));
	PyModule_AddObject(m, "WERR_NO_SHUTDOWN_IN_PROGRESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_SHUTDOWN_IN_PROGRESS)));
	PyModule_AddObject(m, "WERR_IO_DEVICE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IO_DEVICE)));
	PyModule_AddObject(m, "WERR_SERIAL_NO_DEVICE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SERIAL_NO_DEVICE)));
	PyModule_AddObject(m, "WERR_IRQ_BUSY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IRQ_BUSY)));
	PyModule_AddObject(m, "WERR_MORE_WRITES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MORE_WRITES)));
	PyModule_AddObject(m, "WERR_COUNTER_TIMEOUT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_COUNTER_TIMEOUT)));
	PyModule_AddObject(m, "WERR_FLOPPY_ID_MARK_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FLOPPY_ID_MARK_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_FLOPPY_WRONG_CYLINDER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FLOPPY_WRONG_CYLINDER)));
	PyModule_AddObject(m, "WERR_FLOPPY_UNKNOWN_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FLOPPY_UNKNOWN_ERROR)));
	PyModule_AddObject(m, "WERR_FLOPPY_BAD_REGISTERS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FLOPPY_BAD_REGISTERS)));
	PyModule_AddObject(m, "WERR_DISK_RECALIBRATE_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DISK_RECALIBRATE_FAILED)));
	PyModule_AddObject(m, "WERR_DISK_OPERATION_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DISK_OPERATION_FAILED)));
	PyModule_AddObject(m, "WERR_DISK_RESET_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DISK_RESET_FAILED)));
	PyModule_AddObject(m, "WERR_EOM_OVERFLOW",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EOM_OVERFLOW)));
	PyModule_AddObject(m, "WERR_NOT_ENOUGH_SERVER_MEMORY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_ENOUGH_SERVER_MEMORY)));
	PyModule_AddObject(m, "WERR_POSSIBLE_DEADLOCK",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_POSSIBLE_DEADLOCK)));
	PyModule_AddObject(m, "WERR_MAPPED_ALIGNMENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MAPPED_ALIGNMENT)));
	PyModule_AddObject(m, "WERR_SET_POWER_STATE_VETOED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SET_POWER_STATE_VETOED)));
	PyModule_AddObject(m, "WERR_SET_POWER_STATE_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SET_POWER_STATE_FAILED)));
	PyModule_AddObject(m, "WERR_TOO_MANY_LINKS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TOO_MANY_LINKS)));
	PyModule_AddObject(m, "WERR_OLD_WIN_VERSION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_OLD_WIN_VERSION)));
	PyModule_AddObject(m, "WERR_APP_WRONG_OS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_APP_WRONG_OS)));
	PyModule_AddObject(m, "WERR_SINGLE_INSTANCE_APP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SINGLE_INSTANCE_APP)));
	PyModule_AddObject(m, "WERR_RMODE_APP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RMODE_APP)));
	PyModule_AddObject(m, "WERR_INVALID_DLL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_DLL)));
	PyModule_AddObject(m, "WERR_NO_ASSOCIATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_ASSOCIATION)));
	PyModule_AddObject(m, "WERR_DDE_FAIL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DDE_FAIL)));
	PyModule_AddObject(m, "WERR_DLL_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DLL_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_NO_MORE_USER_HANDLES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_MORE_USER_HANDLES)));
	PyModule_AddObject(m, "WERR_MESSAGE_SYNC_ONLY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MESSAGE_SYNC_ONLY)));
	PyModule_AddObject(m, "WERR_SOURCE_ELEMENT_EMPTY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SOURCE_ELEMENT_EMPTY)));
	PyModule_AddObject(m, "WERR_DESTINATION_ELEMENT_FULL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DESTINATION_ELEMENT_FULL)));
	PyModule_AddObject(m, "WERR_ILLEGAL_ELEMENT_ADDRESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ILLEGAL_ELEMENT_ADDRESS)));
	PyModule_AddObject(m, "WERR_MAGAZINE_NOT_PRESENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MAGAZINE_NOT_PRESENT)));
	PyModule_AddObject(m, "WERR_DEVICE_REINITIALIZATION_NEEDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DEVICE_REINITIALIZATION_NEEDED)));
	PyModule_AddObject(m, "WERR_DEVICE_REQUIRES_CLEANING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DEVICE_REQUIRES_CLEANING)));
	PyModule_AddObject(m, "WERR_DEVICE_DOOR_OPEN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DEVICE_DOOR_OPEN)));
	PyModule_AddObject(m, "WERR_DEVICE_NOT_CONNECTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DEVICE_NOT_CONNECTED)));
	PyModule_AddObject(m, "WERR_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_NO_MATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_MATCH)));
	PyModule_AddObject(m, "WERR_SET_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SET_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_POINT_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_POINT_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_NO_TRACKING_SERVICE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_TRACKING_SERVICE)));
	PyModule_AddObject(m, "WERR_NO_VOLUME_ID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_VOLUME_ID)));
	PyModule_AddObject(m, "WERR_UNABLE_TO_REMOVE_REPLACED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNABLE_TO_REMOVE_REPLACED)));
	PyModule_AddObject(m, "WERR_UNABLE_TO_MOVE_REPLACEMENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNABLE_TO_MOVE_REPLACEMENT)));
	PyModule_AddObject(m, "WERR_UNABLE_TO_MOVE_REPLACEMENT_2",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNABLE_TO_MOVE_REPLACEMENT_2)));
	PyModule_AddObject(m, "WERR_JOURNAL_DELETE_IN_PROGRESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_JOURNAL_DELETE_IN_PROGRESS)));
	PyModule_AddObject(m, "WERR_JOURNAL_NOT_ACTIVE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_JOURNAL_NOT_ACTIVE)));
	PyModule_AddObject(m, "WERR_POTENTIAL_FILE_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_POTENTIAL_FILE_FOUND)));
	PyModule_AddObject(m, "WERR_JOURNAL_ENTRY_DELETED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_JOURNAL_ENTRY_DELETED)));
	PyModule_AddObject(m, "WERR_SHUTDOWN_IS_SCHEDULED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SHUTDOWN_IS_SCHEDULED)));
	PyModule_AddObject(m, "WERR_SHUTDOWN_USERS_LOGGED_ON",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SHUTDOWN_USERS_LOGGED_ON)));
	PyModule_AddObject(m, "WERR_BAD_DEVICE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_DEVICE)));
	PyModule_AddObject(m, "WERR_CONNECTION_UNAVAIL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CONNECTION_UNAVAIL)));
	PyModule_AddObject(m, "WERR_DEVICE_ALREADY_REMEMBERED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DEVICE_ALREADY_REMEMBERED)));
	PyModule_AddObject(m, "WERR_NO_NET_OR_BAD_PATH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_NET_OR_BAD_PATH)));
	PyModule_AddObject(m, "WERR_BAD_PROVIDER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_PROVIDER)));
	PyModule_AddObject(m, "WERR_CANNOT_OPEN_PROFILE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANNOT_OPEN_PROFILE)));
	PyModule_AddObject(m, "WERR_BAD_PROFILE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_PROFILE)));
	PyModule_AddObject(m, "WERR_NOT_CONTAINER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_CONTAINER)));
	PyModule_AddObject(m, "WERR_EXTENDED_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EXTENDED_ERROR)));
	PyModule_AddObject(m, "WERR_INVALID_GROUPNAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_GROUPNAME)));
	PyModule_AddObject(m, "WERR_INVALID_COMPUTERNAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_COMPUTERNAME)));
	PyModule_AddObject(m, "WERR_INVALID_EVENTNAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_EVENTNAME)));
	PyModule_AddObject(m, "WERR_INVALID_DOMAINNAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_DOMAINNAME)));
	PyModule_AddObject(m, "WERR_INVALID_SERVICENAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_SERVICENAME)));
	PyModule_AddObject(m, "WERR_INVALID_NETNAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_NETNAME)));
	PyModule_AddObject(m, "WERR_INVALID_SHARENAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_SHARENAME)));
	PyModule_AddObject(m, "WERR_INVALID_PASSWORDNAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_PASSWORDNAME)));
	PyModule_AddObject(m, "WERR_INVALID_MESSAGENAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_MESSAGENAME)));
	PyModule_AddObject(m, "WERR_INVALID_MESSAGEDEST",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_MESSAGEDEST)));
	PyModule_AddObject(m, "WERR_SESSION_CREDENTIAL_CONFLICT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SESSION_CREDENTIAL_CONFLICT)));
	PyModule_AddObject(m, "WERR_REMOTE_SESSION_LIMIT_EXCEEDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_REMOTE_SESSION_LIMIT_EXCEEDED)));
	PyModule_AddObject(m, "WERR_DUP_DOMAINNAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DUP_DOMAINNAME)));
	PyModule_AddObject(m, "WERR_NO_NETWORK",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_NETWORK)));
	PyModule_AddObject(m, "WERR_CANCELLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANCELLED)));
	PyModule_AddObject(m, "WERR_USER_MAPPED_FILE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_USER_MAPPED_FILE)));
	PyModule_AddObject(m, "WERR_CONNECTION_REFUSED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CONNECTION_REFUSED)));
	PyModule_AddObject(m, "WERR_GRACEFUL_DISCONNECT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_GRACEFUL_DISCONNECT)));
	PyModule_AddObject(m, "WERR_ADDRESS_ALREADY_ASSOCIATED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ADDRESS_ALREADY_ASSOCIATED)));
	PyModule_AddObject(m, "WERR_ADDRESS_NOT_ASSOCIATED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ADDRESS_NOT_ASSOCIATED)));
	PyModule_AddObject(m, "WERR_CONNECTION_INVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CONNECTION_INVALID)));
	PyModule_AddObject(m, "WERR_CONNECTION_ACTIVE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CONNECTION_ACTIVE)));
	PyModule_AddObject(m, "WERR_NETWORK_UNREACHABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NETWORK_UNREACHABLE)));
	PyModule_AddObject(m, "WERR_HOST_UNREACHABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_HOST_UNREACHABLE)));
	PyModule_AddObject(m, "WERR_PROTOCOL_UNREACHABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PROTOCOL_UNREACHABLE)));
	PyModule_AddObject(m, "WERR_PORT_UNREACHABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PORT_UNREACHABLE)));
	PyModule_AddObject(m, "WERR_REQUEST_ABORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_REQUEST_ABORTED)));
	PyModule_AddObject(m, "WERR_CONNECTION_ABORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CONNECTION_ABORTED)));
	PyModule_AddObject(m, "WERR_RETRY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RETRY)));
	PyModule_AddObject(m, "WERR_CONNECTION_COUNT_LIMIT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CONNECTION_COUNT_LIMIT)));
	PyModule_AddObject(m, "WERR_LOGIN_TIME_RESTRICTION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOGIN_TIME_RESTRICTION)));
	PyModule_AddObject(m, "WERR_LOGIN_WKSTA_RESTRICTION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOGIN_WKSTA_RESTRICTION)));
	PyModule_AddObject(m, "WERR_INCORRECT_ADDRESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INCORRECT_ADDRESS)));
	PyModule_AddObject(m, "WERR_ALREADY_REGISTERED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ALREADY_REGISTERED)));
	PyModule_AddObject(m, "WERR_SERVICE_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SERVICE_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_NOT_AUTHENTICATED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_AUTHENTICATED)));
	PyModule_AddObject(m, "WERR_NOT_LOGGED_ON",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_LOGGED_ON)));
	PyModule_AddObject(m, "WERR_CONTINUE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CONTINUE)));
	PyModule_AddObject(m, "WERR_ALREADY_INITIALIZED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ALREADY_INITIALIZED)));
	PyModule_AddObject(m, "WERR_NO_MORE_DEVICES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_MORE_DEVICES)));
	PyModule_AddObject(m, "WERR_NO_SUCH_SITE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_SUCH_SITE)));
	PyModule_AddObject(m, "WERR_DOMAIN_CONTROLLER_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DOMAIN_CONTROLLER_EXISTS)));
	PyModule_AddObject(m, "WERR_ONLY_IF_CONNECTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ONLY_IF_CONNECTED)));
	PyModule_AddObject(m, "WERR_OVERRIDE_NOCHANGES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_OVERRIDE_NOCHANGES)));
	PyModule_AddObject(m, "WERR_BAD_USER_PROFILE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_USER_PROFILE)));
	PyModule_AddObject(m, "WERR_NOT_SUPPORTED_ON_SBS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_SUPPORTED_ON_SBS)));
	PyModule_AddObject(m, "WERR_SERVER_SHUTDOWN_IN_PROGRESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SERVER_SHUTDOWN_IN_PROGRESS)));
	PyModule_AddObject(m, "WERR_HOST_DOWN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_HOST_DOWN)));
	PyModule_AddObject(m, "WERR_NON_ACCOUNT_SID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NON_ACCOUNT_SID)));
	PyModule_AddObject(m, "WERR_NON_DOMAIN_SID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NON_DOMAIN_SID)));
	PyModule_AddObject(m, "WERR_APPHELP_BLOCK",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_APPHELP_BLOCK)));
	PyModule_AddObject(m, "WERR_ACCESS_DISABLED_BY_POLICY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ACCESS_DISABLED_BY_POLICY)));
	PyModule_AddObject(m, "WERR_REG_NAT_CONSUMPTION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_REG_NAT_CONSUMPTION)));
	PyModule_AddObject(m, "WERR_CSCSHARE_OFFLINE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CSCSHARE_OFFLINE)));
	PyModule_AddObject(m, "WERR_PKINIT_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PKINIT_FAILURE)));
	PyModule_AddObject(m, "WERR_SMARTCARD_SUBSYSTEM_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SMARTCARD_SUBSYSTEM_FAILURE)));
	PyModule_AddObject(m, "WERR_DOWNGRADE_DETECTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DOWNGRADE_DETECTED)));
	PyModule_AddObject(m, "WERR_MACHINE_LOCKED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MACHINE_LOCKED)));
	PyModule_AddObject(m, "WERR_CALLBACK_SUPPLIED_INVALID_DATA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CALLBACK_SUPPLIED_INVALID_DATA)));
	PyModule_AddObject(m, "WERR_SYNC_FOREGROUND_REFRESH_REQUIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SYNC_FOREGROUND_REFRESH_REQUIRED)));
	PyModule_AddObject(m, "WERR_DRIVER_BLOCKED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DRIVER_BLOCKED)));
	PyModule_AddObject(m, "WERR_INVALID_IMPORT_OF_NON_DLL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_IMPORT_OF_NON_DLL)));
	PyModule_AddObject(m, "WERR_ACCESS_DISABLED_WEBBLADE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ACCESS_DISABLED_WEBBLADE)));
	PyModule_AddObject(m, "WERR_ACCESS_DISABLED_WEBBLADE_TAMPER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ACCESS_DISABLED_WEBBLADE_TAMPER)));
	PyModule_AddObject(m, "WERR_RECOVERY_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RECOVERY_FAILURE)));
	PyModule_AddObject(m, "WERR_ALREADY_FIBER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ALREADY_FIBER)));
	PyModule_AddObject(m, "WERR_ALREADY_THREAD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ALREADY_THREAD)));
	PyModule_AddObject(m, "WERR_STACK_BUFFER_OVERRUN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_STACK_BUFFER_OVERRUN)));
	PyModule_AddObject(m, "WERR_PARAMETER_QUOTA_EXCEEDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PARAMETER_QUOTA_EXCEEDED)));
	PyModule_AddObject(m, "WERR_DEBUGGER_INACTIVE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DEBUGGER_INACTIVE)));
	PyModule_AddObject(m, "WERR_DELAY_LOAD_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DELAY_LOAD_FAILED)));
	PyModule_AddObject(m, "WERR_VDM_DISALLOWED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_VDM_DISALLOWED)));
	PyModule_AddObject(m, "WERR_UNIDENTIFIED_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNIDENTIFIED_ERROR)));
	PyModule_AddObject(m, "WERR_INVALID_CRUNTIME_PARAMETER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_CRUNTIME_PARAMETER)));
	PyModule_AddObject(m, "WERR_BEYOND_VDL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BEYOND_VDL)));
	PyModule_AddObject(m, "WERR_INCOMPATIBLE_SERVICE_SID_TYPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INCOMPATIBLE_SERVICE_SID_TYPE)));
	PyModule_AddObject(m, "WERR_DRIVER_PROCESS_TERMINATED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DRIVER_PROCESS_TERMINATED)));
	PyModule_AddObject(m, "WERR_IMPLEMENTATION_LIMIT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IMPLEMENTATION_LIMIT)));
	PyModule_AddObject(m, "WERR_PROCESS_IS_PROTECTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PROCESS_IS_PROTECTED)));
	PyModule_AddObject(m, "WERR_SERVICE_NOTIFY_CLIENT_LAGGING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SERVICE_NOTIFY_CLIENT_LAGGING)));
	PyModule_AddObject(m, "WERR_DISK_QUOTA_EXCEEDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DISK_QUOTA_EXCEEDED)));
	PyModule_AddObject(m, "WERR_CONTENT_BLOCKED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CONTENT_BLOCKED)));
	PyModule_AddObject(m, "WERR_INCOMPATIBLE_SERVICE_PRIVILEGE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INCOMPATIBLE_SERVICE_PRIVILEGE)));
	PyModule_AddObject(m, "WERR_INVALID_LABEL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_LABEL)));
	PyModule_AddObject(m, "WERR_NOT_ALL_ASSIGNED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_ALL_ASSIGNED)));
	PyModule_AddObject(m, "WERR_SOME_NOT_MAPPED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SOME_NOT_MAPPED)));
	PyModule_AddObject(m, "WERR_NO_QUOTAS_FOR_ACCOUNT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_QUOTAS_FOR_ACCOUNT)));
	PyModule_AddObject(m, "WERR_LOCAL_USER_SESSION_KEY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOCAL_USER_SESSION_KEY)));
	PyModule_AddObject(m, "WERR_NULL_LM_PASSWORD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NULL_LM_PASSWORD)));
	PyModule_AddObject(m, "WERR_UNKNOWN_REVISION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNKNOWN_REVISION)));
	PyModule_AddObject(m, "WERR_REVISION_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_REVISION_MISMATCH)));
	PyModule_AddObject(m, "WERR_INVALID_OWNER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_OWNER)));
	PyModule_AddObject(m, "WERR_NO_IMPERSONATION_TOKEN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_IMPERSONATION_TOKEN)));
	PyModule_AddObject(m, "WERR_CANT_DISABLE_MANDATORY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANT_DISABLE_MANDATORY)));
	PyModule_AddObject(m, "WERR_NO_LOGON_SERVERS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_LOGON_SERVERS)));
	PyModule_AddObject(m, "WERR_NO_SUCH_LOGON_SESSION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_SUCH_LOGON_SESSION)));
	PyModule_AddObject(m, "WERR_NO_SUCH_PRIVILEGE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_SUCH_PRIVILEGE)));
	PyModule_AddObject(m, "WERR_PRIVILEGE_NOT_HELD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PRIVILEGE_NOT_HELD)));
	PyModule_AddObject(m, "WERR_INVALID_ACCOUNT_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_ACCOUNT_NAME)));
	PyModule_AddObject(m, "WERR_USER_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_USER_EXISTS)));
	PyModule_AddObject(m, "WERR_NO_SUCH_USER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_SUCH_USER)));
	PyModule_AddObject(m, "WERR_GROUP_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_GROUP_EXISTS)));
	PyModule_AddObject(m, "WERR_NO_SUCH_GROUP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_SUCH_GROUP)));
	PyModule_AddObject(m, "WERR_MEMBER_IN_GROUP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MEMBER_IN_GROUP)));
	PyModule_AddObject(m, "WERR_MEMBER_NOT_IN_GROUP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MEMBER_NOT_IN_GROUP)));
	PyModule_AddObject(m, "WERR_LAST_ADMIN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LAST_ADMIN)));
	PyModule_AddObject(m, "WERR_WRONG_PASSWORD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WRONG_PASSWORD)));
	PyModule_AddObject(m, "WERR_ILL_FORMED_PASSWORD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ILL_FORMED_PASSWORD)));
	PyModule_AddObject(m, "WERR_PASSWORD_RESTRICTION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PASSWORD_RESTRICTION)));
	PyModule_AddObject(m, "WERR_LOGON_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOGON_FAILURE)));
	PyModule_AddObject(m, "WERR_ACCOUNT_RESTRICTION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ACCOUNT_RESTRICTION)));
	PyModule_AddObject(m, "WERR_INVALID_LOGON_HOURS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_LOGON_HOURS)));
	PyModule_AddObject(m, "WERR_INVALID_WORKSTATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_WORKSTATION)));
	PyModule_AddObject(m, "WERR_PASSWORD_EXPIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PASSWORD_EXPIRED)));
	PyModule_AddObject(m, "WERR_ACCOUNT_DISABLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ACCOUNT_DISABLED)));
	PyModule_AddObject(m, "WERR_NONE_MAPPED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NONE_MAPPED)));
	PyModule_AddObject(m, "WERR_TOO_MANY_LUIDS_REQUESTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TOO_MANY_LUIDS_REQUESTED)));
	PyModule_AddObject(m, "WERR_LUIDS_EXHAUSTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LUIDS_EXHAUSTED)));
	PyModule_AddObject(m, "WERR_INVALID_SUB_AUTHORITY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_SUB_AUTHORITY)));
	PyModule_AddObject(m, "WERR_INVALID_ACL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_ACL)));
	PyModule_AddObject(m, "WERR_INVALID_SID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_SID)));
	PyModule_AddObject(m, "WERR_INVALID_SECURITY_DESCR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_SECURITY_DESCR)));
	PyModule_AddObject(m, "WERR_BAD_INHERITANCE_ACL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_INHERITANCE_ACL)));
	PyModule_AddObject(m, "WERR_SERVER_DISABLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SERVER_DISABLED)));
	PyModule_AddObject(m, "WERR_SERVER_NOT_DISABLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SERVER_NOT_DISABLED)));
	PyModule_AddObject(m, "WERR_INVALID_ID_AUTHORITY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_ID_AUTHORITY)));
	PyModule_AddObject(m, "WERR_ALLOTTED_SPACE_EXCEEDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ALLOTTED_SPACE_EXCEEDED)));
	PyModule_AddObject(m, "WERR_INVALID_GROUP_ATTRIBUTES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_GROUP_ATTRIBUTES)));
	PyModule_AddObject(m, "WERR_BAD_IMPERSONATION_LEVEL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_IMPERSONATION_LEVEL)));
	PyModule_AddObject(m, "WERR_CANT_OPEN_ANONYMOUS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANT_OPEN_ANONYMOUS)));
	PyModule_AddObject(m, "WERR_BAD_VALIDATION_CLASS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_VALIDATION_CLASS)));
	PyModule_AddObject(m, "WERR_BAD_TOKEN_TYPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_TOKEN_TYPE)));
	PyModule_AddObject(m, "WERR_NO_SECURITY_ON_OBJECT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_SECURITY_ON_OBJECT)));
	PyModule_AddObject(m, "WERR_CANT_ACCESS_DOMAIN_INFO",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANT_ACCESS_DOMAIN_INFO)));
	PyModule_AddObject(m, "WERR_INVALID_SERVER_STATE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_SERVER_STATE)));
	PyModule_AddObject(m, "WERR_INVALID_DOMAIN_STATE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_DOMAIN_STATE)));
	PyModule_AddObject(m, "WERR_INVALID_DOMAIN_ROLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_DOMAIN_ROLE)));
	PyModule_AddObject(m, "WERR_NO_SUCH_DOMAIN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_SUCH_DOMAIN)));
	PyModule_AddObject(m, "WERR_DOMAIN_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DOMAIN_EXISTS)));
	PyModule_AddObject(m, "WERR_DOMAIN_LIMIT_EXCEEDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DOMAIN_LIMIT_EXCEEDED)));
	PyModule_AddObject(m, "WERR_INTERNAL_DB_CORRUPTION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INTERNAL_DB_CORRUPTION)));
	PyModule_AddObject(m, "WERR_INTERNAL_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INTERNAL_ERROR)));
	PyModule_AddObject(m, "WERR_GENERIC_NOT_MAPPED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_GENERIC_NOT_MAPPED)));
	PyModule_AddObject(m, "WERR_BAD_DESCRIPTOR_FORMAT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_DESCRIPTOR_FORMAT)));
	PyModule_AddObject(m, "WERR_NOT_LOGON_PROCESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_LOGON_PROCESS)));
	PyModule_AddObject(m, "WERR_LOGON_SESSION_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOGON_SESSION_EXISTS)));
	PyModule_AddObject(m, "WERR_NO_SUCH_PACKAGE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_SUCH_PACKAGE)));
	PyModule_AddObject(m, "WERR_BAD_LOGON_SESSION_STATE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_LOGON_SESSION_STATE)));
	PyModule_AddObject(m, "WERR_LOGON_SESSION_COLLISION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOGON_SESSION_COLLISION)));
	PyModule_AddObject(m, "WERR_INVALID_LOGON_TYPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_LOGON_TYPE)));
	PyModule_AddObject(m, "WERR_CANNOT_IMPERSONATE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANNOT_IMPERSONATE)));
	PyModule_AddObject(m, "WERR_RXACT_INVALID_STATE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RXACT_INVALID_STATE)));
	PyModule_AddObject(m, "WERR_RXACT_COMMIT_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RXACT_COMMIT_FAILURE)));
	PyModule_AddObject(m, "WERR_SPECIAL_ACCOUNT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SPECIAL_ACCOUNT)));
	PyModule_AddObject(m, "WERR_SPECIAL_GROUP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SPECIAL_GROUP)));
	PyModule_AddObject(m, "WERR_SPECIAL_USER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SPECIAL_USER)));
	PyModule_AddObject(m, "WERR_MEMBERS_PRIMARY_GROUP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MEMBERS_PRIMARY_GROUP)));
	PyModule_AddObject(m, "WERR_TOKEN_ALREADY_IN_USE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TOKEN_ALREADY_IN_USE)));
	PyModule_AddObject(m, "WERR_NO_SUCH_ALIAS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_SUCH_ALIAS)));
	PyModule_AddObject(m, "WERR_MEMBER_NOT_IN_ALIAS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MEMBER_NOT_IN_ALIAS)));
	PyModule_AddObject(m, "WERR_MEMBER_IN_ALIAS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MEMBER_IN_ALIAS)));
	PyModule_AddObject(m, "WERR_ALIAS_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ALIAS_EXISTS)));
	PyModule_AddObject(m, "WERR_LOGON_NOT_GRANTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOGON_NOT_GRANTED)));
	PyModule_AddObject(m, "WERR_TOO_MANY_SECRETS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TOO_MANY_SECRETS)));
	PyModule_AddObject(m, "WERR_SECRET_TOO_LONG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SECRET_TOO_LONG)));
	PyModule_AddObject(m, "WERR_INTERNAL_DB_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INTERNAL_DB_ERROR)));
	PyModule_AddObject(m, "WERR_TOO_MANY_CONTEXT_IDS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TOO_MANY_CONTEXT_IDS)));
	PyModule_AddObject(m, "WERR_LOGON_TYPE_NOT_GRANTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOGON_TYPE_NOT_GRANTED)));
	PyModule_AddObject(m, "WERR_NT_CROSS_ENCRYPTION_REQUIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NT_CROSS_ENCRYPTION_REQUIRED)));
	PyModule_AddObject(m, "WERR_NO_SUCH_MEMBER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_SUCH_MEMBER)));
	PyModule_AddObject(m, "WERR_INVALID_MEMBER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_MEMBER)));
	PyModule_AddObject(m, "WERR_TOO_MANY_SIDS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TOO_MANY_SIDS)));
	PyModule_AddObject(m, "WERR_LM_CROSS_ENCRYPTION_REQUIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LM_CROSS_ENCRYPTION_REQUIRED)));
	PyModule_AddObject(m, "WERR_NO_INHERITANCE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_INHERITANCE)));
	PyModule_AddObject(m, "WERR_FILE_CORRUPT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FILE_CORRUPT)));
	PyModule_AddObject(m, "WERR_DISK_CORRUPT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DISK_CORRUPT)));
	PyModule_AddObject(m, "WERR_NO_USER_SESSION_KEY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_USER_SESSION_KEY)));
	PyModule_AddObject(m, "WERR_LICENSE_QUOTA_EXCEEDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LICENSE_QUOTA_EXCEEDED)));
	PyModule_AddObject(m, "WERR_WRONG_TARGET_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WRONG_TARGET_NAME)));
	PyModule_AddObject(m, "WERR_MUTUAL_AUTH_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MUTUAL_AUTH_FAILED)));
	PyModule_AddObject(m, "WERR_TIME_SKEW",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TIME_SKEW)));
	PyModule_AddObject(m, "WERR_CURRENT_DOMAIN_NOT_ALLOWED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CURRENT_DOMAIN_NOT_ALLOWED)));
	PyModule_AddObject(m, "WERR_INVALID_WINDOW_HANDLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_WINDOW_HANDLE)));
	PyModule_AddObject(m, "WERR_INVALID_MENU_HANDLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_MENU_HANDLE)));
	PyModule_AddObject(m, "WERR_INVALID_CURSOR_HANDLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_CURSOR_HANDLE)));
	PyModule_AddObject(m, "WERR_INVALID_ACCEL_HANDLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_ACCEL_HANDLE)));
	PyModule_AddObject(m, "WERR_INVALID_HOOK_HANDLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_HOOK_HANDLE)));
	PyModule_AddObject(m, "WERR_INVALID_DWP_HANDLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_DWP_HANDLE)));
	PyModule_AddObject(m, "WERR_TLW_WITH_WSCHILD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TLW_WITH_WSCHILD)));
	PyModule_AddObject(m, "WERR_CANNOT_FIND_WND_CLASS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANNOT_FIND_WND_CLASS)));
	PyModule_AddObject(m, "WERR_WINDOW_OF_OTHER_THREAD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WINDOW_OF_OTHER_THREAD)));
	PyModule_AddObject(m, "WERR_HOTKEY_ALREADY_REGISTERED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_HOTKEY_ALREADY_REGISTERED)));
	PyModule_AddObject(m, "WERR_CLASS_ALREADY_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLASS_ALREADY_EXISTS)));
	PyModule_AddObject(m, "WERR_CLASS_DOES_NOT_EXIST",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLASS_DOES_NOT_EXIST)));
	PyModule_AddObject(m, "WERR_CLASS_HAS_WINDOWS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLASS_HAS_WINDOWS)));
	PyModule_AddObject(m, "WERR_INVALID_INDEX",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_INDEX)));
	PyModule_AddObject(m, "WERR_INVALID_ICON_HANDLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_ICON_HANDLE)));
	PyModule_AddObject(m, "WERR_PRIVATE_DIALOG_INDEX",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PRIVATE_DIALOG_INDEX)));
	PyModule_AddObject(m, "WERR_LISTBOX_ID_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LISTBOX_ID_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_NO_WILDCARD_CHARACTERS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_WILDCARD_CHARACTERS)));
	PyModule_AddObject(m, "WERR_CLIPBOARD_NOT_OPEN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLIPBOARD_NOT_OPEN)));
	PyModule_AddObject(m, "WERR_HOTKEY_NOT_REGISTERED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_HOTKEY_NOT_REGISTERED)));
	PyModule_AddObject(m, "WERR_WINDOW_NOT_DIALOG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WINDOW_NOT_DIALOG)));
	PyModule_AddObject(m, "WERR_CONTROL_ID_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CONTROL_ID_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_INVALID_COMBOBOX_MESSAGE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_COMBOBOX_MESSAGE)));
	PyModule_AddObject(m, "WERR_WINDOW_NOT_COMBOBOX",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WINDOW_NOT_COMBOBOX)));
	PyModule_AddObject(m, "WERR_INVALID_EDIT_HEIGHT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_EDIT_HEIGHT)));
	PyModule_AddObject(m, "WERR_DC_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DC_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_INVALID_HOOK_FILTER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_HOOK_FILTER)));
	PyModule_AddObject(m, "WERR_INVALID_FILTER_PROC",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_FILTER_PROC)));
	PyModule_AddObject(m, "WERR_HOOK_NEEDS_HMOD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_HOOK_NEEDS_HMOD)));
	PyModule_AddObject(m, "WERR_GLOBAL_ONLY_HOOK",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_GLOBAL_ONLY_HOOK)));
	PyModule_AddObject(m, "WERR_JOURNAL_HOOK_SET",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_JOURNAL_HOOK_SET)));
	PyModule_AddObject(m, "WERR_HOOK_NOT_INSTALLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_HOOK_NOT_INSTALLED)));
	PyModule_AddObject(m, "WERR_INVALID_LB_MESSAGE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_LB_MESSAGE)));
	PyModule_AddObject(m, "WERR_SETCOUNT_ON_BAD_LB",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SETCOUNT_ON_BAD_LB)));
	PyModule_AddObject(m, "WERR_LB_WITHOUT_TABSTOPS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LB_WITHOUT_TABSTOPS)));
	PyModule_AddObject(m, "WERR_DESTROY_OBJECT_OF_OTHER_THREAD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DESTROY_OBJECT_OF_OTHER_THREAD)));
	PyModule_AddObject(m, "WERR_CHILD_WINDOW_MENU",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CHILD_WINDOW_MENU)));
	PyModule_AddObject(m, "WERR_NO_SYSTEM_MENU",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_SYSTEM_MENU)));
	PyModule_AddObject(m, "WERR_INVALID_MSGBOX_STYLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_MSGBOX_STYLE)));
	PyModule_AddObject(m, "WERR_INVALID_SPI_VALUE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_SPI_VALUE)));
	PyModule_AddObject(m, "WERR_SCREEN_ALREADY_LOCKED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SCREEN_ALREADY_LOCKED)));
	PyModule_AddObject(m, "WERR_HWNDS_HAVE_DIFF_PARENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_HWNDS_HAVE_DIFF_PARENT)));
	PyModule_AddObject(m, "WERR_NOT_CHILD_WINDOW",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_CHILD_WINDOW)));
	PyModule_AddObject(m, "WERR_INVALID_GW_COMMAND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_GW_COMMAND)));
	PyModule_AddObject(m, "WERR_INVALID_THREAD_ID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_THREAD_ID)));
	PyModule_AddObject(m, "WERR_NON_MDICHILD_WINDOW",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NON_MDICHILD_WINDOW)));
	PyModule_AddObject(m, "WERR_POPUP_ALREADY_ACTIVE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_POPUP_ALREADY_ACTIVE)));
	PyModule_AddObject(m, "WERR_NO_SCROLLBARS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_SCROLLBARS)));
	PyModule_AddObject(m, "WERR_INVALID_SCROLLBAR_RANGE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_SCROLLBAR_RANGE)));
	PyModule_AddObject(m, "WERR_INVALID_SHOWWIN_COMMAND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_SHOWWIN_COMMAND)));
	PyModule_AddObject(m, "WERR_NO_SYSTEM_RESOURCES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_SYSTEM_RESOURCES)));
	PyModule_AddObject(m, "WERR_NONPAGED_SYSTEM_RESOURCES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NONPAGED_SYSTEM_RESOURCES)));
	PyModule_AddObject(m, "WERR_PAGED_SYSTEM_RESOURCES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PAGED_SYSTEM_RESOURCES)));
	PyModule_AddObject(m, "WERR_WORKING_SET_QUOTA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WORKING_SET_QUOTA)));
	PyModule_AddObject(m, "WERR_PAGEFILE_QUOTA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PAGEFILE_QUOTA)));
	PyModule_AddObject(m, "WERR_COMMITMENT_LIMIT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_COMMITMENT_LIMIT)));
	PyModule_AddObject(m, "WERR_MENU_ITEM_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MENU_ITEM_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_INVALID_KEYBOARD_HANDLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_KEYBOARD_HANDLE)));
	PyModule_AddObject(m, "WERR_HOOK_TYPE_NOT_ALLOWED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_HOOK_TYPE_NOT_ALLOWED)));
	PyModule_AddObject(m, "WERR_REQUIRES_INTERACTIVE_WINDOWSTATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_REQUIRES_INTERACTIVE_WINDOWSTATION)));
	PyModule_AddObject(m, "WERR_TIMEOUT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TIMEOUT)));
	PyModule_AddObject(m, "WERR_INVALID_MONITOR_HANDLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_MONITOR_HANDLE)));
	PyModule_AddObject(m, "WERR_INCORRECT_SIZE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INCORRECT_SIZE)));
	PyModule_AddObject(m, "WERR_SYMLINK_CLASS_DISABLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SYMLINK_CLASS_DISABLED)));
	PyModule_AddObject(m, "WERR_SYMLINK_NOT_SUPPORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SYMLINK_NOT_SUPPORTED)));
	PyModule_AddObject(m, "WERR_EVENTLOG_FILE_CORRUPT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVENTLOG_FILE_CORRUPT)));
	PyModule_AddObject(m, "WERR_EVENTLOG_CANT_START",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVENTLOG_CANT_START)));
	PyModule_AddObject(m, "WERR_LOG_FILE_FULL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_FILE_FULL)));
	PyModule_AddObject(m, "WERR_EVENTLOG_FILE_CHANGED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVENTLOG_FILE_CHANGED)));
	PyModule_AddObject(m, "WERR_INVALID_TASK_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_TASK_NAME)));
	PyModule_AddObject(m, "WERR_INVALID_TASK_INDEX",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_TASK_INDEX)));
	PyModule_AddObject(m, "WERR_THREAD_ALREADY_IN_TASK",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_THREAD_ALREADY_IN_TASK)));
	PyModule_AddObject(m, "WERR_INSTALL_SERVICE_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INSTALL_SERVICE_FAILURE)));
	PyModule_AddObject(m, "WERR_INSTALL_USEREXIT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INSTALL_USEREXIT)));
	PyModule_AddObject(m, "WERR_INSTALL_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INSTALL_FAILURE)));
	PyModule_AddObject(m, "WERR_INSTALL_SUSPEND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INSTALL_SUSPEND)));
	PyModule_AddObject(m, "WERR_UNKNOWN_PRODUCT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNKNOWN_PRODUCT)));
	PyModule_AddObject(m, "WERR_UNKNOWN_FEATURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNKNOWN_FEATURE)));
	PyModule_AddObject(m, "WERR_UNKNOWN_COMPONENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNKNOWN_COMPONENT)));
	PyModule_AddObject(m, "WERR_UNKNOWN_PROPERTY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNKNOWN_PROPERTY)));
	PyModule_AddObject(m, "WERR_INVALID_HANDLE_STATE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_HANDLE_STATE)));
	PyModule_AddObject(m, "WERR_BAD_CONFIGURATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_CONFIGURATION)));
	PyModule_AddObject(m, "WERR_INDEX_ABSENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INDEX_ABSENT)));
	PyModule_AddObject(m, "WERR_INSTALL_SOURCE_ABSENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INSTALL_SOURCE_ABSENT)));
	PyModule_AddObject(m, "WERR_INSTALL_PACKAGE_VERSION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INSTALL_PACKAGE_VERSION)));
	PyModule_AddObject(m, "WERR_PRODUCT_UNINSTALLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PRODUCT_UNINSTALLED)));
	PyModule_AddObject(m, "WERR_BAD_QUERY_SYNTAX",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_QUERY_SYNTAX)));
	PyModule_AddObject(m, "WERR_INVALID_FIELD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_FIELD)));
	PyModule_AddObject(m, "WERR_DEVICE_REMOVED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DEVICE_REMOVED)));
	PyModule_AddObject(m, "WERR_INSTALL_ALREADY_RUNNING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INSTALL_ALREADY_RUNNING)));
	PyModule_AddObject(m, "WERR_INSTALL_PACKAGE_OPEN_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INSTALL_PACKAGE_OPEN_FAILED)));
	PyModule_AddObject(m, "WERR_INSTALL_PACKAGE_INVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INSTALL_PACKAGE_INVALID)));
	PyModule_AddObject(m, "WERR_INSTALL_UI_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INSTALL_UI_FAILURE)));
	PyModule_AddObject(m, "WERR_INSTALL_LOG_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INSTALL_LOG_FAILURE)));
	PyModule_AddObject(m, "WERR_INSTALL_LANGUAGE_UNSUPPORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INSTALL_LANGUAGE_UNSUPPORTED)));
	PyModule_AddObject(m, "WERR_INSTALL_TRANSFORM_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INSTALL_TRANSFORM_FAILURE)));
	PyModule_AddObject(m, "WERR_INSTALL_PACKAGE_REJECTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INSTALL_PACKAGE_REJECTED)));
	PyModule_AddObject(m, "WERR_FUNCTION_NOT_CALLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FUNCTION_NOT_CALLED)));
	PyModule_AddObject(m, "WERR_FUNCTION_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FUNCTION_FAILED)));
	PyModule_AddObject(m, "WERR_INVALID_TABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_TABLE)));
	PyModule_AddObject(m, "WERR_DATATYPE_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DATATYPE_MISMATCH)));
	PyModule_AddObject(m, "WERR_UNSUPPORTED_TYPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNSUPPORTED_TYPE)));
	PyModule_AddObject(m, "WERR_CREATE_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CREATE_FAILED)));
	PyModule_AddObject(m, "WERR_INSTALL_TEMP_UNWRITABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INSTALL_TEMP_UNWRITABLE)));
	PyModule_AddObject(m, "WERR_INSTALL_PLATFORM_UNSUPPORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INSTALL_PLATFORM_UNSUPPORTED)));
	PyModule_AddObject(m, "WERR_INSTALL_NOTUSED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INSTALL_NOTUSED)));
	PyModule_AddObject(m, "WERR_PATCH_PACKAGE_OPEN_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PATCH_PACKAGE_OPEN_FAILED)));
	PyModule_AddObject(m, "WERR_PATCH_PACKAGE_INVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PATCH_PACKAGE_INVALID)));
	PyModule_AddObject(m, "WERR_PATCH_PACKAGE_UNSUPPORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PATCH_PACKAGE_UNSUPPORTED)));
	PyModule_AddObject(m, "WERR_PRODUCT_VERSION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PRODUCT_VERSION)));
	PyModule_AddObject(m, "WERR_INVALID_COMMAND_LINE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_COMMAND_LINE)));
	PyModule_AddObject(m, "WERR_INSTALL_REMOTE_DISALLOWED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INSTALL_REMOTE_DISALLOWED)));
	PyModule_AddObject(m, "WERR_SUCCESS_REBOOT_INITIATED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SUCCESS_REBOOT_INITIATED)));
	PyModule_AddObject(m, "WERR_PATCH_TARGET_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PATCH_TARGET_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_PATCH_PACKAGE_REJECTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PATCH_PACKAGE_REJECTED)));
	PyModule_AddObject(m, "WERR_INSTALL_TRANSFORM_REJECTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INSTALL_TRANSFORM_REJECTED)));
	PyModule_AddObject(m, "WERR_INSTALL_REMOTE_PROHIBITED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INSTALL_REMOTE_PROHIBITED)));
	PyModule_AddObject(m, "WERR_PATCH_REMOVAL_UNSUPPORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PATCH_REMOVAL_UNSUPPORTED)));
	PyModule_AddObject(m, "WERR_UNKNOWN_PATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNKNOWN_PATCH)));
	PyModule_AddObject(m, "WERR_PATCH_NO_SEQUENCE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PATCH_NO_SEQUENCE)));
	PyModule_AddObject(m, "WERR_PATCH_REMOVAL_DISALLOWED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PATCH_REMOVAL_DISALLOWED)));
	PyModule_AddObject(m, "WERR_INVALID_PATCH_XML",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_PATCH_XML)));
	PyModule_AddObject(m, "WERR_PATCH_MANAGED_ADVERTISED_PRODUCT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PATCH_MANAGED_ADVERTISED_PRODUCT)));
	PyModule_AddObject(m, "WERR_INSTALL_SERVICE_SAFEBOOT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INSTALL_SERVICE_SAFEBOOT)));
	PyModule_AddObject(m, "WERR_RPC_S_INVALID_STRING_BINDING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_INVALID_STRING_BINDING)));
	PyModule_AddObject(m, "WERR_RPC_S_WRONG_KIND_OF_BINDING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_WRONG_KIND_OF_BINDING)));
	PyModule_AddObject(m, "WERR_RPC_S_INVALID_BINDING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_INVALID_BINDING)));
	PyModule_AddObject(m, "WERR_RPC_S_PROTSEQ_NOT_SUPPORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_PROTSEQ_NOT_SUPPORTED)));
	PyModule_AddObject(m, "WERR_RPC_S_INVALID_RPC_PROTSEQ",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_INVALID_RPC_PROTSEQ)));
	PyModule_AddObject(m, "WERR_RPC_S_INVALID_STRING_UUID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_INVALID_STRING_UUID)));
	PyModule_AddObject(m, "WERR_RPC_S_INVALID_ENDPOINT_FORMAT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_INVALID_ENDPOINT_FORMAT)));
	PyModule_AddObject(m, "WERR_RPC_S_INVALID_NET_ADDR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_INVALID_NET_ADDR)));
	PyModule_AddObject(m, "WERR_RPC_S_NO_ENDPOINT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_NO_ENDPOINT_FOUND)));
	PyModule_AddObject(m, "WERR_RPC_S_INVALID_TIMEOUT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_INVALID_TIMEOUT)));
	PyModule_AddObject(m, "WERR_RPC_S_OBJECT_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_OBJECT_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_RPC_S_ALREADY_REGISTERED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_ALREADY_REGISTERED)));
	PyModule_AddObject(m, "WERR_RPC_S_TYPE_ALREADY_REGISTERED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_TYPE_ALREADY_REGISTERED)));
	PyModule_AddObject(m, "WERR_RPC_S_ALREADY_LISTENING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_ALREADY_LISTENING)));
	PyModule_AddObject(m, "WERR_RPC_S_NO_PROTSEQS_REGISTERED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_NO_PROTSEQS_REGISTERED)));
	PyModule_AddObject(m, "WERR_RPC_S_NOT_LISTENING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_NOT_LISTENING)));
	PyModule_AddObject(m, "WERR_RPC_S_UNKNOWN_MGR_TYPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_UNKNOWN_MGR_TYPE)));
	PyModule_AddObject(m, "WERR_RPC_S_UNKNOWN_IF",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_UNKNOWN_IF)));
	PyModule_AddObject(m, "WERR_RPC_S_NO_BINDINGS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_NO_BINDINGS)));
	PyModule_AddObject(m, "WERR_RPC_S_NO_PROTSEQS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_NO_PROTSEQS)));
	PyModule_AddObject(m, "WERR_RPC_S_CANT_CREATE_ENDPOINT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_CANT_CREATE_ENDPOINT)));
	PyModule_AddObject(m, "WERR_RPC_S_OUT_OF_RESOURCES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_OUT_OF_RESOURCES)));
	PyModule_AddObject(m, "WERR_RPC_S_SERVER_UNAVAILABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_SERVER_UNAVAILABLE)));
	PyModule_AddObject(m, "WERR_RPC_S_SERVER_TOO_BUSY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_SERVER_TOO_BUSY)));
	PyModule_AddObject(m, "WERR_RPC_S_INVALID_NETWORK_OPTIONS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_INVALID_NETWORK_OPTIONS)));
	PyModule_AddObject(m, "WERR_RPC_S_NO_CALL_ACTIVE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_NO_CALL_ACTIVE)));
	PyModule_AddObject(m, "WERR_RPC_S_CALL_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_CALL_FAILED)));
	PyModule_AddObject(m, "WERR_RPC_S_CALL_FAILED_DNE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_CALL_FAILED_DNE)));
	PyModule_AddObject(m, "WERR_RPC_S_PROTOCOL_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_PROTOCOL_ERROR)));
	PyModule_AddObject(m, "WERR_RPC_S_PROXY_ACCESS_DENIED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_PROXY_ACCESS_DENIED)));
	PyModule_AddObject(m, "WERR_RPC_S_UNSUPPORTED_TRANS_SYN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_UNSUPPORTED_TRANS_SYN)));
	PyModule_AddObject(m, "WERR_RPC_S_UNSUPPORTED_TYPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_UNSUPPORTED_TYPE)));
	PyModule_AddObject(m, "WERR_RPC_S_INVALID_TAG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_INVALID_TAG)));
	PyModule_AddObject(m, "WERR_RPC_S_INVALID_BOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_INVALID_BOUND)));
	PyModule_AddObject(m, "WERR_RPC_S_NO_ENTRY_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_NO_ENTRY_NAME)));
	PyModule_AddObject(m, "WERR_RPC_S_INVALID_NAME_SYNTAX",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_INVALID_NAME_SYNTAX)));
	PyModule_AddObject(m, "WERR_RPC_S_UNSUPPORTED_NAME_SYNTAX",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_UNSUPPORTED_NAME_SYNTAX)));
	PyModule_AddObject(m, "WERR_RPC_S_UUID_NO_ADDRESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_UUID_NO_ADDRESS)));
	PyModule_AddObject(m, "WERR_RPC_S_DUPLICATE_ENDPOINT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_DUPLICATE_ENDPOINT)));
	PyModule_AddObject(m, "WERR_RPC_S_UNKNOWN_AUTHN_TYPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_UNKNOWN_AUTHN_TYPE)));
	PyModule_AddObject(m, "WERR_RPC_S_MAX_CALLS_TOO_SMALL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_MAX_CALLS_TOO_SMALL)));
	PyModule_AddObject(m, "WERR_RPC_S_STRING_TOO_LONG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_STRING_TOO_LONG)));
	PyModule_AddObject(m, "WERR_RPC_S_PROTSEQ_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_PROTSEQ_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_RPC_S_PROCNUM_OUT_OF_RANGE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_PROCNUM_OUT_OF_RANGE)));
	PyModule_AddObject(m, "WERR_RPC_S_BINDING_HAS_NO_AUTH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_BINDING_HAS_NO_AUTH)));
	PyModule_AddObject(m, "WERR_RPC_S_UNKNOWN_AUTHN_SERVICE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_UNKNOWN_AUTHN_SERVICE)));
	PyModule_AddObject(m, "WERR_RPC_S_UNKNOWN_AUTHN_LEVEL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_UNKNOWN_AUTHN_LEVEL)));
	PyModule_AddObject(m, "WERR_RPC_S_INVALID_AUTH_IDENTITY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_INVALID_AUTH_IDENTITY)));
	PyModule_AddObject(m, "WERR_RPC_S_UNKNOWN_AUTHZ_SERVICE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_UNKNOWN_AUTHZ_SERVICE)));
	PyModule_AddObject(m, "WERR_EPT_S_INVALID_ENTRY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EPT_S_INVALID_ENTRY)));
	PyModule_AddObject(m, "WERR_EPT_S_CANT_PERFORM_OP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EPT_S_CANT_PERFORM_OP)));
	PyModule_AddObject(m, "WERR_EPT_S_NOT_REGISTERED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EPT_S_NOT_REGISTERED)));
	PyModule_AddObject(m, "WERR_RPC_S_NOTHING_TO_EXPORT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_NOTHING_TO_EXPORT)));
	PyModule_AddObject(m, "WERR_RPC_S_INCOMPLETE_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_INCOMPLETE_NAME)));
	PyModule_AddObject(m, "WERR_RPC_S_INVALID_VERS_OPTION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_INVALID_VERS_OPTION)));
	PyModule_AddObject(m, "WERR_RPC_S_NO_MORE_MEMBERS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_NO_MORE_MEMBERS)));
	PyModule_AddObject(m, "WERR_RPC_S_NOT_ALL_OBJS_UNEXPORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_NOT_ALL_OBJS_UNEXPORTED)));
	PyModule_AddObject(m, "WERR_RPC_S_INTERFACE_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_INTERFACE_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_RPC_S_ENTRY_ALREADY_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_ENTRY_ALREADY_EXISTS)));
	PyModule_AddObject(m, "WERR_RPC_S_ENTRY_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_ENTRY_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_RPC_S_NAME_SERVICE_UNAVAILABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_NAME_SERVICE_UNAVAILABLE)));
	PyModule_AddObject(m, "WERR_RPC_S_INVALID_NAF_ID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_INVALID_NAF_ID)));
	PyModule_AddObject(m, "WERR_RPC_S_CANNOT_SUPPORT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_CANNOT_SUPPORT)));
	PyModule_AddObject(m, "WERR_RPC_S_NO_CONTEXT_AVAILABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_NO_CONTEXT_AVAILABLE)));
	PyModule_AddObject(m, "WERR_RPC_S_INTERNAL_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_INTERNAL_ERROR)));
	PyModule_AddObject(m, "WERR_RPC_S_ZERO_DIVIDE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_ZERO_DIVIDE)));
	PyModule_AddObject(m, "WERR_RPC_S_ADDRESS_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_ADDRESS_ERROR)));
	PyModule_AddObject(m, "WERR_RPC_S_FP_DIV_ZERO",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_FP_DIV_ZERO)));
	PyModule_AddObject(m, "WERR_RPC_S_FP_UNDERFLOW",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_FP_UNDERFLOW)));
	PyModule_AddObject(m, "WERR_RPC_S_FP_OVERFLOW",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_FP_OVERFLOW)));
	PyModule_AddObject(m, "WERR_RPC_X_NO_MORE_ENTRIES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_X_NO_MORE_ENTRIES)));
	PyModule_AddObject(m, "WERR_RPC_X_SS_CHAR_TRANS_OPEN_FAIL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_X_SS_CHAR_TRANS_OPEN_FAIL)));
	PyModule_AddObject(m, "WERR_RPC_X_SS_CHAR_TRANS_SHORT_FILE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_X_SS_CHAR_TRANS_SHORT_FILE)));
	PyModule_AddObject(m, "WERR_RPC_X_SS_IN_NULL_CONTEXT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_X_SS_IN_NULL_CONTEXT)));
	PyModule_AddObject(m, "WERR_RPC_X_SS_CONTEXT_DAMAGED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_X_SS_CONTEXT_DAMAGED)));
	PyModule_AddObject(m, "WERR_RPC_X_SS_HANDLES_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_X_SS_HANDLES_MISMATCH)));
	PyModule_AddObject(m, "WERR_RPC_X_SS_CANNOT_GET_CALL_HANDLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_X_SS_CANNOT_GET_CALL_HANDLE)));
	PyModule_AddObject(m, "WERR_RPC_X_NULL_REF_POINTER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_X_NULL_REF_POINTER)));
	PyModule_AddObject(m, "WERR_RPC_X_ENUM_VALUE_OUT_OF_RANGE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_X_ENUM_VALUE_OUT_OF_RANGE)));
	PyModule_AddObject(m, "WERR_RPC_X_BYTE_COUNT_TOO_SMALL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_X_BYTE_COUNT_TOO_SMALL)));
	PyModule_AddObject(m, "WERR_RPC_X_BAD_STUB_DATA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_X_BAD_STUB_DATA)));
	PyModule_AddObject(m, "WERR_INVALID_USER_BUFFER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_USER_BUFFER)));
	PyModule_AddObject(m, "WERR_UNRECOGNIZED_MEDIA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNRECOGNIZED_MEDIA)));
	PyModule_AddObject(m, "WERR_NO_TRUST_LSA_SECRET",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_TRUST_LSA_SECRET)));
	PyModule_AddObject(m, "WERR_NO_TRUST_SAM_ACCOUNT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_TRUST_SAM_ACCOUNT)));
	PyModule_AddObject(m, "WERR_TRUSTED_DOMAIN_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TRUSTED_DOMAIN_FAILURE)));
	PyModule_AddObject(m, "WERR_TRUSTED_RELATIONSHIP_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TRUSTED_RELATIONSHIP_FAILURE)));
	PyModule_AddObject(m, "WERR_TRUST_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TRUST_FAILURE)));
	PyModule_AddObject(m, "WERR_RPC_S_CALL_IN_PROGRESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_CALL_IN_PROGRESS)));
	PyModule_AddObject(m, "WERR_NETLOGON_NOT_STARTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NETLOGON_NOT_STARTED)));
	PyModule_AddObject(m, "WERR_ACCOUNT_EXPIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ACCOUNT_EXPIRED)));
	PyModule_AddObject(m, "WERR_REDIRECTOR_HAS_OPEN_HANDLES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_REDIRECTOR_HAS_OPEN_HANDLES)));
	PyModule_AddObject(m, "WERR_PRINTER_DRIVER_ALREADY_INSTALLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PRINTER_DRIVER_ALREADY_INSTALLED)));
	PyModule_AddObject(m, "WERR_UNKNOWN_PORT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNKNOWN_PORT)));
	PyModule_AddObject(m, "WERR_UNKNOWN_PRINTER_DRIVER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNKNOWN_PRINTER_DRIVER)));
	PyModule_AddObject(m, "WERR_UNKNOWN_PRINTPROCESSOR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNKNOWN_PRINTPROCESSOR)));
	PyModule_AddObject(m, "WERR_INVALID_SEPARATOR_FILE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_SEPARATOR_FILE)));
	PyModule_AddObject(m, "WERR_INVALID_PRIORITY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_PRIORITY)));
	PyModule_AddObject(m, "WERR_INVALID_PRINTER_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_PRINTER_NAME)));
	PyModule_AddObject(m, "WERR_PRINTER_ALREADY_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PRINTER_ALREADY_EXISTS)));
	PyModule_AddObject(m, "WERR_INVALID_PRINTER_COMMAND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_PRINTER_COMMAND)));
	PyModule_AddObject(m, "WERR_INVALID_DATATYPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_DATATYPE)));
	PyModule_AddObject(m, "WERR_INVALID_ENVIRONMENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_ENVIRONMENT)));
	PyModule_AddObject(m, "WERR_RPC_S_NO_MORE_BINDINGS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_NO_MORE_BINDINGS)));
	PyModule_AddObject(m, "WERR_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT)));
	PyModule_AddObject(m, "WERR_NOLOGON_WORKSTATION_TRUST_ACCOUNT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOLOGON_WORKSTATION_TRUST_ACCOUNT)));
	PyModule_AddObject(m, "WERR_NOLOGON_SERVER_TRUST_ACCOUNT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOLOGON_SERVER_TRUST_ACCOUNT)));
	PyModule_AddObject(m, "WERR_DOMAIN_TRUST_INCONSISTENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DOMAIN_TRUST_INCONSISTENT)));
	PyModule_AddObject(m, "WERR_SERVER_HAS_OPEN_HANDLES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SERVER_HAS_OPEN_HANDLES)));
	PyModule_AddObject(m, "WERR_RESOURCE_DATA_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RESOURCE_DATA_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_RESOURCE_TYPE_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RESOURCE_TYPE_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_RESOURCE_NAME_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RESOURCE_NAME_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_RESOURCE_LANG_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RESOURCE_LANG_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_NOT_ENOUGH_QUOTA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_ENOUGH_QUOTA)));
	PyModule_AddObject(m, "WERR_RPC_S_NO_INTERFACES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_NO_INTERFACES)));
	PyModule_AddObject(m, "WERR_RPC_S_CALL_CANCELLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_CALL_CANCELLED)));
	PyModule_AddObject(m, "WERR_RPC_S_BINDING_INCOMPLETE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_BINDING_INCOMPLETE)));
	PyModule_AddObject(m, "WERR_RPC_S_COMM_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_COMM_FAILURE)));
	PyModule_AddObject(m, "WERR_RPC_S_UNSUPPORTED_AUTHN_LEVEL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_UNSUPPORTED_AUTHN_LEVEL)));
	PyModule_AddObject(m, "WERR_RPC_S_NO_PRINC_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_NO_PRINC_NAME)));
	PyModule_AddObject(m, "WERR_RPC_S_NOT_RPC_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_NOT_RPC_ERROR)));
	PyModule_AddObject(m, "WERR_RPC_S_UUID_LOCAL_ONLY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_UUID_LOCAL_ONLY)));
	PyModule_AddObject(m, "WERR_RPC_S_SEC_PKG_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_SEC_PKG_ERROR)));
	PyModule_AddObject(m, "WERR_RPC_S_NOT_CANCELLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_NOT_CANCELLED)));
	PyModule_AddObject(m, "WERR_RPC_X_INVALID_ES_ACTION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_X_INVALID_ES_ACTION)));
	PyModule_AddObject(m, "WERR_RPC_X_WRONG_ES_VERSION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_X_WRONG_ES_VERSION)));
	PyModule_AddObject(m, "WERR_RPC_X_WRONG_STUB_VERSION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_X_WRONG_STUB_VERSION)));
	PyModule_AddObject(m, "WERR_RPC_X_INVALID_PIPE_OBJECT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_X_INVALID_PIPE_OBJECT)));
	PyModule_AddObject(m, "WERR_RPC_X_WRONG_PIPE_ORDER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_X_WRONG_PIPE_ORDER)));
	PyModule_AddObject(m, "WERR_RPC_X_WRONG_PIPE_VERSION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_X_WRONG_PIPE_VERSION)));
	PyModule_AddObject(m, "WERR_RPC_S_GROUP_MEMBER_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_GROUP_MEMBER_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_EPT_S_CANT_CREATE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EPT_S_CANT_CREATE)));
	PyModule_AddObject(m, "WERR_RPC_S_INVALID_OBJECT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_INVALID_OBJECT)));
	PyModule_AddObject(m, "WERR_INVALID_TIME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_TIME)));
	PyModule_AddObject(m, "WERR_INVALID_FORM_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_FORM_NAME)));
	PyModule_AddObject(m, "WERR_INVALID_FORM_SIZE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_FORM_SIZE)));
	PyModule_AddObject(m, "WERR_ALREADY_WAITING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ALREADY_WAITING)));
	PyModule_AddObject(m, "WERR_PRINTER_DELETED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PRINTER_DELETED)));
	PyModule_AddObject(m, "WERR_INVALID_PRINTER_STATE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_PRINTER_STATE)));
	PyModule_AddObject(m, "WERR_PASSWORD_MUST_CHANGE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PASSWORD_MUST_CHANGE)));
	PyModule_AddObject(m, "WERR_DOMAIN_CONTROLLER_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DOMAIN_CONTROLLER_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_ACCOUNT_LOCKED_OUT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ACCOUNT_LOCKED_OUT)));
	PyModule_AddObject(m, "WERR_OR_INVALID_OXID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_OR_INVALID_OXID)));
	PyModule_AddObject(m, "WERR_OR_INVALID_OID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_OR_INVALID_OID)));
	PyModule_AddObject(m, "WERR_OR_INVALID_SET",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_OR_INVALID_SET)));
	PyModule_AddObject(m, "WERR_RPC_S_SEND_INCOMPLETE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_SEND_INCOMPLETE)));
	PyModule_AddObject(m, "WERR_RPC_S_INVALID_ASYNC_HANDLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_INVALID_ASYNC_HANDLE)));
	PyModule_AddObject(m, "WERR_RPC_S_INVALID_ASYNC_CALL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_INVALID_ASYNC_CALL)));
	PyModule_AddObject(m, "WERR_RPC_X_PIPE_CLOSED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_X_PIPE_CLOSED)));
	PyModule_AddObject(m, "WERR_RPC_X_PIPE_DISCIPLINE_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_X_PIPE_DISCIPLINE_ERROR)));
	PyModule_AddObject(m, "WERR_RPC_X_PIPE_EMPTY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_X_PIPE_EMPTY)));
	PyModule_AddObject(m, "WERR_NO_SITENAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_SITENAME)));
	PyModule_AddObject(m, "WERR_CANT_ACCESS_FILE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANT_ACCESS_FILE)));
	PyModule_AddObject(m, "WERR_CANT_RESOLVE_FILENAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANT_RESOLVE_FILENAME)));
	PyModule_AddObject(m, "WERR_RPC_S_ENTRY_TYPE_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_ENTRY_TYPE_MISMATCH)));
	PyModule_AddObject(m, "WERR_RPC_S_NOT_ALL_OBJS_EXPORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_NOT_ALL_OBJS_EXPORTED)));
	PyModule_AddObject(m, "WERR_RPC_S_INTERFACE_NOT_EXPORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_INTERFACE_NOT_EXPORTED)));
	PyModule_AddObject(m, "WERR_RPC_S_PROFILE_NOT_ADDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_PROFILE_NOT_ADDED)));
	PyModule_AddObject(m, "WERR_RPC_S_PRF_ELT_NOT_ADDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_PRF_ELT_NOT_ADDED)));
	PyModule_AddObject(m, "WERR_RPC_S_PRF_ELT_NOT_REMOVED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_PRF_ELT_NOT_REMOVED)));
	PyModule_AddObject(m, "WERR_RPC_S_GRP_ELT_NOT_ADDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_GRP_ELT_NOT_ADDED)));
	PyModule_AddObject(m, "WERR_RPC_S_GRP_ELT_NOT_REMOVED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPC_S_GRP_ELT_NOT_REMOVED)));
	PyModule_AddObject(m, "WERR_KM_DRIVER_BLOCKED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_KM_DRIVER_BLOCKED)));
	PyModule_AddObject(m, "WERR_CONTEXT_EXPIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CONTEXT_EXPIRED)));
	PyModule_AddObject(m, "WERR_PER_USER_TRUST_QUOTA_EXCEEDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PER_USER_TRUST_QUOTA_EXCEEDED)));
	PyModule_AddObject(m, "WERR_ALL_USER_TRUST_QUOTA_EXCEEDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ALL_USER_TRUST_QUOTA_EXCEEDED)));
	PyModule_AddObject(m, "WERR_USER_DELETE_TRUST_QUOTA_EXCEEDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_USER_DELETE_TRUST_QUOTA_EXCEEDED)));
	PyModule_AddObject(m, "WERR_AUTHENTICATION_FIREWALL_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_AUTHENTICATION_FIREWALL_FAILED)));
	PyModule_AddObject(m, "WERR_REMOTE_PRINT_CONNECTIONS_BLOCKED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_REMOTE_PRINT_CONNECTIONS_BLOCKED)));
	PyModule_AddObject(m, "WERR_INVALID_PIXEL_FORMAT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_PIXEL_FORMAT)));
	PyModule_AddObject(m, "WERR_BAD_DRIVER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_DRIVER)));
	PyModule_AddObject(m, "WERR_INVALID_WINDOW_STYLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_WINDOW_STYLE)));
	PyModule_AddObject(m, "WERR_METAFILE_NOT_SUPPORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_METAFILE_NOT_SUPPORTED)));
	PyModule_AddObject(m, "WERR_TRANSFORM_NOT_SUPPORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TRANSFORM_NOT_SUPPORTED)));
	PyModule_AddObject(m, "WERR_CLIPPING_NOT_SUPPORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLIPPING_NOT_SUPPORTED)));
	PyModule_AddObject(m, "WERR_INVALID_CMM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_CMM)));
	PyModule_AddObject(m, "WERR_INVALID_PROFILE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_PROFILE)));
	PyModule_AddObject(m, "WERR_TAG_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TAG_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_TAG_NOT_PRESENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TAG_NOT_PRESENT)));
	PyModule_AddObject(m, "WERR_DUPLICATE_TAG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DUPLICATE_TAG)));
	PyModule_AddObject(m, "WERR_PROFILE_NOT_ASSOCIATED_WITH_DEVICE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PROFILE_NOT_ASSOCIATED_WITH_DEVICE)));
	PyModule_AddObject(m, "WERR_PROFILE_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PROFILE_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_INVALID_COLORSPACE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_COLORSPACE)));
	PyModule_AddObject(m, "WERR_ICM_NOT_ENABLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ICM_NOT_ENABLED)));
	PyModule_AddObject(m, "WERR_DELETING_ICM_XFORM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DELETING_ICM_XFORM)));
	PyModule_AddObject(m, "WERR_INVALID_TRANSFORM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_TRANSFORM)));
	PyModule_AddObject(m, "WERR_COLORSPACE_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_COLORSPACE_MISMATCH)));
	PyModule_AddObject(m, "WERR_INVALID_COLORINDEX",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_COLORINDEX)));
	PyModule_AddObject(m, "WERR_PROFILE_DOES_NOT_MATCH_DEVICE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PROFILE_DOES_NOT_MATCH_DEVICE)));
	PyModule_AddObject(m, "WERR_NERR_NETNOTSTARTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_NETNOTSTARTED)));
	PyModule_AddObject(m, "WERR_NERR_UNKNOWNSERVER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_UNKNOWNSERVER)));
	PyModule_AddObject(m, "WERR_NERR_SHAREMEM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_SHAREMEM)));
	PyModule_AddObject(m, "WERR_NERR_NONETWORKRESOURCE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_NONETWORKRESOURCE)));
	PyModule_AddObject(m, "WERR_NERR_REMOTEONLY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_REMOTEONLY)));
	PyModule_AddObject(m, "WERR_NERR_DEVNOTREDIRECTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DEVNOTREDIRECTED)));
	PyModule_AddObject(m, "WERR_CONNECTED_OTHER_PASSWORD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CONNECTED_OTHER_PASSWORD)));
	PyModule_AddObject(m, "WERR_CONNECTED_OTHER_PASSWORD_DEFAULT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CONNECTED_OTHER_PASSWORD_DEFAULT)));
	PyModule_AddObject(m, "WERR_NERR_SERVERNOTSTARTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_SERVERNOTSTARTED)));
	PyModule_AddObject(m, "WERR_NERR_ITEMNOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_ITEMNOTFOUND)));
	PyModule_AddObject(m, "WERR_NERR_UNKNOWNDEVDIR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_UNKNOWNDEVDIR)));
	PyModule_AddObject(m, "WERR_NERR_REDIRECTEDPATH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_REDIRECTEDPATH)));
	PyModule_AddObject(m, "WERR_NERR_DUPLICATESHARE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DUPLICATESHARE)));
	PyModule_AddObject(m, "WERR_NERR_NOROOM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_NOROOM)));
	PyModule_AddObject(m, "WERR_NERR_TOOMANYITEMS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_TOOMANYITEMS)));
	PyModule_AddObject(m, "WERR_NERR_INVALIDMAXUSERS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_INVALIDMAXUSERS)));
	PyModule_AddObject(m, "WERR_NERR_BUFTOOSMALL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_BUFTOOSMALL)));
	PyModule_AddObject(m, "WERR_NERR_REMOTEERR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_REMOTEERR)));
	PyModule_AddObject(m, "WERR_NERR_LANMANINIERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_LANMANINIERROR)));
	PyModule_AddObject(m, "WERR_NERR_NETWORKERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_NETWORKERROR)));
	PyModule_AddObject(m, "WERR_NERR_WKSTAINCONSISTENTSTATE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_WKSTAINCONSISTENTSTATE)));
	PyModule_AddObject(m, "WERR_NERR_WKSTANOTSTARTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_WKSTANOTSTARTED)));
	PyModule_AddObject(m, "WERR_NERR_BROWSERNOTSTARTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_BROWSERNOTSTARTED)));
	PyModule_AddObject(m, "WERR_NERR_INTERNALERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_INTERNALERROR)));
	PyModule_AddObject(m, "WERR_NERR_BADTRANSACTCONFIG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_BADTRANSACTCONFIG)));
	PyModule_AddObject(m, "WERR_NERR_INVALIDAPI",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_INVALIDAPI)));
	PyModule_AddObject(m, "WERR_NERR_BADEVENTNAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_BADEVENTNAME)));
	PyModule_AddObject(m, "WERR_NERR_DUPNAMEREBOOT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DUPNAMEREBOOT)));
	PyModule_AddObject(m, "WERR_NERR_CFGCOMPNOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_CFGCOMPNOTFOUND)));
	PyModule_AddObject(m, "WERR_NERR_CFGPARAMNOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_CFGPARAMNOTFOUND)));
	PyModule_AddObject(m, "WERR_NERR_LINETOOLONG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_LINETOOLONG)));
	PyModule_AddObject(m, "WERR_NERR_QNOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_QNOTFOUND)));
	PyModule_AddObject(m, "WERR_NERR_JOBNOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_JOBNOTFOUND)));
	PyModule_AddObject(m, "WERR_NERR_DESTNOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DESTNOTFOUND)));
	PyModule_AddObject(m, "WERR_NERR_DESTEXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DESTEXISTS)));
	PyModule_AddObject(m, "WERR_NERR_QEXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_QEXISTS)));
	PyModule_AddObject(m, "WERR_NERR_QNOROOM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_QNOROOM)));
	PyModule_AddObject(m, "WERR_NERR_JOBNOROOM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_JOBNOROOM)));
	PyModule_AddObject(m, "WERR_NERR_DESTNOROOM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DESTNOROOM)));
	PyModule_AddObject(m, "WERR_NERR_DESTIDLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DESTIDLE)));
	PyModule_AddObject(m, "WERR_NERR_DESTINVALIDOP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DESTINVALIDOP)));
	PyModule_AddObject(m, "WERR_NERR_PROCNORESPOND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_PROCNORESPOND)));
	PyModule_AddObject(m, "WERR_NERR_SPOOLERNOTLOADED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_SPOOLERNOTLOADED)));
	PyModule_AddObject(m, "WERR_NERR_DESTINVALIDSTATE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DESTINVALIDSTATE)));
	PyModule_AddObject(m, "WERR_NERR_QINVALIDSTATE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_QINVALIDSTATE)));
	PyModule_AddObject(m, "WERR_NERR_JOBINVALIDSTATE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_JOBINVALIDSTATE)));
	PyModule_AddObject(m, "WERR_NERR_SPOOLNOMEMORY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_SPOOLNOMEMORY)));
	PyModule_AddObject(m, "WERR_NERR_DRIVERNOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DRIVERNOTFOUND)));
	PyModule_AddObject(m, "WERR_NERR_DATATYPEINVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DATATYPEINVALID)));
	PyModule_AddObject(m, "WERR_NERR_PROCNOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_PROCNOTFOUND)));
	PyModule_AddObject(m, "WERR_NERR_SERVICETABLELOCKED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_SERVICETABLELOCKED)));
	PyModule_AddObject(m, "WERR_NERR_SERVICETABLEFULL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_SERVICETABLEFULL)));
	PyModule_AddObject(m, "WERR_NERR_SERVICEINSTALLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_SERVICEINSTALLED)));
	PyModule_AddObject(m, "WERR_NERR_SERVICEENTRYLOCKED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_SERVICEENTRYLOCKED)));
	PyModule_AddObject(m, "WERR_NERR_SERVICENOTINSTALLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_SERVICENOTINSTALLED)));
	PyModule_AddObject(m, "WERR_NERR_BADSERVICENAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_BADSERVICENAME)));
	PyModule_AddObject(m, "WERR_NERR_SERVICECTLTIMEOUT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_SERVICECTLTIMEOUT)));
	PyModule_AddObject(m, "WERR_NERR_SERVICECTLBUSY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_SERVICECTLBUSY)));
	PyModule_AddObject(m, "WERR_NERR_BADSERVICEPROGNAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_BADSERVICEPROGNAME)));
	PyModule_AddObject(m, "WERR_NERR_SERVICENOTCTRL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_SERVICENOTCTRL)));
	PyModule_AddObject(m, "WERR_NERR_SERVICEKILLPROC",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_SERVICEKILLPROC)));
	PyModule_AddObject(m, "WERR_NERR_SERVICECTLNOTVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_SERVICECTLNOTVALID)));
	PyModule_AddObject(m, "WERR_NERR_NOTINDISPATCHTBL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_NOTINDISPATCHTBL)));
	PyModule_AddObject(m, "WERR_NERR_BADCONTROLRECV",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_BADCONTROLRECV)));
	PyModule_AddObject(m, "WERR_NERR_SERVICENOTSTARTING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_SERVICENOTSTARTING)));
	PyModule_AddObject(m, "WERR_NERR_ALREADYLOGGEDON",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_ALREADYLOGGEDON)));
	PyModule_AddObject(m, "WERR_NERR_NOTLOGGEDON",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_NOTLOGGEDON)));
	PyModule_AddObject(m, "WERR_NERR_BADUSERNAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_BADUSERNAME)));
	PyModule_AddObject(m, "WERR_NERR_BADPASSWORD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_BADPASSWORD)));
	PyModule_AddObject(m, "WERR_NERR_UNABLETOADDNAME_W",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_UNABLETOADDNAME_W)));
	PyModule_AddObject(m, "WERR_NERR_UNABLETOADDNAME_F",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_UNABLETOADDNAME_F)));
	PyModule_AddObject(m, "WERR_NERR_UNABLETODELNAME_W",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_UNABLETODELNAME_W)));
	PyModule_AddObject(m, "WERR_NERR_UNABLETODELNAME_F",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_UNABLETODELNAME_F)));
	PyModule_AddObject(m, "WERR_NERR_LOGONSPAUSED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_LOGONSPAUSED)));
	PyModule_AddObject(m, "WERR_NERR_LOGONSERVERCONFLICT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_LOGONSERVERCONFLICT)));
	PyModule_AddObject(m, "WERR_NERR_LOGONNOUSERPATH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_LOGONNOUSERPATH)));
	PyModule_AddObject(m, "WERR_NERR_LOGONSCRIPTERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_LOGONSCRIPTERROR)));
	PyModule_AddObject(m, "WERR_NERR_STANDALONELOGON",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_STANDALONELOGON)));
	PyModule_AddObject(m, "WERR_NERR_LOGONSERVERNOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_LOGONSERVERNOTFOUND)));
	PyModule_AddObject(m, "WERR_NERR_LOGONDOMAINEXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_LOGONDOMAINEXISTS)));
	PyModule_AddObject(m, "WERR_NERR_NONVALIDATEDLOGON",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_NONVALIDATEDLOGON)));
	PyModule_AddObject(m, "WERR_NERR_ACFNOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_ACFNOTFOUND)));
	PyModule_AddObject(m, "WERR_NERR_GROUPNOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_GROUPNOTFOUND)));
	PyModule_AddObject(m, "WERR_NERR_USERNOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_USERNOTFOUND)));
	PyModule_AddObject(m, "WERR_NERR_RESOURCENOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RESOURCENOTFOUND)));
	PyModule_AddObject(m, "WERR_NERR_GROUPEXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_GROUPEXISTS)));
	PyModule_AddObject(m, "WERR_NERR_USEREXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_USEREXISTS)));
	PyModule_AddObject(m, "WERR_NERR_RESOURCEEXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RESOURCEEXISTS)));
	PyModule_AddObject(m, "WERR_NERR_NOTPRIMARY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_NOTPRIMARY)));
	PyModule_AddObject(m, "WERR_NERR_ACFNOTLOADED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_ACFNOTLOADED)));
	PyModule_AddObject(m, "WERR_NERR_ACFNOROOM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_ACFNOROOM)));
	PyModule_AddObject(m, "WERR_NERR_ACFFILEIOFAIL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_ACFFILEIOFAIL)));
	PyModule_AddObject(m, "WERR_NERR_ACFTOOMANYLISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_ACFTOOMANYLISTS)));
	PyModule_AddObject(m, "WERR_NERR_USERLOGON",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_USERLOGON)));
	PyModule_AddObject(m, "WERR_NERR_ACFNOPARENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_ACFNOPARENT)));
	PyModule_AddObject(m, "WERR_NERR_CANNOTGROWSEGMENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_CANNOTGROWSEGMENT)));
	PyModule_AddObject(m, "WERR_NERR_SPEGROUPOP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_SPEGROUPOP)));
	PyModule_AddObject(m, "WERR_NERR_NOTINCACHE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_NOTINCACHE)));
	PyModule_AddObject(m, "WERR_NERR_USERINGROUP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_USERINGROUP)));
	PyModule_AddObject(m, "WERR_NERR_USERNOTINGROUP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_USERNOTINGROUP)));
	PyModule_AddObject(m, "WERR_NERR_ACCOUNTUNDEFINED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_ACCOUNTUNDEFINED)));
	PyModule_AddObject(m, "WERR_NERR_ACCOUNTEXPIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_ACCOUNTEXPIRED)));
	PyModule_AddObject(m, "WERR_NERR_INVALIDWORKSTATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_INVALIDWORKSTATION)));
	PyModule_AddObject(m, "WERR_NERR_INVALIDLOGONHOURS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_INVALIDLOGONHOURS)));
	PyModule_AddObject(m, "WERR_NERR_PASSWORDEXPIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_PASSWORDEXPIRED)));
	PyModule_AddObject(m, "WERR_NERR_PASSWORDCANTCHANGE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_PASSWORDCANTCHANGE)));
	PyModule_AddObject(m, "WERR_NERR_PASSWORDHISTCONFLICT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_PASSWORDHISTCONFLICT)));
	PyModule_AddObject(m, "WERR_NERR_PASSWORDTOOSHORT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_PASSWORDTOOSHORT)));
	PyModule_AddObject(m, "WERR_NERR_PASSWORDTOORECENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_PASSWORDTOORECENT)));
	PyModule_AddObject(m, "WERR_NERR_INVALIDDATABASE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_INVALIDDATABASE)));
	PyModule_AddObject(m, "WERR_NERR_DATABASEUPTODATE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DATABASEUPTODATE)));
	PyModule_AddObject(m, "WERR_NERR_SYNCREQUIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_SYNCREQUIRED)));
	PyModule_AddObject(m, "WERR_NERR_USENOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_USENOTFOUND)));
	PyModule_AddObject(m, "WERR_NERR_BADASGTYPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_BADASGTYPE)));
	PyModule_AddObject(m, "WERR_NERR_DEVICEISSHARED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DEVICEISSHARED)));
	PyModule_AddObject(m, "WERR_NERR_NOCOMPUTERNAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_NOCOMPUTERNAME)));
	PyModule_AddObject(m, "WERR_NERR_MSGALREADYSTARTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_MSGALREADYSTARTED)));
	PyModule_AddObject(m, "WERR_NERR_MSGINITFAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_MSGINITFAILED)));
	PyModule_AddObject(m, "WERR_NERR_NAMENOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_NAMENOTFOUND)));
	PyModule_AddObject(m, "WERR_NERR_ALREADYFORWARDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_ALREADYFORWARDED)));
	PyModule_AddObject(m, "WERR_NERR_ADDFORWARDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_ADDFORWARDED)));
	PyModule_AddObject(m, "WERR_NERR_ALREADYEXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_ALREADYEXISTS)));
	PyModule_AddObject(m, "WERR_NERR_TOOMANYNAMES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_TOOMANYNAMES)));
	PyModule_AddObject(m, "WERR_NERR_DELCOMPUTERNAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DELCOMPUTERNAME)));
	PyModule_AddObject(m, "WERR_NERR_LOCALFORWARD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_LOCALFORWARD)));
	PyModule_AddObject(m, "WERR_NERR_GRPMSGPROCESSOR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_GRPMSGPROCESSOR)));
	PyModule_AddObject(m, "WERR_NERR_PAUSEDREMOTE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_PAUSEDREMOTE)));
	PyModule_AddObject(m, "WERR_NERR_BADRECEIVE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_BADRECEIVE)));
	PyModule_AddObject(m, "WERR_NERR_NAMEINUSE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_NAMEINUSE)));
	PyModule_AddObject(m, "WERR_NERR_MSGNOTSTARTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_MSGNOTSTARTED)));
	PyModule_AddObject(m, "WERR_NERR_NOTLOCALNAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_NOTLOCALNAME)));
	PyModule_AddObject(m, "WERR_NERR_NOFORWARDNAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_NOFORWARDNAME)));
	PyModule_AddObject(m, "WERR_NERR_REMOTEFULL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_REMOTEFULL)));
	PyModule_AddObject(m, "WERR_NERR_NAMENOTFORWARDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_NAMENOTFORWARDED)));
	PyModule_AddObject(m, "WERR_NERR_TRUNCATEDBROADCAST",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_TRUNCATEDBROADCAST)));
	PyModule_AddObject(m, "WERR_NERR_INVALIDDEVICE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_INVALIDDEVICE)));
	PyModule_AddObject(m, "WERR_NERR_WRITEFAULT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_WRITEFAULT)));
	PyModule_AddObject(m, "WERR_NERR_DUPLICATENAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DUPLICATENAME)));
	PyModule_AddObject(m, "WERR_NERR_DELETELATER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DELETELATER)));
	PyModule_AddObject(m, "WERR_NERR_INCOMPLETEDEL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_INCOMPLETEDEL)));
	PyModule_AddObject(m, "WERR_NERR_MULTIPLENETS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_MULTIPLENETS)));
	PyModule_AddObject(m, "WERR_NERR_NETNAMENOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_NETNAMENOTFOUND)));
	PyModule_AddObject(m, "WERR_NERR_DEVICENOTSHARED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DEVICENOTSHARED)));
	PyModule_AddObject(m, "WERR_NERR_CLIENTNAMENOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_CLIENTNAMENOTFOUND)));
	PyModule_AddObject(m, "WERR_NERR_FILEIDNOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_FILEIDNOTFOUND)));
	PyModule_AddObject(m, "WERR_NERR_EXECFAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_EXECFAILURE)));
	PyModule_AddObject(m, "WERR_NERR_TMPFILE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_TMPFILE)));
	PyModule_AddObject(m, "WERR_NERR_TOOMUCHDATA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_TOOMUCHDATA)));
	PyModule_AddObject(m, "WERR_NERR_DEVICESHARECONFLICT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DEVICESHARECONFLICT)));
	PyModule_AddObject(m, "WERR_NERR_BROWSERTABLEINCOMPLETE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_BROWSERTABLEINCOMPLETE)));
	PyModule_AddObject(m, "WERR_NERR_NOTLOCALDOMAIN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_NOTLOCALDOMAIN)));
	PyModule_AddObject(m, "WERR_NERR_ISDFSSHARE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_ISDFSSHARE)));
	PyModule_AddObject(m, "WERR_NERR_DEVINVALIDOPCODE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DEVINVALIDOPCODE)));
	PyModule_AddObject(m, "WERR_NERR_DEVNOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DEVNOTFOUND)));
	PyModule_AddObject(m, "WERR_NERR_DEVNOTOPEN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DEVNOTOPEN)));
	PyModule_AddObject(m, "WERR_NERR_BADQUEUEDEVSTRING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_BADQUEUEDEVSTRING)));
	PyModule_AddObject(m, "WERR_NERR_BADQUEUEPRIORITY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_BADQUEUEPRIORITY)));
	PyModule_AddObject(m, "WERR_NERR_NOCOMMDEVS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_NOCOMMDEVS)));
	PyModule_AddObject(m, "WERR_NERR_QUEUENOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_QUEUENOTFOUND)));
	PyModule_AddObject(m, "WERR_NERR_BADDEVSTRING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_BADDEVSTRING)));
	PyModule_AddObject(m, "WERR_NERR_BADDEV",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_BADDEV)));
	PyModule_AddObject(m, "WERR_NERR_INUSEBYSPOOLER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_INUSEBYSPOOLER)));
	PyModule_AddObject(m, "WERR_NERR_COMMDEVINUSE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_COMMDEVINUSE)));
	PyModule_AddObject(m, "WERR_NERR_INVALIDCOMPUTER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_INVALIDCOMPUTER)));
	PyModule_AddObject(m, "WERR_NERR_MAXLENEXCEEDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_MAXLENEXCEEDED)));
	PyModule_AddObject(m, "WERR_NERR_BADCOMPONENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_BADCOMPONENT)));
	PyModule_AddObject(m, "WERR_NERR_CANTTYPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_CANTTYPE)));
	PyModule_AddObject(m, "WERR_NERR_TOOMANYENTRIES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_TOOMANYENTRIES)));
	PyModule_AddObject(m, "WERR_NERR_PROFILEFILETOOBIG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_PROFILEFILETOOBIG)));
	PyModule_AddObject(m, "WERR_NERR_PROFILEOFFSET",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_PROFILEOFFSET)));
	PyModule_AddObject(m, "WERR_NERR_PROFILECLEANUP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_PROFILECLEANUP)));
	PyModule_AddObject(m, "WERR_NERR_PROFILEUNKNOWNCMD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_PROFILEUNKNOWNCMD)));
	PyModule_AddObject(m, "WERR_NERR_PROFILELOADERR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_PROFILELOADERR)));
	PyModule_AddObject(m, "WERR_NERR_PROFILESAVEERR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_PROFILESAVEERR)));
	PyModule_AddObject(m, "WERR_NERR_LOGOVERFLOW",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_LOGOVERFLOW)));
	PyModule_AddObject(m, "WERR_NERR_LOGFILECHANGED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_LOGFILECHANGED)));
	PyModule_AddObject(m, "WERR_NERR_LOGFILECORRUPT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_LOGFILECORRUPT)));
	PyModule_AddObject(m, "WERR_NERR_SOURCEISDIR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_SOURCEISDIR)));
	PyModule_AddObject(m, "WERR_NERR_BADSOURCE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_BADSOURCE)));
	PyModule_AddObject(m, "WERR_NERR_BADDEST",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_BADDEST)));
	PyModule_AddObject(m, "WERR_NERR_DIFFERENTSERVERS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DIFFERENTSERVERS)));
	PyModule_AddObject(m, "WERR_NERR_RUNSRVPAUSED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RUNSRVPAUSED)));
	PyModule_AddObject(m, "WERR_NERR_ERRCOMMRUNSRV",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_ERRCOMMRUNSRV)));
	PyModule_AddObject(m, "WERR_NERR_ERROREXECINGGHOST",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_ERROREXECINGGHOST)));
	PyModule_AddObject(m, "WERR_NERR_SHARENOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_SHARENOTFOUND)));
	PyModule_AddObject(m, "WERR_NERR_INVALIDLANA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_INVALIDLANA)));
	PyModule_AddObject(m, "WERR_NERR_OPENFILES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_OPENFILES)));
	PyModule_AddObject(m, "WERR_NERR_ACTIVECONNS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_ACTIVECONNS)));
	PyModule_AddObject(m, "WERR_NERR_BADPASSWORDCORE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_BADPASSWORDCORE)));
	PyModule_AddObject(m, "WERR_NERR_DEVINUSE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DEVINUSE)));
	PyModule_AddObject(m, "WERR_NERR_LOCALDRIVE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_LOCALDRIVE)));
	PyModule_AddObject(m, "WERR_NERR_ALERTEXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_ALERTEXISTS)));
	PyModule_AddObject(m, "WERR_NERR_TOOMANYALERTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_TOOMANYALERTS)));
	PyModule_AddObject(m, "WERR_NERR_NOSUCHALERT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_NOSUCHALERT)));
	PyModule_AddObject(m, "WERR_NERR_BADRECIPIENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_BADRECIPIENT)));
	PyModule_AddObject(m, "WERR_NERR_ACCTLIMITEXCEEDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_ACCTLIMITEXCEEDED)));
	PyModule_AddObject(m, "WERR_NERR_INVALIDLOGSEEK",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_INVALIDLOGSEEK)));
	PyModule_AddObject(m, "WERR_NERR_BADUASCONFIG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_BADUASCONFIG)));
	PyModule_AddObject(m, "WERR_NERR_INVALIDUASOP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_INVALIDUASOP)));
	PyModule_AddObject(m, "WERR_NERR_LASTADMIN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_LASTADMIN)));
	PyModule_AddObject(m, "WERR_NERR_DCNOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DCNOTFOUND)));
	PyModule_AddObject(m, "WERR_NERR_LOGONTRACKINGERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_LOGONTRACKINGERROR)));
	PyModule_AddObject(m, "WERR_NERR_NETLOGONNOTSTARTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_NETLOGONNOTSTARTED)));
	PyModule_AddObject(m, "WERR_NERR_CANNOTGROWUASFILE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_CANNOTGROWUASFILE)));
	PyModule_AddObject(m, "WERR_NERR_TIMEDIFFATDC",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_TIMEDIFFATDC)));
	PyModule_AddObject(m, "WERR_NERR_PASSWORDMISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_PASSWORDMISMATCH)));
	PyModule_AddObject(m, "WERR_NERR_NOSUCHSERVER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_NOSUCHSERVER)));
	PyModule_AddObject(m, "WERR_NERR_NOSUCHSESSION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_NOSUCHSESSION)));
	PyModule_AddObject(m, "WERR_NERR_NOSUCHCONNECTION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_NOSUCHCONNECTION)));
	PyModule_AddObject(m, "WERR_NERR_TOOMANYSERVERS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_TOOMANYSERVERS)));
	PyModule_AddObject(m, "WERR_NERR_TOOMANYSESSIONS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_TOOMANYSESSIONS)));
	PyModule_AddObject(m, "WERR_NERR_TOOMANYCONNECTIONS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_TOOMANYCONNECTIONS)));
	PyModule_AddObject(m, "WERR_NERR_TOOMANYFILES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_TOOMANYFILES)));
	PyModule_AddObject(m, "WERR_NERR_NOALTERNATESERVERS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_NOALTERNATESERVERS)));
	PyModule_AddObject(m, "WERR_NERR_TRYDOWNLEVEL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_TRYDOWNLEVEL)));
	PyModule_AddObject(m, "WERR_NERR_UPSDRIVERNOTSTARTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_UPSDRIVERNOTSTARTED)));
	PyModule_AddObject(m, "WERR_NERR_UPSINVALIDCONFIG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_UPSINVALIDCONFIG)));
	PyModule_AddObject(m, "WERR_NERR_UPSINVALIDCOMMPORT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_UPSINVALIDCOMMPORT)));
	PyModule_AddObject(m, "WERR_NERR_UPSSIGNALASSERTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_UPSSIGNALASSERTED)));
	PyModule_AddObject(m, "WERR_NERR_UPSSHUTDOWNFAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_UPSSHUTDOWNFAILED)));
	PyModule_AddObject(m, "WERR_NERR_BADDOSRETCODE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_BADDOSRETCODE)));
	PyModule_AddObject(m, "WERR_NERR_PROGNEEDSEXTRAMEM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_PROGNEEDSEXTRAMEM)));
	PyModule_AddObject(m, "WERR_NERR_BADDOSFUNCTION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_BADDOSFUNCTION)));
	PyModule_AddObject(m, "WERR_NERR_REMOTEBOOTFAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_REMOTEBOOTFAILED)));
	PyModule_AddObject(m, "WERR_NERR_BADFILECHECKSUM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_BADFILECHECKSUM)));
	PyModule_AddObject(m, "WERR_NERR_NORPLBOOTSYSTEM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_NORPLBOOTSYSTEM)));
	PyModule_AddObject(m, "WERR_NERR_RPLLOADRNETBIOSERR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLLOADRNETBIOSERR)));
	PyModule_AddObject(m, "WERR_NERR_RPLLOADRDISKERR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLLOADRDISKERR)));
	PyModule_AddObject(m, "WERR_NERR_IMAGEPARAMERR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_IMAGEPARAMERR)));
	PyModule_AddObject(m, "WERR_NERR_TOOMANYIMAGEPARAMS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_TOOMANYIMAGEPARAMS)));
	PyModule_AddObject(m, "WERR_NERR_NONDOSFLOPPYUSED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_NONDOSFLOPPYUSED)));
	PyModule_AddObject(m, "WERR_NERR_RPLBOOTRESTART",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLBOOTRESTART)));
	PyModule_AddObject(m, "WERR_NERR_RPLSRVRCALLFAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLSRVRCALLFAILED)));
	PyModule_AddObject(m, "WERR_NERR_CANTCONNECTRPLSRVR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_CANTCONNECTRPLSRVR)));
	PyModule_AddObject(m, "WERR_NERR_CANTOPENIMAGEFILE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_CANTOPENIMAGEFILE)));
	PyModule_AddObject(m, "WERR_NERR_CALLINGRPLSRVR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_CALLINGRPLSRVR)));
	PyModule_AddObject(m, "WERR_NERR_STARTINGRPLBOOT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_STARTINGRPLBOOT)));
	PyModule_AddObject(m, "WERR_NERR_RPLBOOTSERVICETERM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLBOOTSERVICETERM)));
	PyModule_AddObject(m, "WERR_NERR_RPLBOOTSTARTFAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLBOOTSTARTFAILED)));
	PyModule_AddObject(m, "WERR_NERR_RPL_CONNECTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPL_CONNECTED)));
	PyModule_AddObject(m, "WERR_NERR_BROWSERCONFIGUREDTONOTRUN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_BROWSERCONFIGUREDTONOTRUN)));
	PyModule_AddObject(m, "WERR_NERR_RPLNOADAPTERSSTARTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLNOADAPTERSSTARTED)));
	PyModule_AddObject(m, "WERR_NERR_RPLBADREGISTRY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLBADREGISTRY)));
	PyModule_AddObject(m, "WERR_NERR_RPLBADDATABASE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLBADDATABASE)));
	PyModule_AddObject(m, "WERR_NERR_RPLRPLFILESSHARE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLRPLFILESSHARE)));
	PyModule_AddObject(m, "WERR_NERR_RPLNOTRPLSERVER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLNOTRPLSERVER)));
	PyModule_AddObject(m, "WERR_NERR_RPLCANNOTENUM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLCANNOTENUM)));
	PyModule_AddObject(m, "WERR_NERR_RPLWKSTAINFOCORRUPTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLWKSTAINFOCORRUPTED)));
	PyModule_AddObject(m, "WERR_NERR_RPLWKSTANOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLWKSTANOTFOUND)));
	PyModule_AddObject(m, "WERR_NERR_RPLWKSTANAMEUNAVAILABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLWKSTANAMEUNAVAILABLE)));
	PyModule_AddObject(m, "WERR_NERR_RPLPROFILEINFOCORRUPTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLPROFILEINFOCORRUPTED)));
	PyModule_AddObject(m, "WERR_NERR_RPLPROFILENOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLPROFILENOTFOUND)));
	PyModule_AddObject(m, "WERR_NERR_RPLPROFILENAMEUNAVAILABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLPROFILENAMEUNAVAILABLE)));
	PyModule_AddObject(m, "WERR_NERR_RPLPROFILENOTEMPTY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLPROFILENOTEMPTY)));
	PyModule_AddObject(m, "WERR_NERR_RPLCONFIGINFOCORRUPTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLCONFIGINFOCORRUPTED)));
	PyModule_AddObject(m, "WERR_NERR_RPLCONFIGNOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLCONFIGNOTFOUND)));
	PyModule_AddObject(m, "WERR_NERR_RPLADAPTERINFOCORRUPTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLADAPTERINFOCORRUPTED)));
	PyModule_AddObject(m, "WERR_NERR_RPLINTERNAL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLINTERNAL)));
	PyModule_AddObject(m, "WERR_NERR_RPLVENDORINFOCORRUPTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLVENDORINFOCORRUPTED)));
	PyModule_AddObject(m, "WERR_NERR_RPLBOOTINFOCORRUPTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLBOOTINFOCORRUPTED)));
	PyModule_AddObject(m, "WERR_NERR_RPLWKSTANEEDSUSERACCT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLWKSTANEEDSUSERACCT)));
	PyModule_AddObject(m, "WERR_NERR_RPLNEEDSRPLUSERACCT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLNEEDSRPLUSERACCT)));
	PyModule_AddObject(m, "WERR_NERR_RPLBOOTNOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLBOOTNOTFOUND)));
	PyModule_AddObject(m, "WERR_NERR_RPLINCOMPATIBLEPROFILE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLINCOMPATIBLEPROFILE)));
	PyModule_AddObject(m, "WERR_NERR_RPLADAPTERNAMEUNAVAILABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLADAPTERNAMEUNAVAILABLE)));
	PyModule_AddObject(m, "WERR_NERR_RPLCONFIGNOTEMPTY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLCONFIGNOTEMPTY)));
	PyModule_AddObject(m, "WERR_NERR_RPLBOOTINUSE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLBOOTINUSE)));
	PyModule_AddObject(m, "WERR_NERR_RPLBACKUPDATABASE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLBACKUPDATABASE)));
	PyModule_AddObject(m, "WERR_NERR_RPLADAPTERNOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLADAPTERNOTFOUND)));
	PyModule_AddObject(m, "WERR_NERR_RPLVENDORNOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLVENDORNOTFOUND)));
	PyModule_AddObject(m, "WERR_NERR_RPLVENDORNAMEUNAVAILABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLVENDORNAMEUNAVAILABLE)));
	PyModule_AddObject(m, "WERR_NERR_RPLBOOTNAMEUNAVAILABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLBOOTNAMEUNAVAILABLE)));
	PyModule_AddObject(m, "WERR_NERR_RPLCONFIGNAMEUNAVAILABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_RPLCONFIGNAMEUNAVAILABLE)));
	PyModule_AddObject(m, "WERR_NERR_DFSINTERNALCORRUPTION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DFSINTERNALCORRUPTION)));
	PyModule_AddObject(m, "WERR_NERR_DFSVOLUMEDATACORRUPT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DFSVOLUMEDATACORRUPT)));
	PyModule_AddObject(m, "WERR_NERR_DFSNOSUCHVOLUME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DFSNOSUCHVOLUME)));
	PyModule_AddObject(m, "WERR_NERR_DFSVOLUMEALREADYEXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DFSVOLUMEALREADYEXISTS)));
	PyModule_AddObject(m, "WERR_NERR_DFSALREADYSHARED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DFSALREADYSHARED)));
	PyModule_AddObject(m, "WERR_NERR_DFSNOSUCHSHARE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DFSNOSUCHSHARE)));
	PyModule_AddObject(m, "WERR_NERR_DFSNOTALEAFVOLUME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DFSNOTALEAFVOLUME)));
	PyModule_AddObject(m, "WERR_NERR_DFSLEAFVOLUME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DFSLEAFVOLUME)));
	PyModule_AddObject(m, "WERR_NERR_DFSVOLUMEHASMULTIPLESERVERS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DFSVOLUMEHASMULTIPLESERVERS)));
	PyModule_AddObject(m, "WERR_NERR_DFSCANTCREATEJUNCTIONPOINT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DFSCANTCREATEJUNCTIONPOINT)));
	PyModule_AddObject(m, "WERR_NERR_DFSSERVERNOTDFSAWARE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DFSSERVERNOTDFSAWARE)));
	PyModule_AddObject(m, "WERR_NERR_DFSBADRENAMEPATH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DFSBADRENAMEPATH)));
	PyModule_AddObject(m, "WERR_NERR_DFSVOLUMEISOFFLINE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DFSVOLUMEISOFFLINE)));
	PyModule_AddObject(m, "WERR_NERR_DFSNOSUCHSERVER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DFSNOSUCHSERVER)));
	PyModule_AddObject(m, "WERR_NERR_DFSCYCLICALNAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DFSCYCLICALNAME)));
	PyModule_AddObject(m, "WERR_NERR_DFSNOTSUPPORTEDINSERVERDFS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DFSNOTSUPPORTEDINSERVERDFS)));
	PyModule_AddObject(m, "WERR_NERR_DFSDUPLICATESERVICE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DFSDUPLICATESERVICE)));
	PyModule_AddObject(m, "WERR_NERR_DFSCANTREMOVELASTSERVERSHARE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DFSCANTREMOVELASTSERVERSHARE)));
	PyModule_AddObject(m, "WERR_NERR_DFSVOLUMEISINTERDFS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DFSVOLUMEISINTERDFS)));
	PyModule_AddObject(m, "WERR_NERR_DFSINCONSISTENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DFSINCONSISTENT)));
	PyModule_AddObject(m, "WERR_NERR_DFSSERVERUPGRADED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DFSSERVERUPGRADED)));
	PyModule_AddObject(m, "WERR_NERR_DFSDATAISIDENTICAL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DFSDATAISIDENTICAL)));
	PyModule_AddObject(m, "WERR_NERR_DFSCANTREMOVEDFSROOT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DFSCANTREMOVEDFSROOT)));
	PyModule_AddObject(m, "WERR_NERR_DFSCHILDORPARENTINDFS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DFSCHILDORPARENTINDFS)));
	PyModule_AddObject(m, "WERR_NERR_DFSINTERNALERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DFSINTERNALERROR)));
	PyModule_AddObject(m, "WERR_NERR_SETUPALREADYJOINED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_SETUPALREADYJOINED)));
	PyModule_AddObject(m, "WERR_NERR_SETUPNOTJOINED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_SETUPNOTJOINED)));
	PyModule_AddObject(m, "WERR_NERR_SETUPDOMAINCONTROLLER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_SETUPDOMAINCONTROLLER)));
	PyModule_AddObject(m, "WERR_NERR_DEFAULTJOINREQUIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_DEFAULTJOINREQUIRED)));
	PyModule_AddObject(m, "WERR_NERR_INVALIDWORKGROUPNAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_INVALIDWORKGROUPNAME)));
	PyModule_AddObject(m, "WERR_NERR_NAMEUSESINCOMPATIBLECODEPAGE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_NAMEUSESINCOMPATIBLECODEPAGE)));
	PyModule_AddObject(m, "WERR_NERR_COMPUTERACCOUNTNOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_COMPUTERACCOUNTNOTFOUND)));
	PyModule_AddObject(m, "WERR_NERR_PERSONALSKU",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_PERSONALSKU)));
	PyModule_AddObject(m, "WERR_NERR_PASSWORDMUSTCHANGE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_PASSWORDMUSTCHANGE)));
	PyModule_AddObject(m, "WERR_NERR_ACCOUNTLOCKEDOUT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_ACCOUNTLOCKEDOUT)));
	PyModule_AddObject(m, "WERR_NERR_PASSWORDTOOLONG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_PASSWORDTOOLONG)));
	PyModule_AddObject(m, "WERR_NERR_PASSWORDNOTCOMPLEXENOUGH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_PASSWORDNOTCOMPLEXENOUGH)));
	PyModule_AddObject(m, "WERR_NERR_PASSWORDFILTERERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NERR_PASSWORDFILTERERROR)));
	PyModule_AddObject(m, "WERR_UNKNOWN_PRINT_MONITOR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNKNOWN_PRINT_MONITOR)));
	PyModule_AddObject(m, "WERR_PRINTER_DRIVER_IN_USE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PRINTER_DRIVER_IN_USE)));
	PyModule_AddObject(m, "WERR_SPOOL_FILE_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SPOOL_FILE_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_SPL_NO_STARTDOC",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SPL_NO_STARTDOC)));
	PyModule_AddObject(m, "WERR_SPL_NO_ADDJOB",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SPL_NO_ADDJOB)));
	PyModule_AddObject(m, "WERR_PRINT_PROCESSOR_ALREADY_INSTALLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PRINT_PROCESSOR_ALREADY_INSTALLED)));
	PyModule_AddObject(m, "WERR_PRINT_MONITOR_ALREADY_INSTALLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PRINT_MONITOR_ALREADY_INSTALLED)));
	PyModule_AddObject(m, "WERR_INVALID_PRINT_MONITOR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_PRINT_MONITOR)));
	PyModule_AddObject(m, "WERR_PRINT_MONITOR_IN_USE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PRINT_MONITOR_IN_USE)));
	PyModule_AddObject(m, "WERR_PRINTER_HAS_JOBS_QUEUED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PRINTER_HAS_JOBS_QUEUED)));
	PyModule_AddObject(m, "WERR_SUCCESS_REBOOT_REQUIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SUCCESS_REBOOT_REQUIRED)));
	PyModule_AddObject(m, "WERR_SUCCESS_RESTART_REQUIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SUCCESS_RESTART_REQUIRED)));
	PyModule_AddObject(m, "WERR_PRINTER_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PRINTER_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_PRINTER_DRIVER_WARNED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PRINTER_DRIVER_WARNED)));
	PyModule_AddObject(m, "WERR_PRINTER_DRIVER_BLOCKED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PRINTER_DRIVER_BLOCKED)));
	PyModule_AddObject(m, "WERR_PRINTER_DRIVER_PACKAGE_IN_USE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PRINTER_DRIVER_PACKAGE_IN_USE)));
	PyModule_AddObject(m, "WERR_CORE_DRIVER_PACKAGE_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CORE_DRIVER_PACKAGE_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_FAIL_REBOOT_REQUIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FAIL_REBOOT_REQUIRED)));
	PyModule_AddObject(m, "WERR_FAIL_REBOOT_INITIATED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FAIL_REBOOT_INITIATED)));
	PyModule_AddObject(m, "WERR_PRINTER_DRIVER_DOWNLOAD_NEEDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PRINTER_DRIVER_DOWNLOAD_NEEDED)));
	PyModule_AddObject(m, "WERR_IO_REISSUE_AS_CACHED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IO_REISSUE_AS_CACHED)));
	PyModule_AddObject(m, "WERR_WINS_INTERNAL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WINS_INTERNAL)));
	PyModule_AddObject(m, "WERR_CAN_NOT_DEL_LOCAL_WINS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CAN_NOT_DEL_LOCAL_WINS)));
	PyModule_AddObject(m, "WERR_STATIC_INIT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_STATIC_INIT)));
	PyModule_AddObject(m, "WERR_INC_BACKUP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INC_BACKUP)));
	PyModule_AddObject(m, "WERR_FULL_BACKUP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FULL_BACKUP)));
	PyModule_AddObject(m, "WERR_REC_NON_EXISTENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_REC_NON_EXISTENT)));
	PyModule_AddObject(m, "WERR_RPL_NOT_ALLOWED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RPL_NOT_ALLOWED)));
	PyModule_AddObject(m, "WERR_PEERDIST_ERROR_CONTENTINFO_VERSION_UNSUPPORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PEERDIST_ERROR_CONTENTINFO_VERSION_UNSUPPORTED)));
	PyModule_AddObject(m, "WERR_PEERDIST_ERROR_CANNOT_PARSE_CONTENTINFO",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PEERDIST_ERROR_CANNOT_PARSE_CONTENTINFO)));
	PyModule_AddObject(m, "WERR_PEERDIST_ERROR_MISSING_DATA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PEERDIST_ERROR_MISSING_DATA)));
	PyModule_AddObject(m, "WERR_PEERDIST_ERROR_NO_MORE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PEERDIST_ERROR_NO_MORE)));
	PyModule_AddObject(m, "WERR_PEERDIST_ERROR_NOT_INITIALIZED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PEERDIST_ERROR_NOT_INITIALIZED)));
	PyModule_AddObject(m, "WERR_PEERDIST_ERROR_ALREADY_INITIALIZED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PEERDIST_ERROR_ALREADY_INITIALIZED)));
	PyModule_AddObject(m, "WERR_PEERDIST_ERROR_SHUTDOWN_IN_PROGRESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PEERDIST_ERROR_SHUTDOWN_IN_PROGRESS)));
	PyModule_AddObject(m, "WERR_PEERDIST_ERROR_INVALIDATED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PEERDIST_ERROR_INVALIDATED)));
	PyModule_AddObject(m, "WERR_PEERDIST_ERROR_ALREADY_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PEERDIST_ERROR_ALREADY_EXISTS)));
	PyModule_AddObject(m, "WERR_PEERDIST_ERROR_OPERATION_NOTFOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PEERDIST_ERROR_OPERATION_NOTFOUND)));
	PyModule_AddObject(m, "WERR_PEERDIST_ERROR_ALREADY_COMPLETED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PEERDIST_ERROR_ALREADY_COMPLETED)));
	PyModule_AddObject(m, "WERR_PEERDIST_ERROR_OUT_OF_BOUNDS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PEERDIST_ERROR_OUT_OF_BOUNDS)));
	PyModule_AddObject(m, "WERR_PEERDIST_ERROR_VERSION_UNSUPPORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PEERDIST_ERROR_VERSION_UNSUPPORTED)));
	PyModule_AddObject(m, "WERR_PEERDIST_ERROR_INVALID_CONFIGURATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PEERDIST_ERROR_INVALID_CONFIGURATION)));
	PyModule_AddObject(m, "WERR_PEERDIST_ERROR_NOT_LICENSED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PEERDIST_ERROR_NOT_LICENSED)));
	PyModule_AddObject(m, "WERR_PEERDIST_ERROR_SERVICE_UNAVAILABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PEERDIST_ERROR_SERVICE_UNAVAILABLE)));
	PyModule_AddObject(m, "WERR_DHCP_ADDRESS_CONFLICT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DHCP_ADDRESS_CONFLICT)));
	PyModule_AddObject(m, "WERR_WMI_GUID_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WMI_GUID_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_WMI_INSTANCE_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WMI_INSTANCE_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_WMI_ITEMID_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WMI_ITEMID_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_WMI_TRY_AGAIN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WMI_TRY_AGAIN)));
	PyModule_AddObject(m, "WERR_WMI_DP_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WMI_DP_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_WMI_UNRESOLVED_INSTANCE_REF",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WMI_UNRESOLVED_INSTANCE_REF)));
	PyModule_AddObject(m, "WERR_WMI_ALREADY_ENABLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WMI_ALREADY_ENABLED)));
	PyModule_AddObject(m, "WERR_WMI_GUID_DISCONNECTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WMI_GUID_DISCONNECTED)));
	PyModule_AddObject(m, "WERR_WMI_SERVER_UNAVAILABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WMI_SERVER_UNAVAILABLE)));
	PyModule_AddObject(m, "WERR_WMI_DP_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WMI_DP_FAILED)));
	PyModule_AddObject(m, "WERR_WMI_INVALID_MOF",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WMI_INVALID_MOF)));
	PyModule_AddObject(m, "WERR_WMI_INVALID_REGINFO",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WMI_INVALID_REGINFO)));
	PyModule_AddObject(m, "WERR_WMI_ALREADY_DISABLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WMI_ALREADY_DISABLED)));
	PyModule_AddObject(m, "WERR_WMI_READ_ONLY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WMI_READ_ONLY)));
	PyModule_AddObject(m, "WERR_WMI_SET_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WMI_SET_FAILURE)));
	PyModule_AddObject(m, "WERR_INVALID_MEDIA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_MEDIA)));
	PyModule_AddObject(m, "WERR_INVALID_LIBRARY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_LIBRARY)));
	PyModule_AddObject(m, "WERR_INVALID_MEDIA_POOL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_MEDIA_POOL)));
	PyModule_AddObject(m, "WERR_DRIVE_MEDIA_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DRIVE_MEDIA_MISMATCH)));
	PyModule_AddObject(m, "WERR_MEDIA_OFFLINE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MEDIA_OFFLINE)));
	PyModule_AddObject(m, "WERR_LIBRARY_OFFLINE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LIBRARY_OFFLINE)));
	PyModule_AddObject(m, "WERR_EMPTY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EMPTY)));
	PyModule_AddObject(m, "WERR_NOT_EMPTY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_EMPTY)));
	PyModule_AddObject(m, "WERR_MEDIA_UNAVAILABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MEDIA_UNAVAILABLE)));
	PyModule_AddObject(m, "WERR_RESOURCE_DISABLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RESOURCE_DISABLED)));
	PyModule_AddObject(m, "WERR_INVALID_CLEANER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_CLEANER)));
	PyModule_AddObject(m, "WERR_UNABLE_TO_CLEAN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNABLE_TO_CLEAN)));
	PyModule_AddObject(m, "WERR_OBJECT_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_OBJECT_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_DATABASE_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DATABASE_FAILURE)));
	PyModule_AddObject(m, "WERR_DATABASE_FULL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DATABASE_FULL)));
	PyModule_AddObject(m, "WERR_MEDIA_INCOMPATIBLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MEDIA_INCOMPATIBLE)));
	PyModule_AddObject(m, "WERR_RESOURCE_NOT_PRESENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RESOURCE_NOT_PRESENT)));
	PyModule_AddObject(m, "WERR_INVALID_OPERATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_OPERATION)));
	PyModule_AddObject(m, "WERR_MEDIA_NOT_AVAILABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MEDIA_NOT_AVAILABLE)));
	PyModule_AddObject(m, "WERR_DEVICE_NOT_AVAILABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DEVICE_NOT_AVAILABLE)));
	PyModule_AddObject(m, "WERR_REQUEST_REFUSED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_REQUEST_REFUSED)));
	PyModule_AddObject(m, "WERR_INVALID_DRIVE_OBJECT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_DRIVE_OBJECT)));
	PyModule_AddObject(m, "WERR_LIBRARY_FULL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LIBRARY_FULL)));
	PyModule_AddObject(m, "WERR_MEDIUM_NOT_ACCESSIBLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MEDIUM_NOT_ACCESSIBLE)));
	PyModule_AddObject(m, "WERR_UNABLE_TO_LOAD_MEDIUM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNABLE_TO_LOAD_MEDIUM)));
	PyModule_AddObject(m, "WERR_UNABLE_TO_INVENTORY_DRIVE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNABLE_TO_INVENTORY_DRIVE)));
	PyModule_AddObject(m, "WERR_UNABLE_TO_INVENTORY_SLOT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNABLE_TO_INVENTORY_SLOT)));
	PyModule_AddObject(m, "WERR_UNABLE_TO_INVENTORY_TRANSPORT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNABLE_TO_INVENTORY_TRANSPORT)));
	PyModule_AddObject(m, "WERR_TRANSPORT_FULL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TRANSPORT_FULL)));
	PyModule_AddObject(m, "WERR_CONTROLLING_IEPORT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CONTROLLING_IEPORT)));
	PyModule_AddObject(m, "WERR_UNABLE_TO_EJECT_MOUNTED_MEDIA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNABLE_TO_EJECT_MOUNTED_MEDIA)));
	PyModule_AddObject(m, "WERR_CLEANER_SLOT_SET",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLEANER_SLOT_SET)));
	PyModule_AddObject(m, "WERR_CLEANER_SLOT_NOT_SET",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLEANER_SLOT_NOT_SET)));
	PyModule_AddObject(m, "WERR_CLEANER_CARTRIDGE_SPENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLEANER_CARTRIDGE_SPENT)));
	PyModule_AddObject(m, "WERR_UNEXPECTED_OMID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNEXPECTED_OMID)));
	PyModule_AddObject(m, "WERR_CANT_DELETE_LAST_ITEM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANT_DELETE_LAST_ITEM)));
	PyModule_AddObject(m, "WERR_MESSAGE_EXCEEDS_MAX_SIZE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MESSAGE_EXCEEDS_MAX_SIZE)));
	PyModule_AddObject(m, "WERR_VOLUME_CONTAINS_SYS_FILES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_VOLUME_CONTAINS_SYS_FILES)));
	PyModule_AddObject(m, "WERR_INDIGENOUS_TYPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INDIGENOUS_TYPE)));
	PyModule_AddObject(m, "WERR_NO_SUPPORTING_DRIVES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_SUPPORTING_DRIVES)));
	PyModule_AddObject(m, "WERR_CLEANER_CARTRIDGE_INSTALLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLEANER_CARTRIDGE_INSTALLED)));
	PyModule_AddObject(m, "WERR_IEPORT_FULL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IEPORT_FULL)));
	PyModule_AddObject(m, "WERR_FILE_OFFLINE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FILE_OFFLINE)));
	PyModule_AddObject(m, "WERR_REMOTE_STORAGE_NOT_ACTIVE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_REMOTE_STORAGE_NOT_ACTIVE)));
	PyModule_AddObject(m, "WERR_REMOTE_STORAGE_MEDIA_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_REMOTE_STORAGE_MEDIA_ERROR)));
	PyModule_AddObject(m, "WERR_NOT_A_REPARSE_POINT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_A_REPARSE_POINT)));
	PyModule_AddObject(m, "WERR_REPARSE_ATTRIBUTE_CONFLICT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_REPARSE_ATTRIBUTE_CONFLICT)));
	PyModule_AddObject(m, "WERR_INVALID_REPARSE_DATA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_REPARSE_DATA)));
	PyModule_AddObject(m, "WERR_REPARSE_TAG_INVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_REPARSE_TAG_INVALID)));
	PyModule_AddObject(m, "WERR_REPARSE_TAG_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_REPARSE_TAG_MISMATCH)));
	PyModule_AddObject(m, "WERR_VOLUME_NOT_SIS_ENABLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_VOLUME_NOT_SIS_ENABLED)));
	PyModule_AddObject(m, "WERR_DEPENDENT_RESOURCE_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DEPENDENT_RESOURCE_EXISTS)));
	PyModule_AddObject(m, "WERR_DEPENDENCY_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DEPENDENCY_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_DEPENDENCY_ALREADY_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DEPENDENCY_ALREADY_EXISTS)));
	PyModule_AddObject(m, "WERR_RESOURCE_NOT_ONLINE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RESOURCE_NOT_ONLINE)));
	PyModule_AddObject(m, "WERR_HOST_NODE_NOT_AVAILABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_HOST_NODE_NOT_AVAILABLE)));
	PyModule_AddObject(m, "WERR_RESOURCE_NOT_AVAILABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RESOURCE_NOT_AVAILABLE)));
	PyModule_AddObject(m, "WERR_RESOURCE_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RESOURCE_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_SHUTDOWN_CLUSTER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SHUTDOWN_CLUSTER)));
	PyModule_AddObject(m, "WERR_CANT_EVICT_ACTIVE_NODE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANT_EVICT_ACTIVE_NODE)));
	PyModule_AddObject(m, "WERR_OBJECT_ALREADY_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_OBJECT_ALREADY_EXISTS)));
	PyModule_AddObject(m, "WERR_OBJECT_IN_LIST",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_OBJECT_IN_LIST)));
	PyModule_AddObject(m, "WERR_GROUP_NOT_AVAILABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_GROUP_NOT_AVAILABLE)));
	PyModule_AddObject(m, "WERR_GROUP_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_GROUP_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_GROUP_NOT_ONLINE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_GROUP_NOT_ONLINE)));
	PyModule_AddObject(m, "WERR_HOST_NODE_NOT_RESOURCE_OWNER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_HOST_NODE_NOT_RESOURCE_OWNER)));
	PyModule_AddObject(m, "WERR_HOST_NODE_NOT_GROUP_OWNER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_HOST_NODE_NOT_GROUP_OWNER)));
	PyModule_AddObject(m, "WERR_RESMON_CREATE_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RESMON_CREATE_FAILED)));
	PyModule_AddObject(m, "WERR_RESMON_ONLINE_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RESMON_ONLINE_FAILED)));
	PyModule_AddObject(m, "WERR_RESOURCE_ONLINE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RESOURCE_ONLINE)));
	PyModule_AddObject(m, "WERR_QUORUM_RESOURCE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_QUORUM_RESOURCE)));
	PyModule_AddObject(m, "WERR_NOT_QUORUM_CAPABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_QUORUM_CAPABLE)));
	PyModule_AddObject(m, "WERR_CLUSTER_SHUTTING_DOWN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_SHUTTING_DOWN)));
	PyModule_AddObject(m, "WERR_INVALID_STATE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_STATE)));
	PyModule_AddObject(m, "WERR_RESOURCE_PROPERTIES_STORED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RESOURCE_PROPERTIES_STORED)));
	PyModule_AddObject(m, "WERR_NOT_QUORUM_CLASS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_QUORUM_CLASS)));
	PyModule_AddObject(m, "WERR_CORE_RESOURCE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CORE_RESOURCE)));
	PyModule_AddObject(m, "WERR_QUORUM_RESOURCE_ONLINE_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_QUORUM_RESOURCE_ONLINE_FAILED)));
	PyModule_AddObject(m, "WERR_QUORUMLOG_OPEN_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_QUORUMLOG_OPEN_FAILED)));
	PyModule_AddObject(m, "WERR_CLUSTERLOG_CORRUPT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTERLOG_CORRUPT)));
	PyModule_AddObject(m, "WERR_CLUSTERLOG_RECORD_EXCEEDS_MAXSIZE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTERLOG_RECORD_EXCEEDS_MAXSIZE)));
	PyModule_AddObject(m, "WERR_CLUSTERLOG_EXCEEDS_MAXSIZE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTERLOG_EXCEEDS_MAXSIZE)));
	PyModule_AddObject(m, "WERR_CLUSTERLOG_CHKPOINT_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTERLOG_CHKPOINT_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_CLUSTERLOG_NOT_ENOUGH_SPACE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTERLOG_NOT_ENOUGH_SPACE)));
	PyModule_AddObject(m, "WERR_QUORUM_OWNER_ALIVE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_QUORUM_OWNER_ALIVE)));
	PyModule_AddObject(m, "WERR_NETWORK_NOT_AVAILABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NETWORK_NOT_AVAILABLE)));
	PyModule_AddObject(m, "WERR_NODE_NOT_AVAILABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NODE_NOT_AVAILABLE)));
	PyModule_AddObject(m, "WERR_ALL_NODES_NOT_AVAILABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ALL_NODES_NOT_AVAILABLE)));
	PyModule_AddObject(m, "WERR_RESOURCE_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RESOURCE_FAILED)));
	PyModule_AddObject(m, "WERR_CLUSTER_INVALID_NODE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_INVALID_NODE)));
	PyModule_AddObject(m, "WERR_CLUSTER_NODE_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_NODE_EXISTS)));
	PyModule_AddObject(m, "WERR_CLUSTER_JOIN_IN_PROGRESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_JOIN_IN_PROGRESS)));
	PyModule_AddObject(m, "WERR_CLUSTER_NODE_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_NODE_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_CLUSTER_LOCAL_NODE_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_LOCAL_NODE_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_CLUSTER_NETWORK_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_NETWORK_EXISTS)));
	PyModule_AddObject(m, "WERR_CLUSTER_NETWORK_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_NETWORK_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_CLUSTER_NETINTERFACE_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_NETINTERFACE_EXISTS)));
	PyModule_AddObject(m, "WERR_CLUSTER_NETINTERFACE_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_NETINTERFACE_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_CLUSTER_INVALID_REQUEST",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_INVALID_REQUEST)));
	PyModule_AddObject(m, "WERR_CLUSTER_INVALID_NETWORK_PROVIDER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_INVALID_NETWORK_PROVIDER)));
	PyModule_AddObject(m, "WERR_CLUSTER_NODE_DOWN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_NODE_DOWN)));
	PyModule_AddObject(m, "WERR_CLUSTER_NODE_UNREACHABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_NODE_UNREACHABLE)));
	PyModule_AddObject(m, "WERR_CLUSTER_NODE_NOT_MEMBER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_NODE_NOT_MEMBER)));
	PyModule_AddObject(m, "WERR_CLUSTER_JOIN_NOT_IN_PROGRESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_JOIN_NOT_IN_PROGRESS)));
	PyModule_AddObject(m, "WERR_CLUSTER_INVALID_NETWORK",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_INVALID_NETWORK)));
	PyModule_AddObject(m, "WERR_CLUSTER_NODE_UP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_NODE_UP)));
	PyModule_AddObject(m, "WERR_CLUSTER_IPADDR_IN_USE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_IPADDR_IN_USE)));
	PyModule_AddObject(m, "WERR_CLUSTER_NODE_NOT_PAUSED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_NODE_NOT_PAUSED)));
	PyModule_AddObject(m, "WERR_CLUSTER_NO_SECURITY_CONTEXT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_NO_SECURITY_CONTEXT)));
	PyModule_AddObject(m, "WERR_CLUSTER_NETWORK_NOT_INTERNAL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_NETWORK_NOT_INTERNAL)));
	PyModule_AddObject(m, "WERR_CLUSTER_NODE_ALREADY_UP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_NODE_ALREADY_UP)));
	PyModule_AddObject(m, "WERR_CLUSTER_NODE_ALREADY_DOWN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_NODE_ALREADY_DOWN)));
	PyModule_AddObject(m, "WERR_CLUSTER_NETWORK_ALREADY_ONLINE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_NETWORK_ALREADY_ONLINE)));
	PyModule_AddObject(m, "WERR_CLUSTER_NETWORK_ALREADY_OFFLINE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_NETWORK_ALREADY_OFFLINE)));
	PyModule_AddObject(m, "WERR_CLUSTER_NODE_ALREADY_MEMBER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_NODE_ALREADY_MEMBER)));
	PyModule_AddObject(m, "WERR_CLUSTER_LAST_INTERNAL_NETWORK",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_LAST_INTERNAL_NETWORK)));
	PyModule_AddObject(m, "WERR_CLUSTER_NETWORK_HAS_DEPENDENTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_NETWORK_HAS_DEPENDENTS)));
	PyModule_AddObject(m, "WERR_INVALID_OPERATION_ON_QUORUM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_OPERATION_ON_QUORUM)));
	PyModule_AddObject(m, "WERR_DEPENDENCY_NOT_ALLOWED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DEPENDENCY_NOT_ALLOWED)));
	PyModule_AddObject(m, "WERR_CLUSTER_NODE_PAUSED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_NODE_PAUSED)));
	PyModule_AddObject(m, "WERR_NODE_CANT_HOST_RESOURCE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NODE_CANT_HOST_RESOURCE)));
	PyModule_AddObject(m, "WERR_CLUSTER_NODE_NOT_READY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_NODE_NOT_READY)));
	PyModule_AddObject(m, "WERR_CLUSTER_NODE_SHUTTING_DOWN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_NODE_SHUTTING_DOWN)));
	PyModule_AddObject(m, "WERR_CLUSTER_JOIN_ABORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_JOIN_ABORTED)));
	PyModule_AddObject(m, "WERR_CLUSTER_INCOMPATIBLE_VERSIONS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_INCOMPATIBLE_VERSIONS)));
	PyModule_AddObject(m, "WERR_CLUSTER_MAXNUM_OF_RESOURCES_EXCEEDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_MAXNUM_OF_RESOURCES_EXCEEDED)));
	PyModule_AddObject(m, "WERR_CLUSTER_SYSTEM_CONFIG_CHANGED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_SYSTEM_CONFIG_CHANGED)));
	PyModule_AddObject(m, "WERR_CLUSTER_RESOURCE_TYPE_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_RESOURCE_TYPE_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_CLUSTER_RESTYPE_NOT_SUPPORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_RESTYPE_NOT_SUPPORTED)));
	PyModule_AddObject(m, "WERR_CLUSTER_RESNAME_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_RESNAME_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_CLUSTER_NO_RPC_PACKAGES_REGISTERED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_NO_RPC_PACKAGES_REGISTERED)));
	PyModule_AddObject(m, "WERR_CLUSTER_OWNER_NOT_IN_PREFLIST",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_OWNER_NOT_IN_PREFLIST)));
	PyModule_AddObject(m, "WERR_CLUSTER_DATABASE_SEQMISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_DATABASE_SEQMISMATCH)));
	PyModule_AddObject(m, "WERR_RESMON_INVALID_STATE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RESMON_INVALID_STATE)));
	PyModule_AddObject(m, "WERR_CLUSTER_GUM_NOT_LOCKER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_GUM_NOT_LOCKER)));
	PyModule_AddObject(m, "WERR_QUORUM_DISK_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_QUORUM_DISK_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_DATABASE_BACKUP_CORRUPT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DATABASE_BACKUP_CORRUPT)));
	PyModule_AddObject(m, "WERR_CLUSTER_NODE_ALREADY_HAS_DFS_ROOT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_NODE_ALREADY_HAS_DFS_ROOT)));
	PyModule_AddObject(m, "WERR_RESOURCE_PROPERTY_UNCHANGEABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RESOURCE_PROPERTY_UNCHANGEABLE)));
	PyModule_AddObject(m, "WERR_CLUSTER_MEMBERSHIP_INVALID_STATE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_MEMBERSHIP_INVALID_STATE)));
	PyModule_AddObject(m, "WERR_CLUSTER_QUORUMLOG_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_QUORUMLOG_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_CLUSTER_MEMBERSHIP_HALT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_MEMBERSHIP_HALT)));
	PyModule_AddObject(m, "WERR_CLUSTER_INSTANCE_ID_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_INSTANCE_ID_MISMATCH)));
	PyModule_AddObject(m, "WERR_CLUSTER_NETWORK_NOT_FOUND_FOR_IP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_NETWORK_NOT_FOUND_FOR_IP)));
	PyModule_AddObject(m, "WERR_CLUSTER_PROPERTY_DATA_TYPE_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_PROPERTY_DATA_TYPE_MISMATCH)));
	PyModule_AddObject(m, "WERR_CLUSTER_EVICT_WITHOUT_CLEANUP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_EVICT_WITHOUT_CLEANUP)));
	PyModule_AddObject(m, "WERR_CLUSTER_PARAMETER_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_PARAMETER_MISMATCH)));
	PyModule_AddObject(m, "WERR_NODE_CANNOT_BE_CLUSTERED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NODE_CANNOT_BE_CLUSTERED)));
	PyModule_AddObject(m, "WERR_CLUSTER_WRONG_OS_VERSION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_WRONG_OS_VERSION)));
	PyModule_AddObject(m, "WERR_CLUSTER_CANT_CREATE_DUP_CLUSTER_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_CANT_CREATE_DUP_CLUSTER_NAME)));
	PyModule_AddObject(m, "WERR_CLUSCFG_ALREADY_COMMITTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSCFG_ALREADY_COMMITTED)));
	PyModule_AddObject(m, "WERR_CLUSCFG_ROLLBACK_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSCFG_ROLLBACK_FAILED)));
	PyModule_AddObject(m, "WERR_CLUSCFG_SYSTEM_DISK_DRIVE_LETTER_CONFLICT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSCFG_SYSTEM_DISK_DRIVE_LETTER_CONFLICT)));
	PyModule_AddObject(m, "WERR_CLUSTER_OLD_VERSION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_OLD_VERSION)));
	PyModule_AddObject(m, "WERR_CLUSTER_MISMATCHED_COMPUTER_ACCT_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_MISMATCHED_COMPUTER_ACCT_NAME)));
	PyModule_AddObject(m, "WERR_CLUSTER_NO_NET_ADAPTERS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_NO_NET_ADAPTERS)));
	PyModule_AddObject(m, "WERR_CLUSTER_POISONED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_POISONED)));
	PyModule_AddObject(m, "WERR_CLUSTER_GROUP_MOVING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_GROUP_MOVING)));
	PyModule_AddObject(m, "WERR_CLUSTER_RESOURCE_TYPE_BUSY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_RESOURCE_TYPE_BUSY)));
	PyModule_AddObject(m, "WERR_RESOURCE_CALL_TIMED_OUT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RESOURCE_CALL_TIMED_OUT)));
	PyModule_AddObject(m, "WERR_INVALID_CLUSTER_IPV6_ADDRESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_CLUSTER_IPV6_ADDRESS)));
	PyModule_AddObject(m, "WERR_CLUSTER_INTERNAL_INVALID_FUNCTION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_INTERNAL_INVALID_FUNCTION)));
	PyModule_AddObject(m, "WERR_CLUSTER_PARAMETER_OUT_OF_BOUNDS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_PARAMETER_OUT_OF_BOUNDS)));
	PyModule_AddObject(m, "WERR_CLUSTER_PARTIAL_SEND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_PARTIAL_SEND)));
	PyModule_AddObject(m, "WERR_CLUSTER_REGISTRY_INVALID_FUNCTION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_REGISTRY_INVALID_FUNCTION)));
	PyModule_AddObject(m, "WERR_CLUSTER_INVALID_STRING_TERMINATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_INVALID_STRING_TERMINATION)));
	PyModule_AddObject(m, "WERR_CLUSTER_INVALID_STRING_FORMAT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_INVALID_STRING_FORMAT)));
	PyModule_AddObject(m, "WERR_CLUSTER_DATABASE_TRANSACTION_IN_PROGRESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_DATABASE_TRANSACTION_IN_PROGRESS)));
	PyModule_AddObject(m, "WERR_CLUSTER_DATABASE_TRANSACTION_NOT_IN_PROGRESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_DATABASE_TRANSACTION_NOT_IN_PROGRESS)));
	PyModule_AddObject(m, "WERR_CLUSTER_NULL_DATA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_NULL_DATA)));
	PyModule_AddObject(m, "WERR_CLUSTER_PARTIAL_READ",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_PARTIAL_READ)));
	PyModule_AddObject(m, "WERR_CLUSTER_PARTIAL_WRITE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_PARTIAL_WRITE)));
	PyModule_AddObject(m, "WERR_CLUSTER_CANT_DESERIALIZE_DATA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_CANT_DESERIALIZE_DATA)));
	PyModule_AddObject(m, "WERR_DEPENDENT_RESOURCE_PROPERTY_CONFLICT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DEPENDENT_RESOURCE_PROPERTY_CONFLICT)));
	PyModule_AddObject(m, "WERR_CLUSTER_NO_QUORUM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_NO_QUORUM)));
	PyModule_AddObject(m, "WERR_CLUSTER_INVALID_IPV6_NETWORK",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_INVALID_IPV6_NETWORK)));
	PyModule_AddObject(m, "WERR_CLUSTER_INVALID_IPV6_TUNNEL_NETWORK",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CLUSTER_INVALID_IPV6_TUNNEL_NETWORK)));
	PyModule_AddObject(m, "WERR_QUORUM_NOT_ALLOWED_IN_THIS_GROUP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_QUORUM_NOT_ALLOWED_IN_THIS_GROUP)));
	PyModule_AddObject(m, "WERR_ENCRYPTION_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ENCRYPTION_FAILED)));
	PyModule_AddObject(m, "WERR_DECRYPTION_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DECRYPTION_FAILED)));
	PyModule_AddObject(m, "WERR_FILE_ENCRYPTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FILE_ENCRYPTED)));
	PyModule_AddObject(m, "WERR_NO_RECOVERY_POLICY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_RECOVERY_POLICY)));
	PyModule_AddObject(m, "WERR_NO_EFS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_EFS)));
	PyModule_AddObject(m, "WERR_WRONG_EFS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WRONG_EFS)));
	PyModule_AddObject(m, "WERR_NO_USER_KEYS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_USER_KEYS)));
	PyModule_AddObject(m, "WERR_FILE_NOT_ENCRYPTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FILE_NOT_ENCRYPTED)));
	PyModule_AddObject(m, "WERR_NOT_EXPORT_FORMAT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_EXPORT_FORMAT)));
	PyModule_AddObject(m, "WERR_FILE_READ_ONLY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FILE_READ_ONLY)));
	PyModule_AddObject(m, "WERR_DIR_EFS_DISALLOWED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DIR_EFS_DISALLOWED)));
	PyModule_AddObject(m, "WERR_EFS_SERVER_NOT_TRUSTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EFS_SERVER_NOT_TRUSTED)));
	PyModule_AddObject(m, "WERR_BAD_RECOVERY_POLICY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_BAD_RECOVERY_POLICY)));
	PyModule_AddObject(m, "WERR_EFS_ALG_BLOB_TOO_BIG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EFS_ALG_BLOB_TOO_BIG)));
	PyModule_AddObject(m, "WERR_VOLUME_NOT_SUPPORT_EFS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_VOLUME_NOT_SUPPORT_EFS)));
	PyModule_AddObject(m, "WERR_EFS_DISABLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EFS_DISABLED)));
	PyModule_AddObject(m, "WERR_EFS_VERSION_NOT_SUPPORT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EFS_VERSION_NOT_SUPPORT)));
	PyModule_AddObject(m, "WERR_CS_ENCRYPTION_INVALID_SERVER_RESPONSE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CS_ENCRYPTION_INVALID_SERVER_RESPONSE)));
	PyModule_AddObject(m, "WERR_CS_ENCRYPTION_UNSUPPORTED_SERVER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CS_ENCRYPTION_UNSUPPORTED_SERVER)));
	PyModule_AddObject(m, "WERR_CS_ENCRYPTION_EXISTING_ENCRYPTED_FILE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CS_ENCRYPTION_EXISTING_ENCRYPTED_FILE)));
	PyModule_AddObject(m, "WERR_CS_ENCRYPTION_NEW_ENCRYPTED_FILE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CS_ENCRYPTION_NEW_ENCRYPTED_FILE)));
	PyModule_AddObject(m, "WERR_CS_ENCRYPTION_FILE_NOT_CSE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CS_ENCRYPTION_FILE_NOT_CSE)));
	PyModule_AddObject(m, "WERR_NO_BROWSER_SERVERS_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_BROWSER_SERVERS_FOUND)));
	PyModule_AddObject(m, "WERR_SCHED_E_SERVICE_NOT_LOCALSYSTEM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SCHED_E_SERVICE_NOT_LOCALSYSTEM)));
	PyModule_AddObject(m, "WERR_LOG_SECTOR_INVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_SECTOR_INVALID)));
	PyModule_AddObject(m, "WERR_LOG_SECTOR_PARITY_INVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_SECTOR_PARITY_INVALID)));
	PyModule_AddObject(m, "WERR_LOG_SECTOR_REMAPPED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_SECTOR_REMAPPED)));
	PyModule_AddObject(m, "WERR_LOG_BLOCK_INCOMPLETE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_BLOCK_INCOMPLETE)));
	PyModule_AddObject(m, "WERR_LOG_INVALID_RANGE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_INVALID_RANGE)));
	PyModule_AddObject(m, "WERR_LOG_BLOCKS_EXHAUSTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_BLOCKS_EXHAUSTED)));
	PyModule_AddObject(m, "WERR_LOG_READ_CONTEXT_INVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_READ_CONTEXT_INVALID)));
	PyModule_AddObject(m, "WERR_LOG_RESTART_INVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_RESTART_INVALID)));
	PyModule_AddObject(m, "WERR_LOG_BLOCK_VERSION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_BLOCK_VERSION)));
	PyModule_AddObject(m, "WERR_LOG_BLOCK_INVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_BLOCK_INVALID)));
	PyModule_AddObject(m, "WERR_LOG_READ_MODE_INVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_READ_MODE_INVALID)));
	PyModule_AddObject(m, "WERR_LOG_NO_RESTART",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_NO_RESTART)));
	PyModule_AddObject(m, "WERR_LOG_METADATA_CORRUPT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_METADATA_CORRUPT)));
	PyModule_AddObject(m, "WERR_LOG_METADATA_INVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_METADATA_INVALID)));
	PyModule_AddObject(m, "WERR_LOG_METADATA_INCONSISTENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_METADATA_INCONSISTENT)));
	PyModule_AddObject(m, "WERR_LOG_RESERVATION_INVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_RESERVATION_INVALID)));
	PyModule_AddObject(m, "WERR_LOG_CANT_DELETE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_CANT_DELETE)));
	PyModule_AddObject(m, "WERR_LOG_CONTAINER_LIMIT_EXCEEDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_CONTAINER_LIMIT_EXCEEDED)));
	PyModule_AddObject(m, "WERR_LOG_START_OF_LOG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_START_OF_LOG)));
	PyModule_AddObject(m, "WERR_LOG_POLICY_ALREADY_INSTALLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_POLICY_ALREADY_INSTALLED)));
	PyModule_AddObject(m, "WERR_LOG_POLICY_NOT_INSTALLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_POLICY_NOT_INSTALLED)));
	PyModule_AddObject(m, "WERR_LOG_POLICY_INVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_POLICY_INVALID)));
	PyModule_AddObject(m, "WERR_LOG_POLICY_CONFLICT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_POLICY_CONFLICT)));
	PyModule_AddObject(m, "WERR_LOG_PINNED_ARCHIVE_TAIL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_PINNED_ARCHIVE_TAIL)));
	PyModule_AddObject(m, "WERR_LOG_RECORD_NONEXISTENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_RECORD_NONEXISTENT)));
	PyModule_AddObject(m, "WERR_LOG_RECORDS_RESERVED_INVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_RECORDS_RESERVED_INVALID)));
	PyModule_AddObject(m, "WERR_LOG_SPACE_RESERVED_INVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_SPACE_RESERVED_INVALID)));
	PyModule_AddObject(m, "WERR_LOG_TAIL_INVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_TAIL_INVALID)));
	PyModule_AddObject(m, "WERR_LOG_FULL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_FULL)));
	PyModule_AddObject(m, "WERR_COULD_NOT_RESIZE_LOG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_COULD_NOT_RESIZE_LOG)));
	PyModule_AddObject(m, "WERR_LOG_MULTIPLEXED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_MULTIPLEXED)));
	PyModule_AddObject(m, "WERR_LOG_DEDICATED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_DEDICATED)));
	PyModule_AddObject(m, "WERR_LOG_ARCHIVE_NOT_IN_PROGRESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_ARCHIVE_NOT_IN_PROGRESS)));
	PyModule_AddObject(m, "WERR_LOG_ARCHIVE_IN_PROGRESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_ARCHIVE_IN_PROGRESS)));
	PyModule_AddObject(m, "WERR_LOG_EPHEMERAL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_EPHEMERAL)));
	PyModule_AddObject(m, "WERR_LOG_NOT_ENOUGH_CONTAINERS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_NOT_ENOUGH_CONTAINERS)));
	PyModule_AddObject(m, "WERR_LOG_CLIENT_ALREADY_REGISTERED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_CLIENT_ALREADY_REGISTERED)));
	PyModule_AddObject(m, "WERR_LOG_CLIENT_NOT_REGISTERED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_CLIENT_NOT_REGISTERED)));
	PyModule_AddObject(m, "WERR_LOG_FULL_HANDLER_IN_PROGRESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_FULL_HANDLER_IN_PROGRESS)));
	PyModule_AddObject(m, "WERR_LOG_CONTAINER_READ_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_CONTAINER_READ_FAILED)));
	PyModule_AddObject(m, "WERR_LOG_CONTAINER_WRITE_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_CONTAINER_WRITE_FAILED)));
	PyModule_AddObject(m, "WERR_LOG_CONTAINER_OPEN_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_CONTAINER_OPEN_FAILED)));
	PyModule_AddObject(m, "WERR_LOG_CONTAINER_STATE_INVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_CONTAINER_STATE_INVALID)));
	PyModule_AddObject(m, "WERR_LOG_STATE_INVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_STATE_INVALID)));
	PyModule_AddObject(m, "WERR_LOG_PINNED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_PINNED)));
	PyModule_AddObject(m, "WERR_LOG_METADATA_FLUSH_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_METADATA_FLUSH_FAILED)));
	PyModule_AddObject(m, "WERR_LOG_INCONSISTENT_SECURITY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_INCONSISTENT_SECURITY)));
	PyModule_AddObject(m, "WERR_LOG_APPENDED_FLUSH_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_APPENDED_FLUSH_FAILED)));
	PyModule_AddObject(m, "WERR_LOG_PINNED_RESERVATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_PINNED_RESERVATION)));
	PyModule_AddObject(m, "WERR_INVALID_TRANSACTION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INVALID_TRANSACTION)));
	PyModule_AddObject(m, "WERR_TRANSACTION_NOT_ACTIVE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TRANSACTION_NOT_ACTIVE)));
	PyModule_AddObject(m, "WERR_TRANSACTION_REQUEST_NOT_VALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TRANSACTION_REQUEST_NOT_VALID)));
	PyModule_AddObject(m, "WERR_TRANSACTION_NOT_REQUESTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TRANSACTION_NOT_REQUESTED)));
	PyModule_AddObject(m, "WERR_TRANSACTION_ALREADY_ABORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TRANSACTION_ALREADY_ABORTED)));
	PyModule_AddObject(m, "WERR_TRANSACTION_ALREADY_COMMITTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TRANSACTION_ALREADY_COMMITTED)));
	PyModule_AddObject(m, "WERR_TM_INITIALIZATION_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TM_INITIALIZATION_FAILED)));
	PyModule_AddObject(m, "WERR_RESOURCEMANAGER_READ_ONLY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RESOURCEMANAGER_READ_ONLY)));
	PyModule_AddObject(m, "WERR_TRANSACTION_NOT_JOINED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TRANSACTION_NOT_JOINED)));
	PyModule_AddObject(m, "WERR_TRANSACTION_SUPERIOR_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TRANSACTION_SUPERIOR_EXISTS)));
	PyModule_AddObject(m, "WERR_CRM_PROTOCOL_ALREADY_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CRM_PROTOCOL_ALREADY_EXISTS)));
	PyModule_AddObject(m, "WERR_TRANSACTION_PROPAGATION_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TRANSACTION_PROPAGATION_FAILED)));
	PyModule_AddObject(m, "WERR_CRM_PROTOCOL_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CRM_PROTOCOL_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_TRANSACTION_INVALID_MARSHALL_BUFFER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TRANSACTION_INVALID_MARSHALL_BUFFER)));
	PyModule_AddObject(m, "WERR_CURRENT_TRANSACTION_NOT_VALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CURRENT_TRANSACTION_NOT_VALID)));
	PyModule_AddObject(m, "WERR_TRANSACTION_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TRANSACTION_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_RESOURCEMANAGER_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RESOURCEMANAGER_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_ENLISTMENT_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ENLISTMENT_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_TRANSACTIONMANAGER_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TRANSACTIONMANAGER_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_TRANSACTIONMANAGER_NOT_ONLINE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TRANSACTIONMANAGER_NOT_ONLINE)));
	PyModule_AddObject(m, "WERR_TRANSACTIONMANAGER_RECOVERY_NAME_COLLISION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TRANSACTIONMANAGER_RECOVERY_NAME_COLLISION)));
	PyModule_AddObject(m, "WERR_TRANSACTIONAL_CONFLICT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TRANSACTIONAL_CONFLICT)));
	PyModule_AddObject(m, "WERR_RM_NOT_ACTIVE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RM_NOT_ACTIVE)));
	PyModule_AddObject(m, "WERR_RM_METADATA_CORRUPT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RM_METADATA_CORRUPT)));
	PyModule_AddObject(m, "WERR_DIRECTORY_NOT_RM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DIRECTORY_NOT_RM)));
	PyModule_AddObject(m, "WERR_TRANSACTIONS_UNSUPPORTED_REMOTE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TRANSACTIONS_UNSUPPORTED_REMOTE)));
	PyModule_AddObject(m, "WERR_LOG_RESIZE_INVALID_SIZE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_RESIZE_INVALID_SIZE)));
	PyModule_AddObject(m, "WERR_OBJECT_NO_LONGER_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_OBJECT_NO_LONGER_EXISTS)));
	PyModule_AddObject(m, "WERR_STREAM_MINIVERSION_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_STREAM_MINIVERSION_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_STREAM_MINIVERSION_NOT_VALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_STREAM_MINIVERSION_NOT_VALID)));
	PyModule_AddObject(m, "WERR_MINIVERSION_INACCESSIBLE_FROM_SPECIFIED_TRANSACTION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MINIVERSION_INACCESSIBLE_FROM_SPECIFIED_TRANSACTION)));
	PyModule_AddObject(m, "WERR_CANT_OPEN_MINIVERSION_WITH_MODIFY_INTENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANT_OPEN_MINIVERSION_WITH_MODIFY_INTENT)));
	PyModule_AddObject(m, "WERR_CANT_CREATE_MORE_STREAM_MINIVERSIONS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANT_CREATE_MORE_STREAM_MINIVERSIONS)));
	PyModule_AddObject(m, "WERR_REMOTE_FILE_VERSION_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_REMOTE_FILE_VERSION_MISMATCH)));
	PyModule_AddObject(m, "WERR_HANDLE_NO_LONGER_VALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_HANDLE_NO_LONGER_VALID)));
	PyModule_AddObject(m, "WERR_NO_TXF_METADATA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_TXF_METADATA)));
	PyModule_AddObject(m, "WERR_LOG_CORRUPTION_DETECTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_CORRUPTION_DETECTED)));
	PyModule_AddObject(m, "WERR_CANT_RECOVER_WITH_HANDLE_OPEN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANT_RECOVER_WITH_HANDLE_OPEN)));
	PyModule_AddObject(m, "WERR_RM_DISCONNECTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RM_DISCONNECTED)));
	PyModule_AddObject(m, "WERR_ENLISTMENT_NOT_SUPERIOR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ENLISTMENT_NOT_SUPERIOR)));
	PyModule_AddObject(m, "WERR_RECOVERY_NOT_NEEDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RECOVERY_NOT_NEEDED)));
	PyModule_AddObject(m, "WERR_RM_ALREADY_STARTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RM_ALREADY_STARTED)));
	PyModule_AddObject(m, "WERR_FILE_IDENTITY_NOT_PERSISTENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FILE_IDENTITY_NOT_PERSISTENT)));
	PyModule_AddObject(m, "WERR_CANT_BREAK_TRANSACTIONAL_DEPENDENCY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANT_BREAK_TRANSACTIONAL_DEPENDENCY)));
	PyModule_AddObject(m, "WERR_CANT_CROSS_RM_BOUNDARY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANT_CROSS_RM_BOUNDARY)));
	PyModule_AddObject(m, "WERR_TXF_DIR_NOT_EMPTY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TXF_DIR_NOT_EMPTY)));
	PyModule_AddObject(m, "WERR_INDOUBT_TRANSACTIONS_EXIST",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_INDOUBT_TRANSACTIONS_EXIST)));
	PyModule_AddObject(m, "WERR_TM_VOLATILE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TM_VOLATILE)));
	PyModule_AddObject(m, "WERR_ROLLBACK_TIMER_EXPIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ROLLBACK_TIMER_EXPIRED)));
	PyModule_AddObject(m, "WERR_TXF_ATTRIBUTE_CORRUPT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TXF_ATTRIBUTE_CORRUPT)));
	PyModule_AddObject(m, "WERR_EFS_NOT_ALLOWED_IN_TRANSACTION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EFS_NOT_ALLOWED_IN_TRANSACTION)));
	PyModule_AddObject(m, "WERR_TRANSACTIONAL_OPEN_NOT_ALLOWED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TRANSACTIONAL_OPEN_NOT_ALLOWED)));
	PyModule_AddObject(m, "WERR_LOG_GROWTH_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_LOG_GROWTH_FAILED)));
	PyModule_AddObject(m, "WERR_TRANSACTED_MAPPING_UNSUPPORTED_REMOTE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TRANSACTED_MAPPING_UNSUPPORTED_REMOTE)));
	PyModule_AddObject(m, "WERR_TXF_METADATA_ALREADY_PRESENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TXF_METADATA_ALREADY_PRESENT)));
	PyModule_AddObject(m, "WERR_TRANSACTION_SCOPE_CALLBACKS_NOT_SET",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TRANSACTION_SCOPE_CALLBACKS_NOT_SET)));
	PyModule_AddObject(m, "WERR_TRANSACTION_REQUIRED_PROMOTION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TRANSACTION_REQUIRED_PROMOTION)));
	PyModule_AddObject(m, "WERR_CANNOT_EXECUTE_FILE_IN_TRANSACTION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANNOT_EXECUTE_FILE_IN_TRANSACTION)));
	PyModule_AddObject(m, "WERR_TRANSACTIONS_NOT_FROZEN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TRANSACTIONS_NOT_FROZEN)));
	PyModule_AddObject(m, "WERR_TRANSACTION_FREEZE_IN_PROGRESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TRANSACTION_FREEZE_IN_PROGRESS)));
	PyModule_AddObject(m, "WERR_NOT_SNAPSHOT_VOLUME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_SNAPSHOT_VOLUME)));
	PyModule_AddObject(m, "WERR_NO_SAVEPOINT_WITH_OPEN_FILES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_SAVEPOINT_WITH_OPEN_FILES)));
	PyModule_AddObject(m, "WERR_DATA_LOST_REPAIR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DATA_LOST_REPAIR)));
	PyModule_AddObject(m, "WERR_SPARSE_NOT_ALLOWED_IN_TRANSACTION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SPARSE_NOT_ALLOWED_IN_TRANSACTION)));
	PyModule_AddObject(m, "WERR_TM_IDENTITY_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TM_IDENTITY_MISMATCH)));
	PyModule_AddObject(m, "WERR_FLOATED_SECTION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FLOATED_SECTION)));
	PyModule_AddObject(m, "WERR_CANNOT_ACCEPT_TRANSACTED_WORK",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANNOT_ACCEPT_TRANSACTED_WORK)));
	PyModule_AddObject(m, "WERR_CANNOT_ABORT_TRANSACTIONS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CANNOT_ABORT_TRANSACTIONS)));
	PyModule_AddObject(m, "WERR_CTX_WINSTATION_NAME_INVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_WINSTATION_NAME_INVALID)));
	PyModule_AddObject(m, "WERR_CTX_INVALID_PD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_INVALID_PD)));
	PyModule_AddObject(m, "WERR_CTX_PD_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_PD_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_CTX_WD_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_WD_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_CTX_CANNOT_MAKE_EVENTLOG_ENTRY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_CANNOT_MAKE_EVENTLOG_ENTRY)));
	PyModule_AddObject(m, "WERR_CTX_SERVICE_NAME_COLLISION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_SERVICE_NAME_COLLISION)));
	PyModule_AddObject(m, "WERR_CTX_CLOSE_PENDING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_CLOSE_PENDING)));
	PyModule_AddObject(m, "WERR_CTX_NO_OUTBUF",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_NO_OUTBUF)));
	PyModule_AddObject(m, "WERR_CTX_MODEM_INF_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_MODEM_INF_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_CTX_INVALID_MODEMNAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_INVALID_MODEMNAME)));
	PyModule_AddObject(m, "WERR_CTX_MODEM_RESPONSE_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_MODEM_RESPONSE_ERROR)));
	PyModule_AddObject(m, "WERR_CTX_MODEM_RESPONSE_TIMEOUT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_MODEM_RESPONSE_TIMEOUT)));
	PyModule_AddObject(m, "WERR_CTX_MODEM_RESPONSE_NO_CARRIER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_MODEM_RESPONSE_NO_CARRIER)));
	PyModule_AddObject(m, "WERR_CTX_MODEM_RESPONSE_NO_DIALTONE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_MODEM_RESPONSE_NO_DIALTONE)));
	PyModule_AddObject(m, "WERR_CTX_MODEM_RESPONSE_BUSY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_MODEM_RESPONSE_BUSY)));
	PyModule_AddObject(m, "WERR_CTX_MODEM_RESPONSE_VOICE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_MODEM_RESPONSE_VOICE)));
	PyModule_AddObject(m, "WERR_CTX_TD_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_TD_ERROR)));
	PyModule_AddObject(m, "WERR_CTX_WINSTATION_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_WINSTATION_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_CTX_WINSTATION_ALREADY_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_WINSTATION_ALREADY_EXISTS)));
	PyModule_AddObject(m, "WERR_CTX_WINSTATION_BUSY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_WINSTATION_BUSY)));
	PyModule_AddObject(m, "WERR_CTX_BAD_VIDEO_MODE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_BAD_VIDEO_MODE)));
	PyModule_AddObject(m, "WERR_CTX_GRAPHICS_INVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_GRAPHICS_INVALID)));
	PyModule_AddObject(m, "WERR_CTX_LOGON_DISABLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_LOGON_DISABLED)));
	PyModule_AddObject(m, "WERR_CTX_NOT_CONSOLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_NOT_CONSOLE)));
	PyModule_AddObject(m, "WERR_CTX_CLIENT_QUERY_TIMEOUT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_CLIENT_QUERY_TIMEOUT)));
	PyModule_AddObject(m, "WERR_CTX_CONSOLE_DISCONNECT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_CONSOLE_DISCONNECT)));
	PyModule_AddObject(m, "WERR_CTX_CONSOLE_CONNECT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_CONSOLE_CONNECT)));
	PyModule_AddObject(m, "WERR_CTX_SHADOW_DENIED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_SHADOW_DENIED)));
	PyModule_AddObject(m, "WERR_CTX_WINSTATION_ACCESS_DENIED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_WINSTATION_ACCESS_DENIED)));
	PyModule_AddObject(m, "WERR_CTX_INVALID_WD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_INVALID_WD)));
	PyModule_AddObject(m, "WERR_CTX_SHADOW_INVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_SHADOW_INVALID)));
	PyModule_AddObject(m, "WERR_CTX_SHADOW_DISABLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_SHADOW_DISABLED)));
	PyModule_AddObject(m, "WERR_CTX_CLIENT_LICENSE_IN_USE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_CLIENT_LICENSE_IN_USE)));
	PyModule_AddObject(m, "WERR_CTX_CLIENT_LICENSE_NOT_SET",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_CLIENT_LICENSE_NOT_SET)));
	PyModule_AddObject(m, "WERR_CTX_LICENSE_NOT_AVAILABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_LICENSE_NOT_AVAILABLE)));
	PyModule_AddObject(m, "WERR_CTX_LICENSE_CLIENT_INVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_LICENSE_CLIENT_INVALID)));
	PyModule_AddObject(m, "WERR_CTX_LICENSE_EXPIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_LICENSE_EXPIRED)));
	PyModule_AddObject(m, "WERR_CTX_SHADOW_NOT_RUNNING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_SHADOW_NOT_RUNNING)));
	PyModule_AddObject(m, "WERR_CTX_SHADOW_ENDED_BY_MODE_CHANGE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_SHADOW_ENDED_BY_MODE_CHANGE)));
	PyModule_AddObject(m, "WERR_ACTIVATION_COUNT_EXCEEDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ACTIVATION_COUNT_EXCEEDED)));
	PyModule_AddObject(m, "WERR_CTX_WINSTATIONS_DISABLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_WINSTATIONS_DISABLED)));
	PyModule_AddObject(m, "WERR_CTX_ENCRYPTION_LEVEL_REQUIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_ENCRYPTION_LEVEL_REQUIRED)));
	PyModule_AddObject(m, "WERR_CTX_SESSION_IN_USE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_SESSION_IN_USE)));
	PyModule_AddObject(m, "WERR_CTX_NO_FORCE_LOGOFF",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_NO_FORCE_LOGOFF)));
	PyModule_AddObject(m, "WERR_CTX_ACCOUNT_RESTRICTION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_ACCOUNT_RESTRICTION)));
	PyModule_AddObject(m, "WERR_RDP_PROTOCOL_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RDP_PROTOCOL_ERROR)));
	PyModule_AddObject(m, "WERR_CTX_CDM_CONNECT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_CDM_CONNECT)));
	PyModule_AddObject(m, "WERR_CTX_CDM_DISCONNECT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_CDM_DISCONNECT)));
	PyModule_AddObject(m, "WERR_CTX_SECURITY_LAYER_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_CTX_SECURITY_LAYER_ERROR)));
	PyModule_AddObject(m, "WERR_TS_INCOMPATIBLE_SESSIONS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_TS_INCOMPATIBLE_SESSIONS)));
	PyModule_AddObject(m, "WERR_FRS_ERR_INVALID_API_SEQUENCE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FRS_ERR_INVALID_API_SEQUENCE)));
	PyModule_AddObject(m, "WERR_FRS_ERR_STARTING_SERVICE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FRS_ERR_STARTING_SERVICE)));
	PyModule_AddObject(m, "WERR_FRS_ERR_STOPPING_SERVICE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FRS_ERR_STOPPING_SERVICE)));
	PyModule_AddObject(m, "WERR_FRS_ERR_INTERNAL_API",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FRS_ERR_INTERNAL_API)));
	PyModule_AddObject(m, "WERR_FRS_ERR_INTERNAL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FRS_ERR_INTERNAL)));
	PyModule_AddObject(m, "WERR_FRS_ERR_SERVICE_COMM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FRS_ERR_SERVICE_COMM)));
	PyModule_AddObject(m, "WERR_FRS_ERR_INSUFFICIENT_PRIV",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FRS_ERR_INSUFFICIENT_PRIV)));
	PyModule_AddObject(m, "WERR_FRS_ERR_AUTHENTICATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FRS_ERR_AUTHENTICATION)));
	PyModule_AddObject(m, "WERR_FRS_ERR_PARENT_INSUFFICIENT_PRIV",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FRS_ERR_PARENT_INSUFFICIENT_PRIV)));
	PyModule_AddObject(m, "WERR_FRS_ERR_PARENT_AUTHENTICATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FRS_ERR_PARENT_AUTHENTICATION)));
	PyModule_AddObject(m, "WERR_FRS_ERR_CHILD_TO_PARENT_COMM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FRS_ERR_CHILD_TO_PARENT_COMM)));
	PyModule_AddObject(m, "WERR_FRS_ERR_PARENT_TO_CHILD_COMM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FRS_ERR_PARENT_TO_CHILD_COMM)));
	PyModule_AddObject(m, "WERR_FRS_ERR_SYSVOL_POPULATE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FRS_ERR_SYSVOL_POPULATE)));
	PyModule_AddObject(m, "WERR_FRS_ERR_SYSVOL_POPULATE_TIMEOUT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FRS_ERR_SYSVOL_POPULATE_TIMEOUT)));
	PyModule_AddObject(m, "WERR_FRS_ERR_SYSVOL_IS_BUSY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FRS_ERR_SYSVOL_IS_BUSY)));
	PyModule_AddObject(m, "WERR_FRS_ERR_SYSVOL_DEMOTE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FRS_ERR_SYSVOL_DEMOTE)));
	PyModule_AddObject(m, "WERR_FRS_ERR_INVALID_SERVICE_PARAMETER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_FRS_ERR_INVALID_SERVICE_PARAMETER)));
	PyModule_AddObject(m, "WERR_DS_NOT_INSTALLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NOT_INSTALLED)));
	PyModule_AddObject(m, "WERR_DS_MEMBERSHIP_EVALUATED_LOCALLY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_MEMBERSHIP_EVALUATED_LOCALLY)));
	PyModule_AddObject(m, "WERR_DS_NO_ATTRIBUTE_OR_VALUE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NO_ATTRIBUTE_OR_VALUE)));
	PyModule_AddObject(m, "WERR_DS_INVALID_ATTRIBUTE_SYNTAX",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_INVALID_ATTRIBUTE_SYNTAX)));
	PyModule_AddObject(m, "WERR_DS_ATTRIBUTE_TYPE_UNDEFINED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_ATTRIBUTE_TYPE_UNDEFINED)));
	PyModule_AddObject(m, "WERR_DS_ATTRIBUTE_OR_VALUE_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_ATTRIBUTE_OR_VALUE_EXISTS)));
	PyModule_AddObject(m, "WERR_DS_BUSY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_BUSY)));
	PyModule_AddObject(m, "WERR_DS_UNAVAILABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_UNAVAILABLE)));
	PyModule_AddObject(m, "WERR_DS_NO_RIDS_ALLOCATED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NO_RIDS_ALLOCATED)));
	PyModule_AddObject(m, "WERR_DS_NO_MORE_RIDS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NO_MORE_RIDS)));
	PyModule_AddObject(m, "WERR_DS_INCORRECT_ROLE_OWNER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_INCORRECT_ROLE_OWNER)));
	PyModule_AddObject(m, "WERR_DS_RIDMGR_INIT_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_RIDMGR_INIT_ERROR)));
	PyModule_AddObject(m, "WERR_DS_OBJ_CLASS_VIOLATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_OBJ_CLASS_VIOLATION)));
	PyModule_AddObject(m, "WERR_DS_CANT_ON_NON_LEAF",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_ON_NON_LEAF)));
	PyModule_AddObject(m, "WERR_DS_CANT_ON_RDN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_ON_RDN)));
	PyModule_AddObject(m, "WERR_DS_CANT_MOD_OBJ_CLASS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_MOD_OBJ_CLASS)));
	PyModule_AddObject(m, "WERR_DS_CROSS_DOM_MOVE_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CROSS_DOM_MOVE_ERROR)));
	PyModule_AddObject(m, "WERR_DS_GC_NOT_AVAILABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_GC_NOT_AVAILABLE)));
	PyModule_AddObject(m, "WERR_SHARED_POLICY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SHARED_POLICY)));
	PyModule_AddObject(m, "WERR_POLICY_OBJECT_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_POLICY_OBJECT_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_POLICY_ONLY_IN_DS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_POLICY_ONLY_IN_DS)));
	PyModule_AddObject(m, "WERR_PROMOTION_ACTIVE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_PROMOTION_ACTIVE)));
	PyModule_AddObject(m, "WERR_NO_PROMOTION_ACTIVE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_PROMOTION_ACTIVE)));
	PyModule_AddObject(m, "WERR_DS_OPERATIONS_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_OPERATIONS_ERROR)));
	PyModule_AddObject(m, "WERR_DS_PROTOCOL_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_PROTOCOL_ERROR)));
	PyModule_AddObject(m, "WERR_DS_TIMELIMIT_EXCEEDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_TIMELIMIT_EXCEEDED)));
	PyModule_AddObject(m, "WERR_DS_SIZELIMIT_EXCEEDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SIZELIMIT_EXCEEDED)));
	PyModule_AddObject(m, "WERR_DS_ADMIN_LIMIT_EXCEEDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_ADMIN_LIMIT_EXCEEDED)));
	PyModule_AddObject(m, "WERR_DS_COMPARE_FALSE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_COMPARE_FALSE)));
	PyModule_AddObject(m, "WERR_DS_COMPARE_TRUE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_COMPARE_TRUE)));
	PyModule_AddObject(m, "WERR_DS_AUTH_METHOD_NOT_SUPPORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_AUTH_METHOD_NOT_SUPPORTED)));
	PyModule_AddObject(m, "WERR_DS_STRONG_AUTH_REQUIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_STRONG_AUTH_REQUIRED)));
	PyModule_AddObject(m, "WERR_DS_INAPPROPRIATE_AUTH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_INAPPROPRIATE_AUTH)));
	PyModule_AddObject(m, "WERR_DS_AUTH_UNKNOWN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_AUTH_UNKNOWN)));
	PyModule_AddObject(m, "WERR_DS_REFERRAL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_REFERRAL)));
	PyModule_AddObject(m, "WERR_DS_UNAVAILABLE_CRIT_EXTENSION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_UNAVAILABLE_CRIT_EXTENSION)));
	PyModule_AddObject(m, "WERR_DS_CONFIDENTIALITY_REQUIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CONFIDENTIALITY_REQUIRED)));
	PyModule_AddObject(m, "WERR_DS_INAPPROPRIATE_MATCHING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_INAPPROPRIATE_MATCHING)));
	PyModule_AddObject(m, "WERR_DS_CONSTRAINT_VIOLATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CONSTRAINT_VIOLATION)));
	PyModule_AddObject(m, "WERR_DS_NO_SUCH_OBJECT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NO_SUCH_OBJECT)));
	PyModule_AddObject(m, "WERR_DS_ALIAS_PROBLEM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_ALIAS_PROBLEM)));
	PyModule_AddObject(m, "WERR_DS_INVALID_DN_SYNTAX",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_INVALID_DN_SYNTAX)));
	PyModule_AddObject(m, "WERR_DS_IS_LEAF",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_IS_LEAF)));
	PyModule_AddObject(m, "WERR_DS_ALIAS_DEREF_PROBLEM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_ALIAS_DEREF_PROBLEM)));
	PyModule_AddObject(m, "WERR_DS_UNWILLING_TO_PERFORM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_UNWILLING_TO_PERFORM)));
	PyModule_AddObject(m, "WERR_DS_LOOP_DETECT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_LOOP_DETECT)));
	PyModule_AddObject(m, "WERR_DS_NAMING_VIOLATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NAMING_VIOLATION)));
	PyModule_AddObject(m, "WERR_DS_OBJECT_RESULTS_TOO_LARGE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_OBJECT_RESULTS_TOO_LARGE)));
	PyModule_AddObject(m, "WERR_DS_AFFECTS_MULTIPLE_DSAS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_AFFECTS_MULTIPLE_DSAS)));
	PyModule_AddObject(m, "WERR_DS_SERVER_DOWN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SERVER_DOWN)));
	PyModule_AddObject(m, "WERR_DS_LOCAL_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_LOCAL_ERROR)));
	PyModule_AddObject(m, "WERR_DS_ENCODING_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_ENCODING_ERROR)));
	PyModule_AddObject(m, "WERR_DS_DECODING_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DECODING_ERROR)));
	PyModule_AddObject(m, "WERR_DS_FILTER_UNKNOWN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_FILTER_UNKNOWN)));
	PyModule_AddObject(m, "WERR_DS_PARAM_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_PARAM_ERROR)));
	PyModule_AddObject(m, "WERR_DS_NOT_SUPPORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NOT_SUPPORTED)));
	PyModule_AddObject(m, "WERR_DS_NO_RESULTS_RETURNED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NO_RESULTS_RETURNED)));
	PyModule_AddObject(m, "WERR_DS_CONTROL_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CONTROL_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_DS_CLIENT_LOOP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CLIENT_LOOP)));
	PyModule_AddObject(m, "WERR_DS_REFERRAL_LIMIT_EXCEEDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_REFERRAL_LIMIT_EXCEEDED)));
	PyModule_AddObject(m, "WERR_DS_SORT_CONTROL_MISSING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SORT_CONTROL_MISSING)));
	PyModule_AddObject(m, "WERR_DS_OFFSET_RANGE_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_OFFSET_RANGE_ERROR)));
	PyModule_AddObject(m, "WERR_DS_ROOT_MUST_BE_NC",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_ROOT_MUST_BE_NC)));
	PyModule_AddObject(m, "WERR_DS_ADD_REPLICA_INHIBITED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_ADD_REPLICA_INHIBITED)));
	PyModule_AddObject(m, "WERR_DS_ATT_NOT_DEF_IN_SCHEMA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_ATT_NOT_DEF_IN_SCHEMA)));
	PyModule_AddObject(m, "WERR_DS_MAX_OBJ_SIZE_EXCEEDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_MAX_OBJ_SIZE_EXCEEDED)));
	PyModule_AddObject(m, "WERR_DS_OBJ_STRING_NAME_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_OBJ_STRING_NAME_EXISTS)));
	PyModule_AddObject(m, "WERR_DS_NO_RDN_DEFINED_IN_SCHEMA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NO_RDN_DEFINED_IN_SCHEMA)));
	PyModule_AddObject(m, "WERR_DS_RDN_DOESNT_MATCH_SCHEMA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_RDN_DOESNT_MATCH_SCHEMA)));
	PyModule_AddObject(m, "WERR_DS_NO_REQUESTED_ATTS_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NO_REQUESTED_ATTS_FOUND)));
	PyModule_AddObject(m, "WERR_DS_USER_BUFFER_TO_SMALL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_USER_BUFFER_TO_SMALL)));
	PyModule_AddObject(m, "WERR_DS_ATT_IS_NOT_ON_OBJ",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_ATT_IS_NOT_ON_OBJ)));
	PyModule_AddObject(m, "WERR_DS_ILLEGAL_MOD_OPERATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_ILLEGAL_MOD_OPERATION)));
	PyModule_AddObject(m, "WERR_DS_OBJ_TOO_LARGE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_OBJ_TOO_LARGE)));
	PyModule_AddObject(m, "WERR_DS_BAD_INSTANCE_TYPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_BAD_INSTANCE_TYPE)));
	PyModule_AddObject(m, "WERR_DS_MASTERDSA_REQUIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_MASTERDSA_REQUIRED)));
	PyModule_AddObject(m, "WERR_DS_OBJECT_CLASS_REQUIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_OBJECT_CLASS_REQUIRED)));
	PyModule_AddObject(m, "WERR_DS_MISSING_REQUIRED_ATT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_MISSING_REQUIRED_ATT)));
	PyModule_AddObject(m, "WERR_DS_ATT_NOT_DEF_FOR_CLASS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_ATT_NOT_DEF_FOR_CLASS)));
	PyModule_AddObject(m, "WERR_DS_ATT_ALREADY_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_ATT_ALREADY_EXISTS)));
	PyModule_AddObject(m, "WERR_DS_CANT_ADD_ATT_VALUES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_ADD_ATT_VALUES)));
	PyModule_AddObject(m, "WERR_DS_SINGLE_VALUE_CONSTRAINT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SINGLE_VALUE_CONSTRAINT)));
	PyModule_AddObject(m, "WERR_DS_RANGE_CONSTRAINT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_RANGE_CONSTRAINT)));
	PyModule_AddObject(m, "WERR_DS_ATT_VAL_ALREADY_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_ATT_VAL_ALREADY_EXISTS)));
	PyModule_AddObject(m, "WERR_DS_CANT_REM_MISSING_ATT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_REM_MISSING_ATT)));
	PyModule_AddObject(m, "WERR_DS_CANT_REM_MISSING_ATT_VAL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_REM_MISSING_ATT_VAL)));
	PyModule_AddObject(m, "WERR_DS_ROOT_CANT_BE_SUBREF",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_ROOT_CANT_BE_SUBREF)));
	PyModule_AddObject(m, "WERR_DS_NO_CHAINING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NO_CHAINING)));
	PyModule_AddObject(m, "WERR_DS_NO_CHAINED_EVAL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NO_CHAINED_EVAL)));
	PyModule_AddObject(m, "WERR_DS_NO_PARENT_OBJECT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NO_PARENT_OBJECT)));
	PyModule_AddObject(m, "WERR_DS_PARENT_IS_AN_ALIAS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_PARENT_IS_AN_ALIAS)));
	PyModule_AddObject(m, "WERR_DS_CANT_MIX_MASTER_AND_REPS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_MIX_MASTER_AND_REPS)));
	PyModule_AddObject(m, "WERR_DS_CHILDREN_EXIST",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CHILDREN_EXIST)));
	PyModule_AddObject(m, "WERR_DS_OBJ_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_OBJ_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_DS_ALIASED_OBJ_MISSING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_ALIASED_OBJ_MISSING)));
	PyModule_AddObject(m, "WERR_DS_BAD_NAME_SYNTAX",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_BAD_NAME_SYNTAX)));
	PyModule_AddObject(m, "WERR_DS_ALIAS_POINTS_TO_ALIAS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_ALIAS_POINTS_TO_ALIAS)));
	PyModule_AddObject(m, "WERR_DS_CANT_DEREF_ALIAS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_DEREF_ALIAS)));
	PyModule_AddObject(m, "WERR_DS_OUT_OF_SCOPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_OUT_OF_SCOPE)));
	PyModule_AddObject(m, "WERR_DS_OBJECT_BEING_REMOVED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_OBJECT_BEING_REMOVED)));
	PyModule_AddObject(m, "WERR_DS_CANT_DELETE_DSA_OBJ",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_DELETE_DSA_OBJ)));
	PyModule_AddObject(m, "WERR_DS_GENERIC_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_GENERIC_ERROR)));
	PyModule_AddObject(m, "WERR_DS_DSA_MUST_BE_INT_MASTER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DSA_MUST_BE_INT_MASTER)));
	PyModule_AddObject(m, "WERR_DS_CLASS_NOT_DSA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CLASS_NOT_DSA)));
	PyModule_AddObject(m, "WERR_DS_INSUFF_ACCESS_RIGHTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_INSUFF_ACCESS_RIGHTS)));
	PyModule_AddObject(m, "WERR_DS_ILLEGAL_SUPERIOR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_ILLEGAL_SUPERIOR)));
	PyModule_AddObject(m, "WERR_DS_ATTRIBUTE_OWNED_BY_SAM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_ATTRIBUTE_OWNED_BY_SAM)));
	PyModule_AddObject(m, "WERR_DS_NAME_TOO_MANY_PARTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NAME_TOO_MANY_PARTS)));
	PyModule_AddObject(m, "WERR_DS_NAME_TOO_LONG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NAME_TOO_LONG)));
	PyModule_AddObject(m, "WERR_DS_NAME_VALUE_TOO_LONG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NAME_VALUE_TOO_LONG)));
	PyModule_AddObject(m, "WERR_DS_NAME_UNPARSEABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NAME_UNPARSEABLE)));
	PyModule_AddObject(m, "WERR_DS_NAME_TYPE_UNKNOWN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NAME_TYPE_UNKNOWN)));
	PyModule_AddObject(m, "WERR_DS_NOT_AN_OBJECT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NOT_AN_OBJECT)));
	PyModule_AddObject(m, "WERR_DS_SEC_DESC_TOO_SHORT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SEC_DESC_TOO_SHORT)));
	PyModule_AddObject(m, "WERR_DS_SEC_DESC_INVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SEC_DESC_INVALID)));
	PyModule_AddObject(m, "WERR_DS_NO_DELETED_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NO_DELETED_NAME)));
	PyModule_AddObject(m, "WERR_DS_SUBREF_MUST_HAVE_PARENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SUBREF_MUST_HAVE_PARENT)));
	PyModule_AddObject(m, "WERR_DS_NCNAME_MUST_BE_NC",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NCNAME_MUST_BE_NC)));
	PyModule_AddObject(m, "WERR_DS_CANT_ADD_SYSTEM_ONLY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_ADD_SYSTEM_ONLY)));
	PyModule_AddObject(m, "WERR_DS_CLASS_MUST_BE_CONCRETE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CLASS_MUST_BE_CONCRETE)));
	PyModule_AddObject(m, "WERR_DS_INVALID_DMD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_INVALID_DMD)));
	PyModule_AddObject(m, "WERR_DS_OBJ_GUID_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_OBJ_GUID_EXISTS)));
	PyModule_AddObject(m, "WERR_DS_NOT_ON_BACKLINK",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NOT_ON_BACKLINK)));
	PyModule_AddObject(m, "WERR_DS_NO_CROSSREF_FOR_NC",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NO_CROSSREF_FOR_NC)));
	PyModule_AddObject(m, "WERR_DS_SHUTTING_DOWN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SHUTTING_DOWN)));
	PyModule_AddObject(m, "WERR_DS_UNKNOWN_OPERATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_UNKNOWN_OPERATION)));
	PyModule_AddObject(m, "WERR_DS_INVALID_ROLE_OWNER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_INVALID_ROLE_OWNER)));
	PyModule_AddObject(m, "WERR_DS_COULDNT_CONTACT_FSMO",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_COULDNT_CONTACT_FSMO)));
	PyModule_AddObject(m, "WERR_DS_CROSS_NC_DN_RENAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CROSS_NC_DN_RENAME)));
	PyModule_AddObject(m, "WERR_DS_CANT_MOD_SYSTEM_ONLY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_MOD_SYSTEM_ONLY)));
	PyModule_AddObject(m, "WERR_DS_REPLICATOR_ONLY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_REPLICATOR_ONLY)));
	PyModule_AddObject(m, "WERR_DS_OBJ_CLASS_NOT_DEFINED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_OBJ_CLASS_NOT_DEFINED)));
	PyModule_AddObject(m, "WERR_DS_OBJ_CLASS_NOT_SUBCLASS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_OBJ_CLASS_NOT_SUBCLASS)));
	PyModule_AddObject(m, "WERR_DS_NAME_REFERENCE_INVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NAME_REFERENCE_INVALID)));
	PyModule_AddObject(m, "WERR_DS_CROSS_REF_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CROSS_REF_EXISTS)));
	PyModule_AddObject(m, "WERR_DS_CANT_DEL_MASTER_CROSSREF",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_DEL_MASTER_CROSSREF)));
	PyModule_AddObject(m, "WERR_DS_SUBTREE_NOTIFY_NOT_NC_HEAD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SUBTREE_NOTIFY_NOT_NC_HEAD)));
	PyModule_AddObject(m, "WERR_DS_NOTIFY_FILTER_TOO_COMPLEX",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NOTIFY_FILTER_TOO_COMPLEX)));
	PyModule_AddObject(m, "WERR_DS_DUP_RDN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DUP_RDN)));
	PyModule_AddObject(m, "WERR_DS_DUP_OID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DUP_OID)));
	PyModule_AddObject(m, "WERR_DS_DUP_MAPI_ID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DUP_MAPI_ID)));
	PyModule_AddObject(m, "WERR_DS_DUP_SCHEMA_ID_GUID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DUP_SCHEMA_ID_GUID)));
	PyModule_AddObject(m, "WERR_DS_DUP_LDAP_DISPLAY_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DUP_LDAP_DISPLAY_NAME)));
	PyModule_AddObject(m, "WERR_DS_SEMANTIC_ATT_TEST",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SEMANTIC_ATT_TEST)));
	PyModule_AddObject(m, "WERR_DS_SYNTAX_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SYNTAX_MISMATCH)));
	PyModule_AddObject(m, "WERR_DS_EXISTS_IN_MUST_HAVE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_EXISTS_IN_MUST_HAVE)));
	PyModule_AddObject(m, "WERR_DS_EXISTS_IN_MAY_HAVE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_EXISTS_IN_MAY_HAVE)));
	PyModule_AddObject(m, "WERR_DS_NONEXISTENT_MAY_HAVE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NONEXISTENT_MAY_HAVE)));
	PyModule_AddObject(m, "WERR_DS_NONEXISTENT_MUST_HAVE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NONEXISTENT_MUST_HAVE)));
	PyModule_AddObject(m, "WERR_DS_AUX_CLS_TEST_FAIL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_AUX_CLS_TEST_FAIL)));
	PyModule_AddObject(m, "WERR_DS_NONEXISTENT_POSS_SUP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NONEXISTENT_POSS_SUP)));
	PyModule_AddObject(m, "WERR_DS_SUB_CLS_TEST_FAIL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SUB_CLS_TEST_FAIL)));
	PyModule_AddObject(m, "WERR_DS_BAD_RDN_ATT_ID_SYNTAX",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_BAD_RDN_ATT_ID_SYNTAX)));
	PyModule_AddObject(m, "WERR_DS_EXISTS_IN_AUX_CLS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_EXISTS_IN_AUX_CLS)));
	PyModule_AddObject(m, "WERR_DS_EXISTS_IN_SUB_CLS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_EXISTS_IN_SUB_CLS)));
	PyModule_AddObject(m, "WERR_DS_EXISTS_IN_POSS_SUP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_EXISTS_IN_POSS_SUP)));
	PyModule_AddObject(m, "WERR_DS_RECALCSCHEMA_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_RECALCSCHEMA_FAILED)));
	PyModule_AddObject(m, "WERR_DS_TREE_DELETE_NOT_FINISHED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_TREE_DELETE_NOT_FINISHED)));
	PyModule_AddObject(m, "WERR_DS_CANT_DELETE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_DELETE)));
	PyModule_AddObject(m, "WERR_DS_ATT_SCHEMA_REQ_ID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_ATT_SCHEMA_REQ_ID)));
	PyModule_AddObject(m, "WERR_DS_BAD_ATT_SCHEMA_SYNTAX",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_BAD_ATT_SCHEMA_SYNTAX)));
	PyModule_AddObject(m, "WERR_DS_CANT_CACHE_ATT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_CACHE_ATT)));
	PyModule_AddObject(m, "WERR_DS_CANT_CACHE_CLASS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_CACHE_CLASS)));
	PyModule_AddObject(m, "WERR_DS_CANT_REMOVE_ATT_CACHE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_REMOVE_ATT_CACHE)));
	PyModule_AddObject(m, "WERR_DS_CANT_REMOVE_CLASS_CACHE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_REMOVE_CLASS_CACHE)));
	PyModule_AddObject(m, "WERR_DS_CANT_RETRIEVE_DN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_RETRIEVE_DN)));
	PyModule_AddObject(m, "WERR_DS_MISSING_SUPREF",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_MISSING_SUPREF)));
	PyModule_AddObject(m, "WERR_DS_CANT_RETRIEVE_INSTANCE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_RETRIEVE_INSTANCE)));
	PyModule_AddObject(m, "WERR_DS_CODE_INCONSISTENCY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CODE_INCONSISTENCY)));
	PyModule_AddObject(m, "WERR_DS_DATABASE_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DATABASE_ERROR)));
	PyModule_AddObject(m, "WERR_DS_GOVERNSID_MISSING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_GOVERNSID_MISSING)));
	PyModule_AddObject(m, "WERR_DS_MISSING_EXPECTED_ATT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_MISSING_EXPECTED_ATT)));
	PyModule_AddObject(m, "WERR_DS_NCNAME_MISSING_CR_REF",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NCNAME_MISSING_CR_REF)));
	PyModule_AddObject(m, "WERR_DS_SECURITY_CHECKING_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SECURITY_CHECKING_ERROR)));
	PyModule_AddObject(m, "WERR_DS_SCHEMA_NOT_LOADED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SCHEMA_NOT_LOADED)));
	PyModule_AddObject(m, "WERR_DS_SCHEMA_ALLOC_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SCHEMA_ALLOC_FAILED)));
	PyModule_AddObject(m, "WERR_DS_ATT_SCHEMA_REQ_SYNTAX",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_ATT_SCHEMA_REQ_SYNTAX)));
	PyModule_AddObject(m, "WERR_DS_GCVERIFY_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_GCVERIFY_ERROR)));
	PyModule_AddObject(m, "WERR_DS_DRA_SCHEMA_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_SCHEMA_MISMATCH)));
	PyModule_AddObject(m, "WERR_DS_CANT_FIND_DSA_OBJ",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_FIND_DSA_OBJ)));
	PyModule_AddObject(m, "WERR_DS_CANT_FIND_EXPECTED_NC",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_FIND_EXPECTED_NC)));
	PyModule_AddObject(m, "WERR_DS_CANT_FIND_NC_IN_CACHE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_FIND_NC_IN_CACHE)));
	PyModule_AddObject(m, "WERR_DS_CANT_RETRIEVE_CHILD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_RETRIEVE_CHILD)));
	PyModule_AddObject(m, "WERR_DS_SECURITY_ILLEGAL_MODIFY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SECURITY_ILLEGAL_MODIFY)));
	PyModule_AddObject(m, "WERR_DS_CANT_REPLACE_HIDDEN_REC",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_REPLACE_HIDDEN_REC)));
	PyModule_AddObject(m, "WERR_DS_BAD_HIERARCHY_FILE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_BAD_HIERARCHY_FILE)));
	PyModule_AddObject(m, "WERR_DS_BUILD_HIERARCHY_TABLE_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_BUILD_HIERARCHY_TABLE_FAILED)));
	PyModule_AddObject(m, "WERR_DS_CONFIG_PARAM_MISSING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CONFIG_PARAM_MISSING)));
	PyModule_AddObject(m, "WERR_DS_COUNTING_AB_INDICES_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_COUNTING_AB_INDICES_FAILED)));
	PyModule_AddObject(m, "WERR_DS_HIERARCHY_TABLE_MALLOC_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_HIERARCHY_TABLE_MALLOC_FAILED)));
	PyModule_AddObject(m, "WERR_DS_INTERNAL_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_INTERNAL_FAILURE)));
	PyModule_AddObject(m, "WERR_DS_UNKNOWN_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_UNKNOWN_ERROR)));
	PyModule_AddObject(m, "WERR_DS_ROOT_REQUIRES_CLASS_TOP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_ROOT_REQUIRES_CLASS_TOP)));
	PyModule_AddObject(m, "WERR_DS_REFUSING_FSMO_ROLES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_REFUSING_FSMO_ROLES)));
	PyModule_AddObject(m, "WERR_DS_MISSING_FSMO_SETTINGS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_MISSING_FSMO_SETTINGS)));
	PyModule_AddObject(m, "WERR_DS_UNABLE_TO_SURRENDER_ROLES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_UNABLE_TO_SURRENDER_ROLES)));
	PyModule_AddObject(m, "WERR_DS_DRA_GENERIC",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_GENERIC)));
	PyModule_AddObject(m, "WERR_DS_DRA_INVALID_PARAMETER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_INVALID_PARAMETER)));
	PyModule_AddObject(m, "WERR_DS_DRA_BUSY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_BUSY)));
	PyModule_AddObject(m, "WERR_DS_DRA_BAD_DN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_BAD_DN)));
	PyModule_AddObject(m, "WERR_DS_DRA_BAD_NC",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_BAD_NC)));
	PyModule_AddObject(m, "WERR_DS_DRA_DN_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_DN_EXISTS)));
	PyModule_AddObject(m, "WERR_DS_DRA_INTERNAL_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_INTERNAL_ERROR)));
	PyModule_AddObject(m, "WERR_DS_DRA_INCONSISTENT_DIT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_INCONSISTENT_DIT)));
	PyModule_AddObject(m, "WERR_DS_DRA_CONNECTION_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_CONNECTION_FAILED)));
	PyModule_AddObject(m, "WERR_DS_DRA_BAD_INSTANCE_TYPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_BAD_INSTANCE_TYPE)));
	PyModule_AddObject(m, "WERR_DS_DRA_OUT_OF_MEM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_OUT_OF_MEM)));
	PyModule_AddObject(m, "WERR_DS_DRA_MAIL_PROBLEM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_MAIL_PROBLEM)));
	PyModule_AddObject(m, "WERR_DS_DRA_REF_ALREADY_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_REF_ALREADY_EXISTS)));
	PyModule_AddObject(m, "WERR_DS_DRA_REF_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_REF_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_DS_DRA_OBJ_IS_REP_SOURCE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_OBJ_IS_REP_SOURCE)));
	PyModule_AddObject(m, "WERR_DS_DRA_DB_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_DB_ERROR)));
	PyModule_AddObject(m, "WERR_DS_DRA_NO_REPLICA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_NO_REPLICA)));
	PyModule_AddObject(m, "WERR_DS_DRA_ACCESS_DENIED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_ACCESS_DENIED)));
	PyModule_AddObject(m, "WERR_DS_DRA_NOT_SUPPORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_NOT_SUPPORTED)));
	PyModule_AddObject(m, "WERR_DS_DRA_RPC_CANCELLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_RPC_CANCELLED)));
	PyModule_AddObject(m, "WERR_DS_DRA_SOURCE_DISABLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_SOURCE_DISABLED)));
	PyModule_AddObject(m, "WERR_DS_DRA_SINK_DISABLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_SINK_DISABLED)));
	PyModule_AddObject(m, "WERR_DS_DRA_NAME_COLLISION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_NAME_COLLISION)));
	PyModule_AddObject(m, "WERR_DS_DRA_SOURCE_REINSTALLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_SOURCE_REINSTALLED)));
	PyModule_AddObject(m, "WERR_DS_DRA_MISSING_PARENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_MISSING_PARENT)));
	PyModule_AddObject(m, "WERR_DS_DRA_PREEMPTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_PREEMPTED)));
	PyModule_AddObject(m, "WERR_DS_DRA_ABANDON_SYNC",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_ABANDON_SYNC)));
	PyModule_AddObject(m, "WERR_DS_DRA_SHUTDOWN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_SHUTDOWN)));
	PyModule_AddObject(m, "WERR_DS_DRA_INCOMPATIBLE_PARTIAL_SET",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_INCOMPATIBLE_PARTIAL_SET)));
	PyModule_AddObject(m, "WERR_DS_DRA_SOURCE_IS_PARTIAL_REPLICA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_SOURCE_IS_PARTIAL_REPLICA)));
	PyModule_AddObject(m, "WERR_DS_DRA_EXTN_CONNECTION_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_EXTN_CONNECTION_FAILED)));
	PyModule_AddObject(m, "WERR_DS_INSTALL_SCHEMA_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_INSTALL_SCHEMA_MISMATCH)));
	PyModule_AddObject(m, "WERR_DS_DUP_LINK_ID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DUP_LINK_ID)));
	PyModule_AddObject(m, "WERR_DS_NAME_ERROR_RESOLVING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NAME_ERROR_RESOLVING)));
	PyModule_AddObject(m, "WERR_DS_NAME_ERROR_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NAME_ERROR_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_DS_NAME_ERROR_NOT_UNIQUE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NAME_ERROR_NOT_UNIQUE)));
	PyModule_AddObject(m, "WERR_DS_NAME_ERROR_NO_MAPPING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NAME_ERROR_NO_MAPPING)));
	PyModule_AddObject(m, "WERR_DS_NAME_ERROR_DOMAIN_ONLY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NAME_ERROR_DOMAIN_ONLY)));
	PyModule_AddObject(m, "WERR_DS_NAME_ERROR_NO_SYNTACTICAL_MAPPING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NAME_ERROR_NO_SYNTACTICAL_MAPPING)));
	PyModule_AddObject(m, "WERR_DS_CONSTRUCTED_ATT_MOD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CONSTRUCTED_ATT_MOD)));
	PyModule_AddObject(m, "WERR_DS_WRONG_OM_OBJ_CLASS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_WRONG_OM_OBJ_CLASS)));
	PyModule_AddObject(m, "WERR_DS_DRA_REPL_PENDING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_REPL_PENDING)));
	PyModule_AddObject(m, "WERR_DS_DS_REQUIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DS_REQUIRED)));
	PyModule_AddObject(m, "WERR_DS_INVALID_LDAP_DISPLAY_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_INVALID_LDAP_DISPLAY_NAME)));
	PyModule_AddObject(m, "WERR_DS_NON_BASE_SEARCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NON_BASE_SEARCH)));
	PyModule_AddObject(m, "WERR_DS_CANT_RETRIEVE_ATTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_RETRIEVE_ATTS)));
	PyModule_AddObject(m, "WERR_DS_BACKLINK_WITHOUT_LINK",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_BACKLINK_WITHOUT_LINK)));
	PyModule_AddObject(m, "WERR_DS_EPOCH_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_EPOCH_MISMATCH)));
	PyModule_AddObject(m, "WERR_DS_SRC_NAME_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SRC_NAME_MISMATCH)));
	PyModule_AddObject(m, "WERR_DS_SRC_AND_DST_NC_IDENTICAL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SRC_AND_DST_NC_IDENTICAL)));
	PyModule_AddObject(m, "WERR_DS_DST_NC_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DST_NC_MISMATCH)));
	PyModule_AddObject(m, "WERR_DS_NOT_AUTHORITIVE_FOR_DST_NC",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NOT_AUTHORITIVE_FOR_DST_NC)));
	PyModule_AddObject(m, "WERR_DS_SRC_GUID_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SRC_GUID_MISMATCH)));
	PyModule_AddObject(m, "WERR_DS_CANT_MOVE_DELETED_OBJECT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_MOVE_DELETED_OBJECT)));
	PyModule_AddObject(m, "WERR_DS_PDC_OPERATION_IN_PROGRESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_PDC_OPERATION_IN_PROGRESS)));
	PyModule_AddObject(m, "WERR_DS_CROSS_DOMAIN_CLEANUP_REQD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CROSS_DOMAIN_CLEANUP_REQD)));
	PyModule_AddObject(m, "WERR_DS_ILLEGAL_XDOM_MOVE_OPERATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_ILLEGAL_XDOM_MOVE_OPERATION)));
	PyModule_AddObject(m, "WERR_DS_CANT_WITH_ACCT_GROUP_MEMBERSHPS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_WITH_ACCT_GROUP_MEMBERSHPS)));
	PyModule_AddObject(m, "WERR_DS_NC_MUST_HAVE_NC_PARENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NC_MUST_HAVE_NC_PARENT)));
	PyModule_AddObject(m, "WERR_DS_CR_IMPOSSIBLE_TO_VALIDATE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CR_IMPOSSIBLE_TO_VALIDATE)));
	PyModule_AddObject(m, "WERR_DS_DST_DOMAIN_NOT_NATIVE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DST_DOMAIN_NOT_NATIVE)));
	PyModule_AddObject(m, "WERR_DS_MISSING_INFRASTRUCTURE_CONTAINER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_MISSING_INFRASTRUCTURE_CONTAINER)));
	PyModule_AddObject(m, "WERR_DS_CANT_MOVE_ACCOUNT_GROUP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_MOVE_ACCOUNT_GROUP)));
	PyModule_AddObject(m, "WERR_DS_CANT_MOVE_RESOURCE_GROUP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_MOVE_RESOURCE_GROUP)));
	PyModule_AddObject(m, "WERR_DS_INVALID_SEARCH_FLAG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_INVALID_SEARCH_FLAG)));
	PyModule_AddObject(m, "WERR_DS_NO_TREE_DELETE_ABOVE_NC",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NO_TREE_DELETE_ABOVE_NC)));
	PyModule_AddObject(m, "WERR_DS_COULDNT_LOCK_TREE_FOR_DELETE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_COULDNT_LOCK_TREE_FOR_DELETE)));
	PyModule_AddObject(m, "WERR_DS_COULDNT_IDENTIFY_OBJECTS_FOR_TREE_DELETE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_COULDNT_IDENTIFY_OBJECTS_FOR_TREE_DELETE)));
	PyModule_AddObject(m, "WERR_DS_SAM_INIT_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SAM_INIT_FAILURE)));
	PyModule_AddObject(m, "WERR_DS_SENSITIVE_GROUP_VIOLATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SENSITIVE_GROUP_VIOLATION)));
	PyModule_AddObject(m, "WERR_DS_CANT_MOD_PRIMARYGROUPID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_MOD_PRIMARYGROUPID)));
	PyModule_AddObject(m, "WERR_DS_ILLEGAL_BASE_SCHEMA_MOD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_ILLEGAL_BASE_SCHEMA_MOD)));
	PyModule_AddObject(m, "WERR_DS_NONSAFE_SCHEMA_CHANGE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NONSAFE_SCHEMA_CHANGE)));
	PyModule_AddObject(m, "WERR_DS_SCHEMA_UPDATE_DISALLOWED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SCHEMA_UPDATE_DISALLOWED)));
	PyModule_AddObject(m, "WERR_DS_CANT_CREATE_UNDER_SCHEMA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_CREATE_UNDER_SCHEMA)));
	PyModule_AddObject(m, "WERR_DS_INSTALL_NO_SRC_SCH_VERSION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_INSTALL_NO_SRC_SCH_VERSION)));
	PyModule_AddObject(m, "WERR_DS_INSTALL_NO_SCH_VERSION_IN_INIFILE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_INSTALL_NO_SCH_VERSION_IN_INIFILE)));
	PyModule_AddObject(m, "WERR_DS_INVALID_GROUP_TYPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_INVALID_GROUP_TYPE)));
	PyModule_AddObject(m, "WERR_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN)));
	PyModule_AddObject(m, "WERR_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN)));
	PyModule_AddObject(m, "WERR_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER)));
	PyModule_AddObject(m, "WERR_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER)));
	PyModule_AddObject(m, "WERR_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER)));
	PyModule_AddObject(m, "WERR_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER)));
	PyModule_AddObject(m, "WERR_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER)));
	PyModule_AddObject(m, "WERR_DS_HAVE_PRIMARY_MEMBERS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_HAVE_PRIMARY_MEMBERS)));
	PyModule_AddObject(m, "WERR_DS_STRING_SD_CONVERSION_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_STRING_SD_CONVERSION_FAILED)));
	PyModule_AddObject(m, "WERR_DS_NAMING_MASTER_GC",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NAMING_MASTER_GC)));
	PyModule_AddObject(m, "WERR_DS_DNS_LOOKUP_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DNS_LOOKUP_FAILURE)));
	PyModule_AddObject(m, "WERR_DS_COULDNT_UPDATE_SPNS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_COULDNT_UPDATE_SPNS)));
	PyModule_AddObject(m, "WERR_DS_CANT_RETRIEVE_SD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_RETRIEVE_SD)));
	PyModule_AddObject(m, "WERR_DS_KEY_NOT_UNIQUE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_KEY_NOT_UNIQUE)));
	PyModule_AddObject(m, "WERR_DS_WRONG_LINKED_ATT_SYNTAX",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_WRONG_LINKED_ATT_SYNTAX)));
	PyModule_AddObject(m, "WERR_DS_SAM_NEED_BOOTKEY_PASSWORD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SAM_NEED_BOOTKEY_PASSWORD)));
	PyModule_AddObject(m, "WERR_DS_SAM_NEED_BOOTKEY_FLOPPY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SAM_NEED_BOOTKEY_FLOPPY)));
	PyModule_AddObject(m, "WERR_DS_CANT_START",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_START)));
	PyModule_AddObject(m, "WERR_DS_INIT_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_INIT_FAILURE)));
	PyModule_AddObject(m, "WERR_DS_NO_PKT_PRIVACY_ON_CONNECTION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NO_PKT_PRIVACY_ON_CONNECTION)));
	PyModule_AddObject(m, "WERR_DS_SOURCE_DOMAIN_IN_FOREST",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SOURCE_DOMAIN_IN_FOREST)));
	PyModule_AddObject(m, "WERR_DS_DESTINATION_DOMAIN_NOT_IN_FOREST",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DESTINATION_DOMAIN_NOT_IN_FOREST)));
	PyModule_AddObject(m, "WERR_DS_DESTINATION_AUDITING_NOT_ENABLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DESTINATION_AUDITING_NOT_ENABLED)));
	PyModule_AddObject(m, "WERR_DS_CANT_FIND_DC_FOR_SRC_DOMAIN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_FIND_DC_FOR_SRC_DOMAIN)));
	PyModule_AddObject(m, "WERR_DS_SRC_OBJ_NOT_GROUP_OR_USER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SRC_OBJ_NOT_GROUP_OR_USER)));
	PyModule_AddObject(m, "WERR_DS_SRC_SID_EXISTS_IN_FOREST",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SRC_SID_EXISTS_IN_FOREST)));
	PyModule_AddObject(m, "WERR_DS_SRC_AND_DST_OBJECT_CLASS_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SRC_AND_DST_OBJECT_CLASS_MISMATCH)));
	PyModule_AddObject(m, "WERR_SAM_INIT_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SAM_INIT_FAILURE)));
	PyModule_AddObject(m, "WERR_DS_DRA_SCHEMA_INFO_SHIP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_SCHEMA_INFO_SHIP)));
	PyModule_AddObject(m, "WERR_DS_DRA_SCHEMA_CONFLICT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_SCHEMA_CONFLICT)));
	PyModule_AddObject(m, "WERR_DS_DRA_EARLIER_SCHEMA_CONFLICT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_EARLIER_SCHEMA_CONFLICT)));
	PyModule_AddObject(m, "WERR_DS_DRA_OBJ_NC_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_OBJ_NC_MISMATCH)));
	PyModule_AddObject(m, "WERR_DS_NC_STILL_HAS_DSAS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NC_STILL_HAS_DSAS)));
	PyModule_AddObject(m, "WERR_DS_GC_REQUIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_GC_REQUIRED)));
	PyModule_AddObject(m, "WERR_DS_LOCAL_MEMBER_OF_LOCAL_ONLY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_LOCAL_MEMBER_OF_LOCAL_ONLY)));
	PyModule_AddObject(m, "WERR_DS_NO_FPO_IN_UNIVERSAL_GROUPS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NO_FPO_IN_UNIVERSAL_GROUPS)));
	PyModule_AddObject(m, "WERR_DS_CANT_ADD_TO_GC",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_ADD_TO_GC)));
	PyModule_AddObject(m, "WERR_DS_NO_CHECKPOINT_WITH_PDC",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NO_CHECKPOINT_WITH_PDC)));
	PyModule_AddObject(m, "WERR_DS_SOURCE_AUDITING_NOT_ENABLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SOURCE_AUDITING_NOT_ENABLED)));
	PyModule_AddObject(m, "WERR_DS_CANT_CREATE_IN_NONDOMAIN_NC",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_CREATE_IN_NONDOMAIN_NC)));
	PyModule_AddObject(m, "WERR_DS_INVALID_NAME_FOR_SPN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_INVALID_NAME_FOR_SPN)));
	PyModule_AddObject(m, "WERR_DS_FILTER_USES_CONTRUCTED_ATTRS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_FILTER_USES_CONTRUCTED_ATTRS)));
	PyModule_AddObject(m, "WERR_DS_UNICODEPWD_NOT_IN_QUOTES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_UNICODEPWD_NOT_IN_QUOTES)));
	PyModule_AddObject(m, "WERR_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED)));
	PyModule_AddObject(m, "WERR_DS_MUST_BE_RUN_ON_DST_DC",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_MUST_BE_RUN_ON_DST_DC)));
	PyModule_AddObject(m, "WERR_DS_SRC_DC_MUST_BE_SP4_OR_GREATER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SRC_DC_MUST_BE_SP4_OR_GREATER)));
	PyModule_AddObject(m, "WERR_DS_CANT_TREE_DELETE_CRITICAL_OBJ",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_TREE_DELETE_CRITICAL_OBJ)));
	PyModule_AddObject(m, "WERR_DS_INIT_FAILURE_CONSOLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_INIT_FAILURE_CONSOLE)));
	PyModule_AddObject(m, "WERR_DS_SAM_INIT_FAILURE_CONSOLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SAM_INIT_FAILURE_CONSOLE)));
	PyModule_AddObject(m, "WERR_DS_FOREST_VERSION_TOO_HIGH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_FOREST_VERSION_TOO_HIGH)));
	PyModule_AddObject(m, "WERR_DS_DOMAIN_VERSION_TOO_HIGH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DOMAIN_VERSION_TOO_HIGH)));
	PyModule_AddObject(m, "WERR_DS_FOREST_VERSION_TOO_LOW",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_FOREST_VERSION_TOO_LOW)));
	PyModule_AddObject(m, "WERR_DS_DOMAIN_VERSION_TOO_LOW",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DOMAIN_VERSION_TOO_LOW)));
	PyModule_AddObject(m, "WERR_DS_INCOMPATIBLE_VERSION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_INCOMPATIBLE_VERSION)));
	PyModule_AddObject(m, "WERR_DS_LOW_DSA_VERSION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_LOW_DSA_VERSION)));
	PyModule_AddObject(m, "WERR_DS_NO_BEHAVIOR_VERSION_IN_MIXEDDOMAIN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NO_BEHAVIOR_VERSION_IN_MIXEDDOMAIN)));
	PyModule_AddObject(m, "WERR_DS_NOT_SUPPORTED_SORT_ORDER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NOT_SUPPORTED_SORT_ORDER)));
	PyModule_AddObject(m, "WERR_DS_NAME_NOT_UNIQUE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NAME_NOT_UNIQUE)));
	PyModule_AddObject(m, "WERR_DS_MACHINE_ACCOUNT_CREATED_PRENT4",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_MACHINE_ACCOUNT_CREATED_PRENT4)));
	PyModule_AddObject(m, "WERR_DS_OUT_OF_VERSION_STORE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_OUT_OF_VERSION_STORE)));
	PyModule_AddObject(m, "WERR_DS_INCOMPATIBLE_CONTROLS_USED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_INCOMPATIBLE_CONTROLS_USED)));
	PyModule_AddObject(m, "WERR_DS_NO_REF_DOMAIN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NO_REF_DOMAIN)));
	PyModule_AddObject(m, "WERR_DS_RESERVED_LINK_ID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_RESERVED_LINK_ID)));
	PyModule_AddObject(m, "WERR_DS_LINK_ID_NOT_AVAILABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_LINK_ID_NOT_AVAILABLE)));
	PyModule_AddObject(m, "WERR_DS_AG_CANT_HAVE_UNIVERSAL_MEMBER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_AG_CANT_HAVE_UNIVERSAL_MEMBER)));
	PyModule_AddObject(m, "WERR_DS_MODIFYDN_DISALLOWED_BY_INSTANCE_TYPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_MODIFYDN_DISALLOWED_BY_INSTANCE_TYPE)));
	PyModule_AddObject(m, "WERR_DS_NO_OBJECT_MOVE_IN_SCHEMA_NC",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NO_OBJECT_MOVE_IN_SCHEMA_NC)));
	PyModule_AddObject(m, "WERR_DS_MODIFYDN_DISALLOWED_BY_FLAG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_MODIFYDN_DISALLOWED_BY_FLAG)));
	PyModule_AddObject(m, "WERR_DS_MODIFYDN_WRONG_GRANDPARENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_MODIFYDN_WRONG_GRANDPARENT)));
	PyModule_AddObject(m, "WERR_DS_NAME_ERROR_TRUST_REFERRAL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NAME_ERROR_TRUST_REFERRAL)));
	PyModule_AddObject(m, "WERR_NOT_SUPPORTED_ON_STANDARD_SERVER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NOT_SUPPORTED_ON_STANDARD_SERVER)));
	PyModule_AddObject(m, "WERR_DS_CANT_ACCESS_REMOTE_PART_OF_AD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_ACCESS_REMOTE_PART_OF_AD)));
	PyModule_AddObject(m, "WERR_DS_CR_IMPOSSIBLE_TO_VALIDATE_V2",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CR_IMPOSSIBLE_TO_VALIDATE_V2)));
	PyModule_AddObject(m, "WERR_DS_THREAD_LIMIT_EXCEEDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_THREAD_LIMIT_EXCEEDED)));
	PyModule_AddObject(m, "WERR_DS_NOT_CLOSEST",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NOT_CLOSEST)));
	PyModule_AddObject(m, "WERR_DS_CANT_DERIVE_SPN_WITHOUT_SERVER_REF",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_DERIVE_SPN_WITHOUT_SERVER_REF)));
	PyModule_AddObject(m, "WERR_DS_SINGLE_USER_MODE_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SINGLE_USER_MODE_FAILED)));
	PyModule_AddObject(m, "WERR_DS_NTDSCRIPT_SYNTAX_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NTDSCRIPT_SYNTAX_ERROR)));
	PyModule_AddObject(m, "WERR_DS_NTDSCRIPT_PROCESS_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NTDSCRIPT_PROCESS_ERROR)));
	PyModule_AddObject(m, "WERR_DS_DIFFERENT_REPL_EPOCHS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DIFFERENT_REPL_EPOCHS)));
	PyModule_AddObject(m, "WERR_DS_DRS_EXTENSIONS_CHANGED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRS_EXTENSIONS_CHANGED)));
	PyModule_AddObject(m, "WERR_DS_REPLICA_SET_CHANGE_NOT_ALLOWED_ON_DISABLED_CR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_REPLICA_SET_CHANGE_NOT_ALLOWED_ON_DISABLED_CR)));
	PyModule_AddObject(m, "WERR_DS_NO_MSDS_INTID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NO_MSDS_INTID)));
	PyModule_AddObject(m, "WERR_DS_DUP_MSDS_INTID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DUP_MSDS_INTID)));
	PyModule_AddObject(m, "WERR_DS_EXISTS_IN_RDNATTID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_EXISTS_IN_RDNATTID)));
	PyModule_AddObject(m, "WERR_DS_AUTHORIZATION_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_AUTHORIZATION_FAILED)));
	PyModule_AddObject(m, "WERR_DS_INVALID_SCRIPT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_INVALID_SCRIPT)));
	PyModule_AddObject(m, "WERR_DS_REMOTE_CROSSREF_OP_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_REMOTE_CROSSREF_OP_FAILED)));
	PyModule_AddObject(m, "WERR_DS_CROSS_REF_BUSY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CROSS_REF_BUSY)));
	PyModule_AddObject(m, "WERR_DS_CANT_DERIVE_SPN_FOR_DELETED_DOMAIN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_DERIVE_SPN_FOR_DELETED_DOMAIN)));
	PyModule_AddObject(m, "WERR_DS_CANT_DEMOTE_WITH_WRITEABLE_NC",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_DEMOTE_WITH_WRITEABLE_NC)));
	PyModule_AddObject(m, "WERR_DS_DUPLICATE_ID_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DUPLICATE_ID_FOUND)));
	PyModule_AddObject(m, "WERR_DS_INSUFFICIENT_ATTR_TO_CREATE_OBJECT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_INSUFFICIENT_ATTR_TO_CREATE_OBJECT)));
	PyModule_AddObject(m, "WERR_DS_GROUP_CONVERSION_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_GROUP_CONVERSION_ERROR)));
	PyModule_AddObject(m, "WERR_DS_CANT_MOVE_APP_BASIC_GROUP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_MOVE_APP_BASIC_GROUP)));
	PyModule_AddObject(m, "WERR_DS_CANT_MOVE_APP_QUERY_GROUP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_CANT_MOVE_APP_QUERY_GROUP)));
	PyModule_AddObject(m, "WERR_DS_ROLE_NOT_VERIFIED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_ROLE_NOT_VERIFIED)));
	PyModule_AddObject(m, "WERR_DS_WKO_CONTAINER_CANNOT_BE_SPECIAL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_WKO_CONTAINER_CANNOT_BE_SPECIAL)));
	PyModule_AddObject(m, "WERR_DS_DOMAIN_RENAME_IN_PROGRESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DOMAIN_RENAME_IN_PROGRESS)));
	PyModule_AddObject(m, "WERR_DS_EXISTING_AD_CHILD_NC",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_EXISTING_AD_CHILD_NC)));
	PyModule_AddObject(m, "WERR_DS_REPL_LIFETIME_EXCEEDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_REPL_LIFETIME_EXCEEDED)));
	PyModule_AddObject(m, "WERR_DS_DISALLOWED_IN_SYSTEM_CONTAINER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DISALLOWED_IN_SYSTEM_CONTAINER)));
	PyModule_AddObject(m, "WERR_DS_LDAP_SEND_QUEUE_FULL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_LDAP_SEND_QUEUE_FULL)));
	PyModule_AddObject(m, "WERR_DS_DRA_OUT_SCHEDULE_WINDOW",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_DRA_OUT_SCHEDULE_WINDOW)));
	PyModule_AddObject(m, "WERR_DS_POLICY_NOT_KNOWN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_POLICY_NOT_KNOWN)));
	PyModule_AddObject(m, "WERR_NO_SITE_SETTINGS_OBJECT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_SITE_SETTINGS_OBJECT)));
	PyModule_AddObject(m, "WERR_NO_SECRETS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_SECRETS)));
	PyModule_AddObject(m, "WERR_NO_WRITABLE_DC_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_NO_WRITABLE_DC_FOUND)));
	PyModule_AddObject(m, "WERR_DS_NO_SERVER_OBJECT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NO_SERVER_OBJECT)));
	PyModule_AddObject(m, "WERR_DS_NO_NTDSA_OBJECT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NO_NTDSA_OBJECT)));
	PyModule_AddObject(m, "WERR_DS_NON_ASQ_SEARCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_NON_ASQ_SEARCH)));
	PyModule_AddObject(m, "WERR_DS_AUDIT_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_AUDIT_FAILURE)));
	PyModule_AddObject(m, "WERR_DS_INVALID_SEARCH_FLAG_SUBTREE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_INVALID_SEARCH_FLAG_SUBTREE)));
	PyModule_AddObject(m, "WERR_DS_INVALID_SEARCH_FLAG_TUPLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_INVALID_SEARCH_FLAG_TUPLE)));
	PyModule_AddObject(m, "WERR_DS_HIGH_DSA_VERSION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_HIGH_DSA_VERSION)));
	PyModule_AddObject(m, "WERR_DS_SPN_VALUE_NOT_UNIQUE_IN_FOREST",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_SPN_VALUE_NOT_UNIQUE_IN_FOREST)));
	PyModule_AddObject(m, "WERR_DS_UPN_VALUE_NOT_UNIQUE_IN_FOREST",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DS_UPN_VALUE_NOT_UNIQUE_IN_FOREST)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_RCODE_FORMAT_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_RCODE_FORMAT_ERROR)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_RCODE_SERVER_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_RCODE_SERVER_FAILURE)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_RCODE_NAME_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_RCODE_NAME_ERROR)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_RCODE_NOT_IMPLEMENTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_RCODE_NOT_IMPLEMENTED)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_RCODE_REFUSED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_RCODE_REFUSED)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_RCODE_YXDOMAIN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_RCODE_YXDOMAIN)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_RCODE_YXRRSET",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_RCODE_YXRRSET)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_RCODE_NXRRSET",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_RCODE_NXRRSET)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_RCODE_NOTAUTH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_RCODE_NOTAUTH)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_RCODE_NOTZONE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_RCODE_NOTZONE)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_RCODE_BADSIG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_RCODE_BADSIG)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_RCODE_BADKEY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_RCODE_BADKEY)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_RCODE_BADTIME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_RCODE_BADTIME)));
	PyModule_AddObject(m, "WERR_DNS_INFO_NO_RECORDS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_INFO_NO_RECORDS)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_BAD_PACKET",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_BAD_PACKET)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_NO_PACKET",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_NO_PACKET)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_RCODE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_RCODE)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_UNSECURE_PACKET",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_UNSECURE_PACKET)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_INVALID_TYPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_INVALID_TYPE)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_INVALID_IP_ADDRESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_INVALID_IP_ADDRESS)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_INVALID_PROPERTY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_INVALID_PROPERTY)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_TRY_AGAIN_LATER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_TRY_AGAIN_LATER)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_NOT_UNIQUE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_NOT_UNIQUE)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_NON_RFC_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_NON_RFC_NAME)));
	PyModule_AddObject(m, "WERR_DNS_STATUS_FQDN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_STATUS_FQDN)));
	PyModule_AddObject(m, "WERR_DNS_STATUS_DOTTED_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_STATUS_DOTTED_NAME)));
	PyModule_AddObject(m, "WERR_DNS_STATUS_SINGLE_PART_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_STATUS_SINGLE_PART_NAME)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_INVALID_NAME_CHAR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_INVALID_NAME_CHAR)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_NUMERIC_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_NUMERIC_NAME)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_NOT_ALLOWED_ON_ROOT_SERVER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_NOT_ALLOWED_ON_ROOT_SERVER)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_NOT_ALLOWED_UNDER_DELEGATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_NOT_ALLOWED_UNDER_DELEGATION)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_CANNOT_FIND_ROOT_HINTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_CANNOT_FIND_ROOT_HINTS)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_INCONSISTENT_ROOT_HINTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_INCONSISTENT_ROOT_HINTS)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_DWORD_VALUE_TOO_SMALL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_DWORD_VALUE_TOO_SMALL)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_DWORD_VALUE_TOO_LARGE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_DWORD_VALUE_TOO_LARGE)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_BACKGROUND_LOADING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_BACKGROUND_LOADING)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_NOT_ALLOWED_ON_RODC",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_NOT_ALLOWED_ON_RODC)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_ZONE_DOES_NOT_EXIST",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_ZONE_DOES_NOT_EXIST)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_NO_ZONE_INFO",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_NO_ZONE_INFO)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_INVALID_ZONE_OPERATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_INVALID_ZONE_OPERATION)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_ZONE_CONFIGURATION_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_ZONE_CONFIGURATION_ERROR)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_ZONE_HAS_NO_SOA_RECORD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_ZONE_HAS_NO_SOA_RECORD)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_ZONE_HAS_NO_NS_RECORDS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_ZONE_HAS_NO_NS_RECORDS)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_ZONE_LOCKED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_ZONE_LOCKED)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_ZONE_CREATION_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_ZONE_CREATION_FAILED)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_ZONE_ALREADY_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_ZONE_ALREADY_EXISTS)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_AUTOZONE_ALREADY_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_AUTOZONE_ALREADY_EXISTS)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_INVALID_ZONE_TYPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_INVALID_ZONE_TYPE)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_SECONDARY_REQUIRES_MASTER_IP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_SECONDARY_REQUIRES_MASTER_IP)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_ZONE_NOT_SECONDARY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_ZONE_NOT_SECONDARY)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_NEED_SECONDARY_ADDRESSES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_NEED_SECONDARY_ADDRESSES)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_WINS_INIT_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_WINS_INIT_FAILED)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_NEED_WINS_SERVERS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_NEED_WINS_SERVERS)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_NBSTAT_INIT_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_NBSTAT_INIT_FAILED)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_SOA_DELETE_INVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_SOA_DELETE_INVALID)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_FORWARDER_ALREADY_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_FORWARDER_ALREADY_EXISTS)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_ZONE_REQUIRES_MASTER_IP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_ZONE_REQUIRES_MASTER_IP)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_ZONE_IS_SHUTDOWN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_ZONE_IS_SHUTDOWN)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_PRIMARY_REQUIRES_DATAFILE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_PRIMARY_REQUIRES_DATAFILE)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_INVALID_DATAFILE_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_INVALID_DATAFILE_NAME)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_DATAFILE_OPEN_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_DATAFILE_OPEN_FAILURE)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_FILE_WRITEBACK_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_FILE_WRITEBACK_FAILED)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_DATAFILE_PARSING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_DATAFILE_PARSING)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_RECORD_DOES_NOT_EXIST",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_RECORD_DOES_NOT_EXIST)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_RECORD_FORMAT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_RECORD_FORMAT)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_NODE_CREATION_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_NODE_CREATION_FAILED)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_UNKNOWN_RECORD_TYPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_UNKNOWN_RECORD_TYPE)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_RECORD_TIMED_OUT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_RECORD_TIMED_OUT)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_NAME_NOT_IN_ZONE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_NAME_NOT_IN_ZONE)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_CNAME_LOOP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_CNAME_LOOP)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_NODE_IS_CNAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_NODE_IS_CNAME)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_CNAME_COLLISION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_CNAME_COLLISION)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_RECORD_ONLY_AT_ZONE_ROOT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_RECORD_ONLY_AT_ZONE_ROOT)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_RECORD_ALREADY_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_RECORD_ALREADY_EXISTS)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_SECONDARY_DATA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_SECONDARY_DATA)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_NO_CREATE_CACHE_DATA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_NO_CREATE_CACHE_DATA)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_NAME_DOES_NOT_EXIST",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_NAME_DOES_NOT_EXIST)));
	PyModule_AddObject(m, "WERR_DNS_WARNING_PTR_CREATE_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_WARNING_PTR_CREATE_FAILED)));
	PyModule_AddObject(m, "WERR_DNS_WARNING_DOMAIN_UNDELETED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_WARNING_DOMAIN_UNDELETED)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_DS_UNAVAILABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_DS_UNAVAILABLE)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_DS_ZONE_ALREADY_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_DS_ZONE_ALREADY_EXISTS)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_NO_BOOTFILE_IF_DS_ZONE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_NO_BOOTFILE_IF_DS_ZONE)));
	PyModule_AddObject(m, "WERR_DNS_INFO_AXFR_COMPLETE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_INFO_AXFR_COMPLETE)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_AXFR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_AXFR)));
	PyModule_AddObject(m, "WERR_DNS_INFO_ADDED_LOCAL_WINS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_INFO_ADDED_LOCAL_WINS)));
	PyModule_AddObject(m, "WERR_DNS_STATUS_CONTINUE_NEEDED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_STATUS_CONTINUE_NEEDED)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_NO_TCPIP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_NO_TCPIP)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_NO_DNS_SERVERS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_NO_DNS_SERVERS)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_DP_DOES_NOT_EXIST",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_DP_DOES_NOT_EXIST)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_DP_ALREADY_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_DP_ALREADY_EXISTS)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_DP_NOT_ENLISTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_DP_NOT_ENLISTED)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_DP_ALREADY_ENLISTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_DP_ALREADY_ENLISTED)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_DP_NOT_AVAILABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_DP_NOT_AVAILABLE)));
	PyModule_AddObject(m, "WERR_DNS_ERROR_DP_FSMO_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_DNS_ERROR_DP_FSMO_ERROR)));
	PyModule_AddObject(m, "WERR_WSAEINTR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEINTR)));
	PyModule_AddObject(m, "WERR_WSAEBADF",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEBADF)));
	PyModule_AddObject(m, "WERR_WSAEACCES",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEACCES)));
	PyModule_AddObject(m, "WERR_WSAEFAULT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEFAULT)));
	PyModule_AddObject(m, "WERR_WSAEINVAL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEINVAL)));
	PyModule_AddObject(m, "WERR_WSAEMFILE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEMFILE)));
	PyModule_AddObject(m, "WERR_WSAEWOULDBLOCK",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEWOULDBLOCK)));
	PyModule_AddObject(m, "WERR_WSAEINPROGRESS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEINPROGRESS)));
	PyModule_AddObject(m, "WERR_WSAEALREADY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEALREADY)));
	PyModule_AddObject(m, "WERR_WSAENOTSOCK",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAENOTSOCK)));
	PyModule_AddObject(m, "WERR_WSAEDESTADDRREQ",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEDESTADDRREQ)));
	PyModule_AddObject(m, "WERR_WSAEMSGSIZE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEMSGSIZE)));
	PyModule_AddObject(m, "WERR_WSAEPROTOTYPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEPROTOTYPE)));
	PyModule_AddObject(m, "WERR_WSAENOPROTOOPT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAENOPROTOOPT)));
	PyModule_AddObject(m, "WERR_WSAEPROTONOSUPPORT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEPROTONOSUPPORT)));
	PyModule_AddObject(m, "WERR_WSAESOCKTNOSUPPORT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAESOCKTNOSUPPORT)));
	PyModule_AddObject(m, "WERR_WSAEOPNOTSUPP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEOPNOTSUPP)));
	PyModule_AddObject(m, "WERR_WSAEPFNOSUPPORT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEPFNOSUPPORT)));
	PyModule_AddObject(m, "WERR_WSAEAFNOSUPPORT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEAFNOSUPPORT)));
	PyModule_AddObject(m, "WERR_WSAEADDRINUSE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEADDRINUSE)));
	PyModule_AddObject(m, "WERR_WSAEADDRNOTAVAIL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEADDRNOTAVAIL)));
	PyModule_AddObject(m, "WERR_WSAENETDOWN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAENETDOWN)));
	PyModule_AddObject(m, "WERR_WSAENETUNREACH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAENETUNREACH)));
	PyModule_AddObject(m, "WERR_WSAENETRESET",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAENETRESET)));
	PyModule_AddObject(m, "WERR_WSAECONNABORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAECONNABORTED)));
	PyModule_AddObject(m, "WERR_WSAECONNRESET",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAECONNRESET)));
	PyModule_AddObject(m, "WERR_WSAENOBUFS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAENOBUFS)));
	PyModule_AddObject(m, "WERR_WSAEISCONN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEISCONN)));
	PyModule_AddObject(m, "WERR_WSAENOTCONN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAENOTCONN)));
	PyModule_AddObject(m, "WERR_WSAESHUTDOWN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAESHUTDOWN)));
	PyModule_AddObject(m, "WERR_WSAETOOMANYREFS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAETOOMANYREFS)));
	PyModule_AddObject(m, "WERR_WSAETIMEDOUT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAETIMEDOUT)));
	PyModule_AddObject(m, "WERR_WSAECONNREFUSED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAECONNREFUSED)));
	PyModule_AddObject(m, "WERR_WSAELOOP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAELOOP)));
	PyModule_AddObject(m, "WERR_WSAENAMETOOLONG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAENAMETOOLONG)));
	PyModule_AddObject(m, "WERR_WSAEHOSTDOWN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEHOSTDOWN)));
	PyModule_AddObject(m, "WERR_WSAEHOSTUNREACH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEHOSTUNREACH)));
	PyModule_AddObject(m, "WERR_WSAENOTEMPTY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAENOTEMPTY)));
	PyModule_AddObject(m, "WERR_WSAEPROCLIM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEPROCLIM)));
	PyModule_AddObject(m, "WERR_WSAEUSERS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEUSERS)));
	PyModule_AddObject(m, "WERR_WSAEDQUOT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEDQUOT)));
	PyModule_AddObject(m, "WERR_WSAESTALE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAESTALE)));
	PyModule_AddObject(m, "WERR_WSAEREMOTE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEREMOTE)));
	PyModule_AddObject(m, "WERR_WSASYSNOTREADY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSASYSNOTREADY)));
	PyModule_AddObject(m, "WERR_WSAVERNOTSUPPORTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAVERNOTSUPPORTED)));
	PyModule_AddObject(m, "WERR_WSANOTINITIALISED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSANOTINITIALISED)));
	PyModule_AddObject(m, "WERR_WSAEDISCON",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEDISCON)));
	PyModule_AddObject(m, "WERR_WSAENOMORE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAENOMORE)));
	PyModule_AddObject(m, "WERR_WSAECANCELLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAECANCELLED)));
	PyModule_AddObject(m, "WERR_WSAEINVALIDPROCTABLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEINVALIDPROCTABLE)));
	PyModule_AddObject(m, "WERR_WSAEINVALIDPROVIDER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEINVALIDPROVIDER)));
	PyModule_AddObject(m, "WERR_WSAEPROVIDERFAILEDINIT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEPROVIDERFAILEDINIT)));
	PyModule_AddObject(m, "WERR_WSASYSCALLFAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSASYSCALLFAILURE)));
	PyModule_AddObject(m, "WERR_WSASERVICE_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSASERVICE_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_WSATYPE_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSATYPE_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_WSA_E_NO_MORE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSA_E_NO_MORE)));
	PyModule_AddObject(m, "WERR_WSA_E_CANCELLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSA_E_CANCELLED)));
	PyModule_AddObject(m, "WERR_WSAEREFUSED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAEREFUSED)));
	PyModule_AddObject(m, "WERR_WSAHOST_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSAHOST_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_WSATRY_AGAIN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSATRY_AGAIN)));
	PyModule_AddObject(m, "WERR_WSANO_RECOVERY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSANO_RECOVERY)));
	PyModule_AddObject(m, "WERR_WSANO_DATA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSANO_DATA)));
	PyModule_AddObject(m, "WERR_WSA_QOS_RECEIVERS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSA_QOS_RECEIVERS)));
	PyModule_AddObject(m, "WERR_WSA_QOS_SENDERS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSA_QOS_SENDERS)));
	PyModule_AddObject(m, "WERR_WSA_QOS_NO_SENDERS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSA_QOS_NO_SENDERS)));
	PyModule_AddObject(m, "WERR_WSA_QOS_NO_RECEIVERS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSA_QOS_NO_RECEIVERS)));
	PyModule_AddObject(m, "WERR_WSA_QOS_REQUEST_CONFIRMED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSA_QOS_REQUEST_CONFIRMED)));
	PyModule_AddObject(m, "WERR_WSA_QOS_ADMISSION_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSA_QOS_ADMISSION_FAILURE)));
	PyModule_AddObject(m, "WERR_WSA_QOS_POLICY_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSA_QOS_POLICY_FAILURE)));
	PyModule_AddObject(m, "WERR_WSA_QOS_BAD_STYLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSA_QOS_BAD_STYLE)));
	PyModule_AddObject(m, "WERR_WSA_QOS_BAD_OBJECT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSA_QOS_BAD_OBJECT)));
	PyModule_AddObject(m, "WERR_WSA_QOS_TRAFFIC_CTRL_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSA_QOS_TRAFFIC_CTRL_ERROR)));
	PyModule_AddObject(m, "WERR_WSA_QOS_GENERIC_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSA_QOS_GENERIC_ERROR)));
	PyModule_AddObject(m, "WERR_WSA_QOS_ESERVICETYPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSA_QOS_ESERVICETYPE)));
	PyModule_AddObject(m, "WERR_WSA_QOS_EFLOWSPEC",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSA_QOS_EFLOWSPEC)));
	PyModule_AddObject(m, "WERR_WSA_QOS_EPROVSPECBUF",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSA_QOS_EPROVSPECBUF)));
	PyModule_AddObject(m, "WERR_WSA_QOS_EFILTERSTYLE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSA_QOS_EFILTERSTYLE)));
	PyModule_AddObject(m, "WERR_WSA_QOS_EFILTERTYPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSA_QOS_EFILTERTYPE)));
	PyModule_AddObject(m, "WERR_WSA_QOS_EFILTERCOUNT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSA_QOS_EFILTERCOUNT)));
	PyModule_AddObject(m, "WERR_WSA_QOS_EOBJLENGTH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSA_QOS_EOBJLENGTH)));
	PyModule_AddObject(m, "WERR_WSA_QOS_EFLOWCOUNT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSA_QOS_EFLOWCOUNT)));
	PyModule_AddObject(m, "WERR_WSA_QOS_EUNKOWNPSOBJ",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSA_QOS_EUNKOWNPSOBJ)));
	PyModule_AddObject(m, "WERR_WSA_QOS_EPOLICYOBJ",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSA_QOS_EPOLICYOBJ)));
	PyModule_AddObject(m, "WERR_WSA_QOS_EFLOWDESC",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSA_QOS_EFLOWDESC)));
	PyModule_AddObject(m, "WERR_WSA_QOS_EPSFLOWSPEC",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSA_QOS_EPSFLOWSPEC)));
	PyModule_AddObject(m, "WERR_WSA_QOS_EPSFILTERSPEC",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSA_QOS_EPSFILTERSPEC)));
	PyModule_AddObject(m, "WERR_WSA_QOS_ESDMODEOBJ",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSA_QOS_ESDMODEOBJ)));
	PyModule_AddObject(m, "WERR_WSA_QOS_ESHAPERATEOBJ",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSA_QOS_ESHAPERATEOBJ)));
	PyModule_AddObject(m, "WERR_WSA_QOS_RESERVED_PETYPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WSA_QOS_RESERVED_PETYPE)));
	PyModule_AddObject(m, "WERR_IPSEC_QM_POLICY_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_QM_POLICY_EXISTS)));
	PyModule_AddObject(m, "WERR_IPSEC_QM_POLICY_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_QM_POLICY_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_IPSEC_QM_POLICY_IN_USE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_QM_POLICY_IN_USE)));
	PyModule_AddObject(m, "WERR_IPSEC_MM_POLICY_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_MM_POLICY_EXISTS)));
	PyModule_AddObject(m, "WERR_IPSEC_MM_POLICY_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_MM_POLICY_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_IPSEC_MM_POLICY_IN_USE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_MM_POLICY_IN_USE)));
	PyModule_AddObject(m, "WERR_IPSEC_MM_FILTER_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_MM_FILTER_EXISTS)));
	PyModule_AddObject(m, "WERR_IPSEC_MM_FILTER_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_MM_FILTER_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_IPSEC_TRANSPORT_FILTER_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_TRANSPORT_FILTER_EXISTS)));
	PyModule_AddObject(m, "WERR_IPSEC_TRANSPORT_FILTER_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_TRANSPORT_FILTER_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_IPSEC_MM_AUTH_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_MM_AUTH_EXISTS)));
	PyModule_AddObject(m, "WERR_IPSEC_MM_AUTH_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_MM_AUTH_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_IPSEC_MM_AUTH_IN_USE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_MM_AUTH_IN_USE)));
	PyModule_AddObject(m, "WERR_IPSEC_DEFAULT_MM_POLICY_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_DEFAULT_MM_POLICY_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_IPSEC_DEFAULT_MM_AUTH_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_DEFAULT_MM_AUTH_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_IPSEC_DEFAULT_QM_POLICY_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_DEFAULT_QM_POLICY_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_IPSEC_TUNNEL_FILTER_EXISTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_TUNNEL_FILTER_EXISTS)));
	PyModule_AddObject(m, "WERR_IPSEC_TUNNEL_FILTER_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_TUNNEL_FILTER_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_IPSEC_MM_FILTER_PENDING_DELETION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_MM_FILTER_PENDING_DELETION)));
	PyModule_AddObject(m, "WERR_IPSEC_TRANSPORT_FILTER_ENDING_DELETION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_TRANSPORT_FILTER_ENDING_DELETION)));
	PyModule_AddObject(m, "WERR_IPSEC_TUNNEL_FILTER_PENDING_DELETION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_TUNNEL_FILTER_PENDING_DELETION)));
	PyModule_AddObject(m, "WERR_IPSEC_MM_POLICY_PENDING_ELETION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_MM_POLICY_PENDING_ELETION)));
	PyModule_AddObject(m, "WERR_IPSEC_MM_AUTH_PENDING_DELETION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_MM_AUTH_PENDING_DELETION)));
	PyModule_AddObject(m, "WERR_IPSEC_QM_POLICY_PENDING_DELETION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_QM_POLICY_PENDING_DELETION)));
	PyModule_AddObject(m, "WERR_WARNING_IPSEC_MM_POLICY_PRUNED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WARNING_IPSEC_MM_POLICY_PRUNED)));
	PyModule_AddObject(m, "WERR_WARNING_IPSEC_QM_POLICY_PRUNED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_WARNING_IPSEC_QM_POLICY_PRUNED)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_NEG_STATUS_BEGIN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_NEG_STATUS_BEGIN)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_AUTH_FAIL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_AUTH_FAIL)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_ATTRIB_FAIL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_ATTRIB_FAIL)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_NEGOTIATION_PENDING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_NEGOTIATION_PENDING)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_GENERAL_PROCESSING_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_GENERAL_PROCESSING_ERROR)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_TIMED_OUT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_TIMED_OUT)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_NO_CERT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_NO_CERT)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_SA_DELETED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_SA_DELETED)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_SA_REAPED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_SA_REAPED)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_MM_ACQUIRE_DROP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_MM_ACQUIRE_DROP)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_QM_ACQUIRE_DROP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_QM_ACQUIRE_DROP)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_QUEUE_DROP_MM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_QUEUE_DROP_MM)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_QUEUE_DROP_NO_MM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_QUEUE_DROP_NO_MM)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_DROP_NO_RESPONSE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_DROP_NO_RESPONSE)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_MM_DELAY_DROP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_MM_DELAY_DROP)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_QM_DELAY_DROP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_QM_DELAY_DROP)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_ERROR)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_CRL_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_CRL_FAILED)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_INVALID_KEY_USAGE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_INVALID_KEY_USAGE)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_INVALID_CERT_TYPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_INVALID_CERT_TYPE)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_NO_PRIVATE_KEY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_NO_PRIVATE_KEY)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_DH_FAIL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_DH_FAIL)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_INVALID_HEADER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_INVALID_HEADER)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_NO_POLICY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_NO_POLICY)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_INVALID_SIGNATURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_INVALID_SIGNATURE)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_KERBEROS_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_KERBEROS_ERROR)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_NO_PUBLIC_KEY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_NO_PUBLIC_KEY)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_PROCESS_ERR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_PROCESS_ERR)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_PROCESS_ERR_SA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_PROCESS_ERR_SA)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_PROCESS_ERR_PROP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_PROCESS_ERR_PROP)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_PROCESS_ERR_TRANS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_PROCESS_ERR_TRANS)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_PROCESS_ERR_KE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_PROCESS_ERR_KE)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_PROCESS_ERR_ID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_PROCESS_ERR_ID)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_PROCESS_ERR_CERT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_PROCESS_ERR_CERT)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_PROCESS_ERR_CERT_REQ",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_PROCESS_ERR_CERT_REQ)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_PROCESS_ERR_HASH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_PROCESS_ERR_HASH)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_PROCESS_ERR_SIG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_PROCESS_ERR_SIG)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_PROCESS_ERR_NONCE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_PROCESS_ERR_NONCE)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_PROCESS_ERR_NOTIFY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_PROCESS_ERR_NOTIFY)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_PROCESS_ERR_DELETE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_PROCESS_ERR_DELETE)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_PROCESS_ERR_VENDOR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_PROCESS_ERR_VENDOR)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_INVALID_PAYLOAD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_INVALID_PAYLOAD)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_LOAD_SOFT_SA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_LOAD_SOFT_SA)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_SOFT_SA_TORN_DOWN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_SOFT_SA_TORN_DOWN)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_INVALID_COOKIE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_INVALID_COOKIE)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_NO_PEER_CERT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_NO_PEER_CERT)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_PEER_CRL_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_PEER_CRL_FAILED)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_POLICY_CHANGE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_POLICY_CHANGE)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_NO_MM_POLICY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_NO_MM_POLICY)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_NOTCBPRIV",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_NOTCBPRIV)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_SECLOADFAIL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_SECLOADFAIL)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_FAILSSPINIT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_FAILSSPINIT)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_FAILQUERYSSP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_FAILQUERYSSP)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_SRVACQFAIL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_SRVACQFAIL)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_SRVQUERYCRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_SRVQUERYCRED)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_GETSPIFAIL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_GETSPIFAIL)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_INVALID_FILTER",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_INVALID_FILTER)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_OUT_OF_MEMORY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_OUT_OF_MEMORY)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_ADD_UPDATE_KEY_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_ADD_UPDATE_KEY_FAILED)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_INVALID_POLICY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_INVALID_POLICY)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_UNKNOWN_DOI",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_UNKNOWN_DOI)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_INVALID_SITUATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_INVALID_SITUATION)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_DH_FAILURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_DH_FAILURE)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_INVALID_GROUP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_INVALID_GROUP)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_ENCRYPT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_ENCRYPT)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_DECRYPT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_DECRYPT)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_POLICY_MATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_POLICY_MATCH)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_UNSUPPORTED_ID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_UNSUPPORTED_ID)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_INVALID_HASH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_INVALID_HASH)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_INVALID_HASH_ALG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_INVALID_HASH_ALG)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_INVALID_HASH_SIZE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_INVALID_HASH_SIZE)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_INVALID_ENCRYPT_ALG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_INVALID_ENCRYPT_ALG)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_INVALID_AUTH_ALG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_INVALID_AUTH_ALG)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_INVALID_SIG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_INVALID_SIG)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_LOAD_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_LOAD_FAILED)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_RPC_DELETE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_RPC_DELETE)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_BENIGN_REINIT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_BENIGN_REINIT)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_INVALID_RESPONDER_LIFETIME_NOTIFY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_INVALID_RESPONDER_LIFETIME_NOTIFY)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_INVALID_CERT_KEYLEN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_INVALID_CERT_KEYLEN)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_MM_LIMIT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_MM_LIMIT)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_NEGOTIATION_DISABLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_NEGOTIATION_DISABLED)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_QM_LIMIT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_QM_LIMIT)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_MM_EXPIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_MM_EXPIRED)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_PEER_MM_ASSUMED_INVALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_PEER_MM_ASSUMED_INVALID)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_CERT_CHAIN_POLICY_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_CERT_CHAIN_POLICY_MISMATCH)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_UNEXPECTED_MESSAGE_ID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_UNEXPECTED_MESSAGE_ID)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_INVALID_UMATTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_INVALID_UMATTS)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_DOS_COOKIE_SENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_DOS_COOKIE_SENT)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_SHUTTING_DOWN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_SHUTTING_DOWN)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_CGA_AUTH_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_CGA_AUTH_FAILED)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_PROCESS_ERR_NATOA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_PROCESS_ERR_NATOA)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_INVALID_MM_FOR_QM",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_INVALID_MM_FOR_QM)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_QM_EXPIRED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_QM_EXPIRED)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_TOO_MANY_FILTERS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_TOO_MANY_FILTERS)));
	PyModule_AddObject(m, "WERR_IPSEC_IKE_NEG_STATUS_END",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_IPSEC_IKE_NEG_STATUS_END)));
	PyModule_AddObject(m, "WERR_SXS_SECTION_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_SECTION_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_SXS_CANT_GEN_ACTCTX",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_CANT_GEN_ACTCTX)));
	PyModule_AddObject(m, "WERR_SXS_INVALID_ACTCTXDATA_FORMAT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_INVALID_ACTCTXDATA_FORMAT)));
	PyModule_AddObject(m, "WERR_SXS_ASSEMBLY_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_ASSEMBLY_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_SXS_MANIFEST_FORMAT_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_MANIFEST_FORMAT_ERROR)));
	PyModule_AddObject(m, "WERR_SXS_MANIFEST_PARSE_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_MANIFEST_PARSE_ERROR)));
	PyModule_AddObject(m, "WERR_SXS_ACTIVATION_CONTEXT_DISABLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_ACTIVATION_CONTEXT_DISABLED)));
	PyModule_AddObject(m, "WERR_SXS_KEY_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_KEY_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_SXS_VERSION_CONFLICT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_VERSION_CONFLICT)));
	PyModule_AddObject(m, "WERR_SXS_WRONG_SECTION_TYPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_WRONG_SECTION_TYPE)));
	PyModule_AddObject(m, "WERR_SXS_THREAD_QUERIES_DISABLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_THREAD_QUERIES_DISABLED)));
	PyModule_AddObject(m, "WERR_SXS_PROCESS_DEFAULT_ALREADY_SET",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_PROCESS_DEFAULT_ALREADY_SET)));
	PyModule_AddObject(m, "WERR_SXS_UNKNOWN_ENCODING_GROUP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_UNKNOWN_ENCODING_GROUP)));
	PyModule_AddObject(m, "WERR_SXS_UNKNOWN_ENCODING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_UNKNOWN_ENCODING)));
	PyModule_AddObject(m, "WERR_SXS_INVALID_XML_NAMESPACE_URI",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_INVALID_XML_NAMESPACE_URI)));
	PyModule_AddObject(m, "WERR_SXS_ROOT_MANIFEST_DEPENDENCY_OT_INSTALLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_ROOT_MANIFEST_DEPENDENCY_OT_INSTALLED)));
	PyModule_AddObject(m, "WERR_SXS_LEAF_MANIFEST_DEPENDENCY_NOT_INSTALLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_LEAF_MANIFEST_DEPENDENCY_NOT_INSTALLED)));
	PyModule_AddObject(m, "WERR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE)));
	PyModule_AddObject(m, "WERR_SXS_MANIFEST_MISSING_REQUIRED_DEFAULT_NAMESPACE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_MANIFEST_MISSING_REQUIRED_DEFAULT_NAMESPACE)));
	PyModule_AddObject(m, "WERR_SXS_MANIFEST_INVALID_REQUIRED_DEFAULT_NAMESPACE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_MANIFEST_INVALID_REQUIRED_DEFAULT_NAMESPACE)));
	PyModule_AddObject(m, "WERR_SXS_PRIVATE_MANIFEST_CROSS_PATH_WITH_REPARSE_POINT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_PRIVATE_MANIFEST_CROSS_PATH_WITH_REPARSE_POINT)));
	PyModule_AddObject(m, "WERR_SXS_DUPLICATE_DLL_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_DUPLICATE_DLL_NAME)));
	PyModule_AddObject(m, "WERR_SXS_DUPLICATE_WINDOWCLASS_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_DUPLICATE_WINDOWCLASS_NAME)));
	PyModule_AddObject(m, "WERR_SXS_DUPLICATE_CLSID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_DUPLICATE_CLSID)));
	PyModule_AddObject(m, "WERR_SXS_DUPLICATE_IID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_DUPLICATE_IID)));
	PyModule_AddObject(m, "WERR_SXS_DUPLICATE_TLBID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_DUPLICATE_TLBID)));
	PyModule_AddObject(m, "WERR_SXS_DUPLICATE_PROGID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_DUPLICATE_PROGID)));
	PyModule_AddObject(m, "WERR_SXS_DUPLICATE_ASSEMBLY_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_DUPLICATE_ASSEMBLY_NAME)));
	PyModule_AddObject(m, "WERR_SXS_FILE_HASH_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_FILE_HASH_MISMATCH)));
	PyModule_AddObject(m, "WERR_SXS_POLICY_PARSE_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_POLICY_PARSE_ERROR)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_MISSINGQUOTE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_MISSINGQUOTE)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_COMMENTSYNTAX",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_COMMENTSYNTAX)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_BADSTARTNAMECHAR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_BADSTARTNAMECHAR)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_BADNAMECHAR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_BADNAMECHAR)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_BADCHARINSTRING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_BADCHARINSTRING)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_XMLDECLSYNTAX",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_XMLDECLSYNTAX)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_BADCHARDATA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_BADCHARDATA)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_MISSINGWHITESPACE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_MISSINGWHITESPACE)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_EXPECTINGTAGEND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_EXPECTINGTAGEND)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_MISSINGSEMICOLON",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_MISSINGSEMICOLON)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_UNBALANCEDPAREN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_UNBALANCEDPAREN)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_INTERNALERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_INTERNALERROR)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_UNEXPECTED_WHITESPACE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_UNEXPECTED_WHITESPACE)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_INCOMPLETE_ENCODING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_INCOMPLETE_ENCODING)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_MISSING_PAREN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_MISSING_PAREN)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_EXPECTINGCLOSEQUOTE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_EXPECTINGCLOSEQUOTE)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_MULTIPLE_COLONS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_MULTIPLE_COLONS)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_INVALID_DECIMAL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_INVALID_DECIMAL)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_INVALID_HEXIDECIMAL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_INVALID_HEXIDECIMAL)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_INVALID_UNICODE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_INVALID_UNICODE)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_WHITESPACEORQUESTIONMARK",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_WHITESPACEORQUESTIONMARK)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_UNEXPECTEDENDTAG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_UNEXPECTEDENDTAG)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_UNCLOSEDTAG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_UNCLOSEDTAG)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_DUPLICATEATTRIBUTE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_DUPLICATEATTRIBUTE)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_MULTIPLEROOTS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_MULTIPLEROOTS)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_INVALIDATROOTLEVEL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_INVALIDATROOTLEVEL)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_BADXMLDECL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_BADXMLDECL)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_MISSINGROOT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_MISSINGROOT)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_UNEXPECTEDEOF",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_UNEXPECTEDEOF)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_BADPEREFINSUBSET",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_BADPEREFINSUBSET)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_UNCLOSEDSTARTTAG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_UNCLOSEDSTARTTAG)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_UNCLOSEDENDTAG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_UNCLOSEDENDTAG)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_UNCLOSEDSTRING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_UNCLOSEDSTRING)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_UNCLOSEDCOMMENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_UNCLOSEDCOMMENT)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_UNCLOSEDDECL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_UNCLOSEDDECL)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_UNCLOSEDCDATA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_UNCLOSEDCDATA)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_RESERVEDNAMESPACE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_RESERVEDNAMESPACE)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_INVALIDENCODING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_INVALIDENCODING)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_INVALIDSWITCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_INVALIDSWITCH)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_BADXMLCASE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_BADXMLCASE)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_INVALID_STANDALONE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_INVALID_STANDALONE)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_UNEXPECTED_STANDALONE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_UNEXPECTED_STANDALONE)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_INVALID_VERSION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_INVALID_VERSION)));
	PyModule_AddObject(m, "WERR_SXS_XML_E_MISSINGEQUALS",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_XML_E_MISSINGEQUALS)));
	PyModule_AddObject(m, "WERR_SXS_PROTECTION_RECOVERY_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_PROTECTION_RECOVERY_FAILED)));
	PyModule_AddObject(m, "WERR_SXS_PROTECTION_PUBLIC_KEY_OO_SHORT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_PROTECTION_PUBLIC_KEY_OO_SHORT)));
	PyModule_AddObject(m, "WERR_SXS_PROTECTION_CATALOG_NOT_VALID",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_PROTECTION_CATALOG_NOT_VALID)));
	PyModule_AddObject(m, "WERR_SXS_UNTRANSLATABLE_HRESULT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_UNTRANSLATABLE_HRESULT)));
	PyModule_AddObject(m, "WERR_SXS_PROTECTION_CATALOG_FILE_MISSING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_PROTECTION_CATALOG_FILE_MISSING)));
	PyModule_AddObject(m, "WERR_SXS_MISSING_ASSEMBLY_IDENTITY_ATTRIBUTE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_MISSING_ASSEMBLY_IDENTITY_ATTRIBUTE)));
	PyModule_AddObject(m, "WERR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE_NAME)));
	PyModule_AddObject(m, "WERR_SXS_ASSEMBLY_MISSING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_ASSEMBLY_MISSING)));
	PyModule_AddObject(m, "WERR_SXS_CORRUPT_ACTIVATION_STACK",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_CORRUPT_ACTIVATION_STACK)));
	PyModule_AddObject(m, "WERR_SXS_CORRUPTION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_CORRUPTION)));
	PyModule_AddObject(m, "WERR_SXS_EARLY_DEACTIVATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_EARLY_DEACTIVATION)));
	PyModule_AddObject(m, "WERR_SXS_INVALID_DEACTIVATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_INVALID_DEACTIVATION)));
	PyModule_AddObject(m, "WERR_SXS_MULTIPLE_DEACTIVATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_MULTIPLE_DEACTIVATION)));
	PyModule_AddObject(m, "WERR_SXS_PROCESS_TERMINATION_REQUESTED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_PROCESS_TERMINATION_REQUESTED)));
	PyModule_AddObject(m, "WERR_SXS_RELEASE_ACTIVATION_ONTEXT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_RELEASE_ACTIVATION_ONTEXT)));
	PyModule_AddObject(m, "WERR_SXS_SYSTEM_DEFAULT_ACTIVATION_CONTEXT_EMPTY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_SYSTEM_DEFAULT_ACTIVATION_CONTEXT_EMPTY)));
	PyModule_AddObject(m, "WERR_SXS_INVALID_IDENTITY_ATTRIBUTE_VALUE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_INVALID_IDENTITY_ATTRIBUTE_VALUE)));
	PyModule_AddObject(m, "WERR_SXS_INVALID_IDENTITY_ATTRIBUTE_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_INVALID_IDENTITY_ATTRIBUTE_NAME)));
	PyModule_AddObject(m, "WERR_SXS_IDENTITY_DUPLICATE_ATTRIBUTE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_IDENTITY_DUPLICATE_ATTRIBUTE)));
	PyModule_AddObject(m, "WERR_SXS_IDENTITY_PARSE_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_IDENTITY_PARSE_ERROR)));
	PyModule_AddObject(m, "WERR_MALFORMED_SUBSTITUTION_STRING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MALFORMED_SUBSTITUTION_STRING)));
	PyModule_AddObject(m, "WERR_SXS_INCORRECT_PUBLIC_KEY_OKEN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_INCORRECT_PUBLIC_KEY_OKEN)));
	PyModule_AddObject(m, "WERR_UNMAPPED_SUBSTITUTION_STRING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_UNMAPPED_SUBSTITUTION_STRING)));
	PyModule_AddObject(m, "WERR_SXS_ASSEMBLY_NOT_LOCKED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_ASSEMBLY_NOT_LOCKED)));
	PyModule_AddObject(m, "WERR_SXS_COMPONENT_STORE_CORRUPT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_COMPONENT_STORE_CORRUPT)));
	PyModule_AddObject(m, "WERR_ADVANCED_INSTALLER_FAILED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_ADVANCED_INSTALLER_FAILED)));
	PyModule_AddObject(m, "WERR_XML_ENCODING_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_XML_ENCODING_MISMATCH)));
	PyModule_AddObject(m, "WERR_SXS_MANIFEST_IDENTITY_SAME_BUT_CONTENTS_DIFFERENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_MANIFEST_IDENTITY_SAME_BUT_CONTENTS_DIFFERENT)));
	PyModule_AddObject(m, "WERR_SXS_IDENTITIES_DIFFERENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_IDENTITIES_DIFFERENT)));
	PyModule_AddObject(m, "WERR_SXS_ASSEMBLY_IS_NOT_A_DEPLOYMENT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_ASSEMBLY_IS_NOT_A_DEPLOYMENT)));
	PyModule_AddObject(m, "WERR_SXS_FILE_NOT_PART_OF_ASSEMBLY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_FILE_NOT_PART_OF_ASSEMBLY)));
	PyModule_AddObject(m, "WERR_SXS_MANIFEST_TOO_BIG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_MANIFEST_TOO_BIG)));
	PyModule_AddObject(m, "WERR_SXS_SETTING_NOT_REGISTERED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_SETTING_NOT_REGISTERED)));
	PyModule_AddObject(m, "WERR_SXS_TRANSACTION_CLOSURE_INCOMPLETE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SXS_TRANSACTION_CLOSURE_INCOMPLETE)));
	PyModule_AddObject(m, "WERR_EVT_INVALID_CHANNEL_PATH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_INVALID_CHANNEL_PATH)));
	PyModule_AddObject(m, "WERR_EVT_INVALID_QUERY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_INVALID_QUERY)));
	PyModule_AddObject(m, "WERR_EVT_PUBLISHER_METADATA_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_PUBLISHER_METADATA_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_EVT_EVENT_TEMPLATE_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_EVENT_TEMPLATE_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_EVT_INVALID_PUBLISHER_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_INVALID_PUBLISHER_NAME)));
	PyModule_AddObject(m, "WERR_EVT_INVALID_EVENT_DATA",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_INVALID_EVENT_DATA)));
	PyModule_AddObject(m, "WERR_EVT_CHANNEL_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_CHANNEL_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_EVT_MALFORMED_XML_TEXT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_MALFORMED_XML_TEXT)));
	PyModule_AddObject(m, "WERR_EVT_SUBSCRIPTION_TO_DIRECT_CHANNEL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_SUBSCRIPTION_TO_DIRECT_CHANNEL)));
	PyModule_AddObject(m, "WERR_EVT_CONFIGURATION_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_CONFIGURATION_ERROR)));
	PyModule_AddObject(m, "WERR_EVT_QUERY_RESULT_STALE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_QUERY_RESULT_STALE)));
	PyModule_AddObject(m, "WERR_EVT_QUERY_RESULT_INVALID_POSITION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_QUERY_RESULT_INVALID_POSITION)));
	PyModule_AddObject(m, "WERR_EVT_NON_VALIDATING_MSXML",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_NON_VALIDATING_MSXML)));
	PyModule_AddObject(m, "WERR_EVT_FILTER_ALREADYSCOPED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_FILTER_ALREADYSCOPED)));
	PyModule_AddObject(m, "WERR_EVT_FILTER_NOTELTSET",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_FILTER_NOTELTSET)));
	PyModule_AddObject(m, "WERR_EVT_FILTER_INVARG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_FILTER_INVARG)));
	PyModule_AddObject(m, "WERR_EVT_FILTER_INVTEST",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_FILTER_INVTEST)));
	PyModule_AddObject(m, "WERR_EVT_FILTER_INVTYPE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_FILTER_INVTYPE)));
	PyModule_AddObject(m, "WERR_EVT_FILTER_PARSEERR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_FILTER_PARSEERR)));
	PyModule_AddObject(m, "WERR_EVT_FILTER_UNSUPPORTEDOP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_FILTER_UNSUPPORTEDOP)));
	PyModule_AddObject(m, "WERR_EVT_FILTER_UNEXPECTEDTOKEN",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_FILTER_UNEXPECTEDTOKEN)));
	PyModule_AddObject(m, "WERR_EVT_INVALID_OPERATION_OVER_ENABLED_DIRECT_CHANNEL",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_INVALID_OPERATION_OVER_ENABLED_DIRECT_CHANNEL)));
	PyModule_AddObject(m, "WERR_EVT_INVALID_CHANNEL_PROPERTY_VALUE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_INVALID_CHANNEL_PROPERTY_VALUE)));
	PyModule_AddObject(m, "WERR_EVT_INVALID_PUBLISHER_PROPERTY_VALUE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_INVALID_PUBLISHER_PROPERTY_VALUE)));
	PyModule_AddObject(m, "WERR_EVT_CHANNEL_CANNOT_ACTIVATE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_CHANNEL_CANNOT_ACTIVATE)));
	PyModule_AddObject(m, "WERR_EVT_FILTER_TOO_COMPLEX",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_FILTER_TOO_COMPLEX)));
	PyModule_AddObject(m, "WERR_EVT_MESSAGE_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_MESSAGE_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_EVT_MESSAGE_ID_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_MESSAGE_ID_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_EVT_UNRESOLVED_VALUE_INSERT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_UNRESOLVED_VALUE_INSERT)));
	PyModule_AddObject(m, "WERR_EVT_UNRESOLVED_PARAMETER_INSERT",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_UNRESOLVED_PARAMETER_INSERT)));
	PyModule_AddObject(m, "WERR_EVT_MAX_INSERTS_REACHED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_MAX_INSERTS_REACHED)));
	PyModule_AddObject(m, "WERR_EVT_EVENT_DEFINITION_NOT_OUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_EVENT_DEFINITION_NOT_OUND)));
	PyModule_AddObject(m, "WERR_EVT_MESSAGE_LOCALE_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_MESSAGE_LOCALE_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_EVT_VERSION_TOO_OLD",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_VERSION_TOO_OLD)));
	PyModule_AddObject(m, "WERR_EVT_VERSION_TOO_NEW",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_VERSION_TOO_NEW)));
	PyModule_AddObject(m, "WERR_EVT_CANNOT_OPEN_CHANNEL_OF_QUERY",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_CANNOT_OPEN_CHANNEL_OF_QUERY)));
	PyModule_AddObject(m, "WERR_EVT_PUBLISHER_DISABLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EVT_PUBLISHER_DISABLED)));
	PyModule_AddObject(m, "WERR_EC_SUBSCRIPTION_CANNOT_ACTIVATE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EC_SUBSCRIPTION_CANNOT_ACTIVATE)));
	PyModule_AddObject(m, "WERR_EC_LOG_DISABLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_EC_LOG_DISABLED)));
	PyModule_AddObject(m, "WERR_MUI_FILE_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MUI_FILE_NOT_FOUND)));
	PyModule_AddObject(m, "WERR_MUI_INVALID_FILE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MUI_INVALID_FILE)));
	PyModule_AddObject(m, "WERR_MUI_INVALID_RC_CONFIG",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MUI_INVALID_RC_CONFIG)));
	PyModule_AddObject(m, "WERR_MUI_INVALID_LOCALE_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MUI_INVALID_LOCALE_NAME)));
	PyModule_AddObject(m, "WERR_MUI_INVALID_ULTIMATEFALLBACK_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MUI_INVALID_ULTIMATEFALLBACK_NAME)));
	PyModule_AddObject(m, "WERR_MUI_FILE_NOT_LOADED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MUI_FILE_NOT_LOADED)));
	PyModule_AddObject(m, "WERR_RESOURCE_ENUM_USER_STOP",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_RESOURCE_ENUM_USER_STOP)));
	PyModule_AddObject(m, "WERR_MUI_INTLSETTINGS_UILANG_NOT_INSTALLED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MUI_INTLSETTINGS_UILANG_NOT_INSTALLED)));
	PyModule_AddObject(m, "WERR_MUI_INTLSETTINGS_INVALID_LOCALE_NAME",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MUI_INTLSETTINGS_INVALID_LOCALE_NAME)));
	PyModule_AddObject(m, "WERR_MCA_INVALID_CAPABILITIES_STRING",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MCA_INVALID_CAPABILITIES_STRING)));
	PyModule_AddObject(m, "WERR_MCA_INVALID_VCP_VERSION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MCA_INVALID_VCP_VERSION)));
	PyModule_AddObject(m, "WERR_MCA_MONITOR_VIOLATES_MCCS_SPECIFICATION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MCA_MONITOR_VIOLATES_MCCS_SPECIFICATION)));
	PyModule_AddObject(m, "WERR_MCA_MCCS_VERSION_MISMATCH",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MCA_MCCS_VERSION_MISMATCH)));
	PyModule_AddObject(m, "WERR_MCA_UNSUPPORTED_MCCS_VERSION",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MCA_UNSUPPORTED_MCCS_VERSION)));
	PyModule_AddObject(m, "WERR_MCA_INTERNAL_ERROR",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MCA_INTERNAL_ERROR)));
	PyModule_AddObject(m, "WERR_MCA_INVALID_TECHNOLOGY_TYPE_RETURNED",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MCA_INVALID_TECHNOLOGY_TYPE_RETURNED)));
	PyModule_AddObject(m, "WERR_MCA_UNSUPPORTED_COLOR_TEMPERATURE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_MCA_UNSUPPORTED_COLOR_TEMPERATURE)));
	PyModule_AddObject(m, "WERR_AMBIGUOUS_SYSTEM_DEVICE",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_AMBIGUOUS_SYSTEM_DEVICE)));
	PyModule_AddObject(m, "WERR_SYSTEM_DEVICE_NOT_FOUND",
                  		PyLong_FromUnsignedLongLong(W_ERROR_V(WERR_SYSTEM_DEVICE_NOT_FOUND)));

	return m;
}
