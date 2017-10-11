#ifndef _LEITOR_CENA_H_
#define _LEITOR_CENA_H_

#include <string>

#include "cena.h"
#include "vetor.h"
#include "../src/utilidades.cpp"

class LeitorCena {

	public :
        static Cena& lerCena(std::string);    
};

#include "../../src/leitores/leitor_cena.cpp"

#endif
