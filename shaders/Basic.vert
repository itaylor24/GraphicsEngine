#version 410 core
//shader vertex

layout(location = 0) in vec4 position;
layout(location = 1) in vec3 vertColor;

out vec3 outColor;

void main()
{
    gl_Position = position;
    outColor = vertColor;
}

