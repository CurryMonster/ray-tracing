#include <World/world.hpp>

#include <Tracers/tracer.hpp>
#include <Tracers/singlesphere.hpp>

World::World() 
: tracer_ptr {new SingleSphere(this)}
{

}

World::~World() 
{
    if (tracer_ptr != nullptr) 
        delete tracer_ptr;
}

void World::build() 
{
    view.hres = 200;
    view.vres = 200;
    view.s = 1.0;
    view.gamma = 1.0;

    background_color = Color(0, 0, 0);

    sphere.set_center(Point(0.0, 0.0, 0.0));
    sphere.set_radius(0.0);

}

void World::display_pixel(const Color& pixel_color) const 
{
    std::cout << pixel_color.get_x() << " " << pixel_color.get_y() << " " << pixel_color.get_z() << "\n";
}

void World::render_scene() const 
{
    Color pixel_color;
    Ray ray({0, 0, 0}, {0, 0, 0});
    double z = 100.0;
    double x, y;

    ray.set_direction(Vector(0, 0, 0));

    for (int i = 0; i < view.vres; i++) {// up
        for (int j = 0; j < view.hres; j++) { // across
            x = view.s * (j - 0.5 * (view.hres - 1.0));
            y = view.s * (i - 0.5 * (view.vres - 1.0));
            ray.set_origin(Point(x, y, z));
            pixel_color = tracer_ptr->trace_ray(ray);
        display_pixel(pixel_color);
        }    
    }
}