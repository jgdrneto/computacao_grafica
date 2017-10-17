#ifndef _ULTIMO_PLANO_H_
#define _ULTIMO_PLANO_H_

#include "vetor3.h"

class UltimoPlano
{
public:
	CorRGB superiorEsquerdo;
    CorRGB inferiorEsquerdo;
    CorRGB superiorDireito;
    CorRGB inferiorDireito;

	UltimoPlano(CorRGB&,CorRGB&,CorRGB&,CorRGB&);
};

#include "../src/ultimo_plano.cpp"

#endif