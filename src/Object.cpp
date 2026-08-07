#include "Object.h"

Object::Object(vec2 position, vec2 scale, float rotationRadians , Texture* texture){
    this->position = position;
    this->scale = scale;
    this->rotationRadians = rotationRadians;
    this->texture = texture;
};

void Object::setPosition(vec2 position){
    this->position = position;
};

void Object::addPosition(vec2 position){
    this->position += position;
};

void Object::setScale(vec2 scale){
    this->scale = scale;
};
void Object::scaleUp(vec2 scale){
    this->scale *= scale;
};
void Object::setRotationRadians(float radians){
    this->rotationRadians = radians;
};

void Object::rotateRadians(float radians){
    this->rotationRadians += radians;
};
void Object::setTexture(Texture* texture){
    this->texture = texture;
};

