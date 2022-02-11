add_subdirectory(replace)
add_subdirectory(talloc)
add_subdirectory(time-basic)
add_subdirectory(socket-blocking)
add_subdirectory(iov-buf)
add_subdirectory(samba-debug)
add_subdirectory(tevent)
add_subdirectory(genrand)
add_subdirectory(sys-rw)
add_subdirectory(util-setid)
add_subdirectory(roken)
add_subdirectory(samba-util)
add_subdirectory(samba-errors)
add_subdirectory(com-err)
add_subdirectory(ndr)
add_subdirectory(asn1)
add_subdirectory(tdb)
add_subdirectory(samba-security)
add_subdirectory(hcrypto)
add_subdirectory(wind)
add_subdirectory(ndr-nbt)
add_subdirectory(heimbase)
add_subdirectory(hx509)
add_subdirectory(tevent-util)
add_subdirectory(util-tdb)
add_subdirectory(tdb-wrap)
add_subdirectory(server-role)
add_subdirectory(ndr-standard)
add_subdirectory(krb5)
add_subdirectory(asn1util)
add_subdirectory(samba-hostconfig)
add_subdirectory(dbwrap)
add_subdirectory(gssapi)
add_subdirectory(msghdr)
add_subdirectory(interfaces)
add_subdirectory(events)
add_subdirectory(ndr-samba)
add_subdirectory(ldb)
add_subdirectory(krb5samba)
add_subdirectory(messages-dgm)
add_subdirectory(server-id-db)
add_subdirectory(messages-util)
add_subdirectory(cluster)
add_subdirectory(samba-sockets)
add_subdirectory(MESSAGING-SEND)
add_subdirectory(cli-ldap-common)
add_subdirectory(cliauth)
add_subdirectory(flag-mapping)
add_subdirectory(common-auth)
add_subdirectory(samdb-common)
add_subdirectory(ldbsamba)
add_subdirectory(authkrb5)
add_subdirectory(samba-credentials)
add_subdirectory(winbind-client)
add_subdirectory(wbclient)
add_subdirectory(samdb)
add_subdirectory(samba-modules)
add_subdirectory(samba3-util)
add_subdirectory(clidns)
add_subdirectory(gensec)
add_subdirectory(talloc-report-printf)
add_subdirectory(util-reg)
add_subdirectory(samba-cluster-support)
add_subdirectory(smbd-shim)
add_subdirectory(CHARSET3)
add_subdirectory(netif)
add_subdirectory(cli-nbt)
add_subdirectory(addns)
add_subdirectory(smbconf)
add_subdirectory(cli-ldap)
add_subdirectory(cli-cldap)
add_subdirectory(smb-transport)
add_subdirectory(secrets3)
add_subdirectory(cli-smb-common)
add_subdirectory(dcerpc-binding)
add_subdirectory(gse)
add_subdirectory(dcerpc-samba)
add_subdirectory(libsmb)
add_subdirectory(ndr-samba4)
add_subdirectory(msrpc3)
add_subdirectory(ndr-krb5pac)

add_subdirectory(gnutls)
add_subdirectory(resolv)

add_subdirectory(smbd-base)
add_subdirectory(xattr-tdb)
add_subdirectory(printing-migrate)
add_subdirectory(npa-tstream)
add_subdirectory(netapi)
add_subdirectory(dcerpc-server-core)
add_subdirectory(cli-spoolss)
add_subdirectory(auth)
add_subdirectory(MESSAGING)
add_subdirectory(net-keytab)
add_subdirectory(ads)
add_subdirectory(dcerpc)
add_subdirectory(libcli-lsa3)
add_subdirectory(trusts-util)
add_subdirectory(http)
add_subdirectory(smbclient-raw)
add_subdirectory(dcerpc-pkt-auth)
add_subdirectory(libcli-netlogon3)
add_subdirectory(samba-passdb)

add_subdirectory(bsd)

set(C_LIB ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/libcombi.a)

