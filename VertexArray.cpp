//
// Created by Isaac Taylor on 1/16/24.
//

#include "VertexArray.h"
#include "Renderer.h"

VertexArray::VertexArray() {
        GL_CALL(glGenVertexArrays( 1, &_rendererID  ));
}

VertexArray::~VertexArray() {
    GL_CALL(glDeleteVertexArrays(1, &_rendererID ));
}

void VertexArray::AddBuffer(const VertexBuffer &vertexBuffer, const VertexBufferLayout &layout) {

    Bind();
    vertexBuffer.Bind();
    unsigned char* offset = nullptr;

    const auto& elements = layout.getElements();
    for (unsigned int i = 0; i < elements.size(); i++) {

        const auto& element = elements[i];
        GL_CALL(glEnableVertexAttribArray( i ));
        GL_CALL(glVertexAttribPointer( i, element.count, element.type, element.normalized, layout.getStride() , (const void *)offset ));
        offset += element.count * VertexBufferElement::typeSize(element.type);
    }

}

void VertexArray::Bind() const {
    GL_CALL(glBindVertexArray(_rendererID ));
}

void VertexArray::Unbind() const {
    GL_CALL(glBindVertexArray (0));
}

