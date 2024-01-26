#version 410 core
//shader vertex

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 vertColor;

uniform mat4 MVP;

out vec3 outColor;

void main()
{
    vec4 newPosition = MVP * vec4(position, 1.0f);

    gl_Position = newPosition;

    outColor = vertColor;
}

