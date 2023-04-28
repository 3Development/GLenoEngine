#version 460 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec4 color;

uniform mat4 translationMatrix;

out vec4 color_combine;
void main(){
    gl_Position = translationMatrix * vec4(position.xyz,1);
    color_combine = color;
}