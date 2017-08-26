#ifndef _SCENE_H_
#define _SCENE_H_

#include <string>

#include "vetor.h"
#include "objeto.h"
#include "acerto.h"

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

        int amostras;

        //Values of pixels of bords
        CorRGB superiorEsquerdo;
        CorRGB inferiorEsquerdo;
        CorRGB superiorDireito;
        CorRGB inferiorDireito;

        CorRGB primeiroPlano;
        CorRGB ultimoPlano;

        float profundidadeMaxima;
        
        float profundidadeRaio;

        std::vector<Objeto*> objetos;

        //Métodos
        Cena();

        Acerto* acertarObjetos(Raio&,float,float);

};

#include "../src/cena.cpp"

#endif
