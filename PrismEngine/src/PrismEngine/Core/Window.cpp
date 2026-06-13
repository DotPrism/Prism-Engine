#include "pepch.h"
#include "PrismEngine/Core/Window.h"

#ifdef PE_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif

namespace PrismEngine
{

	Scope<Window> Window::create(const WindowProps& props)
	{
#ifdef PE_PLATFORM_WINDOWS
		return createScope<WindowsWindow>(props);
#else
		PE_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}

}