#include "pepch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace PrismEngine::Platform::OpenGL
{

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		PE_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		PE_CORE_ASSERT(status, "Failed to initialize Glad!");

		PE_ENGINE_INFO("OpenGL Info:");
		PE_ENGINE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		PE_ENGINE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		PE_ENGINE_INFO("  Version: {0}", glGetString(GL_VERSION));

	}

	void OpenGLContext::swapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}