#ifndef _IMPRESSORA_H_
#define _IMPRESSORA_H_

#include <string>
#include <fstream>

#include "imagem.h"

class Impressora{
public:
	static void salvarImagem(Imagem&,std::string,std::string);
};

#include "../src/impressora.cpp"
#endif
