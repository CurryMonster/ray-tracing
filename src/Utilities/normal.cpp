#include <Utilities/normal.hpp>

Normal::Normal(const double& x, const double& y, const double& z)
: x {x}, y {y}, z {z}
{

}

std::ostream& operator<<(std::ostream& os, const Normal& rhs)
{
    os << rhs.x << ", " << rhs.y << ", " << rhs.z << "\n";
    return os;
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
    return lhs.get_x() * rhs.get_x() + lhs.get_y() * rhs.get_y() + lhs.get_z() * rhs.get_z();
}

double operator*(const Vector& lhs, const Normal& rhs)
{
    return lhs.get_x() * rhs.get_x() + lhs.get_y() * rhs.get_y() + lhs.get_z() * rhs.get_z();
}

Normal& Normal::operator=(const Vector& rhs)
{
    x = rhs.get_x();
    y = rhs.get_y();
    z = rhs.get_z();
    return *this;
}