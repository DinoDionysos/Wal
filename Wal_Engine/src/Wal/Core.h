#pragma once

// automatically distinguish between ex and import by defining WAL_API
// depending on if WL_BUILD_DLL is defined in preprocessor definitions
#ifdef WL_PLATFORM_WINDOWS
	#ifdef WL_BUILD_DLL
		#define WAL_API __declspec(dllexport)
	#else
		#define WAL_API __declspec(dllimport)
	#endif
#else
	#error Wal only supports Windows!
#endif