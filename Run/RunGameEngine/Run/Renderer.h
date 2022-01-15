#pragma once

// OpenGL
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//glm 
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// My stuff
#include "Shape.h"
#include "Texture.h"
#include "Shader.h"

// std
#include<vector>
#include<iostream>


class Renderer
{
public:
	Shape createShape(std::vector<float> vertices, std::vector<unsigned int> indices, Shader shader, Texture texture); // You shoud not really use this method
	Shape createQuad(const glm::vec3& position, const glm::vec2& scale, Shader shader, Texture texture);

	void draw(Shape& shape);

	void destroy();
private:
	void createShader(const std::string& vs_shader, const std::string& fs_shader);
	void createVBO(const std::vector<float>& vertices);
	void createEBO(const std::vector<unsigned int>& indices);
	void createVAO();
	void createTexture(Texture texture);

	unsigned int m_VAO;
	unsigned int m_VBO;
	unsigned int m_EBO;
	unsigned int m_shader;
	unsigned int m_texture;

	bool m_usingIndices;

	int m_lenVertices;
	int m_lenIndices;
};

