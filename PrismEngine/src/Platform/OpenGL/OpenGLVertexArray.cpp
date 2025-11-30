#include "pepch.h"
#include "OpenGLVertexArray.h"

#include <glad/glad.h>

namespace PrismEngine::Platform::OpenGL
{
	static GLenum shaderDataTypeToOpenGLBaseType(Renderer::ShaderDataType type)
	{
		switch (type)
		{
		case Renderer::ShaderDataType::Float:    return GL_FLOAT;
		case Renderer::ShaderDataType::Float2:   return GL_FLOAT;
		case Renderer::ShaderDataType::Float3:   return GL_FLOAT;
		case Renderer::ShaderDataType::Float4:   return GL_FLOAT;
		case Renderer::ShaderDataType::Mat3:     return GL_FLOAT;
		case Renderer::ShaderDataType::Mat4:     return GL_FLOAT;
		case Renderer::ShaderDataType::Int:      return GL_INT;
		case Renderer::ShaderDataType::Int2:     return GL_INT;
		case Renderer::ShaderDataType::Int3:     return GL_INT;
		case Renderer::ShaderDataType::Int4:     return GL_INT;
		case Renderer::ShaderDataType::Bool:     return GL_BOOL;
		}

		PE_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		glCreateVertexArrays(1, &m_RendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::bind() const
	{
		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::unbind() const
	{
		glBindVertexArray(0);
	}

	void OpenGLVertexArray::addVertexBuffer(const std::shared_ptr<Renderer::VertexBuffer>& vertexBuffer)
	{
		PE_CORE_ASSERT(vertexBuffer->getLayout().getElements().size(), "Vertex Buffer has no layout!");

		glBindVertexArray(m_RendererID);
		vertexBuffer->bind();

		const auto& layout = vertexBuffer->getLayout();
		for (const auto& element : layout)
		{
			glEnableVertexAttribArray(m_VertexBufferIndex);
			glVertexAttribPointer(m_VertexBufferIndex,
				element.getComponentCount(),
				shaderDataTypeToOpenGLBaseType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*)(intptr_t)element.Offset);
			m_VertexBufferIndex++;
		}

		m_VertexBuffers.push_back(vertexBuffer);
	}

	void OpenGLVertexArray::setIndexBuffer(const std::shared_ptr<Renderer::IndexBuffer>& indexBuffer)
	{
		glBindVertexArray(m_RendererID);
		indexBuffer->bind();

		m_IndexBuffer = indexBuffer;
	}
}
