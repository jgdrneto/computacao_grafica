#ifndef _CAMERA_PERSPECTIVA_H_
#define _CAMERA_PERSPECTIVA_H_

#include "camera.h"

class CameraPerspectiva : public Camera{

public:
    Ponto3 canto_inferior_esquerdo;
    Vetor3 horizontal;
    Vetor3 vertical;
    Ponto3 origem;

    Raio obterRaio(float u, float v);
};

#include "../../src/cameras/camera_perspectiva.cpp"

#endif