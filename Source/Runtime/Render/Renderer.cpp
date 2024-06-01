#include "Renderer.h"



#include <backends/imgui_impl_dx11.h>
#include <backends/imgui_impl_win32.h>
#include <imgui.h>

#include <Runtime/Window/Win32Window.h>

namespace Editor
{
	Renderer::Renderer(const RendererDesc& desc)
	{
		D3D_FEATURE_LEVEL featureLevel[] = { D3D_FEATURE_LEVEL_11_1 };

		u32 deviceFlags = D3D11_CREATE_DEVICE_DEBUG;

		D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE,
			nullptr, deviceFlags, featureLevel, 1, D3D11_SDK_VERSION, mDevice.GetAddressOf(), nullptr, mDeviceContext.GetAddressOf());

		ComPtr<IDXGIDevice> dxgiDevice;
		mDevice.As(&dxgiDevice);

		ComPtr<IDXGIAdapter> dxgiAdapter;
		dxgiDevice->GetAdapter(dxgiAdapter.GetAddressOf());

		ComPtr<IDXGIFactory> dxgiFactory;
		dxgiAdapter->GetParent(__uuidof(IDXGIFactory), &dxgiFactory);

		DXGI_SWAP_CHAIN_DESC swapchainDesc = {};
		swapchainDesc.BufferDesc.Width = desc.WindowSize.x;
		swapchainDesc.BufferDesc.Height = desc.WindowSize.y;
		swapchainDesc.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		swapchainDesc.BufferDesc.RefreshRate.Numerator = 60;
		swapchainDesc.BufferDesc.RefreshRate.Denominator = 1;
		swapchainDesc.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
		swapchainDesc.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		swapchainDesc.SampleDesc.Count = 1;
		swapchainDesc.SampleDesc.Quality = 0;
		swapchainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapchainDesc.BufferCount = 2;
		swapchainDesc.OutputWindow = static_cast<Win32Window*>(desc.Window)->GetWindowHandle();
		swapchainDesc.Windowed = true;
		swapchainDesc.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		swapchainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

		dxgiFactory->CreateSwapChain(mDevice.Get(), &swapchainDesc, mSwapchain.GetAddressOf());

		ComPtr<ID3D11Texture2D> backBuffer;
		mSwapchain->GetBuffer(0, __uuidof(ID3D11Texture2D), &backBuffer);

		mDevice->CreateRenderTargetView(backBuffer.Get(), nullptr, mRenderTargetView.GetAddressOf());

		IMGUI_CHECKVERSION();
		mImGuiContext = ImGui::CreateContext();
		ImGui::StyleColorsDark();
		ImGuiIO& io = ImGui::GetIO(); (void)io;

		auto window = static_cast<Win32Window*>(desc.Window);

		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking

		ImGui::GetIO().Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\arial.ttf", 16.0f);

		ImGui_ImplWin32_Init(window->GetWindowHandle());
		ImGui_ImplDX11_Init(mDevice.Get(), mDeviceContext.Get());
	}

	void Renderer::StartFrame()
	{
		ImGui_ImplDX11_NewFrame();
		ImGui_ImplWin32_NewFrame();
		ImGui::NewFrame();

		f32* clearColor = new f32[4]{ 0.1f, 0.2f, 0.4f, 1.0f };
		mDeviceContext->OMSetRenderTargets(1, mRenderTargetView.GetAddressOf(), nullptr);
		mDeviceContext->ClearRenderTargetView(mRenderTargetView.Get(), clearColor);
		delete[] clearColor;
	}
	void Renderer::EndFrame()
	{
		ImGui::Render();
		ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

		if (ImGui::GetIO().ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
		{
			ImGui::UpdatePlatformWindows();
			ImGui::RenderPlatformWindowsDefault();
		}

		mDeviceContext->ClearState();

		mSwapchain->Present(1, 0);
	}
	void Renderer::Resize(const Vector2u& NewSize)
	{
		mDeviceContext->OMSetRenderTargets(0, nullptr, nullptr);
		mRenderTargetView.Reset();
		mSwapchain->ResizeBuffers(0, NewSize.x, NewSize.y, DXGI_FORMAT_UNKNOWN, 0);
		ComPtr<ID3D11Texture2D> backBuffer;
		mSwapchain->GetBuffer(0, __uuidof(ID3D11Texture2D), &backBuffer);
		mDevice->CreateRenderTargetView(backBuffer.Get(), nullptr, mRenderTargetView.GetAddressOf());
	}
}
