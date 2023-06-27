//
// Created by leno on 16.06.23..
//
#include "../coreTestHeader.h"
#include "core/engine/objects/model/modelGroup.h"
#include "core/engine/render/renderEngine/renderController.h"

/**
 * Checks if initialization os shader program is working
 */


/**
 *
 * @param megaArray
 * @param size
 */
void megaArrayPerformanceTest(Vec3* megaArray,int size){
    std::cout<<"Mega array test"<<std::endl;
    Timer timer;
    for(int i = 0; i < size; i+=2){
        (megaArray+i)->x++;
        (megaArray+i+1)->x++;
    }
}
/**
 *
 * @param positions
 * @param rotations
 * @param size
 */
void rowsArrayPerformanceTest(Vec3* positions,Vec3* rotations,int size){
    std::cout<<"Row perfromance test"<<std::endl;
    Timer timer;
    for(int i = 0; i < size; i++){
        (positions+i)->x++;
        (rotations+i)->x++;
    }
}


TEST(VaoPerformanceTest, VaoPerformanceRenderTest){
    TEST_DESCRIPTION("Check if vao is properly initialized","VaoPerformanceRenderTest")

    const long numberOfEntites = 99999;
    const long numberOfComponents = 2;

    Vec3 megaArray[ numberOfEntites * numberOfComponents ];

    for(int i = 0; i < numberOfEntites; i+=2){
        megaArray[i] = Vec3{.x=1,.y=2,.z=3};
        megaArray[i+1] = Vec3{.x=12,.y=23,.z=34};
    }

    ASSERT_EQ(megaArray[999].x,12);
    ASSERT_EQ(megaArray[998].x,1);


    megaArrayPerformanceTest(megaArray,numberOfEntites);

    ASSERT_EQ(megaArray[999].x,13);
    ASSERT_EQ(megaArray[998].x,2);


    Vec3 allPositions[numberOfEntites];
    Vec3 allRotation[numberOfEntites];

    for(int i = 0; i < numberOfEntites; i++){
        allPositions[i] = Vec3{.x=1,.y=2,.z=3};
        allRotation[i] = Vec3{.x=12,.y=23,.z=34};
    }
    ASSERT_EQ(allPositions[0].x,1);
    ASSERT_EQ(allRotation[0].x,12);

    rowsArrayPerformanceTest(allPositions,allRotation,numberOfEntites);

}




/**
 *
 * @param func
 */
void loopWithFunction(std::function<void(int* array)> func){
    int array[5] = {
            1,2,3,4,5
    };
    Timer A;
    func(array);
}
void loopWithoutFunction(){
    int array[5] = {
            1,2,3,4,5
    };
    Timer B;
    for(int i = 0; i < 5; ++i){
        int a= i;
    }
}
/**
 *
 */
void completeTest(){

    int b = 30;
    std::cout<<"Loop with function"<<std::endl;
    loopWithFunction([&b](int * array) {
        for(int i = 0; i < 5; ++i){
            ++b;
        }
    });

    std::cout<<"Loop without function"<<std::endl;
    loopWithoutFunction();
}

/**
 *
 */
TEST(VaoPerformanceTest, EntityGroupRenderingFunctionCallback){
    TEST_DESCRIPTION("Check if vao is properly initialized","VaoPerformanceRenderTest")

    for(int i = 0; i < 100;++i){
        completeTest();
    }
}


/**
 * Checks if initialization os shader program is working. It should
 * throw an error
 */
