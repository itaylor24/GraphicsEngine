//
// Created by Isaac Taylor on 1/25/24.
//

#include "Camera.h"
#include "glfw/include/GLFW/glfw3.h"

Camera::Camera():
    _viewDirection(0.0f, 0.0f, -1.0f),
    _up(0.0f, 1.0f, 0.0f),
    _position(0.f)
    {

    }

void Camera::mouseUpdate(const glm::vec2& newMousePosition){

    glm::vec2 mouseDelta = newMousePosition - _oldMousePosition;
    std::cout << glm::length(mouseDelta) << std::endl;
    glm::mat4 rotation(1.0f);

    if (glm::length(mouseDelta) < 10.f && glm::length(mouseDelta) > 0){

//        _viewDirection = glm::mat3 (glm::rotate(glm::mat4 (1.0f), glm::radians(mouseDelta.x)/7.f, _up)) * _viewDirection;
//        glm::vec3 toRotateAround = glm::cross(_viewDirection, _up);
//        _viewDirection = glm::mat3 (glm::rotate(glm::mat4 (1.0f), glm::radians(mouseDelta.y /7.f), toRotateAround)) * _viewDirection;

        glm::vec3 toRotateAround = glm::cross(glm::vec3(glm::normalize(glm::vec2 (mouseDelta.x, mouseDelta.y * -1.f)), 0.f), glm::vec3(0.f, 0.f, -1.f));
        rotation = glm::rotate(glm::mat4(1.0f), .04f * glm::length(mouseDelta),  glm::normalize(toRotateAround));

    }

    _oldMousePosition = newMousePosition;
    _rotation =  rotation * _rotation;


}
glm::mat4 Camera::getWorldToViewMatrix() const{
    return glm::lookAt(_position, _position+_viewDirection, _up);
}

glm::mat4 Camera::getRotation() {
    return _rotation;
}

void Camera::moveForward(){
    _position += _moveSpeed * _viewDirection;
}
void Camera::moveBackward(){
    _position += _moveSpeed * -1.f * _viewDirection;
}
void Camera::moveLeft(){
//    _position += _moveSpeed * -1.f * glm::cross(_viewDirection, _up);
}
void Camera::moveRight(){
//    _position += _moveSpeed  * glm::cross(_viewDirection, _up);
}
void Camera::moveUp(){
//    _position += _moveSpeed * -1.f * _up;
}
void Camera::moveDown(){
//    _position += _moveSpeed * _up;

}
