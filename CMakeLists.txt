cmake_minimum_required(VERSION 3.18)
cmake_policy(SET CMP0048 NEW)

project(FactoryEngine)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/glm)

add_subdirectory(RenderAPIInterface)
add_subdirectory(OpenGLRenderAPI)
add_subdirectory(FactoryEngine)
add_subdirectory(Sandbox)