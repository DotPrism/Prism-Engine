#pragma once

#include "PrismEngine/Renderer/Framebuffer.h"

namespace PrismEngine::Platform::OpenGL 
{

	class OpenGLFramebuffer : public Rendering::Framebuffer
	{
	public:
		OpenGLFramebuffer(const Rendering::FramebufferSpecification& spec);
		virtual ~OpenGLFramebuffer();

		void invalidate();

		virtual void bind() override;
		virtual void unbind() override;

		virtual void resize(uint32_t width, uint32_t height) override;
		virtual int readPixel(uint32_t attachmentIndex, int x, int y) override;

		virtual void clearAttachment(uint32_t attachmentIndex, int value) override;

		virtual uint32_t getColorAttachmentRendererID(uint32_t index = 0) const override { PE_CORE_ASSERT(index < m_ColorAttachments.size(), ""); return m_ColorAttachments[index]; }

		virtual const Rendering::FramebufferSpecification& getSpecification() const override { return m_Specification; }
	private:
		uint32_t m_RendererID = 0;
		Rendering::FramebufferSpecification m_Specification;
		std::vector<Rendering::FramebufferTextureSpecification> m_ColorAttachmentSpecifications;
		Rendering::FramebufferTextureSpecification m_DepthAttachmentSpecification = Rendering::FramebufferTextureFormat::None;

		std::vector<uint32_t> m_ColorAttachments;
		uint32_t m_DepthAttachment = 0;
	};

}
