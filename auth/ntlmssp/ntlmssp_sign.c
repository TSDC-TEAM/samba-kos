/*
 *  Unix SMB/CIFS implementation.
 *  Version 3.0
 *  NTLMSSP Signing routines
 *  Copyright (C) Andrew Bartlett 2003-2005
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#include "includes.h"
#include "../auth/ntlmssp/ntlmssp.h"
#include "../libcli/auth/libcli_auth.h"
#include "zlib.h"
#include "../auth/ntlmssp/ntlmssp_private.h"

#include "lib/crypto/gnutls_helpers.h"



#undef DBGC_CLASS
#define DBGC_CLASS DBGC_AUTH

#define CLI_SIGN "session key to client-to-server signing key magic constant"
#define CLI_SEAL "session key to client-to-server sealing key magic constant"
#define SRV_SIGN "session key to server-to-client signing key magic constant"
#define SRV_SEAL "session key to server-to-client sealing key magic constant"

/**
 * Some notes on the NTLM2 code:
 *
 * NTLM2 is a AEAD system.  This means that the data encrypted is not
 * all the data that is signed.  In DCE-RPC case, the headers of the
 * DCE-RPC packets are also signed.  This prevents some of the
 * fun-and-games one might have by changing them.
 *
 */

static void dump_arc4_state(const char *description,
			    gnutls_cipher_hd_t *state)
{
	DBG_DEBUG("%s\n", description);
}

static NTSTATUS calc_ntlmv2_key(uint8_t subkey[16],
				DATA_BLOB session_key,
				const char *constant)
{
	gnutls_hash_hd_t hash_hnd = NULL;
	int rc;

	rc = gnutls_hash_init(&hash_hnd, GNUTLS_DIG_MD5);
	if (rc < 0) {
		return gnutls_error_to_ntstatus(rc, NT_STATUS_NTLM_BLOCKED);
	}
	rc = gnutls_hash(hash_hnd, session_key.data, session_key.length);
	if (rc < 0) {
		gnutls_hash_deinit(hash_hnd, NULL);
		return gnutls_error_to_ntstatus(rc, NT_STATUS_NTLM_BLOCKED);
	}
	rc = gnutls_hash(hash_hnd, constant, strlen(constant) + 1);
	if (rc < 0) {
		gnutls_hash_deinit(hash_hnd, NULL);
		return gnutls_error_to_ntstatus(rc, NT_STATUS_NTLM_BLOCKED);
	}
	gnutls_hash_deinit(hash_hnd, subkey);

	return NT_STATUS_OK;
}

enum ntlmssp_direction {
	NTLMSSP_SEND,
	NTLMSSP_RECEIVE
};

