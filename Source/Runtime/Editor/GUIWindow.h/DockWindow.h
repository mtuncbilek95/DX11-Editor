#pragma once

#include <Runtime/Core/Core.h>
#include <Runtime/Render/RenderModule.h>

namespace Editor
{
	class DockWindow : public RenderModule
	{
	public:
		DockWindow() : RenderModule() {}
		virtual ~DockWindow() override = default;

		virtual void OnPaint() override;

	private:
		bool mIsDirty = false;
	};
}
