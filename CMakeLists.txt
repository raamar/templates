cmake_minimum_required(VERSION 3.10)
project(templates-cpp)

add_subdirectory(include)
add_subdirectory(src)

add_executable(templates_cpp ${SOURCES} ${HEADERS})

target_include_directories(templates_cpp PRIVATE include)