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

#ifdef WL_ENABLE_ASSERTS
	#define WL_ASSERT(x, ...) { if(!(x)) { WL_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define WL_CORE_ASSERT(x, ...) { if(!(x)) { WL_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define WL_ASSERT(x, ...)
	#define WL_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)