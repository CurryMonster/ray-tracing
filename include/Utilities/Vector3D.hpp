#pragma once

#include <iostream>

class Vector3D 
{
    friend std::ostream& operator<<(std::ostream& os, const Vector3D& rhs);
    public:
        Vector3D(const double& x, const double& y, const double& z);
        double get_x() const;
        double get_y() const;
        double get_z() const;
        void set_x(const double& x);
        void set_y(const double& y);
        void set_z(const double& z);
    private:
        double x_;
        double y_;
        double z_;
};