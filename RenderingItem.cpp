//
// Created by Isaac Taylor on 3/10/24.
//

#include "RenderingItem.h"
#include "Camera.h"

RenderingItem::RenderingItem() = default;

void RenderingItem::Render() const{

    _shader->Bind();
    glm::mat4 MVP = _camera->getMVP();
    glm::mat4 translation = glm::translate(glm::mat4 (1.f), glm::vec3(
            _controlPosition[0], _controlPosition[1], _controlPosition[2]
    ));
    glm::mat4 transform = MVP*translation;
    _shader->SetUniformMatrix4fv("MVP", transform);

    RenderDetails();

    _mesh->_mVAO->Bind();
    _mesh->_mIBO->Bind();

    GL_CALL(glDrawElements(GL_TRIANGLES, _mesh->_mIBO->getCount(), GL_UNSIGNED_INT, nullptr));

}

Mesh* RenderingItem::getMesh() const {
    return _mesh;
}

Shader* RenderingItem::getShader() const {
    return _shader;
}

void RenderingItem::controlPosition(float* position){
    _controlPosition = position;
}
void RenderingItem::attachCamera(Camera* camera){
    _camera = camera;
}

glm::vec3 RenderingItem::getPosition() const {
    return {_controlPosition[0], _controlPosition[1], _controlPosition[2]};
}