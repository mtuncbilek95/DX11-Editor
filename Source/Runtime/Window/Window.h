#pragma once

#include <Runtime/Core/Core.h>
#include <Runtime/Event/Event.h>
#include <Runtime/Window/WindowEventType.h>

namespace Editor
{
	struct WindowDesc
	{
		Vector2u WindowSize;
		String WindowTitle;
	};

	using WindowEventBlock = EventDispatcher<EventBase<WindowEventType>>;
	using WindowDelegate = EDelegate<EventBase<WindowEventType>>;

	class WindowLayer
	{
	public:
		static SharedPtr<WindowLayer> Create(const WindowDesc& desc);
	public:
		WindowLayer(const WindowDesc& desc);
		~WindowLayer() = default;

		inline const Vector2u& GetWindowSize() const noexcept { return mWindowSize; }
		inline const Vector2i& GetWindowPosn() const noexcept { return mWindowPosition; }
		inline const String& GetWindowTitle() const noexcept { return mWindowTitle; }

		virtual void OnUpdate() = 0;

		void AddLambda(WindowEventType Type, const WindowDelegate& NewEvent);

	protected:
		void Dispatch(const EventBase<WindowEventType>& DispatchEvent);

		void SetWindowSize(const Vector2u& NewSize) noexcept { mWindowSize = NewSize; }
		void SetWindowPosn(const Vector2i& NewPosn) noexcept { mWindowPosition = NewPosn; }
		void SetWindowTitle(const String& NewTitle) noexcept { mWindowTitle = NewTitle; }

	private:
		Vector2u mWindowSize;
		Vector2i mWindowPosition;
		String mWindowTitle;

		Map<WindowEventType, WindowEventBlock> mWindowEvents;
	};
}
