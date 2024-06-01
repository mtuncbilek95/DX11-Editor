#include "WorldOutliner.h"

#include <imgui.h>
#include <imgui_internal.h>

namespace Editor
{
	void WorldOutliner::OnPaint()
	{
		if (ImGui::Begin("World Outliner", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize))
		{
			ImGui::Text("World Outliner");
		}

		ImGui::End();
	}
}
