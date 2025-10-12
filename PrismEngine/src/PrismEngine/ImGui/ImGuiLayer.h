#pragma once

#include "PrismEngine/Layer.h"
#include "PrismEngine/Events/MouseEvent.h"
#include "PrismEngine/Events/KeyEvent.h"

namespace PrismEngine 
{

	class PEAPI ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void onAttach() override;
		virtual void onDetach() override;
		virtual void onImGuiRender() override;

		void begin();
		void end();
	private:
		float m_Time = 0.0f;
	};

}