#pragma once

// OpenGL
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// std
#include <iostream>

// Run
#include "Core.h"

namespace Run {
	class RUN_API Window
	{
	public:
		Window(float w, float h, const std::string& title, GLFWmonitor* monitor, GLFWwindow* share, bool VsyncOn);
		Window();
		GLFWwindow* getGlfwWindow();
		bool shouldClose();
		void setWindowColor(float r, float g, float b, float a);
		void doBackEndStuff();
		float getWidth();
		float getHeight();
		void destroy();

		friend void windowSizeCallBack(GLFWwindow* window, int width, int height);

		void setFullscreen(bool fullscreen);
	private:
		GLFWwindow* m_window;
		int m_width, m_height;
	};
}