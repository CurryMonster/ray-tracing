#pragma once

#include <iostream>

class Vector 
{
    friend std::ostream& operator<<(std::ostream& os, const Vector& rhs);
    public:
        Vector(const double& x, const double& y, const double& z);
        double get_x() const;
        double get_y() const;
        double get_z() const;
        void set_x(const double& x);
        void set_y(const double& y);
        void set_z(const double& z);
        Vector operator+(const Vector& rhs) const;
    private:
        double x;
        double y;
        double z;
};