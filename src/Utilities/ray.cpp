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

void Ray::set_origin(const Point& origin)
{
    this->origin = origin;
}

void Ray::set_direction(const double& x, const double& y, const double& z)
{
    direction.set_x(x);
    direction.set_y(y);
    direction.set_z(z);
}