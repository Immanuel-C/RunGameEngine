#pragma once

// OpenGL
#include <GLFW/glfw3.h>

// Run
#include "Core.h"

namespace Run {
	struct RUN_API Keys
	{
		const static uint8_t Number0 = GLFW_KEY_0;
		const static uint8_t Number1 = GLFW_KEY_1;
		const static uint8_t Number2 = GLFW_KEY_2;
		const static uint8_t Number3 = GLFW_KEY_3;
		const static uint8_t Number4 = GLFW_KEY_4;
		const static uint8_t Number5 = GLFW_KEY_5;
		const static uint8_t Number6 = GLFW_KEY_6;
		const static uint8_t Number9 = GLFW_KEY_9;
		const static uint8_t Number7 = GLFW_KEY_7;
		const static uint8_t Number8 = GLFW_KEY_8;
		
		const static uint8_t B = GLFW_KEY_B;
		const static uint8_t A = GLFW_KEY_A;
		const static uint8_t C = GLFW_KEY_C;
		const static uint8_t D = GLFW_KEY_D;
		const static uint8_t E = GLFW_KEY_E;
		const static uint8_t F = GLFW_KEY_F;
		const static uint8_t G = GLFW_KEY_G;
		const static uint8_t H = GLFW_KEY_H;
		const static uint8_t I = GLFW_KEY_I;
		const static uint8_t J = GLFW_KEY_J;
		const static uint8_t K = GLFW_KEY_K;
		const static uint8_t L = GLFW_KEY_L;
		const static uint8_t M = GLFW_KEY_M;
		const static uint8_t N = GLFW_KEY_N;
		const static uint8_t O = GLFW_KEY_O;
		const static uint8_t P = GLFW_KEY_P;
		const static uint8_t Q = GLFW_KEY_Q;
		const static uint8_t R = GLFW_KEY_R;
		const static uint8_t S = GLFW_KEY_S;
		const static uint8_t T = GLFW_KEY_T;
		const static uint8_t U = GLFW_KEY_U;
		const static uint8_t V = GLFW_KEY_V;
		const static uint8_t W = GLFW_KEY_W;
		const static uint8_t X = GLFW_KEY_X;
		const static uint8_t Y = GLFW_KEY_Y;
		const static uint8_t Z = GLFW_KEY_Z;
		
		const static uint16_t F1 = GLFW_KEY_F1;
		const static uint16_t F2 = GLFW_KEY_F2;
		const static uint16_t F3 = GLFW_KEY_F3;
		const static uint16_t F4 = GLFW_KEY_F4;
		const static uint16_t F5 = GLFW_KEY_F5;
		const static uint16_t F6 = GLFW_KEY_F6;
		const static uint16_t F7 = GLFW_KEY_F7;
		const static uint16_t F8 = GLFW_KEY_F8;
		const static uint16_t F9 = GLFW_KEY_F9;
		const static uint16_t F10 = GLFW_KEY_F10;
		const static uint16_t F11 = GLFW_KEY_F11;
		const static uint16_t F12 = GLFW_KEY_F12;
		const static uint16_t F13 = GLFW_KEY_F13;
		const static uint16_t F14 = GLFW_KEY_F14;
		const static uint16_t F15 = GLFW_KEY_F15;
		const static uint16_t F16 = GLFW_KEY_F16;
		const static uint16_t F17 = GLFW_KEY_F17;
		const static uint16_t F18 = GLFW_KEY_F18;
		const static uint16_t F19 = GLFW_KEY_F19;
		const static uint16_t F20 = GLFW_KEY_F20;
		const static uint16_t F21 = GLFW_KEY_F21;
		const static uint16_t F22 = GLFW_KEY_F22;
		const static uint16_t F23 = GLFW_KEY_F23;
		const static uint16_t F24 = GLFW_KEY_F24;
		const static uint16_t F25 = GLFW_KEY_F25;
		
