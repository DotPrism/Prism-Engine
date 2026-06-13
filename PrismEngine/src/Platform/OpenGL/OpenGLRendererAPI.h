#pragma once

#include "PrismEngine/Renderer/RendererAPI.h"

namespace PrismEngine::Platform::OpenGL
{
	class OpenGLRendererAPI : public Rendering::RendererAPI
	{
	public:
		virtual void init() override;
		virtual void setViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height) override;
		virtual void setClearColor(const glm::vec4& color) override;
		virtual void clear() override;

		virtual void drawIndexed(const Ref<Rendering::VertexArray>& vertexArray, uint32_t indexCount = 0) override;
	};
}
