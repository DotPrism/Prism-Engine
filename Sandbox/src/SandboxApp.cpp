#include <PrismEngine.h>
#include <PrismEngine/Core/EntryPoint.h>

#include "Platform/OpenGL/OpenGLShader.h"

#include "imgui/imgui.h"

#include "Sandbox2D.h"

#include "ExampleLayer.h"

USING_NS_PRISMENGINE_ALL;

class Sandbox : public App::Application
{
public:
	Sandbox()
	{
		pushLayer(new Sandbox2D());
	}

	~Sandbox()
	{
	}
};

App::Application* App::createApplication()
{
	return new Sandbox();
}