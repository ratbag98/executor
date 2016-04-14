cmake_minimum_required(VERSION 3.5)
project(executor)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

include_directories(/Users/robr/src/quickfix /Users/robr/src/quickfix/include )
link_directories( /Users/robr/src/quickfix/lib)

add_executable(executor executor.cpp Application.cpp)
target_link_libraries(executor quickfix)