static NTSTATUS ntlmssp_make_packet_signature(struct ntlmssp_state *ntlmssp_state,
					      TALLOC_CTX *sig_mem_ctx,
					      const uint8_t *data, size_t length,
					      const uint8_t *whole_pdu, size_t pdu_length,
					      enum ntlmssp_direction direction,
					      DATA_BLOB *sig, bool encrypt_sig)
{
	NTSTATUS status = NT_STATUS_UNSUCCESSFUL;
	int rc;

	if (ntlmssp_state->neg_flags & NTLMSSP_NEGOTIATE_NTLM2) {
		gnutls_hmac_hd_t hmac_hnd = NULL;
		uint8_t digest[16];
		uint8_t seq_num[4];

		*sig = data_blob_talloc(sig_mem_ctx, NULL, NTLMSSP_SIG_SIZE);
		if (!sig->data) {
			return NT_STATUS_NO_MEMORY;
		}

		switch (direction) {
		case NTLMSSP_SEND:
			DEBUG(100,("ntlmssp_make_packet_signature: SEND seq = %u, len = %u, pdu_len = %u\n",
				ntlmssp_state->crypt->ntlm2.sending.seq_num,
				(unsigned int)length,
				(unsigned int)pdu_length));

			SIVAL(seq_num, 0, ntlmssp_state->crypt->ntlm2.sending.seq_num);
			ntlmssp_state->crypt->ntlm2.sending.seq_num++;

			rc = gnutls_hmac_init(&hmac_hnd,
					      GNUTLS_MAC_MD5,
					      ntlmssp_state->crypt->ntlm2.sending.sign_key,
					      16);
			if (rc < 0) {
				return gnutls_error_to_ntstatus(rc, NT_STATUS_NTLM_BLOCKED);
			}
			break;
		case NTLMSSP_RECEIVE:

			DEBUG(100,("ntlmssp_make_packet_signature: RECV seq = %u, len = %u, pdu_len = %u\n",
				ntlmssp_state->crypt->ntlm2.receiving.seq_num,
				(unsigned int)length,
				(unsigned int)pdu_length));

			SIVAL(seq_num, 0, ntlmssp_state->crypt->ntlm2.receiving.seq_num);
			ntlmssp_state->crypt->ntlm2.receiving.seq_num++;

			rc = gnutls_hmac_init(&hmac_hnd,
					      GNUTLS_MAC_MD5,
					      ntlmssp_state->crypt->ntlm2.receiving.sign_key,
					      16);
			if (rc < 0) {
				return gnutls_error_to_ntstatus(rc, NT_STATUS_NTLM_BLOCKED);
			}
			break;
		}

		dump_data_pw("pdu data ", whole_pdu, pdu_length);

		rc = gnutls_hmac(hmac_hnd, seq_num, sizeof(seq_num));
		if (rc < 0) {
			gnutls_hmac_deinit(hmac_hnd, NULL);
			return gnutls_error_to_ntstatus(rc, NT_STATUS_NTLM_BLOCKED);
		}
		rc = gnutls_hmac(hmac_hnd, whole_pdu, pdu_length);
		if (rc < 0) {
			gnutls_hmac_deinit(hmac_hnd, NULL);
			return gnutls_error_to_ntstatus(rc, NT_STATUS_NTLM_BLOCKED);
		}
		gnutls_hmac_deinit(hmac_hnd, digest);

		if (encrypt_sig && (ntlmssp_state->neg_flags & NTLMSSP_NEGOTIATE_KEY_EXCH)) {
			switch (direction) {
			case NTLMSSP_SEND:
				rc = gnutls_cipher_encrypt(ntlmssp_state->crypt->ntlm2.sending.seal_state,
							   digest,
							   8);
				break;
			case NTLMSSP_RECEIVE:
				rc = gnutls_cipher_encrypt(ntlmssp_state->crypt->ntlm2.receiving.seal_state,
							   digest,
							   8);
				break;
			}
			if (rc < 0) {
				DBG_ERR("gnutls_cipher_encrypt for NTLMv2 EXCH "
					"%s packet signature failed: %s\n",
					direction == NTLMSSP_SEND ?
						"send" : "receive",
					gnutls_strerror(rc));
				return gnutls_error_to_ntstatus(rc, NT_STATUS_NTLM_BLOCKED);
			}
		}

		SIVAL(sig->data, 0, NTLMSSP_SIGN_VERSION);
		memcpy(sig->data + 4, digest, 8);
		ZERO_ARRAY(digest);
		memcpy(sig->data + 12, seq_num, 4);
		ZERO_ARRAY(seq_num);

		dump_data_pw("ntlmssp v2 sig ", sig->data, sig->length);

	} else {
		uint32_t crc;

		crc = crc32(0, Z_NULL, 0);
		crc = crc32(crc, data, length);

		status = msrpc_gen(sig_mem_ctx,
			       sig, "dddd",
			       NTLMSSP_SIGN_VERSION, 0, crc,
			       ntlmssp_state->crypt->ntlm.seq_num);
		if (!NT_STATUS_IS_OK(status)) {
			return status;
		}

		ntlmssp_state->crypt->ntlm.seq_num++;

		dump_arc4_state("ntlmssp hash: \n",
				&ntlmssp_state->crypt->ntlm.seal_state);
		rc = gnutls_cipher_encrypt(ntlmssp_state->crypt->ntlm.seal_state,
					   sig->data + 4,
					   sig->length - 4);
		if (rc < 0) {
			DBG_ERR("gnutls_cipher_encrypt for NTLM packet "
				"signature failed: %s\n",
				gnutls_strerror(rc));
			return gnutls_error_to_ntstatus(rc, NT_STATUS_NTLM_BLOCKED);
		}
	}

	return NT_STATUS_OK;
}

