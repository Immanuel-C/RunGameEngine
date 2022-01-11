#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Window
{
public:
	Window(float w, float h, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
	GLFWwindow* getGlfwWindow();
	bool shouldClose();
	void setWindowColor(float r, float g, float b, float a);
	void doBackEndStuff();
	float getWidth();
	float getHeight();
	void destroy();

	void setFullscreen(bool fullscreen);
private:
	GLFWwindow* m_window;
	float m_width, m_height;
};