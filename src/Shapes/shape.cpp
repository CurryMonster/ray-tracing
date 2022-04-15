#include <Shapes/shape.hpp>

Color Shape::get_color() const 
{
    return color;
}
        
void Shape::set_color(const Color& color)
{
    this->color = color;
}