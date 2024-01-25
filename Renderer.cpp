//
// Created by Isaac Taylor on 1/16/24.
//

#include "Renderer.h"

void GLClearError(){
    while(glGetError() != GL_NO_ERROR);
}
bool GLLogCall(const char* func, const char* filename, int line){
    while(GLenum error  = glGetError()){
        std::cout << "<OpenGL Error> (" << error << ") on "  << func << " at " << filename << " | " << line << std::endl;
        return false;
    }
    return true;
}

void Renderer::Draw(const VertexArray &VAO, const IndexBuffer &IBO, const Shader &shader) {
    shader.Bind();
    VAO.Bind();
    IBO.Bind();
    GL_CALL(glDrawElements(GL_TRIANGLES, IBO.getCount(), GL_UNSIGNED_INT, nullptr));
}

void Renderer::Clear() {
    GL_CALL(glClear(GL_COLOR_BUFFER_BIT));
}