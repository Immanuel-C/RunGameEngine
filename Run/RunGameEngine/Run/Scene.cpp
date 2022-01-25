#include "Scene.h"

namespace Run
{
	Scene::Scene(size_t size)
	{
		m_listOfShapes.reserve(size);
	}

	void Scene::pushBackShape(Shape* shape)
	{
		m_listOfShapes.push_back(shape);
	}


	std::vector<Shape*> Scene::getShapes()
	{
		return m_listOfShapes;
	}

	void Scene::setCamera(Camera& camera)
	{
		m_camera = camera;
	}

	Camera& Scene::getCamera()
	{
		return m_camera;
	}

	void Scene::update()
	{
		for (int i = 0; i < m_listOfShapes.size(); i)
		{
			m_listOfShapes.data()[i]->setCamera(m_camera); // Sets the shapes cameras
		}
	}

}