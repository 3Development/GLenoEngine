//
// Created by leno on 27.04.23..
//

#ifndef LENOENGINE_TRANSFORMATION_MATRICES_H
#define LENOENGINE_TRANSFORMATION_MATRICES_H
#include "../objects/matrix.h"
#include "../objects/quaternion.h"
#include <cmath>


/**
 * MATRIX4x4 TRANSFORMATIONS
 */


/**
 * Initializes a identity matrix on a new struct
 * @param mat4X4
 */
void initIdentityMatrix4x4(Mat4x4* mat4X4);


/**
 * Applying a components of vector3 into matrix in a way that this matrix will
 * represent translation matrix
 * @param mat4X4
 * @param vec3
 */
void createTranslationMatrix4x4(Mat4x4* mat4X4,Vec3* vec3);

/**
 * Applying a components of vector3 into matrix in a way that this matrix will
 * represent translation matrix
 * @param mat4X4
 * @param vec3
 */
void createTranslationMatrix4x4(Mat4x4* mat4X4,float x, float y, float z);

/**
 * Applying a component of vector3 that represents a scale in way that this matrix will represent
 * a scale matrix
 */
void createScaleMatrix4x4(Mat4x4* mat4X4, Vec3* vec3);

/**
 * Applying a component of vector3 that represents a scale in way that this matrix will represent
 * a scale matrix
 */
void createScaleMatrix4x4(Mat4x4* mat4X4, float x, float y, float z);


/**
 * Creating perspective matrix.
 * This matrix helps that objects that are further to make them smaller and closer to center.
 * @param mat4X4
 * @param width
 * @param height
 * @param fovDegree
 * @param zNear
 * @param zFar
 */
void createPerspectiveMatrix4x4(Mat4x4* mat4X4,float width,float height,float fovDegree,float zNear,float zFar);


/**
 *
 * @param quaternion
 * @param mat4X4
 */
void createMat4x4FromQuaternionRotation(Quaternion* quaternion,Mat4x4* mat4X4 );

/**
 *
 * @param quaternion
 * @param mat4X4
 */
void createMat4x4FromQuaternionRotation(Mat4x4* mat4X4,float w,float i,float j,float k);

#endif //LENOENGINE_TRANSFORMATION_MATRICES_H
