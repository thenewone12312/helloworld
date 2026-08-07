#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <string>

class Shader
{
    public: //essentially the same as vertex shader
        Shader(const char* shaderSource, GLenum shaderType);
        virtual ~Shader();

        unsigned int getID() const;

    protected: //children will use this
        unsigned int ID;

    private:
        std::string loadFile(const char* filePath);
        void checkErrors();
};

#endif