#pragma once

#include <Runtime/Core/Core.h>

#include <wrl.h>
using Microsoft::WRL::ComPtr;

#include <d3d11.h>
#include <dxgi.h>
#include <d3dcompiler.h>

#include <backends/imgui_impl_win32.h>

namespace Editor
{
	struct RendererDesc
	{
		Vector2u WindowSize;
		String WindowTitle;
		class WindowLayer* Window;
	};

	class Renderer
	{
	public:
		Renderer(const RendererDesc& desc);
		~Renderer() = default;

		void StartFrame();
		void EndFrame();

		void Resize(const Vector2u& NewSize);

		ImGuiContext* GetContext() const noexcept { return mImGuiContext; }

	private:
		ComPtr<ID3D11Device> mDevice;
		ComPtr<ID3D11DeviceContext> mDeviceContext;
		ComPtr<IDXGISwapChain> mSwapchain;
		ComPtr<ID3D11RenderTargetView> mRenderTargetView;

		ImGuiContext* mImGuiContext;
	};
}
