#version 410 core
//shader fragment

out vec4 color;
in vec3 outColor;

uniform vec4 u_Color;

void main()
{
    //color = u_Color;
    color =  vec4(outColor.xyz, 1);
}

