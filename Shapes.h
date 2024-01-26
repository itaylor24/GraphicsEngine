//
// Created by Isaac Taylor on 1/25/24.
//

#ifndef GRAPHICSENGINE_SHAPES_H
#define GRAPHICSENGINE_SHAPES_H

#include "Types.h"
#include "Renderer.h"

struct ShapeData{

    ShapeData() :
        vertices(0), numVertices(0),
        indices(0), numIndices(0){}
    Vertex* vertices;
    GLuint  numVertices;
    unsigned int* indices;
    GLuint  numIndices;

    unsigned int vertexBufferSize() {
        return numVertices * sizeof (Vertex);
    }

    unsigned int indexBufferSize() {
        return numIndices * sizeof (unsigned int);
    }

    void cleanup(){
        delete[] vertices;
        delete[] indices;
        numVertices = numIndices = 0;
    }

};

class Shapes {
public:
    static ShapeData makeTriangle();
    static ShapeData makeCube();
};


#endif //GRAPHICSENGINE_SHAPES_H