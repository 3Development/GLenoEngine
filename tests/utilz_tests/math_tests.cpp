//
// Created by leno on 25.04.23..
//
#include "utilz/math/algebra//objects/vector.h"
#include "../coreTestHeader.h"
#include "utilz/math/algebra//linear_functions/transformation_matrices.h"
#include "utilz/math/algebra/objects/matrix.h"
#include "utilz/math/algebra/objects/quaternion.h"

/**
 * VECTORS TESTS
 */

/**
 * Checks if initilization of struct is working
 */
 TEST(VectorTests, TestInitializationVectorStruct){
    TEST_DESCRIPTION("Checks if initialization of struct is working","TestInitializationVectorStruct")
     Vec3 vec3{.x=1,.y=2,.z=3};

     ASSERT_EQ(vec3.x,1);
     ASSERT_EQ(vec3.y,2);
     ASSERT_EQ(vec3.z,3);
 }


 /**
  * Checks if adding two vector with overridden function will work (operator +)
  */
TEST(VectorTests, CheckIsVec3OperatorAdditionIsWorking){
    TEST_DESCRIPTION("Checks if Vec3 + operator is overridden properly","CheckIsVec3OperatorAdditionIsWorking")
    Vec3 vec3a{.x=1,.y=2,.z=3};
    Vec3 vec3b{.x=1,.y=2,.z=3};
    Vec3 result = vec3a + vec3b;

    ASSERT_EQ(result.x,2);
    ASSERT_EQ(result.y,4);
    ASSERT_EQ(result.z,6);
}

/**
 * Checks if subtracting two vector with overridden function will work (operator -)
 */
TEST(VectorTests, CheckIsVec3OperatorSubtractionIsWorking){
    TEST_DESCRIPTION("Checks if Vec3 - operator is overridden properly","CheckIsVec3OperatorAdditionIsWorking")
    Vec3 vec3a{.x=1,.y=2,.z=3};
    Vec3 vec3b{.x=1,.y=2,.z=3};
    Vec3 result = vec3a - vec3b;

    ASSERT_EQ(result.x,0);
    ASSERT_EQ(result.y,0);
    ASSERT_EQ(result.z,0);
}

/**
 * Checks if multiplying vector with scalar returns a new vector with appropriate values
 */
TEST(VectorTests, CheckIsVec3OperatorMultiplyWithScalarWorking){
    TEST_DESCRIPTION("Checks if Vec3 * scalar operator is overridden properly","CheckIsVec3OperatorMultiplyWithScalarWorking")
    Vec3 vec3a{.x=1,.y=2,.z=3};
    Vec3 result = vec3a * 2;

    ASSERT_EQ(result.x,2);
    ASSERT_EQ(result.y,4);
    ASSERT_EQ(result.z,6);
}

/**
 * Checks if division vector with scalar returns a new vector with appropriate values
 */
TEST(VectorTests, CheckIsVec3OperatorDivisionWithScalarWorking){
    TEST_DESCRIPTION("Checks if Vec3 / scalar operator is overridden properly","CheckIsVec3OperatorDivisionWithScalarWorking")
    Vec3 vec3a{.x=4,.y=8,.z=16};
    Vec3 result = vec3a / 2;

    ASSERT_EQ(result.x,2);
    ASSERT_EQ(result.y,4);
    ASSERT_EQ(result.z,8);
}

/**
 * Checks if multiplying vector with scalar of type float is working
 */
TEST(VectorTests, CheckIsVec3OperatorMultiplyWithScalarWorkingFloat){
    TEST_DESCRIPTION("Checks if Vec3 * scalar operator is overridden properly with float numbers","CheckIsVec3OperatorMultiplyWithScalarWorkingFloat")
    Vec3 vec3a{.x=1,.y=2,.z=3};
    Vec3 result = vec3a * 0.5f;

    ASSERT_EQ(result.x,0.5f);
    ASSERT_EQ(result.y,1);
    ASSERT_EQ(result.z,1.5f);
}

