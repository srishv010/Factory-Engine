set(sources
src/FactoryEngine.cpp
src/FactoryEngine.h
src/Core.h
)

add_library(FactoryEngine SHARED ${sources})

target_compile_definitions(FactoryEngine PUBLIC FACTORY_PLATFORM_WINDOWS)
target_compile_definitions(FactoryEngine PRIVATE FACTORY_BUILD_DLL)

target_include_directories(FactoryEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

set_target_properties(FactoryEngine PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED YES
)

set_target_properties(FactoryEngine PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)