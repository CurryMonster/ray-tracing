#include <Utilities/Point3D.hpp>

Point3D::Point3D(const double& x, const double& y, const double& z) : x_{x}, y_{y}, z_{z} 
{

}

double Point3D::get_x() const 
{
    return x_;
}

double Point3D::get_y() const 
{
    return y_;
}

double Point3D::get_z() const 
{
    return z_;
}

void Point3D::set_x(const double& x) 
{
    x_ = x;
}

void Point3D::set_y(const double& y) 
{
    y_ = y;
}

void Point3D::set_z(const double& z) 
{
    z_ = z;
}

std::ostream& operator<<(std::ostream& os, const Point3D& rhs) 
{
    os << rhs.x_ << ", " << rhs.y_ << ", " << rhs.z_ << "\n";
    return os;
}