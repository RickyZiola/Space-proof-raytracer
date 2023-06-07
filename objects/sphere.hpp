#ifndef SPHERE_HPP
#define SPHERE_HPP

#include <cmath>
#include "base_object.hpp"
#include "../util/vec3.hpp"
#include "../util/ray.hpp"

class Sphere : public BaseObject {
    Vector3 center;
    Vector3 colour;
    float   radius;
public:
    Sphere(Vector3 center, float radius, Vector3 colour) {
        this->center = center;
        this->radius = radius;
        this->colour = colour;
    }
    
    float intersect(Ray& ray) {
        Vector3 O = ray.O();
        Vector3 D = ray.D();
        float b = 2 * D.dot(O - center);
        float c = center.dot(center) + O.dot(O) - 2 * center.dot(O) - (radius*radius);
        float disc = (b*b) - (c * 4);
        float sq = std::sqrt(std::max((float)0,disc));
        float h0 = (-b - sq) / 2;
        float h1 = (-b + sq) / 2;
        float h;
        if ((h0 > 0) & (h0 < h1))
            h = h0;
        else
            h = h1;
        bool pred = (disc > 0) & (h > 0);
        if (pred)
            return h;
        else
            return -1;
    }
    
    Vector3 color(Vector3 at) {
        return Vector3(this->colour);
    }
    
    Vector3 norm(Vector3 at) {
        return (at - this->center).norm();
    }
};

#endif