#pragma once

#include "Utilities/color.hpp"
#include "Utilities/vector.hpp"
#include "Utilities/record.hpp"

class Light
{
    public:
        Light();
        virtual Vector direction(Record& record) = 0;
        virtual Color incident_radiance(Record& record) = 0;
        virtual ~Light();
    public:
        bool shadow;
};

