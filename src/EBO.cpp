#include "EBO.h"

EBO::EBO(unsigned int* indices, GLsizeiptr size){
    glGenBuffers(1, &ID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
};

EBO::~EBO(){
    Delete();
};

unsigned int EBO::getID(){
    return ID;
};

void EBO::bind(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
};

void EBO::unbind(){
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
};

void EBO::Delete(){
    glDeleteBuffers(1, &ID);
}; 