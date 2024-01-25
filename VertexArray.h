//
// Created by Isaac Taylor on 1/16/24.
//

#ifndef GRAPHICSENGINE_VERTEXARRAY_H
#define GRAPHICSENGINE_VERTEXARRAY_H

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

class VertexArray {
    private:
        unsigned int _rendererID;
    public:
        VertexArray();
        ~VertexArray();

        void AddBuffer(const VertexBuffer& vertexBuffer, const VertexBufferLayout& layout);
        void Bind() const;
        void Unbind() const;

};


#endif //GRAPHICSENGINE_VERTEXARRAY_H
