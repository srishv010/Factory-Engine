set(appsources 
    src/main.cpp
)

add_executable(Sandbox ${appsources})

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Sandbox)

add_dependencies(Sandbox FactoryEngine)

target_link_libraries(Sandbox PRIVATE FactoryEngine)

target_include_directories(Sandbox PRIVATE ${CMAKE_SOURCE_DIR}/FactoryEngine/src)

target_compile_definitions(FactoryEngine PUBLIC FACTORY_PLATFORM_WINDOWS)

set_target_properties(Sandbox PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED YES
)

set_target_properties(Sandbox PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)


add_custom_command(TARGET Sandbox POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy
    $<TARGET_FILE:FactoryEngine>
    $<IF:$<CONFIG:Debug>,${CMAKE_BINARY_DIR}/bin/Debug,${CMAKE_BINARY_DIR}/bin/Release>
)