NTSTATUS ntlmssp_sign_packet(struct ntlmssp_state *ntlmssp_state,
			     TALLOC_CTX *sig_mem_ctx,
			     const uint8_t *data, size_t length,
			     const uint8_t *whole_pdu, size_t pdu_length,
			     DATA_BLOB *sig)
{
	NTSTATUS nt_status;

	if (!(ntlmssp_state->neg_flags & NTLMSSP_NEGOTIATE_SIGN)) {
		DEBUG(3, ("NTLMSSP Signing not negotiated - cannot sign packet!\n"));
		return NT_STATUS_INVALID_PARAMETER;
	}

	if (!ntlmssp_state->session_key.length) {
		DEBUG(3, ("NO session key, cannot check sign packet\n"));
		return NT_STATUS_NO_USER_SESSION_KEY;
	}

	nt_status = ntlmssp_make_packet_signature(ntlmssp_state,
						  sig_mem_ctx,
						  data, length,
						  whole_pdu, pdu_length,
						  NTLMSSP_SEND, sig, true);

	return nt_status;
}

/**
 * Check the signature of an incoming packet
 * @note caller *must* check that the signature is the size it expects
 *
 */

NTSTATUS ntlmssp_check_packet(struct ntlmssp_state *ntlmssp_state,
			      const uint8_t *data, size_t length,
			      const uint8_t *whole_pdu, size_t pdu_length,
			      const DATA_BLOB *sig)
{
	DATA_BLOB local_sig;
	NTSTATUS nt_status;
	TALLOC_CTX *tmp_ctx;

	if (!ntlmssp_state->session_key.length) {
		DEBUG(3, ("NO session key, cannot check packet signature\n"));
		return NT_STATUS_NO_USER_SESSION_KEY;
	}

	if (sig->length < 8) {
		DEBUG(0, ("NTLMSSP packet check failed due to short signature (%lu bytes)!\n",
			  (unsigned long)sig->length));
	}

	tmp_ctx = talloc_new(ntlmssp_state);
	if (!tmp_ctx) {
		return NT_STATUS_NO_MEMORY;
	}

	nt_status = ntlmssp_make_packet_signature(ntlmssp_state,
						  tmp_ctx,
						  data, length,
						  whole_pdu, pdu_length,
						  NTLMSSP_RECEIVE,
						  &local_sig, true);

	if (!NT_STATUS_IS_OK(nt_status)) {
		DEBUG(0,("NTLMSSP packet sig creation failed with %s\n",
			 nt_errstr(nt_status)));
		talloc_free(tmp_ctx);
		return nt_status;
	}

	if (ntlmssp_state->neg_flags & NTLMSSP_NEGOTIATE_NTLM2) {
		if (local_sig.length != sig->length ||
		    memcmp(local_sig.data, sig->data, sig->length) != 0) {
			DEBUG(5, ("BAD SIG NTLM2: wanted signature of\n"));
			dump_data(5, local_sig.data, local_sig.length);

			DEBUG(5, ("BAD SIG: got signature of\n"));
			dump_data(5, sig->data, sig->length);

			DEBUG(0, ("NTLMSSP NTLM2 packet check failed due to invalid signature!\n"));
			talloc_free(tmp_ctx);
			return NT_STATUS_ACCESS_DENIED;
		}
	} else {
		if (local_sig.length != sig->length ||
		    memcmp(local_sig.data + 8, sig->data + 8, sig->length - 8) != 0) {
			DEBUG(5, ("BAD SIG NTLM1: wanted signature of\n"));
			dump_data(5, local_sig.data, local_sig.length);

			DEBUG(5, ("BAD SIG: got signature of\n"));
			dump_data(5, sig->data, sig->length);

			DEBUG(0, ("NTLMSSP NTLM1 packet check failed due to invalid signature!\n"));
			talloc_free(tmp_ctx);
			return NT_STATUS_ACCESS_DENIED;
		}
	}
	dump_data_pw("checked ntlmssp signature\n", sig->data, sig->length);
	DEBUG(10,("ntlmssp_check_packet: NTLMSSP signature OK !\n"));

	talloc_free(tmp_ctx);
	return NT_STATUS_OK;
}

/**
 * Seal data with the NTLMSSP algorithm
 *
 */

