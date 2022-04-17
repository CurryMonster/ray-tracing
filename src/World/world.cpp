#include <World/world.hpp>

#include <Tracers/singlesphere.hpp>

#include <fstream>
#include <iostream>

World::World() 
: tracer_ptr {new SingleSphere(this)}
{

}

World::~World() 
{
    delete tracer_ptr;
}

void World::build() 
{
    view.hres = 400;
    view.vres = 400;
    view.s = 0.5;
    view.gamma = 1.0;

    sphere.set_center(Point(0.0, 0.0, 0.0));
    sphere.set_radius(80.0);

}

void World::display_pixel(const Color& pixel_color) const 
{
    std::cout << static_cast<int>(pixel_color.get_x()) * 255 << " " << static_cast<int>(pixel_color.get_y()) * 255 << " " << static_cast<int>(pixel_color.get_z()) * 255 << "\n";
}

void World::render_scene() const 
{
    Color pixel_color;
    Ray ray {};
    double z = 100.0;
    double x, y;

    ray.set_direction(0, 0, -1);

    std::cout << "P3\n" << view.vres << ' ' << view.hres << "\n400\n";

    for (int i = 0; i < view.vres; i++) {
        for (int j = 0; j < view.hres; j++) { 
            x = view.s * (j - 0.5 * (view.hres - 1.0));
            y = view.s * (i - 0.5 * (view.vres - 1.0));
            ray.set_origin({x, y, z});
            pixel_color = tracer_ptr->trace_ray(ray);
            display_pixel(pixel_color);
        }    
    }
}