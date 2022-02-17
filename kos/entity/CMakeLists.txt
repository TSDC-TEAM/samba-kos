#add_subdirectory(smbclient)
add_subdirectory(smbd)

if (KOS)
    add_subdirectory(einit)
    add_subdirectory(env)
endif()
