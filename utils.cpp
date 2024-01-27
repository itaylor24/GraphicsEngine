//
// Created by Isaac Taylor on 1/25/24.
//

#include "utils.h"

bool GLLogCall(const char* func, const char* filename, int line){
    while(GLenum error  = glGetError()){
        std::cout << "<OpenGL Error> (" << error << ") on "  << func << " at " << filename << " | " << line << std::endl;
        return false;
    }
    return true;
}

void GLClearError(){
    while(glGetError() != GL_NO_ERROR);
}
