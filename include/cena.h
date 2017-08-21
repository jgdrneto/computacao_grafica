#ifndef _SCENE_H_
#define _SCENE_H_

#include <string>

#include "Vetor.h"

class Cena {
    
    public:
        // Image name
        std::string nome;
        // Image type
        std::string tipo;
        // Image codification
        std::string codificacao;
        // Image width
        int largura;
        // Image height
        int altura;

        //Values of pixels of bords
        CorRGB superiorEsquerdo;
        CorRGB inferiorEsquerdo;
        CorRGB superiorDireito;
        CorRGB inferiorDireito;

        CorRGB primeiroPlano;
        CorRGB ultimoPlano;

        float profundidadeMaxima;
    
};

#endif