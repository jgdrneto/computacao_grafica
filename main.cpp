#include <iostream>
#include <stdlib.h>

#include "include/rip.h"

//Método principal
int main(int argc, char *argv[]) {

	if(argc>2){

		Rip* rip = nullptr;

		switch(argc){
			case 3:
				rip = new Rip(argv[1],argv[2]);
			break;
			case 4:
				rip = new Rip(argv[1],argv[2],argv[3]);
			break;	
		}	
	
		rip->renderizar();

		//rip->renderizar(mapaProfundidadeAcerto,mapaProfundidadenAcerto);

		std::string arquivo(argv[1]);

  		std::size_t pos = arquivo.find(".");

  		std::string nome = arquivo.substr(0,pos);  

  		std::cout << "Nome: " << nome << std::endl;
 
		rip->salvarImagem("ppm", nome);
 		
	}

    return 0;
}
