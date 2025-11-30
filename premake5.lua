workspace "PrismEngine"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "PrismEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "PrismEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "PrismEngine/vendor/imgui"
IncludeDir["glm"] = "PrismEngine/vendor/glm"
IncludeDir["stb_image"] = "PrismEngine/vendor/stb_image"

group "Dependencies"
	include "PrismEngine/vendor/GLFW"
	include "PrismEngine/vendor/Glad"
	include "PrismEngine/vendor/imgui"

group ""
project "PrismEngine"
	location "PrismEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pepch.h"
	pchsource "PrismEngine/src/pepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"PE_PLATFORM_WINDOWS",
			"PE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "PE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "PE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "PE_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"PrismEngine/vendor/spdlog/include",
		"PrismEngine/src",
		"PrismEngine/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"PrismEngine"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"PE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "PE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "PE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "PE_DIST"
		runtime "Release"
		optimize "on"
