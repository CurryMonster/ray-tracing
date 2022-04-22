#pragma once

#include <iostream>

class Color
{
    public:
        Color();
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

const Color black {0.0, 0.0, 0.0};
const Color white {1.0, 1.0, 1.0};
const Color red {1.0, 0.0, 0.0};
const Color lime {0.0, 1.0, 0.0};
const Color blue {0.0, 0.0, 1.0};
const Color yellow {1.0, 1.0, 0.0};