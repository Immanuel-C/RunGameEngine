#include <Run.h>

class Game : public Run::RunApplication
{
public:
    std::unique_ptr<Run::Renderer> renderer = std::make_unique<Run::Renderer>();
    std::unique_ptr<Run::SoundManager> soundManager = std::make_unique<Run::SoundManager>();

    Run::Camera camera;

    Run::Shape quad1;
    Run::Shape quad2;
    Run::Shape quad3;    
    Run::Shape quad4;
    Run::Shape quad5;
    Run::Shape quad6;
    
    Run::Scene scene = Run::Scene(7);

    /// <summary>
    /// The start method is called before the Update method and is kind of like the constructor for the class
    /// </summary>
    void Start() override
    {
        /// Make sure to init the window before the camera
        window = std::make_unique<Run::Window>(1280, 720, "Run Game Engine Example", nullptr, nullptr, false); // the last param is if Vsync is on  
        
        Run::Input::Input();


        camera = Run::Camera(0.0f, window->getWidth(), 0.0f, window->getHeight(), 0.1f, 100.0f);
        /// We set the cameras's z position to -1 becuase all other objects z position is 0 so 
        /// the camera and the other objects would be in the same z position and the objects 
        /// would get clipped out of our screen 
        camera.setPosition({0.0f, 0.0f, -1.0f});

        quad1 = renderer->createQuad(0.0f, { 600.0f, 50.0f, 0.0f }, { 60.0f, 50.0f }, Run::LoadFile::loadShader("Res/Shader/VertShader.glsl", "Res/Shader/FragShader.glsl"), Run::LoadFile::loadTexture("Res/Textures/Lake.jpg"));
        quad2 = renderer->createQuad(0.0f, { 250.0f, 25.0f, 0.0f }, { 60.0f, 50.0f }, Run::LoadFile::loadShader("Res/Shader/VertShader.glsl", "Res/Shader/FragShader.glsl"), Run::LoadFile::loadTexture("Res/Textures/Lake.jpg"));
        quad3 = renderer->createQuad(0.0f, { 100.0f, 75.0f, 0.0f }, { 60.0f, 50.0f }, Run::LoadFile::loadShader("Res/Shader/VertShader.glsl", "Res/Shader/FragShader.glsl"), Run::LoadFile::loadTexture("Res/Textures/Lake.jpg"));
        quad4 = renderer->createQuad(0.0f, { 400.0f, 50.0f, 0.0f }, { 60.0f, 50.0f }, Run::LoadFile::loadShader("Res/Shader/VertShader.glsl", "Res/Shader/FragShader.glsl"), Run::LoadFile::loadTexture("Res/Textures/Lake.jpg"));
        quad5 = renderer->createQuad(0.0f, { 150.0f, 25.0f, 0.0f }, { 60.0f, 50.0f }, Run::LoadFile::loadShader("Res/Shader/VertShader.glsl", "Res/Shader/FragShader.glsl"), Run::LoadFile::loadTexture("Res/Textures/Lake.jpg"));
        quad6 = renderer->createQuad(0.0f, { 100.0f, 250.0f, 0.0f }, { 60.0f, 50.0f }, Run::LoadFile::loadShader("Res/Shader/VertShader.glsl", "Res/Shader/FragShader.glsl"), Run::LoadFile::loadTexture("Res/Textures/Lake.jpg"));
        
        scene.pushBackShape(&quad1);
        scene.pushBackShape(&quad2);
        scene.pushBackShape(&quad3);
        scene.pushBackShape(&quad4);
        scene.pushBackShape(&quad5);
        scene.pushBackShape(&quad6);
    
    }

    const float MOVEMENT_SPEED = 1000.0f;
    /// <summary>
    /// The Update method is called after the start method and will be called every frame. Do not set the windowColor after you draw any shapes!
    /// </summary>
    /// <param name="dt">
    /// multiply something by delta if it is tied to framerate
    /// </param>
    void Update(float dt) override
    {
        window->setWindowColor(0.5f, 0.25f, 0.1f, 1.0f);

        scene.setCamera(camera);


        if (Run::Input::isKeyPressed(Run::Keys::W) || Run::Input::isKeyPressed(Run::Keys::ArrowUp))
        {
            quad1.move({0.0f, MOVEMENT_SPEED * dt, 0.0f});
        }
        if (Run::Input::isKeyPressed(Run::Keys::A) || Run::Input::isKeyPressed(Run::Keys::ArrowLeft))
        {
            quad1.move({ -MOVEMENT_SPEED * dt, 0.0f, 0.0f });
        }
        if (Run::Input::isKeyPressed(Run::Keys::S) || Run::Input::isKeyPressed(Run::Keys::ArrowDown))
        {
            quad1.move({ 0.0f, -MOVEMENT_SPEED * dt, 0.0f });
        }
        if (Run::Input::isKeyPressed(Run::Keys::D) || Run::Input::isKeyPressed(Run::Keys::ArrowRight))
        {
            quad1.move({ MOVEMENT_SPEED * dt, 0.0f, 0.0f });
        }
        
        // Render here:

        renderer->draw(scene);
       
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

        // The window, renderer and soundManager will be automatically call delete becuase it is a smart pointer
    }
};

Run::RunApplication* CreateApplication()
{
    return new Game;
}
