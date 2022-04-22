#pragma once

#include <Shapes/shape.hpp>
#include <Utilities/point.hpp>
#include <Utilities/normal.hpp>
#include <Utilities/ray.hpp>
#include <Utilities/record.hpp>

class Plane: public Shape 
{
    public:
        Plane();
        Plane(const Point& point, const Normal& normal);
        ~Plane();
        virtual bool hit(const Ray& ray, double& t_min, Record& rec) const override;
        Point get_point() const;
        Normal get_normal() const;
        void set_point(const double& x, const double& y, const double& z);
        void set_normal(const double& x, const double& y, const double& z);
    private:
        Point point;
        Normal normal;
};