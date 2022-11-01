set(TARGET_NAME asn1)

set(TARGET_SRC
        ${SMB_SRC_ROOT}/source4/heimdal/lib/asn1/der_get.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/asn1/der_put.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/asn1/der_free.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/asn1/der_format.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/asn1/der_length.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/asn1/der_copy.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/asn1/der_cmp.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/asn1/extra.c
        ${SMB_SRC_ROOT}/source4/heimdal/lib/asn1/timegm.c
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/asn1/asn1_err.c
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/asn1/asn1_pkinit_asn1.c
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/asn1/asn1_cms_asn1.c
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal_build/asn1.objlist.empty.c
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/asn1/asn1_rfc2459_asn1.c
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/asn1/asn1_krb5_asn1.c
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
        STATIC_HEIMDAL_HEIM_ASN1_MODULES=NULL
        "STATIC_HEIMDAL_HEIM_ASN1_MODULES_PROTO=extern void __HEIMDAL_HEIM_ASN1_dummy_module_proto(void)"
        STATIC_HEIMDAL_PKINIT_ASN1_MODULES=NULL
        "STATIC_HEIMDAL_PKINIT_ASN1_MODULES_PROTO=extern void __HEIMDAL_PKINIT_ASN1_dummy_module_proto(void)"
        STATIC_HEIMDAL_CMS_ASN1_MODULES=NULL
        "STATIC_HEIMDAL_CMS_ASN1_MODULES_PROTO=extern void __HEIMDAL_CMS_ASN1_dummy_module_proto(void)"
        STATIC_asn1_MODULES=NULL
        "STATIC_asn1_MODULES_PROTO=extern void __asn1_dummy_module_proto(void)"
        STATIC_HEIMDAL_RFC2459_ASN1_MODULES=NULL
        "STATIC_HEIMDAL_RFC2459_ASN1_MODULES_PROTO=extern void __HEIMDAL_RFC2459_ASN1_dummy_module_proto(void)"
        STATIC_HEIMDAL_KRB5_ASN1_MODULES=NULL
        "STATIC_HEIMDAL_KRB5_ASN1_MODULES_PROTO=extern void __HEIMDAL_KRB5_ASN1_dummy_module_proto(void)"
)

target_compile_options(
        ${TARGET_NAME}
        PRIVATE
        -MMD
        -fPIC
        -fstack-protector-strong
        ${GCCDEFS}
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
        -Wno-format-truncation
)
