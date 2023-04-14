//
// Created by leno on 3/26/23.
//

/*    TABLE 2.1 OpenGL Variable Types’ Corresponding C Data Types
    OpenGL Data Internal Defined as C C
    Type Representation Type Literal Suffix
    GLbyte 8-bit integer signed char b
    GLshort 16-bit integer short s
    GLint, GLsizei 32-bit integer long l
    GLfloat, 32-bit floating float f
    GLclampf point
    GLdouble, 64-bit floating double d
    GLclampd point
    GLubyte, 8-bit unsigned unsigned char ub
    GLboolean integer
    GLushort 16-bit unsigned unsigned short us
    integer
    GLuint, GLenum, 32-bit unsigned unsigned long ui
    GLbitfield integer
    GLchar 8-bit character char None
    GLsizeiptr,
    GLintptr native pointer ptrdiff_t None

    */

#include "core/window/window.h"
#define GLFW_INCLUDE_GL_3
using namespace std;

Window::Window() {}

Window::~Window() {

}
void Window::openWindow() {
    if (!glfwInit())
    {
        // Initialization failed
        std::cout<<"Helldsadsao word!l"<<std::endl;
    }

    // Open a window and create its OpenGL context
    //Using a field of class window, this one will store the pointer to the window
    window = glfwCreateWindow( 1024, 768, "Tutorial 01", NULL, NULL);

    if(window == NULL){



    }
    glfwMakeContextCurrent(window);
    glewExperimental=true;
    if(glewInit() != GLEW_OK){
        std::cout<<"Glew not initialized "<<std::endl;
    }

    while(true){

    }


}
