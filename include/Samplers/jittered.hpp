#pragma once

#include "Samplers/sampler.hpp"
   
class Jittered: public Sampler
{
    public:
        Jittered(std::size_t no_samples);
        virtual ~Jittered() override;
        virtual void generate_samples() override;
};