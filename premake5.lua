include "./vendor/premake/premake_customization/solution_items.lua"

workspace "PrismEngine"
	architecture "x86_64"
	startproject "PrismEngine-Editor"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/PrismEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/PrismEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/PrismEngine/vendor/imgui"
IncludeDir["glm"] = "%{wks.location}/PrismEngine/vendor/glm"
IncludeDir["stb_image"] = "%{wks.location}/PrismEngine/vendor/stb_image"
IncludeDir["entt"] = "%{wks.location}/PrismEngine/vendor/entt/include"
IncludeDir["yaml_cpp"] = "%{wks.location}/PrismEngine/vendor/yaml-cpp/include"
IncludeDir["ImGuizmo"] = "%{wks.location}/PrismEngine/vendor/ImGuizmo"

group "Dependencies"
	include "vendor/premake"
	include "PrismEngine/vendor/GLFW"
	include "PrismEngine/vendor/Glad"
	include "PrismEngine/vendor/imgui"
	include "PrismEngine/vendor/yaml-cpp"

group "Engine"
	include "PrismEngine"
group "Apps"
	include "Sandbox"
	include "PrismEngine-Editor"
