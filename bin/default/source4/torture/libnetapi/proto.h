#ifndef __SOURCE4_TORTURE_LIBNETAPI_PROTO_H__
#define __SOURCE4_TORTURE_LIBNETAPI_PROTO_H__

#undef _PRINTF_ATTRIBUTE
#define _PRINTF_ATTRIBUTE(a1, a2) PRINTF_ATTRIBUTE(a1, a2)
/* This file was automatically generated by mkproto.pl. DO NOT EDIT */

/* this file contains prototypes for functions that are private 
 * to this subsystem or library. These functions should not be 
 * used outside this particular subsystem! */


/* The following definitions come from ../../source4/torture/libnetapi/libnetapi.c  */

bool torture_libnetapi_init_context(struct torture_context *tctx,
				    struct libnetapi_ctx **ctx_p);
NTSTATUS torture_libnetapi_init(TALLOC_CTX *ctx);

/* The following definitions come from ../../source4/torture/libnetapi/libnetapi_user.c  */

NET_API_STATUS test_netuseradd(struct torture_context *tctx,
			       const char *hostname,
			       const char *username);
bool torture_libnetapi_user(struct torture_context *tctx);

/* The following definitions come from ../../source4/torture/libnetapi/libnetapi_group.c  */

bool torture_libnetapi_group(struct torture_context *tctx);

/* The following definitions come from ../../source4/torture/libnetapi/libnetapi_server.c  */

bool torture_libnetapi_server(struct torture_context *tctx);
#undef _PRINTF_ATTRIBUTE
#define _PRINTF_ATTRIBUTE(a1, a2)

#endif /* __SOURCE4_TORTURE_LIBNETAPI_PROTO_H__ */

