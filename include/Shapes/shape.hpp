#pragma once

#include <Utilities/ray.hpp>
#include <Utilities/record.hpp>
#include <Utilities/color.hpp>

class Shape {
    public:
        Shape();
        virtual ~Shape();
        virtual bool hit(const Ray& ray, double& t_min, Record& rec) const = 0;
        Color get_color() const;
        void set_color(const Color& color);
    private:
        Color color;
};