//
// Created by leno on 16.06.23..
//

#ifndef LENOENGINE_MODELGROUP_H
#define LENOENGINE_MODELGROUP_H
#include "core/gl/vbo&vao/vaoVbo.h"
#include "core/gl/shader/uniformHolder.h"
#include <functional>
#include <memory>
#include <vector>

using namespace vaoVboDefinitions;
/**
 *         TYPEDEFS
 */





/**
 * Purpose of this class is so that all entity groups can be in one array
 * for rendering
 */
struct AbstractModelGroup{
    virtual ~AbstractModelGroup(){};

    virtual void draw() = 0;
    virtual void activateVao() = 0;
    virtual void createEntity() = 0;
};



/**
 * Main class to hold data and just draw it
 *
 * ModelGroup is actually ONE model with many instances of that model.
 *
 * Basically this will hold all of the data of the same Model. Tree model with -> two instance of Tree each with own position
 *
 * @tparam NumberOfEntities
 * @tparam SlotsPerEntity
 */
template<int NumberOfEntities,int SlotsPerEntity,typename VaoType>
class ModelGroup : public AbstractModelGroup{
public:
    /**
     * This one is a callback function to bind all the
     * necessary buffers
     */
    typedef std::function<void(VaoType* vao5)> ActivateVaoFuncType;
    /**
     * Callback for drawing entity
     *
     */
    typedef std::function<void(ENTITIES_GROUP_DATA,ENTITIES_GROUP_ACTIVE,const UniformsHolder*)> EntityDrawFuncType;


private:
    VaoType vao5;
    VaoTransformDataGroup<NumberOfEntities,SlotsPerEntity> vaoGroup;
    const UniformsHolder* uniformsHolder;

    EntityDrawFuncType entityDrawFuncType;
    ActivateVaoFuncType activateVaoFuncType;

public:

    ModelGroup();
    ~ModelGroup() override;


    void setEntityDrawFuncType(const EntityDrawFuncType entityDrawFuncType);
    void setActivateVaoFuncType(const ActivateVaoFuncType activateVaoFuncType);
    void setUniformsHolder(const UniformsHolder* uniformsHolder);


    /**
     * It will generate an id for This vao5.
     * and if bool set to active, it will immediately activate so the data (VBO) can be binded
     * @param active
     * @return
     */
    bool initVao5(bool active);

    /**
     * Return a vao struct
     * @return
     */
    VAO_5* getVao5();
    /**
     * Return VaoGroup
     * @return
     */
    VaoTransformDataGroup<NumberOfEntities,SlotsPerEntity>* getVaoGroup();


    void activateVao() override;

    /**
     *  main function for drawing entitiesData. But it should call a function
     *  that is given, passed as parameter
     */
     void draw() override;


     /**
      * main function for creating an entity object
      */
      void createEntity() override;
};



/**
 *
 * @tparam NumberOfEntities
 * @tparam SlotsPerEntity
 * @tparam VaoType
 * @param uniformsHolder
 */
template<int NumberOfEntities, int SlotsPerEntity, typename VaoType>
void ModelGroup<NumberOfEntities, SlotsPerEntity, VaoType>::setUniformsHolder(const UniformsHolder* uh) {
    this->uniformsHolder = uh;
}


template<int NumberOfEntities, int SlotsPerEntity, typename VaoType>
bool ModelGroup<NumberOfEntities, SlotsPerEntity, VaoType>::initVao5(bool active) {
    initializeVao5Object(&this->vao5,active);
}


/**
 *CONSTRUCTOR
 */
template<int NumberOfEntities, int SlotsPerEntity,typename VaoType>
ModelGroup<NumberOfEntities,SlotsPerEntity,VaoType>::ModelGroup(){
    initializeVaoGroup(&vaoGroup);
}

/**
 * DECONSTRUCTOR
 * @tparam NumberOfEntities
 * @tparam SlotsPerEntity
 */
template<int NumberOfEntities, int SlotsPerEntity,typename VaoType>
ModelGroup<NumberOfEntities, SlotsPerEntity,VaoType>::~ModelGroup(){
}



/**
 *
 * @tparam NumberOfEntities
 * @tparam SlotsPerEntity
 * @param activateVaoFuncType
 */
template<int NumberOfEntities, int SlotsPerEntity,typename VaoType>
void
ModelGroup<NumberOfEntities, SlotsPerEntity,VaoType>::setActivateVaoFuncType(const ActivateVaoFuncType activateVaoFuncType) {
    this->activateVaoFuncType = activateVaoFuncType;
}


/**
 *
 * @tparam NumberOfEntities
 * @tparam SlotsPerEntity
 * @param entityDrawFuncType
 */
template<int NumberOfEntities, int SlotsPerEntity,typename VaoType>
void ModelGroup<NumberOfEntities, SlotsPerEntity,VaoType>::setEntityDrawFuncType(const EntityDrawFuncType entityDrawFuncType) {
    this->entityDrawFuncType = entityDrawFuncType;
}

/**
 *
 * @return
 */
template<int NumberOfEntities, int SlotsPerEntity,typename VaoType>
VAO_5* ModelGroup<NumberOfEntities, SlotsPerEntity,VaoType>::getVao5(){
    return &this->vao5;
}

/**
 *
 * @tparam NumberOfEntities
 * @tparam SlotsPerEntity
 * @return
 */
template<int NumberOfEntities, int SlotsPerEntity,typename VaoType>
VaoTransformDataGroup<NumberOfEntities, SlotsPerEntity>* ModelGroup<NumberOfEntities, SlotsPerEntity,VaoType>::getVaoGroup() {
    return &this->vaoGroup;

}

/**
 *
 * @tparam NumberOfEntities
 * @tparam SlotsPerEntity
 * @tparam VaoType
 */
template<int NumberOfEntities, int SlotsPerEntity, typename VaoType>
void ModelGroup<NumberOfEntities, SlotsPerEntity, VaoType>::createEntity() {
    int indexDataStart = addNewEntity(&vaoGroup);
}


/**
 * Drawing vao models based on positions and all the other necessary data in vaoGroup
 * @tparam NumberOfEntities
 * @tparam SlotsPerEntity
 */
template<int NumberOfEntities, int SlotsPerEntity, typename VaoType>
void ModelGroup<NumberOfEntities, SlotsPerEntity, VaoType>::draw() {
    this->entityDrawFuncType(vaoGroup.entitiesData,vaoGroup.active,uniformsHolder);
}

/**
 * Activate vao, binding all the necessary buffers in opengl
 * @tparam NumberOfEntities
 * @tparam SlotsPerEntity
 */
template<int NumberOfEntities, int SlotsPerEntity,typename VaoType>
void ModelGroup<NumberOfEntities, SlotsPerEntity,VaoType>::activateVao() {
    this->activateVaoFuncType(&vao5);
}



#endif //LENOENGINE_MODELGROUP_H
