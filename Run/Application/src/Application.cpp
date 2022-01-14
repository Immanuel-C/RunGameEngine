#include <Run.h>

class Game : public RunApplication
{
public:
    std::unique_ptr<Renderer> renderer = std::make_unique<Renderer>();
    std::unique_ptr<SoundManager> soundManager = std::make_unique<SoundManager>();

    Camera camera;

    Shape quad;
    Shape triangle;

    std::vector<float> NDCvertices =
{
        // positions    // texture coords
         500.0f, 100.0f,  1.0f, 0.0f,   // bottom right
         450.0f, 500.0f,  0.5f, 1.0f,   // top 
         600.0f, 100.0f,  0.0f, 0.0f,   // bottom left
    };

    std::vector<unsigned int> NDCindices = {  // note that we start from 0!
        0, 1, 2,   // first triangle
    };

    /// <summary>
    /// The start method is called before the Update method and is kind of like the constructor for the class
    /// </summary>
    void Start() override
    {
        // Make sure to init the window before the camera
        window = std::make_shared<Window>(800, 600, "Run Game Engine Example", nullptr, nullptr, false); // the last param is if Vsync is on 
        camera = Camera(-window->getWidth(), window->getWidth(), -window->getHeight(), window->getHeight());

        Input::Input(window);

        //soundManager.play("Res/Audio/getout.ogg");

        //quad = renderer->createQuad(glm::vec2(500.0f, 500.0f), glm::vec2(250.0f, 250.0f), LoadFile::loadShader("Res/Shader/VertShader.glsl", "Res/Shader/FragShader.glsl"), LoadFile::loadTexture("Res/Textures/Lake.jpg"));
        triangle = renderer->createShape(NDCvertices, NDCindices, LoadFile::loadShader("Res/Shader/VertShader.glsl", "Res/Shader/FragShader.glsl"), LoadFile::loadTexture("Res/Textures/Lake.jpg"));
    }

    bool isFullscreen = false;

    void controlShape(Shape shape, float dt)
    {
        float movementSpeed = 1000.0f * dt;

        if (Input::isKeyPressed(Keys::W) || Input::isKeyPressed(Keys::ArrowUp))
        {
            shape.setPosition(glm::vec2(0.0f, movementSpeed ));
        }
        if (Input::isKeyPressed(Keys::A) || Input::isKeyPressed(Keys::ArrowLeft))
        {
            shape.setPosition(glm::vec2(movementSpeed, 0.0f));
        }
        if (Input::isKeyPressed(Keys::S) || Input::isKeyPressed(Keys::ArrowDown))
        {
            shape.setPosition(glm::vec2(0.0f, movementSpeed));
        }
        if (Input::isKeyPressed(Keys::D) || Input::isKeyPressed(Keys::ArrowRight))
        {
            shape.setPosition(glm::vec2(movementSpeed, 0.0f));
        }

        std::cout << "X: " << shape.getPosition().x << " Y: " << shape.getPosition().x << "\n";
    }

    
    /// <summary>
    /// The Update method is called after the start method and will be called every frame.
    /// Do not set the windowColor after you draw any shapes!
    /// </summary>
    /// <param name="dt">
    /// multiply something by delta if it is tied to framerate
    /// </param>
    void Update(float dt) override
    {
        window->setWindowColor(0.5f, 0.25f, 0.1f, 1.0f);

        if (Input::isKeyPressed(Keys::Escape))
        {
            window->destroy();
        }

        /*
        if (Input::isKeyPressed(Keys::F11))
        {
            isFullscreen = !isFullscreen;
        }

        window.setFullscreen(isFullscreen); // Fullscreen mode is still a bit buggy 
        */

        // Render here:
        //quad.setCamera(camera);
        //renderer->draw(quad);

        controlShape(triangle, dt);

        triangle.setCamera(camera);
        renderer->draw(triangle);

        window->doBackEndStuff();
    }

    /// <summary>
    /// Run calls this after the Update method.
    /// Use this method to deconstruct any classes 
    /// </summary>
    void End() override
    {
        // Make sure to destroy anything if it has a destructor!
        camera.destroy();
        soundManager->destroy();
        renderer->destroy();

        // Call the destructor for window after every other destructor because the window destructor also terminates glfw 
        window->destroy();

        // The window and renderer will be automatically call delete becuase it is a smart pointer
    }
};

RunApplication* CreateApplication()
{
    return new Game;
}