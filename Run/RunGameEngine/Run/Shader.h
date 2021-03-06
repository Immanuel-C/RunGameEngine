#pragma once

// Run
#include "Core.h"

// std
#include <string>

namespace Run {

	class RUN_API Shader
	{
	public:
		Shader(std::string vertexShader, std::string fragmentShader);

		std::string getVertexShader();
		std::string getFragmentShader();

	private:
		std::string m_vertexShader;
		std::string m_fragmentShader;

	};
}