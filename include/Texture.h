#pragma once

#include <string>
#include <iostream>
#include <glad/glad.h>

#include <stb/image.h>

class Texture {
public:
    Texture(const std::string& path);
    ~Texture();
    
    GLuint getID() const;

private:
    int width, height, channels;
    unsigned char* data;
    GLuint ID;
};