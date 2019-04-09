#version 330 core

layout(location=0) in vec3 position;
layout(location=1) in vec3 normal;

uniform mat4 projectionMat;
uniform mat4 modelViewMat;

out Data
{
    vec3 positionViewspace;
    vec3 normalViewspace;

}VSOut;

void main(void)
{
    VSOut.positionViewspace = (modelViewMat * vec4(position, 1)).xyz;
    VSOut.normalViewspace = (modelViewMat * vec4(normal, 0)).xyz;

    gl_Position = projectionMat * vec4(VSOut.positionViewspace, 1.0);
}
