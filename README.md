# RunGameEngine

A simple low level, single threaded game engine using OpenGL and GLFW for **Window only**.

**Features:**

- Texture Rendering with OpenGL
- Cameras (Unfinished) with OpenGL
- Input with GLFW
- Windowing System with GLFW
- Audio with IrrKlang

If you find any bugs please report them using the issue tab

**How to build:**

The Run game engine is using the **MSVC** compiler.

**Make sure you have all the irrKlang .dll files and the Res folder in the Application build directory.** It should already be in the debug compile location.

To build you need to make sure you **right click on the RunGameEngine project and then click build**. If you dont. The .lib file and the header files may be mismatched

**All the libraries I am using for the game engine**

OpenGL,   
GLAD,   
GLFW,   
GLM,    
IrrKlang    
