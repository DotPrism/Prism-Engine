#include "pepch.h"
#include "Application.h"
#include "PrismEngine/Log.h"

#include <GLFW/glfw3.h>

namespace PrismEngine
{
#define BIND_EVENT_FN(x) std::bind(&x, this, std::placeholders::_1)
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::create());
		m_Window->setEventCallback(BIND_EVENT_FN(Application::onEvent));
	}

	Application::~Application()
	{
	}

	void Application::onEvent(Event& event)
	{
		EventDispatcher dispatcher(event);

		dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::onWindowCloseEvent));

		PE_ENGINE_TRACE("{0}", event);
	}

	void Application::run()
	{
		while (m_Running)
		{
			glClearColor(0, 0, 0, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->onUpdate();
		}
	}

	bool Application::onWindowCloseEvent(WindowCloseEvent& event)
	{
		m_Running = false;
		return true;
	}
}
