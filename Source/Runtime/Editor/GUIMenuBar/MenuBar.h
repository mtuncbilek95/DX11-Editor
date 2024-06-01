#pragma once

#include <Runtime/Core/Core.h>
#include <Runtime/Render/RenderModule.h>

namespace Editor
{
	class MenuBar : public RenderModule
	{
	public:
		MenuBar() = default;
		virtual ~MenuBar() = default;

		void OnPaint() override;
	};
}
