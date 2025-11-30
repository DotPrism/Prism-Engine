#pragma once

#include "PrismEngine/Core/Window.h"
#include "PrismEngine/Renderer/GraphicsContext.h"

#include <GLFW/glfw3.h>

namespace PrismEngine
{

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void onUpdate() override;

		inline unsigned int getWidth() const override { return m_Data.Width; }
		inline unsigned int getHeight() const override { return m_Data.Height; }

		// Window attributes
		inline void setEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void setVSync(bool enabled) override;
		bool isVSync() const override;

		inline virtual void* getNativeWindow() const { return m_Window; }
	private:
		virtual void init(const WindowProps& props);
		virtual void shutdown();
	private:
		GLFWwindow* m_Window;
		Renderer::GraphicsContext* m_Context;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallbackFn EventCallback;
		};

		WindowData m_Data;
	};

}