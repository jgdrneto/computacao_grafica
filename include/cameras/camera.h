#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "../vetor.h"

class Camera{

public:
    Ponto3 canto_inferior_esquerdo;
    Vetor3 horizontal;
    Vetor3 vertical;
    Ponto3 origem;

    Camera();
    Camera(Ponto3&,Vetor3&,Vetor3&,Ponto3&);

};

#include "../../src/cameras/camera.cpp"

#endif
