#pragma once

// OpenGL
#include <GLFW/glfw3.h>

// irrklang
#include <irrKlang.h>

//std
#include <iostream>

class SoundManager
{
public:
	SoundManager();
	~SoundManager();
	void play(const char* fileLocation);
	void playLooped(const char* fileLocation);
private:
	irrklang::ISoundEngine* m_engine;
};

