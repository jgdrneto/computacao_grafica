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
    private:    
        Cena cena;
        Camera camera;
    public:
        Renderizador(Cena&);
        Imagem& criarImagem( CorRGB (*colorir)(Raio&,Cena&));          
};

#include "../src/renderizador.cpp"

#endif
