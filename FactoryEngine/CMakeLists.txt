cmake_policy(SET CMP0003 NEW)

file ( GLOB_RECURSE sources CMAKE_CONFIGURE_DEPENDS
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/resources/shaders/*.glsl

    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/include/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/src/glad.c
)

add_library(FactoryEngine SHARED ${sources})

find_package(OpenGL REQUIRED)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/glfw)
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/vendor/glm)

target_link_libraries(FactoryEngine glfw OpenGL::GL glm::glm)


target_include_directories(FactoryEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_include_directories(FactoryEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/include)
target_include_directories(FactoryEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vendor/glad/src)

target_compile_definitions(FactoryEngine PUBLIC FACTORY_PLATFORM_WINDOWS)
target_compile_definitions(FactoryEngine PRIVATE FACTORY_BUILD_DLL)

set_target_properties(FactoryEngine PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED YES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)


add_custom_command(TARGET FactoryEngine POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_CURRENT_SOURCE_DIR}/resources
    $<IF:$<CONFIG:Debug>,${CMAKE_BINARY_DIR}/bin/Debug/resources,${CMAKE_BINARY_DIR}/bin/Release/resources>
)
