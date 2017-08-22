#include <iostream>
#include <stdlib.h>

#include "leitor_cena.h"
#include "vetor.h"
#include "renderizador.h"
#include "impressora.h"

int main(int argc, char *argv[]) {
    
	if(argc>1){

    	LeitorCena reader(argv[1]);
    
 		Renderizador renderer(reader.getCena());                       
   		
 		Impressora p(renderer.criarImagem(colorSphere), "PPM","saida.ppm");
 	}
    return 0;
}
