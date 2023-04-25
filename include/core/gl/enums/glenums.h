//
// Created by leno on 22.04.23..
//

#ifndef LENOENGINE_GLENUMS_H
#define LENOENGINE_GLENUMS_H

namespace VboVaoEnums{

    /**
     * Attribute type for VBO.
     * Some VBO (array of data) can represent positions, color or for example normals.
     * When adding new type, new enums is important to add here.
     *
     * @IMPORTANT -> all vbo attribute types should be added here
     */
    enum VboAttributeType : unsigned char{
        POSITION,COLOR,NORMAL,INDICES
    };

    /**
     * Error codes for exceptions
     */
    enum ErrorCodes : unsigned char{
        VA0_NO_FREE_SLOT_IN_VBO_ARRAY,// When VAO is not having anymore free slot to add new attribute, VBO.
    };


}

#endif //LENOENGINE_GLENUMS_H
