#ifndef _ACERTO_H_
#define _ACERTO_H_

#include "vetor.h"
#include "material.h"

class Acerto{

public:
	
	float t;
	Vetor3 normal;
	Ponto3 ponto;
	Material material;
};



#endif
