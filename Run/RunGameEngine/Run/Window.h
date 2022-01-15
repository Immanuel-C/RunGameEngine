#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include <iostream>

class Window
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