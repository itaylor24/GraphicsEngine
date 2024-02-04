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

#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

#define STRIP(token) token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());

#define GL_CALL(func) GLClearError(); \
    func;                            \
    assert(GLLogCall(#func, __FILE_NAME__, __LINE__));

#define RANDOM_COLOR glm::vec3 ((float)std::rand() / (float)RAND_MAX, (float)std::rand() / (float)RAND_MAX, (float)std::rand() / (float)RAND_MAX);

bool GLLogCall(const char* func, const char* filename, int line);
void GLClearError();



#endif //GRAPHICSENGINE_UTILS_H
