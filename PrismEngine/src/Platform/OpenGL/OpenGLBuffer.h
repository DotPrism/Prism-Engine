#pragma once

#include "PrismEngine/Renderer/Buffer.h"

namespace PrismEngine::Platform::OpenGL
{
	class OpenGLVertexBuffer : public Renderer::VertexBuffer
	{
	public:
		OpenGLVertexBuffer(float* vertices, uint32_t size);
		virtual ~OpenGLVertexBuffer();

		virtual void bind() const override;
		virtual void unbind() const override;

		virtual const Renderer::BufferLayout& getLayout() const override { return m_Layout; }
		virtual void setLayout(const Renderer::BufferLayout& layout) override { m_Layout = layout; }
	private:
		uint32_t m_RendererID;
		Renderer::BufferLayout m_Layout;
	};

	class OpenGLIndexBuffer : public Renderer::IndexBuffer
	{
	public:
		OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
		virtual ~OpenGLIndexBuffer();

		virtual void bind() const;
		virtual void unbind() const;

		virtual uint32_t getCount() const { return m_Count; }
	private:
		uint32_t m_RendererID;
		uint32_t m_Count;
	};
}
