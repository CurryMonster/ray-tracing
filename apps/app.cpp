#include <Utilities/Vector3D.hpp>
#include <Utilities/Point3D.hpp>

int main() {
    Vector3D vec {1, 2, 3};
    std::cout << vec << "\n";
    vec.set_x(23.0);
    std::cout << vec;

    Point3D pnt {10, 20, 300};
    std::cout << pnt << "\n";
    pnt.set_x(23.0);
    std::cout << pnt;

    return 0;
}