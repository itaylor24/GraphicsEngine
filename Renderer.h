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
#include "Mesh.h"
#include "Model.h"



//void GLClearError();
//bool GLLogCall(const char* func, const char* filename, int line);

class Renderer {

    public:

        Renderer();
        void Draw(Mesh* mesh, const Shader& shader);
        void Draw(const std::vector<std::pair<Mesh*, Shader&>>& items);
        void Draw();
        void Draw(VertexArray& VAO, IndexBuffer& IBO, const Shader &shader);
        void Clear();

        void Draw(std::vector<RenderingItem*> items);

        std::vector<RenderingItem*> _items;
        void AddItem(Mesh* mesh, Shader &shader);
        void AddItem(RenderingItem* item);

};

#endif //GRAPHICSENGINE_RENDERER_H
