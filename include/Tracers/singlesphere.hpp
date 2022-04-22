#pragma once

#include "Tracers/tracer.hpp"
#include "Utilities/color.hpp"
#include "Utilities/ray.hpp"

class World;

class SingleSphere: public Tracer 
{
    public:
        SingleSphere(World* world_ptr);
        virtual ~SingleSphere();
        virtual Color trace_ray(const Ray& ray) const override;
};