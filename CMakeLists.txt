cmake_minimum_required(VERSION 3.14)
project(agblib)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(agbstring STATIC src/agbstring.c)
target_include_directories(agbstring PUBLIC include)

add_library(agbfile STATIC src/agbfile.c)
target_include_directories(agbfile PUBLIC include)

add_executable(agbcopy src/agbcopy.c)
target_link_libraries(agbcopy PRIVATE agbstring agbfile)
