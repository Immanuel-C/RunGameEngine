#pragma once

// Run
#include "Window.h"

// ImGui
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>

// std
#include <memory>

namespace Run {

	class Gui
	{
	public:
		Gui(std::shared_ptr<Window>& window);

		static void newFrame();
		static void render();
		static void destroy();

	};
}

