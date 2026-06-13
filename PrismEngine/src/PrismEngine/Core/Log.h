#pragma once

#include "PrismEngine/Core/Base.h"

#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace PrismEngine {

	class Log
	{
	public:
		static void init();

		inline static Ref<spdlog::logger>& getCoreLogger() { return s_CoreLogger; }
		inline static Ref<spdlog::logger>& getClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define PE_CORE_TRACE(...)    ::PrismEngine::Log::getCoreLogger()->trace(__VA_ARGS__)
#define PE_CORE_INFO(...)     ::PrismEngine::Log::getCoreLogger()->info(__VA_ARGS__)
#define PE_CORE_WARN(...)     ::PrismEngine::Log::getCoreLogger()->warn(__VA_ARGS__)
#define PE_CORE_ERROR(...)    ::PrismEngine::Log::getCoreLogger()->error(__VA_ARGS__)
#define PE_CORE_CRITICAL(...)    ::PrismEngine::Log::getCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define PE_TRACE(...)	      ::PrismEngine::Log::getClientLogger()->trace(__VA_ARGS__)
#define PE_INFO(...)	      ::PrismEngine::Log::getClientLogger()->info(__VA_ARGS__)
#define PE_WARN(...)	      ::PrismEngine::Log::getClientLogger()->warn(__VA_ARGS__)
#define PE_ERROR(...)	      ::PrismEngine::Log::getClientLogger()->error(__VA_ARGS__)
#define PE_CRITICAL(...)	      ::PrismEngine::Log::getClientLogger()->critical(__VA_ARGS__)
