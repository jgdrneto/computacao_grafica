#ifndef _DIFUSO_LUMINOSO_H_
#define _DIFUSO_LUMINOSO_H_

#include "material.h"
#include "../texturas/textura.h"

class DifusoLuminosoMaterial : public Material{

public:

	Textura* textura;

	Vetor3 obterEmissaoLuz(float u, float v, Vetor3& p);

};

#include "../../src/materiais/difusoLuminoso.cpp"

#endif