/**
 * Checks if multiplying vector with scalar of type float is working
 */
TEST(VectorTests, CheckIsVec3OperatorDivisionWithScalarWorkingFloat){
    TEST_DESCRIPTION("Checks if Vec3 / scalar operator is overridden properly with float numbers","CheckIsVec3OperatorDivisionWithScalarWorkingFloat")
    Vec3 vec3a{.x=1,.y=2,.z=3};
    Vec3 result = vec3a / 0.5f;

    ASSERT_EQ(result.x,2);
    ASSERT_EQ(result.y,4);
    ASSERT_EQ(result.z,6);
}

/**
 * Checks if divide will throw exception appropriately
 */
TEST(VectorTests, ChecksIfDivisionVectorDropsException){
    TEST_DESCRIPTION("Checks if Vec3 / operator with another Vec3 throws exception","ChecksIfDivisionVectorDropsException")
    try{
        Vec3 vec3a{.x=1,.y=2,.z=3};
        Vec3 vec3b{.x=1,.y=2,.z=3};
        Vec3 result = vec3a / vec3b;
    }catch (linearAlgebraEnums::ErrorCodes e){
        ASSERT_EQ(e,linearAlgebraEnums::ErrorCodes::VECTOR_CANT_BE_DIVIDED_BY_VECTOR);
    }
}

/**
 * Checks if dot product is working properly
 */
TEST(VectorTests, CheckIfVec3DotProductIsWorking){
    TEST_DESCRIPTION("Checks if dot product is working properly","CheckIfVec3DotProductIsWorking")
    Vec3 vec3a{.x=5.16,.y=2,.z=3};
    Vec3 vec3b{.x=1,.y=8,.z=12};
    float result = vec3b * vec3a;

    ASSERT_EQ(result,57.16f);
}


/**
 * MATRIX TEST
 */

/**
 * Checks if multiply of two 4x4 matrix is working
 */
TEST(MatrixTests, CheckiIf4X4matMultiplicationIsWorking){
    TEST_DESCRIPTION("Checks if 4x4 matrix multiplication is working - DEPRECATED TEST","CheckiIf4X4matMultiplicationIsWorking")
    Mat4x4Deprecated mat4X4A{};

    mat4X4A.r1[0] = 1;
    mat4X4A.r1[1] = 2;
    mat4X4A.r1[2] = 3;
    mat4X4A.r1[3] = 4;

    mat4X4A.r2[0] = 5;
    mat4X4A.r2[1] = 6;
    mat4X4A.r2[2] = 7;
    mat4X4A.r2[3] = 8;

    mat4X4A.r3[0] = 9;
    mat4X4A.r3[1] = 10;
    mat4X4A.r3[2] = 11;
    mat4X4A.r3[3] = 12;

    mat4X4A.r4[0] = 13;
    mat4X4A.r4[1] = 14;
    mat4X4A.r4[2] = 15;
    mat4X4A.r4[3] = 16;


    Mat4x4Deprecated mat4X4B{};

    mat4X4B.r1[0] = 5;
    mat4X4B.r1[1] = 6;
    mat4X4B.r1[2] = 7;
    mat4X4B.r1[3] = 8;

    mat4X4B.r2[0] = 9;
    mat4X4B.r2[1] = 10;
    mat4X4B.r2[2] = 11;
    mat4X4B.r2[3] = 12;

    mat4X4B.r3[0] = 13;
    mat4X4B.r3[1] = 14;
    mat4X4B.r3[2] = 15;
    mat4X4B.r3[3] = 16;

    mat4X4B.r4[0] = 17;
    mat4X4B.r4[1] = 18;
    mat4X4B.r4[2] = 19;
    mat4X4B.r4[3] = 20;



    Mat4x4Deprecated result = mat4X4A * mat4X4B;

    ASSERT_EQ(result.r1[0],130);
    ASSERT_EQ(result.r1[1],140);
    ASSERT_EQ(result.r1[2],150);
    ASSERT_EQ(result.r1[3],160);

    ASSERT_EQ(result.r2[0],306);
    ASSERT_EQ(result.r2[1],332);
    ASSERT_EQ(result.r2[2],358);
    ASSERT_EQ(result.r2[3],384);

    ASSERT_EQ(result.r3[0],482);
    ASSERT_EQ(result.r3[1],524);
    ASSERT_EQ(result.r3[2],566);
    ASSERT_EQ(result.r3[3],608);

    ASSERT_EQ(result.r4[0],658);
    ASSERT_EQ(result.r4[1],716);
    ASSERT_EQ(result.r4[2],774);
    ASSERT_EQ(result.r4[3],832);
}


