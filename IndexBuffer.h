//
// Created by Isaac Taylor on 1/16/24.
//

#ifndef GRAPHICSENGINE_INDEXBUFFER_H
#define GRAPHICSENGINE_INDEXBUFFER_H

class IndexBuffer {

private:
    unsigned int _rendererID;
    unsigned int _count;
public:
    IndexBuffer(const unsigned int* data, unsigned int count);
    ~IndexBuffer();

    void Bind() const ;
    void Unbind() const;

    inline unsigned int getCount() const { return _count; }

};

#endif //GRAPHICSENGINE_INDEXBUFFER_H
