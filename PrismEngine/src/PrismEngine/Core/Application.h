#pragma once

#include "Core.h"

#include "Window.h"
#include "PrismEngine/Core/LayerStack.h"
#include "PrismEngine/Events/Event.h"
#include "PrismEngine/Events/ApplicationEvent.h"

#include "PrismEngine/ImGui/ImGuiLayer.h"

#include "PrismEngine/Core/Timestep.h"

namespace PrismEngine::App
{

	class Application
	{
	public:
		Application();
		virtual ~Application() = default;

		void run();

		void onEvent(Event& e);

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* layer);

		inline Window& getWindow() { return *m_Window; }

		inline static Application& get() { return *s_Instance; }
	private:
		bool onWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		ImGuiBackend::ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* createApplication();

}