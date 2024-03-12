//
// Created by Isaac Taylor on 3/10/24.
//

#ifndef GRAPHICSENGINE_LIGHTSOURCE_H
#define GRAPHICSENGINE_LIGHTSOURCE_H


#include "RenderingItem.h"

class LightSource : public RenderingItem{
public:
    LightSource();
    void RenderDetails() const override;
};


#endif //GRAPHICSENGINE_LIGHTSOURCE_H
