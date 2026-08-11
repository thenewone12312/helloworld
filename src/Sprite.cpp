#include "Sprite.h"
#include "Polygon.h"

Sprite::Sprite(std::vector<float>* vertices, std::vector<unsigned int>* indices, Texture* texture){
    if(vertices != nullptr && indices != nullptr){
        this->textureUV = static_cast<void*>(new Polygon(*vertices, *indices));
    }
    else{
        this->textureUV = static_cast<void*>(new Polygon());
    }
    this->texture = texture;
}

Sprite::Sprite(Texture* texture){
    this->textureUV = static_cast<void*>(new Polygon());
    this->texture = texture;
}

Sprite::Sprite(){
    this->textureUV = static_cast<void*>(new Polygon());
}

Sprite::~Sprite(){
    if(this->textureUV) delete static_cast<Polygon*>(this->textureUV);
}

std::vector<float> Sprite::getVertexData(){
    if(!textureUV) return {};
    return static_cast<Polygon*>(textureUV)->getVertexData();
}

std::vector<unsigned int> Sprite::getIndexData(){
    if(!textureUV) return {};
    return static_cast<Polygon*>(textureUV)->getIndexData();
}

Texture* Sprite::getTexture(){
    return texture;
}