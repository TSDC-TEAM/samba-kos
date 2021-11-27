add_executable(${TARGET_NAME} ${TARGET_SRC})

if (TARGET_LIBS)
    target_link_libraries(${TARGET_NAME} ${TARGET_LIBS})
endif ()
