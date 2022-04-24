#include "Tracers/tracer.hpp"
#include "Utilities/record.hpp"
#include "World/world.hpp"
#include "Materials/matte.hpp"

Tracer::Tracer(World* world_ptr) : world_ptr {world_ptr}
{

}

Tracer::~Tracer()
{
    if (world_ptr)
    {
        world_ptr = nullptr;
    }
}

Color Tracer::trace_ray(const Ray& ray) const
{
    Record record {world_ptr->config_record(ray)};
    
    if (record.hit_an_object)
    {
        record.ray = ray;
        return record.material_ptr->shade(record);
    }
    else
    {
        return green;
    }
}