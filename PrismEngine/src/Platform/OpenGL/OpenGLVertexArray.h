#pragma once
#include "PrismEngine/Renderer/VertexArray.h"

namespace PrismEngine::Platform::OpenGL
{
	class OpenGLVertexArray : public Rendering::VertexArray
	{
	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		virtual void bind() const override;
		virtual void unbind() const override;

		virtual void addVertexBuffer(const Ref<Rendering::VertexBuffer>& vertexBuffer) override;
		virtual void setIndexBuffer(const Ref<Rendering::IndexBuffer>& indexBuffer) override;

		virtual const std::vector<Ref<Rendering::VertexBuffer>>& getVertexBuffers() const { return m_VertexBuffers; }
		virtual const Ref<Rendering::IndexBuffer>& getIndexBuffer() const { return m_IndexBuffer; }
	private:
		uint32_t m_RendererID;
		uint32_t m_VertexBufferIndex = 0;
		std::vector<Ref<Rendering::VertexBuffer>> m_VertexBuffers;
		Ref<Rendering::IndexBuffer> m_IndexBuffer;
	};
}
