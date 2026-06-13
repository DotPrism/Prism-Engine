#include "pepch.h"
#include "PrismEngine/Renderer/RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace PrismEngine::Rendering
{
	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::create();
}