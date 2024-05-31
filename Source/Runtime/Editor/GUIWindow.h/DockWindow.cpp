#include "DockWindow.h"

#include <Runtime/Render/RenderManager.h>
#include <Runtime/Window/WindowManager.h>

#include <imgui.h>
#include <imgui_internal.h>

namespace Editor
{
	void DockWindow::OnPaint()
	{
		ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking |
			ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse | 
			ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoBringToFrontOnFocus | 
			ImGuiWindowFlags_NoNavFocus;

		ImGuiViewport* viewport = ImGui::GetMainViewport();

		ImGui::SetNextWindowPos(viewport->Pos);
		ImGui::SetNextWindowSize(viewport->Size);
		ImGui::SetNextWindowViewport(viewport->ID);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(0.0f, 0.0f));
		ImGui::Begin("DockSpace Demo", NULL, window_flags);
		ImGui::PopStyleVar(3);

		if (ImGui::BeginMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("New"))
				{
					// Do something
				}

				if (ImGui::MenuItem("Open"))
				{
					// Do something
				}

				if (ImGui::MenuItem("Save"))
				{
					// Do something
				}

				if (ImGui::MenuItem("Exit"))
				{
					WindowManager::GetInstance().IsRunning() = false;
				}

				ImGui::EndMenu();
			}

			if (ImGui::BeginMenu("Edit"))
			{
				if (ImGui::MenuItem("Undo"))
				{
					// Do something
				}

				if (ImGui::MenuItem("Redo"))
				{
					// Do something
				}

				ImGui::EndMenu();
			}

			ImGui::EndMenuBar();
		}

		ImGuiID dockspace_id = ImGui::GetID("DockSpace");
		ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_None);

		if (!mIsDirty)
		{
			mIsDirty = true;

			ImGui::DockBuilderRemoveNode(dockspace_id); // Clear any previous layout
			ImGui::DockBuilderAddNode(dockspace_id, ImGuiDockNodeFlags_None); // Add empty node
			ImGui::DockBuilderSetNodeSize(dockspace_id, viewport->Size);

			ImGuiID dock_id_left = ImGui::DockBuilderSplitNode(dockspace_id, ImGuiDir_Left, 0.20f, nullptr, &dockspace_id);
			ImGuiID dock_id_right = ImGui::DockBuilderSplitNode(dockspace_id, ImGuiDir_Right, 0.20f, nullptr, &dockspace_id);
			ImGuiID dock_id_bottom = ImGui::DockBuilderSplitNode(dockspace_id, ImGuiDir_Down, 0.25f, nullptr, &dockspace_id);

			// Dock the windows into the respective nodes
			ImGui::DockBuilderDockWindow("World Outliner", dock_id_left);
			ImGui::DockBuilderDockWindow("Object Definitions", dock_id_right);
			ImGui::DockBuilderDockWindow("Content Browser", dock_id_bottom);
			ImGui::DockBuilderDockWindow("World Watcher", dockspace_id); // Center

			// Finish the dock builder process
			ImGui::DockBuilderFinish(dockspace_id);
		}

		ImGui::End();

		// Left Window Embedded to DockSpace
		if (ImGui::Begin("World Outliner"))
		{
			ImGui::Text("Hello from Left Window!");
		}
		ImGui::End();

		if (ImGui::Begin("Object Definitions"))
		{
			ImGui::Text("Hello from Right Window!");
		}
		ImGui::End();

		if (ImGui::Begin("Content Browser"))
		{
			ImGui::Text("Hello from Bottom Window!");
		}
		ImGui::End();

		if (ImGui::Begin("World Watcher"))
		{
			ImGui::Text("Hello from Center Window!");
		}
		ImGui::End();
	}
}
