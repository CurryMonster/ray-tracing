#pragma once

#include "Utilities/color.hpp"
#include "Utilities/record.hpp"

class Material
{
    public:
        Material() {};
        virtual ~Material();
        virtual Color shade(Record& record) = 0;
};