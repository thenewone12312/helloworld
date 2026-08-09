#include "Polygon.h"

Property::Property(std::string name, unsigned int numValues){
    this->name = name;
    this->numValues = numValues;
};

Polygon::Polygon(const std::vector<float>& data, const std::vector<Property>& properties, bool position, bool color, bool texture)
    : vertices(data), properties(properties) {
    vertexNumValues = 0;
    if(properties.empty()){
        if(position){
            addProperty("position", 2);
        }
        if(color){
            addProperty("color", 4);
        }
        if(texture){
            addProperty("texture", 2);
        }
    }
};

void Polygon::setProperties(const std::vector<Property>& properties){
    this->properties = properties;
};

// void Polygon::addProperty(std::string name, unsigned int numValues){
//     properties.push_back(Property(name, numValues));
//     vertexNumValues += numValues;
// };

// void Polygon::removeProperty(std::string name){
// };

void Polygon::setVertices(const std::vector<float>& data){
    this->vertices = data;
};

void Polygon::addVertices(const std::vector<float>& data){
    vertices.insert(vertices.end(), data.begin(), data.end());
};

// #pragma once

// #include <iostream>
// #include <vector>

// struct Property{
//     Property(std::string name, unsigned int numValues);
    
//     std::string name;
//     unsigned int numValues;
// };

// class Polygon{
//     public:
//         Polygon(const std::vector<float>& data, bool position = true, bool texture=true, bool color=false, bool regular=true);
//         void addProperty(std::string name, unsigned int numValues);
//         Property& getProperty(std::string name);
//         void removeProperty(std::string name);
//         void setVertices(const std::vector<float>& data);
//         void addVertices(const std::vector<float>& data);


//     private:
//         std::vector<Property> properties;
//         std::vector<float> vertices;
// };