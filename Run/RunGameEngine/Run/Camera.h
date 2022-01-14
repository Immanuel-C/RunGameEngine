#pragma once

//std
#include <iostream>

//glm 
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Run
#include "Window.h"


class Camera
{
public:
	Camera(float left, float right, float bottom, float top);
	Camera(float left, float right, float bottom, float top, float near, float far);
	Camera();
	void destroy();

	glm::mat4& getViewMat();
	glm::mat4& getProjectionMat();
	void setProjectionMat(glm::mat4& projectionMat);
	void setViewMat(glm::mat4& viewMat);

	glm::vec3 getPosition();
	void setPosition(glm::vec3 position);

	float getRotation();
	void setRotation(float rotationDeg);

private:
	glm::vec3 m_position;
	glm::mat4 m_projectionMat;
	glm::mat4 m_viewMat;

	float m_rotationDeg = 0.0f;
};

