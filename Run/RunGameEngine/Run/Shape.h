#pragma once

// Run
#include "Texture.h"
#include "Shader.h"
#include "Camera.h"
#include "Core.h"

// OpenGL
#include <glad/glad.h>

namespace Run {

	class RUN_API Shape
	{
	public:
		void bindVAO() const;
		void bindShader() const;
		void bindTexture() const;
		void setShader(unsigned int shader);
		void setVAO(unsigned int VAO);
		void setTexture(unsigned int texture);

		inline unsigned int getShader() const;
		inline const glm::vec3& getPosition() const;
		inline const glm::vec2& getScale() const;
		inline float getRotation() const;

		void setPosition(const glm::vec3& position);
		void setRotation(float rotationDeg);
		void setScale(const glm::vec2& scale);
		
		void move(const glm::vec3& velocity);
		
		void setCamera(Camera& Camera);
	private:
		void recalculateMatrices();

		unsigned int m_VAO = NULL;
		unsigned int m_shader = NULL;
		unsigned int m_texture = NULL;
		glm::mat4 m_modelMat = glm::mat4(1.0f);
		glm::vec3 m_position{ 0.0f, 0.0f, 0.0f };
		glm::vec2 m_scale{ 1.0f, 1.0f };
		float m_rotationDeg = 0.0f;
		Camera m_camera;
	};
}
