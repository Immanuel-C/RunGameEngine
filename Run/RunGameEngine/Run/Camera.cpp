#include "Camera.h"



Camera::Camera(float left, float right, float bottom, float top)
{
	m_left = left;
	m_right = right;
	m_bottom = bottom;
	m_top = top;

	m_projectionMat = glm::ortho(left, right, bottom, top, 0.1f, 100.0f);
	m_position = glm::vec3(0.0f, 0.0f, 0.0f);
	m_viewMat = glm::mat4(1.0f);
}

Camera::Camera(float left, float right, float bottom, float top, float nearZ, float farZ)
{
	m_left = left;
	m_right = right;
	m_bottom = bottom;
	m_top = top;
	m_nearZ = nearZ;
	m_farZ = farZ;

	m_projectionMat = glm::ortho(left, right, bottom, top, nearZ, farZ);
	m_position = glm::vec3(0.0f, 0.0f, 0.0f);
	m_viewMat = glm::mat4(1.0f);
}

Camera::Camera()
{
	m_position = glm::vec3();
	m_projectionMat = glm::mat4(1.0f);
	m_viewMat = glm::mat4(1.0f);
}

void Camera::destroy()
{
	m_position = glm::vec3(NULL, NULL, NULL);
	m_projectionMat = glm::mat4(NULL);
	m_viewMat = glm::mat4(NULL);
}

const glm::mat4& Camera::getViewMat()
{
	return m_viewMat;
}

const glm::mat4& Camera::getProjectionMat()
{
	return m_projectionMat;
}

void Camera::setProjectionMat(glm::mat4& projectionMat)
{
	m_projectionMat = projectionMat;
}

void Camera::setViewMat(glm::mat4& viewMat)
{
	m_viewMat = viewMat;
}

const glm::vec3& Camera::getPosition()
{
	return m_position;
}

void Camera::setPosition(const glm::vec3& position)
{
	m_position = position;
	glm::mat4 tranlsate = glm::translate(glm::mat4(1.0f), m_position) * glm::rotate(glm::mat4(1.0f), m_rotationDeg, glm::vec3(0.0f, 0.0f, 1.0f));
	m_viewMat = tranlsate;
}

float Camera::getRotation()
{
	return m_rotationDeg;
}

void Camera::setRotation(float rotationDeg)
{
	m_rotationDeg = rotationDeg;
	glm::mat4 tranlsate = glm::translate(glm::mat4(1.0f), m_position) * glm::rotate(glm::mat4(1.0f), m_rotationDeg, glm::vec3(0.0f, 0.0f, 1.0f));
	m_viewMat = tranlsate;
}

float Camera::getLeft()
{
	return m_left;
}

float Camera::getRight()
{
	return m_right;
}

float Camera::getBottom()
{
	return m_bottom;
}

float Camera::getTop()
{
	return m_top;
}

float Camera::getNearZ()
{
	return m_nearZ;
}

float Camera::getFarZ()
{
	return m_farZ;
}
