#ifndef _RENDERIZADOR_H_
#define _RENDERIZADOR_H_

#include <random>
#include <vector>
#include <chrono>

#include "cena.h"
#include "imagem.h"
#include "camera.h"
#include "raio.h"
#include "esfera.h"
#include "barra_progresso.h"	

class Renderizador{    
	private:
    	BarraProgresso barraProgresso;

    public:
    	Cena cena;
        Camera camera;

        CorRGB (*acertarObjetos)(Raio&,Renderizador&, Acerto&); 

    	CorRGB (*nAcertarObjetos)(Raio&,Renderizador&, Acerto&);

    	Renderizador();
        Renderizador(Cena&);
        Imagem& criarImagem();
        CorRGB colorir(Raio&);          
};

#include "../src/renderizador.cpp"

#endif
