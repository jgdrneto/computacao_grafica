#ifndef _PLANO_H_
#define _PLANO_H_

#include "../raio.h"
#include "../materiais/material.h"
#include "../acerto.h"
#include "../objetos/objeto.h"
#include "../objetos/triangulo.h"

class Plano : public Objeto {

public:
	
	std::vector<Triangulo> triangulos;

	Plano();
	
	Acerto* acertar(Raio,float,float);
};

#include "../../src/objetos/plano.cpp"

#endif