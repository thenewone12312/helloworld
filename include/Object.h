#pragma once
#include "vector.h"
#include "Texture.h"

class Object{
    public:
        Object(vec2 position=vec2(0.0f), vec2 scale=vec2(1.0f), float rotationRadians=0.0f, Texture* texture=nullptr);
        void setPosition(vec2 position);
        void addPosition(vec2 position);
        void setScale(vec2 scale);
        void scaleUp(vec2 scale);
        void setRotationRadians(float radians);
        void rotateRadians(float radians);
        void setTexture(Texture* texture);

    private:
        vec2 position;
        vec2 scale;
        float rotationRadians;
        Texture* texture;
};