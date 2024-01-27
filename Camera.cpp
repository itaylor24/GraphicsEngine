//
// Created by Isaac Taylor on 1/25/24.
//

#include "Camera.h"

Camera::Camera():
    _viewDirection(0.0f, 0.0f, -1.0f),
    _up(0.0f, 1.0f, 0.0f),
    _position(0.f)
    {

    }

void Camera::mouseUpdate(const glm::vec2& newMousePosition){

    glm::vec2 mouseDelta = newMousePosition - _oldMousePosition;
    if (glm::length(mouseDelta) < 30.f){
        _viewDirection = glm::mat3 (glm::rotate(glm::mat4 (1.0f), glm::radians(mouseDelta.x)/7.f, _up)) * _viewDirection;
        glm::vec3 toRotateAround = glm::cross(_viewDirection, _up);
        _viewDirection = glm::mat3 (glm::rotate(glm::mat4 (1.0f), glm::radians(mouseDelta.y /7.f), toRotateAround)) * _viewDirection;
    }
    _oldMousePosition = newMousePosition;
}
glm::mat4 Camera::getWorldToViewMatrix() const{
    return glm::lookAt(_position, _position+_viewDirection, _up);
}

void Camera::moveForward(){
    _position += _moveSpeed * _viewDirection;
}
void Camera::moveBackward(){
    _position += _moveSpeed * -1.f * _viewDirection;
}
void Camera::moveLeft(){
    _position += _moveSpeed * -1.f * glm::cross(_viewDirection, _up);
}
void Camera::moveRight(){
    _position += _moveSpeed  * glm::cross(_viewDirection, _up);
}
void Camera::moveUp(){
    _position += _moveSpeed * -1.f * _up;
}
void Camera::moveDown(){
    _position += _moveSpeed * _up;

}
