//
// Created by leno on 21.06.23..
//
#include "../../coreTestHeader.h"
#include "core/engine/objects/model/modelGroup.h"
#include "core/engine/render//holder/renderDataHolder.h"
#include "core/engine/render//renderEngine//renderController.h"

TEST(RenderDataHolderTest, RenderDataHolderTestInitialization){
    TEST_DESCRIPTION("Check if render data  is properly initialized","RenderDataHolderTest")


    MainGLRenderObject renderDataHolder;

    ModelGroup<1,1,VAO_5> model;
    renderDataHolder.models.push_back((AbstractModelGroup*)&model);

    ASSERT_EQ(renderDataHolder.models.size(),1);

}
TEST_F(ShaderBasicProgram, TestingRenderFlow){
    TEST_DESCRIPTION("Check if render data  is properly initialized","RenderDataHolderTest")


    MainGLRenderObject renderDataHolder;
    renderDataHolder.shaderProgram = shaderProgram;

    int testValue = 10;

    ModelGroup<1,1,VAO_5> model;

    model.setEntityDrawFuncType([&testValue](ENTITIES_GROUP_DATA data,ENTITIES_GROUP_ACTIVE& active,const UniformsHolder* uniformsHolder){
        testValue++;
    });
    model.setActivateVaoFuncType([&testValue](VAO_5* vao5){
       testValue++;
    });

    addNewModelGroupToRenderObject(&renderDataHolder,&model);

    Timer t;
    renderModelsArray(renderDataHolder.models);

    ASSERT_EQ(testValue,12);
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