#include "Time.h"

#include <GLFW/glfw3.h>

double Time::m_dt = 0.0f;
double Time::m_currtime = glfwGetTime();
double Time::m_prevTime = 0.0f;
uint16_t Time::FPS;


double Time::calculateDt()
{
	m_currtime = glfwGetTime();
	m_dt = m_currtime - m_prevTime;
	m_prevTime = m_currtime;

	FPS = (1.0 * m_dt) * 1000;

	return m_dt;
}

int Time::getFPS()
{
	return FPS;
}
