//
// Created by Isaac Taylor on 1/17/24.
//

#ifndef GRAPHICSENGINE_SHADER_H
#define GRAPHICSENGINE_SHADER_H

#include <iostream>
#include <unordered_map>
#include "glm/glm.hpp"

class Shader {
    private:
        unsigned int GetUniformLocation(const std::string& name);
        unsigned int _rendererID;
        unsigned int CompileShader(unsigned int type, const std::string& source);
        unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
        std::string ParseFile(const std::string& filePath);
        std::unordered_map<std::string, unsigned int> _uniformLoctionCache;



    public:
        Shader(const std::string& vertexSource, const std::string& fragmentSource);
        ~Shader();

        void Bind() const;
        void Unbind() const;
        void SetUniform4f( const std::string& name, float v0, float v1, float v2, float v3);
        void SetUniformMatrix4fv(const std::string &name, glm::mat4& matrix);



};


#endif //GRAPHICSENGINE_SHADER_H
