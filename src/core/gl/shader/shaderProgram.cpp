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
    std::cout<<"ShaderProgramDeconstructor"<<std::endl;
}




unsigned int ShaderProgram::compileShader(const char *pathToShader,unsigned int type) {
    //COMPILING SHADER CODE

    //creating a shader object with specific id, passing type like (Fragment,Vertex). So vs is just id of shader -> https://docs.gl/gl4/glCreateShader
    unsigned int vs = glCreateShader(type);

    //first creates a buffer that length is equal to file size (shader) and then calls function that will fill it
    char src[getSizeOfFile(pathToShader)];
    readFile(pathToShader,src); // source code in string

    const char* src1 = (const char* )src;
    //replaces the source code in a shader object. Id of shader object. length can be nullptr if string has \0 as last char -> https://docs.gl/gl4/glShaderSource
    glShaderSource(vs,1,&src1,nullptr);
    // compiles a shader object,source code. -> https://docs.gl/gl4/glCompileShader
    glCompileShader(vs);

    //COMPILING STATUS CHECK
    int result;
    glGetShaderiv(vs,GL_COMPILE_STATUS,&result);

    if(result == GL_FALSE){
        int length;
        //if status is false, we are checking for the length of the message;
        glGetShaderiv(vs,GL_INFO_LOG_LENGTH,&length);

        char* message= (char*) alloca(sizeof(char) * length);
        glGetShaderInfoLog(vs,length,&length,message);
        std::cout<<"Failed to compile "<<(type==GL_VERTEX_SHADER?"vertex":" fragment")<<" shader "<<message<<std::endl;

        //NOTE - calling this function will remove source coude from GPU memory and will lose a ability to debug shaders
        glDeleteShader(vs);
    }
    return vs;
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

/**
 * Tells opengl to use this program
 */
void ShaderProgram::activateProgram() {
    glUseProgram(programId);
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








