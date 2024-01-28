//
// Created by Isaac Taylor on 1/25/24.
//

#ifndef GRAPHICSENGINE_UTILS_H
#define GRAPHICSENGINE_UTILS_H

#include <iostream>

#include "glew/include/GL/glew.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"
#define GLM_ENABLE_EXPERIMENTAL
#include "glm/gtx/string_cast.hpp"


#define GL_CALL(func) GLClearError(); \
    func;                            \
    assert(GLLogCall(#func, __FILE_NAME__, __LINE__));

#define RANDOM_COLOR glm::vec3 ((float)std::rand() / (float)RAND_MAX, 0.0f, 1.0f);
#define RANDOM_COLOR1 glm::vec3 ((float)std::rand() / (float)RAND_MAX, (float)std::rand() / (float)RAND_MAX, (float)std::rand() / (float)RAND_MAX);

bool GLLogCall(const char* func, const char* filename, int line);
void GLClearError();



#endif //GRAPHICSENGINE_UTILS_H
