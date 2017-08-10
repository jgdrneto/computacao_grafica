#ifndef _READER_SCENE_H_
#define _READER_SCENE_H_

#include <string>

#include "scene.h"

#include "vec3.h"
#include "../src/utilities.cpp"

class ReaderScene {
    
    private :
    
        Scene scene;
    
    public :
    
        ReaderScene(std::string);
        
        Scene& getScene();
        
};

#include "../src/reader_scene.cpp"

#endif