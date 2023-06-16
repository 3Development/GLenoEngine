//
// Created by leno on 04.05.23..
//
#include "../coreTestHeader.h"





/**
 * Checks if initialization os shader program is working
 */
TEST_F(ShaderBasicProgram, TestShaderInitialization){
    TEST_DESCRIPTION("Check if shader is initialized properly","TestShaderInitialization")
    EXPECT_NE(this->shaderProgram->getProgramId(),0);
}

/**
 * Checks if initialization os shader program is working
 */
TEST_F(ShaderBasicProgram, CheckUniformHolderEnumMapping){
    TEST_DESCRIPTION("Check if uniform holder mapping works","CheckUniformHolderEnumMapping")

    UniformEnums::UniformType worldMatrix = UniformEnums::UniformType::WORLD_MATRIX;


}


/**
 * Checks if initialization os shader program is working
 */
TEST_F(ShaderBasicProgram, TestShaderUniformLocations){
    TEST_DESCRIPTION("Check if uniform locations are found","TestShaderUniformLocations");

    bool status = this->shaderProgram->initUniformLocation(UniformEnums::UniformType::PROJECTION_MATRIX);

    EXPECT_EQ(status,true);
}


/**
 * Checks if initialization os shader program is working. It should
 * throw an error
 */
TEST_F(ShaderBasicProgram, TestShaderUniformCheckIfThrowMessageOccurs){
    TEST_DESCRIPTION("Check if finding uniform will throw proper error when name of location is wrong","TestShaderUniformCheckIfThrowMessageOccurs");

    bool status;
    try{
        status = this->shaderProgram->initUniformLocation(UniformEnums::UniformType::DEBUG_MATRIX);
    }catch(ShaderProgramEnums::ErrorCodes e){
        status = false;
    }
    EXPECT_FALSE(status);
}


/**
 * Checks if initialization os shader program is working. It should
 * throw an error
 */
TEST_F(ShaderBasicProgram, TestMatrixHolderForUniforms){
    TEST_DESCRIPTION("Basic testing of  holder uniforms","TestMatrixHolderForUniforms");

    const UniformsHolder* uniformsHolder = shaderProgram->getUniformsHolder();
    Timer();
    ASSERT_EQ(-1, uniformsHolder->projectionMatrixLocation);
    shaderProgram->initUniformLocation(UniformEnums::UniformType::PROJECTION_MATRIX);

    ASSERT_NE(-1,uniformsHolder->projectionMatrixLocation);
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