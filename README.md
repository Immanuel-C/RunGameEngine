# RunGameEngine

A simple low level, single threaded game engine using OpenGL and GLFW for **Windows only**.

# Features:

- Texture Rendering
- Input
- Windowing System
- Audio

If you find any bugs please report them using the issue tab.

# Requirments:

Run only supports graphics cards with the version 4.6 of OpenGL and requires Windows for now.

# How to build The Example Project:

The Run game engine is using the **MSVC** compiler.

**Make sure you have all the irrKlang and RunGameEngine .dll files and the Res folder in the Application build directory.** 

To build, just press run in visual studio.

# Using The Run Binaries

You should include and link everything as usual (.lib, .dll files) but **make sure you include the Run folder with all the header files in the compiler and make sure Run.h is outside of the Run folder!**. The Res folder is there so you can use the default example code in Application.cpp. **You probably should copy and paste the example code from Applcation into your main file.**

# All the libraries I am using for the game engine

OpenGL,   
GLAD,   
GLFW,   
GLM,    
IrrKlang
