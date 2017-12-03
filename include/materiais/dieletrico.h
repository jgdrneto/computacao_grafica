#ifndef _DIELETRICO_MATERIAL_H_
#define _DIELETRICO_MATERIAL_H_

#include "../texturas/textura.h"
#include "../materiais/lambertiano.h"

class DieletricoMaterial : public Material
{
public:

    Textura* textura;
    float indRef;

	void obterDispersao(Raio& raio, Acerto& acerto,Vetor3& atenuacao, Raio& raioDisperso);

    Vetor3 reflexao(Vetor3 v, Vetor3 n);	

    bool refracao(Vetor3 v, Vetor3& n, float ni_over_nt, Vetor3& refratado);

    float schlick(float cosine, float ref_idx);
    
};

#include "../../src/materiais/dieletrico.cpp"

#endif