#version 460 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec4 color;

uniform mat4 translationM;
uniform mat4 projectionM;
uniform mat4 rotationM;

out vec4 color_combine;
void main(){
    gl_Position = projectionM * (  translationM * rotationM * vec4(position, 1) );
    color_combine = color;
}