#version 460 core

out vec4 color;
in vec4 color_combine;
void main(){
    color = color_combine;
}