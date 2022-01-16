#pragma once
#include "Texture.h"
#include "Shader.h"
#include <fstream>
#include <sstream>

namespace Run {
	class LoadFile
	{
	public:
		static Texture loadTexture(const char* fileLocation);
		static Shader loadShader(const char* vertexShaderFileLocation, const char* fragmentShaderFileLocation);
	};
}

