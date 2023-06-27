//
// Created by leno on 22.06.23..
//
#include "core/engine/render/renderEngine/renderController.h"


/**
 *  @HINT -> Main function for rendering
 *  This is the place where shader will get activated and all of the ModelGroup will be rendered (Models that uses this shader code)
 * @param renderDataHolder
 */
void renderModelsArray(std::vector<AbstractModelGroup*>& array){
    for(AbstractModelGroup* abstractModelGroup : array){
        abstractModelGroup->activateVao();
        abstractModelGroup->draw();
    }
}