/**
 * SIMPLE MATH FUNCTIONS
 */

TEST(MatrixTests, CheckResultOfDotProductArrays){
    TEST_DESCRIPTION("Calculate dot product of arrays","CheckResultOfDotProductArrays")
    float testa[3]={1,2,3};
    float testb[3]={4,5,6};
    float result = dotProductOfArrays(testa,testb,3);

    ASSERT_EQ(result,32);
}


/**
 * Check if identity matrix is properly built
 */
TEST(MatrixTests, CheckIfIdentityMatrixIsInitializedProperly){
    TEST_DESCRIPTION("Check if identity matrix is initialized properly","CheckIfIdentityMatrixIsInitializedProperly")
    Mat4x4 matrix{};

    initIdentityMatrix4x4(&matrix);

}


/**
 * Check if identity matrix is properly built
 */
TEST(MatrixTests, CheckScalarMatrixMultiplicationWithTranslation_COLUMN_ROW){
    TEST_DESCRIPTION("","CheckScalarMatrixMultiplicationWithTranslation_COLUMN_ROW")
    Mat4x4 matrixA{};
    Mat4x4 matrixB{};

    Vec3 translation{.x=5,.y=2,.z=3};
    Vec3 scalar{.x=2,.y=2,.z=2};

    initIdentityMatrix4x4(&matrixA);
    initIdentityMatrix4x4(&matrixB);

    createTranslationMatrix4x4(&matrixA,&translation);
    createScaleMatrix4x4(&matrixB,&scalar);

    Mat4x4 newMatrix = matrixB * &matrixA;


    float correctArray[16] = {
            2,0,0,0,
            0,2,0,0,
            0,0,2,0,
            5,2,3,1
    };

    for(int i = 0; i < 16;++i){
        ASSERT_EQ(correctArray[i],newMatrix.matrix[i]);
    }
}

TEST(MatrixTests, Mat4x4MultipliedWithVec3){
    TEST_DESCRIPTION("","Mat4x4MultipliedWithVec3")
    Mat4x4 matrixA{};

    Vec3 translation{.x=5,.y=2,.z=3};
    Vec3 point{.x=1,.y=2,.z=2};

    initIdentityMatrix4x4(&matrixA);
    createTranslationMatrix4x4(&matrixA,&translation);

    Vec3 result = matrixA * &point;

    ASSERT_EQ(result.x,6);
    ASSERT_EQ(result.y,4);
    ASSERT_EQ(result.z,5);
}

/**
 * QUATERNION TESTS
 */

/**
 * Check if quaternion is normalized properly and if rotation quaternion is set to proper values
 */
TEST(QuaternionTests, CheckQuaternionRotationInitialization){
    TEST_DESCRIPTION("Check if quaternion is properly normalized and values are set properly","CheckQuaternionRotationInitialization")

    Quaternion quaternion{0};

    createUnitQuaternionForRotation(1,1,1,120,&quaternion);

    EXPECT_NEAR(quaternion.w,0.5f,0.1);
    EXPECT_NEAR(quaternion.i,0.5f,0.1);
    EXPECT_NEAR(quaternion.j,0.5f,0.1);
    EXPECT_NEAR(quaternion.k,0.5f,0.1);
}

/**
 * Check if quaternion conjugate is set properly
 */
