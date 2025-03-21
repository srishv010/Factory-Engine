project(glad)
cmake_policy(SET CMP0003 NEW)

add_library(glad)
target_sources(glad PRIVATE src/glad.c)
target_include_directories(glad PUBLIC include)