#include "pepch.h"
#include "Shader.h"

#include <glad/glad.h>

#include "Renderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace PrismEngine::Renderer
{
	Ref<Shader> Shader::create(const std::string& filepath)
	{
		switch (Renderer::getAPI())
		{
		case RendererAPI::API::None:    PE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return std::make_shared<Platform::OpenGL::OpenGLShader>(filepath);
		case RendererAPI::API::Direct3D:    PE_CORE_ASSERT(false, "RendererAPI::Direct3D is currently not supported!"); return nullptr;
		case RendererAPI::API::Vulkan:    PE_CORE_ASSERT(false, "RendererAPI::Vulkan is currently not supported!"); return nullptr;
		}

		PE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	Ref<Shader> Shader::create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc)
	{
		switch (Renderer::getAPI())
		{
		case RendererAPI::API::None:    PE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return std::make_shared<Platform::OpenGL::OpenGLShader>(name, vertexSrc, fragmentSrc);
		case RendererAPI::API::Direct3D:    PE_CORE_ASSERT(false, "RendererAPI::Direct3D is currently not supported!"); return nullptr;
		case RendererAPI::API::Vulkan:    PE_CORE_ASSERT(false, "RendererAPI::Vulkan is currently not supported!"); return nullptr;
		}

		PE_CORE_ASSERT(false, "Unknown RendererAPI!");

		return nullptr;
	}

	void ShaderLibrary::add(const std::string& name, const Ref<Shader>& shader)
	{
		PE_CORE_ASSERT(!exists(name), "Shader already exists!");
		m_Shaders[name] = shader;
	}

	void ShaderLibrary::add(const Ref<Shader>& shader)
	{
		auto& name = shader->getName();
		add(name, shader);
	}

	Ref<PrismEngine::Renderer::Shader> ShaderLibrary::load(const std::string& filepath)
	{
		auto shader = Shader::create(filepath);
		add(shader);
		return shader;
	}

	Ref<Shader> ShaderLibrary::load(const std::string& name, const std::string& filepath)
	{
		auto shader = Shader::create(filepath);
		add(name, shader);
		return shader;
	}

	Ref<Shader> ShaderLibrary::get(const std::string& name)
	{
		PE_CORE_ASSERT(exists(name), "Shader not found!");
		return m_Shaders[name];
	}

	bool ShaderLibrary::exists(const std::string& name) const
	{
		return m_Shaders.find(name) != m_Shaders.end();
	}
}
