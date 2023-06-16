//
// Created by leno on 25.04.23..
//

#ifndef LENOENGINE_CORETESTHEADER_H
#define LENOENGINE_CORETESTHEADER_H
#include <gtest/gtest.h>
#include <GL/glew.h>
#include "yaml-cpp/yaml.h"
#include "GLFW/glfw3.h"
#include <chrono>
#include "core/gl/shader/shaderProgram.h"
#include "core/gl/vbo&vao/vaoVbo.h"

#define TEST_DESCRIPTION(desc,name)  std::cerr<<"\n" <<"        Test name    "<< name<<"\n" << "\n" <<"[   DESC   ]  = " << desc<< "\n" << std::endl;


/**
 * Creates a window context
 */
void initOpenGlWindowEmptyWindow(){
    if (!glfwInit())
    {
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

/**
 * Basic shader class
 */

class ShaderBasicProgram: public ::testing::Test {
public:
    std::string vertex;
    std::string fragment;

    ShaderProgram* shaderProgram;


    ShaderBasicProgram(){
        initOpenGlWindowEmptyWindow();
        YAML::Node config = YAML::LoadFile(ENGINE_PROPERTIES_YAML);
        std::string root = std::string(config["resourceRootDir"].as<std::string>());
        vertex = std::string(root).append("shaders/basic/basicShader.vert");
        fragment = std::string(root).append("shaders/basic/basicShader.frag");

        shaderProgram = new ShaderProgram(vertex.c_str(),fragment.c_str());
    }

    ~ShaderBasicProgram(){
        delete shaderProgram;
    }

    void SetUp() override{
        shaderProgram->initProgram();
        shaderProgram->createShaders();
    }
};






/**
 * TIMER CLASS
 */

class Timer{

public:

    Timer(){
        _startPoint = std::chrono::high_resolution_clock::now();
    }
    ~Timer(){
        stop();
    }

    void stop(){

        auto endPoint = std::chrono::high_resolution_clock::now();

        auto start = std::chrono::time_point_cast<std::chrono::microseconds>(_startPoint).time_since_epoch().count();
        auto end = std::chrono::time_point_cast<std::chrono::microseconds>(endPoint).time_since_epoch().count();


        auto duration = end - start;
        auto ms = duration * 0.001;
        auto seconds = duration * 0.000001;
        std::cout<<"______TIMER_______"<<std::endl;

        std::cout<<"Duration in micro  "<<duration<<std::endl;
        std::cout<<"Duration in milis  "<<ms<<std::endl;
        std::cout<<"Duration in seconds  "<<seconds<<std::endl;

        std::cout<<"______TIMER_______\n\n\n"<<std::endl;
    }
private:
    std::chrono::time_point<std::chrono::high_resolution_clock > _startPoint;
};





#endif //LENOENGINE_CORETESTHEADER_H
