//
// Created by leno on 13.06.23..
//

//
// Created by leno on 04.05.23..
//
#include "../coreTestHeader.h"


/**
 * Checks if initialization os shader program is working
 */
TEST_F(ShaderBasicProgram, TestVBOInitializedToZero){
    TEST_DESCRIPTION("","TestVBOInitializedToZero")
    VBO vbo;

    EXPECT_TRUE(vbo.id == 0 );
}

/**
 * Checks if initialization os shader program is working
 */
TEST_F(ShaderBasicProgram, TestInitializationForVao){
    TEST_DESCRIPTION("Check if vao is properly initialized","Vao initialization")
    VAO_5 vao5;

    initializeVao5Object(&vao5);

    EXPECT_TRUE(vao5.id != -1 );
}

/**
 * Checks if initialization os shader program is working
 */
TEST_F(ShaderBasicProgram, TRIVIAL_TEST_Mesaure_performance_vao_rendering_multiple_objects) {
    TEST_DESCRIPTION("Timer on vao multiple rendering",
                     "TRIVIAL_TEST_Mesaure_performance_vao_rendering_multiple_objects")
    VAO_5 vao5;

    initializeVao5Object(&vao5);

    float positions[12] = {
            -0.5f, -0.5f, 0, //0
            0.5f, 0.5f, 0, // 1
            0.5f, -0.5f, 0, // 2
            -0.5f, 0.5f, 0 // 3
    };
    int indices[] = {
            0, 1, 2,
            0, 3, 1
    };


    float color[24] = {
            1, 0, 0.2, 1,
            0.3, 1, 0.2, 1,
            0, 0, 0, 1,

            1, 0, 0, 1,
            0.5, 1, 0.5, 1,
            0, 0, 0, 1,
    };
    try {
        initializeVboObjectAndBufferData(&vao5, positions, sizeof(float) * 12, GL_ARRAY_BUFFER, GL_FLOAT,
                                         VboVaoEnums::VboAttributeType::POSITION, 0, 3, sizeof(float) * 3);
        initializeVboObjectAndBufferData(&vao5, color, sizeof(float) * 24, GL_ARRAY_BUFFER, GL_FLOAT,
                                         VboVaoEnums::VboAttributeType::COLOR, 1, 4, sizeof(float) * 4);
        initializeVboObjectAndBufferData(&vao5, indices, sizeof(float) * 6, GL_ELEMENT_ARRAY_BUFFER, GL_FLOAT,
                                         VboVaoEnums::VboAttributeType::INDICES, -1, -1, -1);


        EXPECT_TRUE(vao5.id != -1);
    }catch (VboVaoEnums::ErrorCodes e){

    }
}

/**
 * Checks if vao function is working
 * Meaning intializing Vbo inside VAO and instead automatically search for index in VAO5 array it will
 * use attribPointer as index
 */
TEST_F(ShaderBasicProgram, TestInitializationOfVboInsideVAOUsingAttribPointerAsIndex){
    TEST_DESCRIPTION("Instead of automatically assign index to VAO5 struct array it will use a attribPointer","TestInitializationOfVboInsideVAOUsingAttribPointerAsIndex")
    VAO_5 vao5;

    initializeVao5Object(&vao5);

    float positions[12] = {
            -0.5f, -0.5f, 0, //0
            0.5f, 0.5f, 0, // 1
            0.5f, -0.5f, 0, // 2
            -0.5f, 0.5f, 0 // 3
    };
    int indices[] = {
            0, 1, 2,
            0, 3, 1
    };


    float color[24] = {
            1, 0, 0.2, 1,
            0.3, 1, 0.2, 1,
            0, 0, 0, 1,

            1, 0, 0, 1,
            0.5, 1, 0.5, 1,
            0, 0, 0, 1,
    };

    int attribPointer1 = 0;
    int attribPointer2 = 1;

    initializeVboObjectAndSaveItAtIndexAttrPointer(&vao5, positions, sizeof(float) * 12, GL_ARRAY_BUFFER, GL_FLOAT,
                                    attribPointer1, 3, sizeof(float) * 3);
    initializeVboObjectAndSaveItAtIndexAttrPointer(&vao5, color, sizeof(float) * 24, GL_ARRAY_BUFFER, GL_FLOAT,
                                     attribPointer2, 4, sizeof(float) * 4);
    initializeVboObjectAndSaveItAtIndexAttrPointer(&vao5, indices, sizeof(float) * 6, GL_ELEMENT_ARRAY_BUFFER, GL_FLOAT,
                                     -1, -1, -1);


    EXPECT_TRUE(vao5.vbos[attribPointer1].id != 0);
    EXPECT_TRUE(vao5.vbos[attribPointer2].id != 0);
    EXPECT_TRUE(vao5.vbos[3].id == 0);
}

/**
 * Check if object is displayed on window
 */
TEST_F(ShaderBasicProgram, CheckIfObjectIsDisplayed){
    TEST_DESCRIPTION("Check if object is displayed","CheckIfObjectIsDisplayed")
}



/**
 * MEGA ARRAY TESTS
 */