NTSTATUS ntlmssp_seal_packet(struct ntlmssp_state *ntlmssp_state,
			     TALLOC_CTX *sig_mem_ctx,
			     uint8_t *data, size_t length,
			     const uint8_t *whole_pdu, size_t pdu_length,
			     DATA_BLOB *sig)
{
	int rc;

	if (!(ntlmssp_state->neg_flags & NTLMSSP_NEGOTIATE_SEAL)) {
		DEBUG(3, ("NTLMSSP Sealing not negotiated - cannot seal packet!\n"));
		return NT_STATUS_INVALID_PARAMETER;
	}

	if (!(ntlmssp_state->neg_flags & NTLMSSP_NEGOTIATE_SIGN)) {
		DEBUG(3, ("NTLMSSP Sealing not negotiated - cannot seal packet!\n"));
		return NT_STATUS_INVALID_PARAMETER;
	}

	if (!ntlmssp_state->session_key.length) {
		DEBUG(3, ("NO session key, cannot seal packet\n"));
		return NT_STATUS_NO_USER_SESSION_KEY;
	}

	DEBUG(10,("ntlmssp_seal_data: seal\n"));
	dump_data_pw("ntlmssp clear data\n", data, length);
	if (ntlmssp_state->neg_flags & NTLMSSP_NEGOTIATE_NTLM2) {
		NTSTATUS nt_status;
		/*
		 * The order of these two operations matters - we
		 * must first seal the packet, then seal the
		 * sequence number - this is because the
		 * send_seal_hash is not constant, but is is rather
		 * updated with each iteration
		 */
		nt_status = ntlmssp_make_packet_signature(ntlmssp_state,
							  sig_mem_ctx,
							  data, length,
							  whole_pdu, pdu_length,
							  NTLMSSP_SEND,
							  sig, false);
		if (!NT_STATUS_IS_OK(nt_status)) {
			return nt_status;
		}

		rc = gnutls_cipher_encrypt(ntlmssp_state->crypt->ntlm2.sending.seal_state,
					   data,
					   length);
		if (rc < 0) {
			DBG_ERR("gnutls_cipher_encrypt ntlmv2 sealing the data "
				"failed: %s\n",
				gnutls_strerror(rc));
			return gnutls_error_to_ntstatus(rc, NT_STATUS_NTLM_BLOCKED);
		}
		if (ntlmssp_state->neg_flags & NTLMSSP_NEGOTIATE_KEY_EXCH) {
			rc = gnutls_cipher_encrypt(ntlmssp_state->crypt->ntlm2.sending.seal_state,
						    sig->data + 4,
						    8);
			if (rc < 0) {
				DBG_ERR("gnutls_cipher_encrypt ntlmv2 sealing "
					"the EXCH signature data failed: %s\n",
					gnutls_strerror(rc));
				return gnutls_error_to_ntstatus(rc, NT_STATUS_NTLM_BLOCKED);
			}
		}
	} else {
		NTSTATUS status;
		uint32_t crc;

		crc = crc32(0, Z_NULL, 0);
		crc = crc32(crc, data, length);

		status = msrpc_gen(sig_mem_ctx,
			       sig, "dddd",
			       NTLMSSP_SIGN_VERSION, 0, crc,
			       ntlmssp_state->crypt->ntlm.seq_num);
		if (!NT_STATUS_IS_OK(status)) {
			return status;
		}

		/*
		 * The order of these two operations matters - we
		 * must first seal the packet, then seal the
		 * sequence number - this is because the ntlmv1_arc4_state
		 * is not constant, but is is rather updated with
		 * each iteration
		 */
		dump_arc4_state("ntlmv1 arc4 state:\n",
				&ntlmssp_state->crypt->ntlm.seal_state);
		rc = gnutls_cipher_encrypt(ntlmssp_state->crypt->ntlm.seal_state,
					   data,
					   length);
		if (rc < 0) {
			DBG_ERR("gnutls_cipher_encrypt ntlmv1 sealing data"
				"failed: %s\n",
				gnutls_strerror(rc));
			return gnutls_error_to_ntstatus(rc, NT_STATUS_NTLM_BLOCKED);
		}

		dump_arc4_state("ntlmv1 arc4 state:\n",
				&ntlmssp_state->crypt->ntlm.seal_state);

		rc = gnutls_cipher_encrypt(ntlmssp_state->crypt->ntlm.seal_state,
					    sig->data + 4,
					    sig->length - 4);
		if (rc < 0) {
			DBG_ERR("gnutls_cipher_encrypt ntlmv1 sealing signing "
				"data failed: %s\n",
				gnutls_strerror(rc));
			return gnutls_error_to_ntstatus(rc, NT_STATUS_NTLM_BLOCKED);
		}

		ntlmssp_state->crypt->ntlm.seq_num++;
	}
	dump_data_pw("ntlmssp signature\n", sig->data, sig->length);
	dump_data_pw("ntlmssp sealed data\n", data, length);

	return NT_STATUS_OK;
}

