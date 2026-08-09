#pragma once

#include <glad/glad.h>

class EBO{
    public:
        EBO(unsigned int* indices, GLsizeiptr size);
        ~EBO();
        
        unsigned int getID();
        void bind();
        void unbind();
        void Delete();

    private:
        unsigned int ID;



};