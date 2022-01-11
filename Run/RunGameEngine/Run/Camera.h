#pragma once

//glm 
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


class Camera
{
public:
	Camera(glm::vec3 position);
	Camera();
	void destroy();

	glm::mat4 getViewMat();
	glm::mat4 getProjectionMat();
	void setProjectionMat(glm::mat4 projectionMat);
	void setViewMat(glm::mat4 viewMat);

	glm::vec3 getPosition();
	void setPosition(glm::vec3 position);

private:
	glm::vec3 m_cameraPos{0.0f, 0.0f, 0.0f};
	glm::mat4 m_projectionMat = glm::ortho(-1920.0f, 1920.0f, -1080.0f, 1080.0f, 0.1f, 100.0f);
	glm::mat4 m_viewMat{ 1.0f };
};

