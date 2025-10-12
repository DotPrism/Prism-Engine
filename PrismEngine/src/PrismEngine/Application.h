#pragma once

#include "PrismEngine/Core.h"

#include "Window.h"

#include "PrismEngine/LayerStack.h"
#include "PrismEngine/Events/Event.h"
#include "PrismEngine/Events/ApplicationEvent.h"
#include "PrismEngine/ImGui/ImGuiLayer.h"

namespace PrismEngine
{
	class PEAPI Application
	{
	public:
		Application();
		virtual ~Application();

		void run();
		void onEvent(Event& event);

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* layer);

		inline Window& getWindow() { return *m_Window; }

		inline static Application& get() { return *s_Instance; }

	private:
		bool onWindowCloseEvent(WindowCloseEvent& event);

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
		static Application* s_Instance;
	};

	Application* createApplication();
}
