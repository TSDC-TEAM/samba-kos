set(TARGET_NAME samba-util)

set(TARGET_SRC
        ${SMB_SRC_ROOT}/lib/util/tiniparser.c
        ${SMB_SRC_ROOT}/lib/util/fault.c
        ${SMB_SRC_ROOT}/lib/util/signal.c
        ${SMB_SRC_ROOT}/lib/util/charset/codepoints.c
        ${SMB_SRC_ROOT}/lib/util/charset/convert_string.c
        ${SMB_SRC_ROOT}/lib/util/charset/util_str.c
        ${SMB_SRC_ROOT}/lib/util/charset/util_unistr_w.c
        ${SMB_SRC_ROOT}/lib/util/charset/pull_push.c
        ${SMB_SRC_ROOT}/lib/util/charset/util_unistr.c
        ${SMB_SRC_ROOT}/lib/crypto/aes_cmac_128.c
        ${SMB_SRC_ROOT}/dynconfig/dynconfig.c
        ${SMB_SRC_ROOT}/lib/util/strv.c
        ${SMB_SRC_ROOT}/lib/util/util_str_hex.c
        ${SMB_SRC_ROOT}/lib/util/charset/iconv.c
        ${SMB_SRC_ROOT}/lib/util/charset/weird.c
        ${SMB_SRC_ROOT}/lib/util/charset/charset_macosxfs.c
        ${SMB_SRC_ROOT}/lib/crypto/md4.c
        ${SMB_SRC_ROOT}/lib/util/data_blob.c
        ${SMB_SRC_ROOT}/lib/util/util_file.c
        ${SMB_SRC_ROOT}/lib/util/sys_popen.c
        ${SMB_SRC_ROOT}/lib/util/time.c
        ${SMB_SRC_ROOT}/lib/util/util.c
        ${SMB_SRC_ROOT}/lib/util/idtree.c
        ${SMB_SRC_ROOT}/lib/util/substitute.c
        ${SMB_SRC_ROOT}/lib/util/util_process.c
        ${SMB_SRC_ROOT}/lib/util/util_strlist.c
        ${SMB_SRC_ROOT}/lib/util/strv_util.c
        ${SMB_SRC_ROOT}/lib/util/bitmap.c
        ${SMB_SRC_ROOT}/lib/util/select.c
        ${SMB_SRC_ROOT}/lib/util/pidfile.c
        ${SMB_SRC_ROOT}/lib/util/become_daemon.c
        ${SMB_SRC_ROOT}/lib/util/mkdir_p.c
        ${SMB_SRC_ROOT}/lib/util/smb_strtox.c
        ${SMB_SRC_ROOT}/lib/util/tini.c
        ${SMB_SRC_ROOT}/lib/util/base64.c
        ${SMB_SRC_ROOT}/lib/util/dprintf.c
        ${SMB_SRC_ROOT}/lib/util/fsusage.c
        ${SMB_SRC_ROOT}/lib/util/genrand_util.c
        ${SMB_SRC_ROOT}/lib/util/getpass.c
        ${SMB_SRC_ROOT}/lib/util/idtree_random.c
        ${SMB_SRC_ROOT}/lib/util/memcache.c
        ${SMB_SRC_ROOT}/lib/util/ms_fnmatch.c
        ${SMB_SRC_ROOT}/lib/util/params.c
        ${SMB_SRC_ROOT}/lib/util/rbtree.c
        ${SMB_SRC_ROOT}/lib/util/rfc1738.c
        ${SMB_SRC_ROOT}/lib/util/server_id.c
        ${SMB_SRC_ROOT}/lib/util/smb_threads.c
        ${SMB_SRC_ROOT}/lib/util/system.c
        ${SMB_SRC_ROOT}/lib/util/talloc_keep_secret.c
        ${SMB_SRC_ROOT}/lib/util/talloc_stack.c
        ${SMB_SRC_ROOT}/lib/util/tevent_debug.c
        ${SMB_SRC_ROOT}/lib/util/tfork.c
        ${SMB_SRC_ROOT}/lib/util/tftw.c
        ${SMB_SRC_ROOT}/lib/util/unix_match.c
        ${SMB_SRC_ROOT}/lib/util/util_id.c
        ${SMB_SRC_ROOT}/lib/util/util_net.c
        ${SMB_SRC_ROOT}/lib/util/util_paths.c
        ${SMB_SRC_ROOT}/lib/util/util_str.c
        ${SMB_SRC_ROOT}/lib/util/util_str_common.c
        ${SMB_SRC_ROOT}/lib/util/util_strlist_v3.c
        ${SMB_SRC_ROOT}/lib/crypto/aes.c
        ${SMB_SRC_ROOT}/lib/crypto/rijndael-alg-fst.c
        )

add_library(
        ${TARGET_NAME}
        STATIC
        ${TARGET_SRC}
)

