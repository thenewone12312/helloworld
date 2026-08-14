#pragma once
#include "vector.h"
#include "Sprite.h"

class Object{
    public:
        Object(Sprite* sprite);
        Object(Texture* texture);
        void setPosition(vec2 position);
        vec2 getPosition();
        void addPosition(vec2 position);
        
        void setVelocity(vec2 velocity);
        vec2 getVelocity();
        void addVelocity(vec2 velocity);

        void setSpeed(int speed);
        int getSpeed();
        void addSpeed(int speed);

        void setScale(vec2 scale);
        vec2 getScale();
        void scaleUp(vec2 scale);
        void setRotationRadians(float radians);
        float getRotationRadians();
        void rotateRadians(float radians);
        void setSprite(Sprite* Sprite);
        Sprite* getSprite();
        void draw(int &transformLoc, int &scaleLoc);
        void uploadMesh();
        
        void processVelocity(float deltaTime); //or whatever you wanna call it
        void processVelocity(float deltaTime, vec2 velocity);

        static Object defaultObject;

    private:
        vec2 position;

        vec2 velocity;
        int speed = 1;

        vec2 scale;
        float rotationRadians;
        Sprite* sprite;
        vec2 normal;
        unsigned int VBO, VAO, EBO;
        GLsizei indexCount = 0;

};