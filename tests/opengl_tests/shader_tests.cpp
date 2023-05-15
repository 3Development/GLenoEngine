//
// Created by leno on 04.05.23..
//
#include "../coreTestHeader.h"
#include "core/gl/shader/shaderProgram.h"


class ShaderTests: public ::testing::Test {
public:
    std::string vertex;
    std::string fragment;

    ShaderProgram* shaderProgram;


    ShaderTests(){
        initOpenGlWindowEmptyWindow();
        YAML::Node config = YAML::LoadFile(ENGINE_PROPERTIES_YAML);
        std::string root = std::string(config["resourceRootDir"].as<std::string>());
        vertex = std::string(root).append("shaders/basic/basicShader.vert");
        fragment = std::string(root).append("shaders/basic/basicShader.frag");

        shaderProgram = new ShaderProgram(vertex.c_str(),fragment.c_str());
    }

    ~ShaderTests(){
        delete shaderProgram;
    }

    void SetUp() override{
        shaderProgram->initProgram();
        shaderProgram->createShaders();
    }

};

/**
 * Checks if initialization os shader program is working
 */
TEST_F(ShaderTests, TestShaderInitialization){
    TEST_DESCRIPTION("Check if shader is initialized properly","TestShaderInitialization")
    EXPECT_NE(this->shaderProgram->getProgramId(),0);
}


/**
 * Checks if initialization os shader program is working
 */
TEST_F(ShaderTests, TestShaderUniformLocations){
    TEST_DESCRIPTION("Check if uniform locations are found","TestShaderUniformLocations");

    int id= -1;

    this->shaderProgram->initUniformLocation(this->shaderProgram->getUniformsHolder()->projectionMatrix,&id);

    EXPECT_NE(id, -1);
}


/**
 * Checks if initialization os shader program is working. It should
 * throw an error
 */
TEST_F(ShaderTests, TestShaderUniformCheckIfThrowMessageOccurs){
    TEST_DESCRIPTION("Check if finding uniform will throw proper error when name of location is wrong","TestShaderUniformCheckIfThrowMessageOccurs");

    int id= 0;

    try{
        this->shaderProgram->initUniformLocation("projectionMatrixsds",&id);

    }catch (ShaderProgramEnums::ErrorCodes e){
        if(e == ShaderProgramEnums::ErrorCodes::UNIFORM_LOCATION_INITIALIZATION_ERROR){
            id = -1;
        }
    }

    EXPECT_EQ(id, -1);
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