/**
 * Unseal data with the NTLMSSP algorithm
 *
 */

NTSTATUS ntlmssp_unseal_packet(struct ntlmssp_state *ntlmssp_state,
			       uint8_t *data, size_t length,
			       const uint8_t *whole_pdu, size_t pdu_length,
			       const DATA_BLOB *sig)
{
	NTSTATUS status;
	int rc;

	if (!ntlmssp_state->session_key.length) {
		DEBUG(3, ("NO session key, cannot unseal packet\n"));
		return NT_STATUS_NO_USER_SESSION_KEY;
	}

	DEBUG(10,("ntlmssp_unseal_packet: seal\n"));
	dump_data_pw("ntlmssp sealed data\n", data, length);

	if (ntlmssp_state->neg_flags & NTLMSSP_NEGOTIATE_NTLM2) {
		/* First unseal the data. */
		rc = gnutls_cipher_decrypt(ntlmssp_state->crypt->ntlm2.receiving.seal_state,
					   data,
					   length);
		if (rc < 0) {
			DBG_ERR("gnutls_cipher_decrypt ntlmv2 unsealing the "
				"data failed: %s\n",
				gnutls_strerror(rc));
			return gnutls_error_to_ntstatus(rc, NT_STATUS_NTLM_BLOCKED);
		}
		dump_data_pw("ntlmv2 clear data\n", data, length);
	} else {
		rc = gnutls_cipher_decrypt(ntlmssp_state->crypt->ntlm.seal_state,
					   data,
					   length);
		if (rc < 0) {
			DBG_ERR("gnutls_cipher_decrypt ntlmv1 unsealing the "
				"data failed: %s\n",
				gnutls_strerror(rc));
			return gnutls_error_to_ntstatus(rc, NT_STATUS_NTLM_BLOCKED);
		}
		dump_data_pw("ntlmv1 clear data\n", data, length);
	}

	status = ntlmssp_check_packet(ntlmssp_state,
				      data, length,
				      whole_pdu, pdu_length,
				      sig);

	if (!NT_STATUS_IS_OK(status)) {
		DEBUG(1,("NTLMSSP packet check for unseal failed due to invalid signature on %llu bytes of input:\n",
			 (unsigned long long)length));
	}
	return status;
}

NTSTATUS ntlmssp_wrap(struct ntlmssp_state *ntlmssp_state,
		      TALLOC_CTX *out_mem_ctx,
		      const DATA_BLOB *in,
		      DATA_BLOB *out)
{
	NTSTATUS nt_status;
	DATA_BLOB sig;

	if (ntlmssp_state->neg_flags & NTLMSSP_NEGOTIATE_SEAL) {
		if (in->length + NTLMSSP_SIG_SIZE < in->length) {
			return NT_STATUS_INVALID_PARAMETER;
		}

		*out = data_blob_talloc(out_mem_ctx, NULL, in->length + NTLMSSP_SIG_SIZE);
		if (!out->data) {
			return NT_STATUS_NO_MEMORY;
		}
		memcpy(out->data + NTLMSSP_SIG_SIZE, in->data, in->length);

	        nt_status = ntlmssp_seal_packet(ntlmssp_state, out_mem_ctx,
						out->data + NTLMSSP_SIG_SIZE,
						out->length - NTLMSSP_SIG_SIZE,
						out->data + NTLMSSP_SIG_SIZE,
						out->length - NTLMSSP_SIG_SIZE,
						&sig);

		if (NT_STATUS_IS_OK(nt_status)) {
			memcpy(out->data, sig.data, NTLMSSP_SIG_SIZE);
			talloc_free(sig.data);
		}
		return nt_status;

	} else if (ntlmssp_state->neg_flags & NTLMSSP_NEGOTIATE_SIGN) {
		if (in->length + NTLMSSP_SIG_SIZE < in->length) {
			return NT_STATUS_INVALID_PARAMETER;
		}

		*out = data_blob_talloc(out_mem_ctx, NULL, in->length + NTLMSSP_SIG_SIZE);
		if (!out->data) {
			return NT_STATUS_NO_MEMORY;
		}
		memcpy(out->data + NTLMSSP_SIG_SIZE, in->data, in->length);

	        nt_status = ntlmssp_sign_packet(ntlmssp_state, out_mem_ctx,
						out->data + NTLMSSP_SIG_SIZE,
						out->length - NTLMSSP_SIG_SIZE,
						out->data + NTLMSSP_SIG_SIZE,
						out->length - NTLMSSP_SIG_SIZE,
						&sig);

		if (NT_STATUS_IS_OK(nt_status)) {
			memcpy(out->data, sig.data, NTLMSSP_SIG_SIZE);
			talloc_free(sig.data);
		}
		return nt_status;
	} else {
		*out = data_blob_talloc(out_mem_ctx, in->data, in->length);
		if (!out->data) {
			return NT_STATUS_NO_MEMORY;
		}
		return NT_STATUS_OK;
	}
}

