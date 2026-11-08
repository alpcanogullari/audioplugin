cmake_minimum_required(VERSION 3.22)
project(audioplugin)
set(CXX_STANDARD_23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIB_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs")
include(cmake/cpm.cmake)

CPMAddPackage(
    NAME JUCE
    GIT_TAG master
    GITHUB_REPOSITORY juce_framework/JUCE 
)