#pragma once

#include <stdexcept>
#include <iostream>

#include "Application.h"

extern PrismEngine::Application* createApplication();

int main(int argc, char** argv)
{
	try
	{
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
