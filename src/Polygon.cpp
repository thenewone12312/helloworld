#include "Polygon.h"

Property::Property(std::string name, unsigned int numValues){
    this->name = name;
    this->numValues = numValues;
};

Polygon::Polygon(const std::vector<float>& data, const std::vector<Property>& properties, bool position, bool color, bool texture)
    : vertices(data), properties(properties) {
    bool empty = false;
    if(data.empty()){
        empty = true;
    }
    if(properties.empty()){
        if(position){
            addProperty("position", 3);
        }
        if(color){
            addProperty("color", 4);
        }
        if(texture){
            addProperty("texture", 2);
        }

        if(empty){
            vertices = std::vector<float>();
        }
        else{
            vertices = data;
        }
        
    }
};

Polygon::Polygon()
    : Polygon(generateQuad()){
    
};

Polygon::Polygon(vec2 scale)
    : Polygon(generateQuad(scale)){

};

Polygon::Polygon(float width, float height)
    : Polygon(generateQuad(width, height)){

};

std::vector<float> generateQuad(){
    return {0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
            0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
            1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
            1.0f, 1.0f, 0.0f, 1.0f, 1.0f};
};

std::vector<float> generateQuad(){
    
};

void Polygon::setProperties(const std::vector<Property>& properties){
    this->properties = properties;
};

void Polygon::addProperty(std::string name, unsigned int numValues, const std::vector<float>& data){
    int numVertices = calculateVertices();
    properties.push_back(Property(name, numValues));
    int numVertexValues = calculateVertexValues();
    for(int i=0; i<numVertices; ++i){
        vertices.insert(vertices.begin()+((i+1)*numVertexValues - numValues), data.begin()+(i*numValues), data.begin()+((i+1)*numValues));
    }    
};

// void Polygon::removeProperty(std::string name){

// };

void Polygon::setVertices(const std::vector<float>& data){
    this->vertices = data;
};

void Polygon::addVertices(const std::vector<float>& data){
    vertices.insert(vertices.end(), data.begin(), data.end());
};

std::vector<float> Polygon::getVertexData(){
    return vertices;
};

unsigned int Polygon::calculateVertices(){
    return vertices.size()/calculateVertexValues();
};

unsigned int Polygon::calculateVertexValues(){
    int values = 0;
    for(Property property : properties){
        values += property.numValues;
    }
    return values;
};