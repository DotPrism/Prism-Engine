#pragma once

#include "PrismEngine/Core/Core.h"
#include "PrismEngine/Core/Timestep.h"
#include "PrismEngine/Events/Event.h"

namespace PrismEngine {

	class PEAPI Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void onAttach() {}
		virtual void onDetach() {}
		virtual void onUpdate(Time::Timestep ts) {}
		virtual void onImGuiRender() {}
		virtual void onEvent(Event& event) {}

		inline const std::string& getName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}