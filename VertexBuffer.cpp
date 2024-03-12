//
// Created by Isaac Taylor on 1/16/24.
//


#include "VertexBuffer.h"
#include "utils.h"
#include "Types.h"

VertexBuffer::VertexBuffer(const void* data, unsigned int count){
    GL_CALL(glGenBuffers( 1, &_rendererID ));
    GL_CALL(glBindBuffer( GL_ARRAY_BUFFER, _rendererID));
    GL_CALL(glBufferData( GL_ARRAY_BUFFER, count, data, GL_STATIC_DRAW ));
}

VertexBuffer::VertexBuffer(ShapeData* shape){
    GL_CALL(glGenBuffers( 1, &_rendererID ));
    GL_CALL(glBindBuffer( GL_ARRAY_BUFFER, _rendererID));
    GL_CALL(glBufferData( GL_ARRAY_BUFFER, shape->vertexBufferSize(), shape->vertices, GL_STATIC_DRAW ));
}

VertexBuffer::VertexBuffer() {
}

VertexBuffer::~VertexBuffer(){
    GL_CALL(glDeleteBuffers(1, &_rendererID));
}

void VertexBuffer::Bind() const {
    GL_CALL(glBindBuffer( GL_ARRAY_BUFFER, _rendererID));
}
void VertexBuffer::Unbind() const {
    GL_CALL(glBindBuffer( GL_ARRAY_BUFFER, 0));

}






