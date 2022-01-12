#include <Run.h>

class Game : public RunApplication
{
public:
    Renderer renderer;
    
    Camera camera = Camera(glm::vec3(0.0f, 0.0f, 0.0f));
    
    SoundManager soundManager;
    
    Shape triangle;
    std::vector<float> NDCvertices =
    {
        // positions    // texture coords
         800.0f, 100.0f,  1.0f, 0.0f,   // bottom right
         750.0f, 500.0f,  0.5f, 1.0f,   // top 
         600.0f, 100.0f,  0.0f, 0.0f,   // bottom left
    };
    
    std::vector<unsigned int> NDCindices = {  // note that we start from 0!
        0, 1, 2,   // first triangle
    };
    
    void Start()
    {
        window = Window(1280, 720, "Run Game Engine Example", nullptr, nullptr, false); // the last param is if Vsync is on 

        Input::Input(window);

        soundManager.play("Res/Audio/getout.ogg");

        triangle = renderer.createShape(NDCvertices, NDCindices, LoadFile::loadShader("Res/Shader/VertShader.glsl", "Res/Shader/FragShader.glsl"), LoadFile::loadTexture("Res/Textures/Lake.jpg"));

    }

    bool isFullscreen = false;

    // Do not set the windowColor after you draw any shapes!
    void Update(float dt)
    {
        window.setWindowColor(0.5f, 0.25f, 0.1f, 1.0f);

        if (Input::isKeyPressed(Keys::Escape))
        {
            window.destroy();
        }
        if (Input::isKeyPressed(Keys::F11))
        {
            isFullscreen = !isFullscreen;
        }
        
        window.setFullscreen(isFullscreen); // Fullscreen mode is still a bit buggy 


        // Render here:
        triangle.setCamera(camera);
        triangle.setRotation(glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
        renderer.draw(triangle);

        window.doBackEndStuff();
    }

	void End()
	{
        // Make sure to destroy anything if it has a destructor!
        camera.destroy();
        soundManager.destroy();
        renderer.destroy();
        window.destroy();
	}
};

RunApplication* CreateApplication()
{
	return new Game;
}