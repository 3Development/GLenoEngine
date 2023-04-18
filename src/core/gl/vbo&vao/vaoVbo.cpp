//
// Created by leno on 4/18/23.
//
#include "core/gl/vbo&vao/vaoVbo.h"

// VBO initalization functions

void initializeStaticDrawVbo(void* vboBuffer,const void* data,int attributeType){
    unsigned int id;
    glGenBuffers(1,&id);
    VBO vbo{.id=id,.attributeType=attributeType};

}

