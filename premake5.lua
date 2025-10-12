workspace "PrismEngine"
	platforms { "x86", "x64" }
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "PrismEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "PrismEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "PrismEngine/vendor/imgui"
IncludeDir["glm"] = "Hazel/vendor/glm"

include "PrismEngine/vendor/GLFW"
include "PrismEngine/vendor/Glad"
include "PrismEngine/vendor/imgui"

project "PrismEngine"
	location "PrismEngine"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pepch.h"
	pchsource "PrismEngine/src/pepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "platforms:x86"
        architecture "x86"

    filter "platforms:x64"
        architecture "x86_64"

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"PE_PLATFORM_WINDOWS",
			"PE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "PE_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "PE_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "PE_DIST"
		runtime "Release"
		optimize "On"
		symbols "Off"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

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

	filter "platforms:x86"
        architecture "x86"

    filter "platforms:x64"
        architecture "x86_64"

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"PE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "PE_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "PE_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "PE_DIST"
		runtime "Release"
		optimize "On"
		symbols "Off"