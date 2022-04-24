#pragma once

#include "Materials/material.hpp"
#include "Utilities/color.hpp"
#include "Utilities/record.hpp"

#include <memory>

class Lambertian;

class Matte: public Material 
{
    public:
        Matte();
        virtual ~Matte() override;
        virtual Color shade(Record& record) override;
        void set_ambient_reflection_coefficient(const double& value);
        void set_diffuse_reflection_coefficient(const double& value);
        void set_diffuse_color(const Color& color);
    public:
        std::shared_ptr<Lambertian> ambient_brdf;
        std::shared_ptr<Lambertian> diffuse_brdf;
};