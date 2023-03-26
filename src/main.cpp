#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#define GLFW_INCLUDE_GL_3
using namespace std;

int main(){
    if (!glfwInit())
    {
        // Initialization failed
            std::cout<<"Helldsadsao word!l"<<std::endl;
    }

      // Open a window and create its OpenGL context 
    GLFWwindow* window; // (In the accompanying source code, this variable is global) 
    window = glfwCreateWindow( 1024, 768, "Tutorial 01", NULL, NULL); 

    while(true){
        
    }
    std::cout<<"Helldsadsao word!l"<<std::endl;
    return 1;
}