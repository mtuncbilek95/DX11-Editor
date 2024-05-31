#pragma once

#include <Runtime/Core/Core.h>
#include <imgui.h>

namespace Editor
{
	class ImGuiKeyUtils
	{
	public:
		static ImGuiKey GetImGuiKey(u32 keyCode)
		{
			switch (keyCode)
			{
				case 0x08: return ImGuiKey_Backspace;
				case 0x09: return ImGuiKey_Tab;
				case 0x0D: return ImGuiKey_Enter;
				case 0x14: return ImGuiKey_Pause;
				case 0x1B: return ImGuiKey_Escape;
				case 0x20: return ImGuiKey_Space;
				case 0x21: return ImGuiKey_PageUp;
				case 0x22: return ImGuiKey_PageDown;
				case 0x23: return ImGuiKey_End;
				case 0x24: return ImGuiKey_Home;
				case 0x25: return ImGuiKey_LeftArrow;
				case 0x26: return ImGuiKey_UpArrow;
				case 0x27: return ImGuiKey_RightArrow;
				case 0x28: return ImGuiKey_DownArrow;
				case 0x2D: return ImGuiKey_Insert;
				case 0x2E: return ImGuiKey_Delete;
				case 0x30: return ImGuiKey_0;
				case 0x31: return ImGuiKey_1;
				case 0x32: return ImGuiKey_2;
				case 0x33: return ImGuiKey_3;
				case 0x34: return ImGuiKey_4;
				case 0x35: return ImGuiKey_5;
				case 0x36: return ImGuiKey_6;
				case 0x37: return ImGuiKey_7;
				case 0x38: return ImGuiKey_8;
				case 0x39: return ImGuiKey_9;
				case 0x41: return ImGuiKey_A;
				case 0x42: return ImGuiKey_B;
				case 0x43: return ImGuiKey_C;
				case 0x44: return ImGuiKey_D;
				case 0x45: return ImGuiKey_E;
				case 0x46: return ImGuiKey_F;
				case 0x47: return ImGuiKey_G;
				case 0x48: return ImGuiKey_H;
				case 0x49: return ImGuiKey_I;
				case 0x4A: return ImGuiKey_J;
				case 0x4B: return ImGuiKey_K;
				case 0x4C: return ImGuiKey_L;
				case 0x4D: return ImGuiKey_M;
				case 0x4E: return ImGuiKey_N;
				case 0x4F: return ImGuiKey_O;
				case 0x50: return ImGuiKey_P;
				case 0x51: return ImGuiKey_Q;
				case 0x52: return ImGuiKey_R;
				case 0x53: return ImGuiKey_S;
				case 0x54: return ImGuiKey_T;
				case 0x55: return ImGuiKey_U;
				case 0x56: return ImGuiKey_V;
				case 0x57: return ImGuiKey_W;
				case 0x58: return ImGuiKey_X;
				case 0x59: return ImGuiKey_Y;
				case 0x5A: return ImGuiKey_Z;
				case 0x60: return ImGuiKey_0;
				case 0x61: return ImGuiKey_1;
				case 0x62: return ImGuiKey_2;
				case 0x63: return ImGuiKey_3;
				case 0x64: return ImGuiKey_4;
				case 0x65: return ImGuiKey_5;
				case 0x66: return ImGuiKey_6;
				case 0x67: return ImGuiKey_7;
				case 0x68: return ImGuiKey_8;
				case 0x69: return ImGuiKey_9;
				case 0x70: return ImGuiKey_F1;
				case 0x71: return ImGuiKey_F2;
				case 0x72: return ImGuiKey_F3;
				case 0x73: return ImGuiKey_F4;
				case 0x74: return ImGuiKey_F5;
				case 0x75: return ImGuiKey_F6;
				case 0x76: return ImGuiKey_F7;
				case 0x77: return ImGuiKey_F8;
				case 0x78: return ImGuiKey_F9;
				case 0x79: return ImGuiKey_F10;
				case 0x7A: return ImGuiKey_F11;
				case 0x7B: return ImGuiKey_F12;
				case 0x7C: return ImGuiKey_F13;
				case 0x7D: return ImGuiKey_F14;
				case 0x7E: return ImGuiKey_F15;
				case 0x7F: return ImGuiKey_F16;
				case 0x80: return ImGuiKey_F17;
				case 0x81: return ImGuiKey_F18;
				case 0x82: return ImGuiKey_F19;
				case 0x83: return ImGuiKey_F20;
				case 0x84: return ImGuiKey_F21;
				case 0x85: return ImGuiKey_F22;
				case 0x86: return ImGuiKey_F23;
				case 0x87: return ImGuiKey_F24;
				case 0x90: return ImGuiKey_NumLock;
				case 0x91: return ImGuiKey_ScrollLock;
				case 0xA0: return ImGuiKey_LeftShift;
				case 0xA1: return ImGuiKey_RightShift;
				case 0xA2: return ImGuiKey_LeftCtrl;
				case 0xA3: return ImGuiKey_RightCtrl;
				case 0xA4: return ImGuiKey_LeftAlt;
				case 0xA5: return ImGuiKey_RightAlt;

				default: return ImGuiKey_COUNT;
			}
		}

	public:
		ImGuiKeyUtils() = delete;
		~ImGuiKeyUtils() = delete;
	};
}
