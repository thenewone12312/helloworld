#include "matrix.h"

mat2::mat2(float a, float b, float c, float d){
    m[0][0] = a;
    m[0][1] = b;
    m[1][0] = c;
    m[1][1] = d;
};

mat2 mat2::operator*(const mat2& other) const{
    return mat2(
        m[0][0] * other.m[0][0] + m[0][1] * other.m[1][0],
        m[0][0] * other.m[0][1] + m[0][1] * other.m[1][1],
        m[1][0] * other.m[0][0] + m[1][1] * other.m[1][0],
        m[1][0] * other.m[0][1] + m[1][1] * other.m[1][1]
    );
};

mat2 mat2::operator*(const float scalar) const{
    return mat2(
        m[0][0] * scalar,
        m[0][1] * scalar,
        m[1][0] * scalar,
        m[1][1] * scalar
    );
};

vec2 mat2::operator*(const vec2& other) const{
    return vec2(
        m[0][0] * other.x + m[0][1] * other.y,
        m[1][0] * other.x + m[1][1] * other.y
    );
};

mat3::mat3(float a, float b, float c, float d, float e, float f, float g, float h, float i){
    m[0][0] = a;
    m[0][1] = b;
    m[0][2] = c;
    m[1][0] = d;
    m[1][1] = e;
    m[1][2] = f;
    m[2][0] = g;
    m[2][1] = h;
    m[2][2] = i;
};

mat3 mat3::operator*(const mat3& other) const{
    return mat3(
        m[0][0] * other.m[0][0] + m[0][1] * other.m[1][0] + m[0][2] * other.m[2][0],
        m[0][0] * other.m[0][1] + m[0][1] * other.m[1][1] + m[0][2] * other.m[2][1],
        m[0][0] * other.m[0][2] + m[0][1] * other.m[1][2] + m[0][2] * other.m[2][2],

        m[1][0] * other.m[0][0] + m[1][1] * other.m[1][0] + m[1][2] * other.m[2][0],
        m[1][0] * other.m[0][1] + m[1][1] * other.m[1][1] + m[1][2] * other.m[2][1],
        m[1][0] * other.m[0][2] + m[1][1] * other.m[1][2] + m[1][2] * other.m[2][2],

        m[2][0] * other.m[0][0] + m[2][1] * other.m[1][0] + m[2][2] * other.m[2][0],
        m[2][0] * other.m[0][1] + m[2][1] * other.m[1][1] + m[2][2] * other.m[2][1],
        m[2][0] * other.m[0][2] + m[2][1] * other.m[1][2] + m[2][2] * other.m[2][2]
    );
};

mat3 mat3::operator*(const float scalar) const{
    return mat3(
        m[0][0] * scalar,
        m[0][1] * scalar,
        m[0][2] * scalar,
        m[1][0] * scalar,
        m[1][1] * scalar,
        m[1][2] * scalar,
        m[2][0] * scalar,
        m[2][1] * scalar,
        m[2][2] * scalar
    );
};

vec3 mat3::operator*(const vec3& other) const{
    return vec3(
        m[0][0] * other.x + m[0][1] * other.y + m[0][2] * other.z,
        m[1][0] * other.x + m[1][1] * other.y + m[1][2] * other.z,
        m[2][0] * other.x + m[2][1] * other.y + m[2][2] * other.z
    );
};

mat4::mat4(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l, float m, float n, float o, float p){
    this->m[0][0] = a;
    this->m[0][1] = b;
    this->m[0][2] = c;
    this->m[0][3] = d;
    this->m[1][0] = e;
    this->m[1][1] = f;
    this->m[1][2] = g;
    this->m[1][3] = h;
    this->m[2][0] = i;
    this->m[2][1] = j;
    this->m[2][2] = k;
    this->m[2][3] = l;
    this->m[3][0] = m;
    this->m[3][1] = n;
    this->m[3][2] = o;
    this->m[3][3] = p;
};

mat4 mat4::operator*(const mat4& other) const{
    return mat4(
        m[0][0] * other.m[0][0] + m[0][1] * other.m[1][0] + m[0][2] * other.m[2][0] + m[0][3] * other.m[3][0],
        m[0][0] * other.m[0][1] + m[0][1] * other.m[1][1] + m[0][2] * other.m[2][1] + m[0][3] * other.m[3][1],
        m[0][0] * other.m[0][2] + m[0][1] * other.m[1][2] + m[0][2] * other.m[2][2] + m[0][3] * other.m[3][2],
        m[0][0] * other.m[0][3] + m[0][1] * other.m[1][3] + m[0][2] * other.m[2][3] + m[0][3] * other.m[3][3],

        m[1][0] * other.m[0][0] + m[1][1] * other.m[1][0] + m[1][2] * other.m[2][0] + m[1][3] * other.m[3][0],
        m[1][0] * other.m[0][1] + m[1][1] * other.m[1][1] + m[1][2] * other.m[2][1] + m[1][3] * other.m[3][1],
        m[1][0] * other.m[0][2] + m[1][1] * other.m[1][2] + m[1][2] * other.m[2][2] + m[1][3] * other.m[3][2],
        m[1][0] * other.m[0][3] + m[1][1] * other.m[1][3] + m[1][2] * other.m[2][3] + m[1][3] * other.m[3][3],

        m[2][0] * other.m[0][0] + m[2][1] * other.m[1][0] + m[2][2] * other.m[2][0] + m[2][3] * other.m[3][0],
        m[2][0] * other.m[0][1] + m[2][1] * other.m[1][1] + m[2][2] * other.m[2][1] + m[2][3] * other.m[3][1],
        m[2][0] * other.m[0][2] + m[2][1] * other.m[1][2] + m[2][2] * other.m[2][2] + m[2][3] * other.m[3][2],
        m[2][0] * other.m[0][3] + m[2][1] * other.m[1][3] + m[2][2] * other.m[2][3] + m[2][3] * other.m[3][3],

        m[3][0] * other.m[0][0] + m[3][1] * other.m[1][0] + m[3][2] * other.m[2][0] + m[3][3] * other.m[3][0],
        m[3][0] * other.m[0][1] + m[3][1] * other.m[1][1] + m[3][2] * other.m[2][1] + m[3][3] * other.m[3][1],
        m[3][0] * other.m[0][2] + m[3][1] * other.m[1][2] + m[3][2] * other.m[2][2] + m[3][3] * other.m[3][2],
        m[3][0] * other.m[0][3] + m[3][1] * other.m[1][3] + m[3][2] * other.m[2][3] + m[3][3] * other.m[3][3]
    );
};

vec4 mat4::operator*(const vec4& other) const{
    return vec4(
        m[0][0] * other.x + m[0][1] * other.y + m[0][2] * other.z + m[0][3] * other.w,
        m[1][0] * other.x + m[1][1] * other.y + m[1][2] * other.z + m[1][3] * other.w,
        m[2][0] * other.x + m[2][1] * other.y + m[2][2] * other.z + m[2][3] * other.w,
        m[3][0] * other.x + m[3][1] * other.y + m[3][2] * other.z + m[3][3] * other.w
    );
};




