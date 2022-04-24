#include "Lights/ambient.hpp"

Ambient::Ambient() : Light(), radiance_scaling_factor {1.0}, color {white}
{

}

Ambient::~Ambient()
{

}

Color Ambient::incident_radiance(Record& record)
{
    return radiance_scaling_factor * color;
}

Vector Ambient::direction(Record& record)
{
    return Vector(0, 0, 0);
}