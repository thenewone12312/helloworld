#include "Physics.h"

void Physics::setGravity(vec2 gravity){
    Physics::gravity = gravity;
};

vec2 Physics::getGravity() {
    return Physics::gravity;
};

void Physics::updatePosition(Object& object, float deltaTime) {
    object.addPosition(object.getVelocity() * deltaTime);
};

void Physics::Accelerate(Object& object, const vec2& acceleration, float deltaTime) {
    object.addVelocity(acceleration * deltaTime);
};