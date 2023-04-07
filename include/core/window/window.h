//
// Created by leno on 3/26/23.
//

#ifndef LENOENGINE_WINDOW_H
#define LENOENGINE_WINDOW_H
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>

class Window{
private:
    GLFWwindow* window;
public:
    Window();
    virtual ~Window();

    void openWindow();
};

#endif //LENOENGINE_WINDOW_H
