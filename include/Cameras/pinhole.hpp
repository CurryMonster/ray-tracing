#pragma once

#include "Cameras/camera.hpp"
#include "Utilities/vector.hpp"
#include "Utilities/point.hpp"

class World;

class Pinhole: public Camera
{
    public:
        Pinhole();
        virtual ~Pinhole() override;

        double get_distance() const;
        double get_zoom_factor() const;
        void set_view_distance(const double&);
        void set_zoom_factor(const double&);

        virtual void render_scene(World* world_ptr, SDL_Renderer* renderer) override;
        Vector ray_direction(const Point& point) const;
    public:
        double distance;
        double zoom_factor;
};

