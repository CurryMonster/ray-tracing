#include "World/world.hpp"

#include "Tracers/tracer.hpp"

#include "Utilities/record.hpp"

#include "Cameras/camera.hpp"
#include "Cameras/pinhole.hpp"

#include "Samplers/sampler.hpp"
#include "Samplers/jittered.hpp"

#include "Lights/light.hpp"
#include "Lights/ambient.hpp"
#include "Lights/point-light.hpp"

#include "Shapes/shape.hpp"
#include "Shapes/plane.hpp"
#include "Shapes/sphere.hpp"

#include "Materials/material.hpp"
#include "Materials/matte.hpp"
#include "Materials/phong.hpp"

World::World() : 
    background  {black},
    tracer_ptr  {std::make_shared<Tracer>(this)}, 
    sampler_ptr {std::make_shared<Jittered>(4)}
{

}

World::~World() 
{
    
}

void World::insert_shape(std::shared_ptr<Shape> shape)
{
    shapes.push_back(shape);
}

void World::insert_light(std::shared_ptr<Light> light)
{
    lights.push_back(light);
}

Record World::config_record(const Ray& ray) const
{
    Record record          {this};
    double t               {0.0};
    Normal normal          {};
    Point  local_hit_point {};
    double t_m             {1.0E6};

    for (int i {0}; i < shapes.size(); i++)
    {
        if (shapes.at(i)->hit(ray, t, record) && (t < t_m))
        {
            record.hit_an_object = true;
            t_m                  = t;
            record.material_ptr  = shapes.at(i)->material_ptr;
            record.hit_point     = ray.origin + t * ray.direction;
            normal               = record.normal;
            local_hit_point      = record.local_hit_point;
        }
    }

    if (record.hit_an_object)
    {
        record.t               = t_m;
        record.normal          = normal;
        record.local_hit_point = local_hit_point;
    }

    return record;
}

void World::build() 
{
    view_plane.horizontal_resolution = 850; 
    view_plane.vertical_resolution   = 600;
    view_plane.pixel_size            = 1.0;

    std::shared_ptr<Ambient> ambient_ptr = std::make_shared<Ambient>();
    ambient_ptr->radiance_scaling_factor = 1.0;
    light_ptr = ambient_ptr;

    std::shared_ptr<Pinhole> pinhole_ptr = std::make_shared<Pinhole>();
    pinhole_ptr->set_eye(0, 0, 300);
    pinhole_ptr->set_look_at(0, 0, 0);
    pinhole_ptr->set_view_distance(500);
    pinhole_ptr->compute_uvw();
    camera_ptr = pinhole_ptr;

    std::shared_ptr<PointLight> point_light = std::make_shared<PointLight>();
    point_light->set_location(-100, -100, 300);
    point_light->radiance_scaling_factor = 2.0;
    point_light->color = white;
    insert_light(point_light);

    std::shared_ptr<Phong> phong_1 = std::make_shared<Phong>();
    phong_1->set_ambient_reflection_coefficient(0.25);
    phong_1->set_diffuse_reflection_coefficient(0.5);
    phong_1->set_diffuse_color(red);
    phong_1->set_specular_color(white);
    phong_1->set_phong_exponent(50);
    phong_1->set_specular_reflection_coefficient(0.5);

    std::shared_ptr<Sphere> sphere_1 = std::make_shared<Sphere>();
    sphere_1->set_center(0,  0, 100);
    sphere_1->set_radius(50);
    sphere_1->set_material(phong_1);
    insert_shape(sphere_1);

    std::shared_ptr<Phong> phong_2 = std::make_shared<Phong>();
    phong_2->set_ambient_reflection_coefficient(0.25);
    phong_2->set_diffuse_reflection_coefficient(0.5);
    phong_2->set_diffuse_color(blue);
    phong_2->set_specular_color(white);
    phong_2->set_phong_exponent(50);
    phong_2->set_specular_reflection_coefficient(0.5);

    std::shared_ptr<Sphere> sphere_2 = std::make_shared<Sphere>();
    sphere_2->set_center(-115, 30, 80);
    sphere_2->set_radius(50);
    sphere_2->set_material(phong_2);
    insert_shape(sphere_2);

    std::shared_ptr<Phong> phong_3 = std::make_shared<Phong>();
    phong_3->set_ambient_reflection_coefficient(0.25);
    phong_3->set_diffuse_reflection_coefficient(0.5);
    phong_3->set_diffuse_color(yellow);
    phong_3->set_specular_color(white);
    phong_3->set_phong_exponent(50);
    phong_3->set_specular_reflection_coefficient(0.5);

    std::shared_ptr<Sphere> sphere_3 = std::make_shared<Sphere>();
    sphere_3->set_center(100, -30, 100);
    sphere_3->set_radius(50);
    sphere_3->set_material(phong_3);
    insert_shape(sphere_3);

}

void World::render_pixel_color(SDL_Renderer* renderer, Color& color, const int& x, const int& y) const
{
    double value = std::max(color.x, std::max(color.y, color.z));
    if (value > 1.0)
    {
        color /= value;
    }

    SDL_SetRenderDrawColor(renderer, 
                           static_cast<int>(color.x * 255), 
                           static_cast<int>(color.y * 255), 
                           static_cast<int>(color.z * 255), 
                           255);
    
    SDL_RenderDrawPoint(renderer, x, y);
}