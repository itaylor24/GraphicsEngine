//
// Created by Isaac Taylor on 1/16/24.
//



#ifndef GRAPHICSENGINE_VERTEXBUFFERLAYOUT_H
#define GRAPHICSENGINE_VERTEXBUFFERLAYOUT_H

#include <iostream>
#include <vector>
#include "glew/include/GL/glew.h"

struct VertexBufferElement{
    unsigned int type;
    unsigned int count;
    unsigned char normalized;

    static unsigned int typeSize(unsigned int type){
        switch (type) {
            case GL_FLOAT:
                return 4;
            case GL_UNSIGNED_INT:
                return 4;
            case GL_UNSIGNED_BYTE:
                return 1;
            default:
                assert(false);
                return 0;

        }
    }

};

class VertexBufferLayout{
    private:
        std::vector<VertexBufferElement> _elements;
        unsigned int _stride = 0;

    public:
        template<typename T>
        void Push(unsigned int count);


        template<>
        void Push<float>(unsigned int count){
            _elements.push_back(VertexBufferElement{GL_FLOAT, count, GL_FALSE});
            _stride += count * VertexBufferElement::typeSize (GL_FLOAT);
        }

        template<>
        void Push<unsigned int>(unsigned int count){
            _elements.push_back(VertexBufferElement{GL_UNSIGNED_INT, count, GL_FALSE});
            _stride += count * VertexBufferElement::typeSize(GL_UNSIGNED_INT);
        }

        template<>
        void Push<unsigned char>(unsigned int count){
            _elements.push_back(VertexBufferElement{GL_UNSIGNED_BYTE, count, GL_TRUE});
            _stride += count * VertexBufferElement::typeSize (GL_UNSIGNED_BYTE);
        }

        inline const std::vector<VertexBufferElement> getElements() const { return _elements; };
        inline unsigned int getStride() const { return _stride; }


};

#endif //GRAPHICSENGINE_VERTEXBUFFERLAYOUT_H
