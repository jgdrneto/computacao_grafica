#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "ray.h"
#include "material.h"
#include "hit_record.h"
#include "object.h"

class Sphere : public Object {

public:

	float radius;

	Sphere(point3,Material,float);
	
	HitRecord* hit (Ray,float,float);
};

#include "../src/sphere.cpp"

#endif