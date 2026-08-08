#include "Physics.h"

 vec2 Physics::getGravity(const vec2& position)
{
    return Physics::gravity; // Gravity vector pointing downwards
};
//we dont need these rn
//  vec2 Physics::applyFriction(const vec2& velocity, float frictionCoefficient, float deltaTime)
// {

// };
//  vec2 Physics::applyForce(const vec2& velocity, const vec2& force, float mass, float deltaTime)
// {
//     // Implementation for applying force
//     return vec2(0.0f, 0.0f);
// };
 vec2 Physics::updatePosition(const vec2& position, const vec2& velocity, float deltaTime)
{
    // Implementation for updating position
    return position + velocity * deltaTime;
};