#pragma once

#include <Tracers/tracer.hpp>
#include <Utilities/color.hpp>
#include <Utilities/ray.hpp>

#include <memory>

class World;

class SingleSphere: public Tracer 
{
    public:
        SingleSphere(World* world_ptr);
        virtual Color trace_ray(const Ray& ray) const override;
};