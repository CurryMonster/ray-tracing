#include <Utilities/Vector3D.hpp>

Vector3D::Vector3D(const double& x, const double& y, const double& z) : x_{x}, y_{y}, z_{z} 
{

}

double Vector3D::get_x() const 
{
    return x_;
}

double Vector3D::get_y() const 
{
    return y_;
}

double Vector3D::get_z() const 
{
    return z_;
}

void Vector3D::set_x(const double& x) 
{
    x_ = x;
}

void Vector3D::set_y(const double& y) 
{
    y_ = y;
}

void Vector3D::set_z(const double& z) 
{
    z_ = z;
}

std::ostream& operator<<(std::ostream& os, const Vector3D& rhs) 
{
    os << rhs.x_ << ", " << rhs.y_ << ", " << rhs.z_ << "\n";
    return os;
}