//
// Created by Isaac Taylor on 1/28/24.
//

#include "Mesh.h"
#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>
#include <vector>

#include "Types.h"
#include "utils.h"
#include "Shapes.h"

Mesh::Mesh(std::string filename, ShapeData* info) {

    Parse(filename, info);

//    std::vector<Vertex>& vertices = info.first;
//    std::vector<unsigned int>& indices = info.second;
//
//    auto data = std::make_unique<ShapeData>();
//
//    data->numIndices = indices.size();
//    data->numVertices = vertices.size();
//
//    data->vertices = &vertices[0];
//    data->indices = &indices[0];

//    for (int i = 0; i < data.numVertices; ++i) {
//        data.vertices[i].position.x = vertices[i].position.x;
//        data.vertices[i].position.y = vertices[i].position.y;
//        data.vertices[i].position.z = vertices[i].position.z;
//        data.vertices[i].color = vertices[i].color;
//    }
//
//    for (int i = 0; i < data.numIndices; ++i) {
//        data.indices[i] = indices[i];
//    }

}

void Mesh::Parse(std::string filename, ShapeData* data){
    std::ifstream objFile(filename);

    if (!objFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
    }

    std::vector<Vertex> vertices;
    std::vector<unsigned int> indices;

    std::string line;
    while (std::getline(objFile, line)) {
        std::istringstream iss(line);
        std::string token;

        iss >> token;

        if (token == "v") {
            Vertex vertex;
            iss >> vertex.position.x >> vertex.position.y >> vertex.position.z;
            vertex.color = RANDOM_COLOR;
            vertices.push_back(vertex);
        } else if (token == "f") {

            unsigned int index;

            unsigned int ix1, ix2, ix3;
            iss >> ix1 >> ix2 >> ix3;

            indices.push_back(ix1-1);
            indices.push_back(ix2-1);
            indices.push_back(ix3-1);
        }
    }

    objFile.close();

    // Print the parsed vertices
    data->numVertices = vertices.size();
    data->numIndices = indices.size();

    //data->vertices = new Vertex[data->numVertices];
    //data->indices = new unsigned int[data->numIndices];

    std::cout<< data->numIndices << "INDICES" << std::endl;
    std::cout<< data->numVertices << "VERTICES" << std::endl;

    memcpy(data->indices, &indices[0], sizeof (unsigned int) * indices.size());
    memcpy(data->vertices, &vertices[0], sizeof (Vertex) * vertices.size());

    for (int i = 0; i < data->numIndices; ++i) {
        std::cout << data->indices[i] << std::endl;;
    }

}

void Mesh::showVertices(){


    std::cout<< data-> numVertices << std::endl;

    for (int i = 0; i < data->numVertices; ++i) {
        std::cout << glm::to_string(data->vertices[i].position) << std::endl;
        std::cout << glm::to_string(data->vertices[i].color) << std::endl;
    }


    for (int i = 0; i < data->numIndices; ++i) {
        std::cout << data->indices[i] << std::endl;;
    }
}