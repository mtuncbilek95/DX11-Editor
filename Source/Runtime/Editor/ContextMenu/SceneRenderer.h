#pragma once

#include <Runtime/Core/Core.h>
#include <Runtime/Render/RenderModule.h>

namespace Editor
{
	class SceneRenderer : public RenderModule
	{
	public:
		SceneRenderer() : RenderModule() { mModuleName = "SceneRenderer"; }
		virtual ~SceneRenderer() = default;

		virtual void OnPaint() override;
	};
}
