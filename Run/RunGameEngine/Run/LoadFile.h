#pragma once

// Run
#include "Texture.h"
#include "Shader.h"
#include "Core.h"

// std
#include <fstream>
#include <sstream>


namespace Run {
	class RUN_API LoadFile
	{
	public:
		static Texture loadTexture(const char* fileLocation);
		static Shader loadShader(const char* vertexShaderFileLocation, const char* fragmentShaderFileLocation);
	};
}

