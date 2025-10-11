#pragma once

#include "Core.h"
#include "Events/Event.h"

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
