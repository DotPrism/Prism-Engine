#pragma once

#include "PrismEngine/Core/KeyCodes.h"
#include "PrismEngine/Core/MouseCodes.h"

#include <glm/glm.hpp>

namespace PrismEngine 
{
	class Input
	{
	public:
		static bool isKeyPressed(KeyCode key);
		static bool isMouseButtonPressed(MouseCode button);
		static glm::vec2 getMousePosition();
		static float getMouseX();
		static float getMouseY();
	};

}
