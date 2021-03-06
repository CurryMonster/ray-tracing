#include <Utilities/ray.hpp>

Ray::Ray()
: origin {0, 0, 0}, direction {0, 0, 0}
{

}

Ray::Ray(const Point& origin, const Vector& direction)
: origin {origin}, direction {direction}
{

}

Point Ray::get_origin() const
{
    return origin;
}

Vector Ray::get_direction() const
{
    return direction;
}

void Ray::set_origin(const Point& point)
{
    origin = point;
}

void Ray::set_direction(const Vector& vector)
{
    direction = vector;
}

void Ray::set_origin(const double& x, const double& y, const double& z)
{
    origin.set_x(x);
    origin.set_y(y);
    origin.set_z(z);
}

void Ray::set_direction(const double& x, const double& y, const double& z)
{
    direction.x = x;
    direction.y = y;
    direction.z = z;
}