#include "Object.h"
#include "Polygon.h"

/**
 * @class Object
 * @brief records various values about an "objects"
 *
 * this class stores for an object:
 * - position
 * - scale 
 * - rotation RADIANS
 * 
 * and regarding its rendering;
 * - the object's vao
 * - vbo
 * - ebo
 *
 * @note n/a
 * @author zihan
 * @date 2026-08-11
 */

Object::Object(Sprite* sprite){
    this->position = vec2(0.0f, 0.0f);
    this->scale = vec2(0.0f, 0.0f);
    this->rotationRadians = 0.0f;
    this->VAO = 0;
    this->VBO = 0;
    this->EBO = 0;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    if(sprite != nullptr){
        this->sprite = sprite;
    }
    else{
        this->sprite = new Sprite();
    }
    uploadMesh();
};

Object::Object(Texture* texture){
    this->position = vec2(0.0f, 0.0f);
    this->scale = vec2(0.0f, 0.0f);
    this->rotationRadians = 0.0f;
    this->VAO = 0;
    this->VBO = 0;
    this->EBO = 0;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    if(texture != nullptr){
        this->sprite = new Sprite(texture);
    }
    else{
        this->sprite = new Sprite();
    }
    uploadMesh();
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

void Object::setSpeed(int speed){
    this->speed = speed;
};

int Object::getSpeed() {
    return this->speed;
};

void Object::addSpeed(int speed){
    this->speed += speed;
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

void Object::processVelocity(float deltaTime)
{
    this->velocity.normalize();
    this->position += velocity * this->speed* deltaTime;
    velocity = 0.0f;
}
void Object::processVelocity(float deltaTime, vec2 velocity)
{
    velocity.normalize();
    this->position += velocity * this->speed* deltaTime;
    velocity = 0.0f;
}

//inital set up for the mesh stuff
void Object::uploadMesh()
{
    if (sprite == nullptr) return;

    std::vector<float> vertices = sprite->getVertexData();
    std::vector<unsigned int> indices = sprite->getIndexData();

    if (vertices.empty() || indices.empty()) return;

    indexCount = static_cast<GLsizei>(indices.size());

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER,
                 vertices.size() * sizeof(float),
                 vertices.data(),
                 GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                 indices.size() * sizeof(unsigned int),
                 indices.data(),
                 GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
                          5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE,
                          5 * sizeof(float),
                          (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindVertexArray(0);

}

void Object::draw(int &transformLoc)
{
    if (sprite == nullptr || indexCount ==0)
        return;

    glUniform3f(transformLoc,
            getPosition().x,
            getPosition().y,
            0.0f);
    
    //so we dont draw these everytime.
    // // Obtain vertex/index data from the sprite
    // std::vector<float> vertices = sprite->getVertexData();
    // std::vector<unsigned int> indices = sprite->getIndexData();
    // if (vertices.empty() || indices.empty())
    //     return;

    // Bind VAO
    glBindVertexArray(VAO);

    // // Upload vertex data
    // glBindBuffer(GL_ARRAY_BUFFER, VBO);
    // glBufferData(
    //     GL_ARRAY_BUFFER,
    //     vertices.size() * sizeof(float),
    //     vertices.data(),
    //     GL_STATIC_DRAW
    // );

    // // Upload index data
    // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    // glBufferData(
    //     GL_ELEMENT_ARRAY_BUFFER,
    //     indices.size() * sizeof(int),
    //     indices.data(),
    //     GL_STATIC_DRAW
    // );

    // // Position: x, y, z
    // glVertexAttribPointer(
    //     0,
    //     3,
    //     GL_FLOAT,
    //     GL_FALSE,
    //     5 * sizeof(float),
    //     (void*)0
    // );
    // glEnableVertexAttribArray(0);

    // // Texture coordinates: u, v
    // glVertexAttribPointer(
    //     2,
    //     2,
    //     GL_FLOAT,
    //     GL_FALSE,
    //     5 * sizeof(float),
    //     (void*)(3 * sizeof(float))
    // );
    // glEnableVertexAttribArray(2);

    // Bind texture
    if (sprite->getTexture() != nullptr) {
        glActiveTexture(GL_TEXTURE0);
        sprite->getTexture()->bind();
    }

    // Draw
    glDrawElements(
        GL_TRIANGLES,
        (indexCount),
        GL_UNSIGNED_INT,
        nullptr
    );

    glBindVertexArray(0);
};