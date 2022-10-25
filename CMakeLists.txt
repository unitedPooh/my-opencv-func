cmake_minimum_required(VERSION 3.23)
project(MyOpencvFunc)

set(CMAKE_CXX_STANDARD 17)

add_executable(MyOpencvFunc test.cpp)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
set(SOURCE_FILES test.cpp)
target_link_libraries(MyOpencvFunc ${OpenCV_LIBS})
