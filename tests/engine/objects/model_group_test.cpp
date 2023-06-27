//
// Created by leno on 16.06.23..
//
#include "../../coreTestHeader.h"
#include "core/engine/objects/model/modelGroup.h"
#include "core/engine/enums/modelEnums.h"



TEST(EntityGroupTest, EntityGroupInitTest){
    TEST_DESCRIPTION("Check if entityGroup is properly initialized","EntityGroupInitTest")

    int valueToChange = 2;

    ModelGroup<2,9,VAO_5> group;

    group.setActivateVaoFuncType([&valueToChange](VAO_5* vao5){
        valueToChange = 23;
    });

    group.activateVao();

    ASSERT_EQ(valueToChange,23);
}


TEST(EntityGroupTest, EntityAbstractArrayTest){
    TEST_DESCRIPTION("Check if entityGroup is with abstract struct properly added to array","EntityAbstractArrayTest")

    int group1Value = 2;
    int group2Value = 2;

    ModelGroup<2,9,VAO_5> group;
    ModelGroup<3,9,VAO_5> group2;



    group.setActivateVaoFuncType([&group1Value](VAO_5* vao5){
        group1Value = 23;
    });

    group2.setActivateVaoFuncType([&group2Value](VAO_5* vao5){
        group2Value = 100;
    });

    std::vector<AbstractModelGroup*> abstractEntityGroup;

    abstractEntityGroup.push_back((AbstractModelGroup*)&group);
    abstractEntityGroup.push_back((AbstractModelGroup*)&group2);


    for(AbstractModelGroup* abstractEntity:abstractEntityGroup){
        abstractEntity->activateVao();
    }

    ASSERT_EQ(group1Value,23);
    ASSERT_EQ(group2Value,100);
}


/**
 * Simple bitwise check. Basic flag system
 */
TEST(TestEnumFlags, TestEnumFlagsBitwiseOperator){
    TEST_DESCRIPTION("Test enum flag bitwise operator if it properly set","TestEnumFlagsBitwiseOperator")
    using namespace ModelGroupEnums;

    ASSERT_EQ(TransformationFlags::POSITION,1);
    ASSERT_EQ(TransformationFlags::SCALE,2);
    ASSERT_EQ(TransformationFlags::ROTATION,4);

    const unsigned char flagOption = TransformationFlags::POSITION | TransformationFlags::SCALE;

    ASSERT_EQ(TransformationFlags::POSITION & flagOption,TransformationFlags::POSITION);
    ASSERT_EQ(TransformationFlags::SCALE & flagOption,TransformationFlags::SCALE);
    ASSERT_NE(TransformationFlags::ROTATION & flagOption,TransformationFlags::ROTATION);
    ASSERT_EQ(TransformationFlags::ROTATION & flagOption,0);


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