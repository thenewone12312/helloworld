#ifndef VERTEX_SHADER_H
#define VERTEX_SHADER_H

#include <shaders/Shader.h>

class VertexShader : public Shader
{
    public:
        VertexShader(const char* vertexShaderSource);
};

#endif