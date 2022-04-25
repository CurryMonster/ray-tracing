#include "BRDFs/glossy-specular-reflection.hpp"
#include <cmath>

GlossySpecularReflection::GlossySpecularReflection() : BRDF(), specular_reflection_coefficient {}, phong_exponent {}, specular_color {}
{

}

GlossySpecularReflection::~GlossySpecularReflection() 
{

}

Color GlossySpecularReflection::f(const Record& record, const Vector& incoming_direction, const Vector& reflected_direction) const 
{
    Color  radiance          {};
    Vector mirror_reflection {-1 * incoming_direction + 2.0 * record.normal * (record.normal * incoming_direction)};
    
    // if (mirror_reflection * reflected_direction > 0.0)
    // {
          radiance = specular_reflection_coefficient * std::pow(mirror_reflection * reflected_direction, phong_exponent) * specular_color;
    // }

    return radiance;
}

Color GlossySpecularReflection::reflectance(const Record& record, const Vector& reflected_direction) const
{
    return black;
}