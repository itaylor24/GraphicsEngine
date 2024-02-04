//
// Created by Isaac Taylor on 1/25/24.
//

#ifndef GRAPHICSENGINE_CAMERA_H
#define GRAPHICSENGINE_CAMERA_H

#include "glm/glm.hpp"
#include "utils.h"

class Camera {
private:

    glm::vec3 _position;
    glm::vec3 _viewDirection;
    glm::vec3 _up;
    glm::vec2  _oldMousePosition;
    float _moveSpeed = 1.0f;

public:
    Camera();
    glm::mat4 getWorldToViewMatrix() const;
    void mouseUpdate(const glm::vec2& newMousePosition);

    void moveForward();
    void moveBackward();

    void moveLeft();
    void moveRight();

    void moveUp();
    void moveDown();

};


#endif //GRAPHICSENGINE_CAMERA_H
