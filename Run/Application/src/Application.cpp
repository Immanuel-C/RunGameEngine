#include <Run.h>

class Game : public Run::RunApplication
{
public:
    std::unique_ptr<Run::Renderer> renderer = std::make_unique<Run::Renderer>();
    std::unique_ptr<Run::SoundManager> soundManager = std::make_unique<Run::SoundManager>();

    Run::Camera camera;

    Run::Shape quad;

    /// <summary>
    /// The start method is called before the Update method and is kind of like the constructor for the class
    /// </summary>
    void Start() override
    {
        // Make sure to init the window before the camera
        window = std::make_shared<Run::Window>(800, 600, "Run Game Engine Example", nullptr, nullptr, false); // the last param is if Vsync is on  
        
        Run::Gui::Gui(window); // The Gui class is a wrapper for Dear ImGui
        Run::Input::Input(window);

        //camera = Camera(-window->getWidth(), window->getWidth(), -window->getHeight(), window->getHeight());
        camera = Run::Camera(0.0f, window->getWidth(), 0.0f, window->getHeight());
        // We set the cameras's z position to -1 becuase all other objects z position is 0 so 
        // the camera and the other objects would be in the same z position and the objects 
        // would get clipped out of our screen 
        camera.setPosition({0.0f, 0.0f, -1.0f});

        soundManager->play("Res/Audio/getout.ogg");

        quad = renderer->createQuad({ 100.0f, 100.0f, 0.0f }, { 50.0f, 50.0f }, Run::LoadFile::loadShader("Res/Shader/VertShader.glsl", "Res/Shader/FragShader.glsl"), Run::LoadFile::loadTexture("Res/Textures/Lake.jpg"));
    }

    bool isFullscreen = false;

    void controlShape(Run::Shape shape, float dt)
    {
        float movementSpeed = 10.0f;

        float positionX = shape.getPosition().x;
        float positionY = shape.getPosition().y;

        if (Run::Input::isKeyPressed(Run::Keys::W) || Run::Input::isKeyPressed(Run::Keys::ArrowUp))
        {
            positionY += movementSpeed;
        }
        if (Run::Input::isKeyPressed(Run::Keys::A) || Run::Input::isKeyPressed(Run::Keys::ArrowLeft))
        {
            positionX -= movementSpeed;
        }
        if (Run::Input::isKeyPressed(Run::Keys::S) || Run::Input::isKeyPressed(Run::Keys::ArrowDown))
        {
            positionY -= movementSpeed;
        }
        if (Run::Input::isKeyPressed(Run::Keys::D) || Run::Input::isKeyPressed(Run::Keys::ArrowRight))
        {
            positionX += movementSpeed;
        }

        shape.setPosition({positionX, positionY});

       // std::cout << "X: " << shape.getPosition().x << " Y: " << shape.getPosition().y << "\n";
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
        
        Run::Gui::newFrame();

        /*
        if (Input::isKeyPressed(Keys::F11))
        {
            isFullscreen = !isFullscreen;
        }

        window.setFullscreen(isFullscreen); // Fullscreen mode is still a bit buggy 
        */

        controlShape(quad, dt);

        // Render here:
        quad.setCamera(camera);
        renderer->draw(quad);

        ImGui::Begin("Control Window");

        // position
        float newPosition[2] = { quad.getPosition().x , quad.getPosition().y};
        ImGui::DragFloat2("Position", newPosition);
        quad.setPosition({ newPosition[0], newPosition[1] });

        // rotation
        float rotation = quad.getRotation();
        ImGui::DragFloat("Rotation", &rotation);
        quad.setRotation(rotation);

        //scale
        float newScale[2] = { quad.getScale().x, quad.getScale().y };
        ImGui::DragFloat2("Scale", newScale);
        quad.setScale({ newScale[0], newScale[1]});

        
        ImGui::End();

        Run::Gui::render();

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
        Run::Gui::destroy();
        // Call the destructor for window after every other destructor because the window destructor also terminates glfw 
        window->destroy();

        // The window and renderer will be automatically call delete becuase it is a smart pointer
    }
};

Run::RunApplication* CreateApplication()
{
    return new Game;
}