#include "Cameras/pinhole.hpp"
#include "Utilities/color.hpp"
#include "World/viewplane.hpp"
#include "World/world.hpp"
#include "Tracers/tracer.hpp"
#include "Tracers/multiple-objects.hpp"
#include "Samplers/sampler.hpp"
#include "Samplers/jittered.hpp"

Pinhole::Pinhole() : Camera(), distance {0.0}, zoom_factor {2.0}
{

}

Pinhole::~Pinhole()
{

}

double Pinhole::get_distance() const
{
    return distance;
}

double Pinhole::get_zoom_factor() const
{
    return zoom_factor;
}

void Pinhole::Pinhole::set_view_distance(const double& distance)
{
    this->distance = distance;
}

void Pinhole::Pinhole::set_zoom_factor(const double& zoom_factor) 
{
    this->zoom_factor = zoom_factor;
}

Vector Pinhole::ray_direction(const Point& point) const
{
    Vector direction {point.x * u + point.y * v - distance * w};

    direction.normalize();

    return direction;
}

void Pinhole::render_scene(World* world_ptr, SDL_Renderer* renderer)
{
    Color radiance {};

    ViewPlane view_plane  {world_ptr->view_plane};
    
    Ray   ray        {};
    Point sp_unit_sq {};
    Point sp_px      {};

    //view_plane.pixel_size /= 0.25;

    ray.origin = eye;

    SDL_RenderClear(renderer);

    for (int i {0}; i < view_plane.vertical_resolution; i++)
    {
        for (int j {0}; j < view_plane.horizontal_resolution; j++)
        {
            radiance = black;

            for (int k {0}; k < world_ptr->sampler_ptr->no_samples; k++)
            {
                sp_unit_sq    = world_ptr->sampler_ptr->sample_unit_square();
                sp_px.x       = view_plane.pixel_size * (j - 0.5 * view_plane.horizontal_resolution + sp_unit_sq.x);
                sp_px.y       = view_plane.pixel_size * (i - 0.5 * view_plane.vertical_resolution   + sp_unit_sq.y);
                ray.direction = ray_direction(sp_px);
                radiance      += world_ptr->tracer_ptr->trace_ray(ray);
            }
            radiance /= world_ptr->sampler_ptr->no_samples;
            radiance *= exposure_time;
            world_ptr->render_pixel_color(renderer, radiance, j, i);
        }
    }
    SDL_RenderPresent(renderer);
}

