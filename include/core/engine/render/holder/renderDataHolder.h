//
// Created by leno on 21.06.23..
//

#ifndef LENOENGINE_RENDERDATAHOLDER_H
#define LENOENGINE_RENDERDATAHOLDER_H
#include "../../../engine/objects/model/modelGroup.h"
#include "../../../../core/gl/shader/shaderProgram.h"
/**
 * Contains only data necessary for rendering.
 *
 *
 * Render Data holder purpose is to match a specifc shader and models that are using that shaderProgram
 *
 * @HINT -> That is all that this struct should be for. Only to hold data for rendering
 *
 *
 */
struct MainGLRenderObject{
    ShaderProgram* shaderProgram;
    std::vector<AbstractModelGroup*> models;
};


/**
 * Adding new model to render object.
 *  This function will also setup everything that is need to work
 *          Adding uniform holder to model group
 *
 * @tparam N  -> number of entities
 * @tparam S  -> number of slots per entity
 * @tparam VAO_5
 * @param renderDataHolder
 * @param modelGroup
 */
template<int N,int S,typename VAO_5>
void addNewModelGroupToRenderObject(MainGLRenderObject* renderDataHolder, ModelGroup<N,S,VAO_5>* modelGroup){
    renderDataHolder->models.push_back((AbstractModelGroup*)modelGroup);
    modelGroup->setUniformsHolder(renderDataHolder->shaderProgram->getUniformsHolder());
}
















/**
 * 
 */


#endif //LENOENGINE_RENDERDATAHOLDER_H


