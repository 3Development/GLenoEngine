//
// Created by leno on 09.05.23..
//

#ifndef LENOENGINE_QUATERNION_H
#define LENOENGINE_QUATERNION_H
#include "vector.h"
#include <cmath>


struct Quaternion{
    float w;
    float i;
    float j;
    float k;

    /**
     * Quaternion multiplication
     *
     * following rules of quaternion multiplication
     *
            i*i = j*j = k*k = -1
            i*j = k,
            j*i = -k
            j*k = i,
            k*j = -i
            k*i = j,
            i*k = -j
     * @param other
     * @return
     */
    inline Quaternion operator * (Quaternion* other){
        Quaternion newQuaternion;

        newQuaternion.w = (w * other->w) - (i * other->i) - (j * other->j) - (k * other->k);
        newQuaternion.i = (w * other->i) + (i * other->w)  + (j * other-> k) - (k * other->j);
        newQuaternion.j = (w * other->j) + (j * other->w) - (i * other->k) + (k * other->i);
        newQuaternion.k = (w * other->k) + (i * other->j) - (j * other->i) + (k * other->w);

        return newQuaternion;
    }


};


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
void createUnitQuaternionForRotation(float x,float y,float z,float angleDegrees,Quaternion* quaternion);


/**
 * simple multiple with * -1 i , j and k. w stays the same
 * @param original
 * @param inverseQuaternion
 */
void createConjugateQuaternion(Quaternion* original,Quaternion* conjugate);

/**
 *
 * @param vectorPoint
 */
Quaternion createQuaternionFromVector3Point(Vec3* vectorPoint);

#endif //LENOENGINE_QUATERNION_H
