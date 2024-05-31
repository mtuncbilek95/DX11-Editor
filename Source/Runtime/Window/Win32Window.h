#pragma once

#include <Runtime/Core/Core.h>
#include <Runtime/Window/Window.h>
#include <Windows.h>
#include <windowsx.h>

namespace Editor
{
	class Win32Window : public WindowLayer
	{
	public:
		Win32Window(const WindowDesc& desc);
		~Win32Window() = default;

		inline HWND GetWindowHandle() const noexcept { return mWindowHandle; }

		virtual void OnUpdate() override;

	private:
		HWND mWindowHandle;

		static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	};
}
