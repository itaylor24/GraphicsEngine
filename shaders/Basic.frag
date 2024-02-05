#version 410 core
//shader fragment

out vec4 color;
in vec3 outColor;
in vec3 theNormal;
in vec3 thePosition;

uniform vec3 u_Color;
uniform vec3 lightPosition;
uniform vec3 ambientLight;

void main()
{
    vec3 lightVector = normalize(lightPosition - thePosition);
    float brightness = dot(lightVector, theNormal);
    vec3 myColor = brightness * u_Color;
    color =  vec4(myColor.xyz + ambientLight, 1);
}

