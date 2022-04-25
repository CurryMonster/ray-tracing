#pragma once

#include "Materials/material.hpp"
#include "Utilities/color.hpp"

#include <memory>

class Lambertian;
class GlossySpecularReflection;

class Phong: public Material
{
    public:
        Phong();
        virtual ~Phong() override;
        virtual Color shade(Record& record) override;

        void set_specular_reflection_coefficient(const double& value);
        void set_phong_exponent(const double& value);
        void set_specular_color(const Color& color);
        
        void set_ambient_reflection_coefficient(const double& value);
        void set_diffuse_reflection_coefficient(const double& value);
        void set_diffuse_color(const Color& color);
    public:
        std::shared_ptr<Lambertian>               ambient_brdf;
        std::shared_ptr<Lambertian>               diffuse_brdf;
        std::shared_ptr<GlossySpecularReflection> specular_brdf;
};

