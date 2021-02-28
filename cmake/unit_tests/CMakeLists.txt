# created by Ryan Puhalovich - https://github.com/rpuhalovich/

add_executable(unit_tests ${unit_tests_sources})

target_link_libraries(unit_tests STATIC
    gtest_main
    gmock_main
)

target_include_directories(unit_tests PRIVATE 
    "${OBJECTS_SOURCE_ROOT}"
    "${KERNEL_SOURCE_ROOT}"
    "${EXTERN_SOURCE_ROOT}"
)

source_group(Tests FILES ${unit_tests_sources})
source_group(src FILES 
    ${plugin_object_sources} 
    ${kernel_sources} 
    ${UNIT_TESTS_SOURCE_ROOT}/catch_main.cpp
)
