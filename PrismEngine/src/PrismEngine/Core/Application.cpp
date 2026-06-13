#include "pepch.h"
#include "PrismEngine/Core/Application.h"

#include "PrismEngine/Core/Log.h"
#include "PrismEngine/Core/Input.h"

#include "PrismEngine/Renderer/Renderer.h"

#include "GLFW/glfw3.h"

namespace PrismEngine::App
{

	Application* Application::s_Instance = nullptr;

	Application::Application(const std::string& name)
	{
		PE_PROFILE_FUNCTION();

		PE_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_Window = Window::create(WindowProps(name));
		m_Window->setEventCallback(PE_BIND_EVENT_FN(Application::onEvent));

		Rendering::Renderer::init();

		m_ImGuiLayer = new ImGuiBackend::ImGuiLayer();
		pushOverlay(m_ImGuiLayer);
	}

	Application::~Application()
	{
		PE_PROFILE_FUNCTION();

		Rendering::Renderer::shutdown();
	}

	void Application::pushLayer(Layer* layer)
	{
		PE_PROFILE_FUNCTION();

		m_LayerStack.pushLayer(layer);
		layer->onAttach();
	}

	void Application::pushOverlay(Layer* layer)
	{
		PE_PROFILE_FUNCTION();

		m_LayerStack.pushOverlay(layer);
		layer->onAttach();
	}

	void Application::close()
	{
		m_Running = false;
	}

	void Application::onEvent(Event& e)
	{
		PE_PROFILE_FUNCTION();

		EventDispatcher dispatcher(e);
		dispatcher.dispatch<WindowCloseEvent>(PE_BIND_EVENT_FN(Application::onWindowClose));
		dispatcher.dispatch<WindowResizeEvent>(PE_BIND_EVENT_FN(Application::onWindowResize));

		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
		{
			if (e.Handled)
				break;
			(*it)->onEvent(e);
		}
	}

	void Application::run()
	{
		PE_PROFILE_FUNCTION();

		while (m_Running)
		{
			PE_PROFILE_SCOPE("RunLoop");

			Rendering::RenderCommand::setClearColor({ 0.1f, 0.1f, 0.1f, 1 });
			Rendering::RenderCommand::clear();

			float time = (float)glfwGetTime();
			Time::Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			if (!m_Minimized)
			{
				{
					PE_PROFILE_SCOPE("LayerStack OnUpdate");

					for (Layer* layer : m_LayerStack)
						layer->onUpdate(timestep);
				}

				m_ImGuiLayer->begin();
				{
					PE_PROFILE_SCOPE("LayerStack OnImGuiRender");

					for (Layer* layer : m_LayerStack)
						layer->onImGuiRender();
				}
				m_ImGuiLayer->end();
			}

			m_Window->onUpdate();
		}
	}

	bool Application::onWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	bool Application::onWindowResize(WindowResizeEvent& e)
	{
		if (e.getWidth() == 0 || e.getHeight() == 0)
		{
			m_Minimized = true;
			return false;
		}

		m_Minimized = false;
		Rendering::Renderer::onWindowResize(e.getWidth(), e.getHeight());

		return false;
	}

}