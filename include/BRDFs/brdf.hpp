#pragma once

#include "Utilities/color.hpp"
#include "Utilities/record.hpp"
#include "Utilities/vector.hpp"

class BRDF
{
    public:
        BRDF();
        virtual ~BRDF();
        virtual Color f(const Record& record, const Vector& incoming_direction, const Vector& reflected_direction) const = 0;
        virtual Color reflectance(const Record& record, const Vector& reflected_direction) const = 0;
};