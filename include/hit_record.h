#ifndef _HIT_RECORD_H_
#define _HIT_RECORD_H_

#include "vec3.h"
#include "material.h"

class HitRecord{

public:

	float t;
	vec3 normal;
	point3 ponto;
	Material material;
};

#endif