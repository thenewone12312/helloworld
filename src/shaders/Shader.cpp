#include "shaders/Shader.h"
#include <fstream>
#include <sstream>
#include <iostream>

//shader is a basic class
//vertex and fragment inherit this

Shader::Shader(const char* shaderSource, GLenum shaderType)
{
    //constructor
    ID = glCreateShader(shaderType);
    std::string code = loadFile(shaderSource);
    std::cout << "Shader source:\n";
    std::cout << code << "\n";
    const char* codeCStr = code.c_str();

    glShaderSource(ID, 1, &codeCStr, nullptr);
    glCompileShader(ID);

    checkErrors();
}

Shader::~Shader()
{
    //destructor
    glDeleteShader(ID);
}

unsigned int Shader::getID() const
{
    return ID;
}

std::string Shader::loadFile(const char* filePath)
{
    std::ifstream file(filePath);
    if (!file.is_open())
    {
        std::cerr << "Failed to open file: " << filePath << std::endl;
        return "";
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

void Shader::checkErrors()
{
    //ERORRS FRICK YOU ERRORS GO KYS (keep yourself safe obv obv)
    int success;
    char infoLog[512]; //array for storing characters (char)
    glGetShaderiv(ID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(ID, 512, nullptr, infoLog);
        std::cerr << "ERROR::SHADER::" << (ID == GL_FRAGMENT_SHADER ? "FRAGMENT" : "VERTEX") << "::COMPILATION_FAILED\n"
        << infoLog << std::endl;
    }
}
