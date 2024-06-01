#pragma once

#include <Runtime/Core/Core.h>
#include <Runtime/Editor/GUIMenuBar/MenuBar.h>
#include <Runtime/Render/RenderModule.h>

namespace Editor
{
	class DockWindow : public RenderModule
	{
	public:
		DockWindow() : RenderModule() 
		{
			mMenuBar = std::make_shared<MenuBar>();
		}
		virtual ~DockWindow() override = default;

		virtual void OnPaint() override;

	private:
		bool mIsDirty = false;
		SharedPtr<MenuBar> mMenuBar;
	};
}
