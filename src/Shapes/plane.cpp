#include "Shapes/plane.hpp"

Plane::Plane() : point {}, normal {}
{

}

Plane::Plane(const Point& point, const Normal& normal) : point {point}, normal {normal}
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
    point.x = x;
    point.y = y;
    point.z = z;
}

void Plane::set_normal(const double& x, const double& y, const double& z)
{
    normal.x = x;
    normal.y = y;
    normal.z = z;
}

bool Plane::hit(const Ray& ray, double& t_m, Record& record) const
{
    double t = (point - ray.origin) * normal / (ray.direction * normal); 

    if (t > 0.00001) 
    {
        t_m                    = t;
        record.normal          = normal;
        record.local_hit_point = ray.origin + t * ray.direction;
        return true;
    }
    else 
    {
        return false;
    }
}