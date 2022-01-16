#pragma once

//std
#include <iostream>

//glm 
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Run
#include "Window.h"

namespace Run {

	class Camera
	{
	public:
		Camera(float left, float right, float bottom, float top);
		Camera(float left, float right, float bottom, float top, float nearZ, float farZ);
		Camera();
		void destroy();

		const glm::mat4& getViewMat();
		const glm::mat4& getProjectionMat();
		void setProjectionMat(glm::mat4& projectionMat);
		void setViewMat(glm::mat4& viewMat);

		const glm::vec3& getPosition();
		void setPosition(const glm::vec3& position);

		float getRotation();
		void setRotation(float rotationDeg);

		float getLeft();
		float getRight();
		float getBottom();
		float getTop();
		float getNearZ();
		float getFarZ();

	private:
		glm::vec3 m_position;
		glm::mat4 m_projectionMat;
		glm::mat4 m_viewMat;

		float m_left = 0.0f,
			m_right = 0.0f,
			m_top = 0.0f,
			m_bottom = 0.0f,
			m_nearZ = 0.0f,
			m_farZ = 0.0f;

		float m_rotationDeg = 0.0f;
	};
}

