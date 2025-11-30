#include "pepch.h"
#include "Application.h"

#include "PrismEngine/Core/Log.h"
#include "PrismEngine/Core/Input.h"

#include "PrismEngine/Renderer/Renderer.h"

#include "GLFW/glfw3.h"

namespace PrismEngine::App
{

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		PE_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = std::unique_ptr<Window>(Window::create());
		m_Window->setEventCallback(BIND_EVENT_FN(onEvent));

		Renderer::Renderer::init();

		m_ImGuiLayer = new ImGuiBackend::ImGuiLayer();
		pushOverlay(m_ImGuiLayer);
	}

	void Application::pushLayer(Layer* layer)
	{
		m_LayerStack.pushLayer(layer);
		layer->onAttach();
	}

	void Application::pushOverlay(Layer* layer)
	{
		m_LayerStack.pushOverlay(layer);
		layer->onAttach();
	}

	void Application::onEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->onEvent(e);
			if (e.Handled)
				break;
		}
	}

	void Application::run()
	{
		while (m_Running)
		{
			Renderer::RenderCommand::setClearColor({ 0.1f, 0.1f, 0.1f, 1 });
			Renderer::RenderCommand::clear();

			float time = (float)glfwGetTime();
			Time::Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			for (Layer* layer : m_LayerStack)
				layer->onUpdate(timestep);

			m_ImGuiLayer->begin();
			for (Layer* layer : m_LayerStack)
				layer->onImGuiRender();
			m_ImGuiLayer->end();

			m_Window->onUpdate();
		}
	}

	bool Application::onWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

}