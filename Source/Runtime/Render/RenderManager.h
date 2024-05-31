#pragma once

#include <Runtime/Core/Core.h>
#include <Runtime/Render/Renderer.h>

namespace Editor
{
	class RenderManager
	{
	public:
		RenderManager() = default;
		virtual ~RenderManager() = default;

		static RenderManager& GetInstance() noexcept
		{
			static RenderManager instance;
			return instance;
		}

		SharedPtr<Renderer> Create(const RendererDesc& desc)
		{
			if(!mRenderer)
				mRenderer = std::make_shared<Renderer>(desc);

			return mRenderer;
		}

		SharedPtr<Renderer> GetRenderer() const noexcept
		{
			return mRenderer;
		}

	private:
		SharedPtr<Renderer> mRenderer;
	};
}
