#ifndef VEC3_HPP
#define VEC3_HPP

#include <cmath>
#include <string>
#include <iostream>
class Vector3 {
public:
    float x;
    float y;
    float z;
    // Constructors
    
    // Constructs a Vector3 with x, y, and z
    Vector3(float x, float y, float z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    
    // Constructs a Vector3 with x, x, and x
    Vector3(float x) {
        this->x = x;
        this->y = x;
        this->z = x;
    }
    
    // Copy a vector3
    Vector3(Vector3& v) {
        this->x = v.x;
        this->y = v.y;
        this->z = v.z;
    }
    
    // Constructs a Vector3 with 0,0,0
    Vector3() {
        this->x = 0.;
        this->y = 0.;
        this->z = 0.;
    }
    
    Vector3 operator+ (const Vector3 v) {
        return Vector3(this->x + v.x, this->y + v.y, this->z + v.z);
    }
    Vector3 operator- (const Vector3 v) {
        return Vector3(this->x - v.x, this->y - v.y, this->z - v.z);
    }
    Vector3 operator* (const Vector3 v) {
        return Vector3(this->x * v.x, this->y * v.y, this->z * v.z);
    }
    Vector3 operator/ (const Vector3 v) {
        return Vector3(this->x / v.x, this->y / v.y, this->z / v.z);
    }
    
    Vector3 operator* (const float v) {
        return *this * Vector3(v);
    }
    Vector3 operator/ (const float v) {
        return *this / Vector3(v);
    }
    
    float dot(const Vector3 v) {
        return this->x * v.x + this->y * v.y + this->z * v.z;
    }
    float length() {
        return std::sqrt(this->dot(*this));
    }
    
    Vector3 norm() {
        return *this / this->length();
    }
    
    std::string to_string() {
        std::string out;
        out += std::to_string((int)this->x);
        out += " ";
        out += std::to_string((int)this->y);
        out += " ";
        out += std::to_string((int)this->z);
        return out;
    }
};
#endif