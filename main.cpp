#include "util/vec3.hpp"
#include "util/img_out.cpp"
#include "util/ray.hpp"
#include "objects/base_object.hpp"
#include "objects/sphere.hpp"
#include <string>
#include <iostream>
#include <cmath>
#include <vector>
#define IMG_WIDTH 1920
#define IMG_HEIGHT 1080

Vector3 skybox(Vector3 dir) {
    return (dir*-1).dot(Vector3(3,3,-3).norm());
}

Vector3 render(Ray& ray, std::vector<BaseObject*> objects, float NEAR=0.01, float FAR=1000.0) {
    Vector3 O = ray.O();
    Vector3 D = ray.D();
    
    float minDistance = INFINITY;
    BaseObject* closest;
    for (BaseObject* obj : objects) {
        float distance = obj->intersect(ray);
        if (distance > 0 && distance < minDistance) {
            closest = obj;
            minDistance = distance;
        }
    }
    if (minDistance > FAR || minDistance < NEAR)
        return skybox(D);
    Vector3 M = ray.at(minDistance);
    Vector3 c = closest->color(M);
    
    return c * closest->norm(M).dot(Vector3(3,3,-3).norm());
}

int main() {
    init_img(1920,1080,"output.ppm");
    Vector3 c;
    Vector3 eye(0.,0.,-1.);
    Vector3 uv;
    Ray ray;
    
    std::vector<BaseObject*> scene {
        new Sphere(Vector3(0.,0.,1.), .5, Vector3(0.,1.,0.))
    };
    
    float r = (float)IMG_HEIGHT / (float)IMG_WIDTH;
    for (int i = 0; i < IMG_WIDTH; i++) {
        std::cout << i << std::endl;
        for (int j = 0; j < IMG_HEIGHT; j++) {
            uv = Vector3((float)i/(float)IMG_WIDTH*2.-1., ((float)j/(float)IMG_HEIGHT*-2.+1.)*r, 0.);
            ray = Ray(eye, (uv - eye).norm());
            
            c = render(ray, scene)*255;
            write_pixel(c);
        }
    }
}