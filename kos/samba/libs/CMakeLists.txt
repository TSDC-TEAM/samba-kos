set (DEF_DEPENDS
     replace
     talloc
     time-basic
     socket-blocking
     iov-buf
     samba-debug
     tevent
     genrand
     sys-rw
     util-setid
     roken
     samba-util
     samba-errors
     com-err
     ndr
     asn1
     tdb
     samba-security
     hcrypto
     wind
     ndr-nbt
     heimbase
     hx509
     tevent-util
     util-tdb
     tdb-wrap
     server-role
     ndr-standard
     krb5
     asn1util
     samba-hostconfig
     dbwrap
     gssapi
     msghdr
     interfaces
     events
     ndr-samba
     ldb
     krb5samba
     messages-dgm
     server-id-db
     messages-util
     cluster
     samba-sockets
     MESSAGING-SEND
     cli-ldap-common
     cliauth
     flag-mapping
     common-auth
     samdb-common
     ldbsamba
     authkrb5
     samba-credentials
     winbind-client
     wbclient
     samdb
     samba-modules
     samba3-util
     clidns
     gensec
     talloc-report-printf
     util-reg
     samba-cluster-support
     smbd-shim
     CHARSET3
     netif
     cli-nbt
     addns
     smbconf
     cli-ldap
     cli-cldap
     smb-transport
     secrets3
     cli-smb-common
     dcerpc-binding
     gse
     dcerpc-samba
     libsmb
     ndr-samba4
     msrpc3
     ndr-krb5pac
     gnutls
     smbd-base
     xattr-tdb
     printing-migrate
     npa-tstream
     netapi
     dcerpc-server-core
     cli-spoolss
     auth
     MESSAGING
     net-keytab
     ads
     dcerpc
     libcli-lsa3
     trusts-util
     http
     smbclient-raw
     dcerpc-pkt-auth
     libcli-netlogon3
     samba-passdb
     bsd
     popt
     samba-client
     kos-thread)

add_library (smblib STATIC)
foreach (subdir ${DEF_DEPENDS})
    add_subdirectory (${subdir})
    target_sources (smblib PRIVATE $<TARGET_OBJECTS:${subdir}_obj>)
endforeach ()

target_link_libraries (smblib pthread ssl crypto z)

install_header_files (smblib "${SMB_SRC_ROOT}/source3/client/kos_client.h")

set (EXPORT_TARGETS ${EXPORT_TARGETS} smblib PARENT_SCOPE)
