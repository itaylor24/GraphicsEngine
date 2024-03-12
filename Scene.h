//
// Created by Isaac Taylor on 3/12/24.
//

#ifndef GRAPHICSENGINE_SCENE_H
#define GRAPHICSENGINE_SCENE_H

#include <iostream>
#include <vector>

class SceneNode {
public:
    SceneNode* _parent = nullptr;
    std::vector<SceneNode*>* _children = new std::vector<SceneNode*>();
};


#endif //GRAPHICSENGINE_SCENE_H
