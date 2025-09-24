#pragma once

#ifdef PE_PLATFORM_WINDOWS
	#ifdef PE_BUILD_DLL
		#define PEAPI __declspec(dllexport)
	#else
		#define PEAPI __declspec(dllimport)
	#endif
#endif
