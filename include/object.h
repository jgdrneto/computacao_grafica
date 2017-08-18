#ifndef _OBJECT_H_
#define _OBJECT_H_

#include "ray.h"
#include "material.h"
#include "hit_record.h"

class Object{

public:
	point3 origin;
	Material material; 
	virtual HitRecord* hit (Ray,float,float)=0;
};

#endif