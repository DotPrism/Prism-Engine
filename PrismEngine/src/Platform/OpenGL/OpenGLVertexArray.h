#pragma once
#include "PrismEngine/Renderer/VertexArray.h"

namespace PrismEngine::Platform::OpenGL
{
	class OpenGLVertexArray : public Renderer::VertexArray
	{
	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		virtual void bind() const override;
		virtual void unbind() const override;

		virtual void addVertexBuffer(const std::shared_ptr<Renderer::VertexBuffer>& vertexBuffer) override;
		virtual void setIndexBuffer(const std::shared_ptr<Renderer::IndexBuffer>& indexBuffer) override;

		virtual const std::vector<std::shared_ptr<Renderer::VertexBuffer>>& getVertexBuffers() const { return m_VertexBuffers; }
		virtual const std::shared_ptr<Renderer::IndexBuffer>& getIndexBuffer() const { return m_IndexBuffer; }
	private:
		uint32_t m_RendererID;
		uint32_t m_VertexBufferIndex = 0;
		std::vector<std::shared_ptr<Renderer::VertexBuffer>> m_VertexBuffers;
		std::shared_ptr<Renderer::IndexBuffer> m_IndexBuffer;
	};
}
