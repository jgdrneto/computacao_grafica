#ifndef _LAMBERTIANO_MATERIAL_H_
#define _LAMBERTIANO_MATERIAL_H_

#include "material.h"
#include "../texturas/textura.h"

class LambertianoMaterial : public Material{

public:

	Textura* textura;

	Vetor3 random_in_unit_sphere();

	void obterDispersao(Raio& raio, Acerto& acerto,Vetor3& atenuacao, Raio& raioDisperso);
};

#include "../../src/materiais/lambertiano.cpp"

#endif
