cmake_minimum_required(VERSION 3.20)
project(BasicOfProgrammingCource C)

set(CMAKE_C_STANDARD 11)

add_executable(BasicOfProgrammingCource main.c)
add_subdirectory(libs)

target_link_libraries(BasicOfProgrammingCource data_structures)
