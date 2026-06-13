#pragma once

#include "PrismEngine/Core/Base.h"

#include <Windows.h>
#include <iostream>

void initConsole()
{
#ifdef _DEBUG
	AllocConsole();

	FILE* fp;

	freopen_s(&fp, "CONOUT$", "w", stdout);
	freopen_s(&fp, "CONOUT$", "w", stderr);
	freopen_s(&fp, "CONIN$", "r", stdin);

	std::cout << "Debug console initialized\n";
#endif
}

#ifdef PE_PLATFORM_WINDOWS

extern PrismEngine::App::Application* PrismEngine::App::createApplication();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
	initConsole();

	PrismEngine::Log::init();

	PE_PROFILE_BEGIN_SESSION("Startup", "PrismEngineProfile-Startup.json");
	auto app = PrismEngine::App::createApplication();
	PE_PROFILE_END_SESSION();

	PE_PROFILE_BEGIN_SESSION("Runtime", "PrismEngineProfile-Runtime.json");
	app->run();
	PE_PROFILE_END_SESSION();

	PE_PROFILE_BEGIN_SESSION("Shutdown", "PrismEngineProfile-Shutdown.json");
	delete app;
	PE_PROFILE_END_SESSION();

#ifdef _DEBUG
	FreeConsole();
#endif

	return 0;
}

#endif