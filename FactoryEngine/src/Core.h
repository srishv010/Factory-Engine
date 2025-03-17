#pragma once

#ifdef FACTORY_PLATFORM_WINDOWS
    #ifdef FACTORY_BUILD_DLL
        #define FACTORY_API __declspec(dllexport)
    #else
        #define FACTORY_API __declspec(dllimport)
    #endif
#else
    #error Only Windows is supported.
#endif