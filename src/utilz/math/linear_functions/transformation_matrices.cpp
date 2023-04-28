//
// Created by leno on 27.04.23..
//

#include "utilz/math/linear_algebra/linear_functions/transformation_matrices.h"



/**
 * Initializes a identity matrix on a new struct
 *
 * In the end matrix will look like
 *
 * no matter is it row - major or column - major
 *
 * [1 0 0 0]
 * [0 1 0 0]
 * [0 0 1 0]
 * [0 0 0 1]
 *
 * @param mat4X4
 */
void initIdentityMatrix4x4(Mat4x4* mat4X4){
    for(int row = 0; row < 4; row++){
        mat4X4->matrix[(row * 4)+row] = 1;
    }
}


/**
 * Applying a components of vector3 into matrix in a way that this matrix will
 * represent translation matrix
 *
 *
 * (3x4) -> means third row, and why is it going * 4 because if we flatten the matrix the third row and first column is equal to index 12
 * @param mat4X4
 * @param vec3
 */
void createTranslationMatrix4x4(Mat4x4* mat4X4,Vec3* vec){
    mat4X4->matrix[(3*4)+0] = vec->x;
    mat4X4->matrix[(3*4)+1] = vec->y;
    mat4X4->matrix[(3*4)+2] = vec->z;
}


/**
 * Create a scale matrix
 * @param mat4X4
 * @param vec3
 */
void createScaleMatrix4x4(Mat4x4* mat4X4, Vec3* vec3){
    mat4X4->matrix[(0*4) + 0] = vec3->x;
    mat4X4->matrix[(1*4) + 1] = vec3->y;
    mat4X4->matrix[(2*4) + 2] = vec3->z;
}

