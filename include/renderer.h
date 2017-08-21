#ifndef _RENDERIZADOR_H_
#define _RENDERIZADOR_H_

#include "cena.h"
#include "imagem.h"
#include "camera.h"
#include "raio.h"
#include "Esfera.h"	

class Renderizador{
    private:    
        Cena cena;
        Camera camera;
    public:
	
	CorRGB (*colorir)(Raio&); 
	
        Renderizador(Cena&);
        Imagem& CriarImagem();            
};

#include "../src/renderizador.cpp"

#endif
