//
// Created by leno on 3/30/23.
//
#include "core/gl/shader/shaderProgram.h"

/**
 * Main constructor
 */


ShaderProgram::ShaderProgram(const char *vertexShader, const char *fragmentShader) {
    if(vertexShader != nullptr){
        this->vertexShader = vertexShader;
        this->fragmentShader = fragmentShader;
    }
}

/**
 * Main deconstructor. All classes that inherit this class
 * should have their own deconstructor
 */
ShaderProgram::~ShaderProgram() {

}




//Functions-----------------------------------------------------

unsigned int ShaderProgram::compileShader(const char *pathToShader,unsigned int type) {
    unsigned int vs = glCreateShader(type);
    const char* src = "";
    glShaderSource(vs,1,&src,nullptr);
    glCompileShader(vs);

    int result;
    glGetShaderiv(vs,GL_COMPILE_STATUS,&result);

    if(result == GL_FALSE){
        int length;
        glGetShaderiv(vs,GL_INFO_LOG_LENGTH,&length);
        char* message= (char*) alloca(sizeof(char) * length);
        glGetShaderInfoLog(vs,length,&length,message);
        std::cout<<"Failed to compile "<<(type==GL_VERTEX_SHADER?"vertex":" fragment")<<" shader "<<message<<std::endl;

        glDeleteShader(vs);
    }


}

void ShaderProgram::initProgram() {
    programId = glCreateProgram();
}

void ShaderProgram::createShaders() {
    unsigned int vS = compileShader(vertexShader,GL_VERTEX_SHADER);
    unsigned int fS = compileShader(fragmentShader,GL_FRAGMENT_SHADER);


    glAttachShader(programId,vS);
    glAttachShader(programId,fS);
    glLinkProgram(programId);
    glValidateProgram(programId);

    glDeleteShader(vS);
    glDeleteShader(fS);
}


//Functions ---- GETTERS AND CHECKERS ----------------------------

/**
 * Check if shader program got fragment on
 * @return
 */
bool ShaderProgram::isFragmentShader() {
    return fragmentShader != nullptr;
}

/**
 * check if shader program got vertex on.
 * Kinda irrelavant function, because vertex shader is necessary
 * @return
 */
bool ShaderProgram::isVertexShader() {
    return vertexShader != nullptr;
}




