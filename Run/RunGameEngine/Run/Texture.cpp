#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#include <iostream>


Texture::Texture(unsigned char* data, int width, int height, int nrChannels)
{
	m_data = data;
	m_width = width;
	m_height = height;
	m_nrChannels = nrChannels;
}

Texture::Texture()
{
	m_data = nullptr;
	m_width = NULL;
	m_height = NULL;
	m_nrChannels = NULL;
}

unsigned char* Texture::getData()
{
	return m_data;
}

int Texture::getWidth()
{
	return m_width;
}

int Texture::getHeight()
{
	return m_height;
}

int Texture::getNrChannels()
{
	return m_nrChannels;
}
