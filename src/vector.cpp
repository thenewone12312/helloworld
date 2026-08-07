#include "vector.h"


vec2::vec2(){
    this->x = 0;
    this->y = 0;
};

vec2::vec2(float val){
    this->x = val;
    this->y = val;
};

vec2::vec2(float xVal, float yVal){
    this->x = xVal;
    this->y = yVal;
};

vec2 vec2::operator+(const vec2& other) const{
    return vec2(x + other.x, y + other.y);
};

vec2& vec2::operator+=(const vec2& other){
    this->x += other.x;
    this->y += other.y;
    return *this;
};

vec2 vec2::operator-(const vec2& other) const{
    return vec2(x - other.x, y - other.y);
};

vec2& vec2::operator-=(const vec2& other){
    this->x -= other.x;
    this->y -= other.y;
    return *this;
};


vec2 vec2::operator*(const vec2& other) const{
    return vec2(x * other.x, y * other.y);
};

vec2& vec2::operator*=(const vec2& other){
    this->x *= other.x;
    this->y *= other.y;
    return *this;
};

vec2 vec2::operator*(const float scalar) const{
    return vec2(x * scalar, y * scalar);
};

vec2& vec2::operator*=(const float scalar){
    this->x *= scalar;
    this->y *= scalar;
    return *this;
};

vec2 vec2::operator/(const vec2& other) const{
    return vec2(x / other.x, y / other.y);
};

vec2& vec2::operator/=(const vec2& other){
    this->x /= other.x;
    this->y /= other.y;
    return *this;
};


vec2 para::interpolateLinear(vec2 start, vec2 end, float factor){
    vec2 stuff = ((end-start)*factor + start);

    return((end-start)*factor + start);
};