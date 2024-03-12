//
// Created by Isaac Taylor on 3/10/24.
//

#include "LightSource.h"

LightSource::LightSource(){

    ShapeData* light = new ShapeData;

    *light = Shapes::makeCube(1.f, glm::vec3(1.f));
    _mesh = new Mesh(light);

    _shader = new Shader("../shaders/Basic.vert", "../shaders/Basic.frag");

    _shader->Bind();
    _shader->SetUniform3f("diffuseColor", glm::vec3(5.f));
    _shader->Unbind();

}

void LightSource::RenderDetails() const {

}