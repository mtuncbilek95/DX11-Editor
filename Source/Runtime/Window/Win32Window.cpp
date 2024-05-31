#include "Win32Window.h"

#include <Runtime/Window/WindowEvents.h>

#include <backends/imgui_impl_win32.h>

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace Editor
{
	Win32Window* GetWindowUserData(HWND hWnd)
	{
		return (Win32Window*)GetWindowLongPtr(hWnd, -21);
	}

	Win32Window::Win32Window(const WindowDesc& desc)
		: WindowLayer(desc)
	{
		const char className[] = "HollowWin32WindowClass";
		WNDCLASSEX windowClass = {};
		windowClass.cbSize = sizeof(windowClass);
		windowClass.hInstance = nullptr;
		windowClass.cbClsExtra = 0;
		windowClass.cbWndExtra = sizeof(Win32Window*);
		windowClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
		windowClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
		windowClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		windowClass.lpszMenuName = NULL;
		windowClass.lpszClassName = className;
		windowClass.lpfnWndProc = WndProc;

		RegisterClassEx(&windowClass);

		int screenWidth = GetSystemMetrics(SM_CXSCREEN);
		int screenHeight = GetSystemMetrics(SM_CYSCREEN);

		Vector2i center = { (screenWidth - (i32)desc.WindowSize.x) / 2, (screenHeight - (i32)desc.WindowSize.y) / 2 };

		mWindowHandle = CreateWindowEx(0, className, desc.WindowTitle.c_str(), WS_OVERLAPPEDWINDOW | WS_EX_ACCEPTFILES,
			center.x, center.y, desc.WindowSize.x, desc.WindowSize.y,
			nullptr, nullptr, windowClass.hInstance, this);

		ShowWindow(mWindowHandle, SW_SHOW);
	}

	void Win32Window::OnUpdate()
	{
		MSG msg;
		while (PeekMessage(&msg, mWindowHandle, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	LRESULT Win32Window::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		/*if (ImGui_ImplWin32_WndProcHandler(hWnd, message, wParam, lParam))
			return true;*/

		switch (message)
		{
		case WM_CREATE:
		{
			Win32Window* window = (Win32Window*)((LPCREATESTRUCT)lParam)->lpCreateParams;
			SetWindowLongPtr(hWnd, -21, (LONG_PTR)window);

			DragAcceptFiles(hWnd, TRUE);
			break;
		}
		case WM_CLOSE:
		{
			Win32Window* window = GetWindowUserData(hWnd);

			WindowCloseEvent closeEvent;
			window->Dispatch(closeEvent);
			break;
		}
		case WM_SIZE:
		{
			Win32Window* window = GetWindowUserData(hWnd);
			RECT clientRect;
			GetClientRect(hWnd, &clientRect);

			switch (wParam)
			{
			case SIZE_MAXIMIZED:
			{
				WindowMaximizeEvent maximizeEvent({ (u32)clientRect.right, (u32)clientRect.bottom }, { (i32)clientRect.left, (i32)clientRect.top });
				window->Dispatch(maximizeEvent);
				break;
			}
			case SIZE_MINIMIZED:
			{
				WindowMaximizeEvent minimizeEvent({ (u32)clientRect.right, (u32)clientRect.bottom }, { (i32)clientRect.left, (i32)clientRect.top });
				window->Dispatch(minimizeEvent);
				break;
			}
			}

			WindowResizeEvent resizeEvent({ (u32)clientRect.right, (u32)clientRect.bottom });
			window->SetWindowSize({ (u32)clientRect.right, (u32)clientRect.bottom });
			window->Dispatch(resizeEvent);
			break;
		}
		case WM_MOVE:
		{
			Win32Window* window = GetWindowUserData(hWnd);

			RECT clientRect;
			GetWindowRect(hWnd, &clientRect);

			WindowMoveEvent moveEvent({ (i32)clientRect.left, (i32)clientRect.top });
			window->SetWindowPosn({ (i32)clientRect.left, (i32)clientRect.top });
			window->Dispatch(moveEvent);
			break;
		}
		case WM_DROPFILES:
		{
			Win32Window* window = GetWindowUserData(hWnd);
			break;
		}
		case WM_KILLFOCUS:
		{
			Win32Window* window = GetWindowUserData(hWnd);

			WindowLostFocusEvent lostFocusEvent;
			window->Dispatch(lostFocusEvent);
			break;
		}
		case WM_SETFOCUS:
		{
			Win32Window* window = GetWindowUserData(hWnd);

			WindowFocusEvent focusEvent;
			window->Dispatch(focusEvent);
			break;
		}
		case WM_LBUTTONDOWN:
		{
			Win32Window* window = GetWindowUserData(hWnd);

			MouseLeftPressedEvent leftPressedEvent;
			window->Dispatch(leftPressedEvent);
			break;
		}
		case WM_LBUTTONUP:
		{
			Win32Window* window = GetWindowUserData(hWnd);

			MouseLeftReleasedEvent leftReleasedEvent;
			window->Dispatch(leftReleasedEvent);
			break;
		}
		case WM_RBUTTONDOWN:
		{
			Win32Window* window = GetWindowUserData(hWnd);

			MouseRightPressedEvent rightPressedEvent;
			window->Dispatch(rightPressedEvent);
			break;
		}
		case WM_RBUTTONUP:
		{
			Win32Window* window = GetWindowUserData(hWnd);

			MouseRightReleasedEvent rightReleasedEvent;
			window->Dispatch(rightReleasedEvent);
			break;
		}
		case WM_MBUTTONDOWN:
		{
			Win32Window* window = GetWindowUserData(hWnd);

			MouseMiddlePressedEvent middlePressedEvent;
			window->Dispatch(middlePressedEvent);
			break;
		}
		case WM_MBUTTONUP:
		{
			Win32Window* window = GetWindowUserData(hWnd);

			MouseMiddleReleasedEvent middleReleasedEvent;
			window->Dispatch(middleReleasedEvent);
			break;
		}
		case WM_MOUSEMOVE:
		{
			Win32Window* window = GetWindowUserData(hWnd);

			MouseMoveEvent moveEvent({ GET_X_LPARAM(lParam), GET_Y_LPARAM(lParam) });
			window->Dispatch(moveEvent);
			break;
		}
		case WM_KEYDOWN:
		{
			Win32Window* window = GetWindowUserData(hWnd);

			u32 keyCode = (u32)wParam;

			KeyPressedEvent keyEvent(keyCode);
			window->Dispatch(keyEvent);
			break;
		}
		case WM_KEYUP:
		{
			Win32Window* window = GetWindowUserData(hWnd);

			u32 keyCode = (u32)wParam;
			KeyReleasedEvent keyEvent(keyCode);
			window->Dispatch(keyEvent);
			break;
		}
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}

		return 0;
	}
}
