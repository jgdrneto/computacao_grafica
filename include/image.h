#ifndef _IMAGE_H_
#define _IMAGE_H_

class Image {
    
    public:
    
        // Image pixels
        rgb* pixels;
        // Image width
        unsigned int width;
        // Image height
        unsigned int height;

        /**
         * Image constructor.
         *
         * @param Image width
         * @param Image height
         */
        Image(unsigned int, unsigned int);
        
        /**
         * Image destructor.
         */
        ~Image();
};

#include "../src/image.cpp"

#endif
