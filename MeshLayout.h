//
// Created by Isaac Taylor on 3/4/24.
//

#include "VertexBufferLayout.h"

#ifndef GRAPHICSENGINE_MESHLAYOUT_H
#define GRAPHICSENGINE_MESHLAYOUT_H

#endif //GRAPHICSENGINE_MESHLAYOUT_H

class MeshLayout: public VertexBufferLayout{

public:
    MeshLayout(){
        Push<float>(3);
        Push<float>(3);
        Push<float>(3);
    }
};
