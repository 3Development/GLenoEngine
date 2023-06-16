//
// Created by leno on 16.06.23..
//
#include "../../coreTestHeader.h"
#include "core/engine/objects/entityGroup.h"



TEST(EntityGroupTest, EntityGroupInitTest){
    TEST_DESCRIPTION("Check if entityGroup is properly initialized","EntityGroupInitTest")


    EntityGroup<2,9> group;

    group.setActivateVaoFuncType([](VAO_5* vao5){
       std::cout<<"Hello my old dear friend"<<std::endl;
    });

    group.activateVao();
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