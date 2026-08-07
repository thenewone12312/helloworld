#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

#include "VertexShader.h"
#include "FragmentShader.h"

class ShaderProgram
{
    public:
        ShaderProgram(
            const VertexShader& vertexShader,
            const FragmentShader& fragmentShader);

        ~ShaderProgram();

        void use() const;

        unsigned int getID() const;

    private:
        unsigned int ID;

        void checkErrors();
};

#endif
