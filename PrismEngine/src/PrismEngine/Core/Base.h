#pragma once

#include <memory>

#include "PlatformDetection.h"

#ifdef PE_DEBUG
#if defined(PE_PLATFORM_WINDOWS)
	#define PE_DEBUGBREAK() __debugbreak()
#elif defined(PE_PLATFORM_LINUX)
	#include <signal.h>
	#define PE_DEBUGBREAK() raise(SIGTRAP)
#else
	#error "Platform doesn't support debugbreak yet!"
#endif
	#define PE_ENABLE_ASSERTS
#else
	#define PE_DEBUGBREAK()
#endif

#define BIT(x) (1 << x)

#define PE_BIND_EVENT_FN(fn) [this](auto&&... args) -> decltype(auto) { return this->fn(std::forward<decltype(args)>(args)...); }

namespace PrismEngine 
{
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> createScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> createRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}

#include "PrismEngine/Core/Log.h"
#include "PrismEngine/Core/Assert.h"
