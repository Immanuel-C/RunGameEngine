#include "Renderer.h"
#include <stb_image.h>

namespace Run {

	/*
	Shape Renderer::createShape(std::vector<float> vertices, std::vector<unsigned int> indices, Shader shader, Texture texture)
	{
		m_lenVertices = vertices.size();
		m_lenIndices = indices.size();

		createVAO();
		createVBO(vertices);
		createEBO(indices);
		createTexture(texture);
		createShader(shader.getVertexShader(), shader.getFragmentShader());

		Shape shape;

		glm::mat4 model(1.0f);
		glUniformMatrix4fv(glGetUniformLocation(m_shader, "model"), 1, GL_FALSE, glm::value_ptr(model));

		shape.setShader(m_shader);
		shape.setVAO(m_VAO);
		shape.setTexture(m_texture);

		return shape;
	}
	*/

	Shape Renderer::createQuad(float rotation, const glm::vec3& position, const glm::vec2& scale, Shader shader, Texture texture)
	{
		float x = position.x;
		float y = position.y;
		float z = position.z;
		float width = scale.x;
		float height = scale.y;

		std::array<float, 20> vertices =
		{
			x + width, y + height, z, 1.0f, 1.0f, // TR
			x + width, y - height, z, 1.0f, 0.0f, // BR
			x - width, y - height, z, 0.0f, 0.0f, // BL
			x - width, y + height, z, 0.0f, 1.0f  // TL
		};


		std::array<uint8_t, 6> indices =
		{
			0, 1, 3,
			1, 2, 3
		};

		m_lenVertices = vertices.size();
		m_lenIndices = indices.size();


		createVAO();
		createVBO<vertices.size()>(vertices);
		createEBO<indices.size()>(indices);
		createTexture(texture);
		createShader(shader.getVertexShader(), shader.getFragmentShader());

		Shape shape;

		glm::mat4 model(1.0f);
		glUniformMatrix4fv(glGetUniformLocation(m_shader, "model"), 1, GL_FALSE, glm::value_ptr(model));

		shape.setShader(m_shader);
		shape.setVAO(m_VAO);
		shape.setTexture(m_texture);
		shape.setPosition(position);
		shape.setRotation(rotation);
		//shape.setScale(scale);

		return shape;
	}

	void Renderer::draw(Shape& shape)
	{
		// Unbinds any other shapes
		glBindVertexArray(0);
		glUseProgram(0);
		shape.bindShader();
		shape.bindVAO();
		shape.bindTexture();
		glDrawElements(GL_TRIANGLES, m_lenIndices, GL_UNSIGNED_BYTE, 0);
	}

	void Renderer::destroy()
	{
		glDeleteBuffers(1, &m_VAO);
		glDeleteBuffers(1, &m_VBO);
		glDeleteBuffers(1, &m_EBO);
		glDeleteBuffers(1, &m_shader);
		glDeleteBuffers(1, &m_texture);
	}

	void Renderer::createShader(const std::string& vs_Shader, const std::string& fs_Shader)
	{
		int success;
		char infoLog[512];

		const char* vShader = vs_Shader.c_str();
		const char* fShader = fs_Shader.c_str();

		unsigned int vertexShader;
		vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexShader, 1, &vShader, nullptr);
		glCompileShader(vertexShader);

		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
			std::cout << "ERROR: VERTEX SHADER FAILED TO COMPILE\n" << infoLog << std::endl;
		}


		unsigned int fragmentShader;
		fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentShader, 1, &fShader, nullptr);
		glCompileShader(fragmentShader);


		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
			std::cout << "ERROR: FRAGMENT SHADER FAILED TO COMPILE\n" << infoLog << std::endl;
		}

		m_shader = glCreateProgram();

		glAttachShader(m_shader, vertexShader);
		glAttachShader(m_shader, fragmentShader);
		glLinkProgram(m_shader);

		glGetProgramiv(m_shader, GL_LINK_STATUS, &success);

		if (!success)
		{
			glGetProgramInfoLog(m_shader, 512, NULL, infoLog);
			std::cout << "ERROR: SHADERS FAILED TO LINK\n" << infoLog << std::endl;
		}

		glUseProgram(m_shader);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	template <size_t size>
	void Renderer::createVBO(const std::array<float, size>& vertices)
	{

		glGenBuffers(1, &m_VBO);
		glBindBuffer(GL_ARRAY_BUFFER, m_VBO);
		// Send buffer data to opengl
		glBufferData(GL_ARRAY_BUFFER, sizeof(float) * m_lenVertices, vertices.data(), GL_DYNAMIC_DRAW);
		// Tells opengl what to do with the buffers
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, (void*)0);
		glEnableVertexAttribArray(0);
	}

	template <size_t size>
	void Renderer::createEBO(const std::array<uint8_t, size>& indices)
	{
		glGenBuffers(1, &m_EBO);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_EBO);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint8_t) * m_lenIndices, indices.data(), GL_DYNAMIC_DRAW);
	}

	void Renderer::createVAO()
	{
		glGenVertexArrays(1, &m_VAO);
		glBindVertexArray(m_VAO);
	}

	void Renderer::createTexture(Texture texture)
	{
		glGenTextures(1, &m_texture);
		glBindTexture(GL_TEXTURE_2D, m_texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		if (texture.getData())
		{
			if (texture.getNrChannels() == STBI_rgb)
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, texture.getWidth(), texture.getHeight(), 0, GL_RGB, GL_UNSIGNED_BYTE, texture.getData());
			if (texture.getNrChannels() == STBI_rgb_alpha)
				glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture.getWidth(), texture.getHeight(), 0, GL_RGBA, GL_UNSIGNED_BYTE, texture.getData());

			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cout << "Failed to load texture\n\n";
		}

		stbi_image_free(texture.getData());

		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);
	}
}