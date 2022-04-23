#include "Samplers/sampler.hpp"

Sampler::Sampler(std::size_t no_samples) : no_samples {no_samples}, no_sets {83}, count {0}, jump {0}
{
    shuffle_indices();
}

Sampler::~Sampler()
{

}

void Sampler::shuffle_indices()
{
    std::vector<int> t {};

    for (std::size_t i {0}; i < no_samples; i++)
    {
        t.push_back(i);
    }

    for (std::size_t i {0}; i < no_samples; i++)
    {
        std::random_shuffle(t.begin(), t.end());

        for (std::size_t j {0}; j < no_samples; j++)
        {
            indices.push_back(t.at(j));
        }
    }
}

std::size_t Sampler::get_no_samples() const
{
    return no_samples;
}

Point Sampler::sample_unit_square()
{
    if (count % no_samples == 0)
    {
        jump = (random_integer() % no_sets) * no_samples;
    }

    return samples.at(jump + indices.at(jump + count++ % no_samples));
}