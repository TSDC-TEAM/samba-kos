
# @brief Internal function called from add_kos_external_target() and add_kos_external_binary_target()
function (__add_kos_external_target TARGET_NAME ...)
    if (NOT TARGET_NAME)
        message (FATAL_ERROR "TARGET_NAME argument is not set!")
    endif ()

    cmake_parse_arguments (PARSE_ARGV 1 "arg"
            ""
            "QEMU_ENTITY;HW_ENTITY;IMPORTED_LOCATION"
            "DEPENDS_ON_ENTITY")

    if (arg_UNPARSED_ARGUMENTS)
        message (FATAL_ERROR "Unknown arguments: ${arg_UNPARSED_ARGUMENTS}!")
    endif ()

    add_executable (${TARGET_NAME}::entity ALIAS ${TARGET_NAME})
    set_target_properties (${TARGET_NAME} PROPERTIES
            IMPORTED_LOCATION ${arg_IMPORTED_LOCATION}
            SECURITY_CFG ${PROJECT_NAME}/${TARGET_NAME}.cfg
            DEPENDS_ON_ENTITY "${arg_DEPENDS_ON_ENTITY}"
            ENTITY_VAR ${TARGET_NAME}_ENTITY
            )
    if(DEFINED arg_QEMU_ENTITY)
        set_target_properties (${TARGET_NAME} PROPERTIES QEMU_ENTITY ${arg_QEMU_ENTITY})
    endif()
    if(DEFINED arg_HW_ENTITY)
        set_target_properties (${TARGET_NAME} PROPERTIES HW_ENTITY ${arg_HW_ENTITY})
    endif()

    get_property(tmp GLOBAL PROPERTY EXTERNAL_ENTITY_NAMES)
    list(APPEND tmp ${TARGET_NAME})
    set_property(GLOBAL PROPERTY EXTERNAL_ENTITY_NAMES "${tmp}")
endfunction ()

# @brief Function creates imported target from subproject target in the similar way as it's made for SDK entities
# @details
# Use the function to avoid explicit specification of your TARGET_NAME entity in init.yaml
# - additional properties are set to TARGET_NAME:
#   * QEMU_ENTITY, HW_ENTITY - they are used when KOS image is built
#   * DEPENDS_ON_ENTITY - it's used while generating init.yaml
# - alias TARGET_NAME::entity is created for target TARGET_NAME
# Due to specific alias the target is recognized during generating init:yaml, so section like
#[[
- name: myentity.myentity
  connections:
  - target: dependency1.dependency1
    id: ...
  - target: dependency2.dependency2
    id: ...
]]
# is generated inside init.yaml automatically
# The above section is generates from below arguments:
#[[ Example:
add_kos_external_target(myentity
    QEMU_ENTITY myentity::entity
    HW_ENTITY myentity::entity
    DEPENDS_ON_ENTITY "dependency1::entity;dependency2::entity")
]]
# @note You must also call use_kos_external_target(myentity) before build_kos_hw_image/build_kos_qemu_image
function (add_kos_external_target TARGET_NAME ...)

    if (NOT TARGET_NAME)
        message (FATAL_ERROR "TARGET_NAME argument is not set!")
    endif ()

    cmake_parse_arguments (PARSE_ARGV 1 "arg"
            ""
            "QEMU_ENTITY;HW_ENTITY"
            "DEPENDS_ON_ENTITY")

    if (arg_UNPARSED_ARGUMENTS)
        message (FATAL_ERROR "Unknown arguments: ${arg_UNPARSED_ARGUMENTS}!")
    endif ()

    if (NOT arg_QEMU_ENTITY AND NOT arg_HW_ENTITY)
        message (FATAL_ERROR "Either HW_ENTITY or arg_QEMU_ENTITY argument must be specified!")
    endif ()

    if (NOT arg_DEPENDS_ON_ENTITY)
        set(arg_DEPENDS_ON_ENTITY "")
    endif ()

    __add_kos_external_target(${TARGET_NAME}
            QEMU_ENTITY ${arg_QEMU_ENTITY}
            HW_ENTITY ${arg_HW_ENTITY}
            DEPENDS_ON_ENTITY ${arg_DEPENDS_ON_ENTITY}
            IMPORTED_LOCATION $<TARGET_FILE:${TARGET_NAME}>)

    set(DST_DIR "${CMAKE_BINARY_DIR}/_headers_/${PROJECT_NAME}")
    add_custom_target(${TARGET_NAME}-copy-files
            DEPENDS ${DST_DIR}/${TARGET_NAME}.cfg
            )
    add_custom_command(OUTPUT ${DST_DIR}/${TARGET_NAME}.cfg
            COMMAND ${CMAKE_COMMAND} -E make_directory "${DST_DIR}/"
            COMMAND ${CMAKE_COMMAND} -E copy_if_different ${CMAKE_CURRENT_SOURCE_DIR}/${TARGET_NAME}.cfg ${DST_DIR}/${TARGET_NAME}.cfg
            COMMENT "Copying file ${TARGET_NAME}.cfg ..."
            )
    unset(DST_DIR)
    add_dependencies(${TARGET_NAME} ${TARGET_NAME}-copy-files)
