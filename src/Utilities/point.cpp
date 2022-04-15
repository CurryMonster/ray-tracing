#include <Utilities/point.hpp>

Point::Point(const double& x, const double& y, const double& z)
: x {x}, y {y}, z {z}
{

}

std::ostream& operator<<(std::ostream& os, const Point& rhs)
{
    os << rhs.x << ", " << rhs.y << ", " << rhs.z << "\n";
    return os;
}

double Point::get_x() const 
{
    return x;
}

double Point::get_y() const
{
    return y;
}

double Point::get_z() const 
{
    return z;
}

void Point::set_x(const double& x)
{
    this->x = x;
}
    
void Point::set_y(const double& y) 
{
    this->y = y;
}

void Point::set_z(const double& z)
{
    this->z = z;
}