//
// Created by leno on 26.04.23..
//

#ifndef LENOENGINE_MATRIX_H
#define LENOENGINE_MATRIX_H

#include "./vector.h"
#define SIZE_OF_MATRIX4_ARRAY 16

/**
 * Matrix 4x4.
 * Each row contains a 4 numbers that way representing 4x4 matrix
 * We multiply each row by column
 *
 *      A    B
 *  [2,5,6] [3]   one row in A multiply with each column on B
 *          [4]   A column must match B rows -> so one row A must have 3 columns if B in one column have 3 rows
 *         [-5]   At the end Arow1 x Bcolumn1 is basically dot product
 *
 *         A*B = [2X3]
 *
 *
 *
 *         If A increase row then resulted Matrix will have one row extra. If matrix B increases colum then resulted matrix will have extra column
 */
struct Mat4x4Deprecated{
    float r1[4];
    float r2[4];
    float r3[4];
    float r4[4];


    /**
     * Resulted matrix
     *
     * A = r matrix
     * B = or other matrix
     *
     *
     *  0        1               2              3                4
     *  1   Arow1*Bcolumn1
     *  2
     *  3
     *  4
     * @param mat4X4
     * @return
     */
    inline Mat4x4Deprecated operator *(Mat4x4Deprecated mat4X4){
        Mat4x4Deprecated newMat4x4{};

        newMat4x4.r1[0] = ((r1[0] * mat4X4.r1[0]) + (r1[1] * mat4X4.r2[0]) + (r1[2] * mat4X4.r3[0] ) + (r1[3] * mat4X4.r4[0])   ); // First row first column
        newMat4x4.r1[1] = ( (r1[0] * mat4X4.r1[1]) + (r1[1] * mat4X4.r2[1] ) + ( r1[2] * mat4X4.r3[1] ) + ( r1[3] * mat4X4.r4[1]) ); // First row second column
        newMat4x4.r1[2] = ((r1[0] * mat4X4.r1[2]) + (r1[1] * mat4X4.r2[2]) + (r1[2] * mat4X4.r3[2] ) + (r1[3] * mat4X4.r4[2])   ); // First row third column
        newMat4x4.r1[3] = ((r1[0] * mat4X4.r1[3]) + (r1[1] * mat4X4.r2[3]) + (r1[2] * mat4X4.r3[3] ) + (r1[3] * mat4X4.r4[3])   ); // First row fourth column

        newMat4x4.r2[0] = ((r2[0] * mat4X4.r1[0]) + (r2[1] * mat4X4.r2[0]) + (r2[2] * mat4X4.r3[0] ) + (r2[3] * mat4X4.r4[0])   ); // Second row first column
        newMat4x4.r2[1] = ((r2[0] * mat4X4.r1[1]) + (r2[1] * mat4X4.r2[1]) + (r2[2] * mat4X4.r3[1] ) + (r2[3] * mat4X4.r4[1])   ); // Second row second column
        newMat4x4.r2[2] = ((r2[0] * mat4X4.r1[2]) + (r2[1] * mat4X4.r2[2]) + (r2[2] * mat4X4.r3[2] ) + (r2[3] * mat4X4.r4[2])   ); // Second row third column
        newMat4x4.r2[3] = ((r2[0] * mat4X4.r1[3]) + (r2[1] * mat4X4.r2[3]) + (r2[2] * mat4X4.r3[3] ) + (r2[3] * mat4X4.r4[3])   ); // Second row fourth column


        newMat4x4.r3[0] = ( (r3[0] * mat4X4.r1[0]) + (r3[1] * mat4X4.r2[0]) + (r3[2] * mat4X4.r3[0] ) + (r3[3] * mat4X4.r4[0])   );// Third row first column
        newMat4x4.r3[1] = ((r3[0] * mat4X4.r1[1]) + (r3[1] * mat4X4.r2[1]) + (r3[2] * mat4X4.r3[1] ) + (r3[3] * mat4X4.r4[1])   ); // Third row second column
        newMat4x4.r3[2] = ((r3[0] * mat4X4.r1[2]) + (r3[1] * mat4X4.r2[2]) + (r3[2] * mat4X4.r3[2] ) + (r3[3] * mat4X4.r4[2])   ); // Third row third column
        newMat4x4.r3[3] = ((r3[0] * mat4X4.r1[3]) + (r3[1] * mat4X4.r2[3]) + (r3[2] * mat4X4.r3[3] ) + (r3[3] * mat4X4.r4[3])   ); // Third row fourth column

        newMat4x4.r4[0] = ((r4[0] * mat4X4.r1[0]) + (r4[1] * mat4X4.r2[0]) + (r4[2] * mat4X4.r3[0] ) + (r4[3] * mat4X4.r4[0])   );// Third row first column
        newMat4x4.r4[1] = ((r4[0] * mat4X4.r1[1]) + (r4[1] * mat4X4.r2[1]) + (r4[2] * mat4X4.r3[1] ) + (r4[3] * mat4X4.r4[1])   ); // Third row second column
        newMat4x4.r4[2] = ((r4[0] * mat4X4.r1[2]) + (r4[1] * mat4X4.r2[2]) + (r4[2] * mat4X4.r3[2] ) + (r4[3] * mat4X4.r4[2])   ); // Third row third column
        newMat4x4.r4[3] = ((r4[0] * mat4X4.r1[3]) + (r4[1] * mat4X4.r2[3]) + (r4[2] * mat4X4.r3[3] ) + (r4[3] * mat4X4.r4[3])   ); // Third row fourth column


        return newMat4x4;
    }
};


