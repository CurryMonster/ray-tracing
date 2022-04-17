#include <Tracers/singlesphere.hpp>

#include <World/world.hpp>

#include <Shapes/shape.hpp>
#include <Shapes/sphere.hpp>

#include <Utilities/record.hpp>

SingleSphere::SingleSphere(World* world_ptr)
: Tracer(world_ptr)
{

}

Color SingleSphere::trace_ray(const Ray& ray) const 
{
    Record record(world_ptr);
    double t;

    if (world_ptr->sphere.hit(ray, t, record))
    {
        return Color(1.0, 0.0, 0.0);
    }
    else 
    {
        return Color(0.0, 0.0, 1.0);
    }

}