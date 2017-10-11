#ifndef _ESFERA_H_
#define _ESFERA_H_

#include "../raio.h"
#include "../materiais/material.h"
#include "../acerto.h"
#include "../objetos/objeto.h"

class Esfera : public Objeto {

public:

	float r;
	
	Esfera();

	Esfera(Ponto3,Material*,float);
	
	Acerto* acertar(Raio,float,float);
};

#include "../../src/objetos/esfera.cpp"

#endif
