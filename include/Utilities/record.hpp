#pragma once

#include <Utilities/point.hpp>
#include <Utilities/normal.hpp>
#include <Utilities/color.hpp>
#include <Utilities/ray.hpp>
#include <Utilities/vector.hpp>

#include <memory>

class World;
class Material;

class Record 
{
    public:
        Record(const World* world_ptr);
        ~Record();
    public:
        bool   hit_an_object;
        Point  local_hit_point;
        Normal normal;
        Color  color;
  const World* world_ptr;
        Point  hit_point;
        std::shared_ptr<Material> material_ptr;
        Ray    ray;
        Vector direction;
        double t;
};
