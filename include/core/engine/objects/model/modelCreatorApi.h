//
// Created by leno on 25.06.23..
//

#ifndef LENOENGINE_MODELCREATORAPI_H
#define LENOENGINE_MODELCREATORAPI_H
#include "modelGroup.h"

/**
 * Basic initialization of model group.
 * Initialization with basic setup
 *
 * @tparam NumberOfEntities
 * @tparam SlotsPerEntity
 * @tparam VaoType
 * @param modelGroup
 */
template<int NumberOfEntities,int SlotsPerEntity,typename VaoType>
void basicInitializationOfModel(ModelGroup<NumberOfEntities,SlotsPerEntity,VAO_5>* modelGroup);

#endif //LENOENGINE_MODELCREATORAPI_H
