#pragma once

#include "PrismEngine/Core/Layer.h"

#include "PrismEngine/Events/ApplicationEvent.h"
#include "PrismEngine/Events/KeyEvent.h"
#include "PrismEngine/Events/MouseEvent.h"

namespace PrismEngine::ImGuiBackend
{

	class PEAPI ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void onAttach() override;
		virtual void onDetach() override;
		virtual void onImGuiRender() override;

		void begin();
		void end();
	private:
		float m_Time = 0.0f;
	};

}