cmake_minimum_required(VERSION 3.23)
project(MyOpencvFunc)

set(CMAKE_CXX_STANDARD 17)

add_executable(func.hpp  test.cpp)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
set(SOURCE_FILES main.cpp)
target_link_libraries(line_test ${OpenCV_LIBS})