TEST(QuaternionTests, CheckConjugateOfQuaternionFunction){
    TEST_DESCRIPTION("Check if quaternion conjugate is set properly","CheckConjugateOfQuaternionFunction")

    Quaternion quaternion{0};
    Quaternion conjugate{0};
    createUnitQuaternionForRotation(1,1,1,120,&quaternion);
    createConjugateQuaternion(&quaternion,&conjugate);

    EXPECT_NEAR(conjugate.w,0.5f,0.1);
    EXPECT_NEAR(conjugate.i,-0.5f,0.1);
    EXPECT_NEAR(conjugate.j,-0.5f,0.1);
    EXPECT_NEAR(conjugate.k,-0.5f,0.1);

}

/**
 * Check if quaternion is properly setup from Vec3 struct
 */
TEST(QuaternionTests, CheckIfVectorIsProperlyTransformedIntoQuaternion){
    TEST_DESCRIPTION("Check if quaternion is properly setup from Vec3 struct","CheckIfVectorIsProperlyTransformedIntoQuaternion")

    Vec3 point{.x=7,.y=2,.z=10};

    Quaternion quaternion =  createQuaternionFromVector3Point(&point);

    ASSERT_EQ(quaternion.w,0);
    ASSERT_EQ(quaternion.i,7);
    ASSERT_EQ(quaternion.j,2);
    ASSERT_EQ(quaternion.k,10);
}


/**
 * Multiplication of quaternion checking
 */
TEST(QuaternionTests, CheckIfQuaternionMultiplicationIsDoneProperly){
    TEST_DESCRIPTION("Check if quaternion * quaternion gives another quaterinion with proper results","CheckIfQuaternionMultiplicationIsDoneProperly")

    Quaternion quaternion{0};
    Vec3 point{.x=7,.y=2,.z=5};

    createUnitQuaternionForRotation(1,1,1,120,&quaternion);
    Quaternion pointQuaternion = createQuaternionFromVector3Point(&point);

    Quaternion newQuaternion = quaternion * &pointQuaternion;

    ASSERT_EQ(newQuaternion.w,-7);
    ASSERT_EQ(newQuaternion.i,5);
    ASSERT_EQ(newQuaternion.j,2);
    ASSERT_NEAR(newQuaternion.k,0,0.1);
}


/**
 * Multiplication of quaternion checking
 */
TEST(QuaternionTests, CheckQuaternionMatRotationWithVector){
    TEST_DESCRIPTION("Check if quaternion to rotation matrix is returning appropriate values","CheckQuaternionToMat4x4")

    Quaternion quaternion{0};
    Vec3 point{.x=1,.y=0,.z=0};

    createUnitQuaternionForRotation(0,1,1,120,&quaternion);

    Mat4x4 mat4X4{0};

    createMat4x4FromQuaternionRotation(&quaternion, &mat4X4);


    ASSERT_NEAR(mat4X4.matrix[0],-0.5f,0.1);
    ASSERT_NEAR(mat4X4.matrix[4],-0.61f,0.1);
    ASSERT_NEAR(mat4X4.matrix[8],0.6123f,0.1);

    ASSERT_NEAR(mat4X4.matrix[1],0.6123,0.1);
    ASSERT_NEAR(mat4X4.matrix[5],0.25,0.1);
    ASSERT_NEAR(mat4X4.matrix[9],0.75,0.1);

    ASSERT_NEAR(mat4X4.matrix[2],-0.6123,0.1);
    ASSERT_NEAR(mat4X4.matrix[6],0.75,0.1);
    ASSERT_NEAR(mat4X4.matrix[10],0.25,0.1);


    Vec3 rotatedPoint = mat4X4 * &point;

    ASSERT_NEAR(rotatedPoint.x,-0.5,0.05);
    ASSERT_NEAR(rotatedPoint.y,0.6123,0.05);
    ASSERT_NEAR(rotatedPoint.z,-0.6123,0.05);
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