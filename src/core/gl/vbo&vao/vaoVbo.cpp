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
 *
 * @DEPRECATED FUNCTION
 */
int initializeVboObjectAndBufferData(VAO_5* vao,
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


    vao->vbos[index] = VBO{.id=id};

    if(targetBuffer == GL_ARRAY_BUFFER){
        glEnableVertexAttribArray(indexAttribPointer);
        glVertexAttribPointer(indexAttribPointer,numOfVerticesComponents,typeOfData,GL_FALSE,stride,(const void*)0);
        glBindBuffer(targetBuffer,UNBOUND_BUFFER);
    }
    return index;
}

/**
 * It generates and buffers the data
 * It also unbinds the buffer with that id
 *
 * Difference between this and method initializeVboObjectAndBufferData is that it will not autmatically search for available
 * index in VAO5 struct array. Instead indexAttribPointer will be used as index.
 *
 * If type is GL_ELEMENT_ARRAY_BUFFER, it means it is about INDICES, they will be stored in specif field in VAO_5 and not in array
 *
 * @param vao
 * @param data
 * @param sizeofDataInBytes
 * @param targetBuffer
 * @param typeOfData
 * @param indexAttribPointer
 * @param numOfVerticesComponents
 * @param stride
 */
void initializeVboObjectAndSaveItAtIndexAttrPointer(VAO_5* vao,
                                                   const void* data,
                                                   int sizeofDataInBytes ,
                                                   GLenum targetBuffer,
                                                   GLenum typeOfData,
                                                   int indexAttribPointer,
                                                   int numOfVerticesComponents,
                                                   float stride
){

    if( targetBuffer == GL_ELEMENT_ARRAY_BUFFER){
        unsigned int id;
        glGenBuffers(1,&id);
        glBindBuffer(targetBuffer,id);
        glBufferData(targetBuffer,sizeofDataInBytes,data,GL_STATIC_DRAW);
        vao->indicesId = id;

    }
    else if( targetBuffer == GL_ARRAY_BUFFER){

        VBO vbo = vao->vbos[indexAttribPointer];

        if(vbo.id == -1){
            throw VboVaoEnums::ErrorCodes::VAO_SLOT_ALREADY_TAKEN;
        }

        unsigned int id;
        glGenBuffers(1,&id);
        glBindBuffer(targetBuffer,id);
        glBufferData(targetBuffer,sizeofDataInBytes,data,GL_STATIC_DRAW);

        vao->vbos[indexAttribPointer] = VBO{.id=id};
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
 * Initialize empty vao - array
 * Plus Vao gets also activated
 * Without memcpy
 * @param dest
 * @param sizeOfVbos -> this params tells us how many of vbo's will there be (how many attributes like position,color,normal)
 */
void initializeVao5Object(VAO_5* vao5,bool active){
    unsigned int id;
    glGenVertexArrays(1,&id);

    vao5->id = id;

    if(active){
        glBindVertexArray(vao5->id);
    }
}

/**
 * Activating all the buffers and vao
 *
 * 1. Activate vao
 * 2. Activate indices
 * 3. Activate all the vbo using attrIndexPointer (only ones that are initialized, meaning those who dont have id 0)
 *
 * @param vao
 */
void prepareVaoForDrawing(VAO_5* vao){
    glBindVertexArray(vao->id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,vao->indicesId);

    for(int attribPointer = 0; attribPointer < 5; ++attribPointer){

        if(vao->vbos[attribPointer].id != 0){
            glEnableVertexAttribArray(attribPointer);
        }
    }
}

/**
 * Drawing element using indices.
 * Indices count is size of an array basically
 * @param indicesCount
 */
void drawVaoUsingIndices(unsigned int indicesCount){
    glDrawElements(GL_TRIANGLES,indicesCount,GL_UNSIGNED_INT, nullptr);
}

/**
 * Deactivate model
 */
 void deactivateAndUnbindAllFromVao(VAO_5* vao){

    for(int attribPointer = 0; attribPointer < 5; ++attribPointer){

        if(vao->vbos[attribPointer].id != 0){
            glDisableVertexAttribArray(UNBOUND_BUFFER);
        }
    }
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,UNBOUND_BUFFER);
    glBindVertexArray(UNBOUND_BUFFER);
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
    glBindVertexArray(0);
}


/**
 * VAO GROUP functions
 */







