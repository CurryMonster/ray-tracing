#include <Utilities/vector.hpp>
#include <Utilities/point.hpp>
#include <Utilities/color.hpp>
#include <Utilities/ray.hpp>

int main() {
    const Vector v {1, 1, 1};
    std::cout << v;
    Point q {1, 1, 1};
    std::cout << q;
    std::cout << v + v;
    const Color c {10, 100, 1000};
    std::cout << c;
    Ray r {q, v};
    std::cout << r.get_direction().get_x();
    return 0;
}