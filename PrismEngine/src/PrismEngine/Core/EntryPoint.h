#pragma once

#ifdef PE_PLATFORM_WINDOWS

extern PrismEngine::App::Application* PrismEngine::App::createApplication();

int main(int argc, char** argv)
{
	PrismEngine::Log::init();

	auto app = PrismEngine::App::createApplication();
	app->run();
	delete app;
}

#endif