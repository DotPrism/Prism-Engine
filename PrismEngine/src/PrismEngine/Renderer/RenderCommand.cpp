#include "pepch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace PrismEngine::Renderer
{
	RendererAPI* RenderCommand::s_RendererAPI = new Platform::OpenGL::OpenGLRendererAPI;
}