#pragma once

// std
#include <vector>
#include <array>

// Run
#include "Shape.h"
#include "Core.h"

namespace Run 
{
	class RUN_API Scene
	{
	public:
		Scene(size_t size = 5);

		void addShape(Shape* shape);

		std::vector<Shape*> getShapes();

		void setCamera(Camera& camera);
		Camera& getCamera();
		void update();

		void destroy();
	private:
		std::vector<Shape*> m_listOfShapes;
		Camera m_camera;
	};
}

