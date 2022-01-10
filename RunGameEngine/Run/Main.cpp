// Run
#include "RunInclude.h"


int main(void)
{
    /* Create a windowed mode window and its OpenGL context */
    Window window = Window(800, 600, "Run Game Engine Example", nullptr, nullptr);

    Renderer renderer;

    Input::Input(window);

    Camera camera(glm::vec3(0.0f, 0.0f, 0.0f));

    SoundManager soundManager;

    Shape triangles[11];
    float sizeOfTriangles = sizeof(triangles) / sizeof(triangles[0]);
    
    {
        std::vector<float> NDCvertices =
        {
            // positions    // texture coords
             800.0f, 100.0f,  1.0f, 0.0f,   // bottom right
             750.0f, 500.0f,  0.5f, 1.0f,   // top 
             600.0f, 100.0f,  0.0f, 0.0f,   // bottom left
             600.0f, 250.0f,  0.0f, 0.0f,   // bottom left
        };

        std::vector<unsigned int> NDCindices = {  // note that we start from 0!
            0, 1, 3,   // first triangle
        };

        triangles[0] = renderer.createShape(NDCvertices, NDCindices, LoadFile::loadShader("Res/Shader/VertShader.glsl", "Res/Shader/FragShader.glsl"), LoadFile::loadTexture("Res/Textures/Lake.jpg"));
    }
    {
        std::vector<float> NDCvertices =
        {
            // positions    // texture coords
             500.0f, 100.0f,  1.0f, 0.0f,   // bottom right
             550.0f, 500.0f,  0.5f, 1.0f,   // top 
             400.0f, 100.0f,  0.0f, 0.0f,   // bottom left
        };

        std::vector<unsigned int> NDCindices = {  // note that we start from 0!
            0, 1, 2,   // first triangle
        };

        triangles[1] = renderer.createShape(NDCvertices, NDCindices, LoadFile::loadShader("Res/Shader/VertShader.glsl", "Res/Shader/FragShader.glsl"), LoadFile::loadTexture("Res/Textures/WaterFall.jpg"));
    }
    {
        std::vector<float> NDCvertices =
        {
            // positions    // texture coords
             1000.0f, 100.0f,  1.0f, 0.0f,   // bottom right
             750.0f, 500.0f,  0.5f, 1.0f,   // top 
             900.0f, 100.0f,  0.0f, 0.0f,   // bottom left
        };

        std::vector<unsigned int> NDCindices = {  // note that we start from 0!
            0, 1, 2,   // first triangle
        };

        triangles[2] = renderer.createShape(NDCvertices, NDCindices, LoadFile::loadShader("Res/Shader/VertShader.glsl", "Res/Shader/FragShader.glsl"), LoadFile::loadTexture("Res/Textures/container.jpg"));
    }    
    {
        std::vector<float> NDCvertices =
        {
            // positions    // texture coords
             -1000.0f, 100.0f,  1.0f, 0.0f,   // bottom right
             -750.0f, -500.0f,  0.5f, 1.0f,   // top 
             900.0f, 100.0f,  0.0f, 0.0f,   // bottom left
        };

        std::vector<unsigned int> NDCindices = {  // note that we start from 0!
            0, 1, 2,   // first triangle
        };

        triangles[3] = renderer.createShape(NDCvertices, NDCindices, LoadFile::loadShader("Res/Shader/VertShader.glsl", "Res/Shader/FragShader.glsl"), LoadFile::loadTexture("Res/Textures/wall.jpg"));
    }    
    {
        std::vector<float> NDCvertices =
        {
            // positions    // texture coords
             1000.0f, -100.0f,  1.0f, 0.0f,   // bottom right
             750.0f, -500.0f,  0.5f, 1.0f,   // top 
             900.0f, -100.0f,  0.0f, 0.0f,   // bottom left
        };

        std::vector<unsigned int> NDCindices = {  // note that we start from 0!
            0, 1, 2,   // first triangle
        };

        triangles[4] = renderer.createShape(NDCvertices, NDCindices, LoadFile::loadShader("Res/Shader/VertShader.glsl", "Res/Shader/FragShader.glsl"), LoadFile::loadTexture("Res/Textures/Forest.jpg"));
    }
    {
        std::vector<float> NDCvertices =
        {
            // positions    // texture coords
             -1000.0f, -100.0f,  1.0f, 0.0f,   // bottom right
             750.0f, 500.0f,  0.5f, 1.0f,   // top 
             -900.0f, -100.0f,  0.0f, 0.0f,   // bottom left
        };

        std::vector<unsigned int> NDCindices = {  // note that we start from 0!
            0, 1, 2,   // first triangle
        };

        triangles[5] = renderer.createShape(NDCvertices, NDCindices, LoadFile::loadShader("Res/Shader/VertShader.glsl", "Res/Shader/FragShader.glsl"), LoadFile::loadTexture("Res/Textures/wall.jpg"));
    }
    {
        std::vector<float> NDCvertices =
        {
            // positions    // texture coords
             1000.0f, -100.0f,  1.0f, 0.0f,   // bottom right
             -750.0f, -500.0f,  0.5f, 1.0f,   // top 
             900.0f, -100.0f,  0.0f, 0.0f,   // bottom left
        };

        std::vector<unsigned int> NDCindices = {  // note that we start from 0!
            0, 1, 2,   // first triangle
        };

        triangles[6] = renderer.createShape(NDCvertices, NDCindices, LoadFile::loadShader("Res/Shader/VertShader.glsl", "Res/Shader/FragShader.glsl"), LoadFile::loadTexture("Res/Textures/WaterFall.jpg"));
    }
    {
        std::vector<float> NDCvertices =
        {
            // positions    // texture coords
             -1000.0f, -100.0f,  1.0f, 0.0f,   // bottom right
             -750.0f, -500.0f,  0.5f, 1.0f,   // top 
             900.0f, -100.0f,  0.0f, 0.0f,   // bottom left
        };

        std::vector<unsigned int> NDCindices = {  // note that we start from 0!
            0, 1, 2,   // first triangle
        };

        triangles[7] = renderer.createShape(NDCvertices, NDCindices, LoadFile::loadShader("Res/Shader/VertShader.glsl", "Res/Shader/FragShader.glsl"), LoadFile::loadTexture("Res/Textures/container.jpg"));
    }
    {
        std::vector<float> NDCvertices =
        {
            // positions    // texture coords
             -1000.0f, -100.0f,  1.0f, 0.0f,   // bottom right
             750.0f, -500.0f,  0.5f, 1.0f,   // top 
             900.0f, 100.0f,  0.0f, 0.0f,   // bottom left
        };

        std::vector<unsigned int> NDCindices = {  // note that we start from 0!
            0, 1, 2,   // first triangle
        };

        triangles[8] = renderer.createShape(NDCvertices, NDCindices, LoadFile::loadShader("Res/Shader/VertShader.glsl", "Res/Shader/FragShader.glsl"), LoadFile::loadTexture("Res/Textures/Lake.jpg"));
    }
    {
        std::vector<float> NDCvertices =
        {
            // positions    // texture coords
             -1000.0f, 100.0f,  1.0f, 0.0f,   // bottom right
             -750.0f, -500.0f,  0.5f, 1.0f,   // top 
             900.0f,  100.0f,  0.0f, 0.0f,   // bottom left
        };

        std::vector<unsigned int> NDCindices = {  // note that we start from 0!
            0, 1, 2,   // first triangle
        };

        triangles[9] = renderer.createShape(NDCvertices, NDCindices, LoadFile::loadShader("Res/Shader/VertShader.glsl", "Res/Shader/FragShader.glsl"), LoadFile::loadTexture("Res/Textures/Forest.jpg"));
    }  
    {
        std::vector<float> NDCvertices =
        {
            // positions    // texture coords
             1000.0f, -100.0f,  1.0f, 0.0f,   // bottom right
             -1050.0f, 500.0f,  0.5f, 1.0f,   // top 
             -500.0f, -10.0f,  0.0f, 0.0f,   // bottom left
        };

        std::vector<unsigned int> NDCindices = {  // note that we start from 0!
            0, 1, 2,   // first triangle
        };

        triangles[10] = renderer.createShape(NDCvertices, NDCindices, LoadFile::loadShader("Res/Shader/VertShader.glsl", "Res/Shader/FragShader.glsl"), LoadFile::loadTexture("Res/Textures/wall.jpg"));
    }    
    {
        std::vector<float> NDCvertices =
        {
            // positions    // texture coords
             -1000.0f, -100.0f,  1.0f, 0.0f,   // bottom right
             -1050.0f, 500.0f,  0.5f, 1.0f,   // top 
             -500.0f, 10.0f,  0.0f, 0.0f,   // bottom left
        };

        std::vector<unsigned int> NDCindices = {  // note that we start from 0!
            0, 1, 2,   // first triangle
        };

        triangles[10] = renderer.createShape(NDCvertices, NDCindices, LoadFile::loadShader("Res/Shader/VertShader.glsl", "Res/Shader/FragShader.glsl"), LoadFile::loadTexture("Res/Textures/wall.jpg"));
    }

    int isWireframe = GL_FILL;

    soundManager.play("Res/Audio/explosion.wav");

    /* Loop until the user closes the window */
    while (!window.shouldClose())
    {
        window.setWindowColor(0.25f, 0.123f, 0.65f, 1.0f);
        
        if (Input::isKeyPressed(Keys::F1))
        {
            isWireframe = GL_LINE;
        }

        if (Input::isKeyPressed(Keys::F2))
        {
            isWireframe = GL_FILL;
        }
        glPolygonMode(GL_FRONT_AND_BACK, isWireframe);

        //window.setFullscreen(isFullscreen);

        for (int i = 0; i < sizeOfTriangles; i++)
        {
            triangles[i].setCamera(camera);
            triangles[i].setRotation(120 * i, glm::vec3(0.0f, 0.0f, 1.0f));
            renderer.draw(triangles[i]);
        }

        window.doBackEndStuff();
    }

    soundManager.~SoundManager();
    window.destroy();
    return 0;
}