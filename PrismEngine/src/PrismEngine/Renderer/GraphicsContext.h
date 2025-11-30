#pragma once

namespace PrismEngine::Renderer {

	class GraphicsContext
	{
	public:
		virtual void init() = 0;
		virtual void swapBuffers() = 0;
	};

}