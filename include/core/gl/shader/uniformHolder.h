//
// Created by leno on 04.05.23..
//

#ifndef LENOENGINE_UNIFORMHOLDER_H
#define LENOENGINE_UNIFORMHOLDER_H

struct UniformsHolder{
    unsigned int worldMatrixLocation = -1;
    const char* worldMatrix = "worldMatrix";

    unsigned int projectionMatrixLocation = -1;
    const char* projectionMatrix = "projectionMatrix";

    unsigned int viewMatrixLocation = -1;
    const char* viewMatrix = "viewMatrix";
};

#endif //LENOENGINE_UNIFORMHOLDER_H
