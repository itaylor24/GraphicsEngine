//
// Created by Isaac Taylor on 3/7/24.
//

#ifndef GRAPHICSENGINE_MODEL_H
#define GRAPHICSENGINE_MODEL_H


#include "Mesh.h"
#include "Shader.h"
#include "RenderingItem.h"
#include "LightSource.h"

class Model : public RenderingItem{

public:
    explicit Model(std::string filename) ;
    void setLightSource(LightSource* light);
    void setDiffuse(float* diffuseColor);
    void setDiffuse(glm::vec4 diffuseColor);
    void RenderDetails() const override;
    float* _diffuseColor = new float[]{.5f, .1f, .3f};
    LightSource* _lightSource = nullptr;
};


#endif //GRAPHICSENGINE_MODEL_H
