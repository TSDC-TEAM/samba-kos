option(KOS_HW "Build for KOS HW (default is FALSE)" OFF)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
if (KOS)
    list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/kos)
else()
    list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/linux)
endif()

include(tools)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

set(PRODUCT_RESOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/resources)
set(PRODUCT_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR}/entity)

if (KOS)
    add_subdirectory(libs_tmp)
else()
    add_subdirectory(libs)
endif()

add_subdirectory(entity)
