#pragma once

#include "PrismEngine/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace PrismEngine::Platform::OpenGL
{

	class OpenGLContext : public Renderer::GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void init() override;
		virtual void swapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};

}