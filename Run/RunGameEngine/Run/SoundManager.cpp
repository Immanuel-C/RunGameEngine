#include "SoundManager.h"


SoundManager::SoundManager()
{
	m_engine = irrklang::createIrrKlangDevice();
    if (!m_engine)
    {
        std::cout << "AUDIO ERROR: FAILED TO INIT IRRKLANG";
        glfwTerminate();
    }
}

void SoundManager::destroy()
{
    m_engine->drop();
}

void SoundManager::play(const char* fileLocation)
{
    bool didPlay = false;

    if (!didPlay) 
    {
        m_engine->play2D(fileLocation);
        didPlay = true;
    }
}

void SoundManager::playLooped(const char* fileLocation)
{
    bool didPlay = false;

    if (!didPlay) 
    {
        m_engine->play2D(fileLocation, true);
    }
}
