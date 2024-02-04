#version 410 core
//shader vertex

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 vertColor;
layout(location = 2) in vec3 normal;

uniform mat4 MVP;
uniform vec3 ambientLight;

out vec3 theNormal;
out vec3 thePosition;

void main()
{
    vec4 newPosition = MVP * vec4(position, 1.0f);
    gl_Position = newPosition;

    //outColor = vertColor * ambientLight;
    //outColor = vertColor;


    theNormal = normal;
    thePosition = position;
}

