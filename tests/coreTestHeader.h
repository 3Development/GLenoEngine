//
// Created by leno on 25.04.23..
//

#ifndef LENOENGINE_CORETESTHEADER_H
#define LENOENGINE_CORETESTHEADER_H
#include <gtest/gtest.h>
#include <GL/glew.h>
#include "yaml-cpp/yaml.h"
#include "GLFW/glfw3.h"

#define TEST_DESCRIPTION(desc,name)  std::cerr<<"\n" <<"        Test name    "<< name<<"\n" << "\n" <<"[   DESC   ]  = " << desc<< "\n" << std::endl;




void initOpenGlWindowEmptyWindow(){
    if (!glfwInit())
    {
        // Initialization failed
        std::cout<<"Helldsadsao word!l"<<std::endl;
    }

    // Open buffer window and create its OpenGL context
    //Using buffer field of class window, this one will store the pointer to the window
    GLFWwindow* window = glfwCreateWindow( 1024, 768, "Testing 01", NULL, NULL);

    if(window == NULL){
        glfwTerminate();
    }


    glfwMakeContextCurrent(window);

    glewExperimental=true;
    if(glewInit() != GLEW_OK){
        std::cout<<"Glew not initialized "<<std::endl;
    }

    glEnable( GL_DEBUG_OUTPUT );
}




#endif //LENOENGINE_CORETESTHEADER_H
