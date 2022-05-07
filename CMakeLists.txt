cmake_minimum_required (VERSION 3.12)

project(samba LANGUAGES C CXX)

set(SANITIZE 1)

if(SANITIZE AND CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    add_compile_options("-fsanitize=address" "-fno-omit-frame-pointer")
    add_link_options("-fsanitize=address")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(GCCDEFS "-fstack-clash-protection")
endif()

set(CMAKE_C_STANDARD 11)

set(SMB_SRC_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(kos)

if (NOT KOS)
    add_subdirectory(tests/kos/dumps)
    add_subdirectory(tests/kos/env)
endif()
