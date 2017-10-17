#ifndef _LEITOR_H_
#define _LEITOR_H_

#include <fstream>
#include "json.hpp"

using json = nlohmann::json;

class Leitor{
public:

	static json& abrirArquivo(std::string);	
};

#include "../../src/leitores/leitor.cpp"

#endif