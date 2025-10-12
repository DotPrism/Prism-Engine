#pragma once

#include "PrismEngine/Core.h"
#include "PrismEngine/Events/Event.h"

namespace PrismEngine 
{

	class PEAPI Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void onAttach() {}
		virtual void onDetach() {}
		virtual void onUpdate() {}
		virtual void onImGuiRender() {}
		virtual void onEvent(Event& event) {}

		inline const std::string& getName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}
