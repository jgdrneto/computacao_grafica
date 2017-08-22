#ifndef _LEITOR_CENA_H_
#define _LEITOR_CENA_H_

#include <string>

#include "cena.h"

#include "vetor.h"

#include "../src/utilidades.cpp"

class LeitorCena {
    
    private :
    
        Cena cena;
    
    public :
    
        LeitorCena(std::string);
        
        Cena& getCena();
        
};

#include "../src/leitor_cena.cpp"

#endif
