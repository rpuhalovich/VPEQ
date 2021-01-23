# --- sources for the following add_subdirectory(s) (cus repeat code is uncool)
# used in:
# - project_source/cmake/aax_cmake
# - project_source/cmake/au_cmake
# - project_source/cmake/vst_cmake
# - project_source/cmake/unit_tests

# must duplicate dirs as the PARENT_SCOPE flag removes the variable from the current scope
set(OBJECTS_SOURCE_ROOT "${CMAKE_SOURCE_DIR}/project_source/source/PluginObjects" PARENT_SCOPE)
set(OBJECTS_SOURCE_ROOT "${CMAKE_SOURCE_DIR}/project_source/source/PluginObjects") 
set(plugin_object_sources
    ${OBJECTS_SOURCE_ROOT}/fxobjects.h
    ${OBJECTS_SOURCE_ROOT}/filters.h
    ${OBJECTS_SOURCE_ROOT}/fxobjects.cpp
    ${OBJECTS_SOURCE_ROOT}/Filter.hpp
    ${OBJECTS_SOURCE_ROOT}/Filter.cpp
    ${OBJECTS_SOURCE_ROOT}/SimpleBiquad.cpp
    ${OBJECTS_SOURCE_ROOT}/SimpleBiquad.hpp
    ${OBJECTS_SOURCE_ROOT}/pch.hpp
    ${OBJECTS_SOURCE_ROOT}/utils.hpp
    ${OBJECTS_SOURCE_ROOT}/controlView.hpp
    PARENT_SCOPE
)

# used in project_source/cmake/unit_tests
set(TESTS_DIR "${CMAKE_SOURCE_DIR}/project_source/source/unit_tests" PARENT_SCOPE)
set(TESTS_DIR "${CMAKE_SOURCE_DIR}/project_source/source/unit_tests")
set(TESTS_SRC
    ${TESTS_DIR}/catch_main.cpp
    ${TESTS_DIR}/test_Filter.cpp
    ${TESTS_DIR}/test_SimpleBiquad.cpp
    PARENT_SCOPE
)

set(PCH "${CMAKE_SOURCE_DIR}/project_source/source/PluginObjects/pch.hpp" PARENT_SCOPE)