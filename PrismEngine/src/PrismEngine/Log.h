#pragma once
#pragma warning(disable : 4996)

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace PrismEngine
{
	class PEAPI Log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger> getEngineLogger() { return s_EngineLogger; }
		inline static std::shared_ptr<spdlog::logger> getClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_EngineLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Engine Logging
#define PE_ENGINE_ERROR(...) ::PrismEngine::Log::getEngineLogger()->error(__VA_ARGS__)
#define PE_ENGINE_FATAL(...) ::PrismEngine::Log::getEngineLogger()->fatal(__VA_ARGS__)
#define PE_ENGINE_WARN(...) ::PrismEngine::Log::getEngineLogger()->warn(__VA_ARGS__)
#define PE_ENGINE_INFO(...) ::PrismEngine::Log::getEngineLogger()->info(__VA_ARGS__)
#define PE_ENGINE_TRACE(...) ::PrismEngine::Log::getEngineLogger()->trace(__VA_ARGS__)

// Client Logging
#define PE_CLIENT_ERROR(...) ::PrismEngine::Log::getClientLogger()->error(__VA_ARGS__)
#define PE_CLIENT_FATAL(...) ::PrismEngine::Log::getClientLogger()->fatal(__VA_ARGS__)
#define PE_CLIENT_WARN(...) ::PrismEngine::Log::getClientLogger()->warn(__VA_ARGS__)
#define PE_CLIENT_INFO(...) ::PrismEngine::Log::getClientLogger()->info(__VA_ARGS__)
#define PE_CLIENT_TRACE(...) ::PrismEngine::Log::getEngineLogger()->trace(__VA_ARGS__)
