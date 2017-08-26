#ifndef _LEITOR_CAMERA_H_
#define _LEITOR_CAMERA_H_

#include <string>

#include "camera.h"

#include "vetor.h"

#include "../src/utilidades.cpp"

class LeitorCamera {

	public:
    	static Camera& lerConfCamera(std::string);
};

#include "../src/leitor_camera.cpp"

#endif
