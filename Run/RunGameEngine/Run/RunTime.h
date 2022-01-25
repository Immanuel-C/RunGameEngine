#pragma once
#include <cstdint>


class Time
{
public:
	/// <summary>
	/// calculates the delta Δ between each frame 
	/// </summary>
	/// <returns>(double)dt</returns>
	static double calculateDt();
	/// <summary>
	/// returns how many frames are drawn per second.
	/// Make sure to call calculateDt() before this method. 
	/// </summary>
	/// <returns>(uint16_t)FPS</returns>
	static int getFPS();
private:
	static double m_dt;
	static double m_currtime;
	static double m_prevTime;
	static uint16_t FPS;
};

