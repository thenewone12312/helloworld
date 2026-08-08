#include "Object.h"

Object::Object(vec2 position, vec2 scale, float rotationRadians , Sprite* sprite){
    this->position = position;
    this->scale = scale;
    this->rotationRadians = rotationRadians;
    this->sprite = sprite;
};

void Object::setPosition(vec2 position){
    this->position = position;
};

vec2 Object::getPosition(){
    return this->position;
};

void Object::addPosition(vec2 position){
    this->position += position;
};

void Object::setVelocity(vec2 velocity){
    this->velocity = velocity;
};

vec2 Object::getVelocity() {
    return this->velocity;
};

void Object::addVelocity(vec2 velocity){
    this->velocity += velocity;
};

void Object::setScale(vec2 scale){
    this->scale = scale;
};

vec2 Object::getScale(){
    return this->scale;
};

void Object::scaleUp(vec2 scale){
    this->scale *= scale;
};
void Object::setRotationRadians(float radians){
    this->rotationRadians = radians;
};

float Object::getRotationRadians(){
    return this->rotationRadians;
};

void Object::rotateRadians(float radians){
    this->rotationRadians += radians;
};
void Object::setSprite(Sprite* sprite){
    this->sprite = sprite;
};

