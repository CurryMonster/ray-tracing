#pragma once

#include <iostream>

class Vector 
{
    friend Vector operator*(const double& lhs, const Vector& rhs);
    friend Vector operator*(const Vector& lhs, const double& rhs);
    friend double operator*(const Vector& lhs, const Vector& rhs);
    public:
        Vector(const double& x, const double& y, const double& z);
        double get_x() const;
        double get_y() const;
        double get_z() const;
        void set_x(const double& x);
        void set_y(const double& y);
        void set_z(const double& z);
        Vector operator+(const Vector& rhs) const;
        Vector operator/(const double& rhs) const;
    private:
        double x;
        double y;
        double z;
};
