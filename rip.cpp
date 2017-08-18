#include <iostream>
#include <stdlib.h>

#include "reader_scene.h"
#include "vec3.h"
#include "renderer.h"
#include "printer.h"

int main(int argc, char *argv[]) {
    
	if(argc>1){

    	ReaderScene reader(argv[1]);
    
 		Renderer renderer(reader.getScene());                       
   		
 		Printer p(renderer.createSpheresImage(), "PPM","saida.ppm");
 	}
    return 0;
}
