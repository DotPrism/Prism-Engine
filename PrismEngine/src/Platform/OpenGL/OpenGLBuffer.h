#pragma once

#include "PrismEngine/Renderer/Buffer.h"

namespace PrismEngine::Platform::OpenGL
{
	class OpenGLVertexBuffer : public Rendering::VertexBuffer
	{
	public:
		OpenGLVertexBuffer(uint32_t size);
		OpenGLVertexBuffer(float* vertices, uint32_t size);
		virtual ~OpenGLVertexBuffer();

		virtual void bind() const override;
		virtual void unbind() const override;

		virtual void setData(const void* data, uint32_t size) override;

		virtual const Rendering::BufferLayout& getLayout() const override { return m_Layout; }
		virtual void setLayout(const Rendering::BufferLayout& layout) override { m_Layout = layout; }
	private:
		uint32_t m_RendererID;
		Rendering::BufferLayout m_Layout;
	};

	class OpenGLIndexBuffer : public Rendering::IndexBuffer
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
