#include <fstream>
#include <string>
#include "vec3.hpp"

std::ofstream ofs;
void init_img(const int w, const int h, std::string filename) {
    ofs = std::ofstream(filename.c_str());
    
    ofs.write("P3\n", 3);
    ofs.write(std::to_string(w).c_str(), std::to_string(w).size());
    ofs.write(" ", 1);
    ofs.write(std::to_string(h).c_str(), std::to_string(h).size());
    ofs.write("\n255\n", 5);
}

void write_pixel(Vector3& c) {
    ofs.write(c.to_string().c_str(), c.to_string().length());
    ofs.write("\n", 1);
    return;
}