#ifndef _LUZ_DIRECIONAL_H_
#define _LUZ_DIRECIONAL_H_

#include "../vetor.h"
#include "luz.h"

class LuzDirecional : public Luz{

public:

	Vetor3 obterDirecao(Ponto3&);

};

#include "../../src/luzes/luz_direcional.cpp"

#endif