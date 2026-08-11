#pragma once

// #include 
#include <vector>

#include "vector.h"
#include <memory>
#include "Texture.h"

class Polygon;

class Sprite{
    public:
        Sprite(std::vector<float>* vertices, std::vector<unsigned int>* indices=nullptr, Texture* texture=nullptr);
        Sprite(Texture* texture);
        Sprite();
        ~Sprite();
        std::vector<float> getVertexData();
        std::vector<unsigned int> getIndexData();
        Texture* getTexture();

    private:
        void* textureUV;
        Texture* texture;
        vec2 scale;

};