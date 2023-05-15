//
// Created by leno on 15.05.23..
//
#include "utilz/math/algebra/objects/quaternion.h"


/**
 *This function will create a unit quaternion that will be used for rotating in 3d.
 *
 * Basic steps are :
 *  1.Normalized axis, magnitude should be 1
 *  2.use formula cos(degree/2) + sin(degree/2) (x+y+z)
 *
 * @param x
 * @param y
 * @param z
 * @param angleDegrees
 */
void createUnitQuaternionForRotation(float x,float y,float z,float angleDegrees,Quaternion* quaternion){
    float angleInRadians = angleDegrees * (M_PI / 180);
    float magnitude = std::sqrt(x*x + y*y + z*z );

    x= x / magnitude;
    y = y / magnitude;
    z = z / magnitude;

    quaternion-> w = std::cos(angleInRadians / 2);
    quaternion-> i = std::sin(angleInRadians / 2) * x;
    quaternion-> j = std::sin(angleInRadians / 2) * y;
    quaternion-> k = std::sin(angleInRadians / 2) * z;
}

/**
 * simple multiple with * -1 i , j and k. w stays the same
 * @param original
 * @param inverseQuaternion
 */
void createConjugateQuaternion(Quaternion* original,Quaternion* conjugate){
    conjugate->w = original->w;
    conjugate->i = -original->i;
    conjugate->j = -original->j;
    conjugate->k = -original->k;
}

/**
 * Return quaterion from vec3 struct
 * @param vectorPoint
 */
Quaternion createQuaternionFromVector3Point(Vec3* vectorPoint){
    return Quaternion{.w = 0,
                      .i = vectorPoint->x
                              ,.j = vectorPoint->y
                                      ,.k = vectorPoint->z};
}