#ifndef _LEITOR_OBJETOS_H_
#define _LEITOR_OBJETOS_H_

#include <string>
#include <vector>

#include "objeto.h"
#include "esfera.h"
#include "lambertiano.h"
#include "vetor.h"

#include "../src/utilidades.cpp"

class LeitorObjetos {

    public :
        static std::vector<Objeto*>& lerObjetos(std::string); 
};

#include "../src/leitor_objetos.cpp"

#endif
