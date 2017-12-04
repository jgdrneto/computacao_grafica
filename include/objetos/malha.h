#ifndef _MALHA_H_
#define _MALHA_H_

#include "../raio.h"
#include "../materiais/material.h"
#include "../acerto.h"
#include "../objetos/triangulo.h"

class Malha : public Objeto {

public:
	
	std::vector<Triangulo> faces;

	Malha();
	
	Acerto* acertar(Raio,float,float);
};

#include "../../src/objetos/malha.cpp"

#endif