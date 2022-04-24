#include "Materials/matte.hpp"
#include "Utilities/vector.hpp"
#include "World/world.hpp"
#include "Lights/ambient.hpp"
#include "Lights/point-light.hpp"
#include "BRDFs/lambertian.hpp"
#include "Materials/matte.hpp"

Matte::Matte() : Material(), ambient_brdf {std::make_shared<Lambertian>()}, diffuse_brdf {std::make_shared<Lambertian>()}
{

}

Matte::~Matte()
{
    
}

void Matte::set_ambient_reflection_coefficient(const double& value)
{
    ambient_brdf->diffuse_reflection_coefficient = value;
}

void Matte::set_diffuse_reflection_coefficient(const double& value)
{
    diffuse_brdf->diffuse_reflection_coefficient = value;
}

void Matte::set_diffuse_color(const Color& color)
{
    ambient_brdf->diffuse_color = color;
    diffuse_brdf->diffuse_color = color;
}

Color Matte::shade(Record& record)
{
    Vector reflected_direction {-1 * record.ray.direction};
    Color  reflected_radiance  {ambient_brdf->reflectance(record, reflected_direction) * record.world_ptr->light_ptr->incident_radiance(record)};

    for (std::size_t i {0}; i < record.world_ptr->lights.size(); i++) 
    {
        Vector incoming_direction {record.world_ptr->lights.at(i)->direction(record)};

        if (record.normal * incoming_direction > 0.0)
        {
            Color incident_radiance {record.world_ptr->lights.at(i)->incident_radiance(record)};
            reflected_radiance += diffuse_brdf->f(record, reflected_direction, incoming_direction) * incident_radiance * (record.normal * incoming_direction);
        }
    }
    
    return reflected_radiance;
}