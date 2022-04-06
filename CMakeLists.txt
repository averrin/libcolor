cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
project(libcolor)
set( EXE_NAME ${PROJECT_NAME} )

add_executable(${EXE_NAME} libcolor_test.cpp)
target_link_libraries(libcolor PRIVATE)
