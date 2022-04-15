#pragma once

#include <iostream>

class Color
{
    friend std::ostream& operator<<(std::ostream& os, const Color& rhs);
    public:
        Color(const double& x, const double& y, const double& z);
        double get_x() const;
        double get_y() const;
        double get_z() const;
        void set_x(const double& x);
        void set_y(const double& y);
        void set_z(const double& z);
    private:
        double x;
        double y;
        double z;
};