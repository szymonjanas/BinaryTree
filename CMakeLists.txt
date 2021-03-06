cmake_minimum_required(VERSION 3.2)

#############GOOGLE TEST ############
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif ()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download)
if (result)
    message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif ()

add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
        ${CMAKE_BINARY_DIR}/googletest-build
        EXCLUDE_FROM_ALL)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
#####################################

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-c
        -Wall
        -Wextra
        -Winit-self
        -Wold-style-cast
        -Woverloaded-virtual
        -Wuninitialized
        -pedantic
        -pedantic-errors
        -g
        )

project(BinaryTree CXX)

include_directories(inc)
add_executable(${PROJECT_NAME} src/main.cpp)

set(TEST_SRC_LIST
        test/mainTest.cpp
        test/treeTest.cpp
        test/treeAlgorithmTest.cpp
        )

link_libraries(gtest)
add_executable(${PROJECT_NAME}-ut ${TEST_SRC_LIST})
target_link_libraries(${PROJECT_NAME})


