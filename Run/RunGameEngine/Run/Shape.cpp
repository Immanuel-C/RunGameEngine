#include "Shape.h"

#include <iostream>

namespace Run {

	void Shape::bindVAO() const
	{
		glBindVertexArray(m_VAO);
	}

	void Shape::bindShader() const
	{
		glUseProgram(m_shader);
	}

	void Shape::bindTexture() const
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

	inline unsigned int Shape::getShader() const
	{
		return m_shader;
	}

	inline const glm::vec3& Shape::getPosition() const 
	{
		return m_position;
	}

	inline const glm::vec2& Shape::getScale() const
	{
		return m_scale;
	}

	inline float Shape::getRotation() const
	{
		return m_rotationDeg;
	}

	void Shape::setPosition(const glm::vec3& position)
	{
		glBindVertexArray(m_VAO);
		glUseProgram(m_shader);

		m_position = position;
		recalculateMatrices();

		glBindVertexArray(0);
		glUseProgram(0);
	}

	void Shape::setRotation(float rotationDeg)
	{
		glBindVertexArray(m_VAO);
		glUseProgram(m_shader);

		glm::vec3 oldPosition = m_position;
		m_position = { 0.0f, 0.0f, 0.0f };

		m_rotationDeg = rotationDeg;
		recalculateMatrices();

		setPosition(oldPosition);

		glBindVertexArray(0);
		glUseProgram(0);
	}

	void Shape::setScale(const glm::vec2& scale)
	{

		glBindVertexArray(m_VAO);
		glUseProgram(m_shader);

		glm::vec3 oldPosition = m_position;
		m_position = { 0.0f, 0.0f, 0.0f };

		m_scale = scale;
		recalculateMatrices();

		setPosition(oldPosition);

		glBindVertexArray(0);
		glUseProgram(0);
	}

	void Shape::move(const glm::vec3& velocity)
	{
		glBindVertexArray(m_VAO);
		glUseProgram(m_shader);

		glm::normalize(velocity);

		m_position += velocity;
		recalculateMatrices();

		glBindVertexArray(0);
		glUseProgram(0);
	}

	void Shape::setCamera(Camera& camera)
	{
		glBindVertexArray(m_VAO);
		glUseProgram(m_shader);

		glUniformMatrix4fv(glGetUniformLocation(m_shader, "view"), 1, GL_FALSE, glm::value_ptr(camera.getViewMat()));
		glUniformMatrix4fv(glGetUniformLocation(m_shader, "projection"), 1, GL_FALSE, glm::value_ptr(camera.getProjectionMat()));

		glBindVertexArray(0);
		glUseProgram(0);
	}

	void Shape::recalculateMatrices()
	{
		m_modelMat = glm::translate(glm::mat4(1.0f), glm::vec3(m_position.x, m_position.y, m_position.z)) *
			glm::rotate(glm::mat4(1.0f), glm::radians(m_rotationDeg), glm::vec3(0.0f, 0.0f, 1.0f)) *
			glm::scale(glm::mat4(1.0f), glm::vec3(m_scale.x, m_scale.y, 1.0f));
		glUniformMatrix4fv(glGetUniformLocation(m_shader, "model"), 1, GL_FALSE, glm::value_ptr(m_modelMat));
	}
}
