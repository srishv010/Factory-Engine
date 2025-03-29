project(OpenGLRenderAPI)

file (GLOB_RECURSE sources 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp

    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/include/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/src/glad.c
)

add_library(OpenGLRenderAPI SHARED ${sources})

find_package(OpenGL REQUIRED)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw)

add_dependencies(OpenGLRenderAPI RenderAPIInterface)

target_link_libraries(OpenGLRenderAPI PUBLIC glfw OpenGL::GL)
target_link_libraries(OpenGLRenderAPI PUBLIC glm::glm RenderAPIInterface)

target_include_directories(OpenGLRenderAPI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(OpenGLRenderAPI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/include)
target_include_directories(OpenGLRenderAPI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/src)

target_compile_definitions(OpenGLRenderAPI PUBLIC OPEN_GL_RENDER_API_PLATFORM_WINDOWS)
target_compile_definitions(OpenGLRenderAPI PRIVATE OPEN_GL_RENDER_API_BUILD_DLL)

set_target_properties(OpenGLRenderAPI PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED YES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

add_custom_command(TARGET OpenGLRenderAPI POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:OpenGLRenderAPI>
    $<IF:$<CONFIG:Debug>,${CMAKE_BINARY_DIR}/bin/Debug,${CMAKE_BINARY_DIR}/bin/Release>
)