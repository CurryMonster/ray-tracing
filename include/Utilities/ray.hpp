#pragma once 

#include <Utilities/point.hpp>
#include <Utilities/vector.hpp>

class Ray {
    public:
        Ray(const Point& origin, const Vector& direction);
        Point get_origin() const;
        Vector get_direction() const;
        void set_origin(const Point& origin);
        void set_direction(const Vector& direction);
    private:
        Point origin;
        Vector direction;
};

