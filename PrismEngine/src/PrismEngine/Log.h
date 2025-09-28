#pragma once

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
