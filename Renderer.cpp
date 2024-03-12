//
// Created by Isaac Taylor on 1/16/24.
//

#include "Renderer.h"
#include "utils.h"
#include "Model.h"

Renderer::Renderer(){
    GL_CALL(glEnable(GL_DEPTH_TEST));
}


void Renderer::Draw(Mesh* mesh, const Shader &shader) {
    shader.Bind();
    mesh->_mVAO->Bind();
    mesh->_mIBO->Bind();
    GL_CALL(glDrawElements(GL_TRIANGLES, mesh->_mIBO->getCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::Draw(const std::vector<std::pair<Mesh*, Shader&>>& items) {
    for (auto & item : items) {
        Mesh* mesh = item.first;
        Shader& shader = item.second;
        Draw(mesh, shader);
    }
}

void Renderer::Draw(std::vector<RenderingItem*> items) {
    for (auto item : items) {
        item->Render();
    }
}

void Renderer::Draw() {
    Draw(_items);
}

void Renderer::AddItem(RenderingItem* item) {
    _items.push_back(item);
}

void Renderer::Draw(VertexArray& VAO, IndexBuffer& IBO, const Shader &shader) {
    shader.Bind();
    VAO.Bind();
    IBO.Bind();
    GL_CALL(glDrawElements(GL_TRIANGLES, IBO.getCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::Clear() {
    GL_CALL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
    // GL_CALL(glClear(GL_COLOR_BUFFER_BIT));
}