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
	Shape createShape(std::vector<float> vertices, std::vector<unsigned int> indices, Shader shader, Texture texture);
	void draw(Shape shape);
private:
	void createShader(std::string vs_shader, std::string fs_shader);
	void createVBO(std::vector<float> vertices);
	void createEBO(std::vector<unsigned int> indices);
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

