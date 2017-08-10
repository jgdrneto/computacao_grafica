#include <iostream>
#include <stdlib.h>

#include "reader_scene.h"
#include "vec3.h"

int main(int argc, char *argv[]) {
    std::cout << argc << " " << argv[0] << std::endl;
    Vec3* v1 = new Vec3(1,2,3);
    std::cout << *v1 << std::endl;
    Vec3* v2 = new Vec3(3, 2, 1);
    std::cout << *v2 << std::endl;
    Vec3 v3 = *v1 + *v2;
    std::cout << v3 << std::endl;
    
    ReaderScene reader("hello-rain.txt");
    
    std::cout << "Name : "       << reader.getScene().name << std::endl;
    std::cout << "Type : "       << reader.getScene().type << std::endl;
    std::cout << "Codification :"<< reader.getScene().codification << std::endl;
    std::cout << "Width : "      << reader.getScene().width << std::endl;
    std::cout << "Height : "     << reader.getScene().height << std::endl;
    std::cout << "Upper_left : " << (int)reader.getScene().upper_left[Pixel::R] << " " 
                                 << (int)reader.getScene().upper_left[Pixel::G] << " "
                                 << (int)reader.getScene().upper_left[Pixel::B] << std::endl;
    std::cout << "Upper_right :" << (int)reader.getScene().upper_right[Pixel::R] << " " 
                                 << (int)reader.getScene().upper_right[Pixel::G] << " "
                                 << (int)reader.getScene().upper_right[Pixel::B] << std::endl;
    std::cout << "lower_left :"  << (int)reader.getScene().lower_left[Pixel::R] << " " 
                                 << (int)reader.getScene().lower_left[Pixel::G] << " "
                                 << (int)reader.getScene().lower_left[Pixel::B] << std::endl;
    std::cout << "lower_right :" << (int)reader.getScene().lower_right[Pixel::R] << " " 
                                 << (int)reader.getScene().lower_right[Pixel::G] << " "
                                 << (int)reader.getScene().lower_right[Pixel::B] << std::endl;                         
    
    return 0;
}
