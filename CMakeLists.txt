cmake_minimum_required(VERSION 3.5)
project(executor)

include (CTest)
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
        /Users/robr/src/quickfix
        /Users/robr/src/quickfix/include
)

link_directories(/Users/robr/src/quickfix/lib)

add_executable(executor executor.cpp Application.cpp)
target_link_libraries(executor quickfix)


add_test (ExecutorRuns executor)

add_test (ExecutorUsage executor)
set_tests_properties(ExecutorUsage PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .*executor")
