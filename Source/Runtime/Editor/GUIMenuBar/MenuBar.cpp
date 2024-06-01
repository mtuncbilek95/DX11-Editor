#include "MenuBar.h"

#include <imgui.h>
#include <imgui_internal.h>

#include <Runtime/Window/WindowManager.h>
#include <Runtime/Editor/EditorModuleManager.h>
#include <Runtime/Editor/ContextMenu/WorldOutliner.h>
#include <Runtime/Editor/ContextMenu/EntityDetails.h>
#include <Runtime/Editor/ContextMenu/ContentBrowser.h>
#include <Runtime/Editor/ContextMenu/SceneRenderer.h>

namespace Editor
{
	void MenuBar::OnPaint()
	{
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

			static bool isWorldOutlinerVisible = false;
			static bool isEntityDetailsVisible = false;
			static bool isSceneRendererVisible = false;
			static bool isContentBrowserVisible = false;
			if (ImGui::BeginMenu("Window"))
			{
				static bool isWorldOutlinerAdded = false;
				if (ImGui::MenuItem("World Outliner", "", &isWorldOutlinerVisible))
				{
					if (!isWorldOutlinerAdded)
					{
						EditorModuleManager::GetInstance().AddModule(std::make_shared<WorldOutliner>());
						isWorldOutlinerAdded = true;
					}
				}

				static bool isEntityDetalilsAdded = false;
				if (ImGui::MenuItem("Entity Details", "", &isEntityDetailsVisible))
				{
					if (!isEntityDetalilsAdded)
					{
						EditorModuleManager::GetInstance().AddModule(std::make_shared<EntityDetails>());
						isEntityDetalilsAdded = true;
					}
				}

				static bool isContentBrowserAdded = false;
				if (ImGui::MenuItem("Content Browser", "", &isContentBrowserVisible))
				{
					if (!isContentBrowserAdded)
					{
						EditorModuleManager::GetInstance().AddModule(std::make_shared<ContentBrowser>());
						isContentBrowserAdded = true;
					}
				}

				static bool isSceneRendererAdded = false;
				if (ImGui::MenuItem("Scene Renderer", "", &isSceneRendererVisible))
				{
					if (!isSceneRendererAdded)
					{
						EditorModuleManager::GetInstance().AddModule(std::make_shared<SceneRenderer>());
						isSceneRendererAdded = true;
					}
				}

				if (isEntityDetalilsAdded && !isEntityDetailsVisible)
				{
					EditorModuleManager::GetInstance().RemoveModule("EntityDetails");
					isEntityDetalilsAdded = false;
				}

				if (isSceneRendererAdded && !isSceneRendererVisible)
				{
					EditorModuleManager::GetInstance().RemoveModule("SceneRenderer");
					isSceneRendererAdded = false;
				}

				if (isContentBrowserAdded && !isContentBrowserVisible)
				{
					EditorModuleManager::GetInstance().RemoveModule("ContentBrowser");
					isContentBrowserAdded = false;
				}

				if (isWorldOutlinerAdded && !isWorldOutlinerVisible)
				{
					EditorModuleManager::GetInstance().RemoveModule("WorldOutliner");
					isWorldOutlinerAdded = false;
				}

				ImGui::EndMenu();
			}

			ImGui::EndMenuBar();
		}
	}
}
