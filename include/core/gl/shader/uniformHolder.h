//
// Created by leno on 04.05.23..
//

#ifndef LENOENGINE_UNIFORMHOLDER_H
#define LENOENGINE_UNIFORMHOLDER_H
#include "utilz/math/algebra/objects/matrix.h"


/**
 * Placeholder for all the uniforms that are used.
 */


struct UniformsHolder{
    int worldMatrixLocation = -1;
    int projectionMatrixLocation = -1;
    int translationMatrixLocation = -1;
    int viewMatrixLocation = -1;
    int rotationMatrixLocation = -1;
};

#endif //LENOENGINE_UNIFORMHOLDER_H
