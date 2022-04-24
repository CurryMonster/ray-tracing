#include "Shapes/shape.hpp"
#include "Materials/matte.hpp"

Shape::Shape() : color {}, material_ptr {nullptr}
{

}

Shape::~Shape() 
{
    if (material_ptr)
    {
        material_ptr = nullptr;
    }
}

Color Shape::get_color() const 
{
    return color;
}
        
void Shape::set_color(const Color& color)
{
    this->color = color;
}

void Shape::set_material(std::shared_ptr<Material> material)
{
    material_ptr = material;
}