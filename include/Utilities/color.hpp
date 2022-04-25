#pragma once

#include <iostream>

class Color
{
    friend Color operator*(const double& lhs, const Color& rhs);
    friend Color operator*(const Color& lhs, const double& rhs);
    public:
        Color();
        Color(const double& x, const double& y, const double& z);
        double get_x() const;
        double get_y() const;
        double get_z() const;
        void set_x(const double& x);
        void set_y(const double& y);
        void set_z(const double& z);
        Color operator+(const Color& rhs) const;
        Color& operator+=(const Color& rhs);
        Color& operator*=(const double& rhs);
        Color& operator/=(const double& rhs);
        Color operator*(const Color& rhs) const;
    public:
        double x;
        double y;
        double z;
};

const Color black  {0.0, 0.0, 0.0};
const Color white  {1.0, 1.0, 1.0};
const Color red    {1.0, 0.0, 0.0};
const Color lime   {0.0, 1.0, 0.0};
const Color blue   {0.0, 0.0, 1.0};
const Color yellow {1.0, 1.0, 0.0};
const Color green  {0.0, 0.35, 0.0};
const Color silver {0.75, 0.75, 0.75};
const Color smoke  {0.96, 0.96, 0.96};
const Color midnight {0.098, 0.098, 0.439};