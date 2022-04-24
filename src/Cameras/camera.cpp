#include "Cameras/camera.hpp"
#include "World/world.hpp"

Camera::Camera() : eye {}, look_at {}, up {0, 1, 0}, u {}, v {}, w {}, exposure_time {2.0}
{

}

Camera::~Camera()
{

}

void Camera::set_eye(const double& x, const double& y, const double& z)
{
    eye.x = x;
    eye.y = y;
    eye.z = z;
}

void Camera::set_look_at(const double& x, const double& y, const double& z)
{
    look_at.x = x;
    look_at.y = y;
    look_at.z = z;
}

void Camera::set_up(const double& x, const double& y, const double& z)
{
    up.x = x;
    up.y = y;
    up.z = z;
}

void Camera::set_u(const double& x, const double& y, const double& z)
{
    u.x = x;
    u.y = y;
    u.z = z;
}

void Camera::set_v(const double& x, const double& y, const double& z)
{
    v.x = x;
    v.y = y;
    v.z = z;
}

void Camera::set_w(const double& x, const double& y, const double& z)
{
    w.x = x;
    w.y = y;
    w.z = z;
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

    if (eye.x == look_at.x && eye.z == look_at.z && look_at.y < eye.y)
    {
        u.x = 0.0; 
        u.y = 0.0; 
        u.z = 1.0; 

        v.x = 1.0; 
        v.y = 0.0; 
        v.z = 0.0;

        w.x = 0.0; 
        w.y = 1.0; 
        w.z = 0.0;
    }

    if (eye.x == look_at.x && eye.z == look_at.z && look_at.y > eye.y)
    {
        u.x = 1.0; 
        u.y = 0.0; 
        u.z = 0.0; 

        v.x = 0.0; 
        v.y = 0.0; 
        v.z = 1.0;

        w.x = 0.0; 
        w.y = -1.0; 
        w.z = 0.0;
    }

}