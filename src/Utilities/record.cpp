#include <Utilities/record.hpp>

#include "World/world.hpp"
#include "Materials/matte.hpp"

Record::Record(const World* world_ptr) : 
    hit_an_object   {false}, 
    local_hit_point {}, 
    normal          {}, 
    color           {}, 
    world_ptr       {world_ptr},
    hit_point       {},
    material_ptr    {nullptr},
    ray             {},
    direction       {},
    t               {}
{

}

Record::~Record()
{
    if (world_ptr)
    {
        world_ptr = nullptr;
    }

    if (material_ptr)
    {
        material_ptr = nullptr;
    }
}