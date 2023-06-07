#ifndef RAY_HPP
#define RAY_HPP

#include "vec3.hpp"

class Ray {
    Vector3 origin, direction;
public:
    Ray(Vector3 origin, Vector3 direction) {
        this->origin = Vector3(origin);
        this->direction = direction.norm();
    }
    
    Ray() {
        this->origin    = Vector3(0, 0, 0);
        this->direction = Vector3(0, 0, 1);
    }
    
    Vector3 at(float i) {
        return this->origin + (this->direction * i);
    }
    
    Vector3 O() { return Vector3(this->origin); }
    Vector3 D() { return Vector3(this->direction); }
    
};

#endif