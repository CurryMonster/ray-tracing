#pragma once

#include "Lights/light.hpp"
#include "Utilities/color.hpp"

class Ambient: public Light
{
    public:
        Ambient();
        virtual ~Ambient() override;
        virtual Vector direction(Record& record) override;
        virtual Color incident_radiance(Record& record) override;
    public: 
        double radiance_scaling_factor;
        Color  color;
};
