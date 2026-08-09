#pragma once

#include <iostream>
#include <vector>

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
        void setProperties(const std::vector<Property>& properties);
        void addProperty(std::string name, unsigned int numValues);
        void removeProperty(std::string name);
        void setVertices(const std::vector<float>& data);
        void addVertices(const std::vector<float>& data);


    private:
        std::vector<Property> properties;
        std::vector<float> vertices;
        unsigned int vertexNumValues;
};