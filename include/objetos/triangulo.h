#ifndef _TRIANGULO_H_
#define _TRIANGULO_H_

#include "../raio.h"
#include "../materiais/material.h"
#include "../acerto.h"
#include "../objetos/objeto.h"

class Triangulo : public Objeto {

public:

	Ponto3 v0,v1,v2;
	
	bool apagarCostas = true;

	Triangulo();

	Acerto* acertar(Raio,float,float);
};

#include "../../src/objetos/triangulo.cpp"

#endif
