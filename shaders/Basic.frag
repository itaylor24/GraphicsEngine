#version 410 core
//shader fragment

out vec4 color;
in vec3 outColor;
in vec3 theNormal;
in vec3 thePosition;

uniform vec3 u_Color;
uniform vec3 lightPosition;

void main()
{
    vec3 lightVector = normalize(lightPosition - thePosition);
    float brightness = dot(lightVector, theNormal);
    vec3 myColor = brightness * u_Color;
    color =  vec4(myColor.xyz, 1);
}

