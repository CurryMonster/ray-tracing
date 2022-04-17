#pragma once

#include <World/viewplane.hpp>
#include <Utilities/color.hpp>
#include <Shapes/sphere.hpp>

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
        void render_scene() const;
        void display_pixel(const Color& pixel_color) const;

        
};

