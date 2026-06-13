#include "pepch.h"
#include "Platform/OpenGL/OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace PrismEngine::Platform::OpenGL
{

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		PE_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::init()
	{
		PE_PROFILE_FUNCTION();

		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		PE_CORE_ASSERT(status, "Failed to initialize Glad!");

		PE_CORE_INFO("OpenGL Info:");
		PE_CORE_INFO("  Vendor: {0}", glGetString(GL_VENDOR));
		PE_CORE_INFO("  Renderer: {0}", glGetString(GL_RENDERER));
		PE_CORE_INFO("  Version: {0}", glGetString(GL_VERSION));

		PE_CORE_ASSERT(GLVersion.major > 4 || (GLVersion.major == 4 && GLVersion.minor >= 5), "PrismEngine requires at least OpenGL version 4.5!");
	}

	void OpenGLContext::swapBuffers()
	{
		PE_PROFILE_FUNCTION();

		glfwSwapBuffers(m_WindowHandle);
	}
}
