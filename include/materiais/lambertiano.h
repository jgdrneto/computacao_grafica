#ifndef _LAMBERTIANO_H_
#define _LAMBERTIANO_H_

#include "material.h"

class Lambertiano : public Material{

public:
	CorRGB ambiente;
	CorRGB difuso;
	CorRGB especular;

	int expoenteEspecular=1;
};

#endif
