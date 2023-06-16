//
// Created by leno on 3/30/23.
//

#ifndef LENOENGINE_SHADERPROGRAM_H
#define LENOENGINE_SHADERPROGRAM_H
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include "utilz/io/fileReaders.h"
#include "uniformHolder.h"
#include "../enums/glenums.h"



class ShaderProgram{
private:
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

    /**
     * uniforms holder
     */
    UniformsHolder uniformsHolder;

public:
    ShaderProgram(const char* vertexShader,
                  const char* fragmentShader);
    ~ShaderProgram();
    /**
     * Shaders initialization functions
     */
     void initProgram();

     void createShaders();

     void activateProgram();

     void deactivateProgram();

     bool initUniformLocation(UniformEnums::UniformType type);

    /**
     * Getters functions
     * @return
     */
    bool isVertexShader();

    bool isFragmentShader();

    unsigned int getProgramId();

    const UniformsHolder* getUniformsHolder();

    unsigned int getLocationIdOfUniform(UniformEnums::UniformType type);

protected:


};

#endif //LENOENGINE_SHADERPROGRAM_H
