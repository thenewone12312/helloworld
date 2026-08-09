#include "VAO.h"

VAO::VAO(){
    glGenVertexArrays(1, &ID);
};

VAO::~VAO(){
    Delete();
};

void VAO::linkVBO(VBO &vbo, unsigned int layout){
    vbo.bind();
    glVertexAttribPointer(layout, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
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