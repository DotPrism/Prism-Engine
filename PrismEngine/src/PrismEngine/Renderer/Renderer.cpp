#include "pepch.h"
#include "Renderer.h"

#include "Platform/OpenGL/OpenGLShader.h"

namespace PrismEngine::Renderer
{
	Renderer::SceneData* Renderer::s_SceneData = new Renderer::SceneData;

	void Renderer::init()
	{
		RenderCommand::init();
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