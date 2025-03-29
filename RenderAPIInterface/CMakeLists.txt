project(RenderAPIInterface)

file (GLOB_RECURSE sources 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
)

add_library(RenderAPIInterface STATIC ${sources})

target_include_directories(RenderAPIInterface PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
