#ifndef _RENDERIZADOR_H_
#define _RENDERIZADOR_H_

#include <random>
#include <vector>

#include "cena.h"
#include "imagem.h"
#include "camera.h"
#include "raio.h"
#include "esfera.h"	

class Renderizador{    
    public:
    	Cena cena;
        Camera camera;

    	Renderizador();
        Renderizador(Cena&);
        Imagem& criarImagem( CorRGB (*colorir)(Raio&,Cena&));          
};

#include "../src/renderizador.cpp"

#endif
