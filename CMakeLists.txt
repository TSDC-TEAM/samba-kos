cmake_minimum_required (VERSION 3.12)

project(samba LANGUAGES C CXX)

set(CMAKE_C_STANDARD 11)

set(SMB_SRC_ROOT ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(kos)
