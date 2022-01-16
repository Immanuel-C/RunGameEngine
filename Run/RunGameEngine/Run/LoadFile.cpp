#include "LoadFile.h"
#include <stb_image.h>
#include <iostream>

namespace Run {

    Texture LoadFile::loadTexture(const char* fileLocation)
    {
        stbi_set_flip_vertically_on_load(true);

        int width, height, nrchannels;
        unsigned char* data = stbi_load(fileLocation, &width, &height, &nrchannels, 0);

        if (data == nullptr)
            printf("TEXTURE ERROR: FAILED TO LOAD TEXTURE AT %s\n", fileLocation);

        return Texture(data, width, height, nrchannels);
    }

    Shader LoadFile::loadShader(const char* vertexShaderFileLocation, const char* fragmentShaderFileLocation)
    {
        // 1. retrieve the vertex/fragment source code from filePath
        std::string vertexCode;
        std::string fragmentCode;
        std::ifstream vShaderFile;
        std::ifstream fShaderFile;
        // ensure ifstream objects can throw exceptions:
        vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        try
        {
            // open files
            vShaderFile.open(vertexShaderFileLocation);
            fShaderFile.open(fragmentShaderFileLocation);
            std::stringstream vShaderStream, fShaderStream;
            // read file's buffer contents into streams
            vShaderStream << vShaderFile.rdbuf();
            fShaderStream << fShaderFile.rdbuf();
            // close file handlers
            vShaderFile.close();
            fShaderFile.close();
            // convert stream into string
            vertexCode = vShaderStream.str();
            fragmentCode = fShaderStream.str();
        }
        catch (std::ifstream::failure e)
        {
            std::cout << "INPUT FILE STREAM ERROR: FAILED TO LOAD SHADER!";
        }


        return Shader(vertexCode.c_str(), fragmentCode.c_str());
    }
}
