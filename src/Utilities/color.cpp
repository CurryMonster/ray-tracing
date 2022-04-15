#include <Utilities/color.hpp>

Color::Color(const double& x, const double& y, const double& z)
: x {x}, y {y}, z {z}
{

}

std::ostream& operator<<(std::ostream& os, const Color& rhs)
{
    os << rhs.x << ", " << rhs.y << ", " << rhs.z << "\n";
    return os;
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