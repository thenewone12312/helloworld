#include "VAO.h"

VAO::VAO(){
    glGenVertexArrays(1, &ID);
};

VAO::~VAO(){
    Delete();
};

void VAO::linkAttrib(VBO &vbo, unsigned int layout, unsigned int numComponents, GLenum type, GLsizeiptr stride, void* offset){
    vbo.bind();
    glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
    glEnableVertexAttribArray(layout);
};



void VAO::bind(){
    glBindVertexArray(ID);
};

void VAO::unbind(){
    glBindVertexArray(0);
};

void VAO::Delete(){
    glDeleteVertexArrays(1, &ID);
};