#include <World/world.hpp>

#include <Tracers/singlesphere.hpp>

World::World() 
: tracer_ptr {std::make_shared<SingleSphere>(this)}
{

}

World::~World() 
{
    
}

void World::build() 
{
    view_plane.horizontal_resolution = 200;
    view_plane.vertical_resolution = 200;
    view_plane.pixel_size = 1.0;

    sphere.set_center(0.0, 0.0, 0.0);
    sphere.set_radius(80.0);

}

void World::display_pixel(const Color& pixel_color) const 
{
    std::cout << static_cast<int>(pixel_color.get_x()) * 255 << " " 
              << static_cast<int>(pixel_color.get_y()) * 255 << " " 
              << static_cast<int>(pixel_color.get_z()) * 255 << "\n";
}

void World::render_scene() const 
{
    Color pixel_color {};
    Ray ray {};
    double z {100.0};
    double x, y;

    ray.set_direction(0, 0, -1);

    std::cout << "P3\n" << view_plane.vertical_resolution << ' ' << view_plane.horizontal_resolution << "\n255\n";

    for (int i = 0; i < view_plane.vertical_resolution; i++) {
        for (int j = 0; j < view_plane.horizontal_resolution; j++) { 
            x = view_plane.pixel_size * (j - 0.5 * (view_plane.horizontal_resolution - 1.0));
            y = view_plane.pixel_size * (i - 0.5 * (view_plane.vertical_resolution -   1.0));
            ray.set_origin(x, y, z);
            pixel_color = tracer_ptr->trace_ray(ray);
            display_pixel(pixel_color);
        }    
    }
}