#pragma once

#include <Runtime/Core/Core.h>
#include <Runtime/Window/Window.h>
#include <Runtime/Window/WindowEvents.h>

#include <Runtime/Render/RenderManager.h>

namespace Editor
{
	class WindowManager
	{
	public:
		WindowManager()
		{
		}

		virtual ~WindowManager() = default;

		static WindowManager& GetInstance() noexcept
		{
			static WindowManager instance;
			return instance;
		}

		SharedPtr<WindowLayer> Create(const WindowDesc& desc)
		{
			if (!mWindow)
				mWindow = WindowLayer::Create(desc);

			mWindow->AddLambda(WindowEventType::WindowClose, [this](const EventBase<WindowEventType>& event)
				{
					const WindowCloseEvent& closeEvent = static_cast<const WindowCloseEvent&>(event);
					isRunning = false;
				});

			mWindow->AddLambda(WindowEventType::WindowResize, [this](const EventBase<WindowEventType>& event)
				{
					const WindowResizeEvent& resizeEvent = static_cast<const WindowResizeEvent&>(event);
					RenderManager::GetInstance().GetRenderer()->Resize(resizeEvent.GetNewSize());
				});

			mWindow->AddLambda(WindowEventType::WindowMove, [this](const EventBase<WindowEventType>& event)
				{
					const WindowMoveEvent& moveEvent = static_cast<const WindowMoveEvent&>(event);
				});

			mWindow->AddLambda(WindowEventType::WindowMaximize, [this](const EventBase<WindowEventType>& event)
				{
					const WindowMaximizeEvent& maxEvent = static_cast<const WindowMaximizeEvent&>(event);
					RenderManager::GetInstance().GetRenderer()->Resize(maxEvent.GetNewSize());
				});

			mWindow->AddLambda(WindowEventType::WindowMinimize, [this](const EventBase<WindowEventType>& event)
				{
					const WindowMinimizeEvent& minEvent = static_cast<const WindowMinimizeEvent&>(event);
					RenderManager::GetInstance().GetRenderer()->Resize(minEvent.GetNewSize());
				});

			return mWindow;
		}

		SharedPtr<WindowLayer> GetWindow() const noexcept { return mWindow; }
		bool& IsRunning() noexcept { return isRunning; }


	private:
		SharedPtr<WindowLayer> mWindow;
		bool isRunning = true;
	};
}
