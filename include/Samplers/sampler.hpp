#pragma once

#include "Utilities/point.hpp"
#include "Utilities/math.hpp"

#include <vector>
#include <algorithm>

class Sampler
{
    public:
        Sampler(std::size_t no_samples);
        virtual ~Sampler();

        virtual void generate_samples() = 0; // generate sample patterns in a unit square
        void  shuffle_indices();             // set up randomly shuffled indices
        Point sample_unit_square();          // get next sample in unit square

        std::size_t get_no_samples() const;

    public:
        std::size_t        no_samples; // number of samples in a pattern
        std::size_t        no_sets;    // number of samples patterns stored
        std::vector<Point> samples;    // samples point on a unit square
        std::vector<int>   indices;    // shuffled sample array indices
        std::size_t        count;      // current number of sample points used
        std::size_t        jump;       // random index jump
};