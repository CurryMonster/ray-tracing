#pragma once

#include <World/view.hpp>
#include <Utilities/color.hpp>
#include <Shapes/sphere.hpp>

#include <memory>

class Tracer;

class World 
{
    public:
        View view;
        Color background_color;
        Sphere sphere;
        Tracer* tracer_ptr;

        World();
        ~World();

        void build();
        void render_scene() const;
        void display_pixel(const Color& pixel_color) const;

        
};

