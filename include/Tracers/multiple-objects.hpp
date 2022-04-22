#pragma once

#include "Tracers/tracer.hpp"
#include "Utilities/color.hpp"
#include "Utilities/ray.hpp"

class World;

class MultipleObjects: public Tracer 
{
    public:
        MultipleObjects(World* world_ptr);
        virtual ~MultipleObjects() override;
        virtual Color trace_ray(const Ray& ray) const override;
};