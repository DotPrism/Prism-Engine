#pragma once

#include "PrismEngine/Renderer/RenderCommand.h"

#include "PrismEngine/Renderer/OrthographicCamera.h"
#include "PrismEngine/Renderer/Shader.h"
#include "PrismEngine/Renderer/VertexArray.h"

namespace PrismEngine::Rendering
{

	class Renderer
	{
	public:
		static void init();
		static void shutdown();

		static void onWindowResize(uint32_t width, uint32_t height);

		static void beginScene(OrthographicCamera& camera);
		static void endScene();

		static void submit(const Ref<Shader>& shader, const Ref<VertexArray>& vertexArray, const glm::mat4& transform = glm::mat4(1.0f));

		inline static RendererAPI::API getAPI() { return RendererAPI::getAPI(); }
	private:
		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
		};

		static Scope<SceneData> s_SceneData;
	};
}