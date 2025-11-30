#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace PrismEngine {

	class PEAPI Log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define PE_ENGINE_TRACE(...)    ::PrismEngine::Log::getCoreLogger()->trace(__VA_ARGS__)
#define PE_ENGINE_INFO(...)     ::PrismEngine::Log::getCoreLogger()->info(__VA_ARGS__)
#define PE_ENGINE_WARN(...)     ::PrismEngine::Log::getCoreLogger()->warn(__VA_ARGS__)
#define PE_ENGINE_ERROR(...)    ::PrismEngine::Log::getCoreLogger()->error(__VA_ARGS__)
#define PE_ENGINE_FATAL(...)    ::PrismEngine::Log::getCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define PE_TRACE(...)	      ::PrismEngine::Log::getClientLogger()->trace(__VA_ARGS__)
#define PE_INFO(...)	      ::PrismEngine::Log::getClientLogger()->info(__VA_ARGS__)
#define PE_WARN(...)	      ::PrismEngine::Log::getClientLogger()->warn(__VA_ARGS__)
#define PE_ERROR(...)	      ::PrismEngine::Log::getClientLogger()->error(__VA_ARGS__)
#define PE_FATAL(...)	      ::PrismEngine::Log::getClientLogger()->critical(__VA_ARGS__)