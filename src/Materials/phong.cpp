#include "Materials/phong.hpp"
#include "BRDFs/lambertian.hpp"
#include "BRDFs/glossy-specular-reflection.hpp"

#include "Utilities/record.hpp"
#include "world/world.hpp"

#include "Lights/ambient.hpp"
#include "Lights/point-light.hpp"

Phong::Phong() : 
    ambient_brdf  {std::make_shared<Lambertian>()},
    diffuse_brdf  {std::make_shared<Lambertian>()},
    specular_brdf {std::make_shared<GlossySpecularReflection>()}
{

}

Phong::~Phong()
{

}

void Phong::set_ambient_reflection_coefficient(const double& value)
{
    ambient_brdf->diffuse_reflection_coefficient = value;
}

void Phong::set_diffuse_reflection_coefficient(const double& value)
{
    diffuse_brdf->diffuse_reflection_coefficient = value;
}

void Phong::set_diffuse_color(const Color& color)
{
    ambient_brdf->diffuse_color = color;
    diffuse_brdf->diffuse_color = color;
}

void Phong::set_specular_reflection_coefficient(const double& value)
{
    specular_brdf->specular_reflection_coefficient = value;
}

void Phong::set_phong_exponent(const double& value)
{
    specular_brdf->phong_exponent = value;
}

void Phong::set_specular_color(const Color& color)
{
    specular_brdf->specular_color = color;
}

Color Phong::shade(Record& record)
{
    Vector reflected_direction {-1 * record.ray.direction};

    Color  reflected_radiance  {ambient_brdf->reflectance(record, reflected_direction) * record.world_ptr->light_ptr->incident_radiance(record)};

    for (std::size_t i {0}; i < record.world_ptr->lights.size(); i++)
    {
        Vector incoming_direction {record.world_ptr->lights.at(i)->direction(record)};

        double directional_product {record.normal * incoming_direction};

        if (directional_product > 0.0)
        {
            Color incident_radiance          {record.world_ptr->lights.at(i)->incident_radiance(record)};

            Color lambertian_component       {diffuse_brdf->f(record, incoming_direction, reflected_direction)};

            Color glossy_specular_component  {specular_brdf->f(record, incoming_direction, reflected_direction)};

            reflected_radiance               += (lambertian_component + glossy_specular_component) * incident_radiance * directional_product;
        }
    }

    return reflected_radiance;
}