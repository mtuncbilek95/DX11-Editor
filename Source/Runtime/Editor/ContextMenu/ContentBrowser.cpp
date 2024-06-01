#include "ContentBrowser.h"

#include <imgui.h>
#include <imgui_internal.h>

namespace Editor
{
	void ContentBrowser::OnPaint()
	{
		if (ImGui::Begin("Content Browser", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize))
		{
			ImGui::Text("Content Browser");
		}

		ImGui::End();
	}
}
