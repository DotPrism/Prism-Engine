#pragma once

#include "PrismEngine/Core/Base.h"

#include "PrismEngine/Core/Window.h"
#include "PrismEngine/Core/LayerStack.h"
#include "PrismEngine/Events/Event.h"
#include "PrismEngine/Events/ApplicationEvent.h"

#include "PrismEngine/ImGui/ImGuiLayer.h"

#include "PrismEngine/Core/Timestep.h"

int main(int argc, char** argv);

namespace PrismEngine::App
{

	class Application
	{
	public:
		Application(const std::string& name = "PrismEngine App");
		virtual ~Application();

		void onEvent(Event& e);

		void pushLayer(Layer* layer);
		void pushOverlay(Layer* layer);

		Window& getWindow() const { return *m_Window; }

		ImGuiBackend::ImGuiLayer* getImGuiLayer() const { return m_ImGuiLayer; }

		void close();

		inline static Application& get() { return *s_Instance; }
	
		void run();
	private:
		bool onWindowClose(WindowCloseEvent& e);
		bool onWindowResize(WindowResizeEvent& e);
	private:
		Scope<Window> m_Window;
		PrismEngine::ImGuiBackend::ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	// To be defined in CLIENT
	Application* createApplication();

}
