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
#include "MeshLayout.h"

Mesh::Mesh(std::string filename) : _data(Parse(filename)){
    Setup();
}
Mesh::Mesh(ShapeData* shape) : _data(shape){
    Setup();
}

void Mesh::Setup(){
    _mVAO = new VertexArray;
    _mVBO = new VertexBuffer(_data);
    _mIBO = new IndexBuffer(_data);

    MeshLayout* layoutLight = new MeshLayout();

    _mVAO->AddBuffer(*_mVBO, *layoutLight);
    _mVAO->Bind();
}

ShapeData* Mesh::Parse(std::string filename){

    std::ifstream objFile(filename);
    std::ifstream objFileCopy(filename);

    if (!objFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
    }

    int vertSize = 0;
    int normalSize = 0;

    std::vector<Vertex> vertices;
    std::vector<glm::vec3> normals;

    std::vector<unsigned int> indices;
    std::string line;

    while (std::getline(objFileCopy, line)) {
        std::istringstream iss(line);
        std::string token;
        iss >> token;
        if (token == "v") {
            vertSize++;
        }
        if(token == "f"){
            normalSize+=3;
        }
    }

    _vertexCount = vertSize;
    _indexCount = normalSize;

    indices.reserve(_indexCount);
    vertices.reserve(_vertexCount);

    while (std::getline(objFile, line)) {
        std::vector<int> indexVars;

        std::istringstream iss(line);
        std::string token;

        iss >> token;

        if (token == "v") {
            Vertex vertex;
            iss >> vertex.position.x >> vertex.position.y >> vertex.position.z;
            vertex.color = glm::vec3 (1.0f, .05f, .5f);
            vertices.push_back(vertex);
        }
        else if (token == "f") {

            long int ix1, ix2, ix3;
            long int nx1, nx2, nx3;
            int tx1, tx2, tx3;
            char s;

            std::string block;

            for (int i = 0; i < 3; ++i) {

                iss >> block;

                if (block.find('/') != std::string::npos) {

                    std::vector<std::string> result;

                    std::istringstream bstream(block);
                    std::string index;

                    while (std::getline(bstream, index, '/')) {
                        indexVars.push_back(std::stoi(index));
                    }

                } else {

                    indexVars.push_back(std::stoi(block));

                }
            }

            ix1 = indexVars[0];
            ix2 = indexVars[1];
            ix3 = indexVars[2];


            if(ix1 <= 0){

                indices.push_back(ix1 + vertSize);
                indices.push_back(ix2 + vertSize);
                indices.push_back(ix3 + vertSize);

            }else{

                indices.push_back(ix1 - 1);
                indices.push_back(ix2 - 1);
                indices.push_back(ix3 - 1);

            }
        }
    }

    objFile.close();

    ShapeData* shapeData = new ShapeData(_vertexCount, _indexCount);

    normals = computeNormals(vertices, indices);
    for (int i = 0; i < vertices.size(); ++i) {
        vertices[i].normal = normals[i];
    }

    memcpy(shapeData->indices, &indices[0], sizeof (unsigned int) * indices.size());
    memcpy(shapeData->vertices, &vertices[0], sizeof (Vertex) * vertices.size());


    return shapeData;

}

std::vector<glm::vec3> Mesh::computeNormals(std::vector<Vertex>& vertexArray,
                    std::vector<unsigned int>& indexArray){

    std::vector<glm::vec3> normalArray;
    std::vector<glm::vec3> faceNormals;

    for (size_t i = 0; i < indexArray.size(); i += 3) {

        const glm::vec3& v1 = vertexArray[indexArray[i]].position;
        const glm::vec3& v2 = vertexArray[indexArray[i + 1]].position;
        const glm::vec3& v3 = vertexArray[indexArray[i + 2]].position;

        glm::vec3 edge1 = v2 - v1;
        glm::vec3 edge2 = v3 - v1;
        glm::vec3 faceNormal = glm::normalize(glm::cross(edge1, edge2));

        faceNormals.push_back(faceNormal);
    }

    std::vector<glm::vec3> vertexNormals(vertexArray.size(), glm::vec3(0.0f));

    for (size_t i = 0; i < indexArray.size(); ++i) {
        unsigned int vertexIndex = indexArray[i];
        vertexNormals[vertexIndex] += faceNormals[i / 3];
    }

    // Normalize the vertex normals
    for (auto& normal : vertexNormals) {
        normalArray.push_back(glm::normalize(normal));
    }

    return normalArray;

}
