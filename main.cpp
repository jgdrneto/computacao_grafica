#include <iostream>
#include <stdlib.h>

#include "rip.h"

#include "funcoesColorir.cpp"

//Método principal
int main(int argc, char *argv[]) {

	if(argc>1){

		Rip* rip = nullptr;

		switch(argc){

			case 2:
				rip = new Rip(argv[1]);
			break;
			case 3:
				rip = new Rip(argv[1],argv[2]);
			break;	
		}	
	
		rip->renderizar(acertarObjetos,nAcertarObjetos);

		rip->salvarImagem("PPM", "saida.ppm");
 		
	}

    return 0;
}
