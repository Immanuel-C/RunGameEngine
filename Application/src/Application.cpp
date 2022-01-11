#include <Run.h>

class Game : public Application // Replace name with your game name
{
public:

    Window window = Window(800, 600, "Run Game Engine Example", nullptr, nullptr);

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
    
    void start()
    {
        Input::Input(window);

        soundManager.play("Res/Audio/explosion.wav");

        triangle = renderer.createShape(NDCvertices, NDCindices, LoadFile::loadShader("Res/Shader/VertShader.glsl", "Res/Shader/FragShader.glsl"), LoadFile::loadTexture("Res/Textures/Lake.jpg"));

    }

    void run()
    {
        /* Loop until the user closes the window */
        while (!window.shouldClose())
        {
            window.setWindowColor(0.5f, 0.25f, 0.1f, 1.0f);

            if (Input::isKeyPressed(Keys::Escape))
            {
                window.destroy();
                break;
            }
            
            triangle.setCamera(camera);
            renderer.draw(triangle);

            window.doBackEndStuff();
        }
    }

	~Game()
	{
        soundManager.~SoundManager();
        window.destroy();
	}
};

Application* CreateApplication()
{
	return new Game();
}