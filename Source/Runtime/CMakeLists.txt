include(FetchContent)

# IMGUI Library
FetchContent_Declare(
	imgui
	GIT_REPOSITORY https://github.com/ocornut/imgui.git
	GIT_TAG docking
)

FetchContent_MakeAvailable(imgui)

# ---------------------- IMGUI FILES -------------------------
file(GLOB IMGUI_FILES "${imgui_SOURCE_DIR}/*.cpp" "${imgui_SOURCE_DIR}/*.h" "${imgui_SOURCE_DIR}/backends/imgui_impl_win32.h" "${imgui_SOURCE_DIR}/backends/imgui_impl_win32.cpp"
"${imgui_SOURCE_DIR}/backends/imgui_impl_dx11.h" "${imgui_SOURCE_DIR}/backends/imgui_impl_dx11.cpp")
source_group(TREE "${imgui_SOURCE_DIR}" FILES ${IMGUI_FILES})
add_library(imgui STATIC ${IMGUI_FILES})

target_include_directories(imgui PUBLIC "${imgui_SOURCE_DIR}")
target_link_libraries(imgui PRIVATE Runtime)
# ------------------------------------------------------------

# ---------------------- FILE ADDITION -----------------------
file(GLOB_RECURSE SUBDIRECTORIES "${CMAKE_SOURCE_DIR}/Source/Runtime/*.cpp" "${CMAKE_SOURCE_DIR}/Source/Runtime/*.h")
source_group(TREE "${CMAKE_SOURCE_DIR}/Source/Runtime" FILES ${SUBDIRECTORIES})
add_executable(Runtime main.cpp ${SUBDIRECTORIES})
# ------------------------------------------------------------

target_include_directories(Runtime PRIVATE "${PROJECT_SOURCE_DIR}/Source")
if (CMAKE_VERSION VERSION_GREATER 3.26)
  set_property(TARGET Runtime PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(Runtime PRIVATE d3d11.lib d3dcompiler.lib dxgi.lib)

# --------------------- EXTERNAL LIBRARIES --------------------
target_include_directories(Runtime PUBLIC "${imgui_SOURCE_DIR}")

target_link_libraries(Runtime PUBLIC imgui)
# ------------------------------------------------------------