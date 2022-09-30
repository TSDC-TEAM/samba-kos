project(samba)

set(TARGET_NAME Smbclient)

set(TARGET_EDL samba_smbclient)

set(TARGET_SRC
        ${SMB_SRC_ROOT}/source3/client/client.c
        ${SMB_SRC_ROOT}/lib/cmdline/cmdline.c
        ${SMB_SRC_ROOT}/lib/cmdline/cmdline_s4.c
        ${SMB_SRC_ROOT}/source3/client/clitar.c
        ${SMB_SRC_ROOT}/source3/client/dnsbrowse.c
        ${SMB_SRC_ROOT}/libcli/smbreadline/smbreadline.c
        ${SMB_SRC_ROOT}/source3/smbd/kos/kos_thread.c
)

set(TARGET_LIBS
        ${SAMBA_EXT_MODULES}
        ${SAMBA_THIRD_PARTY_LIBS}
)

if (KOS)
    # Setting compilation flags.
    project_header_default ("STANDARD_GNU_11:YES" "STRICT_WARNINGS:NO")

    nk_build_edl_files (${TARGET_EDL}
            NK_MODULE ${PROJECT_NAME}
            EDL ${TARGET_NAME}.edl)

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexceptions")

    add_executable(${TARGET_NAME} ${TARGET_SRC} ${EDL_FILES})

    add_dependencies(${TARGET_NAME} ${TARGET_EDL})

    target_link_libraries(${TARGET_NAME} ${TARGET_LIBS} ${vfs_CLIENT_LIB})

    # We do not need default VFS entity here, which comes from ${vfs_CLIENT_LIB}
    set_target_properties (${TARGET_NAME} PROPERTIES ${vfs_ENTITY}_REPLACEMENT "")
else ()
    add_executable(${TARGET_NAME} ${TARGET_SRC})

    if (TARGET_LIBS)
        target_link_libraries(${TARGET_NAME} ${TARGET_LIBS})
    endif ()
endif ()

target_include_directories(
        ${TARGET_NAME}
        PRIVATE
        ${SMB_SRC_ROOT}
        ${SMB_SRC_ROOT}/lib
        ${SMB_SRC_ROOT}/lib/tsocket
        ${SMB_SRC_ROOT}/lib/replace
        ${SMB_SRC_ROOT}/lib/talloc
        ${SMB_SRC_ROOT}/lib/tevent
        ${SMB_SRC_ROOT}/lib/ldb-samba
        ${SMB_SRC_ROOT}/lib/ldb/include
        ${SMB_SRC_ROOT}/lib/tdb/include
        ${SMB_SRC_ROOT}/include
        ${SMB_SRC_ROOT}/include/public
        ${SMB_SRC_ROOT}/source3
        ${SMB_SRC_ROOT}/source3/lib
        ${SMB_SRC_ROOT}/source3/include
        ${SMB_SRC_ROOT}/source4/heimdal_build
        ${SMB_SRC_ROOT}/source4/heimdal_build/include
        ${SMB_SRC_ROOT}/source4/heimdal/lib
        ${SMB_SRC_ROOT}/source4/heimdal/base
        ${SMB_SRC_ROOT}/source4/heimdal/lib/krb5
        ${SMB_SRC_ROOT}/source4/heimdal/lib/roken
        ${SMB_SRC_ROOT}/source4/heimdal/lib/com_err
        ${SMB_SRC_ROOT}/source4/heimdal/lib/asn1
        ${SMB_SRC_ROOT}/source4/heimdal/lib/wind
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hx509
        ${SMB_SRC_ROOT}/source4/heimdal/lib/gssapi
        ${SMB_SRC_ROOT}/source4/heimdal/lib/gssapi/gssapi
        ${SMB_SRC_ROOT}/source4/heimdal/lib/gssapi/mech
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto
        ${SMB_SRC_ROOT}/source4/heimdal/lib/hcrypto/libtommath
        ${SMB_SRC_ROOT}/source4/heimdal/include
        ${SMB_SRC_ROOT}/third_party/gpfs
        ${SMB_SRC_ROOT}/bin/default
        ${SMB_SRC_ROOT}/bin/default/source3
        ${SMB_SRC_ROOT}/bin/default/include
        ${SMB_SRC_ROOT}/bin/default/include/public
        ${SMB_SRC_ROOT}/bin/default/lib/ldb/include
        ${SMB_SRC_ROOT}/bin/default/librpc/
        ${SMB_SRC_ROOT}/bin/default/source4
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/asn1
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/wind
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/hx509
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/krb5
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/gssapi
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/gssapi/spnego
        ${SMB_SRC_ROOT}/bin/default/source4/heimdal/lib/gssapi/krb5
)

target_compile_definitions(
        ${TARGET_NAME}
        PRIVATE
        _SAMBA_BUILD_=4
        HAVE_CONFIG_H=1
        _GNU_SOURCE=1
        _XOPEN_SOURCE_EXTENDED=1
        HAVE_CONFIG_H=1
        __STDC_WANT_LIB_EXT1__=1
        _REENTRANT
)

add_dependencies(${TARGET_NAME} shareconfig)

install(TARGETS ${TARGET_NAME})
