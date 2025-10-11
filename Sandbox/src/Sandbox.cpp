#include "Sandbox.h"

Sandbox::Sandbox()
{
	PE_INFO("test");
}

Sandbox::~Sandbox()
{

}

PrismEngine::Application* PrismEngine::createApplication()
{
	return new Sandbox();
}
