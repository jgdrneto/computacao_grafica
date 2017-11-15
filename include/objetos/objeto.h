#ifndef _OBJETO_H_
#define _OBJETO_H_

#include "../raio.h"
#include "../materiais/material.h"
#include "../materiais/blinnphong.h"
#include "../acerto.h"

class Objeto{

public:
	Ponto3 origem;
	Material* material; 
	virtual Acerto* acertar (Raio,float,float)=0;
};

#endif