endfunction ()

# @brief Function creates imported target from binary file and include files
# in the similar way as it's made for SDK entities
# @details
# Use the function to avoid explicit specification of your TARGET_NAME entity in init.yaml
# - additional properties are set to TARGET_NAME:
#   * QEMU_ENTITY, HW_ENTITY - they are used when KOS image is built
#   * DEPENDS_ON_ENTITY - it's used while generating init.yaml
#   * COPY_TARGET_NAME - name of the custom targer that copies H, EDL and CFG files into CMAKE_BINARY_DIR
#   * WAYLAND_CONNECTION_NAME - name of wayland connection to be added to compositor entity
# - alias TARGET_NAME::entity is created for target TARGET_NAME
# Due to specific alias the target is recognized during generating init:yaml, so section like
#[[
- name: myentity.myentity
  connections:
  - target: dependency1.dependency1
    id: ...
  - target: dependency2.dependency2
    id: ...
]]
# is generated inside init.yaml automatically
# The above section is generates from below arguments:
#[[ Example:
add_kos_external_binary_target(calculator
        DEPENDS_ON_ENTITY "compositor::entity"
        QEMU_ENTITY calculator::entity
        HW_ENTITY calculator::entity
        COPY_TARGET_NAME copy-iw-binary-files
        WAYLAND_CONNECTION_NAME "calculator.calculator")
]]
# @note You must also call use_kos_external_target(myentity) before build_kos_hw_image/build_kos_qemu_image
function (add_kos_external_binary_target TARGET_NAME ...)
    if (NOT TARGET_NAME)
        message (FATAL_ERROR "TARGET_NAME argument is not set!")
    endif ()

    cmake_parse_arguments (PARSE_ARGV 1 "arg"
            ""
            "QEMU_ENTITY;HW_ENTITY;COPY_TARGET_NAME;WAYLAND_CONNECTION_NAME"
            "DEPENDS_ON_ENTITY")

    if (arg_UNPARSED_ARGUMENTS)
        message (FATAL_ERROR "Unknown arguments: ${arg_UNPARSED_ARGUMENTS}!")
    endif ()

    if (NOT arg_QEMU_ENTITY AND NOT arg_HW_ENTITY)
        message (FATAL_ERROR "Either HW_ENTITY or arg_QEMU_ENTITY argument must be specified!")
    endif ()

    if (NOT arg_DEPENDS_ON_ENTITY)
        set(arg_DEPENDS_ON_ENTITY "")
    endif ()

    if (NOT arg_COPY_TARGET_NAME)
        message (FATAL_ERROR "Either COPY_TARGET_NAME argument must be specified!")
    endif ()

    add_executable (${TARGET_NAME} IMPORTED GLOBAL)

    set(ORIGINAL_PROJECT_NAME ${PROJECT_NAME})
    set(PROJECT_NAME ${TARGET_NAME})
    __add_kos_external_target(${TARGET_NAME}
            QEMU_ENTITY ${arg_QEMU_ENTITY}
            HW_ENTITY ${arg_HW_ENTITY}
            DEPENDS_ON_ENTITY ${arg_DEPENDS_ON_ENTITY}
            IMPORTED_LOCATION ${CMAKE_BINARY_DIR}/bin/${TARGET_NAME})
    set(PROJECT_NAME ${ORIGINAL_PROJECT_NAME})
    add_dependencies(${TARGET_NAME} ${arg_COPY_TARGET_NAME})
    if(DEFINED arg_WAYLAND_CONNECTION_NAME)
        add_compositor_wayland_connection("${arg_WAYLAND_CONNECTION_NAME}")
    endif()
endfunction ()


# @brief Function sets ${EXTERNAL_ENTITIES} and sets mandatory TARGET_NAME_ENTITY variables
# @details
# Use the function to avoid explicit specification of your TARGET_NAME entity in init.yaml
# Function iterates through global property EXTERNAL_ENTITY_NAMES and
# - sets mandatory TARGET_NAME_ENTITY variable to TARGET_NAME::entity value for each target
# - fills the list of entities into ${EXTERNAL_ENTITIES} in form ${TARGET_NAME}::entity
# It's necessary to make all the things work
#[[ Example:
use_kos_external_targets(EXTERNAL_ENTITIES)
. . .
build_kos_hw_image(... IMAGE_FILES ${EXTERNAL_ENTITIES} ...)
or build_kos_qemu_image (... IMAGE_FILES ${EXTERNAL_ENTITIES} ...)
]]
function (use_kos_external_targets OUT_EXTERNAL_ENTITIES)
    get_property(NAMES GLOBAL PROPERTY EXTERNAL_ENTITY_NAMES)
    if (NOT NAMES)
        message (WARNING "Global property EXTERNAL_ENTITY_NAMES argument is empty.")
    endif ()

    set(ENTITIES)
    foreach(name ${NAMES})
        set(${name}_ENTITY ${name}::entity PARENT_SCOPE)
        list(APPEND ENTITIES ${name}::entity)
    endforeach()
    set(${OUT_EXTERNAL_ENTITIES} "${ENTITIES}" PARENT_SCOPE)
endfunction ()
