#include <Utilities/math.hpp>

int random_integer() {
    return rand() / RAND_MAX;
}

int random_integer(int min, int max) {
    return random_integer() * (max - min) + 1;
}

double random_double() {
    return static_cast<double>(rand() / RAND_MAX);
}

double random_double(int min, int max) {
    return random_double() * (max - min) + 1.0;
}