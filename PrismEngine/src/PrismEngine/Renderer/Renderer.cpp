#include "pepch.h"
#include "PrismEngine/Renderer/Renderer.h"
#include "PrismEngine/Renderer/Renderer2D.h"

#include "Platform/OpenGL/OpenGLShader.h"

namespace PrismEngine::Rendering
{
	Scope<Renderer::SceneData> Renderer::s_SceneData = createScope<Renderer::SceneData>();

	void Renderer::init()
	{
		PE_PROFILE_FUNCTION();

		RenderCommand::init();
		Renderer2D::init();
	}

	void Renderer::shutdown()
	{
		Renderer2D::shutdown();
	}

	void Renderer::onWindowResize(uint32_t width, uint32_t height)
	{
		RenderCommand::setViewport(0, 0, width, height);
	}

	void Renderer::beginScene(OrthographicCamera& camera)
	{
		s_SceneData->ViewProjectionMatrix = camera.getViewProjectionMatrix();
	}

	void Renderer::endScene()
	{
	}

	void Renderer::submit(const std::shared_ptr<Shader>& shader, const std::shared_ptr<VertexArray>& vertexArray, const glm::mat4& transform)
	{
		shader->bind();
		std::dynamic_pointer_cast<Platform::OpenGL::OpenGLShader>(shader)->uploadUniformMat4("u_ViewProjection", s_SceneData->ViewProjectionMatrix);
		std::dynamic_pointer_cast<Platform::OpenGL::OpenGLShader>(shader)->uploadUniformMat4("u_Transform", transform);

		vertexArray->bind();
		RenderCommand::drawIndexed(vertexArray);
	}
}