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

#define BIT(x) (1 << x)
