// Run
#include "..\Run.h"

int DeprecatedMain(void)
{
    /* Create a windowed mode window and its OpenGL context */
    Window window = Window(800, 600, "Run Game Engine Example", nullptr, nullptr);

    Renderer renderer;

    Input::Input(window);

    Camera camera(glm::vec3(0.0f, 0.0f, 0.0f));

    SoundManager soundManager;

    Shape triangles[2];
    float sizeOfTriangles = sizeof(triangles) / sizeof(triangles[0]);
    
    {
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

        triangles[0] = renderer.createShape(NDCvertices, NDCindices, LoadFile::loadShader("Res/Shader/VertShader.glsl", "Res/Shader/FragShader.glsl"), LoadFile::loadTexture("Res/Textures/Lake.jpg"));
    }    
    {
        std::vector<float> NDCvertices =
        {
            // positions    // texture coords
             1000.0f,-100.0f,  1.0f, 0.0f,   // bottom right
             850.0f, -500.0f,  0.5f, 1.0f,   // top 
             700.0f, -100.0f,  0.0f, 0.0f,   // bottom left
        };

        std::vector<unsigned int> NDCindices = {  // note that we start from 0!
            0, 1, 2,   // first triangle
        };

        triangles[1] = renderer.createShape(NDCvertices, NDCindices, LoadFile::loadShader("Res/Shader/VertShader.glsl", "Res/Shader/FragShader.glsl"), LoadFile::loadTexture("Res/Textures/Lake.jpg"));
    }

    int isWireframe = GL_FILL;

    soundManager.play("Res/Audio/explosion.wav");

    /* Loop until the user closes the window */

    float colours[3];
    int lengthOfColours = sizeof(colours) / sizeof(colours[0]);

    srand(time(NULL));
    for (int i = 0; i < lengthOfColours; i++)
    {
        colours[i] = (float)(rand() % 256) / 256.0f;
    }

    bool isFullscreen = false;

    while (!window.shouldClose())
    {
        if (Input::isKeyPressed(Keys::Escape))
        {
            window.destroy();
            break;
        }

        window.setWindowColor(colours[0], colours[1], colours[2], 1.0f);
        
        if (Input::isMouseButtonPressed(MouseButtons::SideButton1))
        {
            isWireframe = GL_LINE;
        }

        if (Input::isMouseButtonPressed(MouseButtons::SideButton2))
        {
            isWireframe = GL_FILL;
        }

        glPolygonMode(GL_FRONT_AND_BACK, isWireframe);

        if (Input::isKeyPressed(Keys::F11))
        {
            isFullscreen = !isFullscreen;
        }

        window.setFullscreen(isFullscreen);

        for (int i = 0; i < sizeOfTriangles; i++)
        {
            triangles[i].setCamera(camera);
            triangles[i].setRotation(glfwGetTime(), glm::vec3(0.0f, 0.0f, 1.0f));
            renderer.draw(triangles[i]);
        }

        window.doBackEndStuff();
    }

    soundManager.~SoundManager();
    window.destroy();
    return 0;
}