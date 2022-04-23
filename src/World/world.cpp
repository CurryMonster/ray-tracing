#include "World/world.hpp"
#include "Tracers/multiple-objects.hpp"
#include "Utilities/record.hpp"
#include "Cameras/camera.hpp"
#include "Cameras/pinhole.hpp"
#include "Samplers/sampler.hpp"
#include "Samplers/jittered.hpp"

World::World() : tracer_ptr {std::make_shared<MultipleObjects>(this)}, sampler_ptr {std::make_shared<Jittered>(4)}
{

}

World::~World() 
{
    
}

void World::insert_shape(std::shared_ptr<Shape> shape)
{
    shapes.push_back(shape);
}

Record World::config_record(const Ray& ray) const
{
    Record record {this};
    double t      {0.0};
    double t_m    {1.0E6};

    for (int i {0}; i < shapes.size(); i++)
    {
        if (shapes.at(i)->hit(ray, t, record) && (t < t_m))
        {
            record.hit_an_object = true;
            t_m = t;
            record.color = shapes.at(i)->color;
        }
    }
    return record;
}

void World::build() 
{
    view_plane.horizontal_resolution = 800; // horizontal resolution must match vertical resolution!
    view_plane.vertical_resolution   = 400;
    view_plane.pixel_size            = 1.0;

    std::shared_ptr<Pinhole> pinhole_ptr = std::make_shared<Pinhole>();
    pinhole_ptr->set_eye(300, 400, 500);
    pinhole_ptr->set_look_at(0, 0, -50);
    pinhole_ptr->set_view_distance(400);
    pinhole_ptr->compute_uvw();
    camera_ptr = pinhole_ptr;

    std::shared_ptr<Sphere> sphere_1 = std::make_shared<Sphere>();
    sphere_1->set_center(0, 0, 0);
    sphere_1->set_radius(100);
    sphere_1->set_color(red);
    insert_shape(sphere_1);

    std::shared_ptr<Sphere> sphere_2 = std::make_shared<Sphere>();
    sphere_2->set_center(-250, 0, 0);
    sphere_2->set_radius(100);
    sphere_2->set_color(blue);
    insert_shape(sphere_2);

    std::shared_ptr<Sphere> sphere_3 = std::make_shared<Sphere>();
    sphere_3->set_center(250, 0, 0);
    sphere_3->set_radius(100);
    sphere_3->set_color(lime);
    insert_shape(sphere_3);

}

void World::render_pixel_color(SDL_Renderer* renderer, const Color& color, const int& x, const int& y) const 
{
    SDL_SetRenderDrawColor(renderer, 
                           static_cast<int>(color.x * 255), 
                           static_cast<int>(color.y * 255), 
                           static_cast<int>(color.z * 255), 
                           255);
    
    SDL_RenderDrawPoint(renderer, x, y);
}

void World::render_scene(SDL_Renderer* renderer) const 
{
    Color  color {};
    Ray    ray   {};

    double z {100.0};

    Point sp_unit_sq {};
    Point sp_px {0, 0, z};

    ray.set_direction(0, 0, -1);

    SDL_RenderClear(renderer);

    for (int i {0}; i < view_plane.vertical_resolution; i++) // up
    {
        for (int j {0}; j < view_plane.horizontal_resolution; j++) // across
        { 
            color = black;
            for (std::size_t k {0}; k < sampler_ptr->no_samples; k++)
            {
                sp_unit_sq = sampler_ptr->sample_unit_square();
                sp_px.x    = view_plane.pixel_size * (j - 0.5 * view_plane.horizontal_resolution + sp_unit_sq.x);
                sp_px.y    = view_plane.pixel_size * (i - 0.5 * view_plane.vertical_resolution   + sp_unit_sq.y);
                ray.origin = sp_px;
                color      += tracer_ptr->trace_ray(ray);
            }
            color /= sampler_ptr->no_samples;
            render_pixel_color(renderer, color, j, i);
        }  
    }

    SDL_RenderPresent(renderer);  
}