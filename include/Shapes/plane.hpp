#pragma once

#include <Shapes/shape.hpp>
#include <Utilities/point.hpp>
#include <Utilities/normal.hpp>
#include <Utilities/ray.hpp>
#include <Utilities/record.hpp>

class Plane: public Shape 
{
    public:
        Plane(const Point& point, const Normal& normal);
        virtual bool hit(const Ray& ray, double& t_min, Record& rec) const override;
        Point get_point() const;
        Normal get_normal() const;
        void set_point(const Point& point);
        void set_normal(const Normal& normal);
    private:
        Point point;
        Normal normal;
};