/**
 * Opengl requires the data to be in one dimensional array and
 * it has to be column major, meaning if this is regular matrix
 * row major
 * [1 0 0 x]        [1 0 0 0]
 * [0 1 0 y]    ->  [0 1 0 0]
 * [0 0 1 z]        [0 0 1 0]
 * [0 0 0 1]        [x y z 1]
 *
 */
struct Mat4x4{
    float matrix[SIZE_OF_MATRIX4_ARRAY]={0};

    /**
     * Additional description -> http://localhost:63342/LenoEngine/documentation/code/src/utilz/math/objects/Mat4x4MultiplicationWithMat4x4.png
     *
     * Matrix with matrix multiplication
     *
     * @param otherMat4x4 -> otherMat4x4 is one on the right side or B matrix in notation AxB
     * @return
     */
    inline Mat4x4 operator * (Mat4x4* otherMat4x4){
        Mat4x4 newMatrix{0};
        int columnStartIndex = -1;
        int rowStartIndex = -1;
        for(int i = 0; i < SIZE_OF_MATRIX4_ARRAY; i++){ // Going trough all positions in matrix, meaning all 16

            if( i % 4 == 0){ // If i == 4, that means we need to go to next row and reset column index
                columnStartIndex = 0;
                rowStartIndex +=1;
            }
                                   // This first number is first number in row   Since columns always repeat this represents the first number in first column
            newMatrix.matrix[i] =  ( matrix[(rowStartIndex * 4) + 0  ] * otherMat4x4->matrix[ columnStartIndex ] ) + //Multiplying first row first column with first row first column
                                   ( matrix[(rowStartIndex * 4) + 1  ] * otherMat4x4->matrix[ columnStartIndex + 4 ] ) +
                                   ( matrix[(rowStartIndex * 4) + 2  ] * otherMat4x4->matrix[ columnStartIndex + 8 ] ) +
                                   ( matrix[(rowStartIndex * 4) + 3  ] * otherMat4x4->matrix[ columnStartIndex + 12 ] ) ;

            columnStartIndex +=1;
        }
        return newMatrix;
    }
};


#endif //LENOENGINE_MATRIX_H
