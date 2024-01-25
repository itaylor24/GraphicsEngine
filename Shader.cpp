//
// Created by Isaac Taylor on 1/17/24.
//

#include "Shader.h"
#include "Renderer.h"

#include <iostream>
#include <fstream>
#include <cassert>




Shader::Shader(const std::string& vertexSource, const std::string& fragmentSource)  {

    _rendererID = 0;
    std::string vertexShaderContent = ParseFile(vertexSource);
    std::string fragmentShaderContent = ParseFile(fragmentSource);
    _rendererID = CreateShader(vertexShaderContent, fragmentShaderContent);

}

Shader::~Shader() {
    GL_CALL(glDeleteProgram(_rendererID));
}

unsigned int Shader::CreateShader(const std::string& vertexShader, const std::string& fragmentShader){
    unsigned int program = glCreateProgram();

    unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
    unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

    GL_CALL(glAttachShader(program, vs));
    GL_CALL(glAttachShader(program, fs));
    GL_CALL(glLinkProgram(program));
    GL_CALL(glValidateProgram(program));

    GL_CALL(glDeleteShader(vs));
    GL_CALL(glDeleteShader(fs));

    return program;
}

unsigned int Shader::CompileShader(unsigned int type, const std::string& source) {
    unsigned int id = glCreateShader(type);
    const char* src = source.c_str();

    glShaderSource(id, 1, &src, nullptr);
    glCompileShader(id);


    int result;
    glGetShaderiv(id, GL_COMPILE_STATUS, &result);

    if(result == GL_FALSE){
        int length;
        glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
        char* message = (char *)alloca(length * sizeof(char));

        glGetShaderInfoLog(id, length, &length, message);
        std::cout<< "FAILED TO COMPILE" << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << std::endl;
        std::cout << message << std::endl;
        glDeleteShader(id);
        return 0;
    }


    return id;
}

std::string Shader::ParseFile(const std::string& filePath){

    std::ifstream file(filePath);
    std::string str;
    std::string content;

    while (std::getline(file, str)) {
        content.append(str + "\n");
    }
    return content;

}

unsigned int Shader::GetUniformLocation(const std::string& name){

    if(_uniformLoctionCache.find(name) != _uniformLoctionCache.end()){
        return _uniformLoctionCache[name];
    }

    GL_CALL(unsigned int location = glGetUniformLocation(_rendererID, name.c_str()));
    if (location == -1){
        std::cout << "<Warning> Uniform " << name << " is not present in shader";
    }

    _uniformLoctionCache[name] = location;
    return location;
}


void Shader::Bind() const {
    GL_CALL(glUseProgram(_rendererID));
}

void Shader::Unbind() const {
    GL_CALL(glUseProgram(0));
}

void Shader::SetUniform4f(const std::string &name, float v0, float v1, float v2, float v3) {
    unsigned int location = GetUniformLocation(name);
    GL_CALL(glUniform4f(location, v0, v1, v2, v3));
}

