//
// Created by leno on 27.04.23..
//

#include "utilz/math/algebra//linear_functions/transformation_matrices.h"



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
    mat4X4->matrix[(3*4)+3] = 1;
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
void createTranslationMatrix4x4(Mat4x4* mat4X4,float x, float y, float z){
    mat4X4->matrix[(3*4)+0] = x;
    mat4X4->matrix[(3*4)+1] = y;
    mat4X4->matrix[(3*4)+2] = z;
    mat4X4->matrix[(3*4)+3] = 1;
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

/**
 * Applying a component of vector3 that represents a scale in way that this matrix will represent
 * a scale matrix
 */
void createScaleMatrix4x4(Mat4x4* mat4X4, float x, float y, float z){
    mat4X4->matrix[(0*4) + 0] = x;
    mat4X4->matrix[(1*4) + 1] = y;
    mat4X4->matrix[(2*4) + 2] = z;
}

/**
 * Creating perspective matrix.
 * This matrix helps that objects that are further to make them smaller and closer to center.
 *
 * Aspect ratio -> we divide height by width and because of that we have to multiply it with the x component of vector3, position.
 * @param mat4X4
 * @param width
 * @param height
 * @param fovDegree
 * @param zNear
 * @param zFar
 */
void createPerspectiveMatrix4x4(Mat4x4* mat4X4,float width,float height,float fovDegree,float zNear,float zFar){
    float aspectRatio = height / width;
    float tangent = tan( (fovDegree * M_PI) / 180 )/2;
    mat4X4->matrix[0] = aspectRatio * ( 1 / tangent);
    mat4X4->matrix[ (4*1) + 1 ] = 1 / tangent;
    mat4X4->matrix[ (4*2) + 2 ] = -(zFar + zNear) / (zFar - zNear);
    mat4X4->matrix[ (4*3) + 2 ] = -(2*zFar*zNear)/ (zFar - zNear);
    mat4X4->matrix[ (4*2) + 3 ] = -1;
}

/**
 *
 * @param quaternion
 * @param mat4X4
 */
void createMat4x4FromQuaternionRotation(Quaternion* quaternion,Mat4x4* mat4X4 ){
    float w = quaternion->w;
    float x = quaternion->i;
    float y = quaternion->j;
    float z = quaternion->k;


    mat4X4->matrix[(0 * 4) + 0] = 2 * ( w * w + x * x) - 1;
    mat4X4->matrix[(1 * 4) + 0] = 2 * (x * y  - w * z);
    mat4X4->matrix[(2 * 4) + 0] = 2 * (x * z + w * y);


    mat4X4->matrix[(0 * 4) + 1] = 2 * (x * y + w * z);
    mat4X4->matrix[(1 * 4) + 1] = 2 * (w * w + y * y) - 1;
    mat4X4->matrix[(2 * 4) + 1] = 2 * (y * z - w * x);

    mat4X4->matrix[(0 * 4) + 2] = 2 * (x * z - w * y);
    mat4X4->matrix[(1 * 4) + 2] = 2 * (y * z + w * x);
    mat4X4->matrix[(2 * 4) + 2] = 2 * (w * w + z * z) -1;

    mat4X4->matrix[(3 * 4) + 3] = 1;
}



