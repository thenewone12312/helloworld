#pragma once

#include <iostream>
#include <vector>

#include "vector.h"
#include "matrix.h"
#include "Texture.h"

struct Property{
    Property(std::string name, unsigned int numValues);
    
    std::string name;
    unsigned int numValues;
};

class Polygon{
    public:
        Polygon(const std::vector<float>& data, const std::vector<Property>& properties=std::vector<Property>(), bool position2D = true, bool texture=true, bool color=false);
        Polygon();
        Polygon(vec2 scale);
        Polygon(float width, float height);
        void setProperties(const std::vector<Property>& properties);
        void addProperty(std::string name, unsigned int numValues, const std::vector<float>& data=std::vector<float>());
        void removeProperty(std::string name);
        void setVertices(const std::vector<float>& data);
        void addVertices(const std::vector<float>& data);
        void applyTransformation(mat4 transformation);
        void applyTranslation(vec2 translation);
        std::vector<float> getVertexData();


    private:
        std::vector<Property> properties;
        std::vector<float> vertices;
        vec2 scale;
        std::vector<float> generateQuad();
        std::vector<float> generateQuad(vec2 scale);
        std::vector<float> generateQuad(float width, float height);
        unsigned int calculateVertices();
        unsigned int calculateVertexValues();
};