//
// Created by Isaac Taylor on 1/25/24.
//

#include "Camera.h"
#include "glfw/include/GLFW/glfw3.h"
#include <glm/gtx/rotate_vector.hpp>

Camera::Camera(int width, int height):
    _camFocus(0.0f,0.f, 0.0f),
    _up(0.0f, 1.0f, 0.0f),
    _yaw(0.f),
    _pitch(0.f),
    _radius(15.f),
    _initialView(0.f,0.f,-1.f),
    _right(1.0f, 0.0f, 0.0f),
    _rotation(1.f),
    _moveSpeed(10.f)
    {
        _position = _camFocus + (_initialView*_radius * -1.f);
        _viewDirection = _camFocus - _position;

        _projectionMatrix = glm::perspective(glm::radians(60.0f), ((float)width) / (float)height, 0.1f, 10000.0f);
        _MVP = _projectionMatrix * getWorldToViewMatrix();
    }

void Camera::mouseUpdate(const glm::vec2& newMousePosition){

    glm::vec2 mouseDelta = newMousePosition - _oldMousePosition;

    if (glm::length(mouseDelta) < 30.f && glm::length(mouseDelta) > 0){

        _yaw += -1.f*mouseDelta.x;
        _pitch += -1.f*(mouseDelta.y);

        if (_pitch >= 89.0f)
            _pitch = 89.0f;
        if (_pitch <= -89.0f)
            _pitch = -89.0f;

        glm::vec3  camToPos = glm::rotate(_initialView, glm::radians(_pitch), _right);
        camToPos = glm::rotate(camToPos, glm::radians(_yaw), _up);

        _position = _camFocus + (camToPos*_radius * -1.f);
        _viewDirection = _camFocus - _position;

    }

    _oldMousePosition = newMousePosition;

    _MVP = _projectionMatrix * getWorldToViewMatrix();

}
glm::mat4 Camera::getMVP() const {
    return _MVP;
}

glm::mat4 Camera::getWorldToViewMatrix() const{
    return glm::lookAt(_position, _camFocus, _up);
}

void Camera::zoomIn(){
//    _position += _moveSpeed * glm::normalize(_viewDirection);
//    glm::normalize(_viewDirection =_camFocus-_position);
    if (_radius > 5.f) {
        _radius -= _moveSpeed;
    }else{
        _radius = 5.f;
    }
    _position = _camFocus + (glm::normalize(_camFocus - _position)*_radius * -1.f);
    _viewDirection = _camFocus - _position;
    _MVP = _projectionMatrix * getWorldToViewMatrix();
}
void Camera::zoomOut(){
//    _position += _moveSpeed * -1.f * glm::normalize(_viewDirection);
//    _viewDirection =glm::normalize(_camFocus-_position);

    _radius += _moveSpeed;

    _position = _camFocus + (glm::normalize(_camFocus - _position)*_radius * -1.f);
    _viewDirection = _camFocus - _position;
    _MVP = _projectionMatrix * getWorldToViewMatrix();
}

