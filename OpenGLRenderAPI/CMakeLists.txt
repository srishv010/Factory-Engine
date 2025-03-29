project(OpenGLRenderAPI)

file (GLOB_RECURSE sources 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/include/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/src/glad.c
)

add_library(OpenGLRenderAPI STATIC ${sources})

find_package(OpenGL REQUIRED)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw)

add_dependencies(OpenGLRenderAPI RenderAPIInterface)

target_link_libraries(OpenGLRenderAPI PUBLIC RenderAPIInterface glfw OpenGL::GL) #consider private

target_include_directories(OpenGLRenderAPI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(OpenGLRenderAPI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/include)
target_include_directories(OpenGLRenderAPI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/src)
