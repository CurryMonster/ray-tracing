#include "Tracers/tracer.hpp"

Tracer::Tracer(World* world_ptr) 
: world_ptr {world_ptr}
{

}

Tracer::~Tracer()
{

}

Color Tracer::trace_ray(const Ray& ray) const
{
    return black;
}