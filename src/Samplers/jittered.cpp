#include "Samplers/jittered.hpp"

Jittered::Jittered(std::size_t no_samples) : Sampler(no_samples)
{
    generate_samples();
}

Jittered::~Jittered()
{

}

void Jittered::generate_samples()
{
    double sub_cell_width {1.0 / no_samples};

    Point sample {};

    std::size_t n = static_cast<int>( std::sqrt(no_samples) );

    for (std::size_t i {0}; i < no_samples * no_sets; i++)
    {
        samples.push_back(sample);
    }

    for (std::size_t p {0}; p < no_sets; p++) 
    {
        for (std::size_t i {0}; i < n; i++) 
        {
            for (std::size_t j {0}; j < n; j++) 
            {
                samples.at(i * n + j + p * no_samples).set_x((i * n + j) * sub_cell_width + random_double(0, sub_cell_width));
                samples.at(i * n + j + p * no_samples).set_y((j * n + i) * sub_cell_width + random_double(0, sub_cell_width));
            }
        }
    }

    for (std::size_t p {0}; p < no_sets; p++) 
    {
        for (std::size_t i {0}; i < n; i++) 
        {
            for (std::size_t j {0}; j < n; j++) 
            {
                int k {random_integer(j, n - 1)};
                double t {samples.at(i * n + j + p * no_samples).get_x()};
                samples.at(i * n + j + p * no_samples).set_x(samples.at(i * n + k + p * no_samples).get_x());
                samples.at(i * n + k + p * no_samples).set_x(t);
            }
        }
    }

    for (std::size_t p {0}; p < no_sets; p++) 
    { 
        for (std::size_t i {0}; i < n; i++) 
        {
            for (std::size_t j {0}; j < n; j++) 
            {
                std::size_t k {random_integer(j, n - 1)};
                double t {samples.at(j * n + i + p * no_samples).get_y()};
                samples.at(j * n + i + p * no_samples).set_y(samples.at(k * n + i + p * no_samples).get_y());
                samples.at(k * n + i + p * no_samples).set_y(t);
            }
        }
    } 

}