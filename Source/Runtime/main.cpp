#include <Runtime/Window/Window.h>
#include <Runtime/Window/WindowEvents.h>

#include <Runtime/Render/RenderManager.h>
#include <Runtime/Window/WindowManager.h>
#include <Runtime/Editor/EditorModuleManager.h>

#include <iostream>

using namespace Editor;

int main()
{
	WindowDesc windowDesc = { {1920, 1080}, "Editor" };
	auto windowLayer = WindowManager::GetInstance().Create(windowDesc);
	RendererDesc desc = { windowLayer->GetWindowSize(), windowLayer->GetWindowTitle(), windowLayer.get() };
	auto rend = RenderManager::GetInstance().Create(desc);

	while (WindowManager::GetInstance().IsRunning())
	{
		windowLayer->OnUpdate();

		rend->StartFrame();
		EditorModuleManager::GetInstance().Update();
		rend->EndFrame();
	}

	return 0;
}
