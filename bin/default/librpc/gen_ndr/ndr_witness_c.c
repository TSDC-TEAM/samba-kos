/* client functions auto-generated by pidl */

#include "includes.h"
#include <tevent.h>
#include "lib/util/tevent_ntstatus.h"
#include "bin/default/librpc/gen_ndr/ndr_witness.h"
#include "bin/default/librpc/gen_ndr/ndr_witness_c.h"

/* witness - client functions generated by pidl */

struct dcerpc_witness_GetInterfaceList_r_state {
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_witness_GetInterfaceList_r_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_witness_GetInterfaceList_r_send(TALLOC_CTX *mem_ctx,
	struct tevent_context *ev,
	struct dcerpc_binding_handle *h,
	struct witness_GetInterfaceList *r)
{
	struct tevent_req *req;
	struct dcerpc_witness_GetInterfaceList_r_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_witness_GetInterfaceList_r_state);
	if (req == NULL) {
		return NULL;
	}

	state->out_mem_ctx = talloc_new(state);
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	subreq = dcerpc_binding_handle_call_send(state, ev, h,
			NULL, &ndr_table_witness,
			NDR_WITNESS_GETINTERFACELIST, state->out_mem_ctx, r);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_witness_GetInterfaceList_r_done, req);

	return req;
}

static void dcerpc_witness_GetInterfaceList_r_done(struct tevent_req *subreq)
{
	struct tevent_req *req =
		tevent_req_callback_data(subreq,
		struct tevent_req);
	NTSTATUS status;

	status = dcerpc_binding_handle_call_recv(subreq);
	TALLOC_FREE(subreq);
	if (tevent_req_nterror(req, status)) {
		return;
	}

	tevent_req_done(req);
}

