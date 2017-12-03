#ifndef _CONSTANTE_TEXTURA_H_
#define _CONSTANTE_TEXTURA_H_

#include "textura.h"
#include "../vetor.h"
#include "../raio.h"

class ConstanteTextura : public Textura{
	
public:

	CorRGB cor;

	CorRGB valor(float u, float v, const Vetor3& p);

};

#include "../../src/texturas/constante.cpp"

#endif