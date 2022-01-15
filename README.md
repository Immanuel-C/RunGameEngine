# RunGameEngine

A simple low level, single threaded game engine using OpenGL and GLFW for **Windows only**.

**Features:**

- Texture Rendering with OpenGL
- Cameras with OpenGL
- Input with GLFW
- Windowing System with GLFW
- Audio with IrrKlang

If you find any bugs please report them using the issue tab

**Requirments:**

Run only supports graphics cards with the version 4.6 of OpenGL.


**How to build:**

The Run game engine is using the **MSVC** compiler.

**Make sure you have all the irrKlang .dll files and the Res folder in the Application build directory.** the .dll's and the Res folder should already be in the debug build location.

To build, you need to make sure you **right click on the RunGameEngine project and then click build and then press run. Every time you change the files in the game engine you must do the previous instructions**. If you dont The .lib file and the header files may be mismatched and you will get a linking error.

**All the libraries I am using for the game engine**

OpenGL,   
GLAD,   
GLFW,   
GLM,    
IrrKlang,
ImGui
