//
// Created by Isaac Taylor on 3/10/24.
//

#ifndef GRAPHICSENGINE_RENDERINGITEM_H
#define GRAPHICSENGINE_RENDERINGITEM_H


#include "Shader.h"
#include "Mesh.h"
#include "Camera.h"
#include "Scene.h"

class RenderingItem: public SceneNode{

public:

    Mesh* _mesh = nullptr;
    Shader* _shader = nullptr;
    RenderingItem();
    void Render() const;
    Mesh* getMesh() const;
    Shader* getShader() const;
    void controlPosition(float* position);
    void controlPosition(glm::vec3* position);
    glm::mat4 _transformMatrix = glm::mat4 (1.f);
    float* _controlPosition = new float[]{0,0,0};
    void attachCamera(Camera* camera);
    Camera* _camera;
    virtual void RenderDetails() const = 0;
    glm::vec3 getPosition() const;
};


#endif //GRAPHICSENGINE_RENDERINGITEM_H
