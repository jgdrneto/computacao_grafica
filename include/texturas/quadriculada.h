#ifndef _QUADRICULADA_TEXTURA_H_
#define _QUADRICULADA_TEXTURA_H_

#include <math.h> 

#include "textura.h"
#include "../vetor.h"
#include "../raio.h"

class QuadriculadaTextura : public Textura{
	
public:

	CorRGB cor1;
	CorRGB cor2;

	CorRGB valor(float u, float v, const Vetor3& p);

};

#include "../../src/texturas/quadriculada.cpp"

#endif
