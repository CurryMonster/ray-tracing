#include "World/world.hpp"
#include "Tracers/multiple-objects.hpp"
#include "Utilities/record.hpp"

World::World() 
: tracer_ptr {std::make_shared<MultipleObjects>(this)}
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
    double t {};
    double t_min {1.0E6};

    for (int i {0}; i < shapes.size(); i++)
    {
        if (shapes.at(i)->hit(ray, t, record) && (t < t_min))
        {
            record.hit_an_object = true;
            t_min = t;
            record.color = shapes.at(i)->get_color();
        }
    }
    return record;
}

void World::build() 
{
    view_plane.horizontal_resolution = 500; // horizontal resolution must match vertical resolution!
    view_plane.vertical_resolution   = 500;
    view_plane.pixel_size            = 1.0;

    std::shared_ptr<Sphere> sphere_1 = std::make_shared<Sphere>();
    sphere_1->set_center(0, -125, 0);
    sphere_1->set_radius(100);
    sphere_1->set_color(red);
    insert_shape(sphere_1);

    std::shared_ptr<Sphere> sphere_2 = std::make_shared<Sphere>();
    sphere_2->set_center(100, 0, 125);
    sphere_2->set_radius(100);
    sphere_2->set_color(blue);
    insert_shape(sphere_2);

    std::shared_ptr<Sphere> sphere_3 = std::make_shared<Sphere>();
    sphere_3->set_center(-100, 0, 125);
    sphere_3->set_radius(100);
    sphere_3->set_color(lime);
    insert_shape(sphere_3);
}

void World::display_pixel(SDL_Renderer* renderer, const Color& color, const int& x, const int& y) const 
{
    SDL_SetRenderDrawColor(renderer, 
                           static_cast<int>(color.get_x() * 255), 
                           static_cast<int>(color.get_y() * 255), 
                           static_cast<int>(color.get_z() * 255), 
                           255);

    SDL_RenderDrawPoint(renderer, x, y);
}

void World::render_scene(SDL_Renderer* renderer) const 
{
    Color color;
    Ray ray {};
    double x {};
    double y {};
    double z {100};

    ray.set_direction(0, 0, -1);

    SDL_RenderClear(renderer);

    for (int i = 0; i < view_plane.vertical_resolution; i++) 
    {
        for (int j = 0; j < view_plane.horizontal_resolution; j++) 
        { 
            x = view_plane.pixel_size * (j - 0.5 * (view_plane.horizontal_resolution - 1.0));
            y = view_plane.pixel_size * (i - 0.5 * (view_plane.vertical_resolution   - 1.0));
            ray.set_origin(x, y, z);
            color = tracer_ptr->trace_ray(ray);
            display_pixel(renderer, color, j, i);
        }    
    }

    SDL_RenderPresent(renderer);
}