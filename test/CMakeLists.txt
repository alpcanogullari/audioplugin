cmake_minimum_required(VERSION 3.22)
project(audioplugin)

enable_testing()

add_executable(${PROJECT_NAME}
    source/AudioProcessorTest.cpp
)



target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${GOOGLETEST_SOURCE_DIR}/googletest/include
        ${CMAKE_CURRENT_SOURCE_DIR}/../plugin/source
        ${JUCE_SOURCE_DIR}/modules
    )

target_link_libraries(${PROJECT_NAME}
    PRIVATE
       AudioPlugin
       GTest::gtest_main 
    )

add_subdirectory(test)
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})