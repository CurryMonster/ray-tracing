#include "Shapes/plane.hpp"

Plane::Plane() : point {0, 0, 0}, normal {0, 0, 0}
{

}

Plane::Plane(const Point& point, const Normal& normal) 
: point {point}, normal {normal}
{

}

Plane::~Plane()
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

void Plane::set_point(const double& x, const double& y, const double& z)
{
    point.set_x(x);
    point.set_y(y);
    point.set_z(z);
}

void Plane::set_normal(const double& x, const double& y, const double& z)
{
    normal.set_x(x);
    normal.set_y(y);
    normal.set_z(z);
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