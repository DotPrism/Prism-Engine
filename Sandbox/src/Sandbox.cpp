#include <PrismEngine.h>

class Sandbox : public PrismEngine::Application
{
public:
	Sandbox()
	{
		
	}

	~Sandbox() 
	{
	}
};

PrismEngine::Application* PrismEngine::createApplication()
{
	return new Sandbox();
}