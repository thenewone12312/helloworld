#pragma once


class vec2{
    public:
        vec2();
        vec2(float val);
        vec2(float xVal, float yVal);
        vec2 operator+(const vec2& other) const;
        vec2& operator+=(const vec2& other);
        vec2 operator-(const vec2& other) const;
        vec2& operator-=(const vec2& other);
        vec2 operator*(const vec2& other) const;
        vec2& operator*=(const vec2& other);
        vec2 operator*(const float scalar) const;
        vec2& operator*=(float scalar);
        vec2 operator/(const vec2& other) const;
        vec2& operator/=(const vec2& other);
        void normalize();
        

    private:
        float x;
        float y;
};

// class vec3{
//     public:

//     private:
// }

namespace para{
    vec2 interpolateLinear(vec2 start, vec2 end, float factor);
};
