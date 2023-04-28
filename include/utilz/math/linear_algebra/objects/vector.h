//
// Created by leno on 25.04.23..
//

#ifndef LENOENGINE_VECTOR_H
#define LENOENGINE_VECTOR_H
#include "utilz/math/enums/linearAlgebraEnums.h"

struct Vec3{
    float x = 0;
    float y = 0;
    float z = 0;

    /**
     * Override a multiplication with scalar
     * Vector * scalar -> returns another vector (Vector direction stays the same but magnitude is changed)
     * @param number
     * @return another Vector
     */
    inline Vec3 operator*(float number){
        return Vec3{x*number,y*number,z*number};
    }
    /**
     * Override a division with scalar
     * returns another vector, one that components are divided by scalar
     * @tparam T
     * @param number
     * @return
     */
    template<typename T>
    inline Vec3 operator/(T number){
        return Vec3{x/number,y/number,z/number};
    }




    /**
     * Simple dot product
     * @tparam T  can be float or int or double
     * @param other
     * @return
     */
    inline float operator *(Vec3 other){
        return (other.x * x)+(other.y * y) +(other.z * z);
    }

    /**
     * Vector can not be divided by another vector so this will throw exception
     * @tparam T
     * @param number
     * @return
     */
    inline Vec3 operator/(Vec3 other){
        throw linearAlgebraEnums::ErrorCodes::VECTOR_CANT_BE_DIVIDED_BY_VECTOR;
    }

    /**
     * Addition with another vector.
     * Simply adding components together
     * @param other
     * @return another vector
     */
    inline Vec3 operator+(Vec3 other){
        return {other.x+x,other.y+y,other.z+z};
    }

    /**
     * Subtraction of vectors with one another.
     * This just addition with negative vector
     * @param other
     * @return
     */
    inline Vec3 operator-(Vec3 other){
        return {other.x-x,other.y-y,other.z-z};
    }
};


/**
 * Calculates the dot product of two arrays.
 * They must have an equal number of components.
 * @param a
 * @param b
 * @param componentSize
 * @return
 */
inline float dotProductOfArrays(float *a,float *b,int componentSize){
    float result = 0;

    for(int i = 0; i < componentSize; ++i){
        result += *((a)+i) * *((b+i));
    }
    return result;
}






#endif //LENOENGINE_VECTOR_H
