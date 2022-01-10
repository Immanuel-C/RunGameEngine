#include "Camera.h"

Camera::Camera(glm::vec3 position)
{
	m_cameraPos = position;
}

Camera::Camera()
{

}

glm::mat4 Camera::getViewMat()
{
	return m_viewMat;
}

glm::mat4 Camera::getProjectionMat()
{
	return m_projectionMat;
}

void Camera::setProjectionMat(glm::mat4 projectionMat)
{
	m_projectionMat = projectionMat;
}

void Camera::setViewMat(glm::mat4 viewMat)
{
	m_viewMat = viewMat;
}

glm::vec3 Camera::getPosition()
{
	return m_cameraPos;
}

void Camera::setPosition(glm::vec3 position)
{
	m_cameraPos = position;
	if (m_cameraPos != position)
		m_viewMat = glm::translate(m_viewMat, position);
}
