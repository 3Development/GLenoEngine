//
// Created by leno on 27.04.23..
//

#ifndef LENOENGINE_TRANSFORMATION_MATRICES_H
#define LENOENGINE_TRANSFORMATION_MATRICES_H
#include "../objects/matrix.h"
#include "../objects/vector.h"
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
 * Applying a component of vector3 that represents a scale in way that this matrix will represent
 * a scale matrix
 */
void createScaleMatrix4x4(Mat4x4* mat4X4, Vec3* vec3);


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

#endif //LENOENGINE_TRANSFORMATION_MATRICES_H
