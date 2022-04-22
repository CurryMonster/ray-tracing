#pragma once

#include <iostream>
#include <Utilities/vector.hpp>

class Point 
{
    friend Point operator+(const Point& rhs, const Vector& lhs);
    public:
        Point(const double& x, const double& y, const double& z);
        double get_x() const;
        double get_y() const;
        double get_z() const;
        void set_x(const double& x);
        void set_y(const double& y);
        void set_z(const double& z);
        Vector operator-(const Point& rhs) const;
    private:
        double x;
        double y;
        double z;
};
