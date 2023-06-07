#ifndef BASE_OBJECT_HPP
#define BASE_OBJECT_HPP

#include "../util/vec3.hpp"
#include "../util/ray.hpp"

class BaseObject {
public:
    virtual ~BaseObject() {};
    virtual float intersect(Ray& ray) = 0;
    virtual Vector3 color(Vector3 at) = 0;
    virtual Vector3  norm(Vector3 at) = 0;
};

#endif