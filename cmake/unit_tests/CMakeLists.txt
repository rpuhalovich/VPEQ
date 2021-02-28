# created by Ryan Puhalovich - https://github.com/rpuhalovich/

set(this unit_tests)
add_executable(${this} 
    ${unit_tests_sources}
    ${OBJECTS_SOURCE_ROOT}/fxobjects.h # <-- must include only files to be tested
    ${OBJECTS_SOURCE_ROOT}/fxobjects.cpp
    ${OBJECTS_SOURCE_ROOT}/Filter.hpp
    ${OBJECTS_SOURCE_ROOT}/Filter.cpp
    ${OBJECTS_SOURCE_ROOT}/SimpleBiquad.cpp
    ${OBJECTS_SOURCE_ROOT}/SimpleBiquad.hpp
)

target_link_libraries(${this} PUBLIC # <-- MUST BE PUBLIC
    gtest_main
    gmock_main
)

target_include_directories(${this} PRIVATE 
    "${OBJECTS_SOURCE_ROOT}"
    "${KERNEL_SOURCE_ROOT}"
    "${CUSTOM_CONTROLS_SOURCE_ROOT}"
    "${EXTERN_SOURCE_ROOT}"
)

source_group(Tests FILES ${unit_tests_sources})
source_group(src FILES 
    ${plugin_object_sources} 
    ${kernel_sources} 
)
