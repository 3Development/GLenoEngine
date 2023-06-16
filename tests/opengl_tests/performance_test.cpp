//
// Created by leno on 16.06.23..
//
#include "../coreTestHeader.h"

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
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}