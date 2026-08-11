#pragma once

// #include 
#include <vector>

#include "vector.h"
#include "Polygon.h"
#include "Texture.h"


class Sprite{
    public:
        Sprite(std::vector<vec2>* vertices, Texture* texture=nullptr);

    private:
        Polygon* shape;
        Texture* texture;

};