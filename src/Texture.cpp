#include "Texture.h"

Texture::Texture(const std::string& path)
{

    glGenTextures(1, &ID);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, ID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    // int width, height, channels;

    // unsigned char* data = stbi_load(
    //     path.c_str(),
    //     &width,
    //     &height,
    //     &channels,
    //     0
    // );

    // if (!data) {
    //     std::cout << "Failed to load texture: " << path << std::endl;
    //     ID = 0;
    //     return;
    // }

    // glGenTextures(1, &ID);
    // glBindTexture(GL_TEXTURE_2D, ID);

    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    // glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // GLenum format = channels == 4 ? GL_RGBA : GL_RGB;

    // glTexImage2D(
    //     GL_TEXTURE_2D,
    //     0,
    //     format,
    //     width,
    //     height,
    //     0,
    //     format,
    //     GL_UNSIGNED_BYTE,
    //     data
    // );

    // glGenerateMipmap(GL_TEXTURE_2D);

    // stbi_image_free(data);
}

Texture::~Texture()
{
    glDeleteTextures(1, &ID);
}