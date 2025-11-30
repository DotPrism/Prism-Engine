#pragma once

#include "PrismEngine/Renderer/RendererAPI.h"

namespace PrismEngine::Platform::OpenGL
{
	class OpenGLRendererAPI : public Renderer::RendererAPI
	{
	public:
		virtual void init() override;
		virtual void setClearColor(const glm::vec4& color) override;
		virtual void clear() override;

		virtual void drawIndexed(const std::shared_ptr<Renderer::VertexArray>& vertexArray) override;
	};
}
