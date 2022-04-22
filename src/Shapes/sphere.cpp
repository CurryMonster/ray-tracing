#include "Shapes/sphere.hpp"
#include "Utilities/vector.hpp"

#include <cmath>

Sphere::Sphere()
: center(0.0, 0.0, 0.0), radius(0.0)
{

}

Sphere::Sphere(const Point& center, const double& radius)
: center(center), radius(radius)
{

}

Sphere::~Sphere()
{

}

Point Sphere::get_center() const
{
    return center;
}

double Sphere::get_radius() const
{
    return radius;
}
        
void Sphere::set_center(const double& x, const double& y, const double& z)
{
    center.set_x(x);
    center.set_y(y);
    center.set_z(z);
}
        
void Sphere::set_radius(const double& radius) 
{
    this->radius = radius;
}
        
bool Sphere::hit(const Ray& ray, double& t_min, Record& record) const 
{
    double t;
    double a = ray.get_direction() * ray.get_direction();
    double b = 2.0 * (ray.get_origin() - center) * ray.get_direction();
    double c = (ray.get_origin() - center) * (ray.get_origin() - center) - radius * radius;
    double d = b * b - 4.0 * a * c;

    if (d < 0.0)
    {
        return false;
    }
    else
    {
        double e = std::sqrt(d);
        t = (-b - e) / (2.0 * a);

        if (t > 0.00001)
        {
            t_min = t;
            record.normal = (ray.get_origin() - center + t * ray.get_direction()) / radius;
            record.local_hit_point = ray.get_origin() + t * ray.get_direction();
            return true; 
        }

        t = (-b + e) / (2.0 * a);

        if (t > 0.00001)
        {
            t_min = t;
            record.normal = (ray.get_origin() - center + t * ray.get_direction()) / radius;
            record.local_hit_point = ray.get_origin() + t * ray.get_direction();
            return true; 
        }
    }
    return false;
}