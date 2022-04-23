#pragma once 

#include <Utilities/point.hpp>
#include <Utilities/vector.hpp>

class Ray 
{
    public:
        Ray();
        Ray(const Point& origin, const Vector& direction);
        Point get_origin() const;
        Vector get_direction() const;
        void set_origin(const Point& point);
        void set_direction(const Vector& vector);
        void set_origin(const double& x, const double& y, const double& z);
        void set_direction(const double& x, const double& y, const double& z);
    public:
        Point origin;
        Vector direction;
};

