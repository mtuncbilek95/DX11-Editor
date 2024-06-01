#pragma once

#include <Runtime/Core/Core.h>
#include <Runtime/Render/RenderModule.h>

namespace Editor
{
	class ContentBrowser : public RenderModule
	{
	public:
		ContentBrowser() : RenderModule() { mModuleName = "ContentBrowser"; }
		virtual ~ContentBrowser() = default;

		virtual void OnPaint() override;
	};
}
