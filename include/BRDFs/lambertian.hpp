#pragma once

#include "BRDFs/brdf.hpp"
#include "Utilities/color.hpp"

class Lambertian: public BRDF
{
    public:
        Lambertian();
        virtual ~Lambertian() override;
        virtual Color f(const Record& record, const Vector& incoming_direction, const Vector& reflected_direction) const override;
        virtual Color reflectance(const Record& record, const Vector& reflected_direction) const override;
    public:
        double diffuse_reflection_coefficient;
        Color  diffuse_color;
};