#include <Utilities/color.hpp>

Color::Color() : x {1.0}, y {1.0}, z {1.0}
{

}



Color::Color(const double& x, const double& y, const double& z)
: x {x}, y {y}, z {z}
{

}

double Color::get_x() const 
{
    return x;
}

double Color::get_y() const
{
    return y;
}

double Color::get_z() const 
{
    return z;
}

void Color::set_x(const double& x)
{
    this->x = x;
}
    
void Color::set_y(const double& y) 
{
    this->y = y;
}

void Color::set_z(const double& z)
{
    this->z = z;
}

Color& Color::operator+=(const Color& rhs)
{
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
}

Color& Color::operator*=(const double& rhs)
{
    x *= rhs;
    y *= rhs;
    z *= rhs;
    return *this;
}

Color& Color::operator/=(const double& rhs)
{
    x /= rhs;
    y /= rhs;
    z /= rhs;
    return *this;
}

Color operator*(const double& lhs, const Color& rhs)
{
    return Color(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
}

Color operator*(const Color& lhs, const double& rhs)
{
    return Color(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
}

Color Color::operator*(const Color& rhs) const
{
    return Color(x * rhs.x, y * rhs.y, z * rhs.z);
}

Color Color::operator+(const Color& rhs) const
{
    return Color(x + rhs.x, y + rhs.y, z + rhs.z);
}