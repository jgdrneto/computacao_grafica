#ifndef _LEITOR_CENA_H_
#define _LEITOR_CENA_H_

#include <string>

#include "../cena.h"
#include "../vetor.h"
#include "leitor.h"
#include "../luzes/luz_pontual.h"
#include "../luzes/luz_direcional.h"
#include "../luzes/luz_local.h"

class LeitorCena : public Leitor{

	public :
        static Cena& lerCena(std::string);
        static std::vector<Luz*>& lerLuzes(json j, Cena* cena);    
};

#include "../../src/leitores/leitor_cena.cpp"

#endif