target_include_directories(
        ${TARGET_NAME}
        PRIVATE
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
        ${SMB_SRC_ROOT}/lib/talloc
        ${SMB_SRC_ROOT}/bin/default/lib/talloc
        ${SMB_SRC_ROOT}/lib/util/home/user/samba-of-pred-kos-2/third_party/gpfs
        ${SMB_SRC_ROOT}/bin/default/lib/util/home/user/samba-of-pred-kos-2/third_party/gpfs
        ${SMB_SRC_ROOT}/lib/util/charset
        ${SMB_SRC_ROOT}/bin/default/lib/util/charset
        ${SMB_SRC_ROOT}/dynconfig
        ${SMB_SRC_ROOT}/bin/default/dynconfig
        ${SMB_SRC_ROOT}/lib/crypto
        ${SMB_SRC_ROOT}/bin/default/lib/crypto
        ${SMB_SRC_ROOT}/lib/tevent
        ${SMB_SRC_ROOT}/bin/default/lib/tevent
        /usr/include/p11-kit-1
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
        STATIC_tiniparser_MODULES=NULL
        "STATIC_tiniparser_MODULES_PROTO=extern void __tiniparser_dummy_module_proto(void)"
        STATIC_smb_panic_MODULES=NULL
        "STATIC_smb_panic_MODULES_PROTO=extern void __smb_panic_dummy_module_proto(void)"
        STATIC_charset_MODULES=NULL
        "STATIC_charset_MODULES_PROTO=extern void __charset_dummy_module_proto(void)"
        STATIC_LIBCRYPTO_AES_CMAC_MODULES=NULL
        "STATIC_LIBCRYPTO_AES_CMAC_MODULES_PROTO=extern void __LIBCRYPTO_AES_CMAC_dummy_module_proto(void)"
        BINDIR="/home/user/samba-of-pred-kos-2/bin"
        SBINDIR="/home/user/samba-of-pred-kos-2/bin"
        LIBDIR="/usr/local/samba/lib"
        LIBEXECDIR="/home/user/samba-of-pred-kos-2/bin"
        SAMBA_LIBEXECDIR="/home/user/samba-of-pred-kos-2/bin"
        DATADIR="/usr/local/samba/share"
        SAMBA_DATADIR="/usr/local/samba/share/samba"
        LOCALEDIR="/usr/local/samba/share/locale"
        PYTHONDIR="/home/user/samba-of-pred-kos-2/bin/python"
        PYTHONARCHDIR="/home/user/samba-of-pred-kos-2/bin/python"
        PERL_LIB_INSTALL_DIR="/usr/local/samba/share/perl5"
        PERL_ARCH_INSTALL_DIR="/usr/local/samba/lib/perl5"
        INCLUDEDIR="/usr/local/samba/include"
        SCRIPTSBINDIR="/home/user/samba-of-pred-kos-2/source4/scripting/bin"
        SETUPDIR="/home/user/samba-of-pred-kos-2/source4/setup"
        PKGCONFIGDIR="/usr/local/samba/lib/pkgconfig"
        CODEPAGEDIR="/home/user/samba-of-pred-kos-2/codepages"
        PRIVATELIBDIR="/usr/local/samba/lib/private"
        MODULESDIR="/home/user/samba-of-pred-kos-2/bin/modules"
        PAMMODULESDIR="/usr/local/samba/lib/security"
        CONFIGDIR="/usr/local/samba/etc"
        PRIVATE_DIR="/usr/local/samba/private"
        BINDDNS_DIR="/usr/local/samba/bind-dns"
        LOCKDIR="/usr/local/samba/var/lock"
        PIDDIR="/usr/local/samba/var/run"
        STATEDIR="/usr/local/samba/var/locks"
        CACHEDIR="/usr/local/samba/var/cache"
        LOGFILEBASE="/usr/local/samba/var"
        SOCKET_DIR="/usr/local/samba/var/run"
        PRIVILEGED_SOCKET_DIR="/usr/local/samba/var/lib"
        WINBINDD_SOCKET_DIR="/usr/local/samba/var/run/winbindd"
        NMBDSOCKETDIR="/usr/local/samba/var/run/nmbd"
        NTP_SIGND_SOCKET_DIR="/usr/local/samba/var/lib/ntp_signd"
        NCALRPCDIR="/usr/local/samba/var/run/ncalrpc"
        CONFIGFILE="/usr/local/samba/etc/smb.conf"
        LMHOSTSFILE="/usr/local/samba/etc/lmhosts"
        SMB_PASSWD_FILE="/usr/local/samba/private/smbpasswd"
        STATIC_DYNCONFIG_MODULES=NULL
        "STATIC_DYNCONFIG_MODULES_PROTO=extern void __DYNCONFIG_dummy_module_proto(void)"
        STATIC_strv_MODULES=NULL
        "STATIC_strv_MODULES_PROTO=extern void __strv_dummy_module_proto(void)"
        STATIC_util_str_hex_MODULES=NULL
        "STATIC_util_str_hex_MODULES_PROTO=extern void __util_str_hex_dummy_module_proto(void)"
        STATIC_ICONV_WRAPPER_MODULES=NULL
        "STATIC_ICONV_WRAPPER_MODULES_PROTO=extern void __ICONV_WRAPPER_dummy_module_proto(void)"
        STATIC_LIBCRYPTO_MODULES=NULL
        "STATIC_LIBCRYPTO_MODULES_PROTO=extern void __LIBCRYPTO_dummy_module_proto(void)"
        STATIC_samba_util_core_MODULES=NULL
        "STATIC_samba_util_core_MODULES_PROTO=extern void __samba_util_core_dummy_module_proto(void)"
        STATIC_smb_strtox_MODULES=NULL
        "STATIC_smb_strtox_MODULES_PROTO=extern void __smb_strtox_dummy_module_proto(void)"
        STATIC_tini_MODULES=NULL
        "STATIC_tini_MODULES_PROTO=extern void __tini_dummy_module_proto(void)"
        STATIC_samba_util_MODULES=NULL
        "STATIC_samba_util_MODULES_PROTO=extern void __samba_util_dummy_module_proto(void)"
        STATIC_LIBCRYPTO_AES_MODULES=NULL
        "STATIC_LIBCRYPTO_AES_MODULES_PROTO=extern void __LIBCRYPTO_AES_dummy_module_proto(void)"
)

target_compile_options(
        ${TARGET_NAME}
        PRIVATE
        -MMD
        -fPIC
        -fstack-protector-strong
        -fstack-clash-protection
)
