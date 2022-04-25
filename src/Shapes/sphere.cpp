#include "Shapes/sphere.hpp"
#include "Utilities/vector.hpp"

#include <cmath>

Sphere::Sphere() : center {}, radius {0.0}
{

}

Sphere::Sphere(const Point& center, const double& radius) : center {center}, radius {radius}
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
    center.x = x;
    center.y = y;
    center.z = z;
}
        
void Sphere::set_radius(const double& radius) 
{
    this->radius = radius;
}
        
bool Sphere::hit(const Ray& ray, double& t_min, Record& record) const 
{
    double t       {0.0};
    const double a {ray.direction * ray.direction};
    const double b {2.0 * (ray.origin - center) * ray.direction};
    const double c {(ray.origin - center) * (ray.origin - center) - radius * radius};
    const double d {b * b - 4.0 * a * c};

    if (d < 0.0)
    {
        return false;
    }
    else
    {
        double e {std::sqrt(d)};
        t = (-b - e) / (2.0 * a);

        if (t > 0.00001)
        {
            t_min                  = t;
            record.normal          = (ray.origin - center + t * ray.direction) / radius;
            record.local_hit_point = ray.origin + t * ray.direction;
            return true; 
        }

        t = (-b + e) / (2.0 * a);

        if (t > 0.00001)
        {
            t_min                  = t;
            record.normal          = (ray.origin - center + t * ray.direction) / radius;
            record.local_hit_point = ray.origin + t * ray.direction;
            return true; 
        }
    }
    return false;
}