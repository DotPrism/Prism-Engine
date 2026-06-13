#include "pepch.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

#include <glad/glad.h>

namespace PrismEngine::Platform::OpenGL
{
	static GLenum shaderDataTypeToOpenGLBaseType(Rendering::ShaderDataType type)
	{
		switch (type)
		{
		case Rendering::ShaderDataType::Float:    return GL_FLOAT;
		case Rendering::ShaderDataType::Float2:   return GL_FLOAT;
		case Rendering::ShaderDataType::Float3:   return GL_FLOAT;
		case Rendering::ShaderDataType::Float4:   return GL_FLOAT;
		case Rendering::ShaderDataType::Mat3:     return GL_FLOAT;
		case Rendering::ShaderDataType::Mat4:     return GL_FLOAT;
		case Rendering::ShaderDataType::Int:      return GL_INT;
		case Rendering::ShaderDataType::Int2:     return GL_INT;
		case Rendering::ShaderDataType::Int3:     return GL_INT;
		case Rendering::ShaderDataType::Int4:     return GL_INT;
		case Rendering::ShaderDataType::Bool:     return GL_BOOL;
		}

		PE_CORE_ASSERT(false, "Unknown ShaderDataType!");
		return 0;
	}

	OpenGLVertexArray::OpenGLVertexArray()
	{
		PE_PROFILE_FUNCTION();

		glCreateVertexArrays(1, &m_RendererID);
	}

	OpenGLVertexArray::~OpenGLVertexArray()
	{
		PE_PROFILE_FUNCTION();

		glDeleteVertexArrays(1, &m_RendererID);
	}

	void OpenGLVertexArray::bind() const
	{
		PE_PROFILE_FUNCTION();

		glBindVertexArray(m_RendererID);
	}

	void OpenGLVertexArray::unbind() const
	{
		PE_PROFILE_FUNCTION();

		glBindVertexArray(0);
	}

	void OpenGLVertexArray::addVertexBuffer(const Ref<Rendering::VertexBuffer>& vertexBuffer)
	{
		PE_PROFILE_FUNCTION();

		PE_CORE_ASSERT(vertexBuffer->getLayout().getElements().size(), "Vertex Buffer has no layout!");

		glBindVertexArray(m_RendererID);
		vertexBuffer->bind();

		const auto& layout = vertexBuffer->getLayout();
		for (const auto& element : layout)
		{
			switch (element.Type)
			{
			case Rendering::ShaderDataType::Float:
			case Rendering::ShaderDataType::Float2:
			case Rendering::ShaderDataType::Float3:
			case Rendering::ShaderDataType::Float4:
			{
				glEnableVertexAttribArray(m_VertexBufferIndex);
				glVertexAttribPointer(m_VertexBufferIndex,
					element.getComponentCount(),
					shaderDataTypeToOpenGLBaseType(element.Type),
					element.Normalized ? GL_TRUE : GL_FALSE,
					layout.getStride(),
					(const void*)element.Offset);
				m_VertexBufferIndex++;
				break;
			}
			case Rendering::ShaderDataType::Int:
			case Rendering::ShaderDataType::Int2:
			case Rendering::ShaderDataType::Int3:
			case Rendering::ShaderDataType::Int4:
			case Rendering::ShaderDataType::Bool:
			{
				glEnableVertexAttribArray(m_VertexBufferIndex);
				glVertexAttribIPointer(m_VertexBufferIndex,
					element.getComponentCount(),
					shaderDataTypeToOpenGLBaseType(element.Type),
					layout.getStride(),
					(const void*)element.Offset);
				m_VertexBufferIndex++;
				break;
			}
			case Rendering::ShaderDataType::Mat3:
			case Rendering::ShaderDataType::Mat4:
			{
				uint8_t count = element.getComponentCount();
				for (uint8_t i = 0; i < count; i++)
				{
					glEnableVertexAttribArray(m_VertexBufferIndex);
					glVertexAttribPointer(m_VertexBufferIndex,
						count,
						shaderDataTypeToOpenGLBaseType(element.Type),
						element.Normalized ? GL_TRUE : GL_FALSE,
						layout.getStride(),
						(const void*)(element.Offset + sizeof(float) * count * i));
					glVertexAttribDivisor(m_VertexBufferIndex, 1);
					m_VertexBufferIndex++;
				}
				break;
			}
			default:
				PE_CORE_ASSERT(false, "Unknown ShaderDataType!");
			}
		}

		m_VertexBuffers.push_back(vertexBuffer);
	}

	void OpenGLVertexArray::setIndexBuffer(const Ref<Rendering::IndexBuffer>& indexBuffer)
	{
		PE_PROFILE_FUNCTION();

		glBindVertexArray(m_RendererID);
		indexBuffer->bind();

		m_IndexBuffer = indexBuffer;
	}
}
