#version 410 core
//shader vertex

layout(location = 0) in vec4 position;

void main()
{
    gl_Position = position;
}