NTSTATUS ntlmssp_unwrap(struct ntlmssp_state *ntlmssp_state,
			TALLOC_CTX *out_mem_ctx,
			const DATA_BLOB *in,
			DATA_BLOB *out)
{
	DATA_BLOB sig;

	if (ntlmssp_state->neg_flags & NTLMSSP_NEGOTIATE_SEAL) {
		if (in->length < NTLMSSP_SIG_SIZE) {
			return NT_STATUS_INVALID_PARAMETER;
		}
		sig.data = in->data;
		sig.length = NTLMSSP_SIG_SIZE;

		*out = data_blob_talloc(out_mem_ctx, in->data + NTLMSSP_SIG_SIZE, in->length - NTLMSSP_SIG_SIZE);

	        return ntlmssp_unseal_packet(ntlmssp_state,
					     out->data, out->length,
					     out->data, out->length,
					     &sig);

	} else if (ntlmssp_state->neg_flags & NTLMSSP_NEGOTIATE_SIGN) {
		if (in->length < NTLMSSP_SIG_SIZE) {
			return NT_STATUS_INVALID_PARAMETER;
		}
		sig.data = in->data;
		sig.length = NTLMSSP_SIG_SIZE;

		*out = data_blob_talloc(out_mem_ctx, in->data + NTLMSSP_SIG_SIZE, in->length - NTLMSSP_SIG_SIZE);

		return ntlmssp_check_packet(ntlmssp_state,
					    out->data, out->length,
					    out->data, out->length,
					    &sig);
	} else {
		*out = data_blob_talloc(out_mem_ctx, in->data, in->length);
		if (!out->data) {
			return NT_STATUS_NO_MEMORY;
		}
		return NT_STATUS_OK;
	}
}