TEST_F(ShaderBasicProgram, TestShaderPerformanceWithEntityGroup){
    TEST_DESCRIPTION("Test shader performance with entity group","TestShaderPerformanceWithEntityGroup");

    ModelGroup<2, 3 * 3,VAO_5> entityGroup;
    ModelGroup<2, 3 * 3,VAO_5> entityGroup1;
    ShaderProgram * shP = shaderProgram;


    initOpenGlWindowEmptyWindow();
    YAML::Node config = YAML::LoadFile(ENGINE_PROPERTIES_YAML);
    std::string root = std::string(config["resourceRootDir"].as<std::string>());
    vertex = std::string(root).append("shaders/basic/basicShader.vert");
    fragment = std::string(root).append("shaders/basic/basicShader.frag");

    ShaderProgram shaderProgram1(vertex.c_str(),fragment.c_str());
    ShaderProgram * shP1 = &shaderProgram1;



    entityGroup.setEntityDrawFuncType([shP](ENTITIES_GROUP_DATA data,const ENTITIES_GROUP_ACTIVE& activeEntities,const UniformsHolder* holder){
        std::cout<<"With activate program"<<std::endl;
        Timer t;
        shP->activateProgram();
        for(int i = 0; i < 100; ++i){
            int a = 2;
        }
    });

    entityGroup1.setEntityDrawFuncType([shP](ENTITIES_GROUP_DATA data,const ENTITIES_GROUP_ACTIVE& activeEntities,const UniformsHolder* holder){
        std::cout<<"Without activate program"<<std::endl;
        Timer t;
        for(int i = 0; i < 100; ++i){
            int a = 2;
        }
    });


    for(int i = 0; i < 10; i++){
        entityGroup.draw();
        entityGroup1.draw();
    }
}

TEST_F(ShaderBasicProgram, TestShaderPerformanceWithSwitchingShaderEntityGroup){
    TEST_DESCRIPTION("Test shader with switching performance with entity group","TestShaderPerformanceWithSwitchingShaderEntityGroup");

    ModelGroup<2, 3 * 3,VAO_5> entityGroup;
    ModelGroup<2, 3 * 3,VAO_5> entityGroup1;



    YAML::Node config = YAML::LoadFile(ENGINE_PROPERTIES_YAML);
    std::string root = std::string(config["resourceRootDir"].as<std::string>());
    std::string vertex = std::string(root).append("shaders/basic/basicShader.vert");
    std::string fragment = std::string(root).append("shaders/basic/basicShader.frag");

    ShaderProgram shaderProgram1(vertex.c_str(),fragment.c_str());
    ShaderProgram * shP1 = &shaderProgram1;
    shP1->initProgram();
    shP1->createShaders();

    ShaderProgram shaderProgram2(vertex.c_str(),fragment.c_str());
    ShaderProgram * shP2 = &shaderProgram2;
    shP2->initProgram();
    shP2->createShaders();


    entityGroup.setEntityDrawFuncType([shP1](ENTITIES_GROUP_DATA data,const ENTITIES_GROUP_ACTIVE& activeEntities,const UniformsHolder* holder){
        std::cout<<"With shp1 program"<<std::endl;
        Timer t;
        shP1->activateProgram();

    });

    entityGroup1.setEntityDrawFuncType([shP2](ENTITIES_GROUP_DATA data,const ENTITIES_GROUP_ACTIVE& activeEntities,const UniformsHolder* holder){
        std::cout<<"With shp2 program"<<std::endl;
        Timer t;
        shP2->activateProgram();

    });


    shP1->activateProgram();
    for(int i = 0; i < 10; i++){
        Timer t;
        int a =2;
    }
}


TEST_F(ShaderBasicProgram, RenderHolderDataPerformance){
    TEST_DESCRIPTION("MainGLRenderObject performance, loop testing, to see how much slower it is that primitive loop","RenderHolderDataPerformance");

    MainGLRenderObject renderDataHolder{.shaderProgram=shaderProgram};



    ModelGroup<1,1,VAO_5> model;
    ModelGroup<1,1,VAO_5> model1;

    model.setEntityDrawFuncType([](ENTITIES_GROUP_DATA data,ENTITIES_GROUP_ACTIVE& active,const UniformsHolder* holder){
        for(int i = 0; i < 10; ++i){
            int a = i+1;
        }
    });

    model1.setEntityDrawFuncType([](ENTITIES_GROUP_DATA data,ENTITIES_GROUP_ACTIVE& active,const UniformsHolder* holder){
        for(int i = 0; i < 10; ++i){
            int a = i+1;
        }
    });

    model.setActivateVaoFuncType([](VAO_5* vao5){
        for(int i = 0; i < 10; ++i){
            int a = i+1;
        }
    });

    model1.setActivateVaoFuncType([](VAO_5* vao5){
        for(int i = 0; i < 10; ++i){
            int a = i+1;
        }
    });


    addNewModelGroupToRenderObject(&renderDataHolder,&model);
    addNewModelGroupToRenderObject(&renderDataHolder,&model1);

    {
        Timer p;
        for(int i = 0; i < 10; ++i){
            int a = i+1;
        }
        for(int i = 0; i < 10; ++i){
            int a = i+1;
        }
        for(int i = 0; i < 10; ++i){
            int a = i+1;
        }
        for(int i = 0; i < 10; ++i){
            int a = i+1;
        }
    }
    {
        Timer c;
        renderDataHolder.shaderProgram->activateProgram();
        renderModelsArray(renderDataHolder.models);
    }
}


