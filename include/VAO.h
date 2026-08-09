#pragma once

#include <glad/glad.h>
#include "VBO.h"

class VAO{
    public:
        VAO();
        ~VAO();
        
        unsigned int getID();
        void linkVBO(VBO &vbo, unsigned int layout);
        void bind();
        void unbind();
        void Delete();


    private:
        unsigned int ID;

};