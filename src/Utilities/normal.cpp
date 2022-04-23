#include <Utilities/normal.hpp>

Normal::Normal() : x {0.0}, y {0.0}, z {0.0}
{

}


Normal::Normal(const double& x, const double& y, const double& z)
: x {x}, y {y}, z {z}
{

}

double Normal::get_x() const 
{
    return x;
}

double Normal::get_y() const
{
    return y;
}

double Normal::get_z() const 
{
    return z;
}

void Normal::set_x(const double& x)
{
    this->x = x;
}
    
void Normal::set_y(const double& y) 
{
    this->y = y;
}

void Normal::set_z(const double& z)
{
    this->z = z;
}

double operator*(const Normal& lhs, const Vector& rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

double operator*(const Vector& lhs, const Normal& rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}

Normal& Normal::operator=(const Vector& rhs)
{
    x = rhs.x;
    y = rhs.y;
    z = rhs.z;
    return *this;
}