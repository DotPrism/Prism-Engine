#include "pepch.h"
#include "PrismEngine/Renderer/VertexArray.h"

#include "PrismEngine/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLVertexArray.h"

namespace PrismEngine::Rendering
{
	Ref<VertexArray> VertexArray::create()
	{
		switch (Renderer::Renderer::getAPI())
		{
		case RendererAPI::API::None:    PE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return createRef<Platform::OpenGL::OpenGLVertexArray>();
		case RendererAPI::API::Direct3D:    PE_CORE_ASSERT(false, "RendererAPI::Direct3D is currently not supported!"); return nullptr;
		case RendererAPI::API::Vulkan:    PE_CORE_ASSERT(false, "RendererAPI::Vulkan is currently not supported!"); return nullptr;
		}

		PE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}