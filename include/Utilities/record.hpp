#pragma once

#include <Utilities/point.hpp>
#include <Utilities/normal.hpp>
#include <Utilities/color.hpp>

class World;

class Record 
{
    public:
        bool hit_an_object;
        Point local_hit_point;
        Normal normal;
        Color color;
        World* world_ptr;
        Record(World* world_ptr);

};
