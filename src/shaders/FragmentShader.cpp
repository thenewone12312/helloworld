#include "FragmentShader.h"
#include <fstream>
#include <sstream>
#include <iostream>


FragmentShader::FragmentShader(const char* FragmentShaderSource)
: Shader(FragmentShaderSource, GL_FRAGMENT_SHADER)
{  
}