TEST(MegaArray,MegaArrayInitializationAlgorithmTest){
    TEST_DESCRIPTION("Check if mega array algorithm  is working correctly","MegaArrayInitializationAlgorithmTest")
    const int numberofEntites = 3;
    const int numberOfSlotsPerEntity = 3 * 3;

    VaoTransformDataGroup<numberofEntites,numberOfSlotsPerEntity> vaoGroup;

    ASSERT_EQ(sizeof(vaoGroup.entitiesData), numberofEntites * numberOfSlotsPerEntity * sizeof(float));

    int size = calculateSizeOfVaoGroup<numberofEntites,numberOfSlotsPerEntity>();

    ASSERT_EQ(sizeof(vaoGroup),  size   );


    /**
     * Second part of test
     */

    VaoTransformDataGroup<numberofEntites,numberOfSlotsPerEntity> vaoGroupHandle;
    initializeVaoGroup<numberofEntites,numberOfSlotsPerEntity>(&vaoGroupHandle);
    ASSERT_EQ(vaoGroupHandle.availableSlots.size(), numberofEntites);

    //Function
    int indexSlot = addNewEntity(&vaoGroupHandle);

    ASSERT_EQ(vaoGroupHandle.availableSlots.at(0),1);
    ASSERT_EQ(vaoGroupHandle.active[0],0);

    int indexSlot2 = addNewEntity(&vaoGroupHandle);


    ASSERT_EQ(vaoGroupHandle.availableSlots.at(0),2);
    ASSERT_EQ(vaoGroupHandle.active[1],1);

    Timer t;
    removeEntity(&vaoGroupHandle,indexSlot);
    ASSERT_EQ(vaoGroupHandle.active[0],1);

    int indexSlot3 = addNewEntity(&vaoGroupHandle);
    ASSERT_EQ(indexSlot3,2);
    ASSERT_EQ(vaoGroupHandle.availableSlots[0],0);

    indexSlot = addNewEntity(&vaoGroupHandle);
    ASSERT_EQ(indexSlot,0);
    ASSERT_EQ(vaoGroupHandle.availableSlots.size(),0);
    ASSERT_EQ(vaoGroupHandle.active.size(),3);

    removeEntity(&vaoGroupHandle,indexSlot3);
    ASSERT_EQ(vaoGroupHandle.active[0],1);
    ASSERT_EQ(vaoGroupHandle.active[1],0);
    ASSERT_EQ(vaoGroupHandle.active.size(),2);
    ASSERT_EQ(vaoGroupHandle.availableSlots[0],2);

    deactivateEntity(&vaoGroupHandle,1);
    ASSERT_EQ(vaoGroupHandle.active[0],0);
    ASSERT_EQ(vaoGroupHandle.inactive[0],1);
}

/**
 *
 */
TEST(MegaArray,MegaArrayErrorTest){
    TEST_DESCRIPTION("Check if mega array algorithm exceptions are working correctly","MegaArrayErrorTest")
    const int numberofEntites = 1;
    const int numberOfSlotsPerEntity = 3 * 3;

    VaoTransformDataGroup<numberofEntites,numberOfSlotsPerEntity> vaoGroup;

    ASSERT_EQ(sizeof(vaoGroup.entitiesData), numberofEntites * numberOfSlotsPerEntity * sizeof(float));

    int size = calculateSizeOfVaoGroup<numberofEntites,numberOfSlotsPerEntity>();

    ASSERT_EQ(sizeof(vaoGroup),  size   );

    initializeVaoGroup(&vaoGroup);

    addNewEntity(&vaoGroup);
    ASSERT_EQ(vaoGroup.availableSlots.size(),  0  );

    try{
        addNewEntity(&vaoGroup);
        ASSERT_FALSE(true);
    }catch (VboVaoEnums::ErrorCodes e){
        ASSERT_EQ(e,VboVaoEnums::ErrorCodes::VAOGROUP_NO_MORE_AVAILABLE_SLOTS);
    }

    try{
        removeEntity(&vaoGroup,2);
        ASSERT_FALSE(true);
    }catch (VboVaoEnums::ErrorCodes e){
        ASSERT_EQ(e,VboVaoEnums::ErrorCodes::VAOGROUP_ENTITY_AT_INDEX_NOT_EXISTS);
    }
}

TEST(MegaArray,MegaArrayDataFilling){
    TEST_DESCRIPTION("Check if mega array algorithm for addint data to big array is working properly","MegaArrayDataFilling")

    const int numberofEntites = 2;
    const int numberOfSlotsPerEntity = 2 * 3;

    VaoTransformDataGroup<numberofEntites,numberOfSlotsPerEntity> vaoGroup;

    ASSERT_EQ(sizeof(vaoGroup.entitiesData), numberofEntites * numberOfSlotsPerEntity * sizeof(float));

    int size = calculateSizeOfVaoGroup<numberofEntites,numberOfSlotsPerEntity>();

    ASSERT_EQ(sizeof(vaoGroup),  size   );

    initializeVaoGroup(&vaoGroup);

    int entity1 = addNewEntity(&vaoGroup);
    int entity2 = addNewEntity(&vaoGroup);

    float position[] = {
            1.0f,
            0.0f,
            2.0f
    };
    float rotation[] = {
            90.0f,
            0.0f,
            85.0f
    };
    addComponentDataToEntityArray<numberofEntites,numberOfSlotsPerEntity>(&vaoGroup,entity1,position,3,0);

    ASSERT_EQ(vaoGroup.entitiesData[( entity1*numberOfSlotsPerEntity )+ 0 ],1.0f);
    ASSERT_EQ(vaoGroup.entitiesData[( entity1*numberOfSlotsPerEntity )+ 1 ],0.0f);
    ASSERT_EQ(vaoGroup.entitiesData[( entity1*numberOfSlotsPerEntity )+ 2 ],2.0f);


    addComponentDataToEntityArray<numberofEntites,numberOfSlotsPerEntity>(&vaoGroup,entity2,rotation,3,3);

    ASSERT_EQ(vaoGroup.entitiesData[( entity2*numberOfSlotsPerEntity )+ 3 ],90.0f);
    ASSERT_EQ(vaoGroup.entitiesData[( entity2*numberOfSlotsPerEntity )+ 4 ],0.0f);
    ASSERT_EQ(vaoGroup.entitiesData[( entity2*numberOfSlotsPerEntity )+ 5 ],85.0f);
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