/**
   Initialise the state for NTLMSSP signing.
*/
NTSTATUS ntlmssp_sign_reset(struct ntlmssp_state *ntlmssp_state,
			    bool reset_seqnums)
{
	int rc;

	DEBUG(3, ("NTLMSSP Sign/Seal - Initialising with flags:\n"));
	debug_ntlmssp_flags(ntlmssp_state->neg_flags);

	if (ntlmssp_state->crypt == NULL) {
		return NT_STATUS_INVALID_PARAMETER_MIX;
	}

	if (ntlmssp_state->force_wrap_seal &&
	    (ntlmssp_state->neg_flags & NTLMSSP_NEGOTIATE_SIGN))
	{
		/*
		 * We need to handle NTLMSSP_NEGOTIATE_SIGN as
		 * NTLMSSP_NEGOTIATE_SEAL if GENSEC_FEATURE_LDAP_STYLE
		 * is requested.
		 *
		 * The negotiation of flags (and authentication)
		 * is completed when ntlmssp_sign_init() is called
		 * so we can safely pretent NTLMSSP_NEGOTIATE_SEAL
		 * was negotiated.
		 */
		ntlmssp_state->neg_flags |= NTLMSSP_NEGOTIATE_SEAL;
	}

	if (ntlmssp_state->neg_flags & NTLMSSP_NEGOTIATE_NTLM2) {
		DATA_BLOB weak_session_key = ntlmssp_state->session_key;
		const char *send_sign_const;
		const char *send_seal_const;
		const char *recv_sign_const;
		const char *recv_seal_const;
		uint8_t send_seal_key[16] = {0};
		gnutls_datum_t send_seal_blob = {
			.data = send_seal_key,
			.size = sizeof(send_seal_key),
		};
		uint8_t recv_seal_key[16] = {0};
		gnutls_datum_t recv_seal_blob = {
			.data = recv_seal_key,
			.size = sizeof(recv_seal_key),
		};
		NTSTATUS status;

		switch (ntlmssp_state->role) {
		case NTLMSSP_CLIENT:
			send_sign_const = CLI_SIGN;
			send_seal_const = CLI_SEAL;
			recv_sign_const = SRV_SIGN;
			recv_seal_const = SRV_SEAL;
			break;
		case NTLMSSP_SERVER:
			send_sign_const = SRV_SIGN;
			send_seal_const = SRV_SEAL;
			recv_sign_const = CLI_SIGN;
			recv_seal_const = CLI_SEAL;
			break;
		default:
			return NT_STATUS_INTERNAL_ERROR;
		}

		/*
		 * Weaken NTLMSSP keys to cope with down-level
		 * clients, servers and export restrictions.
		 *
		 * We probably should have some parameters to
		 * control this, once we get NTLM2 working.
		 *
		 * Key weakening was not performed on the master key
		 * for NTLM2, but must be done on the encryption subkeys only.
		 */

		if (ntlmssp_state->neg_flags & NTLMSSP_NEGOTIATE_128) {
			/* nothing to do */
		} else if (ntlmssp_state->neg_flags & NTLMSSP_NEGOTIATE_56) {
			weak_session_key.length = 7;
		} else { /* forty bits */
			weak_session_key.length = 5;
		}

		dump_data_pw("NTLMSSP weakend master key:\n",
			     weak_session_key.data,
			     weak_session_key.length);

		/* SEND: sign key */
		status = calc_ntlmv2_key(ntlmssp_state->crypt->ntlm2.sending.sign_key,
					 ntlmssp_state->session_key, send_sign_const);
		if (!NT_STATUS_IS_OK(status)) {
			return status;
		}
		dump_data_pw("NTLMSSP send sign key:\n",
			     ntlmssp_state->crypt->ntlm2.sending.sign_key, 16);

		/* SEND: seal ARCFOUR pad */
		status = calc_ntlmv2_key(send_seal_key,
					 weak_session_key,
					 send_seal_const);
		if (!NT_STATUS_IS_OK(status)) {
			return status;
		}
		dump_data_pw("NTLMSSP send seal key:\n",
			     send_seal_key,
			     sizeof(send_seal_key));

		if (ntlmssp_state->crypt->ntlm2.sending.seal_state != NULL) {
			gnutls_cipher_deinit(ntlmssp_state->crypt->ntlm2.sending.seal_state);
		}
		rc = gnutls_cipher_init(&ntlmssp_state->crypt->ntlm2.sending.seal_state,
					GNUTLS_CIPHER_ARCFOUR_128,
					&send_seal_blob,
					NULL);
		if (rc < 0) {
			DBG_ERR("gnutls_cipher_init failed: %s\n",
				gnutls_strerror(rc));
			return gnutls_error_to_ntstatus(rc, NT_STATUS_NTLM_BLOCKED);
		}

		dump_arc4_state("NTLMSSP send seal arc4 state:\n",
				&ntlmssp_state->crypt->ntlm2.sending.seal_state);

		/* SEND: seq num */
		if (reset_seqnums) {
			ntlmssp_state->crypt->ntlm2.sending.seq_num = 0;
		}

		/* RECV: sign key */
		status = calc_ntlmv2_key(ntlmssp_state->crypt->ntlm2.receiving.sign_key,
					 ntlmssp_state->session_key, recv_sign_const);
		if (!NT_STATUS_IS_OK(status)) {
			return status;
		}
		dump_data_pw("NTLMSSP recv sign key:\n",
			     ntlmssp_state->crypt->ntlm2.receiving.sign_key, 16);

		/* RECV: seal ARCFOUR pad */
		status = calc_ntlmv2_key(recv_seal_key,
					 weak_session_key,
					 recv_seal_const);
		if (!NT_STATUS_IS_OK(status)) {
			return status;
		}
		dump_data_pw("NTLMSSP recv seal key:\n",
			     recv_seal_key,
			     sizeof(recv_seal_key));

		if (ntlmssp_state->crypt->ntlm2.receiving.seal_state != NULL) {
			gnutls_cipher_deinit(ntlmssp_state->crypt->ntlm2.receiving.seal_state);
		}
		rc = gnutls_cipher_init(&ntlmssp_state->crypt->ntlm2.receiving.seal_state,
					GNUTLS_CIPHER_ARCFOUR_128,
					&recv_seal_blob,
					NULL);
		if (rc < 0) {
			DBG_ERR("gnutls_cipher_init failed: %s\n",
				gnutls_strerror(rc));
			return gnutls_error_to_ntstatus(rc, NT_STATUS_NTLM_BLOCKED);
		}

		dump_arc4_state("NTLMSSP recv seal arc4 state:\n",
				&ntlmssp_state->crypt->ntlm2.receiving.seal_state);

		/* RECV: seq num */
		if (reset_seqnums) {
			ntlmssp_state->crypt->ntlm2.receiving.seq_num = 0;
		}
	} else {
		gnutls_datum_t seal_session_key = {
			.data = ntlmssp_state->session_key.data,
			.size = ntlmssp_state->session_key.length,
		};
		bool do_weak = false;

		DEBUG(5, ("NTLMSSP Sign/Seal - using NTLM1\n"));

		/*
		 * Key weakening not performed on the master key for NTLM2
		 * and does not occour for NTLM1. Therefore we only need
		 * to do this for the LM_KEY.
		 */
		if (ntlmssp_state->neg_flags & NTLMSSP_NEGOTIATE_LM_KEY) {
			do_weak = true;
		}

		/*
		 * Nothing to weaken.
		 * We certainly don't want to 'extend' the length...
		 */
		if (ntlmssp_state->session_key.length < 16) {
			/* TODO: is this really correct? */
			do_weak = false;
		}

		if (do_weak) {
			uint8_t weak_session_key[8];

			memcpy(weak_session_key, seal_session_key.data, 8);
			seal_session_key = (gnutls_datum_t) {
				.data = weak_session_key,
				.size = sizeof(weak_session_key),
			};

			/*
			 * LM key doesn't support 128 bit crypto, so this is
			 * the best we can do. If you negotiate 128 bit, but
			 * not 56, you end up with 40 bit...
			 */
			if (ntlmssp_state->neg_flags & NTLMSSP_NEGOTIATE_56) {
				weak_session_key[7] = 0xa0;
			} else { /* forty bits */
				weak_session_key[5] = 0xe5;
				weak_session_key[6] = 0x38;
				weak_session_key[7] = 0xb0;
			}
		}

		if (ntlmssp_state->crypt->ntlm.seal_state != NULL) {
			gnutls_cipher_deinit(ntlmssp_state->crypt->ntlm.seal_state);
		}
		rc = gnutls_cipher_init(&ntlmssp_state->crypt->ntlm.seal_state,
					GNUTLS_CIPHER_ARCFOUR_128,
					&seal_session_key,
					NULL);
		if (rc < 0) {
			DBG_ERR("gnutls_cipher_init failed: %s\n",
				gnutls_strerror(rc));
			return gnutls_error_to_ntstatus(rc, NT_STATUS_NTLM_BLOCKED);
		}

		dump_arc4_state("NTLMv1 arc4 state:\n",
				&ntlmssp_state->crypt->ntlm.seal_state);

		if (reset_seqnums) {
			ntlmssp_state->crypt->ntlm.seq_num = 0;
		}
	}

	return NT_STATUS_OK;
}

