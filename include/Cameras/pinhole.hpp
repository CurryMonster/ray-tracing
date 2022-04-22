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

        double get_view_distance() const;
        double get_zoom_factor() const;
        void set_view_distance(const double&);
        void set_zoom_factor(const double&);

        virtual void render_scene(World* world_ptr);
        Vector get_ray_direction(const Point& point) const;
    private:
        double view_distance;
        double zoom_factor;
};

Pinhole::Pinhole() : Camera(), view_distance {}, zoom_factor {2.0}
{

}

Pinhole::~Pinhole()
{

}

double Pinhole::get_view_distance() const
{
    return view_distance;
}

double Pinhole::get_zoom_factor() const
{
    return zoom_factor;
}

void Pinhole::Pinhole::set_view_distance(const double& view_distance)
{
    this->view_distance = view_distance;
}

void Pinhole::Pinhole::set_zoom_factor(const double& zoom_factor) 
{
    this->zoom_factor = zoom_factor;
}