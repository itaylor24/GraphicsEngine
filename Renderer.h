//
// Created by Isaac Taylor on 1/16/24.
//

#ifndef GRAPHICSENGINE_RENDERER_H
#define GRAPHICSENGINE_RENDERER_H

#include "glew/include/GL/glew.h"
#include <iostream>

#include "VertexArray.h"
#include "IndexBuffer.h"
#include "VertexBuffer.h"
#include "Shader.h"


#define GL_CALL(func) GLClearError(); \
    func;                            \
    assert(GLLogCall(#func, __FILE_NAME__, __LINE__));


void GLClearError();
bool GLLogCall(const char* func, const char* filename, int line);

class Renderer {

    public:
        Renderer();
        void Draw(const VertexArray& VAO, const IndexBuffer& IBO, const Shader& shader);
        void Clear();


};

#endif //GRAPHICSENGINE_RENDERER_H
