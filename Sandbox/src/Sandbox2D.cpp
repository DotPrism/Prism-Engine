#include "Sandbox2D.h"
#include <imgui/imgui.h>

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Platform/OpenGL/OpenGLShader.h"

#include <chrono>

USING_NS_PRISMENGINE_ALL;

Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f), m_SquareColor({ 0.2f, 0.3f, 0.8f, 1.0f })
{
}

void Sandbox2D::onAttach()
{
	PE_PROFILE_FUNCTION();

	m_CheckerboardTexture = Texture2D::create("assets/textures/Checkerboard.png");

	m_CameraController.setMoveWithKeys(true);
}

void Sandbox2D::onDetach()
{
	PE_PROFILE_FUNCTION();
}

void Sandbox2D::onUpdate(Timestep ts)
{
	PE_PROFILE_SCOPE("Sandbox2D::OnUpdate");
	
	m_CameraController.onUpdate(ts);

	// Render
	{
		PE_PROFILE_SCOPE("Renderer Prep");
		RenderCommand::setClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		RenderCommand::clear();
	}

	{
		static float rotation = 0.0f;
		rotation += ts * 50.0f;

		PE_PROFILE_SCOPE("Renderer Draw");

		Renderer2D::beginScene(m_CameraController.getCamera());
		Renderer2D::drawRotatedQuad({ 1.0f, 0.0f }, { 0.8f, 0.8f }, -45.0f, { 0.8f, 0.2f, 0.3f, 1.0f });
		Renderer2D::drawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
		Renderer2D::drawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, m_SquareColor);
		Renderer2D::drawQuad({ 0.0f, 0.0f, -0.1f }, { 20.0f, 20.0f }, m_CheckerboardTexture, 10.0f);
		Renderer2D::drawRotatedQuad({ -2.0f, 0.0f, 0.0f }, { 1.0f, 1.0f }, rotation, m_CheckerboardTexture, 20.0f);
		
		Renderer2D::endScene();

		Renderer2D::beginScene(m_CameraController.getCamera());
		for (float y = -5.0f; y < 5.0f; y += 0.5f)
		{
			for (float x = -5.0f; x < 5.0f; x += 0.5f)
			{
				glm::vec4 color = { (x + 5.0f) / 10.0f, 0.4f, (y + 5.0f) / 10.0f, 0.7f };
				Renderer2D::drawQuad({ x, y }, { 0.45f, 0.45f }, color);
			}
		}
		Renderer2D::endScene();
	}
}

void Sandbox2D::onImGuiRender()
{
	PE_PROFILE_FUNCTION();

	ImGui::Begin("Settings");
	auto stats = Renderer2D::getStats();
	ImGui::Text("Renderer2D Stats:");
	ImGui::Text("Draw Calls: %d", stats.DrawCalls);
	ImGui::Text("Quads: %d", stats.QuadCount);
	ImGui::Text("Vertices: %d", stats.getTotalVertexCount());
	ImGui::Text("Indices: %d", stats.getTotalIndexCount());
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::onEvent(PrismEngine::Event& e)
{
	m_CameraController.onEvent(e);
}
