//
// Created by leno on 25.06.23..
//

#ifndef LENOENGINE_MODELENUMS_H
#define LENOENGINE_MODELENUMS_H


namespace ModelGroupEnums{


    /**
     * Enum data transformation. This is to signal a function what kind of data is going to be stored in data array in VaoGroup.
     */
    enum TransformationFlags : unsigned char{
        POSITION = 0b00000001,
        SCALE =    0b00000010,
        ROTATION = 0b00000100,
    };
}


#endif //LENOENGINE_MODELENUMS_H
