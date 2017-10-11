#ifndef _RENDERIZADOR_H_
#define _RENDERIZADOR_H_

#include <random>
#include <vector>
#include <chrono>
#include <thread>

#include "cena.h"
#include "imagem.h"
#include "cameras/camera.h"
#include "raio.h"
#include "objetos/esfera.h"
#include "barra_progresso.h"	

class Renderizador{    
    public:
    	Cena cena;
        Camera camera;
        BarraProgresso barraProgresso;
        
        CorRGB (*acertarObjetos)(Raio&, Renderizador&, Acerto&); 

    	CorRGB (*nAcertarObjetos)(Raio&,Renderizador&, Acerto&);
        
    	Renderizador();
        Renderizador(Cena&);
        Imagem& criarImagem();
        CorRGB colorir(Raio&);         
};

#include "../src/renderizador.cpp"

#endif
