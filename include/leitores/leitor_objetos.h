#ifndef _LEITOR_OBJETOS_H_
#define _LEITOR_OBJETOS_H_

#include <string>
#include <vector>

#include "../objetos/objeto.h"
#include "../objetos/esfera.h"
#include "../materiais/lambertiano.h"
#include "../vetor.h"

#include "../src/utilidades.cpp"

class LeitorObjetos {

    public :
        static std::vector<Objeto*>& lerObjetos(std::string); 
};

#include "../../src/leitores/leitor_objetos.cpp"

#endif
