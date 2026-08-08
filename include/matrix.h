#pragma once

#include "vector.h"

class mat2{
    public:
        mat2(float a=1.0f, float b=0.0f, float c=0.0f, float d=1.0f);
        mat2 operator*(const mat2& other) const;
        vec2 operator*(const vec2& other) const;
        void print() const;

    private:
        float m[2][2];
};

class mat3{
    public:
        mat3(float a=1.0f, float b=0.0f, float c=0.0f, float d=0.0f, float e=1.0f, float f=0.0f, float g=0.0f, float h=0.0f, float i=1.0f);
        mat3 operator*(const mat3& other) const;
        vec3 operator*(const vec3& other) const;
        void print() const;

    private:
        float m[3][3];
};

class mat4{
    public:
        mat4(float a=1.0f, float b=0.0f, float c=0.0f, float d=0.0f, float e=0.0f, float f=1.0f, float g=0.0f, float h=0.0f, float i=0.0f, float j=0.0f, float k=1.0f, float l=0.0f, float m=0.0f, float n=0.0f, float o=0.0f, float p=1.0f);
        mat4 operator*(const mat4& other) const;
        vec4 operator*(const vec4& other) const;
        void print() const;

    private:
        float m[4][4];
};