/**
 * Adding Entity
 * @param entityId
 * @return
 */
void addEntity(std::vector<int>& entityId,int id,std::function<void()> * functionStore){
    entityId.push_back(id);

    int index = entityId.size()  - 1;

    if(functionStore != nullptr){
        *functionStore =  [index,&entityId](){
            entityId.erase(entityId.begin() + index);
        };
    }
}

/**
 * Adding Entity
 * @param entityId
 * @return
 */
void removeEntityById(std::vector<int>& entityId,int id){
    auto it = std::find(entityId.begin(),entityId.end(),id);
    entityId.erase(it);
}



TEST(CallbackFunctionForRemovingEntity, CallbackFunctionForRemovingEntity){
    TEST_DESCRIPTION("Remove entity from array with callback function, check performance","CallbackFunctionForRemovingEntity");

    std::vector<int> entites;

    std::function<void()> eraseFunction;

    addEntity(entites,2,&eraseFunction);

    int size1 = 100000;
    for(int i = 0; i < size1;i++){
        addEntity(entites,i+9, nullptr);
    }


    ASSERT_EQ(entites.size(),size1+1);
    ASSERT_EQ(entites.at(0),2);

    {
        Timer t;
        eraseFunction();
    }
    ASSERT_EQ(entites.size(),size1);

    addEntity(entites,3,nullptr);

    {
        Timer t;
        removeEntityById(entites,3);
    }
    ASSERT_EQ(entites.size(),size1);
}





/**
 * LAST time measured 24.06 -> 1.627 seconds for 35000 size
 *
 *
 *
 * Limit would be around size = 20000 ,  around 120 000 objects
 *
 */
