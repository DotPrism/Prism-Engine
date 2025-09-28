#pragma once

#include <stdexcept>
#include <iostream>

#include "Application.h"
#include "Log.h"

extern PrismEngine::Application* createApplication();

int main(int argc, char** argv)
{
	try
	{
		PrismEngine::Log::init();
		PrismEngine::Log::getEngineLogger()->warn("Initialized Log!");
		PrismEngine::Log::getClientLogger()->info("Initialized Log!");

		auto app = PrismEngine::createApplication();
		app->run();
		delete app;
	}
	catch (std::exception* e)
	{
		std::cout << "Caught Unhandled Exception: " << e->what() << std::endl;
	}

	return 0;
}
