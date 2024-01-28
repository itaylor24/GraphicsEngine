//
// Created by Isaac Taylor on 1/25/24.
//

#include <iostream>

#include "Shapes.h"
#include "Types.h"

#include "glm/glm.hpp"

#include "utils.h"

ShapeData Shapes::makeTriangle(){

    ShapeData data;

    Vertex vertices[] =
        {
            glm::vec3 (-0.5f, -0.5f, 1.f),
            glm::vec3 (1.0f, 0.f, 0.f),

            glm::vec3 (.5f, -0.5f, 1.f),
            glm::vec3 (1.0f, 1.f, 0.f),

            glm::vec3 (0.5f, 0.5f, -1.f),
            glm::vec3 (1.0f, 0.f, 1.f),
        };

    unsigned int indices [] = {
            0, 1, 2,
    };


    data.numVertices = std::size(vertices);
    data.numIndices = std::size(indices);
    data.vertices = new Vertex[data.numVertices];
    data.indices = new unsigned int[data.numIndices];
    memcpy(data.indices, indices, sizeof (indices));
    memcpy(data.vertices, vertices, sizeof (vertices));

    return data;
}

ShapeData Shapes::makeCube(){
    ShapeData data;

    Vertex vertices[] =
        {
                glm::vec3(-1.0f, 1.0f, 1.0f),  // 0
                glm::vec3(1.0f, 0.0f, 0.0f),	// Color

                glm::vec3(1.0f, 1.0f, 1.0f),  // 1
                glm::vec3(0.0f, 1.0f, 0.0f),	// Color

                glm::vec3(1.0f, 1.0f, -1.0f),  // 2
                glm::vec3(0.0f, 0.0f, 1.0f),  // Color

                glm::vec3(-1.0f, +1.0f, -1.0f),  // 3
                glm::vec3(+1.0f, +1.0f, +1.0f),  // Color

                glm::vec3(-1.0f, +1.0f, -1.0f),  // 4
                glm::vec3(+1.0f, +0.0f, +1.0f),  // Color

                glm::vec3(+1.0f, +1.0f, -1.0f),  // 5
                glm::vec3(+0.0f, +0.5f, +0.2f),  // Color

                glm::vec3(+1.0f, -1.0f, -1.0f),  // 6
                glm::vec3(+0.8f, +0.6f, +0.4f),  // Color

                glm::vec3(-1.0f, -1.0f, -1.0f),  // 7
                glm::vec3(+0.3f, +1.0f, +0.5f),  // Color

                glm::vec3(+1.0f, +1.0f, -1.0f),  // 8
                glm::vec3(+0.2f, +0.5f, +0.2f),  // Color

                glm::vec3(+1.0f, +1.0f, +1.0f),  // 9
                glm::vec3(+0.9f, +0.3f, +0.7f),  // Color

                glm::vec3(+1.0f, -1.0f, +1.0f),  // 10
                glm::vec3(+0.3f, +0.7f, +0.5f),  // Color

                glm::vec3(+1.0f, -1.0f, -1.0f),  // 11
                glm::vec3(+0.5f, +0.7f, +0.5f),  // Color

                glm::vec3(-1.0f, +1.0f, +1.0f),  // 12
                glm::vec3(+0.7f, +0.8f, +0.2f),  // Color

                glm::vec3(-1.0f, +1.0f, -1.0f),  // 13
                glm::vec3(+0.5f, +0.7f, +0.3f),  // Color

                glm::vec3(-1.0f, -1.0f, -1.0f),  // 14
                glm::vec3(+0.4f, +0.7f, +0.7f),  // Color

                glm::vec3(-1.0f, -1.0f, +1.0f),  // 15
                glm::vec3(+0.2f, +0.5f, +1.0f),  // Color

                glm::vec3(+1.0f, +1.0f, +1.0f),  // 16
                glm::vec3(+0.6f, +1.0f, +0.7f),  // Color

                glm::vec3(-1.0f, +1.0f, +1.0f),  // 17
                glm::vec3(+0.6f, +0.4f, +0.8f),  // Color

                glm::vec3(-1.0f, -1.0f, +1.0f),  // 18
                glm::vec3(+0.2f, +0.8f, +0.7f),  // Color

                glm::vec3(+1.0f, -1.0f, +1.0f),  // 19
                glm::vec3(+0.2f, +0.7f, +1.0f),  // Color

                glm::vec3(+1.0f, -1.0f, -1.0f),  // 20
                glm::vec3(+0.8f, +0.3f, +0.7f),  // Color

                glm::vec3(-1.0f, -1.0f, -1.0f),  // 21
                glm::vec3(+0.8f, +0.9f, +0.5f),  // Color

                glm::vec3(-1.0f, -1.0f, +1.0f),  // 22
                glm::vec3(+0.5f, +0.8f, +0.5f),  // Color

                glm::vec3(+1.0f, -1.0f, +1.0f),  // 23
                glm::vec3(+0.9f, +1.0f, +0.2f),  // Color

        };

    unsigned int indices[] = {
            0,   1,  2,
            0,  2,  3, // Top
            4,   5,  6,  4,  6,  7, // Front
            8,   9, 10,  8, 10, 11, // Right
            12, 13, 14, 12, 14, 15, // Left
            16, 17, 18, 16, 18, 19, // Back
            20, 22, 21, 20, 23, 22, // Bottom
    };

    data.numVertices = std::size(vertices);
    data.numIndices = std::size(indices);

    data.vertices = new Vertex[data.numVertices];
    data.indices = new unsigned int[data.numIndices];

    memcpy(data.indices, indices, sizeof (indices));
    memcpy(data.vertices, vertices, sizeof (vertices));

    return data;
}
ShapeData Shapes::makePlane(unsigned int width){
    //vertices
    ShapeData data;
    data.numVertices = width * width;
    data.vertices = new Vertex[data.numVertices];


    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < width; ++j) {
            Vertex &vertex = data.vertices[ i * width + j];
            vertex.position.x = float (j - int(width/2));
            vertex.position.y = float (i - int(width/2));
            vertex.position.z = 0;
            //std::cout << glm::to_string(vertex.position);
            vertex.color = RANDOM_COLOR;
            std::cout << glm::to_string(vertex.color) << std::endl;
        }
    }

    int index = 0;
    data.numIndices = (width -1 ) * (width -1) * 6;
    data.indices = new unsigned int[data.numIndices];

    for (int row = 0; row < width-1; ++row) {
        for (int col = 0; col < width-1; ++col) {

            data.indices[index++] = (width * col) + row;
            data.indices[index++] = (width * col) + (row+1);
            data.indices[index++] = (width * (col+1)) + row;


            data.indices[index++] = (width * col) + (row+1);
            data.indices[index++] = (width * (col+1)) + row;
            data.indices[index++] = (width * (col+1)) + (row+1);


        }
    }

    return data;
}