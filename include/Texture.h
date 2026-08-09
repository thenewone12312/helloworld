#pragma once

#include <string>
#include <iostream>
#include <glad/glad.h>

#include <stb/image.h>

class Texture {
public:
    Texture(const std::string& path);
    ~Texture();

    void bind();
    void unbind();
    void Delete();
    
    unsigned int getID();

private:
    int width, height, channels;
    unsigned char* data;
    unsigned int ID;
};