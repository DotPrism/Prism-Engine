#pragma once

#include "PrismEngine/Renderer/OrthographicCamera.h"
#include "PrismEngine/Core/Timestep.h"

#include "PrismEngine/Events/ApplicationEvent.h"
#include "PrismEngine/Events/MouseEvent.h"

namespace PrismEngine {

	class OrthographicCameraController
	{
	public:
		OrthographicCameraController(float aspectRatio, bool rotation = false);

		void onUpdate(Time::Timestep ts);
		void onEvent(Event& e);

		void onResize(float width, float height);

		Rendering::OrthographicCamera& getCamera() { return m_Camera; }
		const Rendering::OrthographicCamera& getCamera() const { return m_Camera; }

		inline void setMoveWithKeys(bool canMove) { m_CanMoveWithKeys = canMove; }
	private:
		bool onMouseScrolled(MouseScrolledEvent& e);
		bool onWindowResized(WindowResizeEvent& e);
	private:
		float m_AspectRatio;
		float m_ZoomLevel = 1.0f;
		Rendering::OrthographicCamera m_Camera;

		bool m_Rotation;
		bool m_CanMoveWithKeys;

		glm::vec3 m_CameraPosition = { 0.0f, 0.0f, 0.0f };
		float m_CameraRotation = 0.0f;
		float m_CameraTranslationSpeed = 5.0f, m_CameraRotationSpeed = 180.0f;
	};

}
