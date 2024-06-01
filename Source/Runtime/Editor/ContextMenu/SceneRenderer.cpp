#include "SceneRenderer.h"

#include <imgui.h>
#include <imgui_internal.h>

bool show_window = false;

namespace Editor
{
	void SceneRenderer::OnPaint()
	{
        ImGui::Begin("Scene Renderer", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize);
		ImGui::End();
	}
}
