#pragma once

#include "World/viewplane.hpp"
#include "Shapes/shape.hpp"
#include "Shapes/sphere.hpp"
#include "Utilities/color.hpp"
#include "SDL.h"

#include <memory>
#include <vector>

class Tracer;
class Camera;
class Sampler;
class Record;

class World 
{
    public:
        ViewPlane view_plane;
        Sphere sphere;
        std::shared_ptr<Tracer> tracer_ptr;
        std::vector<std::shared_ptr<Shape>> shapes;
        std::shared_ptr<Camera> camera_ptr;
        std::shared_ptr<Sampler> sampler_ptr;

        World();
        ~World();

        void build();
        void render_scene(SDL_Renderer* renderer) const;
        void render_pixel_color(SDL_Renderer* renderer, const Color& pixel_color, const int& x, const int& y) const;     

        void insert_shape(std::shared_ptr<Shape>);
        Record config_record(const Ray& ray) const;
};

