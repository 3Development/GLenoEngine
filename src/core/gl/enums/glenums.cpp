//
// Created by leno on 26.05.23..
//
#include "core/gl/enums/glenums.h"



namespace UniformEnums{
    /**
     * This represents how variables are named in shaders
     */
    std::map<UniformType,std::string> _uniformTypeMap {
            {UniformType::PROJECTION_MATRIX,"projectionM"},
            {UniformType::ROTATION_MATRIX,"rotationM"},
            {UniformType::TRANSLATION_MATRIX,"translationM"},
            {UniformType::WORLD_MATRIX,"worldM"},
            {UniformType::DEBUG_MATRIX,"debugM"},
    };

}