//
// Created by leno on 26.04.23..
//

#ifndef LENOENGINE_MATRIX_H
#define LENOENGINE_MATRIX_H
#include "vector.h"

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
struct Mat4x4{
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
    inline Mat4x4 operator *(Mat4x4 mat4X4){
        Mat4x4 newMat4x4{};


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


#endif //LENOENGINE_MATRIX_H
