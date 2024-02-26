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
    vec3 myColor = brightness * ambientLight;

    myColor = vec3(clamp(myColor.x,0.f,1.f),clamp(myColor.y,0.f,1.f),clamp(myColor.z,0.f,1.f));

    color =  vec4((.4*vec3(1.f,1.f,1.f))*ambientLight + myColor.xyz*2.f, 1);
}

