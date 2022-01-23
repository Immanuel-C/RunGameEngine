#pragma once

// Run
#include "Core.h"

namespace Run {

	class RUN_API Texture
	{
	public:
		Texture(unsigned char* data, int width, int height, int nrChannels);
		Texture();
		unsigned char* getData();
		int getWidth();
		int getHeight();
		int getNrChannels();

	private:
		unsigned char* m_data;
		int m_width;
		int m_height;
		int m_nrChannels;
	};
}