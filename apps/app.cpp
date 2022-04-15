#include <Utilities/vector.hpp>
#include <Utilities/point.hpp>
#include <Utilities/color.hpp>
#include <Utilities/ray.hpp>
#include <Shapes/plane.hpp>

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
    Ray r2 = r;
    Normal n {0, 0, 0};
    Plane plane {q, n};
    v * n;
    n * v;
    (q - q) * n;
    return 0;
}