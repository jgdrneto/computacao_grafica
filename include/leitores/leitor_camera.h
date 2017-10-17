#ifndef _LEITOR_CAMERA_H_
#define _LEITOR_CAMERA_H_

#include <string>
#include <iostream>

#include "leitor.h"        
#include "../cameras/camera.h"
#include "../cameras/camera_paralela.h"
#include "../cameras/camera_perspectiva.h"

#include "../vetor.h"

class LeitorCamera : public Leitor{

	public:
    	static Camera* lerConfCamera(std::string);
};

#include "../../src/leitores/leitor_camera.cpp"

#endif
