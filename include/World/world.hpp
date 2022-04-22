#pragma once

#include "World/viewplane.hpp"
#include "Shapes/sphere.hpp"
#include "Utilities/color.hpp"
#include "SDL.h"

#include <memory>

class Tracer;

class World 
{
    public:
        ViewPlane view_plane;
        Sphere sphere;
        std::shared_ptr<Tracer> tracer_ptr;

        World();
        ~World();

        void build();
        void render_scene(SDL_Renderer* renderer) const;
        void display_pixel(SDL_Renderer* renderer, const Color& pixel_color, const int& x, const int& y) const;     
};

