#include "Shape.h"


void Shape::bindVAO()
{
	glBindVertexArray(m_VAO);
}

void Shape::bindShader()
{
	glUseProgram(m_shader);
}

void Shape::bindTexture()
{
	glBindTexture(GL_TEXTURE_2D, m_texture);
}

void Shape::setShader(unsigned int shader)
{
	m_shader = shader;
}

void Shape::setVAO(unsigned int VAO)
{
	m_VAO = VAO;
}

void Shape::setTexture(unsigned int texture)
{
	m_texture = texture;
}


unsigned int Shape::getShader()
{
	return m_shader;
}

glm::vec2 Shape::getPosition()
{
	return m_position;
}

glm::vec2 Shape::getScale()
{
	return m_scale;
}

float Shape::getRotation()
{
	return m_rotationDeg;
}

void Shape::setPosition(glm::vec2 position)
{
	if (m_position != position)
	{
		m_position = position;
		m_modelMat = glm::translate(m_modelMat, glm::vec3(m_position.x, m_position.y, 0.0f));
		glUniformMatrix4fv(glGetUniformLocation(m_shader, "model"), 1, GL_FALSE, glm::value_ptr(m_modelMat));
	}
}

void Shape::setRotation(float rotationDeg, glm::vec3 axis)
{
	if (m_rotationDeg != rotationDeg) 
	{
		m_rotationDeg = rotationDeg;
		m_modelMat = glm::rotate(m_modelMat, glm::radians(m_rotationDeg), glm::vec3(axis.x, axis.y, axis.z));
		glUniformMatrix4fv(glGetUniformLocation(m_shader, "model"), 1, GL_FALSE, glm::value_ptr(m_modelMat));
	}
}

void Shape::setScale(glm::vec2 scale)
{
	if (m_scale != scale) 
	{
		m_scale = scale;
		m_modelMat = glm::scale(m_modelMat, glm::vec3(scale.x, scale.y, 0.0f));
		glUniformMatrix4fv(glGetUniformLocation(m_shader, "model"), 1, GL_FALSE, glm::value_ptr(m_modelMat));
	}
}

void Shape::setCamera(Camera camera)
{
	m_camera = camera;
	m_camera.setViewMat(glm::lookAt(glm::vec3(0.0f, 0.0f, 1.0f), glm::vec3(m_position.x, m_position.y, 0.0f), glm::vec3(1.0f, 0.0f, 0.0f)));
	glUniformMatrix4fv(glGetUniformLocation(m_shader, "view"), 1, GL_FALSE, glm::value_ptr(m_camera.getViewMat()));
	glUniformMatrix4fv(glGetUniformLocation(m_shader, "projection"), 1, GL_FALSE, glm::value_ptr(m_camera.getProjectionMat()));
}



