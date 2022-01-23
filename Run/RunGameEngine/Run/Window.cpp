#include "Window.h"

namespace Run {

    void GLAPIENTRY errorCallback(
        GLenum source,
        GLenum type,
        GLuint id,
        GLenum severity,
        GLsizei length,
        const GLchar* message,
        const void* userParam)
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


    void windowSizeCallBack(GLFWwindow* window, int width, int height)
    {
        Window* win = (Window*)(glfwGetWindowUserPointer(window));
        win->m_width = width;
        win->m_height = height;
        glViewport(0, 0, width, height);
    }


    Window::Window(float w, float h, const std::string& title, GLFWmonitor* monitor, GLFWwindow* share, bool VsyncOn)
    {
        /* Initialize the library */
        if (!glfwInit())
            std::cout << "ERROR: FAILED TO INIT GLFW";

        m_width = w;
        m_height = h;

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

        /* Create a windowed mode window and its OpenGL context */
        m_window = glfwCreateWindow(w, h, title.c_str(), monitor, share);
        if (!m_window)
        {
            glfwTerminate();
            std::cout << "ERROR: FAILED TO INIT GLFW WINDOW!";
        }
        /* Make the window's context current */
        glfwMakeContextCurrent(m_window);

        glfwSetWindowUserPointer(m_window, this);

        glfwSetWindowSizeCallback(m_window, windowSizeCallBack);

        if (!VsyncOn)
        {
            glfwSwapInterval(0);
        }

        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
            glfwTerminate();
            std::cout << "ERROR: FAILED TO INIT GLAD";
        }

        glViewport(0, 0, w, h);


        // Debug mode
        //glEnable(GL_DEBUG_OUTPUT);
        //glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
        //glDebugMessageCallback(errorCallback, nullptr);
    }

    Window::Window()
    {
        m_window = nullptr;
        m_width = NULL;
        m_height = NULL;
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
}