TEST_F(ShaderBasicProgram, RenderingPerformance) {
    TEST_DESCRIPTION("Check rendering performance game loop", "check rendering performance game loop");
    using namespace vaoVboDefinitions;
    const int size = 20000;
    ModelGroup<size, 3 * 3, VAO_5> modelWoods;
    ModelGroup<size, 3 * 3, VAO_5> modelRocks;

    ModelGroup<size, 3 * 3, VAO_5> modelNpc;
    ModelGroup<size, 3 * 3, VAO_5> modelFlowers;
    ModelGroup<size, 3 * 3, VAO_5> modelGrass;
    ModelGroup<size, 3 * 3, VAO_5> modelDragons;

    MainGLRenderObject sameShader;

    sameShader.shaderProgram = shaderProgram;


    modelWoods.setActivateVaoFuncType([](VAO_5 *vao) {
        for (int i = 0; i < 100; ++i) {
            int a = 2;
        }
    });

    modelRocks.setActivateVaoFuncType([](VAO_5 *vao) {
        for (int i = 0; i < 100; ++i) {
            int a = 2;
        }
    });

    modelNpc.setActivateVaoFuncType([](VAO_5 *vao) {
        for (int i = 0; i < 100; ++i) {
            int a = 2;
        }
    });

    modelFlowers.setActivateVaoFuncType([](VAO_5 *vao) {
        for (int i = 0; i < 100; ++i) {
            int a = 2;
        }
    });

    modelGrass.setActivateVaoFuncType([](VAO_5 *vao) {
        for (int i = 0; i < 100; ++i) {
            int a = 2;
        }
    });
    modelDragons.setActivateVaoFuncType([](VAO_5 *vao) {
        for (int i = 0; i < 100; ++i) {
            int a = 2;
        }
    });



    modelWoods.setEntityDrawFuncType([](ENTITIES_GROUP_DATA data, ENTITIES_GROUP_ACTIVE active, const UniformsHolder *uniformsHolder) {
                for (int i = 0; i < active.size(); i++) {
                    for (int j = 0; j < 300; ++j) {
                        int a = 2;
                    }
                }
            });
    modelRocks.setEntityDrawFuncType([](ENTITIES_GROUP_DATA data, ENTITIES_GROUP_ACTIVE active, const UniformsHolder *uniformsHolder) {
                for (int i = 0; i < active.size(); i++) {

                    for (int j = 0; j < 300; ++j) {
                        int a = 2;
                    }
                }
            });
    modelFlowers.setEntityDrawFuncType([](ENTITIES_GROUP_DATA data, ENTITIES_GROUP_ACTIVE active, const UniformsHolder *uniformsHolder) {
        for (int i = 0; i < active.size(); i++) {

            for (int j = 0; j < 260; ++j) {
                int a = 2;
            }
        }
    });
    modelNpc.setEntityDrawFuncType([](ENTITIES_GROUP_DATA data, ENTITIES_GROUP_ACTIVE active, const UniformsHolder *uniformsHolder) {
        for (int i = 0; i < active.size(); i++) {

            for (int j = 0; j < 260; ++j) {
                int a = 2;
            }
        }
    });

    modelGrass.setEntityDrawFuncType([](ENTITIES_GROUP_DATA data, ENTITIES_GROUP_ACTIVE active, const UniformsHolder *uniformsHolder) {
        for (int i = 0; i < active.size(); i++) {

            for (int j = 0; j < 260; ++j) {
                int a = 2;
            }
        }
    });

    modelDragons.setEntityDrawFuncType([](ENTITIES_GROUP_DATA data, ENTITIES_GROUP_ACTIVE active, const UniformsHolder *uniformsHolder) {
        for (int i = 0; i < active.size(); i++) {
            for (int j = 0; j < 260; ++j) {
                int a = 2;
            }
        }
    });


    for(int i = 0;i < size;i++){
        addNewEntity(modelRocks.getVaoGroup());
        addNewEntity(modelWoods.getVaoGroup());
        addNewEntity(modelFlowers.getVaoGroup());
        addNewEntity(modelNpc.getVaoGroup());
        addNewEntity(modelGrass.getVaoGroup());
        addNewEntity(modelDragons.getVaoGroup());
    }
    ASSERT_EQ(modelRocks.getVaoGroup()->availableSlots.size(),0);
    ASSERT_EQ(modelWoods.getVaoGroup()->availableSlots.size(),0);

    ASSERT_EQ(modelWoods.getVaoGroup()->active.at(777),777);
    ASSERT_EQ(modelRocks.getVaoGroup()->active.at(233),233);


    sameShader.models.push_back(&modelWoods);
    sameShader.models.push_back(&modelRocks);
    sameShader.models.push_back(&modelNpc);
    sameShader.models.push_back(&modelFlowers);
    sameShader.models.push_back(&modelGrass);
    sameShader.models.push_back(&modelDragons);


    Timer timer60Fps;
    for(int i = 0; i < 60;++i){

        if(i % 10){
            deactivateEntity(modelWoods.getVaoGroup(),i);
            deactivateEntity(modelGrass.getVaoGroup(),i);
            ASSERT_EQ(modelWoods.getVaoGroup()->inactive.at(modelWoods.getVaoGroup()->inactive.size() -1),i);
            ASSERT_EQ(modelGrass.getVaoGroup()->inactive.at(modelGrass.getVaoGroup()->inactive.size() -1),i);
            activateEntity(modelWoods.getVaoGroup(),i);
            activateEntity(modelGrass.getVaoGroup(),i);
        }

        for(AbstractModelGroup* abstractModelGroup:sameShader.models){
            abstractModelGroup->activateVao();
            abstractModelGroup->draw();
        }
    }
}






/**
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}