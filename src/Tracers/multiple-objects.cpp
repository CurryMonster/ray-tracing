#include "Tracers/multiple-objects.hpp"
#include "Utilities/record.hpp"
#include "World/world.hpp"

MultipleObjects::MultipleObjects(World* world_ptr) : Tracer(world_ptr)
{

}

MultipleObjects::~MultipleObjects() 
{
    if (world_ptr)
    {
        world_ptr = nullptr;
    }
}

Color MultipleObjects::trace_ray(const Ray& ray) const 
{
    Record record {world_ptr->config_record(ray)};
    
    if (record.hit_an_object)
    {
        return record.color;
    }
    else
    {
        return black;
    }
}