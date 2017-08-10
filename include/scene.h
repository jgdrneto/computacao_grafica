#ifndef _SCENE_H_
#define _SCENE_H_

#include <string>

#include "vec3.h"

class Scene {
    
    public:
        // Image name
        std::string name;
        // Image type
        std::string type;
        // Image codification
        std::string codification;
        // Image width
        int width;
        // Image height
        int height;

        //Values of pixels of bords
        Pixel upper_left;
        Pixel lower_left;
        Pixel upper_right;
        Pixel lower_right;
    
};

#endif
