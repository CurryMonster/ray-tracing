#pragma once

#include <iostream>
#include <Utilities/vector.hpp>

class Normal 
{
    friend double operator*(const Normal& lhs, const Vector& rhs);
    friend double operator*(const Vector& lhs, const Normal& rhs);
    public:
        Normal(const double& x, const double& y, const double& z);
        double get_x() const;
        double get_y() const;
        double get_z() const;
        void set_x(const double& x);
        void set_y(const double& y);
        void set_z(const double& z);
        Normal& operator=(const Vector& rhs);
    private:
        double x;
        double y;
        double z;
};