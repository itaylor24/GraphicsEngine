//
// Created by Isaac Taylor on 1/28/24.
//

#ifndef GRAPHICSENGINE_MESH_H
#define GRAPHICSENGINE_MESH_H

#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>

#include "Types.h"
#include "utils.h"
#include "Shapes.h"
#include "VertexArray.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"

class Mesh {

public:
    ShapeData* Parse(std::string filename);
    Mesh(std::string filename);
    Mesh(ShapeData* shape);
    void Setup();
    static std::vector<glm::vec3> computeNormals(std::vector<Vertex>& vertexArray,
                                          std::vector<unsigned int>& indexArray);
    ShapeData* getInfo();
    ShapeData* _data;
    VertexArray* _mVAO;
    VertexBuffer* _mVBO;
    IndexBuffer* _mIBO;
    int _vertexCount;
    int _indexCount;
};



#endif //GRAPHICSENGINE_MESH_H
