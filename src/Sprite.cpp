#include "Sprite.h"

Sprite::Sprite(std::vector<vec2>* vertices, Texture* texture){
    this->vertices = vertices;
    this->texture = texture;
};