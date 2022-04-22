#include <Utilities/point.hpp>

Point::Point() : x {0}, y {0}, z {0}
{
    
}

Point::Point(const double& x, const double& y, const double& z)
: x {x}, y {y}, z {z}
{

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

Vector Point::operator-(const Point& rhs) const
{
    return Vector(x - rhs.x, y - rhs.y, z - rhs.z);
}

Point operator+(const Point& lhs, const Vector& rhs)
{
    return Point(lhs.get_x() + rhs.get_x(), lhs.get_y() + rhs.get_y(), lhs.get_z() + rhs.get_z());
}