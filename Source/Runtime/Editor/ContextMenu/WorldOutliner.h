#pragma once

#include <Runtime/Core/Core.h>
#include <Runtime/Render/RenderModule.h>

namespace Editor
{
	class WorldOutliner : public RenderModule
	{
	public:
		WorldOutliner() : RenderModule() { mModuleName = "WorldOutliner"; }
		virtual ~WorldOutliner() = default;

		virtual void OnPaint() override;
	};
}
