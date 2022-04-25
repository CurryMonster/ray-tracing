#pragma once

#include "BRDFs/brdf.hpp"

class GlossySpecularReflection: public BRDF
{
    public:
        GlossySpecularReflection();
        virtual ~GlossySpecularReflection() override;
        virtual Color f(const Record& record, const Vector& incoming_direction, const Vector& reflected_direction) const override;
        virtual Color reflectance(const Record& record, const Vector& reflected_direction) const override;
    public:
        double specular_reflection_coefficient;
        double phong_exponent;
        Color  specular_color;
};