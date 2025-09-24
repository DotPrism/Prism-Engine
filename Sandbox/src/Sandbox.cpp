#include "Sandbox.h"

Sandbox::Sandbox()
{

}

Sandbox::~Sandbox()
{

}

PrismEngine::Application* PrismEngine::createApplication()
{
	return new Sandbox();
}
