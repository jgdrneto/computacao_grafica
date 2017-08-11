#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "vec3.h"

class Camera{

public:
    point3 lower_left_corner;
    vec3 horizontal;
    vec3 vertical;
    point3 origin;

    Camera();
    Camera(point3&,vec3&,vec3&,point3&);

};

#include "../src/camera.cpp"

#endif