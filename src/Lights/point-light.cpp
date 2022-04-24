#include "Lights/point-light.hpp"

PointLight::PointLight() : Light(), radiance_scaling_factor {}, color {}, location {}
{

}

PointLight::~PointLight()
{

}

Color PointLight::incident_radiance(Record& record) 
{
    return radiance_scaling_factor * color;
}

void PointLight::set_location(const double& x, const double& y, const double& z)
{
    location.x = x;
    location.y = y;
    location.z = z;
}

Vector PointLight::direction(Record& record)
{
    Vector vector {location - record.hit_point};

    vector.normalize();

    return vector;
}