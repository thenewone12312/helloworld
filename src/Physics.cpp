#include "Physics.h"

vec2 Physics::gravity = vec2(0.0f, 0.0f);

void Physics::setGravity(vec2 gravity){
    Physics::gravity = gravity;
};

vec2 Physics::getGravity() {
    return Physics::gravity;
};

void Physics::updatePosition(Object object, float deltaTime) {
    object.addPosition(object.getVelocity() * deltaTime);

};

void Physics::Accelerate(Object object, const vec2 acceleration, float deltaTime) {
    object.setVelocity(object.getVelocity() + acceleration * deltaTime);
};