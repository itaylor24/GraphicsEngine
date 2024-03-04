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
ShapeData Shapes::makeCube(float size, glm::vec3 color){
    ShapeData data;

    Vertex vertices[] =
        {
                glm::vec3(-1.0f, 1.0f, 1.0f),// 0
                color,	// Color
                glm::vec3 (1.f, 0.f, 0.f),

                glm::vec3(1.0f, 1.0f, 1.0f),  // 1
                color,	// Color
                glm::vec3 (1.f, 0.f, 0.f),

                glm::vec3(1.0f, 1.0f, -1.0f),  // 2
                color,  // Color
                glm::vec3 (1.f, 0.f, 0.f),

                glm::vec3(-1.0f, +1.0f, -1.0f),  // 3
                color,
                glm::vec3 (1.f, 0.f, 0.f),
                  // Color

                glm::vec3(-1.0f, +1.0f, -1.0f),  // 4
                color,  // Color
                glm::vec3 (1.f, 0.f, 0.f),

                glm::vec3(+1.0f, +1.0f, -1.0f),  // 5
                color,  // Color
                glm::vec3 (1.f, 0.f, 0.f),

                glm::vec3(+1.0f, -1.0f, -1.0f),  // 6
                color,  // Color
                glm::vec3 (1.f, 0.f, 0.f),

                glm::vec3(-1.0f, -1.0f, -1.0f),  // 7
                color,  // Color
                glm::vec3 (1.f, 0.f, 0.f),

                glm::vec3(+1.0f, +1.0f, -1.0f),  // 8
                color,  // Color
                glm::vec3 (1.f, 0.f, 0.f),

                glm::vec3(+1.0f, +1.0f, +1.0f),  // 9
                color,  // Color
                glm::vec3 (1.f, 0.f, 0.f),

                glm::vec3(+1.0f, -1.0f, +1.0f),  // 10
                color,  // Color
                glm::vec3 (1.f, 0.f, 0.f),

                glm::vec3(+1.0f, -1.0f, -1.0f),  // 11
                color,  // Color
                glm::vec3 (1.f, 0.f, 0.f),

                glm::vec3(-1.0f, +1.0f, +1.0f),  // 12
                color,  // Color
                glm::vec3 (1.f, 0.f, 0.f),

                glm::vec3(-1.0f, +1.0f, -1.0f),  // 13
                color,  // Color
                glm::vec3 (1.f, 0.f, 0.f),

                glm::vec3(-1.0f, -1.0f, -1.0f),  // 14
                color,  // Color
                glm::vec3 (1.f, 0.f, 0.f),

                glm::vec3(-1.0f, -1.0f, +1.0f),  // 15
                color,  // Color
                glm::vec3 (1.f, 0.f, 0.f),

                glm::vec3(+1.0f, +1.0f, +1.0f),  // 16
                color,  // Color
                glm::vec3 (1.f, 0.f, 0.f),

                glm::vec3(-1.0f, +1.0f, +1.0f),  // 17
                color,  // Color
                glm::vec3 (1.f, 0.f, 0.f),

                glm::vec3(-1.0f, -1.0f, +1.0f),  // 18
                color,  // Color
                glm::vec3 (1.f, 0.f, 0.f),

                glm::vec3(+1.0f, -1.0f, +1.0f),  // 19
                color,  // Color
                glm::vec3 (1.f, 0.f, 0.f),

                glm::vec3(+1.0f, -1.0f, -1.0f),  // 20
                color,  // Color
                glm::vec3 (1.f, 0.f, 0.f),

                glm::vec3(-1.0f, -1.0f, -1.0f),  // 21
                color,  // Color
                glm::vec3 (1.f, 0.f, 0.f),

                glm::vec3(-1.0f, -1.0f, +1.0f),  // 22
                color,  // Color
                glm::vec3 (1.f, 0.f, 0.f),

                glm::vec3(+1.0f, -1.0f, +1.0f),  // 23
                color,  // Color
                glm::vec3 (1.f, 0.f, 0.f),

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

    for (int i = 0; i < data.numVertices; ++i) {
        vertices[i].position = size * vertices[i].position;
    }

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