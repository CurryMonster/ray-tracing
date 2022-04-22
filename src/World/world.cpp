#include "World/world.hpp"
#include "Tracers/singlesphere.hpp"

World::World() 
: tracer_ptr {std::make_shared<SingleSphere>(this)}
{

}

World::~World() 
{
    
}

void World::build() 
{
    view_plane.horizontal_resolution = 500; // horizontal resolution must match vertical resolution!
    view_plane.vertical_resolution   = 500;
    view_plane.pixel_size            = 1.0;

    sphere.set_center(0.0, 0.0, 0.0);
    sphere.set_radius(100.0);

}

void World::display_pixel(SDL_Renderer* renderer, const Color& pixel_color, const int& x, const int& y) const 
{
    SDL_SetRenderDrawColor(renderer, static_cast<int>(pixel_color.get_x() * 255), static_cast<int>(pixel_color.get_y() * 255), static_cast<int>(pixel_color.get_z() * 255), 255);
    SDL_RenderDrawPoint(renderer, x, y);
}

void World::render_scene(SDL_Renderer* renderer) const 
{
    Color pixel_color {};
    Ray ray {};

    ray.set_direction(0.0, 0.0, -1.0);

    SDL_RenderClear(renderer);

    for (int i = 0; i < view_plane.vertical_resolution; i++) 
    {
        for (int j = 0; j < view_plane.horizontal_resolution; j++) 
        { 
            double x = view_plane.pixel_size * (j - 0.5 * (view_plane.horizontal_resolution - 1.0));
            double y = view_plane.pixel_size * (i - 0.5 * (view_plane.vertical_resolution   - 1.0));
            ray.set_origin(x, y, 100.0);
            pixel_color = tracer_ptr->trace_ray(ray);
            display_pixel(renderer, pixel_color, i, j);
        }    
    }
    SDL_RenderPresent(renderer);
}