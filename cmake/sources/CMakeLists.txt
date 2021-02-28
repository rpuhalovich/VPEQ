# created by Ryan Puhalovich - https://github.com/rpuhalovich/

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
    ${OBJECTS_SOURCE_ROOT}/FreqResponseView.hpp
    ${OBJECTS_SOURCE_ROOT}/FreqResponseView.cpp
    PARENT_SCOPE
)
    
set(unit_tests_sources
    ${UNIT_TESTS_SOURCE_ROOT}/catch_main.cpp
    ${UNIT_TESTS_SOURCE_ROOT}/test_Filter.cpp
    ${UNIT_TESTS_SOURCE_ROOT}/test_SimpleBiquad.cpp
    PARENT_SCOPE
)

set(PCH "${CMAKE_SOURCE_DIR}/project_source/source/PluginObjects/pch.hpp" PARENT_SCOPE)
