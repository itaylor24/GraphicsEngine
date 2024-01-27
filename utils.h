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

bool GLLogCall(const char* func, const char* filename, int line);
void GLClearError();



#endif //GRAPHICSENGINE_UTILS_H
