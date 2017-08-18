#ifndef _READERER_H_
#define _READERER_H_

#include "scene.h"
#include "image.h"
#include "camera.h"
#include "ray.h"
#include "sphere.h"	

class Renderer{
    private:    
        Scene scene;
        Camera camera;
    public:
        Renderer(Scene&);
        Image& createILImage();
        Image& createSphImage();
        Image& createSpheresImage();            
};

#include "../src/renderer.cpp"

#endif