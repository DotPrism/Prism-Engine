#include <PrismEngine.h>
#include <PrismEngine/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace PrismEngine 
{

	class PrismEngineEditor : public App::Application
	{
	public:
		PrismEngineEditor()
			: App::Application("PrismEngine Editor")
		{
			pushLayer(new EditorLayer());
		}

		~PrismEngineEditor()
		{
		}
	};

	App::Application* App::createApplication()
	{
		auto app = new PrismEngineEditor();

		app->get().getWindow().setVSync(true);

		return app;
	}

}
