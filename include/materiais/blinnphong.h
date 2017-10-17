#ifndef _BLINNPHONG_H_
#define _BLINNPHONG_H_

#include "material.h"

class BlinnPhongMaterial : public Material{

public:
	CorRGB ambiente;
	CorRGB difuso;
	CorRGB especular;

	int expoenteEspecular=1;
};

#endif
