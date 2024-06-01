#include "EntityDetails.h"

#include <imgui.h>
#include <imgui_internal.h>

namespace Editor
{
	void EntityDetails::OnPaint()
	{
		if (ImGui::Begin("Entity Details", nullptr, ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize))
		{
			ImGui::Text("Entity Details");
		}

		ImGui::End();
	}
}
