#pragma once

#include <string>
#include <optional>

namespace PrismEngine::Utils {

	class FileDialogs
	{
	public:
		// These return empty strings if cancelled
		static std::optional<std::string> openFile(const char* filter);
		static std::optional<std::string> saveFile(const char* filter);
	};

}
