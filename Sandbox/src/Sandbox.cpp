#include "Sandbox.h"
#include <iostream>

Sandbox::Sandbox()
{
	PE_CLIENT_INFO("test");
}

Sandbox::~Sandbox()
{

}

PrismEngine::Application* PrismEngine::createApplication()
{
	return new Sandbox();
}
