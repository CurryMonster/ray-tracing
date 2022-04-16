#include <Utilities/vector.hpp>

Vector::Vector(const double& x, const double& y, const double& z)
: x {x}, y {y}, z {z}
{

}

std::ostream& operator<<(std::ostream& os, const Vector& rhs)
{
    os << rhs.x << ", " << rhs.y << ", " << rhs.z << "\n";
    return os;
}

double Vector::get_x() const 
{
    return x;
}

double Vector::get_y() const
{
    return y;
}

double Vector::get_z() const 
{
    return z;
}

void Vector::set_x(const double& x)
{
    this->x = x;
}
    
void Vector::set_y(const double& y) 
{
    this->y = y;
}

void Vector::set_z(const double& z)
{
    this->z = z;
}

Vector Vector::operator+(const Vector& rhs) const 
{
    return Vector(x + rhs.x, y + rhs.y, z + rhs.z);
}

Vector Vector::operator/(const double& rhs) const 
{
    return Vector(x / rhs, y / rhs, z / rhs);
}

Vector operator*(const double& lhs, const Vector& rhs)
{
    return Vector(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
}

Vector operator*(const Vector& lhs, const double& rhs)
{
    return Vector(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
}

double operator*(const Vector& lhs, const Vector& rhs)
{
    return lhs.x * rhs.x + lhs.y * rhs.y + lhs.z * rhs.z;
}