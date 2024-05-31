#include "Window.h"

#include <Runtime/Window/WindowEvents.h>
#include <Runtime/Window/Win32Window.h>

namespace Editor
{
	SharedPtr<WindowLayer> WindowLayer::Create(const WindowDesc& desc)
	{
		return std::make_shared<Win32Window>(desc);
	}

	WindowLayer::WindowLayer(const WindowDesc& desc) : mWindowSize(desc.WindowSize), mWindowTitle(desc.WindowTitle),
		mWindowPosition({0,0})
	{
	}
	void WindowLayer::AddLambda(WindowEventType Type, const WindowDelegate& NewEvent)
	{
		mWindowEvents[Type].AddListener(NewEvent);
	}
	void WindowLayer::Dispatch(const EventBase<WindowEventType>& DispatchEvent)
	{
		switch (DispatchEvent.GetType())
		{
		case WindowEventType::WindowClose:
			mWindowEvents[WindowEventType::WindowClose].Dispatch(static_cast<const WindowCloseEvent&>(DispatchEvent));
			break;
		case WindowEventType::WindowResize:
			mWindowEvents[WindowEventType::WindowResize].Dispatch(static_cast<const WindowResizeEvent&>(DispatchEvent));
			break;
		case WindowEventType::WindowMove:
			mWindowEvents[WindowEventType::WindowMove].Dispatch(static_cast<const WindowMoveEvent&>(DispatchEvent));
			break;
		case WindowEventType::WindowFocus:
			mWindowEvents[WindowEventType::WindowFocus].Dispatch(static_cast<const WindowFocusEvent&>(DispatchEvent));
			break;
		case WindowEventType::WindowLostFocus:
			mWindowEvents[WindowEventType::WindowLostFocus].Dispatch(static_cast<const WindowLostFocusEvent&>(DispatchEvent));
			break;
		case WindowEventType::WindowMaximize:
			mWindowEvents[WindowEventType::WindowMaximize].Dispatch(static_cast<const WindowMaximizeEvent&>(DispatchEvent));
			break;
		case WindowEventType::WindowMinimize:
			mWindowEvents[WindowEventType::WindowMinimize].Dispatch(static_cast<const WindowMinimizeEvent&>(DispatchEvent));
			break;
		case WindowEventType::MouseLeftPressed:
			mWindowEvents[WindowEventType::MouseLeftPressed].Dispatch(static_cast<const MouseLeftPressedEvent&>(DispatchEvent));
			break;
		case WindowEventType::MouseLeftReleased:
			mWindowEvents[WindowEventType::MouseLeftReleased].Dispatch(static_cast<const MouseLeftReleasedEvent&>(DispatchEvent));
			break;
		case WindowEventType::MouseRightPressed:
			mWindowEvents[WindowEventType::MouseRightPressed].Dispatch(static_cast<const MouseRightPressedEvent&>(DispatchEvent));
			break;
		case WindowEventType::MouseRightReleased:
			mWindowEvents[WindowEventType::MouseRightReleased].Dispatch(static_cast<const MouseRightReleasedEvent&>(DispatchEvent));
			break;
		case WindowEventType::MouseMiddlePressed:
			mWindowEvents[WindowEventType::MouseMiddlePressed].Dispatch(static_cast<const MouseMiddlePressedEvent&>(DispatchEvent));
			break;
		case WindowEventType::MouseMiddleReleased:
			mWindowEvents[WindowEventType::MouseMiddleReleased].Dispatch(static_cast<const MouseMiddleReleasedEvent&>(DispatchEvent));
			break;
		case WindowEventType::MouseMove:
			mWindowEvents[WindowEventType::MouseMove].Dispatch(static_cast<const MouseMoveEvent&>(DispatchEvent));
			break;
		case WindowEventType::KeyPressed:
			mWindowEvents[WindowEventType::KeyPressed].Dispatch(static_cast<const KeyPressedEvent&>(DispatchEvent));
			break;
		case WindowEventType::KeyReleased:
			mWindowEvents[WindowEventType::KeyReleased].Dispatch(static_cast<const KeyReleasedEvent&>(DispatchEvent));
			break;
		default:
			break;
		}
	}
}