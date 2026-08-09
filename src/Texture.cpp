#include "Texture.h"

Texture::Texture(const std::string& path)
    : width(0), height(0), channels(0), data(nullptr), ID(0)
{
    data = stbi_load(path.c_str(), &width, &height, &channels, STBI_rgb_alpha);
    if (!data) {
        std::cerr << "Failed to load texture: " << path << " - " << stbi_failure_reason() << std::endl;
        return;
    }

    glGenTextures(1, &ID);
    glActiveTexture(GL_TEXTURE0);
    bind();
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    unbind();

    stbi_image_free(data);
};

Texture::~Texture()
{
    Delete();
};

void Texture::bind() {
    glBindTexture(GL_TEXTURE_2D, ID);
};

void Texture::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
};

void Texture::Delete() {
    glDeleteTextures(1, &ID);
};