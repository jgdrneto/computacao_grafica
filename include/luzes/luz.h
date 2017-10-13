#ifndef _LUZ_H_
#define _LUZ_H_

#include "../vetor.h"

class Luz{

public:
	Vetor3 direcao;
	CorRGB intensidade;

	virtual Vetor3 obterDirecao(Ponto3&)=0;

};

#endif	