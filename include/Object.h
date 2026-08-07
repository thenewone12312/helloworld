#pragma once
#include "vector.h"
#include "Sprite.h"

class Object{
    public:
        Object(vec2 position=vec2(0.0f), vec2 scale=vec2(1.0f), float rotationRadians=0.0f, Sprite* sprite=nullptr);
        void setPosition(vec2 position);
        void addPosition(vec2 position);
        void setScale(vec2 scale);
        void scaleUp(vec2 scale);
        void setRotationRadians(float radians);
        void rotateRadians(float radians);
        void setSprite(Sprite* Sprite);

    private:
        vec2 position;
        vec2 scale;
        float rotationRadians;
        Sprite* sprite;
        vec2 normal;
};