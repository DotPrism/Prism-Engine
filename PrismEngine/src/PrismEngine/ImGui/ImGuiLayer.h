#pragma once

#include "PrismEngine/Core/Layer.h"

#include "PrismEngine/Events/ApplicationEvent.h"
#include "PrismEngine/Events/KeyEvent.h"
#include "PrismEngine/Events/MouseEvent.h"

namespace PrismEngine::ImGuiBackend
{

	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void onAttach() override;
		virtual void onDetach() override;
		virtual void onEvent(Event& e) override;

		void begin();
		void end();

		void blockEvents(bool block) { m_BlockEvents = block; }

		void setDarkThemeColors();
	private:
		float m_Time = 0.0f;
		bool m_BlockEvents = true;
	};

}
