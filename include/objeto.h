#ifndef _OBJETO_H_
#define _OBJETO_H_

#include "raio.h"
#include "material.h"
#include "acerto.h"

class Objeto{

public:
	Ponto3 origem;
	Material* material; 
	virtual Acerto* acertar (Raio,float,float)=0;
};

#endif
