#pragma once

#include "vector.h"
#include "Object.h"

class Physics {
public:
    static void setGravity(vec2 gravity);
    static vec2 getGravity();
    static void Accelerate(Object& object, const vec2& acceleration, float deltaTime);
    static void updatePosition(Object& object, float deltaTime);
private:
    static vec2 gravity; // Gravity vector
};