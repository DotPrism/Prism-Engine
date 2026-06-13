#pragma once

#include "Entity.h"

namespace PrismEngine::Scene 
{
	class ScriptableEntity
	{
	public:
		virtual ~ScriptableEntity() {}

		template<typename T>
		T& getComponent()
		{
			return m_Entity.getComponent<T>();
		}
	protected:
		virtual void onCreate() {}
		virtual void onDestroy() {}
		virtual void onUpdate(Time::Timestep ts) {}
	private:
		Entity m_Entity;
		friend class Scene;
	};
}
