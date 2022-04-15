#include <Utilities/ray.hpp>

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

void Ray::set_direction(const Vector& direction)
{
    this->direction = direction;
}