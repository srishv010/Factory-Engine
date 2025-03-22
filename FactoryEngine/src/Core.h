#pragma once

#ifdef FACTORY_BUILD_DLL
	#define FACTORY_API __declspec(dllexport)
#else
	#define FACTORY_API __declspec(dllimport)
#endif