#ifndef _ESFERA_H_
#define _ESFERA_H_

#include "raio.h"
#include "material.h"
#include "acerto.h"
#include "objeto.h"

class Esfera : public Objeto {

public:

	float r;
	
	Esfera();

	Esfera(Ponto3,Material*,float);
	
	Acerto* acertar(Raio,float,float);
};

#include "../src/esfera.cpp"

#endif
