#pragma once

#include <Runtime/Core/Core.h>

namespace Editor
{
	class RenderModule
	{
	public:
		RenderModule() = default;
		virtual ~RenderModule() = default;

		virtual void OnPaint() = 0;
	};
}
