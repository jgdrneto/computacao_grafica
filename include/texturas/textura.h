#ifndef _TEXTURA_H_
#define _TEXTURA_H_

#include <math.h> 

#include "../vetor.h"
#include "../raio.h"

class Textura{
public:

	virtual CorRGB valor(float u, float v, const Vetor3& p) = 0;

};


#endif