add_custom_target(combined
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/replace
        COMMAND ar -x $<TARGET_FILE:replace> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/replace
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/talloc
        COMMAND ar -x $<TARGET_FILE:talloc> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/talloc
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/time-basic
        COMMAND ar -x $<TARGET_FILE:time-basic> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/time-basic
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/socket-blocking
        COMMAND ar -x $<TARGET_FILE:socket-blocking> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/socket-blocking
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/iov-buf
        COMMAND ar -x $<TARGET_FILE:iov-buf> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/iov-buf
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-debug
        COMMAND ar -x $<TARGET_FILE:samba-debug> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-debug
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/tevent
        COMMAND ar -x $<TARGET_FILE:tevent> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/tevent
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/genrand
        COMMAND ar -x $<TARGET_FILE:genrand> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/genrand
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/sys-rw
        COMMAND ar -x $<TARGET_FILE:sys-rw> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/sys-rw
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/util-setid
        COMMAND ar -x $<TARGET_FILE:util-setid> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/util-setid
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/roken
        COMMAND ar -x $<TARGET_FILE:roken> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/roken
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-util
        COMMAND ar -x $<TARGET_FILE:samba-util> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-util
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-errors
        COMMAND ar -x $<TARGET_FILE:samba-errors> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-errors
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/com-err
        COMMAND ar -x $<TARGET_FILE:com-err> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/com-err
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/ndr
        COMMAND ar -x $<TARGET_FILE:ndr> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/ndr
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/asn1
        COMMAND ar -x $<TARGET_FILE:asn1> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/asn1
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/tdb
        COMMAND ar -x $<TARGET_FILE:tdb> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/tdb
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-security
        COMMAND ar -x $<TARGET_FILE:samba-security> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-security
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/hcrypto
        COMMAND ar -x $<TARGET_FILE:hcrypto> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/hcrypto
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/wind
        COMMAND ar -x $<TARGET_FILE:wind> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/wind
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/ndr-nbt
        COMMAND ar -x $<TARGET_FILE:ndr-nbt> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/ndr-nbt
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/heimbase
        COMMAND ar -x $<TARGET_FILE:heimbase> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/heimbase
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/hx509
        COMMAND ar -x $<TARGET_FILE:hx509> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/hx509
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/tevent-util
        COMMAND ar -x $<TARGET_FILE:tevent-util> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/tevent-util
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/util-tdb
        COMMAND ar -x $<TARGET_FILE:util-tdb> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/util-tdb
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/tdb-wrap
        COMMAND ar -x $<TARGET_FILE:tdb-wrap> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/tdb-wrap
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/server-role
        COMMAND ar -x $<TARGET_FILE:server-role> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/server-role
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/ndr-standard
        COMMAND ar -x $<TARGET_FILE:ndr-standard> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/ndr-standard
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/krb5
        COMMAND ar -x $<TARGET_FILE:krb5> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/krb5
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/asn1util
        COMMAND ar -x $<TARGET_FILE:asn1util> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/asn1util
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-hostconfig
        COMMAND ar -x $<TARGET_FILE:samba-hostconfig> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-hostconfig
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/dbwrap
        COMMAND ar -x $<TARGET_FILE:dbwrap> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/dbwrap
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/gssapi
        COMMAND ar -x $<TARGET_FILE:gssapi> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/gssapi
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/msghdr
        COMMAND ar -x $<TARGET_FILE:msghdr> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/msghdr
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/interfaces
        COMMAND ar -x $<TARGET_FILE:interfaces> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/interfaces
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/events
        COMMAND ar -x $<TARGET_FILE:events> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/events
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/ndr-samba
        COMMAND ar -x $<TARGET_FILE:ndr-samba> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/ndr-samba
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/ldb
        COMMAND ar -x $<TARGET_FILE:ldb> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/ldb
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/krb5samba
        COMMAND ar -x $<TARGET_FILE:krb5samba> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/krb5samba
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/messages-dgm
        COMMAND ar -x $<TARGET_FILE:messages-dgm> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/messages-dgm
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/server-id-db
        COMMAND ar -x $<TARGET_FILE:server-id-db> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/server-id-db
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/messages-util
        COMMAND ar -x $<TARGET_FILE:messages-util> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/messages-util
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/cluster
        COMMAND ar -x $<TARGET_FILE:cluster> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/cluster
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-sockets
        COMMAND ar -x $<TARGET_FILE:samba-sockets> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-sockets
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/MESSAGING-SEND
        COMMAND ar -x $<TARGET_FILE:MESSAGING-SEND> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/MESSAGING-SEND
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/cli-ldap-common
        COMMAND ar -x $<TARGET_FILE:cli-ldap-common> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/cli-ldap-common
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/cliauth
        COMMAND ar -x $<TARGET_FILE:cliauth> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/cliauth
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/flag-mapping
        COMMAND ar -x $<TARGET_FILE:flag-mapping> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/flag-mapping
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/common-auth
        COMMAND ar -x $<TARGET_FILE:common-auth> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/common-auth
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samdb-common
        COMMAND ar -x $<TARGET_FILE:samdb-common> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samdb-common
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/ldbsamba
        COMMAND ar -x $<TARGET_FILE:ldbsamba> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/ldbsamba
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/authkrb5
        COMMAND ar -x $<TARGET_FILE:authkrb5> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/authkrb5
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-credentials
        COMMAND ar -x $<TARGET_FILE:samba-credentials> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-credentials
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/winbind-client
        COMMAND ar -x $<TARGET_FILE:winbind-client> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/winbind-client
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/wbclient
        COMMAND ar -x $<TARGET_FILE:wbclient> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/wbclient
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samdb
        COMMAND ar -x $<TARGET_FILE:samdb> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samdb
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-modules
        COMMAND ar -x $<TARGET_FILE:samba-modules> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-modules
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba3-util
        COMMAND ar -x $<TARGET_FILE:samba3-util> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba3-util
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/clidns
        COMMAND ar -x $<TARGET_FILE:clidns> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/clidns
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/gensec
        COMMAND ar -x $<TARGET_FILE:gensec> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/gensec
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/talloc-report-printf
        COMMAND ar -x $<TARGET_FILE:talloc-report-printf> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/talloc-report-printf
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/util-reg
        COMMAND ar -x $<TARGET_FILE:util-reg> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/util-reg
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-cluster-support
        COMMAND ar -x $<TARGET_FILE:samba-cluster-support> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-cluster-support
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/smbd-shim
        COMMAND ar -x $<TARGET_FILE:smbd-shim> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/smbd-shim
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/CHARSET3
        COMMAND ar -x $<TARGET_FILE:CHARSET3> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/CHARSET3
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/netif
        COMMAND ar -x $<TARGET_FILE:netif> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/netif
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/cli-nbt
        COMMAND ar -x $<TARGET_FILE:cli-nbt> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/cli-nbt
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/addns
        COMMAND ar -x $<TARGET_FILE:addns> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/addns
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/smbconf
        COMMAND ar -x $<TARGET_FILE:smbconf> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/smbconf
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/cli-ldap
        COMMAND ar -x $<TARGET_FILE:cli-ldap> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/cli-ldap
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/cli-cldap
        COMMAND ar -x $<TARGET_FILE:cli-cldap> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/cli-cldap
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/smb-transport
        COMMAND ar -x $<TARGET_FILE:smb-transport> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/smb-transport
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/secrets3
        COMMAND ar -x $<TARGET_FILE:secrets3> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/secrets3
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/cli-smb-common
        COMMAND ar -x $<TARGET_FILE:cli-smb-common> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/cli-smb-common
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/dcerpc-binding
        COMMAND ar -x $<TARGET_FILE:dcerpc-binding> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/dcerpc-binding
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/gse
        COMMAND ar -x $<TARGET_FILE:gse> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/gse
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/dcerpc-samba
        COMMAND ar -x $<TARGET_FILE:dcerpc-samba> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/dcerpc-samba
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/libsmb
        COMMAND ar -x $<TARGET_FILE:libsmb> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/libsmb
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/ndr-samba4
        COMMAND ar -x $<TARGET_FILE:ndr-samba4> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/ndr-samba4
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/msrpc3
        COMMAND ar -x $<TARGET_FILE:msrpc3> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/msrpc3
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/ndr-krb5pac
        COMMAND ar -x $<TARGET_FILE:ndr-krb5pac> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/ndr-krb5pac
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/gnutls
        COMMAND ar -x $<TARGET_FILE:gnutls> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/gnutls
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/smbd-base
        COMMAND ar -x $<TARGET_FILE:smbd-base> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/smbd-base
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/xattr-tdb
        COMMAND ar -x $<TARGET_FILE:xattr-tdb> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/xattr-tdb
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/printing-migrate
        COMMAND ar -x $<TARGET_FILE:printing-migrate> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/printing-migrate
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/npa-tstream
        COMMAND ar -x $<TARGET_FILE:npa-tstream> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/npa-tstream
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/netapi
        COMMAND ar -x $<TARGET_FILE:netapi> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/netapi
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/dcerpc-server-core
        COMMAND ar -x $<TARGET_FILE:dcerpc-server-core> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/dcerpc-server-core
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/cli-spoolss
        COMMAND ar -x $<TARGET_FILE:cli-spoolss> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/cli-spoolss
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/auth
        COMMAND ar -x $<TARGET_FILE:auth> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/auth
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/MESSAGING
        COMMAND ar -x $<TARGET_FILE:MESSAGING> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/MESSAGING
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/net-keytab
        COMMAND ar -x $<TARGET_FILE:net-keytab> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/net-keytab
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/ads
        COMMAND ar -x $<TARGET_FILE:ads> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/ads
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/dcerpc
        COMMAND ar -x $<TARGET_FILE:dcerpc> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/dcerpc
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/libcli-lsa3
        COMMAND ar -x $<TARGET_FILE:libcli-lsa3> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/libcli-lsa3
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/trusts-util
        COMMAND ar -x $<TARGET_FILE:trusts-util> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/trusts-util
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/http
        COMMAND ar -x $<TARGET_FILE:http> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/http
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/smbclient-raw
        COMMAND ar -x $<TARGET_FILE:smbclient-raw> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/smbclient-raw
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/dcerpc-pkt-auth
        COMMAND ar -x $<TARGET_FILE:dcerpc-pkt-auth> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/dcerpc-pkt-auth
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/libcli-netlogon3
        COMMAND ar -x $<TARGET_FILE:libcli-netlogon3> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/libcli-netlogon3
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-passdb
        COMMAND ar -x $<TARGET_FILE:samba-passdb> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-passdb
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/bsd
        COMMAND ar -x $<TARGET_FILE:bsd> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/bsd
        COMMAND mkdir -p ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/resolv
        COMMAND ar -x $<TARGET_FILE:resolv> --output ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/resolv
        COMMAND ar -qcs ${C_LIB} ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/replace/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/talloc/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/time-basic/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/socket-blocking/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/iov-buf/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-debug/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/tevent/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/genrand/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/sys-rw/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/util-setid/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/roken/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-util/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-errors/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/com-err/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/ndr/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/asn1/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/tdb/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-security/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/hcrypto/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/wind/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/ndr-nbt/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/heimbase/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/hx509/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/tevent-util/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/util-tdb/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/tdb-wrap/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/server-role/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/ndr-standard/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/krb5/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/asn1util/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-hostconfig/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/dbwrap/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/gssapi/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/msghdr/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/interfaces/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/events/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/ndr-samba/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/ldb/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/krb5samba/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/messages-dgm/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/server-id-db/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/messages-util/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/cluster/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-sockets/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/MESSAGING-SEND/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/cli-ldap-common/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/cliauth/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/flag-mapping/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/common-auth/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samdb-common/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/ldbsamba/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/authkrb5/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-credentials/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/winbind-client/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/wbclient/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samdb/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-modules/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba3-util/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/clidns/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/gensec/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/talloc-report-printf/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/util-reg/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-cluster-support/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/smbd-shim/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/CHARSET3/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/netif/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/cli-nbt/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/addns/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/smbconf/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/cli-ldap/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/cli-cldap/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/smb-transport/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/secrets3/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/cli-smb-common/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/dcerpc-binding/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/gse/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/dcerpc-samba/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/libsmb/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/ndr-samba4/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/msrpc3/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/ndr-krb5pac/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/gnutls/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/smbd-base/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/xattr-tdb/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/printing-migrate/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/npa-tstream/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/netapi/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/dcerpc-server-core/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/cli-spoolss/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/auth/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/MESSAGING/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/net-keytab/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/ads/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/dcerpc/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/libcli-lsa3/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/trusts-util/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/http/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/smbclient-raw/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/dcerpc-pkt-auth/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/libcli-netlogon3/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/samba-passdb/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/bsd/*.o ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}/resolv/*.o
        WORKING_DIRECTORY ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}
        DEPENDS replace talloc time-basic socket-blocking iov-buf samba-debug tevent genrand sys-rw util-setid roken samba-util samba-errors com-err ndr asn1 tdb samba-security hcrypto wind ndr-nbt heimbase hx509 tevent-util util-tdb tdb-wrap server-role ndr-standard krb5 asn1util samba-hostconfig dbwrap gssapi msghdr interfaces events ndr-samba ldb krb5samba messages-dgm server-id-db messages-util cluster samba-sockets MESSAGING-SEND cli-ldap-common cliauth flag-mapping common-auth samdb-common ldbsamba authkrb5 samba-credentials winbind-client wbclient samdb samba-modules samba3-util clidns gensec talloc-report-printf util-reg samba-cluster-support smbd-shim CHARSET3 netif cli-nbt addns smbconf cli-ldap cli-cldap smb-transport secrets3 cli-smb-common dcerpc-binding gse dcerpc-samba libsmb ndr-samba4 msrpc3 ndr-krb5pac gnutls smbd-base xattr-tdb printing-migrate npa-tstream netapi dcerpc-server-core cli-spoolss auth MESSAGING net-keytab ads dcerpc libcli-lsa3 trusts-util http smbclient-raw dcerpc-pkt-auth libcli-netlogon3 samba-passdb bsd resolv
)

add_library(c STATIC IMPORTED GLOBAL)
add_dependencies(c combined)

set_target_properties(c
        PROPERTIES
        IMPORTED_LOCATION ${C_LIB}
)

set(SAMBA_EXT_MODULES
        c
        PARENT_SCOPE
)

set(SAMBA_THIRD_PARTY_LIBS
        pthread
        dl
        ssl
        crypto
        z
        # resolv
        PARENT_SCOPE
)
