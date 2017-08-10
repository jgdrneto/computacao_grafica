#ifndef _READERER_H_
#define _READERER_H_

#include "scene.h"

class Renderer{
    private:    
        Scene scene;
    public:
        Renderer(Scene&);
        Renderer(Scene&, Pixel* pixels);
        Image& createImage();    
        
        
};

#include "../src/renderer.cpp"

#endif