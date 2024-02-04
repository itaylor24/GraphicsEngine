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
    std::ifstream objFileCopy(filename);

    if (!objFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
    }

    int vertSize = 0;
    int normalSize;

    std::vector<Vertex> vertices;
    std::vector<glm::vec3> normals;

    std::vector<unsigned int> indices;

    int iters = 0;
    std::string line;
    while (std::getline(objFileCopy, line)) {
        std::istringstream iss(line);
        std::string token;
        iss >> token;
        if (token == "v") {
            vertSize += 1;
        }
//        if(token == "vn" ){
//            normalSize += 1;
//            glm::vec3 normal;
//            iss >> normal.x >> normal.y >> normal.z;
//            //vertex.color = RANDOM_COLOR;
//            normals.push_back(normal);
//        }

    }

    std::cout << normalSize << "COMPARe"<< std::endl;
    std::cout << vertSize << "COMPARe"<< std::endl;

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
        if (token == "vn") {

        }
//      } else if (token == "f") {
//
//            unsigned int ix1, ix2, ix3;
//            iss >> ix1 >> ix2 >> ix3;
//
//            indices.push_back(ix1-1);
//            indices.push_back(ix2-1);
//            indices.push_back(ix3-1);
//
//        }
        else if (token == "f") {


//            std::string index;


            long int ix1, ix2, ix3;
            long int nx1, nx2, nx3;
            int tx1, tx2, tx3;
            char s;

            std::string block;

            for (int i = 0; i < 3; ++i) {

                iss >> block;

                if (block.find('/') != std::string::npos) {

                    //std::cout << "String contains '/'" << std::endl;

                    std::vector<std::string> result;

                    std::istringstream bstream(block);
                    std::string index;


                    while (std::getline(bstream, index, '/')) {
                        indexVars.push_back(std::stoi(index));


//                        std::cout << std::stol(index);
                    }

                    // Display the result
//                    for (const auto &substring : result) {
//
//                        std::cout << substring << std::endl;
//
//
//                    }


                } else {
                    //std::cout << "String does not contain '/'" << std::endl;

                    indexVars.push_back(std::stoi(block));

                    indexVars.push_back(0);
                    indexVars.push_back(0);

                }
            }


////            iss >> ix1
////            iss >> ix2
////            iss >> ix3
//
//            std::string delimiter = "/";
//            std::string begin = "f";
//
//            std::string part = iss.str();;
//
//            size_t pos = part.find(begin);
//
//            std::string token = part.substr(0, pos);
//
//            part.erase(0, pos + begin.length());
//
//            int ix = 0;
//
//            while ((pos = part.find(delimiter)) != std::string::npos) {
//
//                token = part.substr(0, pos);
//
//                ix++;
//
//                if(ix == 3 || ix == 5){
//                    //std::cout << token << "TOKEN" << std::endl;
//
//                    std::istringstream tokenstream(token);
//                    std::string newtoken;
//
//                    tokenstream >> newtoken;
//                    //token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
//                    //std::cout << std::stoi(newtoken) << std::endl;
//                    //std::cout << std::stoi(token) << std::endl;
//
//                    indexVars.push_back(std::stol(newtoken));
//
//                    ix++;
//                    tokenstream >> token;
////                    std::string space = " ";
////                    pos = token.find(space);
////
////                    token = token.substr(0, pos);
////
////                    token.erase(0, pos + space.length());
////
////                    token = token.substr(0, pos);
////                    STRIP(token);
////
////                    std::cout << std::stoi(token) << " O"<< std::endl;
////
////                    indexVars.push_back(std::stoi(token));
////
////                    ix++;
//
//                }
//
//                STRIP(token);
//                //token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
//                //std::cout << std::stoi(token) << " ix " << ix << std::endl;
//                //std::cout << std::stoi(token) << std::endl;
//
//                indexVars.push_back(std::stol(token));
//
//                part.erase(0, pos + delimiter.length());
//
//
//
//            }
//
//
//
////            std::cout << s << std::endl;
//
//            indices.push_back(ix1-1);
//            indices.push_back(ix2-1);
//            indices.push_back(ix3-1);
//
//
//


            ix1 = indexVars[0];
            ix2 = indexVars[3];
            ix3 = indexVars[6];

            nx1 = indexVars[1];
            nx2 = indexVars[4];
            nx3 = indexVars[7];

            tx1 = indexVars[2];
            tx2 = indexVars[5];
            tx3 = indexVars[8];

            if(ix1 <= 0){

                indices.push_back(ix1 + vertSize);
                indices.push_back(ix2 + vertSize);
                indices.push_back(ix3 + vertSize);

            }else{

                indices.push_back(ix1 - 1);
                indices.push_back(ix2 - 1);
                indices.push_back(ix3 - 1);

//                vertices[nx1-1].normal = normals[nx1-1];
//                vertices[nx1-1].normal = normals[nx1-2];
//                vertices[nx1-1].normal = normals[nx1-3];


//                vertices[ix1-1].normal = normals[nx1-1];
//                vertices[ix2-1].normal = normals[nx2-1];
//                vertices[ix3-1].normal = normals[nx3-1];

            }



        }


    }

    objFile.close();


    // Print the parsed vertices
    data->numVertices = vertices.size();
    std::cout << vertices.size();

    data->numIndices = indices.size();

    //data->vertices = new Vertex[data->numVertices];
    //data->indices = new unsigned int[data->numIndices];

//    std::cout<< data->numIndices << "INDICES" << std::endl;
//    std::cout<< data->numVertices << "VERTICES" << std::endl;

//    std::vector<unsigned int>::iterator i2 = std::min_element(std::begin(indices), std::end(indices));
//
//    std::cout <<  *i2 << "MIN" << std::endl;


//    for (int i = 0; i < indices.size(); ++i) {
//
//
//        if (indices[i] <= 0){
//
//            std::cout << indices[i] <<"," << std::endl;
//            std::cout << vertices.size();
//
//            indices[i] += (long int) vertices.size();
//
//
//
//        }else{
//
//            indices[i] -= 1;
//            std::cout << indices[i] <<"," << std::endl;
//
//        }
//
//
//    }

    normals = computeNormals(vertices, indices);

    for (int i = 0; i < vertices.size(); ++i) {
        vertices[i].normal = normals[i];
    }

    memcpy(data->indices, &indices[0], sizeof (unsigned int) * indices.size());
    memcpy(data->vertices, &vertices[0], sizeof (Vertex) * vertices.size());




//    for (int i = 0; i < data->numIndices; ++i) {
//        std::cout << data->indices[i] << std::endl;;
//    }

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

void Mesh::showVertices(){

//
//    std::cout<< data-> numVertices << std::endl;
//
//    for (int i = 0; i < data->numVertices; ++i) {
//        std::cout << glm::to_string(data->vertices[i].position) << std::endl;
//        std::cout << glm::to_string(data->vertices[i].color) << std::endl;
//    }
//
//
//    for (int i = 0; i < data->numIndices; ++i) {
//        std::cout << data->indices[i] << std::endl;;
//    }
}