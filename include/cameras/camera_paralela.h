#ifndef _CAMERA_PARALELA_H_
#define _CAMERA_PARALELA_H_

#include "camera.h"

class CameraParalela : public Camera{

public:
    Ponto3 canto_inferior_esquerdo;
    Vetor3 horizontal;
    Vetor3 vertical;
    Ponto3 origem;

    Raio obterRaio(float u, float v);
};

#include "../../src/cameras/camera_paralela.cpp"

#endif