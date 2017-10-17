#ifndef _LUZ_PONTUAL_H_
#define _LUZ_PONTUAL_H_

#include "../vetor.h"
#include "luz.h"

class LuzPontual : public Luz{

public:

	Ponto3 origem;

	Vetor3 obterDirecao(Ponto3&);
	Vetor3 obterIntensidade();

};

#include "../../src/luzes/luz_pontual.cpp"

#endif