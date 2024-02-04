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

class Mesh {



public:
    static void Parse(std::string filename, ShapeData* data);
    Mesh(std::string filename, ShapeData* info);
    void showVertices();
    ShapeData* data;
    static std::vector<glm::vec3> computeNormals(std::vector<Vertex>& vertexArray,
                                          std::vector<unsigned int>& indexArray);
};



#endif //GRAPHICSENGINE_MESH_H
