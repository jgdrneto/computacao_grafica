#ifndef _LUZ_DIRECIONAL_H_
#define _LUZ_DIRECIONAL_H_

#include "../vetor.h"
#include "luz.h"

class LuzDirecional : public Luz{

public:

	virtual Vetor3 obterDirecao(Ponto3);
	virtual Vetor3 obterIntensidade();

};

#include "../../src/luzes/luz_direcional.cpp"

#endif