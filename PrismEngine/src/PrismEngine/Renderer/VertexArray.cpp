#include "pepch.h"
#include "VertexArray.h"

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace PrismEngine::Renderer
{
	VertexArray* VertexArray::create()
	{
		switch (Renderer::Renderer::getAPI())
		{
		case RendererAPI::API::None:    PE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return new Platform::OpenGL::OpenGLVertexArray();
		case RendererAPI::API::Direct3D:    PE_CORE_ASSERT(false, "RendererAPI::Direct3D is currently not supported!"); return nullptr;
		case RendererAPI::API::Vulkan:    PE_CORE_ASSERT(false, "RendererAPI::Vulkan is currently not supported!"); return nullptr;
		}

		PE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}