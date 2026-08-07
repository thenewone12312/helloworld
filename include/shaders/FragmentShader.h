#ifndef FRAGMENT_SHADER_H
#define FRAGMENT_SHADER_H

#include <shaders/Shader.h>

class FragmentShader : public Shader
{
    public: //essentially the same as vertex shader
        FragmentShader(const char* fragmentShaderSource);
};

#endif