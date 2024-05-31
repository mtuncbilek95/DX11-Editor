#pragma once

#include <Runtime/Core/Core.h>

namespace Editor
{
	enum class WindowEventType
	{
		Unknown,
		WindowClose,
		WindowResize,
		WindowMove,
		WindowMinimize,
		WindowMaximize,
		WindowFocus,
		WindowLostFocus,

		KeyPressed,
		KeyReleased,

		MouseLeftPressed,
		MouseLeftReleased,
		MouseRightPressed,
		MouseRightReleased,
		MouseMiddlePressed,
		MouseMiddleReleased,
		MouseMove,
		MouseScroll
	};
}
