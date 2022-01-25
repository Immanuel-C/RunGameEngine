#pragma once

// OpenGL
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//glm 
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Run
#include "Shape.h"
#include "Scene.h"
#include "Texture.h"
#include "Shader.h"
#include "Core.h"

// std
#include <iostream>
#include <array>

namespace Run {
	class RUN_API Renderer
	{
	public:
		// You shoud not really use this method
		// Shape createShape(std::vector<float> vertices, std::vector<unsigned int> indices, Shader shader, Texture texture); 
		Shape createQuad(float rotation, const glm::vec3& position, const glm::vec2& scale, Shader shader, Texture texture);

		void draw(Scene& scene);

		void destroy();
	private:
		void createShader(const std::string& vs_shader, const std::string& fs_shader);
		template <size_t size>
		void createVBO(const std::array<float, size>& vertices);
		template <size_t size>
		void createEBO(const std::array<uint8_t, size>& indices);
		void createVAO();
		void createTexture(Texture texture);

		unsigned int m_VAO;
		unsigned int m_VBO;
		unsigned int m_EBO;
		unsigned int m_shader;
		unsigned int m_texture;

		int m_lenVertices;
		int m_lenIndices;
	};
}