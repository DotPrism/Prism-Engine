workspace "PrismEngine"
	platforms { "x86", "x64" }

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "PrismEngine/vendor/GLFW/include"

include "PrismEngine/vendor/GLFW"

project "PrismEngine"
	location "PrismEngine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pepch.h"
	pchsource "PrismEngine/src/pepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links 
	{ 
		"GLFW",
		"opengl32.lib"
	}

	filter "platforms:x86"
        architecture "x86"

    filter "platforms:x64"
        architecture "x86_64"

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PE_PLATFORM_WINDOWS",
			"PE_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "PE_DEBUG"
		symbols "On"

		defines
		{
			"PE_ENABLE_ASSERTS"
		}

	filter "configurations:Release"
		defines "PE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PE_DIST"
		optimize "On"
		symbols "Off"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

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
		"PrismEngine/src"
	}

	links
	{
		"PrismEngine"
	}

	filter "platforms:x86"
        architecture "x86"

    filter "platforms:x64"
        architecture "x86_64"

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"PE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "PE_DEBUG"
		symbols "On"

		defines
		{
			"PE_ENABLE_ASSERTS"
		}

	filter "configurations:Release"
		defines "PE_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PE_DIST"
		optimize "On"
		symbols "Off"