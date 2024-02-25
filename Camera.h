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
    glm::vec3 _right;
    glm::vec3 _camFocus;
    glm::vec3 _initialView;
    glm::vec2  _oldMousePosition;
    glm::mat4 _rotation = glm::mat4(1.f);
    float _moveSpeed = 10.f;
    float _yaw;
    float _pitch;
    float _radius;


public:
    Camera();
    glm::mat4 getWorldToViewMatrix() const;
    glm::mat4 getRotation();

    void mouseUpdate(const glm::vec2& newMousePosition);

    void moveForward();
    void moveBackward();

    void moveLeft();
    void moveRight();

    void moveUp();
    void moveDown();
    glm::vec3 getViewDirection();

};


#endif //GRAPHICSENGINE_CAMERA_H
