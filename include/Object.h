#pragma once
#include "vector.h"
#include "Sprite.h"

class Object{
    public:
        Object(vec2 position=vec2(0.0f), vec2 scale=vec2(1.0f), float rotationRadians=0.0f, Sprite* sprite=nullptr);
        void setPosition(vec2 position);
        vec2 getPosition();
        void addPosition(vec2 position);
        void setVelocity(vec2 velocity);
        vec2 getVelocity();
        void addVelocity(vec2 velocity);
        void setScale(vec2 scale);
        vec2 getScale();
        void scaleUp(vec2 scale);
        void setRotationRadians(float radians);
        float getRotationRadians();
        void rotateRadians(float radians);
        void setSprite(Sprite* Sprite);
        Sprite* getSprite();

    private:
        vec2 position;
        vec2 velocity;
        vec2 scale;
        float rotationRadians;
        Sprite* sprite;
        vec2 normal;
};