static int ntlmssp_crypt_free_gnutls_cipher_state(union ntlmssp_crypt_state *c)
{
	if (c->ntlm2.sending.seal_state != NULL) {
		gnutls_cipher_deinit(c->ntlm2.sending.seal_state);
		c->ntlm2.sending.seal_state = NULL;
	}
	if (c->ntlm2.receiving.seal_state != NULL) {
		gnutls_cipher_deinit(c->ntlm2.receiving.seal_state);
		c->ntlm2.receiving.seal_state = NULL;
	}
	if (c->ntlm.seal_state != NULL) {
		gnutls_cipher_deinit(c->ntlm.seal_state);
		c->ntlm.seal_state = NULL;
	}

	return 0;
}

NTSTATUS ntlmssp_sign_init(struct ntlmssp_state *ntlmssp_state)
{
	if (ntlmssp_state->session_key.length < 8) {
		DEBUG(3, ("NO session key, cannot initialise signing\n"));
		return NT_STATUS_NO_USER_SESSION_KEY;
	}

	ntlmssp_state->crypt = talloc_zero(ntlmssp_state,
					   union ntlmssp_crypt_state);
	if (ntlmssp_state->crypt == NULL) {
		return NT_STATUS_NO_MEMORY;
	}
	talloc_set_destructor(ntlmssp_state->crypt,
			      ntlmssp_crypt_free_gnutls_cipher_state);

	return ntlmssp_sign_reset(ntlmssp_state, true);
}
