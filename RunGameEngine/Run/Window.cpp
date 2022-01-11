#include "Window.h"

void GLAPIENTRY errorCallback(
            GLenum source,
            GLenum type,
            GLuint id,
            GLenum severity,
            GLsizei length,
            const GLchar *message,
            const void *userParam)
{
    const char* severityC = "";
    const char* typeC = "";


    switch (severity)
    {
    case GL_DEBUG_SEVERITY_LOW:
        severityC = "SEVERITY LOW: WARNING";
        break;
    case GL_DEBUG_SEVERITY_MEDIUM:
        severityC = "SEVERITY LOW: WARNING";
        break;
    case GL_DEBUG_SEVERITY_HIGH:
        severityC = "SEVERITY HIGH";
        break;
    case GL_DEBUG_SEVERITY_NOTIFICATION:
        severityC = "SEVERITY LOW, WARNING";
        break;
    default:
        severityC = "UNKNOWN SEVERITY!";
        break;
    }

    switch (type)
    {
    case GL_DEBUG_TYPE_ERROR:
        typeC = "ERROR";
        break;
    case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:
        typeC = "SOMETHING IS DEPRACATED";
        break;
    case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:
        typeC = "UNDEFINED BEHAVIOR";
        break;
    case GL_DEBUG_TYPE_PORTABILITY:
        typeC = "NOT PORTABLE";
        break;
    case GL_DEBUG_TYPE_PERFORMANCE:
        typeC = "PREFORMANCE ISSUES";
        break;
    case GL_DEBUG_TYPE_MARKER:
        typeC = "GL_DEBUG_TYPE_MARKER";
        break;
    case GL_DEBUG_TYPE_PUSH_GROUP:
        typeC = "GL_DEBUG_TYPE_PUSH_GROUP";
        break;
    case GL_DEBUG_TYPE_POP_GROUP:
        typeC = "GL_DEBUG_TYPE_POP_GROUP";
        break;
    case GL_DEBUG_TYPE_OTHER:
        typeC = "OTHER";
        break;
    }

    std::cout << "GL ERROR: \n" << "ERROR TYPE: " << typeC << ",\n" << "SEVERITY: " << severityC << ",\n" << "MESSAGE: " << message << "\n" << "LENGTH: " << length << "\n\n\n";
}


Window::Window(float w, float h, const char* title, GLFWmonitor* monitor, GLFWwindow* share)
{
    /* Initialize the library */
    if (!glfwInit())
        std::cout << "ERROR: FAILED TO INIT GLFW";

    m_width = w;
    m_height = h;


    /* Create a windowed mode window and its OpenGL context */
    m_window = glfwCreateWindow(w, h, title, monitor, share);
    if (!m_window)
    {
        glfwTerminate();
        std::cout << "ERROR: FAILED TO INIT GLFW WINDOW!";
    }
    /* Make the window's context current */
    glfwMakeContextCurrent(m_window);

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        glfwTerminate();
        std::cout << "ERROR: FAILED TO INIT GLAD";
    }

    glViewport(0, 0, w, h);
    
    // Debug mode
    //glEnable(GL_DEBUG_OUTPUT);
    //glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
    //glDebugMessageCallback(errorCallback, (void*)m_window);
}

GLFWwindow* Window::getGlfwWindow()
{
    return m_window;
}

bool Window::shouldClose()
{
    return glfwWindowShouldClose(m_window);
}

void Window::setWindowColor(float r, float g, float b, float a)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(r, g, b, a);
}

void Window::doBackEndStuff()
{
    /* Swap front and back buffers */
    glfwSwapBuffers(m_window);

    /* Poll for and process events */
    glfwPollEvents();
}

float Window::getWidth()
{
    return m_width;
}

float Window::getHeight()
{
    return m_height;
}

void Window::destroy()
{  
    glfwDestroyWindow(m_window);
    glfwTerminate();
}

void Window::setFullscreen(bool fullscreen)
{
    GLFWmonitor* monitor = glfwGetPrimaryMonitor();
    const GLFWvidmode* mode = glfwGetVideoMode(monitor);

    if (fullscreen) {
        glfwSetWindowMonitor(m_window, monitor, 0, 0, mode->width, mode->height, mode->refreshRate);
        glViewport(0, 0, mode->width, mode->height);
    }

    if (!fullscreen) {
        glfwSetWindowMonitor(m_window, nullptr, 100, 100, m_width, m_height, GLFW_DONT_CARE);
        glViewport(0, 0, m_width, m_height);
    }
}
