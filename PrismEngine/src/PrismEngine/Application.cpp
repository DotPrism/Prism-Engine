#include "pepch.h"
#include "Application.h"

#include "PrismEngine/Log.h"
#include "PrismEngine/Events/ApplicationEvent.h"

PrismEngine::Application::Application()
{

}

PrismEngine::Application::~Application()
{

}

void PrismEngine::Application::run()
{
	WindowResizeEvent e(1280, 720);
	if (e.isInCategory(EventCategoryApplication))
	{
		PE_TRACE(e);
	}
	if (e.isInCategory(EventCategoryInput))
	{
		PE_TRACE(e);
	}

	while (true);
}
