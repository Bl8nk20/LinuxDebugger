find_package(Doxygen)

if(DOXYGEN_FOUND)
    add_custom_target(
        docs
        ${DOXYGEN_EXECUTABLE}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/docs
    )
else()
  message(STATUS "Doxygen not found, not building docs")
endif()