NTSTATUS dcerpc_witness_GetInterfaceList_r_recv(struct tevent_req *req, TALLOC_CTX *mem_ctx)
{
	struct dcerpc_witness_GetInterfaceList_r_state *state =
		tevent_req_data(req,
		struct dcerpc_witness_GetInterfaceList_r_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_witness_GetInterfaceList_r(struct dcerpc_binding_handle *h, TALLOC_CTX *mem_ctx, struct witness_GetInterfaceList *r)
{
	NTSTATUS status;

	status = dcerpc_binding_handle_call(h,
			NULL, &ndr_table_witness,
			NDR_WITNESS_GETINTERFACELIST, mem_ctx, r);

	return status;
}

struct dcerpc_witness_GetInterfaceList_state {
	struct witness_GetInterfaceList orig;
	struct witness_GetInterfaceList tmp;
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_witness_GetInterfaceList_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_witness_GetInterfaceList_send(TALLOC_CTX *mem_ctx,
							struct tevent_context *ev,
							struct dcerpc_binding_handle *h,
							struct witness_interfaceList **_interface_list /* [out] [ref] */)
{
	struct tevent_req *req;
	struct dcerpc_witness_GetInterfaceList_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_witness_GetInterfaceList_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;

	/* In parameters */

	/* Out parameters */
	state->orig.out.interface_list = _interface_list;

	/* Result */
	NDR_ZERO_STRUCT(state->orig.out.result);

	state->out_mem_ctx = talloc_named_const(state, 0,
			     "dcerpc_witness_GetInterfaceList_out_memory");
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = dcerpc_witness_GetInterfaceList_r_send(state, ev, h, &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_witness_GetInterfaceList_done, req);
	return req;
}

static void dcerpc_witness_GetInterfaceList_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct dcerpc_witness_GetInterfaceList_state *state = tevent_req_data(
		req, struct dcerpc_witness_GetInterfaceList_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = dcerpc_witness_GetInterfaceList_r_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (tevent_req_nterror(req, status)) {
		return;
	}

	/* Copy out parameters */
	*state->orig.out.interface_list = *state->tmp.out.interface_list;

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	NDR_ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS dcerpc_witness_GetInterfaceList_recv(struct tevent_req *req,
					      TALLOC_CTX *mem_ctx,
					      WERROR *result)
{
	struct dcerpc_witness_GetInterfaceList_state *state = tevent_req_data(
		req, struct dcerpc_witness_GetInterfaceList_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possible out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_witness_GetInterfaceList(struct dcerpc_binding_handle *h,
					 TALLOC_CTX *mem_ctx,
					 struct witness_interfaceList **_interface_list /* [out] [ref] */,
					 WERROR *result)
{
	struct witness_GetInterfaceList r;
	NTSTATUS status;

	/* In parameters */

	/* Out parameters */
	r.out.interface_list = _interface_list;

	/* Result */
	NDR_ZERO_STRUCT(r.out.result);

	status = dcerpc_witness_GetInterfaceList_r(h, mem_ctx, &r);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	/* Return variables */
	*_interface_list = *r.out.interface_list;

	/* Return result */
	*result = r.out.result;

	return NT_STATUS_OK;
}

struct dcerpc_witness_Register_r_state {
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_witness_Register_r_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_witness_Register_r_send(TALLOC_CTX *mem_ctx,
	struct tevent_context *ev,
	struct dcerpc_binding_handle *h,
	struct witness_Register *r)
{
	struct tevent_req *req;
	struct dcerpc_witness_Register_r_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_witness_Register_r_state);
	if (req == NULL) {
		return NULL;
	}

	state->out_mem_ctx = talloc_new(state);
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	subreq = dcerpc_binding_handle_call_send(state, ev, h,
			NULL, &ndr_table_witness,
			NDR_WITNESS_REGISTER, state->out_mem_ctx, r);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_witness_Register_r_done, req);

	return req;
}

static void dcerpc_witness_Register_r_done(struct tevent_req *subreq)
{
	struct tevent_req *req =
		tevent_req_callback_data(subreq,
		struct tevent_req);
	NTSTATUS status;

	status = dcerpc_binding_handle_call_recv(subreq);
	TALLOC_FREE(subreq);
	if (tevent_req_nterror(req, status)) {
		return;
	}

	tevent_req_done(req);
}

NTSTATUS dcerpc_witness_Register_r_recv(struct tevent_req *req, TALLOC_CTX *mem_ctx)
{
	struct dcerpc_witness_Register_r_state *state =
		tevent_req_data(req,
		struct dcerpc_witness_Register_r_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_witness_Register_r(struct dcerpc_binding_handle *h, TALLOC_CTX *mem_ctx, struct witness_Register *r)
{
	NTSTATUS status;

	status = dcerpc_binding_handle_call(h,
			NULL, &ndr_table_witness,
			NDR_WITNESS_REGISTER, mem_ctx, r);

	return status;
}

struct dcerpc_witness_Register_state {
	struct witness_Register orig;
	struct witness_Register tmp;
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_witness_Register_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_witness_Register_send(TALLOC_CTX *mem_ctx,
						struct tevent_context *ev,
						struct dcerpc_binding_handle *h,
						struct policy_handle *_context_handle /* [out] [ref] */,
						enum witness_version _version /* [in]  */,
						const char *_net_name /* [in] [charset(UTF16),unique] */,
						const char *_ip_address /* [in] [charset(UTF16),unique] */,
						const char *_client_computer_name /* [in] [charset(UTF16),unique] */)
{
	struct tevent_req *req;
	struct dcerpc_witness_Register_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_witness_Register_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;

	/* In parameters */
	state->orig.in.version = _version;
	state->orig.in.net_name = _net_name;
	state->orig.in.ip_address = _ip_address;
	state->orig.in.client_computer_name = _client_computer_name;

	/* Out parameters */
	state->orig.out.context_handle = _context_handle;

	/* Result */
	NDR_ZERO_STRUCT(state->orig.out.result);

	state->out_mem_ctx = talloc_named_const(state, 0,
			     "dcerpc_witness_Register_out_memory");
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = dcerpc_witness_Register_r_send(state, ev, h, &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_witness_Register_done, req);
	return req;
}

static void dcerpc_witness_Register_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct dcerpc_witness_Register_state *state = tevent_req_data(
		req, struct dcerpc_witness_Register_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = dcerpc_witness_Register_r_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (tevent_req_nterror(req, status)) {
		return;
	}

	/* Copy out parameters */
	*state->orig.out.context_handle = *state->tmp.out.context_handle;

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	NDR_ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS dcerpc_witness_Register_recv(struct tevent_req *req,
				      TALLOC_CTX *mem_ctx,
				      WERROR *result)
{
	struct dcerpc_witness_Register_state *state = tevent_req_data(
		req, struct dcerpc_witness_Register_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possible out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_witness_Register(struct dcerpc_binding_handle *h,
				 TALLOC_CTX *mem_ctx,
				 struct policy_handle *_context_handle /* [out] [ref] */,
				 enum witness_version _version /* [in]  */,
				 const char *_net_name /* [in] [charset(UTF16),unique] */,
				 const char *_ip_address /* [in] [charset(UTF16),unique] */,
				 const char *_client_computer_name /* [in] [charset(UTF16),unique] */,
				 WERROR *result)
{
	struct witness_Register r;
	NTSTATUS status;

	/* In parameters */
	r.in.version = _version;
	r.in.net_name = _net_name;
	r.in.ip_address = _ip_address;
	r.in.client_computer_name = _client_computer_name;

	/* Out parameters */
	r.out.context_handle = _context_handle;

	/* Result */
	NDR_ZERO_STRUCT(r.out.result);

	status = dcerpc_witness_Register_r(h, mem_ctx, &r);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	/* Return variables */
	*_context_handle = *r.out.context_handle;

	/* Return result */
	*result = r.out.result;

	return NT_STATUS_OK;
}

struct dcerpc_witness_UnRegister_r_state {
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_witness_UnRegister_r_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_witness_UnRegister_r_send(TALLOC_CTX *mem_ctx,
	struct tevent_context *ev,
	struct dcerpc_binding_handle *h,
	struct witness_UnRegister *r)
{
	struct tevent_req *req;
	struct dcerpc_witness_UnRegister_r_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_witness_UnRegister_r_state);
	if (req == NULL) {
		return NULL;
	}

	state->out_mem_ctx = NULL;

	subreq = dcerpc_binding_handle_call_send(state, ev, h,
			NULL, &ndr_table_witness,
			NDR_WITNESS_UNREGISTER, state, r);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_witness_UnRegister_r_done, req);

	return req;
}

static void dcerpc_witness_UnRegister_r_done(struct tevent_req *subreq)
{
	struct tevent_req *req =
		tevent_req_callback_data(subreq,
		struct tevent_req);
	NTSTATUS status;

	status = dcerpc_binding_handle_call_recv(subreq);
	TALLOC_FREE(subreq);
	if (tevent_req_nterror(req, status)) {
		return;
	}

	tevent_req_done(req);
}

NTSTATUS dcerpc_witness_UnRegister_r_recv(struct tevent_req *req, TALLOC_CTX *mem_ctx)
{
	struct dcerpc_witness_UnRegister_r_state *state =
		tevent_req_data(req,
		struct dcerpc_witness_UnRegister_r_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_witness_UnRegister_r(struct dcerpc_binding_handle *h, TALLOC_CTX *mem_ctx, struct witness_UnRegister *r)
{
	NTSTATUS status;

	status = dcerpc_binding_handle_call(h,
			NULL, &ndr_table_witness,
			NDR_WITNESS_UNREGISTER, mem_ctx, r);

	return status;
}

struct dcerpc_witness_UnRegister_state {
	struct witness_UnRegister orig;
	struct witness_UnRegister tmp;
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_witness_UnRegister_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_witness_UnRegister_send(TALLOC_CTX *mem_ctx,
						  struct tevent_context *ev,
						  struct dcerpc_binding_handle *h,
						  struct policy_handle _context_handle /* [in]  */)
{
	struct tevent_req *req;
	struct dcerpc_witness_UnRegister_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_witness_UnRegister_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;

	/* In parameters */
	state->orig.in.context_handle = _context_handle;

	/* Out parameters */

	/* Result */
	NDR_ZERO_STRUCT(state->orig.out.result);

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = dcerpc_witness_UnRegister_r_send(state, ev, h, &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_witness_UnRegister_done, req);
	return req;
}

static void dcerpc_witness_UnRegister_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct dcerpc_witness_UnRegister_state *state = tevent_req_data(
		req, struct dcerpc_witness_UnRegister_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = dcerpc_witness_UnRegister_r_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (tevent_req_nterror(req, status)) {
		return;
	}

	/* Copy out parameters */

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	NDR_ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS dcerpc_witness_UnRegister_recv(struct tevent_req *req,
					TALLOC_CTX *mem_ctx,
					WERROR *result)
{
	struct dcerpc_witness_UnRegister_state *state = tevent_req_data(
		req, struct dcerpc_witness_UnRegister_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possible out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_witness_UnRegister(struct dcerpc_binding_handle *h,
				   TALLOC_CTX *mem_ctx,
				   struct policy_handle _context_handle /* [in]  */,
				   WERROR *result)
{
	struct witness_UnRegister r;
	NTSTATUS status;

	/* In parameters */
	r.in.context_handle = _context_handle;

	/* Out parameters */

	/* Result */
	NDR_ZERO_STRUCT(r.out.result);

	status = dcerpc_witness_UnRegister_r(h, mem_ctx, &r);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	/* Return variables */

	/* Return result */
	*result = r.out.result;

	return NT_STATUS_OK;
}

struct dcerpc_witness_AsyncNotify_r_state {
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_witness_AsyncNotify_r_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_witness_AsyncNotify_r_send(TALLOC_CTX *mem_ctx,
	struct tevent_context *ev,
	struct dcerpc_binding_handle *h,
	struct witness_AsyncNotify *r)
{
	struct tevent_req *req;
	struct dcerpc_witness_AsyncNotify_r_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_witness_AsyncNotify_r_state);
	if (req == NULL) {
		return NULL;
	}

	state->out_mem_ctx = talloc_new(state);
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	subreq = dcerpc_binding_handle_call_send(state, ev, h,
			NULL, &ndr_table_witness,
			NDR_WITNESS_ASYNCNOTIFY, state->out_mem_ctx, r);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_witness_AsyncNotify_r_done, req);

	return req;
}

static void dcerpc_witness_AsyncNotify_r_done(struct tevent_req *subreq)
{
	struct tevent_req *req =
		tevent_req_callback_data(subreq,
		struct tevent_req);
	NTSTATUS status;

	status = dcerpc_binding_handle_call_recv(subreq);
	TALLOC_FREE(subreq);
	if (tevent_req_nterror(req, status)) {
		return;
	}

	tevent_req_done(req);
}

NTSTATUS dcerpc_witness_AsyncNotify_r_recv(struct tevent_req *req, TALLOC_CTX *mem_ctx)
{
	struct dcerpc_witness_AsyncNotify_r_state *state =
		tevent_req_data(req,
		struct dcerpc_witness_AsyncNotify_r_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_witness_AsyncNotify_r(struct dcerpc_binding_handle *h, TALLOC_CTX *mem_ctx, struct witness_AsyncNotify *r)
{
	NTSTATUS status;

	status = dcerpc_binding_handle_call(h,
			NULL, &ndr_table_witness,
			NDR_WITNESS_ASYNCNOTIFY, mem_ctx, r);

	return status;
}

struct dcerpc_witness_AsyncNotify_state {
	struct witness_AsyncNotify orig;
	struct witness_AsyncNotify tmp;
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_witness_AsyncNotify_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_witness_AsyncNotify_send(TALLOC_CTX *mem_ctx,
						   struct tevent_context *ev,
						   struct dcerpc_binding_handle *h,
						   struct policy_handle _context_handle /* [in]  */,
						   struct witness_notifyResponse **_response /* [out] [ref] */)
{
	struct tevent_req *req;
	struct dcerpc_witness_AsyncNotify_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_witness_AsyncNotify_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;

	/* In parameters */
	state->orig.in.context_handle = _context_handle;

	/* Out parameters */
	state->orig.out.response = _response;

	/* Result */
	NDR_ZERO_STRUCT(state->orig.out.result);

	state->out_mem_ctx = talloc_named_const(state, 0,
			     "dcerpc_witness_AsyncNotify_out_memory");
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = dcerpc_witness_AsyncNotify_r_send(state, ev, h, &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_witness_AsyncNotify_done, req);
	return req;
}

static void dcerpc_witness_AsyncNotify_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct dcerpc_witness_AsyncNotify_state *state = tevent_req_data(
		req, struct dcerpc_witness_AsyncNotify_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = dcerpc_witness_AsyncNotify_r_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (tevent_req_nterror(req, status)) {
		return;
	}

	/* Copy out parameters */
	*state->orig.out.response = *state->tmp.out.response;

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	NDR_ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS dcerpc_witness_AsyncNotify_recv(struct tevent_req *req,
					 TALLOC_CTX *mem_ctx,
					 WERROR *result)
{
	struct dcerpc_witness_AsyncNotify_state *state = tevent_req_data(
		req, struct dcerpc_witness_AsyncNotify_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possible out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_witness_AsyncNotify(struct dcerpc_binding_handle *h,
				    TALLOC_CTX *mem_ctx,
				    struct policy_handle _context_handle /* [in]  */,
				    struct witness_notifyResponse **_response /* [out] [ref] */,
				    WERROR *result)
{
	struct witness_AsyncNotify r;
	NTSTATUS status;

	/* In parameters */
	r.in.context_handle = _context_handle;

	/* Out parameters */
	r.out.response = _response;

	/* Result */
	NDR_ZERO_STRUCT(r.out.result);

	status = dcerpc_witness_AsyncNotify_r(h, mem_ctx, &r);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	/* Return variables */
	*_response = *r.out.response;

	/* Return result */
	*result = r.out.result;

	return NT_STATUS_OK;
}

struct dcerpc_witness_RegisterEx_r_state {
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_witness_RegisterEx_r_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_witness_RegisterEx_r_send(TALLOC_CTX *mem_ctx,
	struct tevent_context *ev,
	struct dcerpc_binding_handle *h,
	struct witness_RegisterEx *r)
{
	struct tevent_req *req;
	struct dcerpc_witness_RegisterEx_r_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_witness_RegisterEx_r_state);
	if (req == NULL) {
		return NULL;
	}

	state->out_mem_ctx = talloc_new(state);
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	subreq = dcerpc_binding_handle_call_send(state, ev, h,
			NULL, &ndr_table_witness,
			NDR_WITNESS_REGISTEREX, state->out_mem_ctx, r);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_witness_RegisterEx_r_done, req);

	return req;
}

static void dcerpc_witness_RegisterEx_r_done(struct tevent_req *subreq)
{
	struct tevent_req *req =
		tevent_req_callback_data(subreq,
		struct tevent_req);
	NTSTATUS status;

	status = dcerpc_binding_handle_call_recv(subreq);
	TALLOC_FREE(subreq);
	if (tevent_req_nterror(req, status)) {
		return;
	}

	tevent_req_done(req);
}

NTSTATUS dcerpc_witness_RegisterEx_r_recv(struct tevent_req *req, TALLOC_CTX *mem_ctx)
{
	struct dcerpc_witness_RegisterEx_r_state *state =
		tevent_req_data(req,
		struct dcerpc_witness_RegisterEx_r_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	talloc_steal(mem_ctx, state->out_mem_ctx);

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_witness_RegisterEx_r(struct dcerpc_binding_handle *h, TALLOC_CTX *mem_ctx, struct witness_RegisterEx *r)
{
	NTSTATUS status;

	status = dcerpc_binding_handle_call(h,
			NULL, &ndr_table_witness,
			NDR_WITNESS_REGISTEREX, mem_ctx, r);

	return status;
}

struct dcerpc_witness_RegisterEx_state {
	struct witness_RegisterEx orig;
	struct witness_RegisterEx tmp;
	TALLOC_CTX *out_mem_ctx;
};

static void dcerpc_witness_RegisterEx_done(struct tevent_req *subreq);

struct tevent_req *dcerpc_witness_RegisterEx_send(TALLOC_CTX *mem_ctx,
						  struct tevent_context *ev,
						  struct dcerpc_binding_handle *h,
						  struct policy_handle *_context_handle /* [out] [ref] */,
						  enum witness_version _version /* [in]  */,
						  const char *_net_name /* [in] [charset(UTF16),unique] */,
						  const char *_share_name /* [in] [charset(UTF16),unique] */,
						  const char *_ip_address /* [in] [charset(UTF16),unique] */,
						  const char *_client_computer_name /* [in] [charset(UTF16),unique] */,
						  uint32_t _flags /* [in]  */,
						  uint32_t _timeout /* [in]  */)
{
	struct tevent_req *req;
	struct dcerpc_witness_RegisterEx_state *state;
	struct tevent_req *subreq;

	req = tevent_req_create(mem_ctx, &state,
				struct dcerpc_witness_RegisterEx_state);
	if (req == NULL) {
		return NULL;
	}
	state->out_mem_ctx = NULL;

	/* In parameters */
	state->orig.in.version = _version;
	state->orig.in.net_name = _net_name;
	state->orig.in.share_name = _share_name;
	state->orig.in.ip_address = _ip_address;
	state->orig.in.client_computer_name = _client_computer_name;
	state->orig.in.flags = _flags;
	state->orig.in.timeout = _timeout;

	/* Out parameters */
	state->orig.out.context_handle = _context_handle;

	/* Result */
	NDR_ZERO_STRUCT(state->orig.out.result);

	state->out_mem_ctx = talloc_named_const(state, 0,
			     "dcerpc_witness_RegisterEx_out_memory");
	if (tevent_req_nomem(state->out_mem_ctx, req)) {
		return tevent_req_post(req, ev);
	}

	/* make a temporary copy, that we pass to the dispatch function */
	state->tmp = state->orig;

	subreq = dcerpc_witness_RegisterEx_r_send(state, ev, h, &state->tmp);
	if (tevent_req_nomem(subreq, req)) {
		return tevent_req_post(req, ev);
	}
	tevent_req_set_callback(subreq, dcerpc_witness_RegisterEx_done, req);
	return req;
}

static void dcerpc_witness_RegisterEx_done(struct tevent_req *subreq)
{
	struct tevent_req *req = tevent_req_callback_data(
		subreq, struct tevent_req);
	struct dcerpc_witness_RegisterEx_state *state = tevent_req_data(
		req, struct dcerpc_witness_RegisterEx_state);
	NTSTATUS status;
	TALLOC_CTX *mem_ctx;

	if (state->out_mem_ctx) {
		mem_ctx = state->out_mem_ctx;
	} else {
		mem_ctx = state;
	}

	status = dcerpc_witness_RegisterEx_r_recv(subreq, mem_ctx);
	TALLOC_FREE(subreq);
	if (tevent_req_nterror(req, status)) {
		return;
	}

	/* Copy out parameters */
	*state->orig.out.context_handle = *state->tmp.out.context_handle;

	/* Copy result */
	state->orig.out.result = state->tmp.out.result;

	/* Reset temporary structure */
	NDR_ZERO_STRUCT(state->tmp);

	tevent_req_done(req);
}

NTSTATUS dcerpc_witness_RegisterEx_recv(struct tevent_req *req,
					TALLOC_CTX *mem_ctx,
					WERROR *result)
{
	struct dcerpc_witness_RegisterEx_state *state = tevent_req_data(
		req, struct dcerpc_witness_RegisterEx_state);
	NTSTATUS status;

	if (tevent_req_is_nterror(req, &status)) {
		tevent_req_received(req);
		return status;
	}

	/* Steal possible out parameters to the callers context */
	talloc_steal(mem_ctx, state->out_mem_ctx);

	/* Return result */
	*result = state->orig.out.result;

	tevent_req_received(req);
	return NT_STATUS_OK;
}

NTSTATUS dcerpc_witness_RegisterEx(struct dcerpc_binding_handle *h,
				   TALLOC_CTX *mem_ctx,
				   struct policy_handle *_context_handle /* [out] [ref] */,
				   enum witness_version _version /* [in]  */,
				   const char *_net_name /* [in] [charset(UTF16),unique] */,
				   const char *_share_name /* [in] [charset(UTF16),unique] */,
				   const char *_ip_address /* [in] [charset(UTF16),unique] */,
				   const char *_client_computer_name /* [in] [charset(UTF16),unique] */,
				   uint32_t _flags /* [in]  */,
				   uint32_t _timeout /* [in]  */,
				   WERROR *result)
{
	struct witness_RegisterEx r;
	NTSTATUS status;

	/* In parameters */
	r.in.version = _version;
	r.in.net_name = _net_name;
	r.in.share_name = _share_name;
	r.in.ip_address = _ip_address;
	r.in.client_computer_name = _client_computer_name;
	r.in.flags = _flags;
	r.in.timeout = _timeout;

	/* Out parameters */
	r.out.context_handle = _context_handle;

	/* Result */
	NDR_ZERO_STRUCT(r.out.result);

	status = dcerpc_witness_RegisterEx_r(h, mem_ctx, &r);
	if (!NT_STATUS_IS_OK(status)) {
		return status;
	}

	/* Return variables */
	*_context_handle = *r.out.context_handle;

	/* Return result */
	*result = r.out.result;

	return NT_STATUS_OK;
}

