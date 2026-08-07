#include "ShaderProgram.h"

#include <iostream>

ShaderProgram::ShaderProgram(const VertexShader& vertexShader, const FragmentShader& fragmentShader)
{
    ID = glCreateProgram();
    glAttachShader(ID, vertexShader.getID());
    glAttachShader(ID, fragmentShader.getID());
    glLinkProgram(ID);

    glDetachShader(ID, vertexShader.getID());
    glDetachShader(ID, fragmentShader.getID());

    checkErrors();
}

ShaderProgram::~ShaderProgram()
{
    glDeleteProgram(ID);
}

unsigned int ShaderProgram::getID() const
{
    return ID;
}

void ShaderProgram::use() const
{
    glUseProgram(ID);
}

void ShaderProgram::checkErrors()
{
    int success;
    char infoLog[512];
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(ID, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << 
        infoLog << std::endl;
    }
}