//
// Created by leno on 3/30/23.
//

#ifndef LENOENGINE_SHADERPROGRAM_H
#define LENOENGINE_SHADERPROGRAM_H
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>


class ShaderProgram{
private:

    virtual void abstract() = 0;
    unsigned int compileShader(const char* pathToShader,unsigned int type);

protected:
    /**
     * Shaders path to file
     */
    const char* vertexShader;
    const char* fragmentShader;

    /**
     * All the necessary ID's
     */
    unsigned int programId;

    ShaderProgram(const char* vertexShader,
                  const char* fragmentShader);

public:
    /**
     * Shaders initialization functions
     */
     void initProgram();
     void createShaders();

    /**
     * Getters functions
     * @return
     */
    bool isVertexShader();
    bool isFragmentShader();

protected:
    virtual ~ShaderProgram();

public:
};

#endif //LENOENGINE_SHADERPROGRAM_H
