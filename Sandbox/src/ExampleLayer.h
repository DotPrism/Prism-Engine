#pragma once

#include "PrismEngine.h"

USING_NS_PRISMENGINE_ALL;

class ExampleLayer : public Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void onAttach() override;
	virtual void onDetach() override;

	void onUpdate(Timestep ts) override;
	virtual void onImGuiRender() override;
	void onEvent(Event& e) override;
private:
	ShaderLibrary m_ShaderLibrary;
	Ref<Shader> m_Shader;
	Ref<VertexArray> m_VertexArray;

	Ref<Shader> m_FlatColorShader;
	Ref<VertexArray> m_SquareVA;

	Ref<Texture2D> m_Texture, m_ChernoLogoTexture;

	OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};