#pragma once

#include <Runtime/Core/Core.h>
#include <Runtime/Render/RenderModule.h>

#include <Runtime/Editor/GUIWindow/DockWindow.h>

#include <Runtime/Editor/ImGuiKeyUtils.h>

#include <imgui.h>
#include <backends/imgui_impl_win32.h>
namespace Editor
{
	class EditorModuleManager
	{
	public:
		EditorModuleManager()
		{
			AddModule(std::make_shared<DockWindow>());
			auto window = WindowManager::GetInstance().GetWindow();
			
			window->AddLambda(WindowEventType::MouseLeftPressed, [this](const EventBase<WindowEventType>& event) 
				{
					const MouseLeftPressedEvent& mouseEvent = static_cast<const MouseLeftPressedEvent&>(event);
					ImGui::GetIO().AddMouseButtonEvent(ImGuiMouseButton_Left, true);
				});
			window->AddLambda(WindowEventType::MouseLeftReleased, [this](const EventBase<WindowEventType>& event)
				{
					const MouseLeftReleasedEvent& mouseEvent = static_cast<const MouseLeftReleasedEvent&>(event);
					ImGui::GetIO().AddMouseButtonEvent(ImGuiMouseButton_Left, false);
				});
			window->AddLambda(WindowEventType::MouseRightPressed, [this](const EventBase<WindowEventType>& event)
				{
					const MouseRightPressedEvent& mouseEvent = static_cast<const MouseRightPressedEvent&>(event);
					ImGui::GetIO().AddMouseButtonEvent(ImGuiMouseButton_Right, true);
				});
			window->AddLambda(WindowEventType::MouseRightReleased, [this](const EventBase<WindowEventType>& event)
				{
					const MouseRightReleasedEvent& mouseEvent = static_cast<const MouseRightReleasedEvent&>(event);
					ImGui::GetIO().AddMouseButtonEvent(ImGuiMouseButton_Right, false);
				});
			window->AddLambda(WindowEventType::MouseMove, [this](const EventBase<WindowEventType>& event)
				{
					const MouseMoveEvent& mouseEvent = static_cast<const MouseMoveEvent&>(event);
					ImGui::GetIO().AddMousePosEvent((float)mouseEvent.GetNewPos().x, (float)mouseEvent.GetNewPos().y);
				});
			window->AddLambda(WindowEventType::KeyPressed, [this](const EventBase<WindowEventType>& event)
				{
					const KeyPressedEvent& keyEvent = static_cast<const KeyPressedEvent&>(event);
					ImGui::GetIO().AddInputCharacter((ImWchar)keyEvent.GetKeyCode());
				});
			window->AddLambda(WindowEventType::KeyReleased, [this](const EventBase<WindowEventType>& event)
				{
					const KeyReleasedEvent& keyEvent = static_cast<const KeyReleasedEvent&>(event);
				});

		}
		virtual ~EditorModuleManager() = default;

		static EditorModuleManager& GetInstance() noexcept
		{
			static EditorModuleManager instance;
			return instance;
		}

		void Update()
		{
			for (u32 i = 0; i < mRenderModules.size(); i++)
			{
				mRenderModules[i]->OnPaint();
			}
		}

		void AddModule(SharedPtr<RenderModule> module)
		{
			mRenderModules.push_back(module);
		}

		void RemoveModule(const String& moduleName)
		{
			// Remove the module and reduce the size of the array
			mRenderModules.erase(std::remove_if(mRenderModules.begin(), mRenderModules.end(), [moduleName](const SharedPtr<RenderModule>& module)
				{
					return module->GetModuleName() == moduleName;
				}), mRenderModules.end());
		}

	private:
		DArray<SharedPtr<RenderModule>> mRenderModules;
	};
}
