#include "Cameras/camera.hpp"
#include "World/world.hpp"

Camera::Camera() : eye {}, look_at {}, up {0, 1, 0}, u {}, v {}, w {}, exposure_time {1.0}
{

}

Camera::~Camera()
{

}

void Camera::set_eye(const double& x, const double& y, const double& z)
{
    eye.set_x(x);
    eye.set_y(y);
    eye.set_z(z);
}

void Camera::set_look_at(const double& x, const double& y, const double& z)
{
    look_at.set_x(x);
    look_at.set_y(y);
    look_at.set_z(z);
}

void Camera::set_up(const double& x, const double& y, const double& z)
{
    up.set_x(x);
    up.set_y(y);
    up.set_z(z);
}

void Camera::set_u(const double& x, const double& y, const double& z)
{
    u.set_x(x);
    u.set_y(y);
    u.set_z(z);
}

void Camera::set_v(const double& x, const double& y, const double& z)
{
    v.set_x(x);
    v.set_y(y);
    v.set_z(z);
}

void Camera::set_w(const double& x, const double& y, const double& z)
{
    w.set_x(x);
    w.set_y(y);
    w.set_z(z);
}

void Camera::set_exposure_time(const double& exposure_time)
{
    this->exposure_time = exposure_time;
}
        
Point Camera::get_eye() const
{
    return eye;
}

Point Camera::get_look_at() const
{
    return look_at;
}

Vector Camera::get_up() const
{
    return up;
}
    
Vector Camera::get_u() const
{
    return u; 
}

Vector Camera::get_v() const
{
    return v;
}   

Vector Camera::get_w() const
{
    return w;
}

double Camera::get_exposure_time() const
{
    return exposure_time;
}

void Camera::compute_uvw()
{
    w =  eye - look_at;
    w.normalize();
    u = up ^ w;
    u.normalize();
    v = w ^ u;

    if (eye.get_x() == look_at.get_x() && eye.get_z() == look_at.get_z() && look_at.get_y() < eye.get_y())
    {
        u.set_x(0); 
        u.set_y(0); 
        u.set_z(1); 

        v.set_x(1); 
        v.set_y(0); 
        v.set_z(0);

        w.set_x(0); 
        w.set_y(1); 
        w.set_z(0);
    }

    if (eye.get_x() == look_at.get_x() && eye.get_z() == look_at.get_z() && look_at.get_y() > eye.get_y())
    {
        u.set_x(1); 
        u.set_y(0); 
        u.set_z(0); 

        v.set_x(0); 
        v.set_y(0); 
        v.set_z(1);

        w.set_x(0); 
        w.set_y(-1); 
        w.set_z(0);
    }

}