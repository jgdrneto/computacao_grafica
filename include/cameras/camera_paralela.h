#ifndef _CAMERA_PARALELA_H_
#define _CAMERA_PARALELA_H_

#include "camera.h"

class CameraParalela : public Camera{

public:

	Vetor3 u, v, w;

	CameraParalela(Ponto3&, Ponto3&, Vetor3&, float,float,float,float);
    Raio obterRaio(float u, float v);
};

#include "../../src/cameras/camera_paralela.cpp"

#endif