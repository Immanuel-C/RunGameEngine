#pragma once

// OpenGL
#include <GLFW/glfw3.h>

// irrklang
#include <irrKlang.h>

//std
#include <iostream>

// Run
#include "Core.h"

namespace Run {

	class RUN_API SoundManager
	{
	public:
		SoundManager();
		void destroy();
		void play(const char* fileLocation);
		void playLooped(const char* fileLocation);
	private:
		irrklang::ISoundEngine* m_engine;
	};
}

