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

#ifdef PE_DEBUG
#define PE_ENABLE_ASSERTS
#endif

#ifdef PE_ENABLE_ASSERTS
#define PE_ASSERT(x, ...) { if(!(x)) { PE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define PE_CORE_ASSERT(x, ...) { if(!(x)) { PE_ENGINE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define PE_ASSERT(x, ...)
#define PE_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)
