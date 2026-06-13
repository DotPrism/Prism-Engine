#pragma once

#include "PrismEngine.h"

USING_NS_PRISMENGINE_ALL;

class Sandbox2D : public Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void onAttach() override;
	virtual void onDetach() override;

	void onUpdate(Timestep ts) override;
	virtual void onImGuiRender() override;
	void onEvent(Event& e) override;
private:
	OrthographicCameraController m_CameraController;

	// Temp
	Ref<VertexArray> m_SquareVA;

	Ref<Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};

