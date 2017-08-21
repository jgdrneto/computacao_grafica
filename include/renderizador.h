#ifndef _RENDERIZADOR_H_
#define _RENDERIZADOR_H_

#include "cena.h"
#include "imagem.h"
#include "camera.h"
#include "raio.h"
#include "Esfera.h"	
#include "../src/utilidades.cpp"


class Renderizador{
    private:    
        Cena cena;
        Camera camera;
    public:
        Renderizador(Cena&);
        Imagem& CriarImagem( CorRGB (*colorir)(Raio&,Cena&));            
};

#include "../src/renderizador.cpp"

#endif