cmake_minimum_required(VERSION 3.5)
project(executor)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)

include(CTest)
enable_testing()

set(Executor_VERSION_MAJOR 1)
set(Executor_VERSION_MINOR 0)

# pass Cmake varibles into the source code
configure_file(
        "${PROJECT_SOURCE_DIR}/ExecutorConfig.h.in"
        "${PROJECT_BINARY_DIR}/ExecutorConfig.h"
)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wno-uninitialized")

include_directories(
        "${PROJECT_BINARY_DIR}"
)

add_executable(executor executor.cpp Application.cpp)

find_package(QUICKFIX)

if (QUICKFIX_FOUND)
    include_directories(${QUICKFIX_INCLUDE_DIRS})
    target_link_libraries(executor ${QUICKFIX_LIBRARIES})
endif (QUICKFIX_FOUND)

add_test(ExecutorRuns executor)

add_test(ExecutorUsage executor)
set_tests_properties(ExecutorUsage PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .*executor")
