#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace PrismEngine
{
	class PEAPI Application
	{
	public:
		Application();
		virtual ~Application();

		void run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* createApplication();
}
