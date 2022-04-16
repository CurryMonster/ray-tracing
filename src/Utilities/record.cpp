#include <Utilities/record.hpp>

#include <World/world.hpp>

Record::Record(World* world_ptr)
: hit_an_object {false}, local_hit_point {0.0, 0.0, 0.0}, normal {0.0, 0.0, 0.0}, color {0.0, 0.0, 0.0}, world_ptr {world_ptr}
{

}