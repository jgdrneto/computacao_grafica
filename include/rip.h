#ifndef _RIP_H
#define _RIP_H

#include <string>

#include "leitores/leitor_cena.h"
#include "leitores/leitor_camera.h"
#include "leitores/leitor_objetos.h"
#include "renderizador.h"
#include "impressora.h"
#include "../src/sombreadores/blinnphong.cpp"
#include "../src/sombreadores/toon.cpp"
#include "../src/sombreadores/lambertiano.cpp"

class Rip {

private:
	Renderizador renderizador;
	Imagem imagem;
public:

	Rip(std::string);
	/*
	void renderizar(CorRGB (*nAcertarObjetos)(Raio&,Renderizador&, Acerto&), CorRGB (*nNacertarObjetos)(Raio&,Renderizador&, Acerto&));
	*/
	void renderizar();

	void salvarImagem(std::string,std::string);
};

#include "../src/rip.cpp"

#endif	