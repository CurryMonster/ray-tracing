#pragma once

#include "Lights/light.hpp"
#include "Utilities/color.hpp"
#include "Utilities/point.hpp"

class PointLight: public Light 
{
    public:
        PointLight();
        virtual ~PointLight() override;
        virtual Vector direction(Record& record) override;
        virtual Color incident_radiance(Record& record) override;
        void set_location(const double& x, const double& y, const double& z);
    public:
        double radiance_scaling_factor;
        Color  color;
        Point  location;
};