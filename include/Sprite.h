#pragma once

// #include 
#include <vector>

#include "vector.h"
#include "Texture.h"


class Sprite{
    public:
        Sprite(std::vector<vec2>* vertices, Texture* texture=nullptr);

    private:
        ;
        Texture* texture;

};