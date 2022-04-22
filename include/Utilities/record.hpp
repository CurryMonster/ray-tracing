#pragma once

#include <Utilities/point.hpp>
#include <Utilities/normal.hpp>
#include <Utilities/color.hpp>

class World;

class Record 
{
    public:
        Record(const World* world_ptr);
    public:
        bool hit_an_object;
        Point local_hit_point;
        Normal normal;
        Color color;
        const World* world_ptr;
};
