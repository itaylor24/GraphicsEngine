//
// Created by Isaac Taylor on 3/7/24.
//

#include "Model.h"
#include "RenderingItem.h"

Model::Model(std::string filename){
    _shader = new Shader("../shaders/Basic.vert", "../shaders/Basic.frag");
    _mesh = new Mesh(filename);
}

void Model::setDiffuse(float* color){
    _diffuseColor = color;
}

void Model::setLightSource(LightSource* light) {
    _lightSource = light;
}

void Model::RenderDetails() const {
    _shader->SetUniform3f("diffuseColor", glm::vec3 (_diffuseColor[0], _diffuseColor[1], _diffuseColor[2]));
    glm::vec3  lightPosition = _lightSource->getPosition();
    _shader->SetUniform3f("lightPosition", lightPosition);
}

