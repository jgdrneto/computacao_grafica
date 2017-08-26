#ifndef _RIP_H
#define _RIP_H

#include <string>

#include "leitor_cena.h"
#include "leitor_camera.h"
#include "leitor_objetos.h"
#include "renderizador.h"
#include "impressora.h"

class Rip {

private:
	Renderizador renderizador;
	Imagem imagem;
public:

	Rip(std::string);

	Rip(std::string,std::string);

	void renderizar(CorRGB (*colorir)(Raio&,Cena&));

	void salvarImagem(std::string,std::string);
};

#include "../src/rip.cpp"

#endif	