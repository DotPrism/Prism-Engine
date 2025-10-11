#pragma once

#ifdef PE_PLATFORM_WINDOWS
	#ifdef PE_BUILD_DLL
		#define PEAPI __declspec(dllexport)
	#else
		#define PEAPI __declspec(dllimport)
	#endif
#else
	#error Prism Engine only supports Windows!
#endif

#ifdef PE_ENABLE_ASSERTS
#define HZ_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define HZ_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define HZ_ASSERT(x, ...)
#define HZ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
