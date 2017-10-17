#ifndef _LUZ_LOCAL_H_
#define _LUZ_LOCAL_H_

#include "../vetor.h"
#include "luz.h"

class LuzLocal : public Luz{

public:
	Vetor3 origem;
	float angulo;

	Vetor3 obterDirecao(Ponto3);
	Vetor3 obterIntensidade();

};

#include "../../src/luzes/luz_local.cpp"

#endif	