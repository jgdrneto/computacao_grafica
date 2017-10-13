#ifndef _TOONMATERIAL_H_
#define _TOONMATERIAL_H_

#include <vector>

#include "material.h"


class ToonMaterial : public Material{

public:
	std::vector<CorRGB> gradientes;
	std::vector<float> angulos;
};

#endif
