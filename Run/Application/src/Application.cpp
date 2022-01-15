#include <Run.h>

class Game : public RunApplication
{
public:
    std::unique_ptr<Renderer> renderer = std::make_unique<Renderer>();
    std::unique_ptr<SoundManager> soundManager = std::make_unique<SoundManager>();

    Camera camera;

    Shape quad;

    /// <summary>
    /// The start method is called before the Update method and is kind of like the constructor for the class
    /// </summary>
    void Start() override
    {
        // Make sure to init the window before the camera
        window = std::make_shared<Window>(800, 600, "Run Game Engine Example", nullptr, nullptr, false); // the last param is if Vsync is on  
        
        Gui::Gui(window); // The Gui class is a wrapper for Dear ImGui
        Input::Input(window);

        //camera = Camera(-window->getWidth(), window->getWidth(), -window->getHeight(), window->getHeight());
        camera = Camera(0.0f, window->getWidth(), 0.0f, window->getHeight());
        // We set the cameras's z position to -1 becuase all other objects z position is 0 so 
        // the camera and the other objects would be in the same z position and the objects 
        // would get clipped out of our screen 
        camera.setPosition({ 0.0f, 0.0f, -1.0f }); 
        //soundManager->play("Res/Audio/getout.ogg");

        quad = renderer->createQuad({ 100.0f, 100.0f, 0.0f }, { 50.0f, 50.0f }, LoadFile::loadShader("Res/Shader/VertShader.glsl", "Res/Shader/FragShader.glsl"), LoadFile::loadTexture("Res/Textures/Lake.jpg"));
    }

    bool isFullscreen = false;

    void controlShape(Shape shape, float dt)
    {
        float movementSpeed = 10.0f;

        float positionX = shape.getPosition().x;
        float positionY = shape.getPosition().y;

        if (Input::isKeyPressed(Keys::W) || Input::isKeyPressed(Keys::ArrowUp))
        {
            positionY += movementSpeed;
        }
        if (Input::isKeyPressed(Keys::A) || Input::isKeyPressed(Keys::ArrowLeft))
        {
            positionX -= movementSpeed;
        }
        if (Input::isKeyPressed(Keys::S) || Input::isKeyPressed(Keys::ArrowDown))
        {
            positionY -= movementSpeed;
        }
        if (Input::isKeyPressed(Keys::D) || Input::isKeyPressed(Keys::ArrowRight))
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
        
        Gui::newFrame();

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

        Gui::render();

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
        Gui::destroy();
        // Call the destructor for window after every other destructor because the window destructor also terminates glfw 
        window->destroy();

        // The window and renderer will be automatically call delete becuase it is a smart pointer
    }
};

RunApplication* CreateApplication()
{
    return new Game;
}