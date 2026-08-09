#pragma once

#include <glad/glad.h>
#include "VBO.h"

class VAO{
    public:
        VAO();
        ~VAO();
        
        unsigned int getID();
        void linkAttrib(VBO &vbo, unsigned int layout, unsigned int numComponents, GLenum type, GLsizeiptr stride, void* offset);
        void bind();
        void unbind();
        void Delete();


    private:
        unsigned int ID;

};