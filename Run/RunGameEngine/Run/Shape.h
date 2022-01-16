#pragma once
#include "Texture.h"
#include "Camera.h"
#include <glad/glad.h>

namespace Run {

	class Shape
	{
	public:
		void bindVAO();
		void bindShader();
		void bindTexture();
		void setShader(unsigned int shader);
		void setVAO(unsigned int VAO);
		void setTexture(unsigned int texture);

		unsigned int getShader();
		const glm::vec2& getPosition();
		const glm::vec2& getScale();
		float getRotation();

		void setPosition(const glm::vec2& position);
		void setRotation(float rotationDeg);
		void setScale(const glm::vec2& scale);
		void setCamera(Camera& Camera);
	private:
		void recalculateMatrices();

		unsigned int m_VAO;
		unsigned int m_shader;
		unsigned int m_texture;
		glm::mat4 m_modelMat = glm::mat4(1.0f);
		glm::vec2 m_position{ 0.0f, 0.0f };
		glm::vec2 m_scale{ 1.0f, 1.0f };
		float m_rotationDeg = 0.0f;
		Camera m_camera;
	};
}
