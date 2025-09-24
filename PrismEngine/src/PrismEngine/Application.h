#pragma once

#include "Core.h"

namespace PrismEngine
{
	class PEAPI Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
	};

	Application* createApplication();
}
