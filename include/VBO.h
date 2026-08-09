#pragma once

#include <glad/glad.h>

class VBO{
    public:
        VBO(GLfloat* vertices, GLsizeiptr size);
        ~VBO();
        
        unsigned int getID();
        void bind();
        void unbind();
        void Delete();

    private:
        unsigned int ID;



};