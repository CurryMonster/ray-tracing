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
        virtual ~Sphere() override;

        Point get_center() const;
        double get_radius() const;
        void set_center(const double& x, const double& y, const double& z);
        void set_radius(const double& radius);

        virtual bool hit(const Ray& ray, double& t_m, Record& record) const override;
    public:
        Point center;
        double radius;
};

