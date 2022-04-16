#pragma once

#include <Shapes/shape.hpp>
#include <Utilities/point.hpp>
#include <Utilities/ray.hpp>
#include <Utilities/record.hpp>

class Sphere: public Shape 
{
    public:
        Sphere();
        Sphere(const Point& center, const double& radius);
        Point get_center() const;
        double get_radius() const;
        void set_center(const Point& center);
        void set_radius(const double& radius);
        virtual bool hit(const Ray& ray, double& t_min, Record& rec) const override;
    private:
        Point center;
        double radius;
};

