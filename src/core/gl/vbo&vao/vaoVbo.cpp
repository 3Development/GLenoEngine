//
// Created by leno on 4/18/23.
//
#include <iostream>
#include "core/gl/vbo&vao/vaoVbo.h"

//Private functions
/**
 * It will return pointer to the first available slot in array where a new vbo can be saved
 * @param vao
 * @return
 */
int findFirstAvailableVboInVao5(VAO_5* vao){
    for(int i =0; i < 5;++i){
        if(vao->vbos[i].id == 0){
            return i;
        }
    }
    return -1;
}



// VBO initalization functions


/**
 *
 * It generates an ID for buffer and if copy value is set to true, will then copy the data into the
 * GPU ram.
 * This only initialize one buffer.
 * Also it copies the data
 *
 * It also unbinds the buffer with that id
 *
 * There is also VAO, vertex array. This vbo will be saved into this vao/
 *
 * @param vao
 * @param data
 * @param sizeofDataInBytes
 * @param targetBuffer
 * @param typeOfData
 * @param attributeType
 * @param indexAttribPointer
 * @param numOfVerticesComponents
 * @param stride
 *
 * @throws VboVaoEnums::ErrorCodes
 */
void initializeVboObjectAndBufferData(VAO_5* vao,
                                      const void* data,
                                      int sizeofDataInBytes ,
                                      GLenum targetBuffer,
                                      GLenum typeOfData,
                                      VboVaoEnums::VboAttributeType attributeType,
                                      int indexAttribPointer,
                                      int numOfVerticesComponents,
                                      float stride){

    int index = findFirstAvailableVboInVao5(vao); // If vao does not have any free slot in VBO array it will throw exception and no data will be buffered into GPU
    if(index == -1){
        throw VboVaoEnums::ErrorCodes::VA0_NO_FREE_SLOT_IN_VBO_ARRAY;
    }

    unsigned int id;
    glGenBuffers(1,&id);
    glBindBuffer(targetBuffer,id);
    glBufferData(targetBuffer,sizeofDataInBytes,data,GL_STATIC_DRAW);


    vao->vbos[index] = VBO{.id=id,.attributeType=attributeType};

    if(targetBuffer == GL_ARRAY_BUFFER){
        glEnableVertexAttribArray(indexAttribPointer);
        glVertexAttribPointer(indexAttribPointer,numOfVerticesComponents,typeOfData,GL_FALSE,stride,(const void*)0);
        glBindBuffer(targetBuffer,UNBOUND_BUFFER);
    }
}


/**
 * Initialize empty vao - array
 * Plus Vao gets also activated
 * @param dest
 * @param sizeOfVbos -> this params tells us how many of vbo's will there be (how many attributes like position,color,normal)
 */
void initializeVao5Object(void* dest,bool active){
    unsigned int id;
    glGenVertexArrays(1,&id);
    VAO_5 vao {.id=id};
    memcpy(dest,&vao,sizeof(VAO_5));

    if(active){
        glBindVertexArray(vao.id);
    }
}


/**
 * Activates vao with id in struct. Meaning when drawing opengl will use that vao
 * @param vao
 */
void activateVao(VAO_5* vao){
    glBindVertexArray(vao->id);
}


/**
 * Deactivates all vao's it sets binding to 0
 * @param vao
 */
void deactivateVao(){
    glBindVertexArray(UNBOUND_BUFFER);
}




