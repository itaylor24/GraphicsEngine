//
// Created by Isaac Taylor on 1/16/24.
//

#include "Renderer.h"
#include "utils.h"

Renderer::Renderer(){
    GL_CALL(glEnable(GL_DEPTH_TEST));
}


void Renderer::Draw(const VertexArray &VAO, const IndexBuffer &IBO, const Shader &shader) {
    shader.Bind();
    VAO.Bind();
    IBO.Bind();
    GL_CALL(glDrawElements(GL_TRIANGLES, IBO.getCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::Clear() {
    GL_CALL(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));
    //GL_CALL(glClear(GL_COLOR_BUFFER_BIT));
}