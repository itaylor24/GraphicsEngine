//
// Created by Isaac Taylor on 1/16/24.
//

#ifndef GRAPHICSENGINE_VERTEXBUFFER_H
#define GRAPHICSENGINE_VERTEXBUFFER_H

class VertexBuffer {

    private:
        unsigned int _rendererID;
    public:
        VertexBuffer(const void* data, unsigned int size);
        VertexBuffer();
        ~VertexBuffer();

        void Bind() const;
        void Unbind() const;

};


#endif //GRAPHICSENGINE_VERTEXBUFFER_H
