#pragma once

#include "vector.h"

class Physics {
public:
    static vec2 getGravity(const vec2& position);
    // this class functions by applying the velocity to position
    // static vec2 applyFriction(const vec2& velocity, float frictionCoefficient, float deltaTime);
    // static vec2 applyForce(const vec2& velocity, const vec2& force, float mass, float deltaTime);
    static vec2 updatePosition(const vec2& position, const vec2& velocity, float deltaTime);
private:
    static const vec2 gravity; // Gravity vector
};