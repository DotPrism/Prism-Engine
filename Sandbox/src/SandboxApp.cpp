#include <PrismEngine.h>

#include "Platform/OpenGL/OpenGLShader.h"

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class ExampleLayer : public PrismEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example"), m_CameraController(1280.0f / 720.0f)
	{
		m_VertexArray.reset(PrismEngine::Renderer::VertexArray::create());

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		PrismEngine::Ref<PrismEngine::Renderer::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(PrismEngine::Renderer::VertexBuffer::create(vertices, sizeof(vertices)));
		PrismEngine::Renderer::BufferLayout layout = {
			{ PrismEngine::Renderer::ShaderDataType::Float3, "a_Position" },
			{ PrismEngine::Renderer::ShaderDataType::Float4, "a_Color" }
		};
		vertexBuffer->setLayout(layout);
		m_VertexArray->addVertexBuffer(vertexBuffer);

		uint32_t indices[3] = { 0, 1, 2 };
		PrismEngine::Ref<PrismEngine::Renderer::IndexBuffer> indexBuffer;
		indexBuffer.reset(PrismEngine::Renderer::IndexBuffer::create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->setIndexBuffer(indexBuffer);

		m_SquareVA.reset(PrismEngine::Renderer::VertexArray::create());

		float squareVertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};

		PrismEngine::Ref<PrismEngine::Renderer::VertexBuffer> squareVB;
		squareVB.reset(PrismEngine::Renderer::VertexBuffer::create(squareVertices, sizeof(squareVertices)));
		squareVB->setLayout({
			{ PrismEngine::Renderer::ShaderDataType::Float3, "a_Position" },
			{ PrismEngine::Renderer::ShaderDataType::Float2, "a_TexCoord" }
			});
		m_SquareVA->addVertexBuffer(squareVB);

		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		PrismEngine::Ref<PrismEngine::Renderer::IndexBuffer> squareIB;
		squareIB.reset(PrismEngine::Renderer::IndexBuffer::create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->setIndexBuffer(squareIB);

		auto src = m_ShaderLibrary.load("assets/shaders/Src.glsl");
		auto flatColor = m_ShaderLibrary.load("assets/shaders/FlatColor.glsl");
		auto textureShader = m_ShaderLibrary.load("assets/shaders/Texture.glsl");

		m_Texture = PrismEngine::Renderer::Texture2D::create("assets/textures/Checkerboard.png");
		m_ChernoLogoTexture = PrismEngine::Renderer::Texture2D::create("assets/textures/ChernoLogo.png");

		std::dynamic_pointer_cast<PrismEngine::Platform::OpenGL::OpenGLShader>(textureShader)->bind();
		std::dynamic_pointer_cast<PrismEngine::Platform::OpenGL::OpenGLShader>(textureShader)->uploadUniformInt("u_Texture", 0);;
	}

	void onUpdate(PrismEngine::Time::Timestep ts) override
	{
		// Update
		m_CameraController.onUpdate(ts);

		// Render
		PrismEngine::Renderer::RenderCommand::setClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		PrismEngine::Renderer::RenderCommand::clear();

		PrismEngine::Renderer::Renderer::beginScene(m_CameraController.getCamera());

		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

		auto flatColor = m_ShaderLibrary.get("FlatColor");

		std::dynamic_pointer_cast<PrismEngine::Platform::OpenGL::OpenGLShader>(flatColor)->bind();
		std::dynamic_pointer_cast<PrismEngine::Platform::OpenGL::OpenGLShader>(flatColor)->uploadUniformFloat3("u_Color", m_SquareColor);

		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 50; x++)
			{
				glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
				PrismEngine::Renderer::Renderer::submit(flatColor, m_SquareVA, transform);
			}
		}

		auto textureShader = m_ShaderLibrary.get("Texture");

		m_Texture->bind();
		PrismEngine::Renderer::Renderer::submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
		m_ChernoLogoTexture->bind();
		PrismEngine::Renderer::Renderer::submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

		// Triangle
		// PrismEngine::Renderer::Submit(m_Shader, m_VertexArray);

		PrismEngine::Renderer::Renderer::endScene();
	}

	virtual void onImGuiRender() override
	{
		ImGui::Begin("Settings");
		ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
		ImGui::End();
	}

	void onEvent(PrismEngine::Event& event) override
	{
	}
	private:
		PrismEngine::Renderer::ShaderLibrary m_ShaderLibrary;

		PrismEngine::Ref<PrismEngine::Renderer::VertexArray> m_VertexArray;
		PrismEngine::Ref<PrismEngine::Renderer::VertexArray> m_SquareVA;
		PrismEngine::Ref<PrismEngine::Renderer::Texture2D> m_Texture;
		PrismEngine::Ref<PrismEngine::Renderer::Texture2D> m_ChernoLogoTexture;

		PrismEngine::OrthographicCameraController m_CameraController;

		glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};

class Test : public PrismEngine::Layer
{
public:
		Test()
			: Layer("Test")
		{
		}
		void onImGuiRender() override
		{
			ImGui::Begin("Test");
			ImGui::Text("Hello from Test Layer!");
			ImGui::End();
		}
};

class Sandbox : public PrismEngine::App::Application
{
public:
	Sandbox()
	{
		pushLayer(new ExampleLayer());
		pushOverlay(new Test());
	}

	~Sandbox()
	{

	}

};

PrismEngine::App::Application* PrismEngine::App::createApplication()
{
	auto test = new Sandbox();
	return new Sandbox();
}