		const static uint16_t KP0 = GLFW_KEY_KP_0;
		const static uint16_t KP1 = GLFW_KEY_KP_1;
		const static uint16_t KP2 = GLFW_KEY_KP_2;
		const static uint16_t KP3 = GLFW_KEY_KP_3;
		const static uint16_t KP4 = GLFW_KEY_KP_4;
		const static uint16_t KP5 = GLFW_KEY_KP_5;
		const static uint16_t KP6 = GLFW_KEY_KP_6;
		const static uint16_t KP7 = GLFW_KEY_KP_7;
		const static uint16_t KP8 = GLFW_KEY_KP_8;
		const static uint16_t KP9 = GLFW_KEY_KP_9;
		const static uint16_t KP_Decimal = GLFW_KEY_KP_DECIMAL;
		const static uint16_t KP_Divide = GLFW_KEY_KP_DIVIDE;
		const static uint16_t KP_Multiply = GLFW_KEY_KP_MULTIPLY;
		const static uint16_t KP_Subtract = GLFW_KEY_KP_SUBTRACT;
		const static uint16_t KP_ADD = GLFW_KEY_KP_ADD;
		const static uint16_t KP_Enter = GLFW_KEY_KP_ENTER;
		const static uint16_t KP_Equal = GLFW_KEY_KP_EQUAL;

		const static uint8_t Space = GLFW_KEY_SPACE;
		const static uint8_t Apostrophe = GLFW_KEY_APOSTROPHE;
		const static uint8_t Comma = GLFW_KEY_COMMA;
		const static uint8_t Minus = GLFW_KEY_MINUS;
		const static uint8_t Period = GLFW_KEY_PERIOD;
		const static uint8_t Slash = GLFW_KEY_SLASH;
		const static uint8_t Semicolon = GLFW_KEY_SEMICOLON;
		const static uint8_t Equal = GLFW_KEY_EQUAL;
		const static uint8_t LeftBracket = GLFW_KEY_LEFT_BRACKET;
		const static uint8_t BackSlash = GLFW_KEY_BACKSLASH;
		const static uint8_t RightBracket = GLFW_KEY_RIGHT_BRACKET;
		const static uint8_t GraveAccent = GLFW_KEY_GRAVE_ACCENT; // `
		
		const static uint16_t Escape = GLFW_KEY_ESCAPE;
		const static uint16_t Enter = GLFW_KEY_ENTER;
		const static uint16_t Tab = GLFW_KEY_TAB;
		const static uint16_t BackSpace = GLFW_KEY_BACKSPACE;
		const static uint16_t Insert = GLFW_KEY_INSERT;
		const static uint16_t Delete = GLFW_KEY_DELETE;
		const static uint16_t ArrowRight = GLFW_KEY_RIGHT;
		const static uint16_t ArrowLeft = GLFW_KEY_LEFT;
		const static uint16_t ArrowDown = GLFW_KEY_DOWN;
		const static uint16_t ArrowUp = GLFW_KEY_UP;
		const static uint16_t PageUp = GLFW_KEY_PAGE_UP;
		const static uint16_t PageDown = GLFW_KEY_PAGE_DOWN;
		const static uint16_t Home = GLFW_KEY_HOME;
		const static uint16_t END = GLFW_KEY_END;
		const static uint16_t CapsLock = GLFW_KEY_CAPS_LOCK;
		const static uint16_t ScrollLock = GLFW_KEY_SCROLL_LOCK;
		const static uint16_t NumberLock = GLFW_KEY_NUM_LOCK;
		const static uint16_t PrintScreen = GLFW_KEY_PRINT_SCREEN;
		const static uint16_t PAUSE = GLFW_KEY_PAUSE;
		const static uint16_t LeftShift = GLFW_KEY_LEFT_SHIFT;
		const static uint16_t LeftControl = GLFW_KEY_LEFT_CONTROL;
		const static uint16_t LeftAlt = GLFW_KEY_LEFT_ALT;
		const static uint16_t LeftWindows = GLFW_KEY_LEFT_SUPER;
		const static uint16_t RightShift = GLFW_KEY_RIGHT_SHIFT;
		const static uint16_t RightControl = GLFW_KEY_RIGHT_CONTROL;
		const static uint16_t RightAlt = GLFW_KEY_RIGHT_ALT;
		const static uint16_t RightWindows = GLFW_KEY_RIGHT_SUPER;
		const static uint16_t Menu = GLFW_KEY_MENU;
	};

	struct RUN_API MouseButtons
	{
		const static uint8_t Left = GLFW_MOUSE_BUTTON_LEFT;
		const static uint8_t Right = GLFW_MOUSE_BUTTON_2;
		const static uint8_t Middle = GLFW_MOUSE_BUTTON_3;
		const static uint8_t SideButton1 = GLFW_MOUSE_BUTTON_4;
		const static uint8_t SideButton2 = GLFW_MOUSE_BUTTON_5;
		const static uint8_t MouseButton6 = GLFW_MOUSE_BUTTON_6;
		const static uint8_t MouseButton7 = GLFW_MOUSE_BUTTON_7;
	};
}