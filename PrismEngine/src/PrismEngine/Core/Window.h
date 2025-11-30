#pragma once

#include "pepch.h"

#include "PrismEngine/Core/Core.h"
#include "PrismEngine/Events/Event.h"

namespace PrismEngine
{

	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "PrismEngine",
			        unsigned int width = 1280,
			        unsigned int height = 720)
			: Title(title), Width(width), Height(height)
		{
		}
	};

	// Interface representing a desktop system based Window
	class PEAPI Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void onUpdate() = 0;

		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;

		// Window attributes
		virtual void setEventCallback(const EventCallbackFn& callback) = 0;
		virtual void setVSync(bool enabled) = 0;
		virtual bool isVSync() const = 0;

		virtual void* getNativeWindow() const = 0;

		static Window* create(const WindowProps& props = WindowProps());
	};

}