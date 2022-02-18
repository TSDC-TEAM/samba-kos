set(TARGET_NAME hx509)

set(TARGET_SRC
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/asn1/asn1_pkcs12_asn1.c
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/asn1/asn1_pkcs9_asn1.c
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/hx509/asn1_pkcs10_asn1.c
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/asn1/asn1_pkcs8_asn1.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hx509/ca.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hx509/cert.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hx509/cms.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hx509/collector.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hx509/crypto.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hx509/error.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hx509/env.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hx509/file.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hx509/keyset.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hx509/ks_dir.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hx509/ks_file.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hx509/ks_keychain.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hx509/ks_mem.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hx509/ks_null.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hx509/ks_p11.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hx509/ks_p12.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hx509/lock.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hx509/name.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hx509/peer.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hx509/print.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hx509/req.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hx509/revoke.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hx509/sel.c
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/hx509/hx509_err.c
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/hx509/sel-lex.lex.c
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/hx509/sel-gram.tab.c
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/hx509/asn1_ocsp_asn1.c
        )

add_library(
        ${TARGET_NAME}
        STATIC
        ${TARGET_SRC}
)

target_include_directories(
        ${TARGET_NAME}
        PRIVATE
        ${SMB_SRC_ROOT}/source4/heimdal_build
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal_build
        ${SMB_SRC_ROOT}/source4/heimdal/lib/asn1
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/asn1
        ${SMB_SRC_ROOT}/include/public
        ${SMB_SRC_ROOT}/bin/default/include/public
        ${SMB_SRC_ROOT}/source4
        ${SMB_SRC_ROOT}/bin/default/source4
        ${SMB_SRC_ROOT}/lib
        ${SMB_SRC_ROOT}/bin/default/lib
        ${SMB_SRC_ROOT}/source4/lib
        ${SMB_SRC_ROOT}/bin/default/source4/lib
        ${SMB_SRC_ROOT}/source4/include
        ${SMB_SRC_ROOT}/bin/default/source4/include
        ${SMB_SRC_ROOT}/include
        ${SMB_SRC_ROOT}/bin/default/include
        ${SMB_SRC_ROOT}/lib/replace
        ${SMB_SRC_ROOT}/bin/default/lib/replace
        ${SMB_SRC_ROOT}/.
        ${SMB_SRC_ROOT}/bin/default/
        ${SMB_SRC_ROOT}/source4/heimdal/lib/roken
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/roken
        ${SMB_SRC_ROOT}/source4/heimdal/include
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/include
        ${SMB_SRC_ROOT}/source4/heimdal_build/include
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal_build/include
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hx509
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/hx509
        ${SMB_SRC_ROOT}/source4/heimdal/lib/wind
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/wind
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/hcrypto
        ${SMB_SRC_ROOT}/source4/heimdal/lib
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/hcrypto/libtommath
        ${SMB_SRC_ROOT}/source4/heimdal/lib/com_err
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/com_err
)

target_compile_definitions(
        ${TARGET_NAME}
        PRIVATE
        _SAMBA_BUILD_=4
        HAVE_CONFIG_H=1
        _GNU_SOURCE=1
        _XOPEN_SOURCE_EXTENDED=1
        __STDC_WANT_LIB_EXT1__=1
        _REENTRANT
        _POSIX_PTHREAD_SEMANTICS
        STATIC_HEIMDAL_PKCS12_ASN1_MODULES=NULL
        "STATIC_HEIMDAL_PKCS12_ASN1_MODULES_PROTO=extern void __HEIMDAL_PKCS12_ASN1_dummy_module_proto(void)"
        STATIC_HEIMDAL_PKCS9_ASN1_MODULES=NULL
        "STATIC_HEIMDAL_PKCS9_ASN1_MODULES_PROTO=extern void __HEIMDAL_PKCS9_ASN1_dummy_module_proto(void)"
        STATIC_HEIMDAL_PKCS10_ASN1_MODULES=NULL
        "STATIC_HEIMDAL_PKCS10_ASN1_MODULES_PROTO=extern void __HEIMDAL_PKCS10_ASN1_dummy_module_proto(void)"
        STATIC_HEIMDAL_PKCS8_ASN1_MODULES=NULL
        "STATIC_HEIMDAL_PKCS8_ASN1_MODULES_PROTO=extern void __HEIMDAL_PKCS8_ASN1_dummy_module_proto(void)"
        STATIC_hx509_MODULES=NULL
        "STATIC_hx509_MODULES_PROTO=extern void __hx509_dummy_module_proto(void)"
        STATIC_HEIMDAL_OCSP_ASN1_MODULES=NULL
        "STATIC_HEIMDAL_OCSP_ASN1_MODULES_PROTO=extern void __HEIMDAL_OCSP_ASN1_dummy_module_proto(void)"
)

target_compile_options(
        ${TARGET_NAME}
        PRIVATE
        -MMD
        -fPIC
        -fstack-protector-strong
        -fstack-clash-protection
        -Wno-error=discarded-qualifiers
        -Wno-error=cast-qual
        -Wno-error=missing-field-initializers
        -Wno-error=shadow
        -Wno-error=implicit-fallthrough
        -Wno-error=enum-compare
        -Wno-error=unused-but-set-variable
        -Wno-error=unused-const-variable
        -Wno-error=unused-variable
        -Wno-error=unused-result
)
