#pragma once

#include "Utilities/point.hpp"
#include "Utilities/vector.hpp"

class World;

class Camera
{
    public:
        Camera();
        virtual ~Camera();

        void set_eye(const double& x, const double& y, const double& z);
        void set_look_at(const double& x, const double& y, const double& z);
        void set_up(const double& x, const double& y, const double& z);
        void set_u(const double& x, const double& y, const double& z);
        void set_v(const double& x, const double& y, const double& z);
        void set_w(const double& x, const double& y, const double& z);
        void set_exposure_time(const double& arg);
        
        Point get_eye() const;
        Point get_look_at() const;
        Vector get_up() const;
        Vector get_u() const;
        Vector get_v() const;
        Vector get_w() const;
        double get_exposure_time() const;

        void compute_uvw();
        virtual void render_scene(World* w) = 0;
    private:
        Point eye;
        Point look_at;
        Vector up;
        Vector u;
        Vector v;
        Vector w;
        float exposure_time;
};


        