#include <iostream>
#include <stdlib.h>

#include "rip.h"

int main(int argc, char *argv[]) {
	
	std::cout << "Quantidade de argumentos: " << argc << std::endl;

	if(argc>1){

		Rip* rip = nullptr;

		switch(argc){

			case 2:
				std::cout << "Argumento 1: " << argv[1] << std::endl;

				rip = new Rip(argv[1]);
			break;
			case 3:

				std::cout << "Argumento 1: " << argv[1] << std::endl;
				std::cout << "Argumento 2: " << argv[2] << std::endl;

				rip = new Rip(argv[1],argv[2]);
			break;	
		}	
	
		rip->renderizar(colorSphere);

		rip->salvarImagem("PPM", "saida.ppm");
 	
	}

    return 0;
}
