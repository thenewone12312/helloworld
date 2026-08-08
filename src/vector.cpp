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
void vec2::normalize(){
    float length = std::sqrt(x * x + y * y);
    if (length != 0) {
        x /= length;
        y /= length;
    }
};






vec3::vec3(){
    this->x = 0;
    this->y = 0;
    this->z = 0;
};

vec3::vec3(float val){
    this->x = val;
    this->y = val;
    this->z = val;
};

vec3::vec3(float xVal, float yVal, float zVal){
    this->x = xVal;
    this->y = yVal;
    this->z = zVal;
};

vec3 vec3::operator+(const vec3& other) const{
    return vec3(x + other.x, y + other.y, z + other.z);
};

vec3& vec3::operator+=(const vec3& other){
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
    return *this;
};

vec3 vec3::operator-(const vec3& other) const{
    return vec3(x - other.x, y - other.y, z - other.z);
};

vec3& vec3::operator-=(const vec3& other){
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;
    return *this;
};


vec3 vec3::operator*(const vec3& other) const{
    return vec3(x * other.x, y * other.y, z * other.z);
};

vec3& vec3::operator*=(const vec3& other){
    this->x *= other.x;
    this->y *= other.y;
    this->z *= other.z;
    return *this;
};

vec3 vec3::operator*(const float scalar) const{
    return vec3(x * scalar, y * scalar, z * scalar);
};

vec3& vec3::operator*=(const float scalar){
    this->x *= scalar;
    this->y *= scalar;
    this->z *= scalar;
    return *this;
};

vec3 vec3::operator/(const vec3& other) const{
    return vec3(x / other.x, y / other.y, z / other.z);
};

vec3& vec3::operator/=(const vec3& other){
    this->x /= other.x;
    this->y /= other.y;
    this->z /= other.z;
    return *this;
};

void vec3::normalize(){
    float length = std::sqrt(x * x + y * y + z * z);
    if (length != 0) {
        x /= length;
        y /= length;
        z /= length;
    }
};

vec4::vec4(){
    this->x = 0;
    this->y = 0;
    this->z = 0;
    this->w = 0;
};

vec4::vec4(float val){
    this->x = val;
    this->y = val;
    this->z = val;
    this->w = val;
};

vec4::vec4(float xVal, float yVal, float zVal, float wVal){
    this->x = xVal;
    this->y = yVal;
    this->z = zVal;
    this->w = wVal;
};

vec4 vec4::operator+(const vec4& other) const{
    return vec4(x + other.x, y + other.y, z + other.z, w + other.w);
};

vec4& vec4::operator+=(const vec4& other){
    this->x += other.x;
    this->y += other.y;
    this->z += other.z;
    this->w += other.w;
    return *this;
};

vec4 vec4::operator-(const vec4& other) const{
    return vec4(x - other.x, y - other.y, z - other.z, w - other.w);
};

vec4& vec4::operator-=(const vec4& other){
    this->x -= other.x;
    this->y -= other.y;
    this->z -= other.z;
    this->w -= other.w;
    return *this;
};


vec4 vec4::operator*(const vec4& other) const{
    return vec4(x * other.x, y * other.y, z * other.z, w * other.w);
};

vec4& vec4::operator*=(const vec4& other){
    this->x *= other.x;
    this->y *= other.y;
    this->z *= other.z;
    this->w *= other.w;
    return *this;
};

vec4 vec4::operator*(const float scalar) const{
    return vec4(x * scalar, y * scalar, z * scalar, w * scalar);
};

vec4& vec4::operator*=(const float scalar){
    this->x *= scalar;
    this->y *= scalar;
    this->z *= scalar;
    this->w *= scalar;
    return *this;
};

vec4 vec4::operator/(const vec4& other) const{
    return vec4(x / other.x, y / other.y, z / other.z, w / other.w);
};

vec4& vec4::operator/=(const vec4& other){
    this->x /= other.x;
    this->y /= other.y;
    this->z /= other.z;
    this->w /= other.w;
    return *this;
};
void vec4::normalize(){
    float length = std::sqrt(x * x + y * y + z * z + w * w);
    if (length != 0) {
        x /= length;
        y /= length;
        z /= length;
        w /= length;
    }
};

vec2 para::interpolateLinear(vec2 start, vec2 end, float factor){

    return((end-start)*factor + start);
};

vec3 para::interpolateLinear(vec3 start, vec3 end, float factor){

    return((end-start)*factor + start);
};
