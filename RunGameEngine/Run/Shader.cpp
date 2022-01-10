#include "Shader.h"

Shader::Shader(std::string vertexShader, std::string fragmentShader)
{
	m_vertexShader = vertexShader;
	m_fragmentShader = fragmentShader;
}

std::string Shader::getVertexShader()
{
	return m_vertexShader;
}

std::string Shader::getFragmentShader()
{
	return m_fragmentShader;
}
