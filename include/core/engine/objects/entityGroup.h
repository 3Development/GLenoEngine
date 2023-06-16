//
// Created by leno on 16.06.23..
//

#ifndef LENOENGINE_ENTITYGROUP_H
#define LENOENGINE_ENTITYGROUP_H
#include "core/gl/vbo&vao/vaoVbo.h"
#include <functional>
/**
 *         TYPEDEFS
 */



typedef std::function<void(ENTITIES_GROUP_DATA,ENTITIES_GROUP_ACTIVE)> EntityDrawFuncType;
/**
 * This one is a callback function to bind all the
 * necessary buffers
 */
typedef std::function<void(VAO_5* vao5)> ActivateVaoFuncType;


/**
 * Main class to hold data and just draw it
 * @tparam NumberOfEntities
 * @tparam SlotsPerEntity
 */
template<int NumberOfEntities,int SlotsPerEntity>
class EntityGroup{
private:
    VAO_5 vao5;
    VAOGroup<NumberOfEntities,SlotsPerEntity> vaoGroup;


    EntityDrawFuncType entityDrawFuncType;
    ActivateVaoFuncType activateVaoFuncType;

public:
    EntityGroup();
    ~EntityGroup();


    void setEntityDrawFuncType(const EntityDrawFuncType& entityDrawFuncType);
    void setActivateVaoFuncType(const ActivateVaoFuncType& activateVaoFuncType);

    /**
     * Return a vao struct
     * @return
     */
    VAO_5* getVao5();
    /**
     * Return VaoGroup
     * @return
     */
    VAOGroup<NumberOfEntities,SlotsPerEntity>* getVaoGroup();


    void activateVao();

    /**
     *  main function for drawing entitiesData. But it should call a function
     *  that is given, passed as parameter
     */
     void draw();
};


/**
 *CONSTRUCTOR
 */
template<int NumberOfEntities, int SlotsPerEntity>
EntityGroup<NumberOfEntities,SlotsPerEntity>::EntityGroup(){
    initializeVaoGroup(&vaoGroup);
}

/**
 * DECONSTRUCTOR
 * @tparam NumberOfEntities
 * @tparam SlotsPerEntity
 */
template<int NumberOfEntities, int SlotsPerEntity>
EntityGroup<NumberOfEntities, SlotsPerEntity>::~EntityGroup() {

}



/**
 *
 * @tparam NumberOfEntities
 * @tparam SlotsPerEntity
 * @param activateVaoFuncType
 */
template<int NumberOfEntities, int SlotsPerEntity>
void
EntityGroup<NumberOfEntities, SlotsPerEntity>::setActivateVaoFuncType(const ActivateVaoFuncType &activateVaoFuncType) {
    this->activateVaoFuncType = activateVaoFuncType;
}


/**
 *
 * @tparam NumberOfEntities
 * @tparam SlotsPerEntity
 * @param entityDrawFuncType
 */
template<int NumberOfEntities, int SlotsPerEntity>
void EntityGroup<NumberOfEntities, SlotsPerEntity>::setEntityDrawFuncType(const EntityDrawFuncType& entityDrawFuncType) {
    this->entityDrawFuncType = entityDrawFuncType;
}

/**
 *
 * @return
 */
template<int NumberOfEntities, int SlotsPerEntity>
VAO_5* EntityGroup<NumberOfEntities, SlotsPerEntity>::getVao5(){
    return &this->vao5;
}

/**
 *
 * @tparam NumberOfEntities
 * @tparam SlotsPerEntity
 * @return
 */
template<int NumberOfEntities, int SlotsPerEntity>
VAOGroup<NumberOfEntities, SlotsPerEntity>* EntityGroup<NumberOfEntities, SlotsPerEntity>::getVaoGroup() {
    return &this->vaoGroup;

}


/**
 * Drawing vao models based on positions and all the other necessary data in vaoGroup
 * @tparam NumberOfEntities
 * @tparam SlotsPerEntity
 */
template<int NumberOfEntities, int SlotsPerEntity>
void EntityGroup<NumberOfEntities, SlotsPerEntity>::draw() {
    this->entityDrawFuncType(vaoGroup.entitiesData,vaoGroup.active);
}


/**
 * Activate vao, binding all the necessary buffers in opengl
 * @tparam NumberOfEntities
 * @tparam SlotsPerEntity
 */
template<int NumberOfEntities, int SlotsPerEntity>
void EntityGroup<NumberOfEntities, SlotsPerEntity>::activateVao() {
    this->activateVaoFuncType(&vao5);
}



#endif //LENOENGINE_ENTITYGROUP_H
