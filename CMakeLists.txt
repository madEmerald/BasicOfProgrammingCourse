cmake_minimum_required(VERSION 3.20)
project(BasicOfProgrammingCourse C)

set(CMAKE_C_STANDARD 11)

add_executable(BasicOfProgrammingCourse
        libs/data_structures/string/tasks/3.c)
add_subdirectory(libs)

target_link_libraries(BasicOfProgrammingCourse data_structures)
target_link_libraries(BasicOfProgrammingCourse algorithms)
