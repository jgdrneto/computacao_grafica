#ifndef _READERER_H_
#define _READERER_H_

#include "scene.h"
#include "image.h"
#include "camera.h"
#include "ray.h"	

class Renderer{
    private:    
        Scene scene;
        Camera camera;
    public:
        Renderer(Scene&);
        Image& createILImage();            
};

#include "../src/renderer.cpp"

#endif