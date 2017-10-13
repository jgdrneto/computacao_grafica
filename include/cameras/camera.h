#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "../vetor.h"
#include "../raio.h"

class Camera{

public:
    Ponto3 canto_inferior_esquerdo;
    Vetor3 horizontal;
    Vetor3 vertical;
    Ponto3 origem;

    Camera();
    Camera(Ponto3&,Vetor3&,Vetor3&,Ponto3&);
    Raio obterRaio(float u, float v);
};

#include "../../src/cameras/camera.cpp"

#endif
