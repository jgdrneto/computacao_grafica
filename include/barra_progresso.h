#ifndef _BARRA_PROGRESSO_H_
#define _BARRA_PROGRESSO_H_

#include <string>
#include <iostream>
#include <cstdlib>

class BarraProgresso{

    int tamanho;
    int dimensao;
    int porcentagem;

    public:
        BarraProgresso(int);

        void resetar();

        void setDimensao(int);

        void incrementar();

        void imprimir();
} ;

#include "../src/barra_progresso.cpp"

#endif