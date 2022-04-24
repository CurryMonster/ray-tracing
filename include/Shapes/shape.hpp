#pragma once

#include "Utilities/ray.hpp"
#include "Utilities/record.hpp"
#include "Utilities/color.hpp"

#include <memory>

class Material;

class Shape {
    public:
        Shape();
        virtual ~Shape();
        virtual bool hit(const Ray& ray, double& t_min, Record& rec) const = 0;
        Color get_color() const;
        void set_color(const Color& color);
        void set_material(std::shared_ptr<Material> material);
    public:
        Color color;
        std::shared_ptr<Material> material_ptr;
};