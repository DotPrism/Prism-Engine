#include "pepch.h"
#include "PrismEngine/Renderer/GraphicsContext.h"

#include "PrismEngine/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace PrismEngine::Rendering
{

	Scope<GraphicsContext> GraphicsContext::create(void* window)
	{
		switch (Renderer::getAPI())
		{
		case RendererAPI::API::None:    PE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return createScope<Platform::OpenGL::OpenGLContext>(static_cast<GLFWwindow*>(window));
		case RendererAPI::API::Direct3D:    PE_CORE_ASSERT(false, "RendererAPI::Direct3D is currently not supported!"); return nullptr;
		case RendererAPI::API::Vulkan:    PE_CORE_ASSERT(false, "RendererAPI::Vulkan is currently not supported!"); return nullptr;
		}

		PE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}