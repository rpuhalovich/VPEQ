# created by Ryan Puhalovich - https://github.com/rpuhalovich/
# adding unit testing to the Aspik template

# sources for the library to link to exe
set(OBJECTS_SOURCE_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../../source/PluginObjects")
set(KERNEL_SOURCE_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../../source/PluginKernel")
set(VENDOR_SOURCE_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/../../source/vendor")

set(kernel_sources ${KERNEL_SOURCE_ROOT}/guiconstants.h)

# plugin_object_sources and TESTS_SRC found in root CMakeLists.txt
add_executable(unit_tests
    ${TESTS_DIR}/catch_main.cpp
    ${TESTS_SRC} 
    ${plugin_object_sources} 
    ${kernel_sources}
)

target_link_libraries(unit_tests STATIC
    gtest_main
)

# include directories to main exe
target_include_directories(unit_tests PRIVATE 
    "${OBJECTS_SOURCE_ROOT}"
    "${KERNEL_SOURCE_ROOT}"
    "${VENDOR_SOURCE_ROOT}"
)

source_group(Tests FILES ${TESTS_SRC})
source_group(src FILES ${plugin_object_sources} ${kernel_sources} ${TESTS_DIR}/catch_main.cpp)
