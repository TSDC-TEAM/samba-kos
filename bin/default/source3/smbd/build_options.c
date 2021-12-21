/*
   Unix SMB/CIFS implementation.
   Build Options for Samba Suite
   Copyright (C) Vance Lankhaar <vlankhaar@linux.ca> 2003
   Copyright (C) Andrew Bartlett <abartlet@samba.org> 2001

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, see <http://www.gnu.org/licenses/>.
*/

#include "includes.h"
#include "dynconfig/dynconfig.h"
#include "lib/cluster_support.h"

static int output(bool screen, const char *format, ...) PRINTF_ATTRIBUTE(2,3);
void build_options(bool screen);


/****************************************************************************
helper function for build_options
****************************************************************************/
static int output(bool screen, const char *format, ...)
{
       char *ptr = NULL;
       int ret = 0;
       va_list ap;
       
       va_start(ap, format);
       ret = vasprintf(&ptr,format,ap);
       va_end(ap);

       if (screen) {
              d_printf("%s", ptr ? ptr : "");
       } else {
              DEBUG(4,("%s", ptr ? ptr : ""));
       }
       
       SAFE_FREE(ptr);
       return ret;
}

/****************************************************************************
options set at build time for the samba suite
****************************************************************************/
void build_options(bool screen)
{
       if ((DEBUGLEVEL < 4) && (!screen)) {
              return;
       }


       /* Output various paths to files and directories */
       output(screen,"\nPaths:\n");
       output(screen,"   SBINDIR: %s\n", get_dyn_SBINDIR());
       output(screen,"   BINDIR: %s\n", get_dyn_BINDIR());
       output(screen,"   CONFIGFILE: %s\n", get_dyn_CONFIGFILE());
       output(screen,"   LOGFILEBASE: %s\n", get_dyn_LOGFILEBASE());
       output(screen,"   LMHOSTSFILE: %s\n",get_dyn_LMHOSTSFILE());
       output(screen,"   LIBDIR: %s\n",get_dyn_LIBDIR());
       output(screen,"   DATADIR: %s\n",get_dyn_DATADIR());
       output(screen,"   SAMBA_DATADIR: %s\n",get_dyn_SAMBA_DATADIR());
       output(screen,"   MODULESDIR: %s\n",get_dyn_MODULESDIR());
       output(screen,"   SHLIBEXT: %s\n",get_dyn_SHLIBEXT());
       output(screen,"   LOCKDIR: %s\n",get_dyn_LOCKDIR());
       output(screen,"   STATEDIR: %s\n",get_dyn_STATEDIR());
       output(screen,"   CACHEDIR: %s\n",get_dyn_CACHEDIR());
       output(screen,"   PIDDIR: %s\n", get_dyn_PIDDIR());
       output(screen,"   SMB_PASSWD_FILE: %s\n",get_dyn_SMB_PASSWD_FILE());
       output(screen,"   PRIVATE_DIR: %s\n",get_dyn_PRIVATE_DIR());
       output(screen,"   BINDDNS_DIR: %s\n",get_dyn_BINDDNS_DIR());


	/* Show System Headers */
       output(screen, "\nSystem Headers:\n");

#ifdef HAVE_SYS_ACL_H
       output(screen, "   HAVE_SYS_ACL_H\n");
#endif
#ifdef HAVE_SYS_AUXV_H
       output(screen, "   HAVE_SYS_AUXV_H\n");
#endif
#ifdef HAVE_SYS_CDEFS_H
       output(screen, "   HAVE_SYS_CDEFS_H\n");
#endif
#ifdef HAVE_SYS_DIR_H
       output(screen, "   HAVE_SYS_DIR_H\n");
#endif
#ifdef HAVE_SYS_EPOLL_H
       output(screen, "   HAVE_SYS_EPOLL_H\n");
#endif
#ifdef HAVE_SYS_EVENTFD_H
       output(screen, "   HAVE_SYS_EVENTFD_H\n");
#endif
#ifdef HAVE_SYS_FCNTL_H
       output(screen, "   HAVE_SYS_FCNTL_H\n");
#endif
#ifdef HAVE_SYS_FILE_H
       output(screen, "   HAVE_SYS_FILE_H\n");
#endif
#ifdef HAVE_SYS_INOTIFY_H
       output(screen, "   HAVE_SYS_INOTIFY_H\n");
#endif
#ifdef HAVE_SYS_IOCTL_H
       output(screen, "   HAVE_SYS_IOCTL_H\n");
#endif
#ifdef HAVE_SYS_IPC_H
       output(screen, "   HAVE_SYS_IPC_H\n");
#endif
#ifdef HAVE_SYS_KERNEL_PROC_CORE_PATTERN
       output(screen, "   HAVE_SYS_KERNEL_PROC_CORE_PATTERN\n");
#endif
#ifdef HAVE_SYS_MMAN_H
       output(screen, "   HAVE_SYS_MMAN_H\n");
#endif
#ifdef HAVE_SYS_MOUNT_H
       output(screen, "   HAVE_SYS_MOUNT_H\n");
#endif
#ifdef HAVE_SYS_PARAM_H
       output(screen, "   HAVE_SYS_PARAM_H\n");
#endif
#ifdef HAVE_SYS_PRCTL_H
       output(screen, "   HAVE_SYS_PRCTL_H\n");
#endif
#ifdef HAVE_SYS_QUOTAS
       output(screen, "   HAVE_SYS_QUOTAS\n");
#endif
#ifdef HAVE_SYS_QUOTA_H
       output(screen, "   HAVE_SYS_QUOTA_H\n");
#endif
#ifdef HAVE_SYS_RESOURCE_H
       output(screen, "   HAVE_SYS_RESOURCE_H\n");
#endif
#ifdef HAVE_SYS_SELECT_H
       output(screen, "   HAVE_SYS_SELECT_H\n");
#endif
#ifdef HAVE_SYS_SENDFILE_H
       output(screen, "   HAVE_SYS_SENDFILE_H\n");
#endif
#ifdef HAVE_SYS_SHM_H
       output(screen, "   HAVE_SYS_SHM_H\n");
#endif
#ifdef HAVE_SYS_SOCKET_H
       output(screen, "   HAVE_SYS_SOCKET_H\n");
#endif
#ifdef HAVE_SYS_STATFS_H
       output(screen, "   HAVE_SYS_STATFS_H\n");
#endif
#ifdef HAVE_SYS_STATVFS_H
       output(screen, "   HAVE_SYS_STATVFS_H\n");
#endif
#ifdef HAVE_SYS_STAT_H
       output(screen, "   HAVE_SYS_STAT_H\n");
#endif
#ifdef HAVE_SYS_SYSCALL_H
       output(screen, "   HAVE_SYS_SYSCALL_H\n");
#endif
#ifdef HAVE_SYS_SYSCTL_H
       output(screen, "   HAVE_SYS_SYSCTL_H\n");
#endif
#ifdef HAVE_SYS_SYSLOG_H
       output(screen, "   HAVE_SYS_SYSLOG_H\n");
#endif
#ifdef HAVE_SYS_SYSMACROS_H
       output(screen, "   HAVE_SYS_SYSMACROS_H\n");
#endif
#ifdef HAVE_SYS_TERMIOS_H
       output(screen, "   HAVE_SYS_TERMIOS_H\n");
#endif
#ifdef HAVE_SYS_TIMEB_H
       output(screen, "   HAVE_SYS_TIMEB_H\n");
#endif
#ifdef HAVE_SYS_TIMES_H
       output(screen, "   HAVE_SYS_TIMES_H\n");
#endif
#ifdef HAVE_SYS_TIME_H
       output(screen, "   HAVE_SYS_TIME_H\n");
#endif
#ifdef HAVE_SYS_TYPES_H
       output(screen, "   HAVE_SYS_TYPES_H\n");
#endif
#ifdef HAVE_SYS_UCONTEXT_H
       output(screen, "   HAVE_SYS_UCONTEXT_H\n");
#endif
#ifdef HAVE_SYS_UIO_H
       output(screen, "   HAVE_SYS_UIO_H\n");
#endif
#ifdef HAVE_SYS_UNISTD_H
       output(screen, "   HAVE_SYS_UNISTD_H\n");
#endif
#ifdef HAVE_SYS_UN_H
       output(screen, "   HAVE_SYS_UN_H\n");
#endif
#ifdef HAVE_SYS_UTSNAME_H
       output(screen, "   HAVE_SYS_UTSNAME_H\n");
#endif
#ifdef HAVE_SYS_VFS_H
       output(screen, "   HAVE_SYS_VFS_H\n");
#endif
#ifdef HAVE_SYS_WAIT_H
       output(screen, "   HAVE_SYS_WAIT_H\n");
#endif
#ifdef HAVE_SYS_XATTR_H
       output(screen, "   HAVE_SYS_XATTR_H\n");
#endif


	/* Show Headers */
       output(screen, "\nHeaders:\n");

#ifdef HAVE_ACL_LIBACL_H
       output(screen, "   HAVE_ACL_LIBACL_H\n");
#endif
#ifdef HAVE_ALLOCA_H
       output(screen, "   HAVE_ALLOCA_H\n");
#endif
#ifdef HAVE_ARPA_INET_H
       output(screen, "   HAVE_ARPA_INET_H\n");
#endif
#ifdef HAVE_ARPA_NAMESER_H
       output(screen, "   HAVE_ARPA_NAMESER_H\n");
#endif
#ifdef HAVE_ASM_TYPES_H
       output(screen, "   HAVE_ASM_TYPES_H\n");
#endif
#ifdef HAVE_ASM_UNISTD_H
       output(screen, "   HAVE_ASM_UNISTD_H\n");
#endif
#ifdef HAVE_ASSERT_H
       output(screen, "   HAVE_ASSERT_H\n");
#endif
#ifdef HAVE_ATTR_ATTRIBUTES_H
       output(screen, "   HAVE_ATTR_ATTRIBUTES_H\n");
#endif
#ifdef HAVE_ATTR_XATTR_H
       output(screen, "   HAVE_ATTR_XATTR_H\n");
#endif
#ifdef HAVE_BSD_LIBUTIL_H
       output(screen, "   HAVE_BSD_LIBUTIL_H\n");
#endif
#ifdef HAVE_BSD_STRING_H
       output(screen, "   HAVE_BSD_STRING_H\n");
#endif
#ifdef HAVE_BSD_UNISTD_H
       output(screen, "   HAVE_BSD_UNISTD_H\n");
#endif
#ifdef HAVE_COM_ERR_H
       output(screen, "   HAVE_COM_ERR_H\n");
#endif
#ifdef HAVE_CONFIG_H
       output(screen, "   HAVE_CONFIG_H\n");
#endif
#ifdef HAVE_CRYPT_H
       output(screen, "   HAVE_CRYPT_H\n");
#endif
#ifdef HAVE_CTYPE_H
       output(screen, "   HAVE_CTYPE_H\n");
#endif
#ifdef HAVE_CURSES_H
       output(screen, "   HAVE_CURSES_H\n");
#endif
#ifdef HAVE_DIRENT_H
       output(screen, "   HAVE_DIRENT_H\n");
#endif
#ifdef HAVE_DLFCN_H
       output(screen, "   HAVE_DLFCN_H\n");
#endif
#ifdef HAVE_ENDIAN_H
       output(screen, "   HAVE_ENDIAN_H\n");
#endif
#ifdef HAVE_ERRNO_H
       output(screen, "   HAVE_ERRNO_H\n");
#endif
#ifdef HAVE_ERR_H
       output(screen, "   HAVE_ERR_H\n");
#endif
#ifdef HAVE_EXECINFO_H
       output(screen, "   HAVE_EXECINFO_H\n");
#endif
#ifdef HAVE_FCNTL_H
       output(screen, "   HAVE_FCNTL_H\n");
#endif
#ifdef HAVE_FLOAT_H
       output(screen, "   HAVE_FLOAT_H\n");
#endif
#ifdef HAVE_FNMATCH_H
       output(screen, "   HAVE_FNMATCH_H\n");
#endif
#ifdef HAVE_FORM_H
       output(screen, "   HAVE_FORM_H\n");
#endif
#ifdef HAVE_FTW_H
       output(screen, "   HAVE_FTW_H\n");
#endif
#ifdef HAVE_FUSE_FUSE_LOWLEVEL_H
       output(screen, "   HAVE_FUSE_FUSE_LOWLEVEL_H\n");
#endif
#ifdef HAVE_GETOPT_H
       output(screen, "   HAVE_GETOPT_H\n");
#endif
#ifdef HAVE_GLOB_H
       output(screen, "   HAVE_GLOB_H\n");
#endif
#ifdef HAVE_GNUTLS_GNUTLS_H
       output(screen, "   HAVE_GNUTLS_GNUTLS_H\n");
#endif
#ifdef HAVE_GPFS_H
       output(screen, "   HAVE_GPFS_H\n");
#endif
#ifdef HAVE_GRP_H
       output(screen, "   HAVE_GRP_H\n");
#endif
#ifdef HAVE_GSSAPI_GSSAPI_H
       output(screen, "   HAVE_GSSAPI_GSSAPI_H\n");
#endif
#ifdef HAVE_GSSAPI_GSSAPI_KRB5_H
       output(screen, "   HAVE_GSSAPI_GSSAPI_KRB5_H\n");
#endif
#ifdef HAVE_GSSAPI_GSSAPI_SPNEGO_H
       output(screen, "   HAVE_GSSAPI_GSSAPI_SPNEGO_H\n");
#endif
#ifdef HAVE_ICONV_H
       output(screen, "   HAVE_ICONV_H\n");
#endif
#ifdef HAVE_IFADDRS_H
       output(screen, "   HAVE_IFADDRS_H\n");
#endif
#ifdef HAVE_INTTYPES_H
       output(screen, "   HAVE_INTTYPES_H\n");
#endif
#ifdef HAVE_KRB5_H
       output(screen, "   HAVE_KRB5_H\n");
#endif
#ifdef HAVE_KRB5_LOCATE_PLUGIN_H
       output(screen, "   HAVE_KRB5_LOCATE_PLUGIN_H\n");
#endif
#ifdef HAVE_LANGINFO_H
       output(screen, "   HAVE_LANGINFO_H\n");
#endif
#ifdef HAVE_LASTLOG_H
       output(screen, "   HAVE_LASTLOG_H\n");
#endif
#ifdef HAVE_LIBGEN_H
       output(screen, "   HAVE_LIBGEN_H\n");
#endif
#ifdef HAVE_LIBINTL_H
       output(screen, "   HAVE_LIBINTL_H\n");
#endif
#ifdef HAVE_LIMITS_H
       output(screen, "   HAVE_LIMITS_H\n");
#endif
#ifdef HAVE_LINUX_ETHTOOL_H
       output(screen, "   HAVE_LINUX_ETHTOOL_H\n");
#endif
#ifdef HAVE_LINUX_FALLOC_H
       output(screen, "   HAVE_LINUX_FALLOC_H\n");
#endif
#ifdef HAVE_LINUX_FCNTL_H
       output(screen, "   HAVE_LINUX_FCNTL_H\n");
#endif
#ifdef HAVE_LINUX_FS_H
       output(screen, "   HAVE_LINUX_FS_H\n");
#endif
#ifdef HAVE_LINUX_IOCTL_H
       output(screen, "   HAVE_LINUX_IOCTL_H\n");
#endif
#ifdef HAVE_LINUX_NETLINK_H
       output(screen, "   HAVE_LINUX_NETLINK_H\n");
#endif
#ifdef HAVE_LINUX_RTNETLINK_H
       output(screen, "   HAVE_LINUX_RTNETLINK_H\n");
#endif
#ifdef HAVE_LINUX_SOCKIOS_H
       output(screen, "   HAVE_LINUX_SOCKIOS_H\n");
#endif
#ifdef HAVE_LINUX_TYPES_H
       output(screen, "   HAVE_LINUX_TYPES_H\n");
#endif
#ifdef HAVE_LOCALE_H
       output(screen, "   HAVE_LOCALE_H\n");
#endif
#ifdef HAVE_MALLOC_H
       output(screen, "   HAVE_MALLOC_H\n");
#endif
#ifdef HAVE_MEMORY_H
       output(screen, "   HAVE_MEMORY_H\n");
#endif
#ifdef HAVE_MENU_H
       output(screen, "   HAVE_MENU_H\n");
#endif
#ifdef HAVE_MNTENT_H
       output(screen, "   HAVE_MNTENT_H\n");
#endif
#ifdef HAVE_NCURSES_H
       output(screen, "   HAVE_NCURSES_H\n");
#endif
#ifdef HAVE_NETDB_H
       output(screen, "   HAVE_NETDB_H\n");
#endif
#ifdef HAVE_NETINET_IN_H
       output(screen, "   HAVE_NETINET_IN_H\n");
#endif
#ifdef HAVE_NETINET_IN_SYSTM_H
       output(screen, "   HAVE_NETINET_IN_SYSTM_H\n");
#endif
#ifdef HAVE_NETINET_IP_H
       output(screen, "   HAVE_NETINET_IP_H\n");
#endif
#ifdef HAVE_NETINET_TCP_H
       output(screen, "   HAVE_NETINET_TCP_H\n");
#endif
#ifdef HAVE_NET_IF_H
       output(screen, "   HAVE_NET_IF_H\n");
#endif
#ifdef HAVE_NSS_H
       output(screen, "   HAVE_NSS_H\n");
#endif
#ifdef HAVE_PANEL_H
       output(screen, "   HAVE_PANEL_H\n");
#endif
#ifdef HAVE_POLL_H
       output(screen, "   HAVE_POLL_H\n");
#endif
#ifdef HAVE_POPT_H
       output(screen, "   HAVE_POPT_H\n");
#endif
#ifdef HAVE_PTHREAD_H
       output(screen, "   HAVE_PTHREAD_H\n");
#endif
#ifdef HAVE_PTY_H
       output(screen, "   HAVE_PTY_H\n");
#endif
#ifdef HAVE_PWD_H
       output(screen, "   HAVE_PWD_H\n");
#endif
#ifdef HAVE_RESOLV_H
       output(screen, "   HAVE_RESOLV_H\n");
#endif
#ifdef HAVE_RPCSVC_NIS_H
       output(screen, "   HAVE_RPCSVC_NIS_H\n");
#endif
#ifdef HAVE_RPCSVC_RQUOTA_H
       output(screen, "   HAVE_RPCSVC_RQUOTA_H\n");
#endif
#ifdef HAVE_RPC_RPC_H
       output(screen, "   HAVE_RPC_RPC_H\n");
#endif
#ifdef HAVE_RPC_TYPES_H
       output(screen, "   HAVE_RPC_TYPES_H\n");
#endif
#ifdef HAVE_RPC_XDR_H
       output(screen, "   HAVE_RPC_XDR_H\n");
#endif
#ifdef HAVE_SCHED_H
       output(screen, "   HAVE_SCHED_H\n");
#endif
#ifdef HAVE_SECURITY_PAM_APPL_H
       output(screen, "   HAVE_SECURITY_PAM_APPL_H\n");
#endif
#ifdef HAVE_SECURITY_PAM_MODULES_H
       output(screen, "   HAVE_SECURITY_PAM_MODULES_H\n");
#endif
#ifdef HAVE_SETJMP_H
       output(screen, "   HAVE_SETJMP_H\n");
#endif
#ifdef HAVE_SHADOW_H
       output(screen, "   HAVE_SHADOW_H\n");
#endif
#ifdef HAVE_SIGNAL_H
       output(screen, "   HAVE_SIGNAL_H\n");
#endif
#ifdef HAVE_STDARG_H
       output(screen, "   HAVE_STDARG_H\n");
#endif
#ifdef HAVE_STDATOMIC_H
       output(screen, "   HAVE_STDATOMIC_H\n");
#endif
#ifdef HAVE_STDBOOL_H
       output(screen, "   HAVE_STDBOOL_H\n");
#endif
#ifdef HAVE_STDDEF_H
       output(screen, "   HAVE_STDDEF_H\n");
#endif
#ifdef HAVE_STDINT_H
       output(screen, "   HAVE_STDINT_H\n");
#endif
#ifdef HAVE_STDIO_H
       output(screen, "   HAVE_STDIO_H\n");
#endif
#ifdef HAVE_STDLIB_H
       output(screen, "   HAVE_STDLIB_H\n");
#endif
#ifdef HAVE_STRINGS_H
       output(screen, "   HAVE_STRINGS_H\n");
#endif
#ifdef HAVE_STRING_H
       output(screen, "   HAVE_STRING_H\n");
#endif
#ifdef HAVE_SYSCALL_H
       output(screen, "   HAVE_SYSCALL_H\n");
#endif
#ifdef HAVE_SYSLOG_H
       output(screen, "   HAVE_SYSLOG_H\n");
#endif
#ifdef HAVE_TERMCAP_H
       output(screen, "   HAVE_TERMCAP_H\n");
#endif
#ifdef HAVE_TERMIOS_H
       output(screen, "   HAVE_TERMIOS_H\n");
#endif
#ifdef HAVE_TERMIO_H
       output(screen, "   HAVE_TERMIO_H\n");
#endif
#ifdef HAVE_TERM_H
       output(screen, "   HAVE_TERM_H\n");
#endif
#ifdef HAVE_TIME_H
       output(screen, "   HAVE_TIME_H\n");
#endif
#ifdef HAVE_UNISTD_H
       output(screen, "   HAVE_UNISTD_H\n");
#endif
#ifdef HAVE_UTIME_H
       output(screen, "   HAVE_UTIME_H\n");
#endif
#ifdef HAVE_VALGRIND_HELGRIND_H
       output(screen, "   HAVE_VALGRIND_HELGRIND_H\n");
#endif
#ifdef HAVE_VALGRIND_MEMCHECK_H
       output(screen, "   HAVE_VALGRIND_MEMCHECK_H\n");
#endif
#ifdef HAVE_VALGRIND_VALGRIND_H
       output(screen, "   HAVE_VALGRIND_VALGRIND_H\n");
#endif
#ifdef HAVE_ZLIB_H
       output(screen, "   HAVE_ZLIB_H\n");
#endif


	/* Show UTMP Options */
       output(screen, "\nUTMP Options:\n");

#ifdef HAVE_GETUTMPX
       output(screen, "   HAVE_GETUTMPX\n");
#endif
#ifdef HAVE_UTMPX_H
       output(screen, "   HAVE_UTMPX_H\n");
#endif
#ifdef HAVE_UTMP_H
       output(screen, "   HAVE_UTMP_H\n");
#endif
#ifdef HAVE_UT_UT_EXIT
       output(screen, "   HAVE_UT_UT_EXIT\n");
#endif
#ifdef HAVE_UT_UT_HOST
       output(screen, "   HAVE_UT_UT_HOST\n");
#endif
#ifdef HAVE_UT_UT_ID
       output(screen, "   HAVE_UT_UT_ID\n");
#endif
#ifdef HAVE_UT_UT_NAME
       output(screen, "   HAVE_UT_UT_NAME\n");
#endif
#ifdef HAVE_UT_UT_PID
       output(screen, "   HAVE_UT_UT_PID\n");
#endif
#ifdef HAVE_UT_UT_TIME
       output(screen, "   HAVE_UT_UT_TIME\n");
#endif
#ifdef HAVE_UT_UT_TV
       output(screen, "   HAVE_UT_UT_TV\n");
#endif
#ifdef HAVE_UT_UT_TYPE
       output(screen, "   HAVE_UT_UT_TYPE\n");
#endif
#ifdef HAVE_UT_UT_USER
       output(screen, "   HAVE_UT_UT_USER\n");
#endif
#ifdef PUTUTLINE_RETURNS_UTMP
       output(screen, "   PUTUTLINE_RETURNS_UTMP\n");
#endif
#ifdef SIZEOF_UTMP_UT_LINE
       output(screen, "   SIZEOF_UTMP_UT_LINE\n");
#endif
#ifdef WITH_UTMP
       output(screen, "   WITH_UTMP\n");
#endif


	/* Show HAVE_* Defines */
       output(screen, "\nHAVE_* Defines:\n");

#ifdef HAVE_64_BIT_SIZE_T_FOR_LMDB
       output(screen, "   HAVE_64_BIT_SIZE_T_FOR_LMDB\n");
#endif
#ifdef HAVE_ADDR_TYPE_IN_KRB5_ADDRESS
       output(screen, "   HAVE_ADDR_TYPE_IN_KRB5_ADDRESS\n");
#endif
#ifdef HAVE_AP_OPTS_USE_SUBKEY
       output(screen, "   HAVE_AP_OPTS_USE_SUBKEY\n");
#endif
#ifdef HAVE_ASPRINTF
       output(screen, "   HAVE_ASPRINTF\n");
#endif
#ifdef HAVE_ATEXIT
       output(screen, "   HAVE_ATEXIT\n");
#endif
#ifdef HAVE_ATOMIC_ADD_32
       output(screen, "   HAVE_ATOMIC_ADD_32\n");
#endif
#ifdef HAVE_ATOMIC_THREAD_FENCE
       output(screen, "   HAVE_ATOMIC_THREAD_FENCE\n");
#endif
#ifdef HAVE_ATOMIC_THREAD_FENCE_SUPPORT
       output(screen, "   HAVE_ATOMIC_THREAD_FENCE_SUPPORT\n");
#endif
#ifdef HAVE_AVAHI_CLIENT_NEW
       output(screen, "   HAVE_AVAHI_CLIENT_NEW\n");
#endif
#ifdef HAVE_AVAHI_STRERROR
       output(screen, "   HAVE_AVAHI_STRERROR\n");
#endif
#ifdef HAVE_BACKTRACE
       output(screen, "   HAVE_BACKTRACE\n");
#endif
#ifdef HAVE_BACKTRACE_SYMBOLS
       output(screen, "   HAVE_BACKTRACE_SYMBOLS\n");
#endif
#ifdef HAVE_BASENAME
       output(screen, "   HAVE_BASENAME\n");
#endif
#ifdef HAVE_BIG_ENDIAN
       output(screen, "   HAVE_BIG_ENDIAN\n");
#endif
#ifdef HAVE_BINDTEXTDOMAIN
       output(screen, "   HAVE_BINDTEXTDOMAIN\n");
#endif
#ifdef HAVE_BIND_TEXTDOMAIN_CODESET
       output(screen, "   HAVE_BIND_TEXTDOMAIN_CODESET\n");
#endif
#ifdef HAVE_BLKCNT_T
       output(screen, "   HAVE_BLKCNT_T\n");
#endif
#ifdef HAVE_BLKSIZE_T
       output(screen, "   HAVE_BLKSIZE_T\n");
#endif
#ifdef HAVE_BOOL
       output(screen, "   HAVE_BOOL\n");
#endif
#ifdef HAVE_BSD_STRTOLL
       output(screen, "   HAVE_BSD_STRTOLL\n");
#endif
#ifdef HAVE_BSWAP16
       output(screen, "   HAVE_BSWAP16\n");
#endif
#ifdef HAVE_BSWAP32
       output(screen, "   HAVE_BSWAP32\n");
#endif
#ifdef HAVE_BZERO
       output(screen, "   HAVE_BZERO\n");
#endif
#ifdef HAVE_C99_VSNPRINTF
       output(screen, "   HAVE_C99_VSNPRINTF\n");
#endif
#ifdef HAVE_CAP_GET_PROC
       output(screen, "   HAVE_CAP_GET_PROC\n");
#endif
#ifdef HAVE_CGETENT
       output(screen, "   HAVE_CGETENT\n");
#endif
#ifdef HAVE_CHARSET_CP850
       output(screen, "   HAVE_CHARSET_CP850\n");
#endif
#ifdef HAVE_CHARSET_UTF_8
       output(screen, "   HAVE_CHARSET_UTF_8\n");
#endif
#ifdef HAVE_CHECKSUM_IN_KRB5_CHECKSUM
       output(screen, "   HAVE_CHECKSUM_IN_KRB5_CHECKSUM\n");
#endif
#ifdef HAVE_CHFLAGS
       output(screen, "   HAVE_CHFLAGS\n");
#endif
#ifdef HAVE_CHMOD
       output(screen, "   HAVE_CHMOD\n");
#endif
#ifdef HAVE_CHOWN
       output(screen, "   HAVE_CHOWN\n");
#endif
#ifdef HAVE_CHROOT
       output(screen, "   HAVE_CHROOT\n");
#endif
#ifdef HAVE_CHSIZE
       output(screen, "   HAVE_CHSIZE\n");
#endif
#ifdef HAVE_CLEARENV
       output(screen, "   HAVE_CLEARENV\n");
#endif
#ifdef HAVE_CLOCK_GETTIME
       output(screen, "   HAVE_CLOCK_GETTIME\n");
#endif
#ifdef HAVE_CLOCK_MONOTONIC
       output(screen, "   HAVE_CLOCK_MONOTONIC\n");
#endif
#ifdef HAVE_CLOCK_PROCESS_CPUTIME_ID
       output(screen, "   HAVE_CLOCK_PROCESS_CPUTIME_ID\n");
#endif
#ifdef HAVE_CLOCK_REALTIME
       output(screen, "   HAVE_CLOCK_REALTIME\n");
#endif
#ifdef HAVE_CLOSEFROM
       output(screen, "   HAVE_CLOSEFROM\n");
#endif
#ifdef HAVE_COMPARISON_FN_T
       output(screen, "   HAVE_COMPARISON_FN_T\n");
#endif
#ifdef HAVE_COMPILER_WILL_OPTIMIZE_OUT_FNS
       output(screen, "   HAVE_COMPILER_WILL_OPTIMIZE_OUT_FNS\n");
#endif
#ifdef HAVE_CONNECT
       output(screen, "   HAVE_CONNECT\n");
#endif
#ifdef HAVE_CONSTRUCTOR_ATTRIBUTE
       output(screen, "   HAVE_CONSTRUCTOR_ATTRIBUTE\n");
#endif
#ifdef HAVE_COPY_FILE_RANGE
       output(screen, "   HAVE_COPY_FILE_RANGE\n");
#endif
#ifdef HAVE_CPPFUNCTION
       output(screen, "   HAVE_CPPFUNCTION\n");
#endif
#ifdef HAVE_CRYPT
       output(screen, "   HAVE_CRYPT\n");
#endif
#ifdef HAVE_CRYPT16
       output(screen, "   HAVE_CRYPT16\n");
#endif
#ifdef HAVE_CRYPT_R
       output(screen, "   HAVE_CRYPT_R\n");
#endif
#ifdef HAVE_CRYPT_RN
       output(screen, "   HAVE_CRYPT_RN\n");
#endif
#ifdef HAVE_CUPS
       output(screen, "   HAVE_CUPS\n");
#endif
#ifdef HAVE_DARWIN_INITGROUPS
       output(screen, "   HAVE_DARWIN_INITGROUPS\n");
#endif
#ifdef HAVE_DECL_ASPRINTF
       output(screen, "   HAVE_DECL_ASPRINTF\n");
#endif
#ifdef HAVE_DECL_BINDTEXTDOMAIN
       output(screen, "   HAVE_DECL_BINDTEXTDOMAIN\n");
#endif
#ifdef HAVE_DECL_BIND_TEXTDOMAIN_CODESET
       output(screen, "   HAVE_DECL_BIND_TEXTDOMAIN_CODESET\n");
#endif
#ifdef HAVE_DECL_DGETTEXT
       output(screen, "   HAVE_DECL_DGETTEXT\n");
#endif
#ifdef HAVE_DECL_DLOPEN
       output(screen, "   HAVE_DECL_DLOPEN\n");
#endif
#ifdef HAVE_DECL_EWOULDBLOCK
       output(screen, "   HAVE_DECL_EWOULDBLOCK\n");
#endif
#ifdef HAVE_DECL_FDATASYNC
       output(screen, "   HAVE_DECL_FDATASYNC\n");
#endif
#ifdef HAVE_DECL_FS_COMPR_FL
       output(screen, "   HAVE_DECL_FS_COMPR_FL\n");
#endif
#ifdef HAVE_DECL_FS_IOC_GETFLAGS
       output(screen, "   HAVE_DECL_FS_IOC_GETFLAGS\n");
#endif
#ifdef HAVE_DECL_GETGRENT_R
       output(screen, "   HAVE_DECL_GETGRENT_R\n");
#endif
#ifdef HAVE_DECL_GETPWENT_R
       output(screen, "   HAVE_DECL_GETPWENT_R\n");
#endif
#ifdef HAVE_DECL_GETTEXT
       output(screen, "   HAVE_DECL_GETTEXT\n");
#endif
#ifdef HAVE_DECL_GETTIMEOFDAY
       output(screen, "   HAVE_DECL_GETTIMEOFDAY\n");
#endif
#ifdef HAVE_DECL_H_ERRNO
       output(screen, "   HAVE_DECL_H_ERRNO\n");
#endif
#ifdef HAVE_DECL_KRB5_AUTH_CON_SET_REQ_CKSUMTYPE
       output(screen, "   HAVE_DECL_KRB5_AUTH_CON_SET_REQ_CKSUMTYPE\n");
#endif
#ifdef HAVE_DECL_KRB5_GET_CREDENTIALS_FOR_USER
       output(screen, "   HAVE_DECL_KRB5_GET_CREDENTIALS_FOR_USER\n");
#endif
#ifdef HAVE_DECL_MALLOC
       output(screen, "   HAVE_DECL_MALLOC\n");
#endif
#ifdef HAVE_DECL_MEMALIGN
       output(screen, "   HAVE_DECL_MEMALIGN\n");
#endif
#ifdef HAVE_DECL_PTHREAD_MUTEX_ROBUST
       output(screen, "   HAVE_DECL_PTHREAD_MUTEX_ROBUST\n");
#endif
#ifdef HAVE_DECL_READAHEAD
       output(screen, "   HAVE_DECL_READAHEAD\n");
#endif
#ifdef HAVE_DECL_RL_EVENT_HOOK
       output(screen, "   HAVE_DECL_RL_EVENT_HOOK\n");
#endif
#ifdef HAVE_DECL_SNPRINTF
       output(screen, "   HAVE_DECL_SNPRINTF\n");
#endif
#ifdef HAVE_DECL_STRPTIME
       output(screen, "   HAVE_DECL_STRPTIME\n");
#endif
#ifdef HAVE_DECL_TEXTDOMAIN
       output(screen, "   HAVE_DECL_TEXTDOMAIN\n");
#endif
#ifdef HAVE_DECL_VASPRINTF
       output(screen, "   HAVE_DECL_VASPRINTF\n");
#endif
#ifdef HAVE_DECL_VSNPRINTF
       output(screen, "   HAVE_DECL_VSNPRINTF\n");
#endif
#ifdef HAVE_DECL__RES
       output(screen, "   HAVE_DECL__RES\n");
#endif
#ifdef HAVE_DESTRUCTOR_ATTRIBUTE
       output(screen, "   HAVE_DESTRUCTOR_ATTRIBUTE\n");
#endif
#ifdef HAVE_DES_PCBC_ENCRYPT
       output(screen, "   HAVE_DES_PCBC_ENCRYPT\n");
#endif
#ifdef HAVE_DEVICE_MAJOR_FN
       output(screen, "   HAVE_DEVICE_MAJOR_FN\n");
#endif
#ifdef HAVE_DEVICE_MINOR_FN
       output(screen, "   HAVE_DEVICE_MINOR_FN\n");
#endif
#ifdef HAVE_DEVNM
       output(screen, "   HAVE_DEVNM\n");
#endif
#ifdef HAVE_DGETTEXT
       output(screen, "   HAVE_DGETTEXT\n");
#endif
#ifdef HAVE_DIRENT_D_OFF
       output(screen, "   HAVE_DIRENT_D_OFF\n");
#endif
#ifdef HAVE_DIRFD
       output(screen, "   HAVE_DIRFD\n");
#endif
#ifdef HAVE_DIRFD_DECL
       output(screen, "   HAVE_DIRFD_DECL\n");
#endif
#ifdef HAVE_DIRNAME
       output(screen, "   HAVE_DIRNAME\n");
#endif
#ifdef HAVE_DIR_DD_FD
       output(screen, "   HAVE_DIR_DD_FD\n");
#endif
#ifdef HAVE_DLCLOSE
       output(screen, "   HAVE_DLCLOSE\n");
#endif
#ifdef HAVE_DLERROR
       output(screen, "   HAVE_DLERROR\n");
#endif
#ifdef HAVE_DLOPEN
       output(screen, "   HAVE_DLOPEN\n");
#endif
#ifdef HAVE_DLSYM
       output(screen, "   HAVE_DLSYM\n");
#endif
#ifdef HAVE_DM_GET_EVENTLIST
       output(screen, "   HAVE_DM_GET_EVENTLIST\n");
#endif
#ifdef HAVE_DNSSERVICEREGISTER
       output(screen, "   HAVE_DNSSERVICEREGISTER\n");
#endif
#ifdef HAVE_DNS_SEARCH
       output(screen, "   HAVE_DNS_SEARCH\n");
#endif
#ifdef HAVE_DN_EXPAND
       output(screen, "   HAVE_DN_EXPAND\n");
#endif
#ifdef HAVE_DPRINTF
       output(screen, "   HAVE_DPRINTF\n");
#endif
#ifdef HAVE_DQB_FSOFTLIMIT
       output(screen, "   HAVE_DQB_FSOFTLIMIT\n");
#endif
#ifdef HAVE_DUP2
       output(screen, "   HAVE_DUP2\n");
#endif
#ifdef HAVE_ENCTYPE_AES128_CTS_HMAC_SHA1_96
       output(screen, "   HAVE_ENCTYPE_AES128_CTS_HMAC_SHA1_96\n");
#endif
#ifdef HAVE_ENCTYPE_AES256_CTS_HMAC_SHA1_96
       output(screen, "   HAVE_ENCTYPE_AES256_CTS_HMAC_SHA1_96\n");
#endif
#ifdef HAVE_ENCTYPE_ARCFOUR_HMAC
       output(screen, "   HAVE_ENCTYPE_ARCFOUR_HMAC\n");
#endif
#ifdef HAVE_ENCTYPE_ARCFOUR_HMAC_MD5
       output(screen, "   HAVE_ENCTYPE_ARCFOUR_HMAC_MD5\n");
#endif
#ifdef HAVE_ENCTYPE_ARCFOUR_HMAC_MD5_56
       output(screen, "   HAVE_ENCTYPE_ARCFOUR_HMAC_MD5_56\n");
#endif
#ifdef HAVE_ENDHOSTENT
       output(screen, "   HAVE_ENDHOSTENT\n");
#endif
#ifdef HAVE_ENDMNTENT
       output(screen, "   HAVE_ENDMNTENT\n");
#endif
#ifdef HAVE_ENVIRON_DECL
       output(screen, "   HAVE_ENVIRON_DECL\n");
#endif
#ifdef HAVE_EPOLL
       output(screen, "   HAVE_EPOLL\n");
#endif
#ifdef HAVE_EPOLL_CREATE
       output(screen, "   HAVE_EPOLL_CREATE\n");
#endif
#ifdef HAVE_ERR
       output(screen, "   HAVE_ERR\n");
#endif
#ifdef HAVE_ERRNO_DECL
       output(screen, "   HAVE_ERRNO_DECL\n");
#endif
#ifdef HAVE_ERRX
       output(screen, "   HAVE_ERRX\n");
#endif
#ifdef HAVE_ETHTOOL
       output(screen, "   HAVE_ETHTOOL\n");
#endif
#ifdef HAVE_ETYPE_IN_ENCRYPTEDDATA
       output(screen, "   HAVE_ETYPE_IN_ENCRYPTEDDATA\n");
#endif
#ifdef HAVE_EVENTFD
       output(screen, "   HAVE_EVENTFD\n");
#endif
#ifdef HAVE_EXECL
       output(screen, "   HAVE_EXECL\n");
#endif
#ifdef HAVE_E_DATA_POINTER_IN_KRB5_ERROR
       output(screen, "   HAVE_E_DATA_POINTER_IN_KRB5_ERROR\n");
#endif
#ifdef HAVE_FALLOCATE
       output(screen, "   HAVE_FALLOCATE\n");
#endif
#ifdef HAVE_FALLOC_FL_PUNCH_HOLE
       output(screen, "   HAVE_FALLOC_FL_PUNCH_HOLE\n");
#endif
#ifdef HAVE_FALLTHROUGH_ATTRIBUTE
       output(screen, "   HAVE_FALLTHROUGH_ATTRIBUTE\n");
#endif
#ifdef HAVE_FCHFLAGS
       output(screen, "   HAVE_FCHFLAGS\n");
#endif
#ifdef HAVE_FCHMOD
       output(screen, "   HAVE_FCHMOD\n");
#endif
#ifdef HAVE_FCHOWN
       output(screen, "   HAVE_FCHOWN\n");
#endif
#ifdef HAVE_FCNTL_LOCK
       output(screen, "   HAVE_FCNTL_LOCK\n");
#endif
#ifdef HAVE_FDATASYNC
       output(screen, "   HAVE_FDATASYNC\n");
#endif
#ifdef HAVE_FDOPENDIR
       output(screen, "   HAVE_FDOPENDIR\n");
#endif
#ifdef HAVE_FLAGS_IN_KRB5_CREDS
       output(screen, "   HAVE_FLAGS_IN_KRB5_CREDS\n");
#endif
#ifdef HAVE_FLOCK
       output(screen, "   HAVE_FLOCK\n");
#endif
#ifdef HAVE_FMEMOPEN
       output(screen, "   HAVE_FMEMOPEN\n");
#endif
#ifdef HAVE_FREEADDRINFO
       output(screen, "   HAVE_FREEADDRINFO\n");
#endif
#ifdef HAVE_FREEHOSTENT
       output(screen, "   HAVE_FREEHOSTENT\n");
#endif
#ifdef HAVE_FREEIFADDRS
       output(screen, "   HAVE_FREEIFADDRS\n");
#endif
#ifdef HAVE_FREE_CHECKSUM
       output(screen, "   HAVE_FREE_CHECKSUM\n");
#endif
#ifdef HAVE_FRSIZE
       output(screen, "   HAVE_FRSIZE\n");
#endif
#ifdef HAVE_FSEEKO
       output(screen, "   HAVE_FSEEKO\n");
#endif
#ifdef HAVE_FSID_INT
       output(screen, "   HAVE_FSID_INT\n");
#endif
#ifdef HAVE_FSYNC
       output(screen, "   HAVE_FSYNC\n");
#endif
#ifdef HAVE_FTRUNCATE
       output(screen, "   HAVE_FTRUNCATE\n");
#endif
#ifdef HAVE_FTRUNCATE_EXTEND
       output(screen, "   HAVE_FTRUNCATE_EXTEND\n");
#endif
#ifdef HAVE_FUNCTION_MACRO
       output(screen, "   HAVE_FUNCTION_MACRO\n");
#endif
#ifdef HAVE_FUTIMENS
       output(screen, "   HAVE_FUTIMENS\n");
#endif
#ifdef HAVE_F_OWNER_EX
       output(screen, "   HAVE_F_OWNER_EX\n");
#endif
#ifdef HAVE_F_SETLEASE_DECL
       output(screen, "   HAVE_F_SETLEASE_DECL\n");
#endif
#ifdef HAVE_GAI_STRERROR
       output(screen, "   HAVE_GAI_STRERROR\n");
#endif
#ifdef HAVE_GCC_VOLATILE_MEMORY_PROTECTION
       output(screen, "   HAVE_GCC_VOLATILE_MEMORY_PROTECTION\n");
#endif
#ifdef HAVE_GETADDRINFO
       output(screen, "   HAVE_GETADDRINFO\n");
#endif
#ifdef HAVE_GETAUTHUID
       output(screen, "   HAVE_GETAUTHUID\n");
#endif
#ifdef HAVE_GETAUXVAL
       output(screen, "   HAVE_GETAUXVAL\n");
#endif
#ifdef HAVE_GETCWD
       output(screen, "   HAVE_GETCWD\n");
#endif
#ifdef HAVE_GETGRENT
       output(screen, "   HAVE_GETGRENT\n");
#endif
#ifdef HAVE_GETGRENT_R
       output(screen, "   HAVE_GETGRENT_R\n");
#endif
#ifdef HAVE_GETGRENT_R_DECL
       output(screen, "   HAVE_GETGRENT_R_DECL\n");
#endif
#ifdef HAVE_GETGRGID_R
       output(screen, "   HAVE_GETGRGID_R\n");
#endif
#ifdef HAVE_GETGRNAM
       output(screen, "   HAVE_GETGRNAM\n");
#endif
#ifdef HAVE_GETGRNAM_R
       output(screen, "   HAVE_GETGRNAM_R\n");
#endif
#ifdef HAVE_GETGROUPLIST
       output(screen, "   HAVE_GETGROUPLIST\n");
#endif
#ifdef HAVE_GETGRSET
       output(screen, "   HAVE_GETGRSET\n");
#endif
#ifdef HAVE_GETHOSTBYADDR
       output(screen, "   HAVE_GETHOSTBYADDR\n");
#endif
#ifdef HAVE_GETHOSTBYNAME
       output(screen, "   HAVE_GETHOSTBYNAME\n");
#endif
#ifdef HAVE_GETHOSTBYNAME_R
       output(screen, "   HAVE_GETHOSTBYNAME_R\n");
#endif
#ifdef HAVE_GETHOSTENT
       output(screen, "   HAVE_GETHOSTENT\n");
#endif
#ifdef HAVE_GETHOSTENT_R
       output(screen, "   HAVE_GETHOSTENT_R\n");
#endif
#ifdef HAVE_GETHOSTNAME
       output(screen, "   HAVE_GETHOSTNAME\n");
#endif
#ifdef HAVE_GETIFADDRS
       output(screen, "   HAVE_GETIFADDRS\n");
#endif
#ifdef HAVE_GETIPNODEBYADDR
       output(screen, "   HAVE_GETIPNODEBYADDR\n");
#endif
#ifdef HAVE_GETIPNODEBYNAME
       output(screen, "   HAVE_GETIPNODEBYNAME\n");
#endif
#ifdef HAVE_GETMNTENT
       output(screen, "   HAVE_GETMNTENT\n");
#endif
#ifdef HAVE_GETNAMEINFO
       output(screen, "   HAVE_GETNAMEINFO\n");
#endif
#ifdef HAVE_GETPAGESIZE
       output(screen, "   HAVE_GETPAGESIZE\n");
#endif
#ifdef HAVE_GETPEEREID
       output(screen, "   HAVE_GETPEEREID\n");
#endif
#ifdef HAVE_GETPGRP
       output(screen, "   HAVE_GETPGRP\n");
#endif
#ifdef HAVE_GETPROGNAME
       output(screen, "   HAVE_GETPROGNAME\n");
#endif
#ifdef HAVE_GETPWANAM
       output(screen, "   HAVE_GETPWANAM\n");
#endif
#ifdef HAVE_GETPWENT_R
       output(screen, "   HAVE_GETPWENT_R\n");
#endif
#ifdef HAVE_GETPWENT_R_DECL
       output(screen, "   HAVE_GETPWENT_R_DECL\n");
#endif
#ifdef HAVE_GETPWNAM
       output(screen, "   HAVE_GETPWNAM\n");
#endif
#ifdef HAVE_GETPWNAM_R
       output(screen, "   HAVE_GETPWNAM_R\n");
#endif
#ifdef HAVE_GETPWUID_R
       output(screen, "   HAVE_GETPWUID_R\n");
#endif
#ifdef HAVE_GETQUOTA_RSLT_GETQUOTA_RSLT_U
       output(screen, "   HAVE_GETQUOTA_RSLT_GETQUOTA_RSLT_U\n");
#endif
#ifdef HAVE_GETRLIMIT
       output(screen, "   HAVE_GETRLIMIT\n");
#endif
#ifdef HAVE_GETSPNAM
       output(screen, "   HAVE_GETSPNAM\n");
#endif
#ifdef HAVE_GETTEXT
       output(screen, "   HAVE_GETTEXT\n");
#endif
#ifdef HAVE_GETTIMEOFDAY_TZ
       output(screen, "   HAVE_GETTIMEOFDAY_TZ\n");
#endif
#ifdef HAVE_GETTIMEOFDAY_TZ_VOID
       output(screen, "   HAVE_GETTIMEOFDAY_TZ_VOID\n");
#endif
#ifdef HAVE_GETUTXENT
       output(screen, "   HAVE_GETUTXENT\n");
#endif
#ifdef HAVE_GETXATTR
       output(screen, "   HAVE_GETXATTR\n");
#endif
#ifdef HAVE_GET_CURRENT_DIR_NAME
       output(screen, "   HAVE_GET_CURRENT_DIR_NAME\n");
#endif
#ifdef HAVE_GLOB
       output(screen, "   HAVE_GLOB\n");
#endif
#ifdef HAVE_GLUSTERFS
       output(screen, "   HAVE_GLUSTERFS\n");
#endif
#ifdef HAVE_GNUTLS
       output(screen, "   HAVE_GNUTLS\n");
#endif
#ifdef HAVE_GNUTLS_AEAD_CIPHER_ENCRYPTV2
       output(screen, "   HAVE_GNUTLS_AEAD_CIPHER_ENCRYPTV2\n");
#endif
#ifdef HAVE_GNUTLS_AES_CFB8
       output(screen, "   HAVE_GNUTLS_AES_CFB8\n");
#endif
#ifdef HAVE_GNUTLS_AES_CMAC
       output(screen, "   HAVE_GNUTLS_AES_CMAC\n");
#endif
#ifdef HAVE_GNUTLS_FIPS_MODE_SUPPORTED
       output(screen, "   HAVE_GNUTLS_FIPS_MODE_SUPPORTED\n");
#endif
#ifdef HAVE_GNUTLS_PKCS7_GET_EMBEDDED_DATA_OID
       output(screen, "   HAVE_GNUTLS_PKCS7_GET_EMBEDDED_DATA_OID\n");
#endif
#ifdef HAVE_GNUTLS_SET_DEFAULT_PRIORITY_APPEND
       output(screen, "   HAVE_GNUTLS_SET_DEFAULT_PRIORITY_APPEND\n");
#endif
#ifdef HAVE_GPFS
       output(screen, "   HAVE_GPFS\n");
#endif
#ifdef HAVE_GRANTPT
       output(screen, "   HAVE_GRANTPT\n");
#endif
#ifdef HAVE_GSSAPI
       output(screen, "   HAVE_GSSAPI\n");
#endif
#ifdef HAVE_GSSKRB5_EXTRACT_AUTHZ_DATA_FROM_SEC_CONTEXT
       output(screen, "   HAVE_GSSKRB5_EXTRACT_AUTHZ_DATA_FROM_SEC_CONTEXT\n");
#endif
#ifdef HAVE_GSSKRB5_GET_SUBKEY
       output(screen, "   HAVE_GSSKRB5_GET_SUBKEY\n");
#endif
#ifdef HAVE_GSS_DISPLAY_STATUS
       output(screen, "   HAVE_GSS_DISPLAY_STATUS\n");
#endif
#ifdef HAVE_GSS_EXPORT_CRED
       output(screen, "   HAVE_GSS_EXPORT_CRED\n");
#endif
#ifdef HAVE_GSS_IMPORT_CRED
       output(screen, "   HAVE_GSS_IMPORT_CRED\n");
#endif
#ifdef HAVE_GSS_INQUIRE_SEC_CONTEXT_BY_OID
       output(screen, "   HAVE_GSS_INQUIRE_SEC_CONTEXT_BY_OID\n");
#endif
#ifdef HAVE_GSS_KRB5_CRED_NO_CI_FLAGS_X
       output(screen, "   HAVE_GSS_KRB5_CRED_NO_CI_FLAGS_X\n");
#endif
#ifdef HAVE_GSS_KRB5_EXPORT_LUCID_SEC_CONTEXT
       output(screen, "   HAVE_GSS_KRB5_EXPORT_LUCID_SEC_CONTEXT\n");
#endif
#ifdef HAVE_GSS_KRB5_IMPORT_CRED
       output(screen, "   HAVE_GSS_KRB5_IMPORT_CRED\n");
#endif
#ifdef HAVE_GSS_OID_EQUAL
       output(screen, "   HAVE_GSS_OID_EQUAL\n");
#endif
#ifdef HAVE_GSS_WRAP_IOV
       output(screen, "   HAVE_GSS_WRAP_IOV\n");
#endif
#ifdef HAVE_HISTORY_LIST
       output(screen, "   HAVE_HISTORY_LIST\n");
#endif
#ifdef HAVE_HSTRERROR
       output(screen, "   HAVE_HSTRERROR\n");
#endif
#ifdef HAVE_HTTPCONNECT
       output(screen, "   HAVE_HTTPCONNECT\n");
#endif
#ifdef HAVE_HTTPCONNECT2
       output(screen, "   HAVE_HTTPCONNECT2\n");
#endif
#ifdef HAVE_HTTPCONNECTENCRYPT
       output(screen, "   HAVE_HTTPCONNECTENCRYPT\n");
#endif
#ifdef HAVE_H_ERRNO
       output(screen, "   HAVE_H_ERRNO\n");
#endif
#ifdef HAVE_ICONV
       output(screen, "   HAVE_ICONV\n");
#endif
#ifdef HAVE_ICONV_ERRNO_ILLEGAL_MULTIBYTE
       output(screen, "   HAVE_ICONV_ERRNO_ILLEGAL_MULTIBYTE\n");
#endif
#ifdef HAVE_ICONV_OPEN
       output(screen, "   HAVE_ICONV_OPEN\n");
#endif
#ifdef HAVE_IFACE_AIX
       output(screen, "   HAVE_IFACE_AIX\n");
#endif
#ifdef HAVE_IFACE_GETIFADDRS
       output(screen, "   HAVE_IFACE_GETIFADDRS\n");
#endif
#ifdef HAVE_IFACE_IFCONF
       output(screen, "   HAVE_IFACE_IFCONF\n");
#endif
#ifdef HAVE_IFACE_IFREQ
       output(screen, "   HAVE_IFACE_IFREQ\n");
#endif
#ifdef HAVE_IF_NAMETOINDEX
       output(screen, "   HAVE_IF_NAMETOINDEX\n");
#endif
#ifdef HAVE_IMMEDIATE_STRUCTURES
       output(screen, "   HAVE_IMMEDIATE_STRUCTURES\n");
#endif
#ifdef HAVE_INCOHERENT_MMAP
       output(screen, "   HAVE_INCOHERENT_MMAP\n");
#endif
#ifdef HAVE_INET_ATON
       output(screen, "   HAVE_INET_ATON\n");
#endif
#ifdef HAVE_INET_NTOA
       output(screen, "   HAVE_INET_NTOA\n");
#endif
#ifdef HAVE_INET_NTOP
       output(screen, "   HAVE_INET_NTOP\n");
#endif
#ifdef HAVE_INET_PTON
       output(screen, "   HAVE_INET_PTON\n");
#endif
#ifdef HAVE_INFLATEINIT2
       output(screen, "   HAVE_INFLATEINIT2\n");
#endif
#ifdef HAVE_INITGROUPS
       output(screen, "   HAVE_INITGROUPS\n");
#endif
#ifdef HAVE_INITIALIZE_KRB5_ERROR_TABLE
       output(screen, "   HAVE_INITIALIZE_KRB5_ERROR_TABLE\n");
#endif
#ifdef HAVE_INITSCR
       output(screen, "   HAVE_INITSCR\n");
#endif
#ifdef HAVE_INNETGR
       output(screen, "   HAVE_INNETGR\n");
#endif
#ifdef HAVE_INOTIFY
       output(screen, "   HAVE_INOTIFY\n");
#endif
#ifdef HAVE_INOTIFY_INIT
       output(screen, "   HAVE_INOTIFY_INIT\n");
#endif
#ifdef HAVE_INO_T
       output(screen, "   HAVE_INO_T\n");
#endif
#ifdef HAVE_INT16_T
       output(screen, "   HAVE_INT16_T\n");
#endif
#ifdef HAVE_INT32_T
       output(screen, "   HAVE_INT32_T\n");
#endif
#ifdef HAVE_INT64_T
       output(screen, "   HAVE_INT64_T\n");
#endif
#ifdef HAVE_INT8_T
       output(screen, "   HAVE_INT8_T\n");
#endif
#ifdef HAVE_INTPTR_T
       output(screen, "   HAVE_INTPTR_T\n");
#endif
#ifdef HAVE_IPV6
       output(screen, "   HAVE_IPV6\n");
#endif
#ifdef HAVE_IPV6_V6ONLY
       output(screen, "   HAVE_IPV6_V6ONLY\n");
#endif
#ifdef HAVE_IRUSEROK
       output(screen, "   HAVE_IRUSEROK\n");
#endif
#ifdef HAVE_ISATTY
       output(screen, "   HAVE_ISATTY\n");
#endif
#ifdef HAVE_ITEM_COUNT
       output(screen, "   HAVE_ITEM_COUNT\n");
#endif
#ifdef HAVE_KERNEL_OPLOCKS_LINUX
       output(screen, "   HAVE_KERNEL_OPLOCKS_LINUX\n");
#endif
#ifdef HAVE_KERNEL_SHARE_MODES
       output(screen, "   HAVE_KERNEL_SHARE_MODES\n");
#endif
#ifdef HAVE_KRB5
       output(screen, "   HAVE_KRB5\n");
#endif
#ifdef HAVE_KRB5_ADDRESSES
       output(screen, "   HAVE_KRB5_ADDRESSES\n");
#endif
#ifdef HAVE_KRB5_AUTH_CON_SETKEY
       output(screen, "   HAVE_KRB5_AUTH_CON_SETKEY\n");
#endif
#ifdef HAVE_KRB5_CC_COPY_CACHE
       output(screen, "   HAVE_KRB5_CC_COPY_CACHE\n");
#endif
#ifdef HAVE_KRB5_CC_GET_LIFETIME
       output(screen, "   HAVE_KRB5_CC_GET_LIFETIME\n");
#endif
#ifdef HAVE_KRB5_CONFIG_GET_BOOL_DEFAULT
       output(screen, "   HAVE_KRB5_CONFIG_GET_BOOL_DEFAULT\n");
#endif
#ifdef HAVE_KRB5_CREATE_CHECKSUM
       output(screen, "   HAVE_KRB5_CREATE_CHECKSUM\n");
#endif
#ifdef HAVE_KRB5_CRYPTO
       output(screen, "   HAVE_KRB5_CRYPTO\n");
#endif
#ifdef HAVE_KRB5_CRYPTO_DESTROY
       output(screen, "   HAVE_KRB5_CRYPTO_DESTROY\n");
#endif
#ifdef HAVE_KRB5_CRYPTO_INIT
       output(screen, "   HAVE_KRB5_CRYPTO_INIT\n");
#endif
#ifdef HAVE_KRB5_C_VERIFY_CHECKSUM
       output(screen, "   HAVE_KRB5_C_VERIFY_CHECKSUM\n");
#endif
#ifdef HAVE_KRB5_DATA_COPY
       output(screen, "   HAVE_KRB5_DATA_COPY\n");
#endif
#ifdef HAVE_KRB5_ENCTYPE_TO_STRING
       output(screen, "   HAVE_KRB5_ENCTYPE_TO_STRING\n");
#endif
#ifdef HAVE_KRB5_ENCTYPE_TO_STRING_WITH_KRB5_CONTEXT_ARG
       output(screen, "   HAVE_KRB5_ENCTYPE_TO_STRING_WITH_KRB5_CONTEXT_ARG\n");
#endif
#ifdef HAVE_KRB5_FREE_ERROR_CONTENTS
       output(screen, "   HAVE_KRB5_FREE_ERROR_CONTENTS\n");
#endif
#ifdef HAVE_KRB5_FREE_HOST_REALM
       output(screen, "   HAVE_KRB5_FREE_HOST_REALM\n");
#endif
#ifdef HAVE_KRB5_FWD_TGT_CREDS
       output(screen, "   HAVE_KRB5_FWD_TGT_CREDS\n");
#endif
#ifdef HAVE_KRB5_GET_CREDS
       output(screen, "   HAVE_KRB5_GET_CREDS\n");
#endif
#ifdef HAVE_KRB5_GET_CREDS_OPT_ALLOC
       output(screen, "   HAVE_KRB5_GET_CREDS_OPT_ALLOC\n");
#endif
#ifdef HAVE_KRB5_GET_CREDS_OPT_SET_IMPERSONATE
       output(screen, "   HAVE_KRB5_GET_CREDS_OPT_SET_IMPERSONATE\n");
#endif
#ifdef HAVE_KRB5_GET_DEFAULT_IN_TKT_ETYPES
       output(screen, "   HAVE_KRB5_GET_DEFAULT_IN_TKT_ETYPES\n");
#endif
#ifdef HAVE_KRB5_GET_HOST_REALM
       output(screen, "   HAVE_KRB5_GET_HOST_REALM\n");
#endif
#ifdef HAVE_KRB5_GET_INIT_CREDS_KEYBLOCK
       output(screen, "   HAVE_KRB5_GET_INIT_CREDS_KEYBLOCK\n");
#endif
#ifdef HAVE_KRB5_GET_INIT_CREDS_OPT_ALLOC
       output(screen, "   HAVE_KRB5_GET_INIT_CREDS_OPT_ALLOC\n");
#endif
#ifdef HAVE_KRB5_GET_INIT_CREDS_OPT_FREE
       output(screen, "   HAVE_KRB5_GET_INIT_CREDS_OPT_FREE\n");
#endif
#ifdef HAVE_KRB5_GET_INIT_CREDS_OPT_GET_ERROR
       output(screen, "   HAVE_KRB5_GET_INIT_CREDS_OPT_GET_ERROR\n");
#endif
#ifdef HAVE_KRB5_GET_INIT_CREDS_OPT_SET_PAC_REQUEST
       output(screen, "   HAVE_KRB5_GET_INIT_CREDS_OPT_SET_PAC_REQUEST\n");
#endif
#ifdef HAVE_KRB5_GET_PW_SALT
       output(screen, "   HAVE_KRB5_GET_PW_SALT\n");
#endif
#ifdef HAVE_KRB5_GET_RENEWED_CREDS
       output(screen, "   HAVE_KRB5_GET_RENEWED_CREDS\n");
#endif
#ifdef HAVE_KRB5_KEYBLOCK_INIT
       output(screen, "   HAVE_KRB5_KEYBLOCK_INIT\n");
#endif
#ifdef HAVE_KRB5_KEYBLOCK_KEYVALUE
       output(screen, "   HAVE_KRB5_KEYBLOCK_KEYVALUE\n");
#endif
#ifdef HAVE_KRB5_KEYTAB_ENTRY_KEYBLOCK
       output(screen, "   HAVE_KRB5_KEYTAB_ENTRY_KEYBLOCK\n");
#endif
#ifdef HAVE_KRB5_KRBHST_GET_ADDRINFO
       output(screen, "   HAVE_KRB5_KRBHST_GET_ADDRINFO\n");
#endif
#ifdef HAVE_KRB5_KRBHST_INIT
       output(screen, "   HAVE_KRB5_KRBHST_INIT\n");
#endif
#ifdef HAVE_KRB5_KT_COMPARE
       output(screen, "   HAVE_KRB5_KT_COMPARE\n");
#endif
#ifdef HAVE_KRB5_KT_FREE_ENTRY
       output(screen, "   HAVE_KRB5_KT_FREE_ENTRY\n");
#endif
#ifdef HAVE_KRB5_KU_OTHER_CKSUM
       output(screen, "   HAVE_KRB5_KU_OTHER_CKSUM\n");
#endif
#ifdef HAVE_KRB5_MAKE_PRINCIPAL
       output(screen, "   HAVE_KRB5_MAKE_PRINCIPAL\n");
#endif
#ifdef HAVE_KRB5_MK_REQ_EXTENDED
       output(screen, "   HAVE_KRB5_MK_REQ_EXTENDED\n");
#endif
#ifdef HAVE_KRB5_PDU_NONE_DECL
       output(screen, "   HAVE_KRB5_PDU_NONE_DECL\n");
#endif
#ifdef HAVE_KRB5_PRINCIPAL_COMPARE_ANY_REALM
       output(screen, "   HAVE_KRB5_PRINCIPAL_COMPARE_ANY_REALM\n");
#endif
#ifdef HAVE_KRB5_PRINCIPAL_GET_COMP_STRING
       output(screen, "   HAVE_KRB5_PRINCIPAL_GET_COMP_STRING\n");
#endif
#ifdef HAVE_KRB5_PRINCIPAL_GET_NUM_COMP
       output(screen, "   HAVE_KRB5_PRINCIPAL_GET_NUM_COMP\n");
#endif
#ifdef HAVE_KRB5_PRINCIPAL_GET_REALM
       output(screen, "   HAVE_KRB5_PRINCIPAL_GET_REALM\n");
#endif
#ifdef HAVE_KRB5_PRINCIPAL_GET_TYPE
       output(screen, "   HAVE_KRB5_PRINCIPAL_GET_TYPE\n");
#endif
#ifdef HAVE_KRB5_PRINCIPAL_SET_REALM
       output(screen, "   HAVE_KRB5_PRINCIPAL_SET_REALM\n");
#endif
#ifdef HAVE_KRB5_PRINCIPAL_SET_TYPE
       output(screen, "   HAVE_KRB5_PRINCIPAL_SET_TYPE\n");
#endif
#ifdef HAVE_KRB5_PROMPT_TYPE
       output(screen, "   HAVE_KRB5_PROMPT_TYPE\n");
#endif
#ifdef HAVE_KRB5_REALM_TYPE
       output(screen, "   HAVE_KRB5_REALM_TYPE\n");
#endif
#ifdef HAVE_KRB5_SET_DEFAULT_IN_TKT_ETYPES
       output(screen, "   HAVE_KRB5_SET_DEFAULT_IN_TKT_ETYPES\n");
#endif
#ifdef HAVE_KRB5_SET_REAL_TIME
       output(screen, "   HAVE_KRB5_SET_REAL_TIME\n");
#endif
#ifdef HAVE_KRB5_STRING_TO_KEY
       output(screen, "   HAVE_KRB5_STRING_TO_KEY\n");
#endif
#ifdef HAVE_KRB5_STRING_TO_KEY_SALT
       output(screen, "   HAVE_KRB5_STRING_TO_KEY_SALT\n");
#endif
#ifdef HAVE_KRB5_WARNX
       output(screen, "   HAVE_KRB5_WARNX\n");
#endif
#ifdef HAVE_KRB_STRUCT_WINSIZE
       output(screen, "   HAVE_KRB_STRUCT_WINSIZE\n");
#endif
#ifdef HAVE_LCHOWN
       output(screen, "   HAVE_LCHOWN\n");
#endif
#ifdef HAVE_LDWRAP
       output(screen, "   HAVE_LDWRAP\n");
#endif
#ifdef HAVE_LD_VERSION_SCRIPT
       output(screen, "   HAVE_LD_VERSION_SCRIPT\n");
#endif
#ifdef HAVE_LIBBSD
       output(screen, "   HAVE_LIBBSD\n");
#endif
#ifdef HAVE_LIBCRYPT
       output(screen, "   HAVE_LIBCRYPT\n");
#endif
#ifdef HAVE_LIBCRYPTO
       output(screen, "   HAVE_LIBCRYPTO\n");
#endif
#ifdef HAVE_LIBDL
       output(screen, "   HAVE_LIBDL\n");
#endif
#ifdef HAVE_LIBFORM
       output(screen, "   HAVE_LIBFORM\n");
#endif
#ifdef HAVE_LIBKRB5
       output(screen, "   HAVE_LIBKRB5\n");
#endif
#ifdef HAVE_LIBMENU
       output(screen, "   HAVE_LIBMENU\n");
#endif
#ifdef HAVE_LIBNCURSES
       output(screen, "   HAVE_LIBNCURSES\n");
#endif
#ifdef HAVE_LIBNSL
       output(screen, "   HAVE_LIBNSL\n");
#endif
#ifdef HAVE_LIBPAM
       output(screen, "   HAVE_LIBPAM\n");
#endif
#ifdef HAVE_LIBPANEL
       output(screen, "   HAVE_LIBPANEL\n");
#endif
#ifdef HAVE_LIBPOPT
       output(screen, "   HAVE_LIBPOPT\n");
#endif
#ifdef HAVE_LIBPTHREAD
       output(screen, "   HAVE_LIBPTHREAD\n");
#endif
#ifdef HAVE_LIBREPLACE
       output(screen, "   HAVE_LIBREPLACE\n");
#endif
#ifdef HAVE_LIBRESOLV
       output(screen, "   HAVE_LIBRESOLV\n");
#endif
#ifdef HAVE_LIBTASN1
       output(screen, "   HAVE_LIBTASN1\n");
#endif
#ifdef HAVE_LIBUTIL
       output(screen, "   HAVE_LIBUTIL\n");
#endif
#ifdef HAVE_LIBZ
       output(screen, "   HAVE_LIBZ\n");
#endif
#ifdef HAVE_LINK
       output(screen, "   HAVE_LINK\n");
#endif
#ifdef HAVE_LINUX_FALLOCATE
       output(screen, "   HAVE_LINUX_FALLOCATE\n");
#endif
#ifdef HAVE_LINUX_INOTIFY
       output(screen, "   HAVE_LINUX_INOTIFY\n");
#endif
#ifdef HAVE_LINUX_IOCTL
       output(screen, "   HAVE_LINUX_IOCTL\n");
#endif
#ifdef HAVE_LINUX_READAHEAD
       output(screen, "   HAVE_LINUX_READAHEAD\n");
#endif
#ifdef HAVE_LINUX_SPLICE
       output(screen, "   HAVE_LINUX_SPLICE\n");
#endif
#ifdef HAVE_LINUX_THREAD_CREDENTIALS
       output(screen, "   HAVE_LINUX_THREAD_CREDENTIALS\n");
#endif
#ifdef HAVE_LITTLE_ENDIAN
       output(screen, "   HAVE_LITTLE_ENDIAN\n");
#endif
#ifdef HAVE_LLSEEK
       output(screen, "   HAVE_LLSEEK\n");
#endif
#ifdef HAVE_LOFF_T
       output(screen, "   HAVE_LOFF_T\n");
#endif
#ifdef HAVE_LONGJMP
       output(screen, "   HAVE_LONGJMP\n");
#endif
#ifdef HAVE_LONG_LONG
       output(screen, "   HAVE_LONG_LONG\n");
#endif
#ifdef HAVE_LSEEK_HOLE_DATA
       output(screen, "   HAVE_LSEEK_HOLE_DATA\n");
#endif
#ifdef HAVE_LSTAT
       output(screen, "   HAVE_LSTAT\n");
#endif
#ifdef HAVE_LUTIMES
       output(screen, "   HAVE_LUTIMES\n");
#endif
#ifdef HAVE_MAKEDEV
       output(screen, "   HAVE_MAKEDEV\n");
#endif
#ifdef HAVE_MALLINFO
       output(screen, "   HAVE_MALLINFO\n");
#endif
#ifdef HAVE_MEMALIGN
       output(screen, "   HAVE_MEMALIGN\n");
#endif
#ifdef HAVE_MEMCPY
       output(screen, "   HAVE_MEMCPY\n");
#endif
#ifdef HAVE_MEMMEM
       output(screen, "   HAVE_MEMMEM\n");
#endif
#ifdef HAVE_MEMMOVE
       output(screen, "   HAVE_MEMMOVE\n");
#endif
#ifdef HAVE_MEMSET
       output(screen, "   HAVE_MEMSET\n");
#endif
#ifdef HAVE_MEMSET_EXPLICIT
       output(screen, "   HAVE_MEMSET_EXPLICIT\n");
#endif
#ifdef HAVE_MEMSET_S
       output(screen, "   HAVE_MEMSET_S\n");
#endif
#ifdef HAVE_MKDIR_MODE
       output(screen, "   HAVE_MKDIR_MODE\n");
#endif
#ifdef HAVE_MKDTEMP
       output(screen, "   HAVE_MKDTEMP\n");
#endif
#ifdef HAVE_MKNOD
       output(screen, "   HAVE_MKNOD\n");
#endif
#ifdef HAVE_MKNODAT
       output(screen, "   HAVE_MKNODAT\n");
#endif
#ifdef HAVE_MKTIME
       output(screen, "   HAVE_MKTIME\n");
#endif
#ifdef HAVE_MLOCK
       output(screen, "   HAVE_MLOCK\n");
#endif
#ifdef HAVE_MLOCKALL
       output(screen, "   HAVE_MLOCKALL\n");
#endif
#ifdef HAVE_MMAP
       output(screen, "   HAVE_MMAP\n");
#endif
#ifdef HAVE_MREMAP
       output(screen, "   HAVE_MREMAP\n");
#endif
#ifdef HAVE_MUNLOCK
       output(screen, "   HAVE_MUNLOCK\n");
#endif
#ifdef HAVE_MUNLOCKALL
       output(screen, "   HAVE_MUNLOCKALL\n");
#endif
#ifdef HAVE_NATIVE_ICONV
       output(screen, "   HAVE_NATIVE_ICONV\n");
#endif
#ifdef HAVE_NCURSES
       output(screen, "   HAVE_NCURSES\n");
#endif
#ifdef HAVE_NEW_FIELD
       output(screen, "   HAVE_NEW_FIELD\n");
#endif
#ifdef HAVE_NEW_FORM
       output(screen, "   HAVE_NEW_FORM\n");
#endif
#ifdef HAVE_NEW_PANEL
       output(screen, "   HAVE_NEW_PANEL\n");
#endif
#ifdef HAVE_NFS_QUOTAS
       output(screen, "   HAVE_NFS_QUOTAS\n");
#endif
#ifdef HAVE_NFTW
       output(screen, "   HAVE_NFTW\n");
#endif
#ifdef HAVE_NSCD_FLUSH_CACHE
       output(screen, "   HAVE_NSCD_FLUSH_CACHE\n");
#endif
#ifdef HAVE_NSS_XBYY_KEY_IPNODE
       output(screen, "   HAVE_NSS_XBYY_KEY_IPNODE\n");
#endif
#ifdef HAVE_OFD_LOCKS
       output(screen, "   HAVE_OFD_LOCKS\n");
#endif
#ifdef HAVE_OFFSET_T
       output(screen, "   HAVE_OFFSET_T\n");
#endif
#ifdef HAVE_OPENAT
       output(screen, "   HAVE_OPENAT\n");
#endif
#ifdef HAVE_OPENPTY
       output(screen, "   HAVE_OPENPTY\n");
#endif
#ifdef HAVE_OPEN_O_DIRECT
       output(screen, "   HAVE_OPEN_O_DIRECT\n");
#endif
#ifdef HAVE_PAM_START
       output(screen, "   HAVE_PAM_START\n");
#endif
#ifdef HAVE_PASSWD_PW_AGE
       output(screen, "   HAVE_PASSWD_PW_AGE\n");
#endif
#ifdef HAVE_PASSWD_PW_COMMENT
       output(screen, "   HAVE_PASSWD_PW_COMMENT\n");
#endif
#ifdef HAVE_PATHCONF
       output(screen, "   HAVE_PATHCONF\n");
#endif
#ifdef HAVE_PEERCRED
       output(screen, "   HAVE_PEERCRED\n");
#endif
#ifdef HAVE_PIPE
       output(screen, "   HAVE_PIPE\n");
#endif
#ifdef HAVE_POLL
       output(screen, "   HAVE_POLL\n");
#endif
#ifdef HAVE_POPT
       output(screen, "   HAVE_POPT\n");
#endif
#ifdef HAVE_POPTGETCONTEXT
       output(screen, "   HAVE_POPTGETCONTEXT\n");
#endif
#ifdef HAVE_PORT_CREATE
       output(screen, "   HAVE_PORT_CREATE\n");
#endif
#ifdef HAVE_POSIX_FADVISE
       output(screen, "   HAVE_POSIX_FADVISE\n");
#endif
#ifdef HAVE_POSIX_FALLOCATE
       output(screen, "   HAVE_POSIX_FALLOCATE\n");
#endif
#ifdef HAVE_POSIX_MEMALIGN
       output(screen, "   HAVE_POSIX_MEMALIGN\n");
#endif
#ifdef HAVE_POSIX_OPENPT
       output(screen, "   HAVE_POSIX_OPENPT\n");
#endif
#ifdef HAVE_PRCTL
       output(screen, "   HAVE_PRCTL\n");
#endif
#ifdef HAVE_PREAD
       output(screen, "   HAVE_PREAD\n");
#endif
#ifdef HAVE_PREAD_DECL
       output(screen, "   HAVE_PREAD_DECL\n");
#endif
#ifdef HAVE_PRINTF
       output(screen, "   HAVE_PRINTF\n");
#endif
#ifdef HAVE_PROGRAM_INVOCATION_SHORT_NAME
       output(screen, "   HAVE_PROGRAM_INVOCATION_SHORT_NAME\n");
#endif
#ifdef HAVE_PTHREAD
       output(screen, "   HAVE_PTHREAD\n");
#endif
#ifdef HAVE_PTHREAD_ATTR_INIT
       output(screen, "   HAVE_PTHREAD_ATTR_INIT\n");
#endif
#ifdef HAVE_PTHREAD_CREATE
       output(screen, "   HAVE_PTHREAD_CREATE\n");
#endif
#ifdef HAVE_PTHREAD_MUTEXATTR_SETROBUST
       output(screen, "   HAVE_PTHREAD_MUTEXATTR_SETROBUST\n");
#endif
#ifdef HAVE_PTHREAD_MUTEX_CONSISTENT
       output(screen, "   HAVE_PTHREAD_MUTEX_CONSISTENT\n");
#endif
#ifdef HAVE_PTRDIFF_T
       output(screen, "   HAVE_PTRDIFF_T\n");
#endif
#ifdef HAVE_PUTENV
       output(screen, "   HAVE_PUTENV\n");
#endif
#ifdef HAVE_PUTUTLINE
       output(screen, "   HAVE_PUTUTLINE\n");
#endif
#ifdef HAVE_PUTUTXLINE
       output(screen, "   HAVE_PUTUTXLINE\n");
#endif
#ifdef HAVE_PWRITE
       output(screen, "   HAVE_PWRITE\n");
#endif
#ifdef HAVE_PWRITE_DECL
       output(screen, "   HAVE_PWRITE_DECL\n");
#endif
#ifdef HAVE_QUOTACTL_LINUX
       output(screen, "   HAVE_QUOTACTL_LINUX\n");
#endif
#ifdef HAVE_RAND
       output(screen, "   HAVE_RAND\n");
#endif
#ifdef HAVE_RANDOM
       output(screen, "   HAVE_RANDOM\n");
#endif
#ifdef HAVE_RCMD
       output(screen, "   HAVE_RCMD\n");
#endif
#ifdef HAVE_RDCHK
       output(screen, "   HAVE_RDCHK\n");
#endif
#ifdef HAVE_READAHEAD_DECL
       output(screen, "   HAVE_READAHEAD_DECL\n");
#endif
#ifdef HAVE_READLINK
       output(screen, "   HAVE_READLINK\n");
#endif
#ifdef HAVE_READV
       output(screen, "   HAVE_READV\n");
#endif
#ifdef HAVE_REALPATH
       output(screen, "   HAVE_REALPATH\n");
#endif
#ifdef HAVE_RENAME
       output(screen, "   HAVE_RENAME\n");
#endif
#ifdef HAVE_RES_NDESTROY
       output(screen, "   HAVE_RES_NDESTROY\n");
#endif
#ifdef HAVE_RES_NSEARCH
       output(screen, "   HAVE_RES_NSEARCH\n");
#endif
#ifdef HAVE_RES_SEARCH
       output(screen, "   HAVE_RES_SEARCH\n");
#endif
#ifdef HAVE_RL_COMPLETION_FUNC_T
       output(screen, "   HAVE_RL_COMPLETION_FUNC_T\n");
#endif
#ifdef HAVE_RL_COMPLETION_MATCHES
       output(screen, "   HAVE_RL_COMPLETION_MATCHES\n");
#endif
#ifdef HAVE_ROBUST_MUTEXES
       output(screen, "   HAVE_ROBUST_MUTEXES\n");
#endif
#ifdef HAVE_RPC_RPC_HEADERS
       output(screen, "   HAVE_RPC_RPC_HEADERS\n");
#endif
#ifdef HAVE_RW_HINTS
       output(screen, "   HAVE_RW_HINTS\n");
#endif
#ifdef HAVE_SA_FAMILY_T
       output(screen, "   HAVE_SA_FAMILY_T\n");
#endif
#ifdef HAVE_SA_SIGINFO_DECL
       output(screen, "   HAVE_SA_SIGINFO_DECL\n");
#endif
#ifdef HAVE_SECURE_GETENV
       output(screen, "   HAVE_SECURE_GETENV\n");
#endif
#ifdef HAVE_SELECT
       output(screen, "   HAVE_SELECT\n");
#endif
#ifdef HAVE_SENDFILE
       output(screen, "   HAVE_SENDFILE\n");
#endif
#ifdef HAVE_SENDMSG
       output(screen, "   HAVE_SENDMSG\n");
#endif
#ifdef HAVE_SETBUFFER
       output(screen, "   HAVE_SETBUFFER\n");
#endif
#ifdef HAVE_SETEGID
       output(screen, "   HAVE_SETEGID\n");
#endif
#ifdef HAVE_SETENV
       output(screen, "   HAVE_SETENV\n");
#endif
#ifdef HAVE_SETENV_DECL
       output(screen, "   HAVE_SETENV_DECL\n");
#endif
#ifdef HAVE_SETEUID
       output(screen, "   HAVE_SETEUID\n");
#endif
#ifdef HAVE_SETGID
       output(screen, "   HAVE_SETGID\n");
#endif
#ifdef HAVE_SETGIDX
       output(screen, "   HAVE_SETGIDX\n");
#endif
#ifdef HAVE_SETGROUPS
       output(screen, "   HAVE_SETGROUPS\n");
#endif
#ifdef HAVE_SETHOSTENT
       output(screen, "   HAVE_SETHOSTENT\n");
#endif
#ifdef HAVE_SETITIMER
       output(screen, "   HAVE_SETITIMER\n");
#endif
#ifdef HAVE_SETLINEBUF
       output(screen, "   HAVE_SETLINEBUF\n");
#endif
#ifdef HAVE_SETLOCALE
       output(screen, "   HAVE_SETLOCALE\n");
#endif
#ifdef HAVE_SETLUID
       output(screen, "   HAVE_SETLUID\n");
#endif
#ifdef HAVE_SETMNTENT
       output(screen, "   HAVE_SETMNTENT\n");
#endif
#ifdef HAVE_SETPGID
       output(screen, "   HAVE_SETPGID\n");
#endif
#ifdef HAVE_SETPRIV
       output(screen, "   HAVE_SETPRIV\n");
#endif
#ifdef HAVE_SETPROCTITLE
       output(screen, "   HAVE_SETPROCTITLE\n");
#endif
#ifdef HAVE_SETPROCTITLE_INIT
       output(screen, "   HAVE_SETPROCTITLE_INIT\n");
#endif
#ifdef HAVE_SETPROGNAME
       output(screen, "   HAVE_SETPROGNAME\n");
#endif
#ifdef HAVE_SETREGID
       output(screen, "   HAVE_SETREGID\n");
#endif
#ifdef HAVE_SETRESGID
       output(screen, "   HAVE_SETRESGID\n");
#endif
#ifdef HAVE_SETRESGID_DECL
       output(screen, "   HAVE_SETRESGID_DECL\n");
#endif
#ifdef HAVE_SETRESUID
       output(screen, "   HAVE_SETRESUID\n");
#endif
#ifdef HAVE_SETRESUID_DECL
       output(screen, "   HAVE_SETRESUID_DECL\n");
#endif
#ifdef HAVE_SETREUID
       output(screen, "   HAVE_SETREUID\n");
#endif
#ifdef HAVE_SETSID
       output(screen, "   HAVE_SETSID\n");
#endif
#ifdef HAVE_SETUID
       output(screen, "   HAVE_SETUID\n");
#endif
#ifdef HAVE_SETUIDX
       output(screen, "   HAVE_SETUIDX\n");
#endif
#ifdef HAVE_SET_MENU_ITEMS
       output(screen, "   HAVE_SET_MENU_ITEMS\n");
#endif
#ifdef HAVE_SHA1_UPDATE
       output(screen, "   HAVE_SHA1_UPDATE\n");
#endif
#ifdef HAVE_SHARED_MMAP
       output(screen, "   HAVE_SHARED_MMAP\n");
#endif
#ifdef HAVE_SHL_FINDSYM
       output(screen, "   HAVE_SHL_FINDSYM\n");
#endif
#ifdef HAVE_SHL_LOAD
       output(screen, "   HAVE_SHL_LOAD\n");
#endif
#ifdef HAVE_SHL_UNLOAD
       output(screen, "   HAVE_SHL_UNLOAD\n");
#endif
#ifdef HAVE_SHOW_PANEL
       output(screen, "   HAVE_SHOW_PANEL\n");
#endif
#ifdef HAVE_SIGACTION
       output(screen, "   HAVE_SIGACTION\n");
#endif
#ifdef HAVE_SIGBLOCK
       output(screen, "   HAVE_SIGBLOCK\n");
#endif
#ifdef HAVE_SIGGETMASK
       output(screen, "   HAVE_SIGGETMASK\n");
#endif
#ifdef HAVE_SIGLONGJMP
       output(screen, "   HAVE_SIGLONGJMP\n");
#endif
#ifdef HAVE_SIGPROCMASK
       output(screen, "   HAVE_SIGPROCMASK\n");
#endif
#ifdef HAVE_SIGSET
       output(screen, "   HAVE_SIGSET\n");
#endif
#ifdef HAVE_SIGSETMASK
       output(screen, "   HAVE_SIGSETMASK\n");
#endif
#ifdef HAVE_SIG_ATOMIC_T_TYPE
       output(screen, "   HAVE_SIG_ATOMIC_T_TYPE\n");
#endif
#ifdef HAVE_SIZE_T
       output(screen, "   HAVE_SIZE_T\n");
#endif
#ifdef HAVE_SNPRINTF
       output(screen, "   HAVE_SNPRINTF\n");
#endif
#ifdef HAVE_SOCKADDR_SA_LEN
       output(screen, "   HAVE_SOCKADDR_SA_LEN\n");
#endif
#ifdef HAVE_SOCKET
       output(screen, "   HAVE_SOCKET\n");
#endif
#ifdef HAVE_SOCKETPAIR
       output(screen, "   HAVE_SOCKETPAIR\n");
#endif
#ifdef HAVE_SOCKLEN_T
       output(screen, "   HAVE_SOCKLEN_T\n");
#endif
#ifdef HAVE_SOCK_SIN6_LEN
       output(screen, "   HAVE_SOCK_SIN6_LEN\n");
#endif
#ifdef HAVE_SOCK_SIN_LEN
       output(screen, "   HAVE_SOCK_SIN_LEN\n");
#endif
#ifdef HAVE_SPLICE_DECL
       output(screen, "   HAVE_SPLICE_DECL\n");
#endif
#ifdef HAVE_SRAND
       output(screen, "   HAVE_SRAND\n");
#endif
#ifdef HAVE_SRANDOM
       output(screen, "   HAVE_SRANDOM\n");
#endif
#ifdef HAVE_SSIZE_T
       output(screen, "   HAVE_SSIZE_T\n");
#endif
#ifdef HAVE_SS_FAMILY
       output(screen, "   HAVE_SS_FAMILY\n");
#endif
#ifdef HAVE_STATFS_F_FSID
       output(screen, "   HAVE_STATFS_F_FSID\n");
#endif
#ifdef HAVE_STATVFS
       output(screen, "   HAVE_STATVFS\n");
#endif
#ifdef HAVE_STATVFS_F_FLAG
       output(screen, "   HAVE_STATVFS_F_FLAG\n");
#endif
#ifdef HAVE_STATVFS_F_FLAGS
       output(screen, "   HAVE_STATVFS_F_FLAGS\n");
#endif
#ifdef HAVE_STAT_HIRES_TIMESTAMPS
       output(screen, "   HAVE_STAT_HIRES_TIMESTAMPS\n");
#endif
#ifdef HAVE_STAT_ST_BLKSIZE
       output(screen, "   HAVE_STAT_ST_BLKSIZE\n");
#endif
#ifdef HAVE_STAT_ST_BLOCKS
       output(screen, "   HAVE_STAT_ST_BLOCKS\n");
#endif
#ifdef HAVE_STAT_ST_FLAGS
       output(screen, "   HAVE_STAT_ST_FLAGS\n");
#endif
#ifdef HAVE_STRCASECMP
       output(screen, "   HAVE_STRCASECMP\n");
#endif
#ifdef HAVE_STRCASESTR
       output(screen, "   HAVE_STRCASESTR\n");
#endif
#ifdef HAVE_STRCHR
       output(screen, "   HAVE_STRCHR\n");
#endif
#ifdef HAVE_STRCPY
       output(screen, "   HAVE_STRCPY\n");
#endif
#ifdef HAVE_STRDUP
       output(screen, "   HAVE_STRDUP\n");
#endif
#ifdef HAVE_STRERROR
       output(screen, "   HAVE_STRERROR\n");
#endif
#ifdef HAVE_STRERROR_R
       output(screen, "   HAVE_STRERROR_R\n");
#endif
#ifdef HAVE_STRFTIME
       output(screen, "   HAVE_STRFTIME\n");
#endif
#ifdef HAVE_STRLCAT
       output(screen, "   HAVE_STRLCAT\n");
#endif
#ifdef HAVE_STRLCPY
       output(screen, "   HAVE_STRLCPY\n");
#endif
#ifdef HAVE_STRLWR
       output(screen, "   HAVE_STRLWR\n");
#endif
#ifdef HAVE_STRNCASECMP
       output(screen, "   HAVE_STRNCASECMP\n");
#endif
#ifdef HAVE_STRNCPY
       output(screen, "   HAVE_STRNCPY\n");
#endif
#ifdef HAVE_STRNDUP
       output(screen, "   HAVE_STRNDUP\n");
#endif
#ifdef HAVE_STRNLEN
       output(screen, "   HAVE_STRNLEN\n");
#endif
#ifdef HAVE_STRPBRK
       output(screen, "   HAVE_STRPBRK\n");
#endif
#ifdef HAVE_STRPTIME
       output(screen, "   HAVE_STRPTIME\n");
#endif
#ifdef HAVE_STRSEP
       output(screen, "   HAVE_STRSEP\n");
#endif
#ifdef HAVE_STRSEP_COPY
       output(screen, "   HAVE_STRSEP_COPY\n");
#endif
#ifdef HAVE_STRSIGNAL
       output(screen, "   HAVE_STRSIGNAL\n");
#endif
#ifdef HAVE_STRTOK_R
       output(screen, "   HAVE_STRTOK_R\n");
#endif
#ifdef HAVE_STRTOL
       output(screen, "   HAVE_STRTOL\n");
#endif
#ifdef HAVE_STRTOLL
       output(screen, "   HAVE_STRTOLL\n");
#endif
#ifdef HAVE_STRTOQ
       output(screen, "   HAVE_STRTOQ\n");
#endif
#ifdef HAVE_STRTOULL
       output(screen, "   HAVE_STRTOULL\n");
#endif
#ifdef HAVE_STRTOUQ
       output(screen, "   HAVE_STRTOUQ\n");
#endif
#ifdef HAVE_STRUCT_ADDRINFO
       output(screen, "   HAVE_STRUCT_ADDRINFO\n");
#endif
#ifdef HAVE_STRUCT_DQBLK_DQB_CURBYTES
       output(screen, "   HAVE_STRUCT_DQBLK_DQB_CURBYTES\n");
#endif
#ifdef HAVE_STRUCT_IFADDRS
       output(screen, "   HAVE_STRUCT_IFADDRS\n");
#endif
#ifdef HAVE_STRUCT_MSGHDR_MSG_ACCRIGHTS
       output(screen, "   HAVE_STRUCT_MSGHDR_MSG_ACCRIGHTS\n");
#endif
#ifdef HAVE_STRUCT_MSGHDR_MSG_CONTROL
       output(screen, "   HAVE_STRUCT_MSGHDR_MSG_CONTROL\n");
#endif
#ifdef HAVE_STRUCT_SECMETHOD_TABLE_METHOD_ATTRLIST
       output(screen, "   HAVE_STRUCT_SECMETHOD_TABLE_METHOD_ATTRLIST\n");
#endif
#ifdef HAVE_STRUCT_SECMETHOD_TABLE_METHOD_VERSION
       output(screen, "   HAVE_STRUCT_SECMETHOD_TABLE_METHOD_VERSION\n");
#endif
#ifdef HAVE_STRUCT_SIGEVENT
       output(screen, "   HAVE_STRUCT_SIGEVENT\n");
#endif
#ifdef HAVE_STRUCT_SIGEVENT_SIGEV_VALUE_SIGVAL_PTR
       output(screen, "   HAVE_STRUCT_SIGEVENT_SIGEV_VALUE_SIGVAL_PTR\n");
#endif
#ifdef HAVE_STRUCT_SIGEVENT_SIGEV_VALUE_SIVAL_PTR
       output(screen, "   HAVE_STRUCT_SIGEVENT_SIGEV_VALUE_SIVAL_PTR\n");
#endif
#ifdef HAVE_STRUCT_SOCKADDR
       output(screen, "   HAVE_STRUCT_SOCKADDR\n");
#endif
#ifdef HAVE_STRUCT_SOCKADDR_IN6
       output(screen, "   HAVE_STRUCT_SOCKADDR_IN6\n");
#endif
#ifdef HAVE_STRUCT_SOCKADDR_STORAGE
       output(screen, "   HAVE_STRUCT_SOCKADDR_STORAGE\n");
#endif
#ifdef HAVE_STRUCT_STAT_ST_BIRTHTIME
       output(screen, "   HAVE_STRUCT_STAT_ST_BIRTHTIME\n");
#endif
#ifdef HAVE_STRUCT_STAT_ST_BIRTHTIMENSEC
       output(screen, "   HAVE_STRUCT_STAT_ST_BIRTHTIMENSEC\n");
#endif
#ifdef HAVE_STRUCT_STAT_ST_BIRTHTIMESPEC_TV_NSEC
       output(screen, "   HAVE_STRUCT_STAT_ST_BIRTHTIMESPEC_TV_NSEC\n");
#endif
#ifdef HAVE_STRUCT_STAT_ST_MTIMENSEC
       output(screen, "   HAVE_STRUCT_STAT_ST_MTIMENSEC\n");
#endif
#ifdef HAVE_STRUCT_STAT_ST_MTIMESPEC_TV_NSEC
       output(screen, "   HAVE_STRUCT_STAT_ST_MTIMESPEC_TV_NSEC\n");
#endif
#ifdef HAVE_STRUCT_STAT_ST_MTIME_N
       output(screen, "   HAVE_STRUCT_STAT_ST_MTIME_N\n");
#endif
#ifdef HAVE_STRUCT_STAT_ST_MTIM_TV_NSEC
       output(screen, "   HAVE_STRUCT_STAT_ST_MTIM_TV_NSEC\n");
#endif
#ifdef HAVE_STRUCT_STAT_ST_RDEV
       output(screen, "   HAVE_STRUCT_STAT_ST_RDEV\n");
#endif
#ifdef HAVE_STRUCT_STAT_ST_UMTIME
       output(screen, "   HAVE_STRUCT_STAT_ST_UMTIME\n");
#endif
#ifdef HAVE_STRUCT_TIMESPEC
       output(screen, "   HAVE_STRUCT_TIMESPEC\n");
#endif
#ifdef HAVE_STRUCT_WINSIZE
       output(screen, "   HAVE_STRUCT_WINSIZE\n");
#endif
#ifdef HAVE_STRUPR
       output(screen, "   HAVE_STRUPR\n");
#endif
#ifdef HAVE_ST_RDEV
       output(screen, "   HAVE_ST_RDEV\n");
#endif
#ifdef HAVE_SWAB
       output(screen, "   HAVE_SWAB\n");
#endif
#ifdef HAVE_SYMLINK
       output(screen, "   HAVE_SYMLINK\n");
#endif
#ifdef HAVE_SYSCALL
       output(screen, "   HAVE_SYSCALL\n");
#endif
#ifdef HAVE_SYSCONF
       output(screen, "   HAVE_SYSCONF\n");
#endif
#ifdef HAVE_SYSCTL
       output(screen, "   HAVE_SYSCTL\n");
#endif
#ifdef HAVE_SYSCTLBYNAME
       output(screen, "   HAVE_SYSCTLBYNAME\n");
#endif
#ifdef HAVE_SYSLOG
       output(screen, "   HAVE_SYSLOG\n");
#endif
#ifdef HAVE_TEXTDOMAIN
       output(screen, "   HAVE_TEXTDOMAIN\n");
#endif
#ifdef HAVE_TGETENT
       output(screen, "   HAVE_TGETENT\n");
#endif
#ifdef HAVE_TIMEGM
       output(screen, "   HAVE_TIMEGM\n");
#endif
#ifdef HAVE_UCONTEXT_T
       output(screen, "   HAVE_UCONTEXT_T\n");
#endif
#ifdef HAVE_UINT16_T
       output(screen, "   HAVE_UINT16_T\n");
#endif
#ifdef HAVE_UINT32_T
       output(screen, "   HAVE_UINT32_T\n");
#endif
#ifdef HAVE_UINT64_T
       output(screen, "   HAVE_UINT64_T\n");
#endif
#ifdef HAVE_UINT8_T
       output(screen, "   HAVE_UINT8_T\n");
#endif
#ifdef HAVE_UINTPTR_T
       output(screen, "   HAVE_UINTPTR_T\n");
#endif
#ifdef HAVE_UINT_T
       output(screen, "   HAVE_UINT_T\n");
#endif
#ifdef HAVE_UMASK
       output(screen, "   HAVE_UMASK\n");
#endif
#ifdef HAVE_UNAME
       output(screen, "   HAVE_UNAME\n");
#endif
#ifdef HAVE_UNIXSOCKET
       output(screen, "   HAVE_UNIXSOCKET\n");
#endif
#ifdef HAVE_UNSETENV
       output(screen, "   HAVE_UNSETENV\n");
#endif
#ifdef HAVE_UNSHARE_CLONE_FS
       output(screen, "   HAVE_UNSHARE_CLONE_FS\n");
#endif
#ifdef HAVE_UPDWTMP
       output(screen, "   HAVE_UPDWTMP\n");
#endif
#ifdef HAVE_UPDWTMPX
       output(screen, "   HAVE_UPDWTMPX\n");
#endif
#ifdef HAVE_USLEEP
       output(screen, "   HAVE_USLEEP\n");
#endif
#ifdef HAVE_UTIMBUF
       output(screen, "   HAVE_UTIMBUF\n");
#endif
#ifdef HAVE_UTIME
       output(screen, "   HAVE_UTIME\n");
#endif
#ifdef HAVE_UTIMENSAT
       output(screen, "   HAVE_UTIMENSAT\n");
#endif
#ifdef HAVE_UTIMES
       output(screen, "   HAVE_UTIMES\n");
#endif
#ifdef HAVE_UX_UT_HOST
       output(screen, "   HAVE_UX_UT_HOST\n");
#endif
#ifdef HAVE_UX_UT_SYSLEN
       output(screen, "   HAVE_UX_UT_SYSLEN\n");
#endif
#ifdef HAVE_U_CHAR
       output(screen, "   HAVE_U_CHAR\n");
#endif
#ifdef HAVE_U_INT32_T
       output(screen, "   HAVE_U_INT32_T\n");
#endif
#ifdef HAVE_VASPRINTF
       output(screen, "   HAVE_VASPRINTF\n");
#endif
#ifdef HAVE_VA_COPY
       output(screen, "   HAVE_VA_COPY\n");
#endif
#ifdef HAVE_VDPRINTF
       output(screen, "   HAVE_VDPRINTF\n");
#endif
#ifdef HAVE_VISIBILITY_ATTR
       output(screen, "   HAVE_VISIBILITY_ATTR\n");
#endif
#ifdef HAVE_VOLATILE
       output(screen, "   HAVE_VOLATILE\n");
#endif
#ifdef HAVE_VSNPRINTF
       output(screen, "   HAVE_VSNPRINTF\n");
#endif
#ifdef HAVE_VSYSLOG
       output(screen, "   HAVE_VSYSLOG\n");
#endif
#ifdef HAVE_WAIT4
       output(screen, "   HAVE_WAIT4\n");
#endif
#ifdef HAVE_WAITPID
       output(screen, "   HAVE_WAITPID\n");
#endif
#ifdef HAVE_WARN
       output(screen, "   HAVE_WARN\n");
#endif
#ifdef HAVE_WARNX
       output(screen, "   HAVE_WARNX\n");
#endif
#ifdef HAVE_WNO_FORMAT_TRUNCATION
       output(screen, "   HAVE_WNO_FORMAT_TRUNCATION\n");
#endif
#ifdef HAVE_WNO_STRICT_OVERFLOW
       output(screen, "   HAVE_WNO_STRICT_OVERFLOW\n");
#endif
#ifdef HAVE_WNO_UNUSED_FUNCTION
       output(screen, "   HAVE_WNO_UNUSED_FUNCTION\n");
#endif
#ifdef HAVE_WORKING_STRPTIME
       output(screen, "   HAVE_WORKING_STRPTIME\n");
#endif
#ifdef HAVE_WRITEV
       output(screen, "   HAVE_WRITEV\n");
#endif
#ifdef HAVE_WS_XPIXEL
       output(screen, "   HAVE_WS_XPIXEL\n");
#endif
#ifdef HAVE_WS_YPIXEL
       output(screen, "   HAVE_WS_YPIXEL\n");
#endif
#ifdef HAVE_XATTR_SUPPORT
       output(screen, "   HAVE_XATTR_SUPPORT\n");
#endif
#ifdef HAVE_XATTR_XATTR
       output(screen, "   HAVE_XATTR_XATTR\n");
#endif
#ifdef HAVE_XFS_QUOTAS
       output(screen, "   HAVE_XFS_QUOTAS\n");
#endif
#ifdef HAVE_ZLIB
       output(screen, "   HAVE_ZLIB\n");
#endif
#ifdef HAVE__Bool
       output(screen, "   HAVE__Bool\n");
#endif
#ifdef HAVE__DN_EXPAND
       output(screen, "   HAVE__DN_EXPAND\n");
#endif
#ifdef HAVE__RES
       output(screen, "   HAVE__RES\n");
#endif
#ifdef HAVE__VA_ARGS__MACRO
       output(screen, "   HAVE__VA_ARGS__MACRO\n");
#endif
#ifdef HAVE___ATTRIBUTE__
       output(screen, "   HAVE___ATTRIBUTE__\n");
#endif
#ifdef HAVE___DN_EXPAND
       output(screen, "   HAVE___DN_EXPAND\n");
#endif
#ifdef HAVE___SS_FAMILY
       output(screen, "   HAVE___SS_FAMILY\n");
#endif
#ifdef HAVE___STRTOLL
       output(screen, "   HAVE___STRTOLL\n");
#endif
#ifdef HAVE___STRTOULL
       output(screen, "   HAVE___STRTOULL\n");
#endif
#ifdef HAVE___SYNC_FETCH_AND_ADD
       output(screen, "   HAVE___SYNC_FETCH_AND_ADD\n");
#endif
#ifdef HAVE___THREAD
       output(screen, "   HAVE___THREAD\n");
#endif


	/* Show --with Options */
       output(screen, "\n--with Options:\n");

#ifdef WITH_AUTOMOUNT
       output(screen, "   WITH_AUTOMOUNT\n");
#endif
#ifdef WITH_PTHREADPOOL
       output(screen, "   WITH_PTHREADPOOL\n");
#endif
#ifdef WITH_QUOTAS
       output(screen, "   WITH_QUOTAS\n");
#endif
#ifdef WITH_SPOTLIGHT
       output(screen, "   WITH_SPOTLIGHT\n");
#endif
#ifdef WITH_SYSLOG
       output(screen, "   WITH_SYSLOG\n");
#endif
#ifdef WITH_WINBIND
       output(screen, "   WITH_WINBIND\n");
#endif


	/* Show Build Options */
       output(screen, "\nBuild Options:\n");

#ifdef ABI_CHECK
       output(screen, "   ABI_CHECK\n");
#endif
#ifdef ABS_TOP_BUILDDIR
       output(screen, "   ABS_TOP_BUILDDIR\n");
#endif
#ifdef ABS_TOP_SRCDIR
       output(screen, "   ABS_TOP_SRCDIR\n");
#endif
#ifdef ALLOW_GNUTLS_AEAD_CIPHER_ENCRYPTV2_AES_GCM
       output(screen, "   ALLOW_GNUTLS_AEAD_CIPHER_ENCRYPTV2_AES_GCM\n");
#endif
#ifdef AR
       output(screen, "   AR\n");
#endif
#ifdef ARFLAGS
       output(screen, "   ARFLAGS\n");
#endif
#ifdef ASN1_COMPILE
       output(screen, "   ASN1_COMPILE\n");
#endif
#ifdef AUTH_SHARED
       output(screen, "   AUTH_SHARED\n");
#endif
#ifdef AUTH_STATIC
       output(screen, "   AUTH_STATIC\n");
#endif
#ifdef AUTOCONF_BUILD
       output(screen, "   AUTOCONF_BUILD\n");
#endif
#ifdef AUTOCONF_HOST
       output(screen, "   AUTOCONF_HOST\n");
#endif
#ifdef AUTOCONF_PROGRAM_PREFIX
       output(screen, "   AUTOCONF_PROGRAM_PREFIX\n");
#endif
#ifdef AWK
       output(screen, "   AWK\n");
#endif
#ifdef BINDDNS_DIR
       output(screen, "   BINDDNS_DIR\n");
#endif
#ifdef BINDIR
       output(screen, "   BINDIR\n");
#endif
#ifdef BISON
       output(screen, "   BISON\n");
#endif
#ifdef BISONFLAGS
       output(screen, "   BISONFLAGS\n");
#endif
#ifdef BOOL_DEFINED
       output(screen, "   BOOL_DEFINED\n");
#endif
#ifdef BROKEN_NISPLUS_INCLUDE_FILES
       output(screen, "   BROKEN_NISPLUS_INCLUDE_FILES\n");
#endif
#ifdef BSD_STYLE_STATVFS
       output(screen, "   BSD_STYLE_STATVFS\n");
#endif
#ifdef BUILD_DIRECTORY
       output(screen, "   BUILD_DIRECTORY\n");
#endif
#ifdef BUILTIN_LIBRARIES
       output(screen, "   BUILTIN_LIBRARIES\n");
#endif
#ifdef BUNDLED_LIBS
       output(screen, "   BUNDLED_LIBS\n");
#endif
#ifdef CACHEDIR
       output(screen, "   CACHEDIR\n");
#endif
#ifdef CC
       output(screen, "   CC\n");
#endif
#ifdef CCLNK_SRC_F
       output(screen, "   CCLNK_SRC_F\n");
#endif
#ifdef CCLNK_TGT_F
       output(screen, "   CCLNK_TGT_F\n");
#endif
#ifdef CC_NAME
       output(screen, "   CC_NAME\n");
#endif
#ifdef CC_SRC_F
       output(screen, "   CC_SRC_F\n");
#endif
#ifdef CC_TGT_F
       output(screen, "   CC_TGT_F\n");
#endif
#ifdef CC_VERSION
       output(screen, "   CC_VERSION\n");
#endif
#ifdef CFLAGS
       output(screen, "   CFLAGS\n");
#endif
#ifdef CFLAGS_CEPHFS
       output(screen, "   CFLAGS_CEPHFS\n");
#endif
#ifdef CFLAGS_MACBUNDLE
       output(screen, "   CFLAGS_MACBUNDLE\n");
#endif
#ifdef CFLAGS_bsd
       output(screen, "   CFLAGS_bsd\n");
#endif
#ifdef CFLAGS_crypt
       output(screen, "   CFLAGS_crypt\n");
#endif
#ifdef CFLAGS_crypto
       output(screen, "   CFLAGS_crypto\n");
#endif
#ifdef CFLAGS_cshlib
       output(screen, "   CFLAGS_cshlib\n");
#endif
#ifdef CFLAGS_dl
       output(screen, "   CFLAGS_dl\n");
#endif
#ifdef CFLAGS_form
       output(screen, "   CFLAGS_form\n");
#endif
#ifdef CFLAGS_menu
       output(screen, "   CFLAGS_menu\n");
#endif
#ifdef CFLAGS_ncurses
       output(screen, "   CFLAGS_ncurses\n");
#endif
#ifdef CFLAGS_nsl
       output(screen, "   CFLAGS_nsl\n");
#endif
#ifdef CFLAGS_pam
       output(screen, "   CFLAGS_pam\n");
#endif
#ifdef CFLAGS_panel
       output(screen, "   CFLAGS_panel\n");
#endif
#ifdef CFLAGS_popt
       output(screen, "   CFLAGS_popt\n");
#endif
#ifdef CFLAGS_pthread
       output(screen, "   CFLAGS_pthread\n");
#endif
#ifdef CFLAGS_resolv
       output(screen, "   CFLAGS_resolv\n");
#endif
#ifdef CFLAGS_util
       output(screen, "   CFLAGS_util\n");
#endif
#ifdef CFLAGS_z
       output(screen, "   CFLAGS_z\n");
#endif
#ifdef CHARSET_SHARED
       output(screen, "   CHARSET_SHARED\n");
#endif
#ifdef CHARSET_STATIC
       output(screen, "   CHARSET_STATIC\n");
#endif
#ifdef CODEPAGEDIR
       output(screen, "   CODEPAGEDIR\n");
#endif
#ifdef COMPILER_CC
       output(screen, "   COMPILER_CC\n");
#endif
#ifdef COMPILER_SUPPORTS_LL
       output(screen, "   COMPILER_SUPPORTS_LL\n");
#endif
#ifdef COMPILE_ET
       output(screen, "   COMPILE_ET\n");
#endif
#ifdef CONFIGDIR
       output(screen, "   CONFIGDIR\n");
#endif
#ifdef CONFIGFILE
       output(screen, "   CONFIGFILE\n");
#endif
#ifdef CONFIG_H_IS_FROM_SAMBA
       output(screen, "   CONFIG_H_IS_FROM_SAMBA\n");
#endif
#ifdef CPPPATH
       output(screen, "   CPPPATH\n");
#endif
#ifdef CPPPATH_GPFS
       output(screen, "   CPPPATH_GPFS\n");
#endif
#ifdef CPPPATH_ST
       output(screen, "   CPPPATH_ST\n");
#endif
#ifdef CROSS_ANSWERS
       output(screen, "   CROSS_ANSWERS\n");
#endif
#ifdef CROSS_COMPILE
       output(screen, "   CROSS_COMPILE\n");
#endif
#ifdef CROSS_EXECUTE
       output(screen, "   CROSS_EXECUTE\n");
#endif
#ifdef DATADIR
       output(screen, "   DATADIR\n");
#endif
#ifdef DATAROOTDIR
       output(screen, "   DATAROOTDIR\n");
#endif
#ifdef DEFAULT_DOS_CHARSET
       output(screen, "   DEFAULT_DOS_CHARSET\n");
#endif
#ifdef DEFAULT_UNIX_CHARSET
       output(screen, "   DEFAULT_UNIX_CHARSET\n");
#endif
#ifdef DEFINES
       output(screen, "   DEFINES\n");
#endif
#ifdef DEFINES_NCURSES
       output(screen, "   DEFINES_NCURSES\n");
#endif
#ifdef DEFINES_ST
       output(screen, "   DEFINES_ST\n");
#endif
#ifdef DEST_BINFMT
       output(screen, "   DEST_BINFMT\n");
#endif
#ifdef DEST_CPU
       output(screen, "   DEST_CPU\n");
#endif
#ifdef DEST_OS
       output(screen, "   DEST_OS\n");
#endif
#ifdef DLOPEN_TAKES_UNSIGNED_FLAGS
       output(screen, "   DLOPEN_TAKES_UNSIGNED_FLAGS\n");
#endif
#ifdef DOCDIR
       output(screen, "   DOCDIR\n");
#endif
#ifdef DOC_VERSION
       output(screen, "   DOC_VERSION\n");
#endif
#ifdef DVIDIR
       output(screen, "   DVIDIR\n");
#endif
#ifdef ENABLE_GCCDEPS
       output(screen, "   ENABLE_GCCDEPS\n");
#endif
#ifdef ENABLE_PIE
       output(screen, "   ENABLE_PIE\n");
#endif
#ifdef ENABLE_RELRO
       output(screen, "   ENABLE_RELRO\n");
#endif
#ifdef EXEC_PREFIX
       output(screen, "   EXEC_PREFIX\n");
#endif
#ifdef EXTRA_CFLAGS
       output(screen, "   EXTRA_CFLAGS\n");
#endif
#ifdef EXTRA_INCLUDES
       output(screen, "   EXTRA_INCLUDES\n");
#endif
#ifdef EXTRA_LDFLAGS
       output(screen, "   EXTRA_LDFLAGS\n");
#endif
#ifdef FLEX
       output(screen, "   FLEX\n");
#endif
#ifdef FLEXFLAGS
       output(screen, "   FLEXFLAGS\n");
#endif
#ifdef FOUND_SYSTEMLIB_cmocka
       output(screen, "   FOUND_SYSTEMLIB_cmocka\n");
#endif
#ifdef FOUND_SYSTEMLIB_ldb
       output(screen, "   FOUND_SYSTEMLIB_ldb\n");
#endif
#ifdef FOUND_SYSTEMLIB_libtasn1
       output(screen, "   FOUND_SYSTEMLIB_libtasn1\n");
#endif
#ifdef FOUND_SYSTEMLIB_popt
       output(screen, "   FOUND_SYSTEMLIB_popt\n");
#endif
#ifdef FOUND_SYSTEMLIB_talloc
       output(screen, "   FOUND_SYSTEMLIB_talloc\n");
#endif
#ifdef FOUND_SYSTEMLIB_tdb
       output(screen, "   FOUND_SYSTEMLIB_tdb\n");
#endif
#ifdef FOUND_SYSTEMLIB_tevent
       output(screen, "   FOUND_SYSTEMLIB_tevent\n");
#endif
#ifdef GDB
       output(screen, "   GDB\n");
#endif
#ifdef GETCWD_TAKES_NULL
       output(screen, "   GETCWD_TAKES_NULL\n");
#endif
#ifdef GIT
       output(screen, "   GIT\n");
#endif
#ifdef GIT_LOCAL_CHANGES
       output(screen, "   GIT_LOCAL_CHANGES\n");
#endif
#ifdef GLOBAL_DEPENDENCIES
       output(screen, "   GLOBAL_DEPENDENCIES\n");
#endif
#ifdef GPEXT_SHARED
       output(screen, "   GPEXT_SHARED\n");
#endif
#ifdef GPEXT_STATIC
       output(screen, "   GPEXT_STATIC\n");
#endif
#ifdef HEIMDAL_NO_ERROR_CFLAGS
       output(screen, "   HEIMDAL_NO_ERROR_CFLAGS\n");
#endif
#ifdef HOSTCC
       output(screen, "   HOSTCC\n");
#endif
#ifdef HTMLDIR
       output(screen, "   HTMLDIR\n");
#endif
#ifdef IDMAP_SHARED
       output(screen, "   IDMAP_SHARED\n");
#endif
#ifdef IDMAP_STATIC
       output(screen, "   IDMAP_STATIC\n");
#endif
#ifdef INCLUDEDIR
       output(screen, "   INCLUDEDIR\n");
#endif
#ifdef INCLUDES_GNUTLS
       output(screen, "   INCLUDES_GNUTLS\n");
#endif
#ifdef INFODIR
       output(screen, "   INFODIR\n");
#endif
#ifdef INIT_FUNCTIONS
       output(screen, "   INIT_FUNCTIONS\n");
#endif
#ifdef INLINE_MACRO
       output(screen, "   INLINE_MACRO\n");
#endif
#ifdef KRB5_CREDS_OPT_FREE_REQUIRES_CONTEXT
       output(screen, "   KRB5_CREDS_OPT_FREE_REQUIRES_CONTEXT\n");
#endif
#ifdef KRB5_PRINC_REALM_RETURNS_REALM
       output(screen, "   KRB5_PRINC_REALM_RETURNS_REALM\n");
#endif
#ifdef LDAP_LIBS
       output(screen, "   LDAP_LIBS\n");
#endif
#ifdef LDB_MODULESDIR
       output(screen, "   LDB_MODULESDIR\n");
#endif
#ifdef LDFLAGS_bsd
       output(screen, "   LDFLAGS_bsd\n");
#endif
#ifdef LDFLAGS_crypt
       output(screen, "   LDFLAGS_crypt\n");
#endif
#ifdef LDFLAGS_crypto
       output(screen, "   LDFLAGS_crypto\n");
#endif
#ifdef LDFLAGS_dl
       output(screen, "   LDFLAGS_dl\n");
#endif
#ifdef LDFLAGS_form
       output(screen, "   LDFLAGS_form\n");
#endif
#ifdef LDFLAGS_menu
       output(screen, "   LDFLAGS_menu\n");
#endif
#ifdef LDFLAGS_ncurses
       output(screen, "   LDFLAGS_ncurses\n");
#endif
#ifdef LDFLAGS_nsl
       output(screen, "   LDFLAGS_nsl\n");
#endif
#ifdef LDFLAGS_pam
       output(screen, "   LDFLAGS_pam\n");
#endif
#ifdef LDFLAGS_panel
       output(screen, "   LDFLAGS_panel\n");
#endif
#ifdef LDFLAGS_popt
       output(screen, "   LDFLAGS_popt\n");
#endif
#ifdef LDFLAGS_pthread
       output(screen, "   LDFLAGS_pthread\n");
#endif
#ifdef LDFLAGS_resolv
       output(screen, "   LDFLAGS_resolv\n");
#endif
#ifdef LDFLAGS_util
       output(screen, "   LDFLAGS_util\n");
#endif
#ifdef LDFLAGS_z
       output(screen, "   LDFLAGS_z\n");
#endif
#ifdef LIBDIR
       output(screen, "   LIBDIR\n");
#endif
#ifdef LIBEXECDIR
       output(screen, "   LIBEXECDIR\n");
#endif
#ifdef LIBPATH
       output(screen, "   LIBPATH\n");
#endif
#ifdef LIBPATH_GNUTLS
       output(screen, "   LIBPATH_GNUTLS\n");
#endif
#ifdef LIBPATH_LIBTASN1
       output(screen, "   LIBPATH_LIBTASN1\n");
#endif
#ifdef LIBPATH_POPT
       output(screen, "   LIBPATH_POPT\n");
#endif
#ifdef LIBPATH_ST
       output(screen, "   LIBPATH_ST\n");
#endif
#ifdef LIBPATH_ZLIB
       output(screen, "   LIBPATH_ZLIB\n");
#endif
#ifdef LIBREPLACE_NETWORK_CHECKS
       output(screen, "   LIBREPLACE_NETWORK_CHECKS\n");
#endif
#ifdef LIB_BSD
       output(screen, "   LIB_BSD\n");
#endif
#ifdef LIB_CRYPT
       output(screen, "   LIB_CRYPT\n");
#endif
#ifdef LIB_CRYPTO
       output(screen, "   LIB_CRYPTO\n");
#endif
#ifdef LIB_DL
       output(screen, "   LIB_DL\n");
#endif
#ifdef LIB_FORM
       output(screen, "   LIB_FORM\n");
#endif
#ifdef LIB_GNUTLS
       output(screen, "   LIB_GNUTLS\n");
#endif
#ifdef LIB_LIBTASN1
       output(screen, "   LIB_LIBTASN1\n");
#endif
#ifdef LIB_MENU
       output(screen, "   LIB_MENU\n");
#endif
#ifdef LIB_NCURSES
       output(screen, "   LIB_NCURSES\n");
#endif
#ifdef LIB_NSL
       output(screen, "   LIB_NSL\n");
#endif
#ifdef LIB_PAM
       output(screen, "   LIB_PAM\n");
#endif
#ifdef LIB_PANEL
       output(screen, "   LIB_PANEL\n");
#endif
#ifdef LIB_POPT
       output(screen, "   LIB_POPT\n");
#endif
#ifdef LIB_PTHREAD
       output(screen, "   LIB_PTHREAD\n");
#endif
#ifdef LIB_RESOLV
       output(screen, "   LIB_RESOLV\n");
#endif
#ifdef LIB_ST
       output(screen, "   LIB_ST\n");
#endif
#ifdef LIB_UTIL
       output(screen, "   LIB_UTIL\n");
#endif
#ifdef LIB_Z
       output(screen, "   LIB_Z\n");
#endif
#ifdef LIB_ZLIB
       output(screen, "   LIB_ZLIB\n");
#endif
#ifdef LIB_bsd
       output(screen, "   LIB_bsd\n");
#endif
#ifdef LIB_crypt
       output(screen, "   LIB_crypt\n");
#endif
#ifdef LIB_crypto
       output(screen, "   LIB_crypto\n");
#endif
#ifdef LIB_dl
       output(screen, "   LIB_dl\n");
#endif
#ifdef LIB_form
       output(screen, "   LIB_form\n");
#endif
#ifdef LIB_menu
       output(screen, "   LIB_menu\n");
#endif
#ifdef LIB_ncurses
       output(screen, "   LIB_ncurses\n");
#endif
#ifdef LIB_nsl
       output(screen, "   LIB_nsl\n");
#endif
#ifdef LIB_pam
       output(screen, "   LIB_pam\n");
#endif
#ifdef LIB_panel
       output(screen, "   LIB_panel\n");
#endif
#ifdef LIB_popt
       output(screen, "   LIB_popt\n");
#endif
#ifdef LIB_pthread
       output(screen, "   LIB_pthread\n");
#endif
#ifdef LIB_resolv
       output(screen, "   LIB_resolv\n");
#endif
#ifdef LIB_util
       output(screen, "   LIB_util\n");
#endif
#ifdef LIB_z
       output(screen, "   LIB_z\n");
#endif
#ifdef LINKFLAGS
       output(screen, "   LINKFLAGS\n");
#endif
#ifdef LINKFLAGS_MACBUNDLE
       output(screen, "   LINKFLAGS_MACBUNDLE\n");
#endif
#ifdef LINKFLAGS_NCURSES
       output(screen, "   LINKFLAGS_NCURSES\n");
#endif
#ifdef LINKFLAGS_cshlib
       output(screen, "   LINKFLAGS_cshlib\n");
#endif
#ifdef LINKFLAGS_cstlib
       output(screen, "   LINKFLAGS_cstlib\n");
#endif
#ifdef LINK_CC
       output(screen, "   LINK_CC\n");
#endif
#ifdef LINUX
       output(screen, "   LINUX\n");
#endif
#ifdef LINUX_SENDFILE_API
       output(screen, "   LINUX_SENDFILE_API\n");
#endif
#ifdef LMHOSTSFILE
       output(screen, "   LMHOSTSFILE\n");
#endif
#ifdef LOCALEDIR
       output(screen, "   LOCALEDIR\n");
#endif
#ifdef LOCALSTATEDIR
       output(screen, "   LOCALSTATEDIR\n");
#endif
#ifdef LOCKDIR
       output(screen, "   LOCKDIR\n");
#endif
#ifdef LOGFILEBASE
       output(screen, "   LOGFILEBASE\n");
#endif
#ifdef MANDIR
       output(screen, "   MANDIR\n");
#endif
#ifdef MODULESDIR
       output(screen, "   MODULESDIR\n");
#endif
#ifdef MODULE_PREFIXES
       output(screen, "   MODULE_PREFIXES\n");
#endif
#ifdef NCALRPCDIR
       output(screen, "   NCALRPCDIR\n");
#endif
#ifdef NCURSES_CONFIG
       output(screen, "   NCURSES_CONFIG\n");
#endif
#ifdef NMBDSOCKETDIR
       output(screen, "   NMBDSOCKETDIR\n");
#endif
#ifdef NONSHARED_BINARIES
       output(screen, "   NONSHARED_BINARIES\n");
#endif
#ifdef NSS_INFO_SHARED
       output(screen, "   NSS_INFO_SHARED\n");
#endif
#ifdef NSS_INFO_STATIC
       output(screen, "   NSS_INFO_STATIC\n");
#endif
#ifdef NTP_SIGND_SOCKET_DIR
       output(screen, "   NTP_SIGND_SOCKET_DIR\n");
#endif
#ifdef OLDINCLUDEDIR
       output(screen, "   OLDINCLUDEDIR\n");
#endif
#ifdef PACKAGE
       output(screen, "   PACKAGE\n");
#endif
#ifdef PAMMODULESDIR
       output(screen, "   PAMMODULESDIR\n");
#endif
#ifdef PDB_SHARED
       output(screen, "   PDB_SHARED\n");
#endif
#ifdef PDB_STATIC
       output(screen, "   PDB_STATIC\n");
#endif
#ifdef PDFDIR
       output(screen, "   PDFDIR\n");
#endif
#ifdef PERFCOUNT_SHARED
       output(screen, "   PERFCOUNT_SHARED\n");
#endif
#ifdef PERFCOUNT_STATIC
       output(screen, "   PERFCOUNT_STATIC\n");
#endif
#ifdef PERL
       output(screen, "   PERL\n");
#endif
#ifdef PERL_ARCH_INSTALL_DIR
       output(screen, "   PERL_ARCH_INSTALL_DIR\n");
#endif
#ifdef PERL_INC
       output(screen, "   PERL_INC\n");
#endif
#ifdef PERL_LIB_INSTALL_DIR
       output(screen, "   PERL_LIB_INSTALL_DIR\n");
#endif
#ifdef PERL_SPECIFIED
       output(screen, "   PERL_SPECIFIED\n");
#endif
#ifdef PIDDIR
       output(screen, "   PIDDIR\n");
#endif
#ifdef PIDL_HEADERS
       output(screen, "   PIDL_HEADERS\n");
#endif
#ifdef PKGCONFIG
       output(screen, "   PKGCONFIG\n");
#endif
#ifdef PKGCONFIGDIR
       output(screen, "   PKGCONFIGDIR\n");
#endif
#ifdef PREFIX
       output(screen, "   PREFIX\n");
#endif
#ifdef PRIVATELIBDIR
       output(screen, "   PRIVATELIBDIR\n");
#endif
#ifdef PRIVATE_DIR
       output(screen, "   PRIVATE_DIR\n");
#endif
#ifdef PRIVATE_EXTENSION
       output(screen, "   PRIVATE_EXTENSION\n");
#endif
#ifdef PRIVATE_EXTENSION_EXCEPTION
       output(screen, "   PRIVATE_EXTENSION_EXCEPTION\n");
#endif
#ifdef PRIVATE_LIBS
       output(screen, "   PRIVATE_LIBS\n");
#endif
#ifdef PRIVILEGED_SOCKET_DIR
       output(screen, "   PRIVILEGED_SOCKET_DIR\n");
#endif
#ifdef PSDIR
       output(screen, "   PSDIR\n");
#endif
#ifdef PYC
       output(screen, "   PYC\n");
#endif
#ifdef PYFLAGS
       output(screen, "   PYFLAGS\n");
#endif
#ifdef PYFLAGS_OPT
       output(screen, "   PYFLAGS_OPT\n");
#endif
#ifdef PYO
       output(screen, "   PYO\n");
#endif
#ifdef PYTAG
       output(screen, "   PYTAG\n");
#endif
#ifdef PYTHON
       output(screen, "   PYTHON\n");
#endif
#ifdef PYTHON3
       output(screen, "   PYTHON3\n");
#endif
#ifdef PYTHONARCHDIR
       output(screen, "   PYTHONARCHDIR\n");
#endif
#ifdef PYTHONDIR
       output(screen, "   PYTHONDIR\n");
#endif
#ifdef PYTHON_SPECIFIED
       output(screen, "   PYTHON_SPECIFIED\n");
#endif
#ifdef PYTHON_VERSION
       output(screen, "   PYTHON_VERSION\n");
#endif
#ifdef READLINE_TERMLIB
       output(screen, "   READLINE_TERMLIB\n");
#endif
#ifdef REALPATH_TAKES_NULL
       output(screen, "   REALPATH_TAKES_NULL\n");
#endif
#ifdef REQUIRE_LMDB
       output(screen, "   REQUIRE_LMDB\n");
#endif
#ifdef RETSIGTYPE
       output(screen, "   RETSIGTYPE\n");
#endif
#ifdef RETSIGTYPE_INT
       output(screen, "   RETSIGTYPE_INT\n");
#endif
#ifdef RPATH_ON_BUILD
       output(screen, "   RPATH_ON_BUILD\n");
#endif
#ifdef RPATH_ON_INSTALL
       output(screen, "   RPATH_ON_INSTALL\n");
#endif
#ifdef RPATH_ON_INSTALL_PRIVATE
       output(screen, "   RPATH_ON_INSTALL_PRIVATE\n");
#endif
#ifdef RPATH_ST
       output(screen, "   RPATH_ST\n");
#endif
#ifdef RPC_SHARED
       output(screen, "   RPC_SHARED\n");
#endif
#ifdef RPC_STATIC
       output(screen, "   RPC_STATIC\n");
#endif
#ifdef SAMBA4_USES_HEIMDAL
       output(screen, "   SAMBA4_USES_HEIMDAL\n");
#endif
#ifdef SAMBA_DATADIR
       output(screen, "   SAMBA_DATADIR\n");
#endif
#ifdef SAMBA_GENERATOR_VARS
       output(screen, "   SAMBA_GENERATOR_VARS\n");
#endif
#ifdef SAMBA_LIBEXECDIR
       output(screen, "   SAMBA_LIBEXECDIR\n");
#endif
#ifdef SBINDIR
       output(screen, "   SBINDIR\n");
#endif
#ifdef SCRIPTSBINDIR
       output(screen, "   SCRIPTSBINDIR\n");
#endif
#ifdef SEEKDIR_RETURNS_VOID
       output(screen, "   SEEKDIR_RETURNS_VOID\n");
#endif
#ifdef SELFTEST_PREFIX
       output(screen, "   SELFTEST_PREFIX\n");
#endif
#ifdef SETUPDIR
       output(screen, "   SETUPDIR\n");
#endif
#ifdef SHAREDSTATEDIR
       output(screen, "   SHAREDSTATEDIR\n");
#endif
#ifdef SHLIBEXT
       output(screen, "   SHLIBEXT\n");
#endif
#ifdef SHLIB_MARKER
       output(screen, "   SHLIB_MARKER\n");
#endif
#ifdef SIZEOF_BLKCNT_T_4
       output(screen, "   SIZEOF_BLKCNT_T_4\n");
#endif
#ifdef SIZEOF_BLKCNT_T_8
       output(screen, "   SIZEOF_BLKCNT_T_8\n");
#endif
#ifdef SIZEOF_BOOL
       output(screen, "   SIZEOF_BOOL\n");
#endif
#ifdef SIZEOF_CHAR
       output(screen, "   SIZEOF_CHAR\n");
#endif
#ifdef SIZEOF_DEV_T
       output(screen, "   SIZEOF_DEV_T\n");
#endif
#ifdef SIZEOF_INO_T
       output(screen, "   SIZEOF_INO_T\n");
#endif
#ifdef SIZEOF_INT
       output(screen, "   SIZEOF_INT\n");
#endif
#ifdef SIZEOF_INT16_T
       output(screen, "   SIZEOF_INT16_T\n");
#endif
#ifdef SIZEOF_INT32_T
       output(screen, "   SIZEOF_INT32_T\n");
#endif
#ifdef SIZEOF_INT64_T
       output(screen, "   SIZEOF_INT64_T\n");
#endif
#ifdef SIZEOF_INT8_T
       output(screen, "   SIZEOF_INT8_T\n");
#endif
#ifdef SIZEOF_LONG
       output(screen, "   SIZEOF_LONG\n");
#endif
#ifdef SIZEOF_LONG_LONG
       output(screen, "   SIZEOF_LONG_LONG\n");
#endif
#ifdef SIZEOF_OFF_T
       output(screen, "   SIZEOF_OFF_T\n");
#endif
#ifdef SIZEOF_SHORT
       output(screen, "   SIZEOF_SHORT\n");
#endif
#ifdef SIZEOF_SIZE_T
       output(screen, "   SIZEOF_SIZE_T\n");
#endif
#ifdef SIZEOF_SSIZE_T
       output(screen, "   SIZEOF_SSIZE_T\n");
#endif
#ifdef SIZEOF_TIME_T
       output(screen, "   SIZEOF_TIME_T\n");
#endif
#ifdef SIZEOF_UINT16_T
       output(screen, "   SIZEOF_UINT16_T\n");
#endif
#ifdef SIZEOF_UINT32_T
       output(screen, "   SIZEOF_UINT32_T\n");
#endif
#ifdef SIZEOF_UINT64_T
       output(screen, "   SIZEOF_UINT64_T\n");
#endif
#ifdef SIZEOF_UINT8_T
       output(screen, "   SIZEOF_UINT8_T\n");
#endif
#ifdef SIZEOF_VOID_P
       output(screen, "   SIZEOF_VOID_P\n");
#endif
#ifdef SMB_PASSWD_FILE
       output(screen, "   SMB_PASSWD_FILE\n");
#endif
#ifdef SOCKET_DIR
       output(screen, "   SOCKET_DIR\n");
#endif
#ifdef SOLARIS_GETGRENT_R
       output(screen, "   SOLARIS_GETGRENT_R\n");
#endif
#ifdef SOLARIS_GETPWENT_R
       output(screen, "   SOLARIS_GETPWENT_R\n");
#endif
#ifdef SONAME_ST
       output(screen, "   SONAME_ST\n");
#endif
#ifdef SRCDIR
       output(screen, "   SRCDIR\n");
#endif
#ifdef STANDARD_LIBPATH
       output(screen, "   STANDARD_LIBPATH\n");
#endif
#ifdef STATEDIR
       output(screen, "   STATEDIR\n");
#endif
#ifdef STAT_STATVFS
       output(screen, "   STAT_STATVFS\n");
#endif
#ifdef STAT_ST_BLOCKSIZE
       output(screen, "   STAT_ST_BLOCKSIZE\n");
#endif
#ifdef STDC_HEADERS
       output(screen, "   STDC_HEADERS\n");
#endif
#ifdef STLIBPATH_ST
       output(screen, "   STLIBPATH_ST\n");
#endif
#ifdef STLIB_MARKER
       output(screen, "   STLIB_MARKER\n");
#endif
#ifdef STLIB_ST
       output(screen, "   STLIB_ST\n");
#endif
#ifdef STRERROR_R_XSI_NOT_GNU
       output(screen, "   STRERROR_R_XSI_NOT_GNU\n");
#endif
#ifdef STRING_SHARED_MODULES
       output(screen, "   STRING_SHARED_MODULES\n");
#endif
#ifdef STRING_STATIC_MODULES
       output(screen, "   STRING_STATIC_MODULES\n");
#endif
#ifdef SUMMARY_PASSES
       output(screen, "   SUMMARY_PASSES\n");
#endif
#ifdef SYSCONFDIR
       output(screen, "   SYSCONFDIR\n");
#endif
#ifdef SYSCONF_SC_NGROUPS_MAX
       output(screen, "   SYSCONF_SC_NGROUPS_MAX\n");
#endif
#ifdef SYSCONF_SC_NPROCESSORS_ONLN
       output(screen, "   SYSCONF_SC_NPROCESSORS_ONLN\n");
#endif
#ifdef SYSCONF_SC_NPROC_ONLN
       output(screen, "   SYSCONF_SC_NPROC_ONLN\n");
#endif
#ifdef SYSCONF_SC_PAGESIZE
       output(screen, "   SYSCONF_SC_PAGESIZE\n");
#endif
#ifdef SYSLIB_DEPS
       output(screen, "   SYSLIB_DEPS\n");
#endif
#ifdef SYSTEMDDIR
       output(screen, "   SYSTEMDDIR\n");
#endif
#ifdef SYSTEM_LIBS
       output(screen, "   SYSTEM_LIBS\n");
#endif
#ifdef SYSTEM_UNAME_MACHINE
       output(screen, "   SYSTEM_UNAME_MACHINE\n");
#endif
#ifdef SYSTEM_UNAME_RELEASE
       output(screen, "   SYSTEM_UNAME_RELEASE\n");
#endif
#ifdef SYSTEM_UNAME_SYSNAME
       output(screen, "   SYSTEM_UNAME_SYSNAME\n");
#endif
#ifdef SYSTEM_UNAME_VERSION
       output(screen, "   SYSTEM_UNAME_VERSION\n");
#endif
#ifdef TALLOC_BUILD_VERSION_MAJOR
       output(screen, "   TALLOC_BUILD_VERSION_MAJOR\n");
#endif
#ifdef TALLOC_BUILD_VERSION_MINOR
       output(screen, "   TALLOC_BUILD_VERSION_MINOR\n");
#endif
#ifdef TALLOC_BUILD_VERSION_RELEASE
       output(screen, "   TALLOC_BUILD_VERSION_RELEASE\n");
#endif
#ifdef TALLOC_COMPAT1
       output(screen, "   TALLOC_COMPAT1\n");
#endif
#ifdef TARGET_TYPE
       output(screen, "   TARGET_TYPE\n");
#endif
#ifdef TEVENT_NUM_SIGNALS
       output(screen, "   TEVENT_NUM_SIGNALS\n");
#endif
#ifdef TIME_T_MAX
       output(screen, "   TIME_T_MAX\n");
#endif
#ifdef TIME_WITH_SYS_TIME
       output(screen, "   TIME_WITH_SYS_TIME\n");
#endif
#ifdef USE_LINUX_32BIT_SYSCALLS
       output(screen, "   USE_LINUX_32BIT_SYSCALLS\n");
#endif
#ifdef USE_TDB_MUTEX_LOCKING
       output(screen, "   USE_TDB_MUTEX_LOCKING\n");
#endif
#ifdef USING_BUILD_GROUPS
       output(screen, "   USING_BUILD_GROUPS\n");
#endif
#ifdef USING_EMBEDDED_HEIMDAL
       output(screen, "   USING_EMBEDDED_HEIMDAL\n");
#endif
#ifdef USING_SYSTEM_POPT
       output(screen, "   USING_SYSTEM_POPT\n");
#endif
#ifdef VALUEOF_GNUTLS_CIPHER_AES_128_CFB8
       output(screen, "   VALUEOF_GNUTLS_CIPHER_AES_128_CFB8\n");
#endif
#ifdef VALUEOF_GNUTLS_MAC_AES_CMAC_128
       output(screen, "   VALUEOF_GNUTLS_MAC_AES_CMAC_128\n");
#endif
#ifdef VALUEOF_NSIG
       output(screen, "   VALUEOF_NSIG\n");
#endif
#ifdef VALUEOF_SIGRTMAX
       output(screen, "   VALUEOF_SIGRTMAX\n");
#endif
#ifdef VALUEOF_SIGRTMIN
       output(screen, "   VALUEOF_SIGRTMIN\n");
#endif
#ifdef VALUEOF__NSIG
       output(screen, "   VALUEOF__NSIG\n");
#endif
#ifdef VFS_SHARED
       output(screen, "   VFS_SHARED\n");
#endif
#ifdef VFS_STATIC
       output(screen, "   VFS_STATIC\n");
#endif
#ifdef VISIBILITY_CFLAGS
       output(screen, "   VISIBILITY_CFLAGS\n");
#endif
#ifdef VOID_RETSIGTYPE
       output(screen, "   VOID_RETSIGTYPE\n");
#endif
#ifdef WERROR_CFLAGS
       output(screen, "   WERROR_CFLAGS\n");
#endif
#ifdef WINBINDD_SOCKET_DIR
       output(screen, "   WINBINDD_SOCKET_DIR\n");
#endif
#ifdef WINEXE_LDFLAGS
       output(screen, "   WINEXE_LDFLAGS\n");
#endif
#ifdef XATTR_ADDITIONAL_OPTIONS
       output(screen, "   XATTR_ADDITIONAL_OPTIONS\n");
#endif
#ifdef YAPP
       output(screen, "   YAPP\n");
#endif
#ifdef _GNU_SOURCE
       output(screen, "   _GNU_SOURCE\n");
#endif
#ifdef _HAVE_SENDFILE
       output(screen, "   _HAVE_SENDFILE\n");
#endif
#ifdef _POSIX_FALLOCATE_CAPABLE_LIBC
       output(screen, "   _POSIX_FALLOCATE_CAPABLE_LIBC\n");
#endif
#ifdef _SAMBA_BUILD_
       output(screen, "   _SAMBA_BUILD_\n");
#endif
#ifdef _XOPEN_SOURCE_EXTENDED
       output(screen, "   _XOPEN_SOURCE_EXTENDED\n");
#endif
#ifdef __TIME_T_MAX
       output(screen, "   __TIME_T_MAX\n");
#endif
#ifdef added_project_rules
       output(screen, "   added_project_rules\n");
#endif
#ifdef build_mvxattr
       output(screen, "   build_mvxattr\n");
#endif
#ifdef build_public_headers
       output(screen, "   build_public_headers\n");
#endif
#ifdef build_regedit
       output(screen, "   build_regedit\n");
#endif
#ifdef build_winbind
       output(screen, "   build_winbind\n");
#endif
#ifdef build_winexe
       output(screen, "   build_winexe\n");
#endif
#ifdef building_tdb
       output(screen, "   building_tdb\n");
#endif
#ifdef cfg_files
       output(screen, "   cfg_files\n");
#endif
#ifdef cprogram_PATTERN
       output(screen, "   cprogram_PATTERN\n");
#endif
#ifdef cshlib_PATTERN
       output(screen, "   cshlib_PATTERN\n");
#endif
#ifdef cstlib_PATTERN
       output(screen, "   cstlib_PATTERN\n");
#endif
#ifdef define_key
       output(screen, "   define_key\n");
#endif
#ifdef disable_python
       output(screen, "   disable_python\n");
#endif
#ifdef disable_tdb_mutex_locking
       output(screen, "   disable_tdb_mutex_locking\n");
#endif
#ifdef dmapi_lib
       output(screen, "   dmapi_lib\n");
#endif
#ifdef enable_afl_fuzzer
       output(screen, "   enable_afl_fuzzer\n");
#endif
#ifdef enable_clangdb
       output(screen, "   enable_clangdb\n");
#endif
#ifdef enable_coverage
       output(screen, "   enable_coverage\n");
#endif
#ifdef enable_fuzzing
       output(screen, "   enable_fuzzing\n");
#endif
#ifdef enable_libfuzzer
       output(screen, "   enable_libfuzzer\n");
#endif
#ifdef hlist
       output(screen, "   hlist\n");
#endif
#ifdef icu_libs
       output(screen, "   icu_libs\n");
#endif
#ifdef idmap_autorid_init
       output(screen, "   idmap_autorid_init\n");
#endif
#ifdef idmap_hash_init
       output(screen, "   idmap_hash_init\n");
#endif
#ifdef idmap_rid_init
       output(screen, "   idmap_rid_init\n");
#endif
#ifdef in_compound
       output(screen, "   in_compound\n");
#endif
#ifdef intl_libs
       output(screen, "   intl_libs\n");
#endif
#ifdef legacy_quota_libs
       output(screen, "   legacy_quota_libs\n");
#endif
#ifdef libtracker
       output(screen, "   libtracker\n");
#endif
#ifdef macbundle_PATTERN
       output(screen, "   macbundle_PATTERN\n");
#endif
#ifdef merge_config_header
       output(screen, "   merge_config_header\n");
#endif
#ifdef offset_t
       output(screen, "   offset_t\n");
#endif
#ifdef public_headers_list
       output(screen, "   public_headers_list\n");
#endif
#ifdef public_headers_skip
       output(screen, "   public_headers_skip\n");
#endif
#ifdef python_interpreters
       output(screen, "   python_interpreters\n");
#endif
#ifdef replace_add_global_pthread
       output(screen, "   replace_add_global_pthread\n");
#endif
#ifdef shared_modules
       output(screen, "   shared_modules\n");
#endif
#ifdef srcdir
       output(screen, "   srcdir\n");
#endif
#ifdef standalone_ldb
       output(screen, "   standalone_ldb\n");
#endif
#ifdef standalone_replace
       output(screen, "   standalone_replace\n");
#endif
#ifdef standalone_talloc
       output(screen, "   standalone_talloc\n");
#endif
#ifdef standalone_tdb
       output(screen, "   standalone_tdb\n");
#endif
#ifdef standalone_tevent
       output(screen, "   standalone_tevent\n");
#endif
#ifdef static_decl_auth
       output(screen, "   static_decl_auth\n");
#endif
#ifdef static_decl_charset
       output(screen, "   static_decl_charset\n");
#endif
#ifdef static_decl_gpext
       output(screen, "   static_decl_gpext\n");
#endif
#ifdef static_decl_idmap
       output(screen, "   static_decl_idmap\n");
#endif
#ifdef static_decl_nss_info
       output(screen, "   static_decl_nss_info\n");
#endif
#ifdef static_decl_pdb
       output(screen, "   static_decl_pdb\n");
#endif
#ifdef static_decl_perfcount
       output(screen, "   static_decl_perfcount\n");
#endif
#ifdef static_decl_rpc
       output(screen, "   static_decl_rpc\n");
#endif
#ifdef static_decl_vfs
       output(screen, "   static_decl_vfs\n");
#endif
#ifdef static_init_auth
       output(screen, "   static_init_auth\n");
#endif
#ifdef static_init_charset
       output(screen, "   static_init_charset\n");
#endif
#ifdef static_init_gpext
       output(screen, "   static_init_gpext\n");
#endif
#ifdef static_init_idmap
       output(screen, "   static_init_idmap\n");
#endif
#ifdef static_init_nss_info
       output(screen, "   static_init_nss_info\n");
#endif
#ifdef static_init_pdb
       output(screen, "   static_init_pdb\n");
#endif
#ifdef static_init_perfcount
       output(screen, "   static_init_perfcount\n");
#endif
#ifdef static_init_rpc
       output(screen, "   static_init_rpc\n");
#endif
#ifdef static_init_vfs
       output(screen, "   static_init_vfs\n");
#endif
#ifdef static_modules
       output(screen, "   static_modules\n");
#endif
#ifdef suffix3
       output(screen, "   suffix3\n");
#endif
#ifdef suffix4
       output(screen, "   suffix4\n");
#endif
#ifdef systemd_install_services
       output(screen, "   systemd_install_services\n");
#endif
#ifdef systemd_nmb_extra
       output(screen, "   systemd_nmb_extra\n");
#endif
#ifdef systemd_samba_extra
       output(screen, "   systemd_samba_extra\n");
#endif
#ifdef systemd_smb_extra
       output(screen, "   systemd_smb_extra\n");
#endif
#ifdef systemd_winbind_extra
       output(screen, "   systemd_winbind_extra\n");
#endif
#ifdef uint_t
       output(screen, "   uint_t\n");
#endif
#ifdef undefined_ldflags
       output(screen, "   undefined_ldflags\n");
#endif
#ifdef with_avahi
       output(screen, "   with_avahi\n");
#endif
#ifdef with_ctdb
       output(screen, "   with_ctdb\n");
#endif
#ifdef with_iconv
       output(screen, "   with_iconv\n");
#endif
#ifdef with_spotlight
       output(screen, "   with_spotlight\n");
#endif
#ifdef with_utmp
       output(screen, "   with_utmp\n");
#endif

       /* Output the sizes of the various cluster features */
       output(screen, "\n%s", cluster_support_features());

       /* Output the sizes of the various types */
       output(screen, "\nType sizes:\n");
       output(screen, "   sizeof(char):         %lu\n",(unsigned long)sizeof(char));
       output(screen, "   sizeof(int):          %lu\n",(unsigned long)sizeof(int));
       output(screen, "   sizeof(long):         %lu\n",(unsigned long)sizeof(long));
       output(screen, "   sizeof(long long):    %lu\n",(unsigned long)sizeof(long long));
       output(screen, "   sizeof(uint8_t):      %lu\n",(unsigned long)sizeof(uint8_t));
       output(screen, "   sizeof(uint16_t):     %lu\n",(unsigned long)sizeof(uint16_t));
       output(screen, "   sizeof(uint32_t):     %lu\n",(unsigned long)sizeof(uint32_t));
       output(screen, "   sizeof(short):        %lu\n",(unsigned long)sizeof(short));
       output(screen, "   sizeof(void*):        %lu\n",(unsigned long)sizeof(void*));
       output(screen, "   sizeof(size_t):       %lu\n",(unsigned long)sizeof(size_t));
       output(screen, "   sizeof(off_t):        %lu\n",(unsigned long)sizeof(off_t));
       output(screen, "   sizeof(ino_t):        %lu\n",(unsigned long)sizeof(ino_t));
       output(screen, "   sizeof(dev_t):        %lu\n",(unsigned long)sizeof(dev_t));

       output(screen, "\nBuiltin modules:\n");
       output(screen, "   %s\n", STRING_STATIC_MODULES);
}
