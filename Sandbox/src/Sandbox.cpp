#include "Sandbox.h"

#include "imgui/imgui.h"

class ExampleLayer : public PrismEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void onUpdate() override
	{
		PE_INFO("ExampleLayer::Update");
		if (PrismEngine::Input::isKeyPressed(PE_KEY_TAB))
			PE_TRACE("Tab key is pressed (poll)!");
	}

	virtual void onImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void onEvent(PrismEngine::Event& event) override
	{
		if (event.getEventType() == PrismEngine::EventType::KeyPressed)
		{
			PrismEngine::KeyPressedEvent& e = (PrismEngine::KeyPressedEvent&)event;
			if (e.getKeyCode() == PE_KEY_TAB)
				PE_TRACE("Tab key is pressed (event)!");
			PE_TRACE("{0}", (char)e.getKeyCode());
		}
	}

};

Sandbox::Sandbox()
{
	pushLayer(new ExampleLayer());
}

Sandbox::~Sandbox()
{

}

PrismEngine::Application* PrismEngine::createApplication()
{
	return new Sandbox();
}
