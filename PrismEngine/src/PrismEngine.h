#pragma once

// For use by PrismEngine applications

#define USING_NS_PRISMENGINE using namespace PrismEngine;

#define USING_NS_PRISMENGINE_ALL using namespace PrismEngine; \
	using namespace PrismEngine::Rendering; \
	using namespace PrismEngine::Time; \
	using namespace PrismEngine::Scene; \

#include "PrismEngine/Core/Base.h"

#include "PrismEngine/Core/Timestep.h"

#include "PrismEngine/Core/Application.h"
#include "PrismEngine/Core/Layer.h"
#include "PrismEngine/Core/Log.h"
#include "PrismEngine/Core/Assert.h"

#include "PrismEngine/Core/Input.h"
#include "PrismEngine/Core/KeyCodes.h"
#include "PrismEngine/Core/MouseCodes.h"
#include "PrismEngine/Renderer/OrthographicCameraController.h"

#include "PrismEngine/ImGui/ImGuiLayer.h"

#include "PrismEngine/Scene/Scene.h"
#include "PrismEngine/Scene/Components.h"
#include "PrismEngine/Scene/Entity.h"

// ---Renderer------------------------
#include "PrismEngine/Renderer/Renderer.h"
#include "PrismEngine/Renderer/Renderer2D.h"
#include "PrismEngine/Renderer/RenderCommand.h"

#include "PrismEngine/Renderer/Buffer.h"
#include "PrismEngine/Renderer/Shader.h"
#include "PrismEngine/Renderer/Texture.h"
#include "PrismEngine/Renderer/Framebuffer.h"
#include "PrismEngine/Renderer/VertexArray.h"

#include "PrismEngine/Renderer/OrthographicCamera.h"
// -----------------------------------
