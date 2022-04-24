#include "BRDFs/lambertian.hpp"
#include "Utilities/math.hpp"

Lambertian::Lambertian() : BRDF(), diffuse_reflection_coefficient {}, diffuse_color {}
{

}

Lambertian::~Lambertian() 
{

}

Color Lambertian::f(const Record& record, const Vector& incoming_direction, const Vector& reflected_direction) const
{
    return diffuse_reflection_coefficient * diffuse_color * inverse_pi;
}
    
Color Lambertian::reflectance(const Record& record, const Vector& reflected_direction) const
{
    return diffuse_reflection_coefficient * diffuse_color;
}