#ifndef _CAMERA_PERSPECTIVA_H_
#define _CAMERA_PERSPECTIVA_H_

#include "camera.h"

class CameraPerspectiva : public Camera{

public:

	float raioLente;
    Vetor3 u,v,w;

    CameraPerspectiva(Ponto3&, Ponto3&, Vetor3&, float, float, float, float);
    Raio obterRaio(float u, float v);
};

#include "../../src/cameras/camera_perspectiva.cpp"

#endif