#pragma once

#include "Utilities/color.hpp"
#include "Utilities/ray.hpp"

class World;

class Tracer 
{
    public:
        Tracer(World* world_ptr);
        virtual Color trace_ray(const Ray& ray) const = 0;
        virtual ~Tracer();
    protected:
        World* world_ptr;
};