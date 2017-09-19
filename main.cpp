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
	
		rip->renderizar(blinnFoundObjetos2,nAcertarObjetos);

		//rip->renderizar(mapaProfundidadeAcerto,mapaProfundidadenAcerto);

		std::string arquivo(argv[1]);

  		std::size_t pos = arquivo.find(".");

  		std::string nome = arquivo.substr(0,pos);  

  		std::cout << "Nome: " << nome << std::endl;
 
		rip->salvarImagem("ppm", nome);
 		
	}

    return 0;
}
