cmake_minimum_required(VERSION 3.22)
project(audioplugin)
set(CXX_STANDARD_23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs")
include(cmake/cpm.cmake)

CPMAddPackage(
    NAME JUCE
    GITHUB_REPOSITORY juce-framework/JUCE 
    GIT_TAG 9.0.5 
    VERSION 9.0.5
    SOURCE_DIR ${LIB_DIR}/juce
)