#pragma once

#include <Runtime/Core/Core.h>
#include <Runtime/Event/Event.h>
#include <Runtime/Window/WindowEventType.h>

namespace Editor
{
	// Close Event for Window
	class WindowCloseEvent : public EventBase<WindowEventType>
	{
	public:
		WindowCloseEvent() : EventBase(WindowEventType::WindowClose, "WindowCloseEvent") {}
		~WindowCloseEvent() = default;
	};

	// Resize Event for Window
	class WindowResizeEvent : public EventBase<WindowEventType>
	{
	public:
		WindowResizeEvent(const Vector2u NewSize) : EventBase(WindowEventType::WindowResize, "WindowResizeEvent"),
			mNewSize(NewSize)
		{}
		~WindowResizeEvent() = default;

		inline const Vector2u& GetNewSize() const noexcept { return mNewSize; }

	private:
		Vector2u mNewSize;
	};

	// Move Event for Window
	class WindowMoveEvent : public EventBase<WindowEventType>
	{
	public:
		WindowMoveEvent(const Vector2i NewPosition) : EventBase(WindowEventType::WindowMove, "WindowMoveEvent"),
			mNewPosition(NewPosition)
		{}
		~WindowMoveEvent() = default;

		inline const Vector2i& GetNewPosition() const noexcept { return mNewPosition; }

	private:
		Vector2i mNewPosition;
	};

	// Focus Event for Window
	class WindowFocusEvent : public EventBase<WindowEventType>
	{
	public:
		WindowFocusEvent() : EventBase(WindowEventType::WindowFocus, "WindowFocusEvent") {}
		~WindowFocusEvent() = default;
	};

	// Lost Focus Event for Window
	class WindowLostFocusEvent : public EventBase<WindowEventType>
	{
	public:
		WindowLostFocusEvent() : EventBase(WindowEventType::WindowLostFocus, "WindowLostFocusEvent") {}
		~WindowLostFocusEvent() = default;
	};

	// Maximize Event for Window
	class WindowMaximizeEvent : public EventBase<WindowEventType>
	{
	public:
		WindowMaximizeEvent(const Vector2u& newSize, const Vector2i& newPos) : EventBase(WindowEventType::WindowMaximize, "WindowMaximizeEvent"),
			mNewSize(newSize), mNewPos(newPos) {}
		~WindowMaximizeEvent() = default;

		inline const Vector2u& GetNewSize() const noexcept { return mNewSize; }
		inline const Vector2i& GetNewPos() const noexcept { return mNewPos; }

	private:
		Vector2u mNewSize;
		Vector2i mNewPos;
	};

	// Minimize Event for Window
	class WindowMinimizeEvent : public EventBase<WindowEventType>
	{
	public:
		WindowMinimizeEvent(const Vector2u& newSize, const Vector2i& newPos) : EventBase(WindowEventType::WindowMinimize, "WindowMinimizeEvent"),
			mNewSize(newSize), mNewPos(newPos) {}
		~WindowMinimizeEvent() = default;

		inline const Vector2u& GetNewSize() const noexcept { return mNewSize; }
		inline const Vector2i& GetNewPos() const noexcept { return mNewPos; }

	private:
		Vector2u mNewSize;
		Vector2i mNewPos;
	};

	// Key Pressed Event for Window
	class KeyPressedEvent : public EventBase<WindowEventType>
	{
	public:
		KeyPressedEvent(const u32 KeyCode) : EventBase(WindowEventType::KeyPressed, "KeyPressedEvent"),
			mKeyCode(KeyCode)
		{}
		~KeyPressedEvent() = default;

		inline const u32& GetKeyCode() const noexcept { return mKeyCode; }

	private:
		u32 mKeyCode;
	};

	// Key Released Event for Window
	class KeyReleasedEvent : public EventBase<WindowEventType>
	{
	public:
		KeyReleasedEvent(const u32 KeyCode) : EventBase(WindowEventType::KeyReleased, "KeyReleasedEvent"),
			mKeyCode(KeyCode)
		{}
		~KeyReleasedEvent() = default;

		inline const u32& GetKeyCode() const noexcept { return mKeyCode; }

	private:
		u32 mKeyCode;
	};

	// Mouse Left Pressed Event for Window
	class MouseLeftPressedEvent : public EventBase<WindowEventType>
	{
	public:
		MouseLeftPressedEvent() : EventBase(WindowEventType::MouseLeftPressed, "MouseLeftPressedEvent") {}
		~MouseLeftPressedEvent() = default;
	};

	// Mouse Left Released Event for Window
	class MouseLeftReleasedEvent : public EventBase<WindowEventType>
	{
	public:
		MouseLeftReleasedEvent() : EventBase(WindowEventType::MouseLeftReleased, "MouseLeftReleasedEvent") {}
		~MouseLeftReleasedEvent() = default;
	};

	// Mouse Right Pressed Event for Window
	class MouseRightPressedEvent : public EventBase<WindowEventType>
	{
	public:
		MouseRightPressedEvent() : EventBase(WindowEventType::MouseRightPressed, "MouseRightPressedEvent") {}
		~MouseRightPressedEvent() = default;
	};

	// Mouse Right Released Event for Window
	class MouseRightReleasedEvent : public EventBase<WindowEventType>
	{
	public:
		MouseRightReleasedEvent() : EventBase(WindowEventType::MouseRightReleased, "MouseRightReleasedEvent") {}
		~MouseRightReleasedEvent() = default;
	};

	// Mouse Middle Pressed Event for Window
	class MouseMiddlePressedEvent : public EventBase<WindowEventType>
	{
	public:
		MouseMiddlePressedEvent() : EventBase(WindowEventType::MouseMiddlePressed, "MouseMiddlePressedEvent") {}
		~MouseMiddlePressedEvent() = default;
	};

	// Mouse Middle Released Event for Window
	class MouseMiddleReleasedEvent : public EventBase<WindowEventType>
	{
	public:
		MouseMiddleReleasedEvent() : EventBase(WindowEventType::MouseMiddleReleased, "MouseMiddleReleasedEvent") {}
		~MouseMiddleReleasedEvent() = default;
	};

	// Mouse Move Event for Window
	class MouseMoveEvent : public EventBase<WindowEventType>
	{
	public:
		MouseMoveEvent(const Vector2i& NewPos) : EventBase(WindowEventType::MouseMove, "MouseMoveEvent"),
			mNewPos(NewPos)
		{}
		~MouseMoveEvent() = default;

		inline const Vector2i& GetNewPos() const noexcept { return mNewPos; }

	private:
		Vector2i mNewPos;
	};
}
