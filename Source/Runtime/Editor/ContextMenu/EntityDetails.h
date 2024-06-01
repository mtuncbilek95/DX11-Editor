#pragma once

#include <Runtime/Core/Core.h>
#include <Runtime/Render/RenderModule.h>

namespace Editor
{
	class EntityDetails : public RenderModule
	{
	public:
		EntityDetails() : RenderModule() { mModuleName = "EntityDetails"; }
		virtual ~EntityDetails() = default;

		virtual void OnPaint() override;
	};
}