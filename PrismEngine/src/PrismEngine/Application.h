#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "PrismEngine/Events/ApplicationEvent.h"
#include "Window.h"

namespace PrismEngine
{
	class PEAPI Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
		void onEvent(Event& event);

	private:
		bool onWindowCloseEvent(WindowCloseEvent& event);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	Application* createApplication();
}
