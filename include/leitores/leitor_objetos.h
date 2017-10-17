#ifndef _LEITOR_OBJETOS_H_
#define _LEITOR_OBJETOS_H_

#include <string>
#include <vector>

#include "leitor.h"
#include "../objetos/objeto.h"
#include "../objetos/esfera.h"
#include "../materiais/blinnphong.h"
#include "../materiais/toon.h"
#include "../vetor.h"

class LeitorObjetos {

    public :
        static std::vector<Objeto*>& lerObjetos(std::string); 
};

#include "../../src/leitores/leitor_objetos.cpp"

#endif
