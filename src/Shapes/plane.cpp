#include "Shapes/plane.hpp"

Plane::Plane(const Point& point, const Normal& normal) 
: point {point}, normal {normal}
{

}

Point Plane::get_point() const
{
    return point;
}

Normal Plane::get_normal() const
{
    return normal;
}

void Plane::set_point(const Point& point)
{
    this->point = point;
}

void Plane::set_normal(const Normal& normal)
{
    this->normal = normal;
}

bool Plane::hit(const Ray& ray, double& t_min, Record& rec) const
{
    double t = (point - ray.get_origin()) * normal / (ray.get_direction() * normal); 
    if (t > 0.00001) 
    {
        t_min = t;
        rec.normal = normal;
        rec.local_hit_point = ray.get_origin() + t * ray.get_direction();
        return true;
    }
    else 
    {
        return false;
    }
}