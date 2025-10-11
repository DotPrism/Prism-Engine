#include "pepch.h"
#include "Application.h"

#include "PrismEngine/Events/ApplicationEvent.h"
#include "PrismEngine/Log.h"

#include <GLFW/glfw3.h>

PrismEngine::Application::Application()
{
	m_Window = std::unique_ptr<Window>(Window::create());
}

PrismEngine::Application::~Application()
{
}

void PrismEngine::Application::run()
{
	while (m_Running)
	{
		glClearColor(1, 0, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);
		m_Window->onUpdate();
	}
}
